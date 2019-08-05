using System;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.IO;
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
        }

        private static IEnumerable<string> LoadCommands()
        {
            var line = Console.ReadLine();
            while (!"end".Equals(line?.ToLowerInvariant()))
            {
                yield return line;
                line = Console.ReadLine();
            }
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
            return
                from command in commands
                select ParseCommand(command);
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

            return new BotParseResult {id = id, firstRedirect = firstRedirect, secondRedirect = secondRedirect};
        }

        private ValueParseResult ParseValueCommand(string command)
        {
            var parts = command.Split();

            var id = int.Parse(parts[1]);
            var value = int.Parse(parts[5]);

            return new ValueParseResult {botId = id, value = value};
        }
    }

    internal class Bot
    {
        private readonly List<Action<int>> _redirects;
        private readonly List<int> _values;

        private Bot(params Action<int>[] redirects)
        {
            _values = new List<int>();
            _redirects = redirects.ToList();
        }

        public static Bot FromParseResult(Parser.BotParseResult parseResult, Dictionary<int, Bot> bots)
        {
            return new Bot(
                GenerateRedirect(bots, parseResult.firstRedirect),
                GenerateRedirect(bots, parseResult.secondRedirect)
            );
        }

        private static Action<int> GenerateRedirect(IReadOnlyDictionary<int, Bot> bots, int redirect)
        {
            if (redirect < -1)
            {
                return passed => { };
            }

            return passed => bots[redirect].AddValue(passed);
        }

        public void AddValue(int value)
        {
            if (_values.Count < _redirects.Count)
            {
                _values.Add(value);
            }

            if (_values.Count != _redirects.Count)
            {
                return;
            }

            for (var i = 0; i < _values.Count; i++)
            {
                _redirects[i].Invoke(_values[i]);
            }

            _values.Clear();
        }
    }
}