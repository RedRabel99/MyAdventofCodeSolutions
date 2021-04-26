using System;
using System.Linq;

namespace AOC
{
    class Program
    {
        public static System.Collections.Generic.IEnumerable<int[]> solution(string[] lines)
        {
            for (int i = 0; i < lines.Length - 2; i++)
            {
                for (int j = i; j < lines.Length - 1; j++)
                {
                    for (int y = j; y < lines.Length; y++)
                    {
                        yield return new[] { Int32.Parse(lines[i]), Int32.Parse(lines[j]), Int32.Parse(lines[y]) };
                    }
                    yield return new[] { Int32.Parse(lines[i]), Int32.Parse(lines[j]) };
                }
            }
        }
        static void Main(string[] args)
        {
            string[] input = System.IO.File.ReadAllLines(@"day1.txt");

            foreach (var pair in solution(input))
            {
                int result = pair.Sum();
                var wasFound = false;
                if (result == 2020)
                {
                    if (pair.Length == 2)
                    {
                        Console.WriteLine("part1: {0}", pair.Aggregate(1, (a, b) => a * b));
                        if (!wasFound) wasFound = true;
                        else break;
                    }
                    else if (pair.Length == 3)
                    {
                        Console.WriteLine("part2: {0}", pair.Aggregate(1, (a, b) => a * b));
                        if (!wasFound) wasFound = true;
                        else break;
                    }
                }
            }
        }
    }
}
