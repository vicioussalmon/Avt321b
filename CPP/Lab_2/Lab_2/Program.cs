using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;




namespace SecondLab 
{
class Program
    {
        static void Main(string[] args)
        {
            int[][] jaggedArray = new int[3][];
            //jaggedArray[0] = new int[5];
            //jaggedArray[1] = new int[2];
            //jaggedArray[2] = new int[10];

            //Random random = new Random();
            //for (int i = 0; i < jaggedArray.Length; i++)
            //{
            //    for (int j = 0; j < jaggedArray[i].Length; j++)
            //    {

            //        jaggedArray[i][j] = random.Next(100);

            //    }

            //}
            jaggedArray[0] = new int[5] { 1, 3, 4, 5, 9 };
            jaggedArray[1] = new int[2] { 2, 4 };
            jaggedArray[2] = new int[7] { 1, 3, 5, 6, 9, 7, 3 };


            Console.WriteLine("Your array:");
            PrintJaggedArray(jaggedArray);
            Console.WriteLine("Your new array:");
            ChangingJaggedArray(jaggedArray);


        }


        static void ChangingJaggedArray(int[][] jaggedArray)
        {
            float count = 0;
            int NewLength = 0;

            for (int i = 0; i < jaggedArray.Length; i++) 
            {
                for (int j = 0; j < jaggedArray[i].Length; j++) 
                    if (jaggedArray[i][j]%2 == 0) { 
                    count++;
                    }

                if (count != jaggedArray[i].Length) { NewLength++; }
                count = 0;  
                
               // Console.WriteLine(count);
            }
           

            int[][] NewjaggedArray = new int[NewLength][]; 

            for (int i = 0, k = 0; i < jaggedArray.Length; i++) 
            {
                for (int j = 0; j < jaggedArray[i].Length; j++)
                    if (jaggedArray[i][j] % 2 == 0) count++;

                if (count != jaggedArray[i].Length)
                    {
                        NewjaggedArray[k] = new int[jaggedArray[i].Length];
                        for (int j = 0; j < jaggedArray[i].Length; j++)
                            NewjaggedArray[k][j] = jaggedArray[i][j];
                        k++;
                    }
                count = 0;

            }




            PrintJaggedArray(NewjaggedArray);

        }

        static void PrintJaggedArray(int[][] jaggedArray)
        {
            for (int i = 0; i < jaggedArray.Length; i++)
            {
                for (int j = 0; j < jaggedArray[i].Length; j++)
                {
                    Console.Write(jaggedArray[i][j] + "\t");


                }
                Console.WriteLine();
            }


        }

        }


}