using System;
using System.Collections.Generic;
using System.Linq;

namespace AdventOfCode
{
    class Solution
    {
        private const int ROWS = 6;
        private const int COLUMNS = 50;

        private static readonly bool[,] screen = new bool[ROWS, COLUMNS];
        private static readonly bool[] row = new bool[COLUMNS];
        private static readonly bool[] column = new bool[ROWS];

        static void Main()
        {
            ParseInput();
            var lit = GetLit();
            Console.WriteLine(lit);
        }

        private static void ParseInput()
        {
            var line = Console.ReadLine();
            while ("" != line)
            {
                var words = line.Split();
                ExecuteCommand(words);
                line = Console.ReadLine();
            }
        }

        private static void ExecuteCommand(string[] words)
        {
            if (words[0] == "rect")
            {
                FillRect(words);
            }
            else
            {
                Rotate(words);
            }
        }

        /// <summary>
        /// rect 3x2
        /// </summary>
        private static void FillRect(string[] words)
        {
            var rotation = words[1].Split('x').Select(int.Parse).ToArray();

            for (var y = 0; y < rotation[1]; y++)
            {
                for (var x = 0; x < rotation[0]; x++)
                {
                    screen[y, x] = true;
                }
            }
        }

        private static void Rotate(string[] words)
        {
            var rotation = new List<string>() { words[2].Substring(2), words[4] }.Select(int.Parse).ToArray();

            if (words[1] == "column")
            {
                RotateColumn(rotation);
            }
            else
            {
                RotateRow(rotation);
            }
        }

        /// <summary>
        /// rotate column x=1 by 1
        /// </summary>
        private static void RotateColumn(int[] rotation)
        {
            var x = rotation[0];
            var move = rotation[1];

            // Copy moved
            for (var i = 0; i < ROWS; i++)
            {
                column[(i + move) % ROWS] = screen[i, x];
            }

            // Replace with copy
            for (var i = 0; i < ROWS; i++)
            {
                screen[i, x] = column[i];
            }
        }

        /// <summary>
        /// rotate row y=0 by 4
        /// </summary>
        private static void RotateRow(int[] rotation)
        {
            var y = rotation[0];
            var move = rotation[1];

            // Copy moved
            for (var i = 0; i < COLUMNS; i++)
            {
                row[(i + move) % COLUMNS] = screen[y, i];
            }

            // Replace with copy
            for (var i = 0; i < COLUMNS; i++)
            {
                screen[y, i] = row[i];
            }
        }

        private static int GetLit()
        {
            var result = 0;

            for (var y = 0; y < ROWS; y++)
            {
                for (var x = 0; x < COLUMNS; x++)
                {
                    if (screen[y, x])
                    {
                        result++;
                    }
                }
            }

            return result;
        }
    }

}
