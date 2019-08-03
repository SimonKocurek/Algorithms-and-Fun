using System;
using System.Collections.Generic;
using System.Linq;

namespace AdventOfCode
{
    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();
            solution.Solve();
        }
    }

    internal class Solution
    {
        private List<int> _weights;
        private List<int> _combination;

        public void Solve()
        {
            _weights = LoadWeights().ToList();
            _weights.Sort();

            _combination = new List<int>();
            GenerateCombinations(_combination, _weights.Sum() / 3);
            _combination.Sort((a, b) => NumberOfSetBits(a).CompareTo(NumberOfSetBits(b)));

            var distributions = GetDistributions().ToList();
            distributions.Sort();
            foreach (var distribution in distributions)
            {
                Console.WriteLine(distribution);
            }
        }

        private static IEnumerable<int> LoadWeights()
        {
            var line = Console.ReadLine();
            while (!"end".Equals(line?.ToLowerInvariant()))
            {
                if (int.TryParse(line, out var added))
                {
                    yield return added;
                }
                else
                {
                    Console.Error.WriteLine($"Failed parsing {line} to int");
                }

                line = Console.ReadLine();
            }
        }

        private void GenerateCombinations(List<int> result, int remaining, int idx = 0, int values = 0)
        {
            for (var i = idx; i < _weights.Count; i++)
            {
                GenerateCombinations(result, remaining, i + 1, values);
             
                if (remaining - _weights[i] < 0)
                {
                    return;
                }
                
                values |= 1 << i;
                remaining -= _weights[i];
            }
            
            if (remaining == 0)
            {
                result.Add(values);
            }
        }
        
        /// <summary>
        /// Count the number of bits set to 1 in an int
        /// </summary>
        private static int NumberOfSetBits(int i)
        {
            i -= (i >> 1) & 0x55555555;
            i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
            return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
        }

        private IEnumerable<ulong> GetDistributions()
        {
            var result = new List<ulong>();

            for (var i = 0; i < _combination.Count; i++)
            {
                if (i > 0 && NumberOfSetBits(_combination[i - 1]) < NumberOfSetBits(_combination[i]))
                {
                    break;
                }

                for (var j = i + 1; j < _combination.Count; j++)
                {
                    if ((_combination[i] & _combination[j]) == 0)
                    {
                        var weights = CombinationToWeights(_combination[i]);
                        var product = WeightProduct(weights);
                        result.Add(product);
                        break;
                    }
                }
            }

            return result;
        }

        private IEnumerable<int> CombinationToWeights(int combination)
        {
            return _weights.Where((weight, idx) => (combination & (1 << idx)) != 0).ToList();
        }

        private static ulong WeightProduct(IEnumerable<int> weights)
        {
            return weights.Aggregate(1ul, (current, weight) => checked(current * (ulong) weight));
        }
    }
}