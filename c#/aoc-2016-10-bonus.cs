using System;
using System.Collections.Generic;
using System.Linq;

namespace AdventOfCode
{
    class Solution
    {
        static void Main()
        {
            var commands = LoadCommands();
            var (bots, outputs, values) = new Parser().Parse(commands);
            PassValues(bots, values);

            Console.WriteLine(outputs[0].value * outputs[1].value * outputs[2].value);
        }

        private static IEnumerable<string> LoadCommands()
        {
            var lines = new List<string>();

            var line = Console.ReadLine();
            while (!"".Equals(line))
            {
                lines.Add(line);
                line = Console.ReadLine();
            }

            return lines;
        }

        private static void PassValues(Dictionary<int, Bot> bots, IEnumerable<Value> values)
        {
            foreach (var value in values)
            {
                PassValues(bots, value);
            }
        }

        private static void PassValues(Dictionary<int, Bot> bots, Value value)
        {
            var bot = bots[value.botId];
            bot.AddValue(value.value);

            var checkedBots = new Stack<Bot>();
            checkedBots.Push(bot);

            while (checkedBots.Count > 0)
            {
                bot = checkedBots.Pop();
                if (bot.CanPass())
                {
                    PassToOtherBots(bots, checkedBots, bot);
                }
            }
        }

        private static void PassToOtherBots(Dictionary<int, Bot> bots, Stack<Bot> checkedBots, Bot bot)
        {
            for (var i = 0; i < bot.redirects.Count; i++)
            {
                var target = bot.redirects[i];
                target.AddValue(bot.values[i]);

                if (target is Bot checkedBot)
                {
                    checkedBots.Push(checkedBot);
                }
            }

            bot.values.Clear();
        }
    }

    internal class Parser
    {
        public (Dictionary<int, Bot> bots, Dictionary<int, Output> outputs, IEnumerable<Value> values) Parse(IEnumerable<string> commands)
        {
            var (bots, outputs) = ParseTargets(commands);
            AssignTargets(commands, bots, outputs);
            var values = ParseValues(commands);

            return (bots, outputs, values);
        }

        private (Dictionary<int, Bot> bots, Dictionary<int, Output> outputs) ParseTargets(IEnumerable<string> commands)
        {
            var targets = LoadTargets(commands);

            var bots = targets
                .OfType<Bot>()
                .ToDictionary(bot => bot.id, bot => bot);

            var outputs = targets
                .OfType<Output>()
                .ToDictionary(output => output.id, output => output);

            return (bots, outputs);
        }

        private IEnumerable<Target> LoadTargets(IEnumerable<string> commands)
        {
            return commands
                .Where(IsBotCommand)
                .SelectMany(ParseBotCommand)
                .Distinct();
        }

        private List<Target> ParseBotCommand(string command)
        {
            var result = new List<Target>();
            var parts = command.Split();

            var id = int.Parse(parts[1]);
            result.Add(new Bot(id));

            id = int.Parse(parts[6]);
            var firstTarget = parts[5] == "bot" ?  (Target) new Bot(id) : new Output(id);
            result.Add(firstTarget);

            id = int.Parse(parts[11]);
            var secondTarget = parts[10] == "bot" ? (Target) new Bot(id) : new Output(id);
            result.Add(secondTarget);

            return result;
        }

        private void AssignTargets(IEnumerable<string> commands, Dictionary<int, Bot> bots, Dictionary<int, Output> outputs)
        {
            commands
                .Where(IsBotCommand)
                .ToList()
                .ForEach(command => AssignTarget(command, bots, outputs));
        }

        private void AssignTarget(string command, Dictionary<int, Bot> bots, Dictionary<int, Output> outputs)
        {
            var parts = command.Split();

            var botId = int.Parse(parts[1]);
            var bot = bots[botId];

            var id = int.Parse(parts[6]);
            var firstRedirect = parts[5] == "bot" ? (Target) bots[id] : outputs[id];
            bot.AddRedirect(firstRedirect);

            id = int.Parse(parts[11]);
            var secondRedirect = parts[10] == "bot" ? (Target) bots[id] : outputs[id];
            bot.AddRedirect(secondRedirect);
        }

        private bool IsBotCommand(string command)
        {
            return command.StartsWith("bot");
        }

        
        private IEnumerable<Value> ParseValues(IEnumerable<string> commands)
        {
            return commands
                .Where(command => !IsBotCommand(command))
                .Select(ParseValue);
        }

        private Value ParseValue(string command)
        {
            var parts = command.Split();

            var value = int.Parse(parts[1]);
            var id = int.Parse(parts[5]);

            return new Value { value = value, botId = id};
        }
    }
    public struct Value
    {
        public int botId;
        public int value;
    }

    internal abstract class Target
    {
        public readonly int id;

        public Target(int id)
        {
            this.id = id;
        }

        public abstract void AddValue(int value);
    }

    internal class Output : Target
    {
        public int value;

        public Output(int id) : base(id)
        {
        }

        public override void AddValue(int value)
        {
            this.value = value;
        }

        public override bool Equals(object obj)
        {
            if (obj is Output output)
            {
                return output.id == id;
            }

            return false;
        }

        public override int GetHashCode()
        {
            return id;
        }
    }

    internal class Bot : Target
    {
        public readonly List<Target> redirects;
        public readonly List<int> values;

        public Bot(int id) : base(id)
        {
            values = new List<int>();
            redirects = new List<Target>();
        }

        public void AddRedirect(Target target)
        {
            redirects.Add(target);
        }

        public override void AddValue(int value)
        {
            if (values.Count < redirects.Count)
            {
                values.Add(value);
            }

            values.Sort();
        }

        public bool CanPass()
        {
            return values.Count == redirects.Count;
        }

        public override bool Equals(object obj)
        {
            if (obj is Bot bot)
            {
                return bot.id == id;
            }

            return false;
        }

        public override int GetHashCode()
        {
            return id;
        }
    }
}