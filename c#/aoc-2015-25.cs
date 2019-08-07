using System;
using System.Numerics;

namespace AdventOfCode
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution.Solve();
        }
    }

    internal class Solution
    {
        private static readonly BigInteger Start = 20151125;
        private static readonly BigInteger Multiplier = 252533;
        private static readonly BigInteger Divider = 33554393;

        private const int WantedRow = 2981;
        private const int WantedColumn = 3075;
        
        public static void Solve()
        {
            var diagonal = 1;
            var value = Start;

            while (true)
            {
                for (var i = 0; i < diagonal; i++)
                {
                    var row = diagonal - i;
                    var column = i + 1;
                    
                    if (row == WantedRow && column == WantedColumn)
                    {
                        Console.WriteLine(value);
                        return;
                    }

                    value = (value * Multiplier) % Divider;
                }

                diagonal++;
            }
        }

    }
}