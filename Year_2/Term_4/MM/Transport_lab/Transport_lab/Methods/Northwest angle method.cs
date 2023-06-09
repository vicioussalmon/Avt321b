using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Transport_lab
{
    internal class Northwest_angle_method
    {
        const int MAX = 100;
        int[,] data = new int[MAX, MAX];
        int[] required = new int[MAX];
        int[] capacity = new int[MAX];
        int[,] allocation = new int[MAX, MAX];
        int rows, columns, no_of_allocation;

        public Northwest_angle_method()
        {
            for (int i = 0; i < MAX; i++)
            {
                capacity[i] = 0;
                required[i] = 0;
                for (int j = 0; j < MAX; j++)
                {
                    data[i, j] = 0;
                    allocation[i, j] = 0;
                }
            }
            rows = columns = no_of_allocation = 0;
        }

        // Define tamanho da coluna
        public void SetColumn(int col)
        {
            columns = col;
        }

        // Define tamanho da linha
        public void SetRow(int row)
        {
            rows = row;
        }

        // Popula matriz com os custos
        public void PopulateCosts(int[,] matrix)
        {
            
            for(int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns;j++)
                {
                    data[i,j]  = matrix[i,j];
                }
            }
        }

        // Popula matriz com as ofertas
        public void PopulateOffers(int[] supply)
        {
            for (int i = 0; i < rows; i++)
            {
                capacity[i] = supply[i];
            }
        }

        // Popula matriz com as demandas
        public void PopulateDemands(int[] demand)
        {
            for (int i = 0; i < columns; i++)
            {
                required[i] = demand[i];
            }
        }
        public int[,] GetData2()
        {
            int[,] copy = new int[rows, columns];
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    copy[i, j] = data[i, j];
                }
            }
            return copy;
        }
        public int[,] GetData()
        {
            int[,] copy = new int[rows,columns];
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    copy[i,j] = allocation[i, j];
                }
            }
            return copy;
        }
        public int[] GetDemand()
        {
            int[] demand = new int[columns];
            for (int i = 0; i < columns; i++)
            {
                demand[i] = required[i];
            }
            return demand;

        }
        public int[] GetSupply()
        {
            int[] Supply = new int[rows];
            for (int i = 0; i < rows; i++)
            {
                Supply[i] = capacity[i];
            }
            return Supply;
        }
        // Verifica se todos os valores do array são zero
        private Boolean CheckValue(int[] arr, int no)
        {
            for (int i = 0; i < no; i++)
            {
                if (arr[i] != 0)
                {
                    return false;
                }
            }
            return true;
        }

        // Duplica valores de um vetor em outro
        private void DuplicateArray(int size, int[] source, int[] destination)
        {
            for (int i = 0; i < size; i++)
            {
                destination[i] = source[i];
            }
        }

        // Calcula a soma total de um array
        private int GetTotal(int[] array, int no)
        {
            int sum = 0;
            for (int i = 0; i < no; i++)
            {
                sum += array[i];
            }
            return sum;
        }

        // Realiza a alocação da matriz
        public void AllocateMatrix()
        {
            int i = 0, j = 0;
            int[] temp_required = new int[MAX];
            int[] temp_capacity = new int[MAX];
            int sum_of_cap, sum_of_req;

            sum_of_cap = GetTotal(capacity, rows);
            sum_of_req = GetTotal(required, columns);
            if (sum_of_cap != sum_of_req)
            {
                if (sum_of_cap > sum_of_req)
                {
                    for (j = 0; j < rows; j++)
                    {
                        data[j, columns] = 0;
                    }
                    required[columns] = sum_of_cap - sum_of_req;
                    columns++;
                }
                else
                {
                    for (j = 0; j < columns; j++)
                    {
                        data[rows, j] = 0;
                    }
                    capacity[rows] = sum_of_req - sum_of_cap;
                    rows++;
                }
            }

            i = j = 0;

            DuplicateArray(rows, capacity, temp_capacity);
            DuplicateArray(columns, required, temp_required);

            while (!CheckValue(temp_capacity, rows) || !CheckValue(temp_required, columns))
            {
                if (temp_capacity[i] > temp_required[j])
                {
                    allocation[i, j] = temp_required[j];
                    temp_capacity[i] -= temp_required[j];
                    temp_required[j] = 0;
                    j++;
                }
                else if (temp_capacity[i] < temp_required[j])
                {
                    allocation[i, j] = temp_capacity[i];
                    temp_required[j] -= temp_capacity[i];
                    temp_capacity[i] = 0;
                    i++;
                }
                else
                {
                    allocation[i, j] = temp_capacity[i];
                    temp_capacity[i] = temp_required[j] = 0;
                    i++;
                    j++;
                }
                no_of_allocation++;
            }
        }


        public void Optimalplane()
        {
            int[] v = new int[columns]; // потенциал столбца
            int[] u = new int[rows];    // потенциал строки
            u[0] = 0;

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (allocation[i, j] != 0)
                    {
                        if (i == 0)
                        {
                            v[j] = data[i, j];
                        }
                        else
                        {
                            if (v[j] != 0)
                            {
                                u[i] = data[i, j] - v[j];
                            }
                            else if (u[i] != 0)
                            {
                                v[j] = data[i, j] - u[i];
                            }
                        }
                    }
                }
            }

            Console.WriteLine("U=");
            for (int i = 0; i < rows; i++)
            {
                Console.WriteLine(u[i] + "  ");
            }

            Console.WriteLine("V=");
            for (int j = 0; j < columns; j++)
            {
                Console.Write(v[j] + "   ");
            }
            Console.WriteLine();

            int max = int.MinValue;
            int u_index = 0;
            int v_index = 0;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (u[i] + v[j] > data[i, j])
                    {
                        Console.WriteLine(u[i] + "+" + v[j] + "=" + ((u[i] + v[j]) - data[i, j]) + ">" + 0);
                        if (max < ((u[i] + v[j]) - data[i, j]))
                        {
                            max = ((u[i] + v[j]) - data[i, j]);
                            u_index = i;
                            v_index = j;
                        }
                        else if (max == int.MinValue)
                        {
                            Console.WriteLine("Plan oporniy");
                            return;
                        }
                    }
                }
            }
            Console.WriteLine($"max ={max}, \nмакс яч = ({u_index} ,{v_index})");
            Console.WriteLine("_____________________________________________");
            int[,] kv = new int[rows, columns];

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (allocation[i, j] != 0)
                    {
                        kv[i, j] = data[i, j] * allocation[i, j];
                    }
                    else
                    {
                        kv[i, j] = data[i, j];
                    }
                }
                Console.WriteLine();
            }
        }

        public void Display()
        {
            Console.WriteLine();
            Console.Write("{0,9}", "");
            for (int i = 0; i < columns; i++)
            {
                Console.Write("D{0}{1}", i + 1, "    ");
            }
            Console.WriteLine("{0}{1}", "Oferta", "");
            for (int i = 0; i < rows; i++)
            {
                Console.Write("{0,3}{1}", "S" + (i + 1), "");
                for (int j = 0; j < columns; j++)
                {
                    Console.Write("{0,5}", data[i, j]);
                }
                Console.WriteLine("{0,5}", capacity[i]);
            }
            Console.Write("{0,4}{1}", "Demanda:", "");
            for (int i = 0; i < columns; i++)
            {
                Console.Write("{0,5}", required[i]);
            }

            Console.WriteLine("\n\nApos a alocacao:");
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (allocation[i, j] != 0)
                    {
                        Console.Write("\t{0}[{1}]", data[i, j], allocation[i, j]);
                    }
                    else
                    {
                        Console.Write("\t{0}", data[i, j]);
                    }
                }
                Console.WriteLine();
            }

            int k = 0, sum = 0;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (allocation[i, j] != 0)
                    {
                        if (k < no_of_allocation - 1)
                        {
                            k++;
                        }
                        sum += data[i, j] * allocation[i, j];
                    }
                }
            }

            Console.WriteLine("\nanswer : {0}", sum);
            if ((rows + columns - 1) == no_of_allocation)
            {
                Console.WriteLine("\nEssa eh uma solucao nao otimizada!");
            }
            else
            {
                Console.WriteLine("\nОБЕМе");
            }
        }
        public int GetSum()
        {
            int k = 0, sum = 0;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (allocation[i, j] != 0)
                    {
                        if (k < no_of_allocation - 1)
                        {
                            k++;
                        }
                        sum += data[i, j] * allocation[i, j];
                    }
                }
            }
            return sum;
        }
    }
}