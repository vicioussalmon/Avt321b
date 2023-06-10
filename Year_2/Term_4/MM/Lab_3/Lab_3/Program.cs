using System;
using System.Collections.Generic;
using OfficeOpenXml;
using OfficeOpenXml.Style;
using System.IO;

namespace MM_LB_3
{
    public class Simplex
    {
        int countLimits;
        int countVars;
        public static int[] nameX;

        public static double[,] table;

        public static int currentRow = 1;
        public static int currentCol = 1;
        public static string path = "../../Results.xlsx";
        int m, n;

        List<int> basis;

        public Simplex(double[,] source, string[] signs, int limits, int countVars, string target_func)
        {
            m = source.GetLength(0);
            n = source.GetLength(1);
            this.countLimits = limits;
            this.countVars = countVars;
            nameX = new int[countLimits];
            table = new double[m, n + m - 1];
            basis = new List<int>();

            for (int i = 0, count = countVars + 1; i < nameX.Length; i++, count++)
                nameX[i] = count;

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < table.GetLength(1); j++)
                {
                    if (j < n)
                        table[i, j] = source[i, j];
                    else
                        table[i, j] = 0;
                }

                if ((n + i) < table.GetLength(1))
                {
                    if (signs[i] == "<=")
                        table[i, n + i] = 1;
                    else if (signs[i] == ">=")
                        table[i, n + i] = -1;

                    basis.Add(n + i);
                }
            }
            for (int i = 0; i < m - 1; i++)
            {
                if (signs[i] == ">=" && target_func == "max")
                {
                    for (int j = 0; j < table.GetLength(1); j++)
                        if (table[i, j] != 0)
                            table[i, j] *= -1;

                }
                else if (signs[i] == "<=" && target_func == "min")
                {
                    for (int j = 0; j < table.GetLength(1); j++)
                        if (table[i, j] != 0)
                            table[i, j] *= -1;

                }
            }


            n = table.GetLength(1);
            Console.WriteLine("\t\tReduction to canonical form");
            ExportLineToExcel("Reduction to canonical form", Program.sheet1, true, table.GetLength(1));
            Program.printTable(table);
            ExportToExcel(table, Program.sheet1);
        }

        public double[,] Calculate(double[] result)
        {
            int mainCol, mainRow;

            while (!IsItEnd())
            {
                mainCol = findMainCol();
                mainRow = findMainRow(mainCol);
                basis[mainRow] = mainCol;
                nameX[mainRow] = mainCol;
                double[,] new_table = new double[m, n];

                for (int j = 0; j < n; j++)
                    new_table[mainRow, j] = table[mainRow, j] / table[mainRow, mainCol];

                for (int i = 0; i < m; i++)
                {
                    if (i == mainRow)
                        continue;

                    for (int j = 0; j < n; j++)
                        new_table[i, j] = table[i, j] - table[i, mainCol] * new_table[mainRow, j];
                }
                table = new_table;
            }


            for (int i = 0; i < result.Length; i++)
            {
                int k = basis.IndexOf(i + 1);
                if (k != -1)
                    result[i] = table[k, 0];
                else
                    result[i] = 0;
            }
            Console.WriteLine();
            ExportLineToExcel("Solved table", Program.sheet1, true, table.GetLength(1));
            ExportToExcel(table, Program.sheet1);
            return table;
        }

        private bool IsItEnd()
        {
            bool flag = true;

            for (int j = 1; j < n; j++)
                if (table[m - 1, j] < 0) { flag = false; break; }

            return flag;
        }

        private int findMainCol()
        {
            int mainCol = 1;

            for (int j = 2; j < n; j++)
                if (table[m - 1, j] < table[m - 1, mainCol])
                    mainCol = j;

            return mainCol;
        }

        private int findMainRow(int mainCol)
        {
            int mainRow = 0;

            for (int i = 0; i < m - 1; i++)
                if (table[i, mainCol] > 0) { mainRow = i; break; }

            for (int i = mainRow + 1; i < m - 1; i++)
                if ((table[i, mainCol] > 0) && ((table[i, 0] / table[i, mainCol]) < (table[mainRow, 0] / table[mainRow, mainCol])))
                    mainRow = i;

            return mainRow;
        }

        public static void Gomori(int countVars)
        {

            bool is_solved = true;

            for (int i = 0; i < table.GetLength(0) - 1; i++)
            {
                if (Math.Round(table[i, 0] * 1000) / 1000 != Math.Round(table[i, 0]))
                {
                    is_solved = false;
                    break;
                }
            }

            if (!is_solved)
            {
                int tableRows = table.GetLength(0);
                int tableCols = table.GetLength(1);
                Console.WriteLine("\n\t\tThe problem cannot be solved due to invalid variables");
                ExportLineToExcel("The problem cannot be solved due to invalid variables", Program.sheet2, true, table.GetLength(1));
                double[,] tempTable = new double[tableRows + 1, tableCols + 1];

                Array.Resize(ref nameX, nameX.Length + 1);
                nameX[nameX.Length - 1] = tableCols;

                for (int i = 0; i < tableRows; i++)
                {
                    for (int j = 0; j < tableCols; j++)
                    {
                        if (i == tableRows - 1)
                            tempTable[i + 1, j] = table[i, j];

                        else
                            tempTable[i, j] = table[i, j];

                    }
                }

                int maxElIndex = 0;
                for (int i = 0; i < tableRows - 2; i++)
                {
                    if (tempTable[i, 0] - (int)tempTable[i, 0] < tempTable[i + 1, 0] - (int)tempTable[i + 1, 0])
                        maxElIndex = i + 1;
                }

                for (int j = 0; j < tableCols; j++)
                {

                    if (tempTable[maxElIndex, j] == (int)tempTable[maxElIndex, j])
                        tempTable[tableRows - 1, j] = 0;

                    else if (tempTable[maxElIndex, j] > 0)
                        tempTable[tableRows - 1, j] = tempTable[maxElIndex, j] - (int)tempTable[maxElIndex, j];

                    else
                        tempTable[tableRows - 1, j] = Math.Abs((int)tempTable[maxElIndex, j]) + 1 - Math.Abs(tempTable[maxElIndex, j]);
                }

                tableRows++;

                for (int i = 0; i < tableRows; i++)
                {
                    if (i == tableRows - 2)
                        tempTable[i, tableCols] = 1;
                    else
                        tempTable[i, tableCols] = 0;
                }
                tableCols++;
                table = tempTable;


                for (int i = 1; i <= 2; i++)
                    for (int j = 0; j < tableCols - 1; j++)
                        if (tempTable[tableRows - i, j] != 0)
                            tempTable[tableRows - i, j] *= -1;



                Console.WriteLine("\n\t\tThe new table is based on the Gomori method");
                Program.printTable(table);
                ExportLineToExcel("The new table is based on the Gomori method", Program.sheet2, true, table.GetLength(1));
                ExportToExcel(table, Program.sheet2);


                double[] marks = new double[tableCols - 2];
                for (int i = 0; i < tableRows; i++)
                {
                    for (int j = 1; j < tableCols - 1; j++)
                    {
                        if (table[tableRows - 2, j] != 0)
                            marks[j - 1] = table[tableRows - 1, j] / table[tableRows - 2, j];
                        else
                            marks[j - 1] = 1000;

                    }
                }

                Console.WriteLine("\tA string of estimates");
                Console.Write("\t");
                for (int i = 0; i < tableCols - 2; i++)
                {
                    if (marks[i] == 1000)
                        Console.Write($"\t-");
                    else
                        Console.Write($"\t{marks[i]}");
                }
                int index = 0;


                for (int i = 0; i < tableCols - 3; i++)
                    if (marks[i] > marks[i + 1])
                        index = i + 1;

                index++;
                nameX[nameX.Length - 1] = index;
                Console.WriteLine();

                double enablElement = table[tableRows - 2, index];

                for (int j = 0; j < tableCols; j++)
                    table[tableRows - 2, j] /= enablElement;



                for (int i = 0; i < tableRows - 2; i++)
                {
                    double columnElenemt = table[i, index] * -1;
                    for (int j = 0; j < tableCols; j++)
                        table[i, j] = table[tableRows - 2, j] * columnElenemt + table[i, j];

                }
                Console.WriteLine("\n\t\tThe resulting table is based on the Gomori method");
                ExportLineToExcel("The resulting table is based on the Gomori method", Program.sheet2, true, table.GetLength(1));
                double endFunc = 0;
                int c = 0;
                for (int i = 0; i < countVars; i++)
                    for (int j = 0; j < nameX.Length; j++)
                        if (nameX[j] == i + 1)
                        {
                            endFunc = endFunc + Program.funcCoff[c] * table[j, 0];
                            c++;
                        }


                table[table.GetLength(0) - 1, 0] = endFunc;
                Program.printTable(table);
                ExportToExcel(table, Program.sheet2);


                Console.WriteLine("\n\tSolution:");
                ExportLineToExcel("\nSolution:", Program.sheet2, true, 1);
                for (int i = 0; i < countVars; i++)
                    for (int j = 0; j < nameX.Length; j++)

                        if (nameX[j] == i + 1)
                        {
                            Console.WriteLine($"X{nameX[j]} = {Math.Round(table[j, 0], 3)}");
                            ExportLineToExcel($"X{nameX[j]} = {Math.Round(table[j, 0], 3)}", Program.sheet2, length: 1);
                        }


                Console.WriteLine($"f(x) = {Math.Round(table[table.GetLength(0) - 1, 0], 3)}\n");
                ExportLineToExcel($"f(x) = {Math.Round(table[table.GetLength(0) - 1, 0], 3)}", Program.sheet2, length: 1);
                Gomori(countVars);
            }
            else
            {
                Console.WriteLine("\tThe task has all the necessary variables, and therefore it is completed");
                ExportLineToExcel("The task has all the necessary variables, and therefore it is completed", Program.sheet2, true, table.GetLength(1));
            }
        }
        public static void ExportToExcel(double[,] table, string sheetName)
        {
            currentCol = 1;
            ExcelPackage.LicenseContext = OfficeOpenXml.LicenseContext.NonCommercial;
            FileInfo fileInfo = new FileInfo(path);
            using (ExcelPackage package = new ExcelPackage(fileInfo))
            {
                ExcelWorksheet worksheet = package.Workbook.Worksheets[sheetName];
                if (worksheet == null)
                    worksheet = package.Workbook.Worksheets.Add(sheetName);

                worksheet.Cells[currentRow, currentCol++].Value = " ";
                worksheet.Cells[currentRow, currentCol++].Value = "В";

                for (int i = 0; i < table.GetLength(0) + 1; i++, currentCol++)
                    worksheet.Cells[currentRow, currentCol].Value = $"x{i + 1}";


                for (int i = 0; i < table.GetLength(0); i++, currentRow++)
                {
                    currentCol = 1;
                    if (i != table.GetLength(0) - 1)
                        worksheet.Cells[currentRow, currentCol++].Value = $"x{Simplex.nameX[i]}";
                    else
                        worksheet.Cells[currentRow, currentCol++].Value = "f(x)";
                    for (int j = 0; j < table.GetLength(1); currentCol++, j++)
                    {
                        if (j == 0)
                            worksheet.Cells[currentRow, currentCol].Style.Fill.PatternType = ExcelFillStyle.Solid;

                        worksheet.Cells[currentRow, currentCol].Value = Math.Round(table[i, j], 3);
                    }
                }
                currentCol = 1;

                currentRow++;
                package.Save();
            }
        }
        public static void ExportLineToExcel(string line, string sheetName, bool bold = false, int length = 3)
        {
            FileInfo fileInfo = new FileInfo(path);
            using (ExcelPackage package = new ExcelPackage(fileInfo))
            {
                ExcelWorksheet worksheet = package.Workbook.Worksheets[sheetName];
                if (worksheet == null)
                    worksheet = package.Workbook.Worksheets.Add(sheetName);

                currentCol = 1;
                ExcelRange mergedCell = worksheet.Cells[currentRow, currentCol, currentRow, currentCol + length];
                mergedCell.Merge = true;
                mergedCell.Value = line;



                mergedCell.Style.HorizontalAlignment = ExcelHorizontalAlignment.Center;
                currentRow += 1;
                package.Save();
            }
        }
    }

    internal class Program
    {
        public static string sheet1 = "Simplex method";
        public static string sheet2 = "Gomori method";
        public static double[] funcCoff = new double[0];

        public static void printTable(double[,] table)
        {
            Console.Write("\tВ\t");
            for (int i = 0; i < table.GetLength(0) + 1; i++)
                Console.Write($"x{i + 1}\t");

            Console.WriteLine();
            for (int i = 0; i < table.GetLength(0); i++)
            {
                if (i != table.GetLength(0) - 1)
                    Console.Write($"x{Simplex.nameX[i]}\t");
                else
                    Console.Write("f(x)\t");
                for (int j = 0; j < table.GetLength(1); j++)
                    Console.Write($"{Math.Round(table[i, j], 3)}\t");

                Console.WriteLine();
            }
        }



        static void ClearExcel(string sheetName)
        {
            ExcelPackage.LicenseContext = OfficeOpenXml.LicenseContext.NonCommercial;
            FileInfo fileInfo = new FileInfo(Simplex.path);
            using (ExcelPackage package = new ExcelPackage(fileInfo))
            {
                ExcelWorksheet worksheet = package.Workbook.Worksheets[sheetName];
                if (worksheet != null)
                {
                    worksheet.Cells.Clear();
                    package.Save();
                }

            }
        }
        static void Main(string[] args)
        {
            ExcelPackage.LicenseContext = OfficeOpenXml.LicenseContext.NonCommercial;

            Console.OutputEncoding = System.Text.Encoding.UTF8;


            ClearExcel(sheet2);
            ClearExcel(sheet1);
            Console.WriteLine("\t\tOptimization (max/min):");
            string target_func = Console.ReadLine();
            Console.Write("Number of variables -->  ");
            int countVars = int.Parse(Console.ReadLine());
            Console.Write("Number of restrictions -->  ");
            int countLimits = int.Parse(Console.ReadLine());

            double[,] table = new double[countLimits + 1, countVars + 1];
            string[] signs = new string[countLimits];

            for (int i = 0; i < countLimits + 1; i++)
            {
                if (i != countLimits)
                {
                    Console.WriteLine($"\t{i + 1} limit");
                    for (int j = 1; j < countVars + 1; j++)
                    {
                        Console.Write($"Coefficient at x{j}: ");
                        table[i, j] = double.Parse(Console.ReadLine());
                    }
                    Console.Write($"Restriction sign (>=, <=):  ");
                    signs[i] = Console.ReadLine();
                    Console.Write($"A free member:  ");
                    table[i, 0] = double.Parse(Console.ReadLine());
                }
                else
                {
                    table[i, 0] = 0;
                    Console.WriteLine("\t\tTarget function");
                    for (int j = 1; j < countVars + 1; j++)
                    {
                        Console.Write($"Coefficient at x{j} -->  ");
                        table[i, j] = double.Parse(Console.ReadLine()) * -1;
                    }
                }
            }



            funcCoff = new double[countVars];
            for (int i = 0; i < funcCoff.Length; i++)
                funcCoff[i] = table[table.GetLength(0) - 1, i + 1] * -1;

            Console.Clear();
            Simplex.ExportLineToExcel("Target function", sheet1, true, 5);
            Console.WriteLine("\t\tEntered Task");

            string func = "";
            for (int j = 1; j < countVars + 1; j++)
                func += ($"{table[countLimits, j] * -1}x{j} + ");

            func = func.Replace("+ -", "- ").Substring(0, func.Length - 3);
            Console.WriteLine($"f(x) = {func} -> {target_func}");
            Simplex.ExportLineToExcel($"f(x) = {func} -> {target_func}", sheet1, true, 5);
            Console.WriteLine("\n\tLimitations in the system");
            Simplex.ExportLineToExcel("Limitations in the system", sheet1, true, 5);
            for (int i = 0; i < countLimits; i++)
            {
                string limit = "";
                for (int j = 1; j < countVars + 1; j++)
                    if (table[i, j] == 0) limit += "";
                    else if (table[i, j] == 1)
                        limit += $"x{j} + ";
                    else
                        limit += $"{table[i, j]}x{j} + ";


                limit = limit.Replace("+ -", "- ").Substring(0, limit.Length - 3);
                limit += $" {signs[i]} {table[i, 0]}";
                Simplex.ExportLineToExcel(limit, sheet1, true, 5);
                Console.WriteLine(limit);
            }
            Console.WriteLine();


            double[] result = new double[countVars];
            double[,] table_result;
            Simplex S = new Simplex(table, signs, countLimits, countVars, target_func);
            table_result = S.Calculate(result);

            Simplex.table = table_result;

            Console.WriteLine("\n\tSolved simplex table:");
            printTable(table_result);

            Console.WriteLine();
            Console.WriteLine("\t\tSolution:");
            Simplex.ExportLineToExcel("Solution", sheet1, true, 1);
            for (int i = 0; i < countVars; i++)
            {
                Console.WriteLine($"X{i + 1} = {result[i]}");
                Simplex.ExportLineToExcel($"X{i + 1} = {result[i]}", sheet1, length: 1);
            }
            Console.WriteLine($"f(x) = {table_result[table_result.GetLength(0) - 1, 0]}");
            Simplex.ExportLineToExcel($"f(x) = {table_result[table_result.GetLength(0) - 1, 0]}", sheet1, length: 1);



            Simplex.currentCol = 1;
            Simplex.currentRow = 1;
            Simplex.ExportLineToExcel("The resulting table is solved by the simplex method", sheet2, true, table_result.GetLength(1));
            Simplex.ExportToExcel(table_result, sheet2);
            Simplex.Gomori(countVars);

            Console.Read();
        }

    }
}
