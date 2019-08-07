using System;
using System.IO;
using System.Text.RegularExpressions;

namespace AdventOfCode
{
    class Solution
    {
        static void Main()
        {
            var text = File.ReadAllText(@"input.txt");
            var result = new Decompressor(text).GetUncompressedLength();
            Console.WriteLine(result);
        }
    }

    internal class Decompressor
    {
        private readonly string _line;

        private static readonly Regex Marker = new Regex(@"^\(\d+x\d+\)");

        public Decompressor(string line)
        {
            _line = line;
        }

        public ulong GetUncompressedLength()
        {
            var result = 0ul;

            var i = 0;
            while (i < _line.Length)
            {
                ProcessToken(ref i, out var tokenSize);
                result = checked(result + tokenSize);
            }

            return result;
        }

        private void ProcessToken(ref int pointer, out ulong tokenSize)
        {
            if (IsDecompressionMarker(pointer))
            {
                var (size, count) = ParseMarker(ref pointer);

                var decompressed = _line.Substring(pointer, size);
                var decompressedSize = new Decompressor(decompressed).GetUncompressedLength();
                tokenSize =  decompressedSize * (ulong) count;

                pointer += size;
            }
            else
            {
                pointer++;
                tokenSize = 1;
            }
        }

        private (int, int) ParseMarker(ref int pointer)
        {
            pointer++; // (

            var size = ParseInt(ref pointer); // 10

            pointer++; // x

            var count = ParseInt(ref pointer); // 2

            pointer++; // )

            return (size, count);
        }

        private int ParseInt(ref int pointer)
        {
            var digit = "";

            while (char.IsDigit(_line[pointer]))
            {
                digit += _line[pointer++];
            }

            return int.Parse(digit);
        }

        private bool IsDecompressionMarker(int pointer)
        {
            var startingAtPointer = _line.Substring(pointer);
            return Marker.IsMatch(startingAtPointer);
        }
    }
}