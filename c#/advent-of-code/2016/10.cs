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
            var parseResults = new Parser().Parse(commands);
            var bots = LoadBots(parseResults);
            PassValues(parseResults, bots);
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

        private static Dictionary<int, Bot> LoadBots(IEnumerable<Parser.ParseResult> parseResults)
        {
            var bots = new Dictionary<int, Bot>();

            foreach (var parseResult in parseResults.OfType<Parser.BotParseResult>())
            {
                bots[parseResult.id] = Bot.FromParseResult(parseResult, bots);
            }

            return bots;
        }

        private static void PassValues(IEnumerable<Parser.ParseResult> parseResults, Dictionary<int, Bot> bots)
        {
            foreach (var parseResult in parseResults.OfType<Parser.ValueParseResult>())
            {
                PropagateValue(bots, parseResult.botId, parseResult.value);
            }
        }

        private static void PropagateValue(Dictionary<int, Bot> bots, int botId, int value)
        {
            var checkedBots = new Stack<Bot>();

            var bot = bots[botId];
            bot.AddValue(value);
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
                if (bot.redirects[i] == -1)
                {
                    continue;
                }

                var redirectedBot = bots[bot.redirects[i]];
                redirectedBot.AddValue(bot.values[i]);

                checkedBots.Push(redirectedBot);
            }

            bot.values.Clear();
        }
    }

    internal class Parser
    {
        internal abstract class ParseResult
        {
        }

        public class BotParseResult : ParseResult
        {
            public int id;
            public int firstRedirect;
            public int secondRedirect;
        }

        public class ValueParseResult : ParseResult
        {
            public int botId;
            public int value;
        }

        public IEnumerable<ParseResult> Parse(IEnumerable<string> commands)
        {
            return commands.Select(ParseCommand);
        }

        private ParseResult ParseCommand(string command)
        {
            if (command.StartsWith("bot"))
            {
                return ParseBotCommand(command);
            }
            else
            {
                return ParseValueCommand(command);
            }
        }

        private BotParseResult ParseBotCommand(string command)
        {
            var parts = command.Split();

            var id = int.Parse(parts[1]);
            var firstRedirect = parts[5] == "bot" ? int.Parse(parts[6]) : -1;
            var secondRedirect = parts[10] == "bot" ? int.Parse(parts[11]) : -1;

            return new BotParseResult { id = id, firstRedirect = firstRedirect, secondRedirect = secondRedirect };
        }

        private ValueParseResult ParseValueCommand(string command)
        {
            var parts = command.Split();

            var value = int.Parse(parts[1]);
            var id = int.Parse(parts[5]);

            return new ValueParseResult { botId = id, value = value };
        }
    }

    internal class Bot
    {
        private readonly int _id;
        public readonly List<int> redirects;
        public readonly List<int> values;

        private Bot(int id, params int[] redirects)
        {
            _id = id;
            values = new List<int>();
            this.redirects = redirects.ToList();
        }

        public static Bot FromParseResult(Parser.BotParseResult parseResult, Dictionary<int, Bot> bots)
        {
            return new Bot(parseResult.id, parseResult.firstRedirect, parseResult.secondRedirect);
        }

        public void AddValue(int value)
        {
            if (values.Count < redirects.Count)
            {
                values.Add(value);
            }

            values.Sort();

            if (values.Count == redirects.Count && values[0] == 17 && values[1] == 61)
            {
                Console.WriteLine(_id);
            }
        }

        public bool CanPass()
        {
            return values.Count == redirects.Count;
        }

    }
}