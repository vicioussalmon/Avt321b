using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Transport_lab
{
    internal class Minimum_cost_method
    {
        public int[][] B;
        int[][] initial;
        public int[] supply;
        public int[] demand;

        public Minimum_cost_method(int[][] B, int[] supply, int[] demand)
        {
            this.B = B;
            this.supply = supply;
            this.demand = demand;
            this.ModernizeMatrix();
            this.initial = (int[][])this.B.Clone();
        }
        public int[][] GetData()
        {
            int[][] copiedJaggedArray = new int[B.Length][];
            for (int i = 0; i < B.Length; i++)
            {
                copiedJaggedArray[i] = new int[B[i].Length];
                Array.Copy(B[i], copiedJaggedArray[i], B[i].Length);
            }
            return copiedJaggedArray;
        }
        public int[][] GetInitial()
        {
            int[][] copiedJaggedArray = new int[initial.Length][];
            for (int i = 0; i < initial.Length; i++)
            {
                copiedJaggedArray[i] = new int[initial[i].Length];
                Array.Copy(initial[i], copiedJaggedArray[i], initial[i].Length);
            }
            return copiedJaggedArray;
        }
        public int[] GetDemand()
        {
            int[] array2 = (int[])demand.Clone();
            return array2;
        }
        public int[] GetSupply()
        {
            int[] array2 = (int[])supply.Clone();
            return array2;
        }
        public int TotalSum()
        {
            int totalSum = 0;

            for (int i = 0; i < B.Length; i++)
                for (int j = 0; j < B[i].Length; j++)
                {
                    if (B[i][j] == int.MaxValue)
                        B[i][j] = 0;

                    if (initial[i][j] == int.MaxValue)
                        initial[i][j] = 0;

                    totalSum += initial[i][j] * B[i][j];
                }
            return totalSum;
        }

        private void ModernizeMatrix()
        {
            if (demand.Sum() == supply.Sum())
                return;

            bool addFlag = demand.Sum() > supply.Sum() ? true : false;
            int devision = Math.Abs(demand.Sum() - supply.Sum());

            if (!addFlag)
            {
                demand = demand.Append(devision).ToArray();

                for (int i = 0; i < B.Length; i++)
                    B[i] = B[i].Append(int.MaxValue).ToArray();
            }
            else
            {
                supply = supply.Append(devision).ToArray();

                int[] tempRow = new int[demand.Length];
                for (int i = 0; i < tempRow.Length; i++)
                    tempRow[i] = int.MaxValue;

                B = B.Append(tempRow).ToArray();
            }
        }

        public void Calculate()
        {

            var t = new Dictionary<string, List<int>>();
            t["str"] = new List<int>();
            t["stl"] = new List<int>();
            var r = new int[B.Length][];
            for (int i = 0; i < B.Length; i++)
            {
                r[i] = new int[B[i].Length];
                for (int j = 0; j < B[i].Length; j++)
                {
                    r[i][j] = int.MaxValue;
                }
            }

            for (int k = 0; k < B.Length * B[0].Length; k++)
            {
                var (i, j) = getMin(B, t);

                if (i == int.MaxValue || j == int.MaxValue)
                {
                    B = r;
                    return;
                }

                (int, int) info = (supply[i], demand[j]);

                if (info.Item1 >= info.Item2)
                {
                    r[i][j] = info.Item2;
                    supply[i] -= info.Item2;
                    t["stl"].Add(j);
                }
                else
                {
                    r[i][j] = info.Item1;
                    demand[j] -= info.Item1;
                    t["str"].Add(i);
                }
            }
            B = r;
            return;
        }
        private (int, int) getMin(int[][] a, Dictionary<string, List<int>> r)
        {
            int min = int.MaxValue, str = int.MaxValue, stl = int.MaxValue;

            for (int i = 0; i < a.Length; i++)
            {
                for (int j = 0; j < a[i].Length; j++)
                {


                    if (min == int.MaxValue || a[i][j] < min)
                    {
                        if (r["str"].Contains(i) || r["stl"].Contains(j))
                        {
                            continue;
                        }
                        min = a[i][j];
                        str = i;
                        stl = j;
                    }
                }
            }
            return (str, stl);
        }
    }
}
