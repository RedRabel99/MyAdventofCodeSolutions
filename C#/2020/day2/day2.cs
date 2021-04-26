using System;
using System.Linq;

namespace day2
{
    class Program
    {
        static void Day2(string path)
        {
            string[] lines = System.IO.File.ReadAllLines(path);
            var part1 = 0;
            var part2 = 0;
            foreach(var line in lines)
            {
                string[] elements = line.Split(' ');
                var letter = elements[1][0];
                int count = elements[2].Count(x => (x == letter));
                int[] range = elements[0].Split("-").Select(x => Int32.Parse(x)).ToArray();
                if (range[0] <= count && count <= range[1]) part1++;
                var counter = 0;
                if (elements[2][range[0] - 1] == letter) counter++;
                if (elements[2][range[1] - 1] == letter) counter++;
                if (counter == 1) part2++;
            }
            Console.WriteLine($"Part1: {part1}\nPart2: {part2}");
        }
        static void Main(string[] args)
        {
            Day2("day2.txt");
        }
    }
}
