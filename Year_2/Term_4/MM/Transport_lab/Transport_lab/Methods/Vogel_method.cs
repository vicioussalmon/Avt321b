using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Transport_lab
{
    internal class Vogel_method
    {
        private int nRows;//количество строк
        private int nCols;//количество столбцов
        private int totalCost;

        private List<List<int>> costsCopy;
        private List<List<int>> result;
        private List<int> demand;
        private List<int> supply;
        private List<List<int>> costs;

        public Vogel_method(List<List<int>> costs, List<int> demand, List<int> supply)
        {
            this.demand = demand;
            this.supply = supply;
            this.costs = costs;
            nRows = supply.Count;
            nCols = demand.Count;
            result = Enumerable.Repeat(0, nRows).Select(_ => Enumerable.Repeat(0, nCols).ToList()).ToList();
            totalCost = 0;
            amount();
        }

        public List<List<int>> GetCopy()
        {
            List<List<int>> copiedList = new List<List<int>>(costsCopy);
            return copiedList;
        }
        public List<List<int>> GetResult()
        {
            List<List<int>> copiedList = new List<List<int>>(result);
            return copiedList;
        }
        public List<int> GetDemand()
        {
            List<int> copiedList = new List<int>(demand);
            return copiedList;
        }
        public List<int> GetSupply()
        {
            List<int> copiedList = new List<int>(supply);
            return copiedList;
        }
        public int GetSum()
        {
            int temp = totalCost;
            return temp;
        }
        private List<List<int>> CopyList()//копирует начальную матрицу
        {
            List<List<int>> temp = new List<List<int>>();
            for (int i = 0; i < costs.Count; i++)
            {
                temp.Add(new List<int>()); // добавить новый список

                for (int j = 0; j < costs[i].Count; j++)
                {
                    temp[i].Add(costs[i][j]);
                }
            }
            return temp;
        }
        public void amount()//корректирует балланс demand и supply
        {
            int dif = Math.Abs(demand.Sum() - supply.Sum());

            if (demand.Sum() < supply.Sum())
            {
                demand.Add(dif);

                for (int i = 0; i < costs.Count; i++)
                {
                    costs[i].Add(0);
                }
                nCols++;
            }
            else if (demand.Sum() > supply.Sum())
            {
                supply.Add(dif);
                List<int> list = new List<int>();
                for (int i = 0; i < costs[0].Count; i++)
                {
                    list.Add(0);
                }
                costs.Add(list);
                nRows++;
            }

            result = Enumerable.Repeat(0, nRows).Select(_ => Enumerable.Repeat(0, nCols).ToList()).ToList();
        }

        public List<int> MaxDiffR()//находит разницу минимальных элементов в строке
        {
            int diff = 0;
            List<List<int>> test = new List<List<int>>();

            for (int i = 0; i < nRows; i++)
            {
                test.Add(new List<int>()); // добавить новый список

                for (int j = 0; j < costs[i].Count; j++)
                {
                    test[i].Add(costs[i][j]);
                }
            }

            List<int> DiffR = new List<int>(nRows);

            for (int i = 0; i < nRows; i++)
            {
                int minValue = 999999;
                int indexValue = 0;

                for (int j = 0; j < nCols; j++)
                {
                    if (minValue > test[i][j] && test[i][j] != -1 && test[i][j] != 0)
                    {
                        minValue = test[i][j];
                        indexValue = j;
                    }
                }
                test[i][indexValue] = 999999;
                diff -= minValue;
                minValue = test[i].Min();
                minValue = 999999;

                for (int j = 0; j < nCols; j++)
                {
                    if (minValue > test[i][j] && test[i][j] != -1 && test[i][j] != 0)
                    {
                        minValue = test[i][j];
                        indexValue = j;
                    }
                }
                diff += minValue;
                DiffR.Add(diff);
                diff = 0;
            }
            return DiffR;
        }

        public List<int> MaxDiffC()//находит разницу минимальных элементов в колонке
        {
            int diff = 0;
            List<List<int>> test = new List<List<int>>();

            for (int i = 0; i < costs.Count; i++)
            {
                test.Add(new List<int>()); // добавить новый список

                for (int j = 0; j < costs[i].Count; j++)
                {
                    test[i].Add(costs[i][j]);
                }
            }

            List<int> DiffC = new List<int>(nCols);

            for (int j = 0; j < nCols; j++)
            {
                int minValue = 999999;
                int indexValue = 0;

                for (int i = 0; i < costs.Count; i++)
                {
                    if (minValue > test[i][j] && test[i][j] != -1 && test[i][j] != 0)
                    {
                        minValue = test[i][j];
                        indexValue = i;
                    }
                }
                test[indexValue][j] = 999999;
                if (minValue == 999999)
                {
                    minValue = 0;
                }
                diff -= minValue;
                minValue = 999999;

                for (int i = 0; i < costs.Count; i++)
                {
                    if (minValue > test[i][j] && test[i][j] != -1 && test[i][j] != 0)
                    {
                        minValue = test[i][j];
                        indexValue = i;
                    }
                }
                test[indexValue][j] = 999999;

                if (minValue == 999999)
                {
                    minValue = 0;
                }

                diff += minValue;
                DiffC.Add(diff);
                diff = 0;
            }
            return DiffC;
        }

        public void MatrixTransform(int check, int index)//Изменяет начальную таблицу записывая -1 и записывает в result записывает минимальное на пересечении supply and demand
        {
            int minValue = 999999;
            int indexC = 0;
            int indexR = 0;

            if (check == 0)
            {
                for (int j = 0; j < nCols; j++)
                {
                    if (minValue > costs[index][j] && costs[index][j] != -1 && costs[index][j] != 0)
                    {
                        minValue = costs[index][j];
                        indexR = index;
                        indexC = j;
                    }
                }
            }
            else
            {
                for (int i = 0; i < nRows; i++)
                {
                    if (minValue > costs[i][index] && costs[i][index] != -1 && costs[i][index] != 0)
                    {
                        minValue = costs[i][index];
                        indexR = i;
                        indexC = costs[i].IndexOf(minValue);
                    }
                }
            }
            if (demand[indexC] == supply[indexR])
            {
                result[indexR][indexC] = supply[indexR];
                supply[indexR] = 0;
                demand[indexC] = 0;

                for (int i = 0; i < nCols; i++)
                {
                    costs[indexR][i] = -1;
                }
                for (int i = 0; i < nRows; i++)
                {
                    costs[i][indexC] = -1;
                }
            }
            else if (demand[indexC] > supply[indexR])
            {
                result[indexR][indexC] = supply[indexR];
                demand[indexC] = demand[indexC] - supply[indexR];
                supply[indexR] = 0;

                for (int i = 0; i < nCols; i++)
                {
                    costs[indexR][i] = -1;
                }
            }
            else
            {
                result[indexR][indexC] = demand[indexC];
                supply[indexR] = supply[indexR] - demand[indexC];
                demand[indexC] = 0;

                for (int i = 0; i < nRows; i++)
                {
                    costs[i][indexC] = -1;
                }
            }
        }

        public void MatrixTransformOne()//Изменяет начальную таблицу записывая -1 и записывает в result записывает минимальное на пересечении supply and demand в случае когда осталось одно число в supply или demand
        {
            int minValue = 999999;
            int index = 0;
            int indexC = 0;
            int indexR = 0;

            if (demand.Max() == demand.Sum())
            {
                index = demand.IndexOf(demand.Max());

                for (int i = 0; i < nRows; i++)
                {
                    if (minValue > costs[i][index] && costs[i][index] != -1)
                    {
                        minValue = costs[i][index];
                        indexR = i;
                        indexC = costs[i].IndexOf(minValue);
                    }
                }
            }
            else
            {
                index = supply.IndexOf(supply.Max());

                for (int i = 0; i < nCols; i++)
                {
                    if (minValue > costs[index][i] && costs[index][i] != -1)
                    {
                        minValue = costs[index][i];
                        indexC = i;
                        indexR = index;
                    }
                }
            }

            if (demand[indexC] == supply[indexR])
            {
                result[indexR][indexC] = demand[indexC];
                supply[indexR] = 0;
                demand[indexC] = 0;

                for (int i = 0; i < nCols; i++)
                {
                    costs[indexR][i] = -1;
                }
                for (int i = 0; i < nRows; i++)
                {
                    costs[i][indexC] = -1;
                }
            }
            else if (demand[indexC] > supply[indexR])
            {
                result[indexR][indexC] = supply[indexR];
                demand[indexC] = demand[indexC] - supply[indexR];
                supply[indexR] = 0;

                for (int i = 0; i < nCols; i++)
                {
                    costs[indexR][i] = -1;
                }
            }
            else
            {
                result[indexR][indexC] = demand[indexC];
                supply[indexR] = supply[indexR] - demand[indexC];
                demand[indexC] = 0;

                for (int i = 0; i < nRows; i++)
                {
                    costs[i][indexC] = -1;
                }
            }
        }

        public void AlgoritmWork()//основной алгоритм
        {
            
            costsCopy = CopyList();
            while (demand.Max() != 0 || supply.Max() != 0)
            {

                List<int> maxdiffR = MaxDiffR();
                List<int> maxdiffC = MaxDiffC();
                int max = 0;
                int index = 0;

                if (demand.Max() == demand.Sum() || supply.Max() == supply.Sum())
                {
                    MatrixTransformOne();
                }
                else
                {
                    if (maxdiffR.Max() >= maxdiffC.Max())
                    {
                        max = maxdiffR.Max();
                        index = maxdiffR.IndexOf(max);
                        MatrixTransform(0, index);
                    }
                    else
                    {
                        max = maxdiffC.Max();
                        index = maxdiffC.IndexOf(max);

                        MatrixTransform(1, index);
                    }
                }
            }
            Total();
        }
        public void Print()//печать суммы и результирующей таблицы
        {
            foreach (var row in costs)
            {
                Console.WriteLine(string.Join(", ", row));
            }
            foreach (var row in result)
            {
                Console.WriteLine(string.Join(", ", row));
            }
            foreach (var row in costsCopy)
            {
                Console.WriteLine(string.Join(", ", row));
            }
            Total();
            Console.WriteLine("Total cost: " + totalCost);
        }
        public void Total()//подсчет суммы
        {
            for (int i = 0; i < costs.Count; i++)
            {
                for (int j = 0; j < costs[i].Count; j++)
                {
                    if (result[i][j] != 0)
                    {
                        totalCost += result[i][j] * costsCopy[i][j];
                    }
                }
            }
        }
    }
}
