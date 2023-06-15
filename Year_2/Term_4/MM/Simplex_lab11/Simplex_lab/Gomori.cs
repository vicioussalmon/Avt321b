using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;

namespace Simplex_lab
{
    class Gomori
    {

        private double[,] _data;
        private double[] _bi;
        private double[] _F;
        private int _FLength;
        private (string, int)[] _Baza;
        public Gomori(double[,] data, double[] bi, double[] f, (string, int)[] Baza, int F_length)
        {
            _data = data;
            _FLength = F_length;
            _bi = bi;
            _F = f;
            _Baza = Baza;
        }

        public static double CustomRound(double number)
        {
            double threshold = 0.001; // Пороговое значение для определения приближенных дробей
            if (Math.Abs(number) < 0.0000001)
            {
                number = 0;
            }
            // Проверяем, является ли число приближенной дробью
            if (Math.Abs(number - Math.Round(number)) < threshold && Math.Abs(number % 1) > threshold)
            {
                return Math.Round(number); // Округляем приближенную дробь до целого числа
            }
            else
            {
                return number; // Оставляем обычные дроби без изменений
            }
        }



        public void AbobeBababa()
        {

        }



        public (string, int)[] GetgomoriBaza()
        {
            return ((string, int)[])_Baza.Clone();
        }
        public double[] GetgomoriF()
        {
            return (double[])_F.Clone();
        }
        public double[] GetgomoriBi()
        {
            return (double[])_bi.Clone();
        }

        public double[,] GetgomoriData()
        {
            return (double[,])_data.Clone();
        }




        public double GetDrobPart(double num)
        {
            num = CustomRound(num);
            return num < 0 ? num + (-1) * Math.Floor(num) : num % 1;
        }



        public void Modernize()
        {

            double max = double.MinValue;
            int jndex = -1;
            double JndexBigProMax;

            double[,] gomoriData = new double[_data.GetLength(0) + 1, _data.GetLength(1) + 1];
            double[] gomoriF = new double[_F.Length + 1];
            double[] gomoriBi = new double[_bi.Length + 1];
            (string, int)[] gomoriBaza = new (string, int)[_Baza.Length + 1];

            for (int i = 1; i < _bi.Length; i++)
            {
                JndexBigProMax = GetDrobPart(_bi[i]);
                JndexBigProMax = CustomRound(JndexBigProMax); 
                if (max < JndexBigProMax && _Baza[i - 1].Item2 < _FLength + 1)
                {
                    max = JndexBigProMax;
                    jndex = i;
                }

            }


            
            for (int i = 0; i < _data.GetLength(0); i++)
            {
                for (int j = 0; j < _data.GetLength(1); j++)
                {

                    _data[i, j] = CustomRound(_data[i, j]);

                }
            }

            for (int i = 0; i < _F.Length; i++)
            {
                _F[i] = CustomRound(_F[i]);
            }

            for (int i = 0; i < _bi.Length; i++)
            {
                _bi[i] = CustomRound(_bi[i]);
            }



            



            for (int i = 0; i < _data.GetLength(0); i++)
            {
                for (int j = 0; j < _data.GetLength(1); j++)
                {
                    gomoriData[i, j] = _data[i, j];
                }
            }

            for (int i = 0; i < _F.Length; i++)
            {
                gomoriF[i] = _F[i];
            }

            for (int i = 1; i < _bi.Length; i++)
            {

                gomoriBi[i] = _bi[i];
            }

            gomoriBi[0] = _bi[0];

            for (int i = 0; i < gomoriData.GetLength(1); i++)
            {
                gomoriData[gomoriData.GetLength(0) - 1, i] = GetDrobPart(gomoriData[jndex - 1, i]) * (-1);

            }
            gomoriData[gomoriData.GetLength(0) - 1, gomoriData.GetLength(1) - 1] = 1;
            gomoriBi[gomoriBi.Length - 1] = CustomRound(GetDrobPart(gomoriBi[jndex]) * (-1));

            for (int i = 0; i < _Baza.Length; i++)
            {
                gomoriBaza[i] = _Baza[i];
            }
            gomoriBaza[gomoriBaza.Length - 1].Item1 = "x" + (gomoriData.GetLength(1));
            gomoriBaza[gomoriBaza.Length - 1].Item2 = (gomoriData.GetLength(1));




            _data = gomoriData;
            _bi = gomoriBi;
            _F = gomoriF;
            _Baza = gomoriBaza;

        }


        public bool isGemoroi()
        {


            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < _bi.Length; i++)
            {

                sb.Append(_bi[i]);


                sb.AppendLine();
            }

           


            for (int i = 0; i < _Baza.Length; i++)
            {
                _bi[i + 1] = CustomRound(_bi[i + 1]);

                if (_Baza[i].Item2 < _FLength + 1)
                {


                    if ((Math.Round(_bi[i+1], 3)) % 1 > 0.01 && 1 - (Math.Round(_bi[i+1], 3)) % 1 > 0.01)
                    {

                        return true;
                    }

                }
            }
            return false;
        }


        public void CalZalUpaProMAxDouble()
        {
            
            int Row = _bi.Length - 2;


            double min = 0;
            int Column = -1;
            for (int i = 0; i < _data.GetLength(1); i++)
            {
                if (min > _data[Row, i])
                {
                    min = _data[Row, i];
                    Column = i;
                    break;
                }

            }
            
            if (Column == -1)
            {
                throw new Exception("Розв'язок немає рішень");

            }

            _Baza[Row].Item2 = Column + 1;
            _Baza[Row].Item1 = "x" + (Column + 1);
            double val = _data[Row, Column];
            _bi[Row + 1] /= val;
            for (int i = 0; i < _data.GetLength(1); i++)
            {
                _data[Row, i] /= val;
            }

            for (int i = 0; i < _data.GetLength(0); i++)
            {
                double k = _data[i, Column] * -1;
                if (i != Row)
                {
                    for (int j = 0; j < _data.GetLength(1); j++)
                    {
                        _data[i, j] += _data[Row, j] * k;
                    }
                    _bi[i + 1] += _bi[Row + 1] * k;
                }
            }
            double t = _F[Column] * -1;
            for (int i = 0; i < _data.GetLength(1); i++)
            {
                _F[i] += _data[Row, i] * t;
            }
            _bi[0] += _bi[Row + 1] * t;




            for (int i = 0; i < _data.GetLength(0); i++)
            {
                for (int j = 0; j < _data.GetLength(1); j++)
                {

                    _data[i, j] = CustomRound(_data[i, j]);

                }
            }

            for (int i = 0; i < _F.Length; i++)
            {
                _F[i] = CustomRound(_F[i]);
            }

            for (int i = 0; i < _bi.Length; i++)
            {
                _bi[i] = CustomRound(_bi[i]);
            }



        }

    }


}

