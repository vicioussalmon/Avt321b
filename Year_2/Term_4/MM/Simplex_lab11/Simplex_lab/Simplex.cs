using System;
using System.Collections.Generic;
using System.Data.Common;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Simplex_lab
{
    public class Simplex
    {
        private double[,] _data;
        private double[] _bi;
        private double[] _F;
        private double[] _FClone;
        private string[] _sign;
        private (string, int)[] Baza;

        public Simplex(double[,] data, double[] bi, double[] f, string[] sign)
        {
            _data = data;
            _FClone = (double[])f.Clone();
            _bi = bi;
            _F = f;
            _sign = sign;
            Baza = new (string, int)[_data.GetLength(0)];
        }

        public (string, int)[] GetBaza()
        {
            return ((string, int)[])Baza.Clone();
        }
        public double[] GetF()
        {
            return (double[])_F.Clone();
        }
        public double[] GetBi()
        {
            return (double[])_bi.Clone();
        }

        public double[,] GetData()
        {
            return (double[,])_data.Clone();
        }

        public double FResult()
        {
            double res = 0;// bi 2  4  1
                           //    x2 x4 x1
            for (int i = 0; i < Baza.Length; i++)
            {
                if (Baza[i].Item2 < _FClone.Length + 1)
                {
                    res += _FClone[Baza[i].Item2 - 1] * _bi[i + 1];
                }
            }
            return res;
        }
        public void ModernizePlusUltraMin()
        {
            double[,] temp = (double[,])_data.Clone();
            int col = Baza.Length - 1;
            double min = int.MaxValue;
            int row = 0;
            for (int i = 0; i < _data.GetLength(0); i++)
            {
                Baza[i].Item1 = "x" + (_FClone.Length + (i + 1));
                Baza[i].Item2 = _FClone.Length + (i + 1);
                if (min > _bi[i + 1] / _data[i, col] && _bi[i + 1] / _data[i, col] >= 0)
                {
                    min = _bi[i + 1] / _data[i, col];
                    row = i;
                }
            }

            for (int i = 0; i < _data.GetLength(0); i++)
            {

                for (int j = 0; j < temp.GetLength(1); j++)
                {
                    if (row == i)
                    {
                        temp[i, j] /= _data[row, col];
                    }
                    else
                    {
                        temp[i, j] -= (_data[row, j] * _data[i, col]) / _data[row, col];
                    }
                }
            }
            double bi = _bi[row + 1];
            for (int i = 1; i < _bi.Length; i++)
            {
                if (row + 1 == i)
                {
                    _bi[i] /= _data[row, col];
                }
                else
                {
                    _bi[i] -= (bi * _data[i - 1, col]) / _data[row, col];
                }
            }
            _data = temp;
            for (int i = 0; i < _F.Length; i++)
            {
                _F[i] -= _F[col] * _data[row, i];
            }
            _F[col] = 0;
        }
        public void ModernizePlusUltraMax()
        {
            double[,] temp = (double[,])_data.Clone();
            int col = Baza.Length - 1;
            double min = int.MaxValue;
            int row = 0;
            for (int i = 0; i < _data.GetLength(0); i++)
            {
                Baza[i].Item1 = "x" + (_FClone.Length + (i + 1));
                Baza[i].Item2 = (_FClone.Length + i + 1);
                if (min > _bi[i + 1] / _data[i, col] && _bi[i + 1] / _data[i, col] >= 0)
                {
                    min = _bi[i + 1] / _data[i, col];
                    row = i;
                }
            }

            for (int i = 0; i < _data.GetLength(0); i++)
            {

                for (int j = 0; j < temp.GetLength(1); j++)
                {
                    if (row == i)
                    {
                        temp[i, j] /= _data[row, col];
                    }
                    else
                    {
                        temp[i, j] -= (_data[row, j] * _data[i, col]) / _data[row, col];
                    }
                }
            }
            double bi = _bi[row + 1];
            for (int i = 1; i < _bi.Length; i++)
            {
                if (row + 1 == i)
                {
                    _bi[i] /= _data[row, col];
                }
                else
                {
                    _bi[i] -= (bi * _data[i - 1, col]) / _data[row, col];
                }
            }
            _data = temp;
            for (int i = 0; i < _F.Length; i++)
            {
                _F[i] -= _F[col] * _data[row, i];
            }
            _F[col] = 0;
        }
        public void Modernize()
        {
            int count = _sign.Count(element => element == "=");
            double[,] temp = new double[_data.GetLength(0), _data.GetLength(0) + _data.GetLength(1) - count];

            for (int i = 0; i < _data.GetLength(0); i++)
            {
                Baza[i].Item1 = "x" + (_data.GetLength(1) + i + 1);
                Baza[i].Item2 = _data.GetLength(1) + i + 1;
                for (int j = 0; j < _data.GetLength(1); j++)
                    temp[i, j] = _data[i, j];
            }

            int jndex = 0;
            for (int i = 0; i < temp.GetLength(0); i++)
            {
                if (_sign[i] == "<=")
                {
                    temp[i, _data.GetLength(1) + jndex] = 1;
                    jndex++;
                }
                else if (_sign[i] == ">=")
                {
                    temp[i, _data.GetLength(1) + jndex] = -1;
                    jndex++;
                }
            }

            for (int i = 0; i < temp.GetLength(0); i++)
            {
                for (int j = 0; j < temp.GetLength(1); j++)
                {
                    if (_sign[i] == ">=")
                        temp[i, j] *= -1;
                }
                if (_sign[i] == ">=")
                {
                    _sign[i] = "<=";
                    _bi[i + 1] *= -1;
                }
            }
            _data = temp;
            double[] tempF = new double[temp.GetLength(1)];
            for (int i = 0; i < _F.Length; i++)
            {
                tempF[i] = _F[i];
            }
            _F = tempF;
            for (int i = 0; i < _F.Length; i++)
            {
                _F[i] *= -1;
            }




            //StringBuilder sb = new StringBuilder();
            //for (int i = 0; i < _data.GetLength(0); i++)
            //{
            //    for (int j = 0; j < _data.GetLength(1); j++)
            //    {
            //        sb.Append(_data[i, j]);
            //        sb.Append('\t');
            //    }
            //    sb.AppendLine();
            //}

            //MessageBox.Show(sb.ToString());


            for (int j1 = 0; j1 < _bi.Length; j1++)
            {
                if (_bi[j1] < 0)
                {
                    j1--;

                    int Row = (Array.IndexOf(_bi, _bi.Min())) - 1;


                    double min = 0;
                    int Column = -1;
                    for (int i = 0; i < _data.GetLength(1); i++)
                    {
                        if (min > _data[Row, i])
                        {
                            min = _data[Row, i];
                            Column = i;
                        }
                    }

                    if (Column == -1)
                    {
                        throw new Exception("Розв'язок немає рішень");

                    }

                    Baza[Row].Item1 = "x" + (Column + 1);
                    Baza[Row].Item2 = Column + 1;
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
                }
            }

            //sb = new StringBuilder();
            //for (int i = 0; i < _data.GetLength(0); i++)
            //{
            //    for (int j = 0; j < _data.GetLength(1); j++)
            //    {
            //        sb.Append(_data[i, j]);
            //        sb.Append('\t');
            //    }
            //    sb.AppendLine();
            //}
            //MessageBox.Show(sb.ToString());



        }

        public bool Is_Optimal(bool boo)
        {
            return boo ? _F.Max() > 0 : _F.Min() < 0;
        }
        public void CalculateMin()
        {
            for (int i = 0; i < _sign.Length; i++)
            {
                if (_sign[i] == "=")
                {
                    ModernizePlusUltraMin();
                }
            }
            int Column = Array.IndexOf(_F, _F.Max());



            double min = int.MaxValue;
            int Row = -1;
            int t1 = 0;

            for (int i = 0; i < _data.GetLength(0); i++)
            {
                if ((min > (_bi[i + 1] / _data[i, Column])) && (_bi[i + 1] / _data[i, Column] >= 0))
                {
                    min = _bi[i + 1] / _data[i, Column];
                    Row = i;
                }
                if (_data[i, Column] < 0)
                {
                    t1++;
                }
            }

            if (Row == -1 || t1 == _bi.Length - 1)
            {
                throw new Exception("Розв'язок має безліч рішень");
            }




            Baza[Row].Item1 = "x" + (Column + 1);
            Baza[Row].Item2 = Column + 1;
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


        }

        public void CalculateMax()
        {
            for (int i = 0; i < _sign.Length; i++)
            {
                if (_sign[i] == "=")
                {
                    ModernizePlusUltraMax();
                }
            }
            int Column = Array.IndexOf(_F, _F.Min());


            double min = int.MaxValue;
            int Row = -1;
            int t1 = 0;
            for (int i = 0; i < _data.GetLength(0); i++)
            {
                if ((min > (_bi[i + 1] / _data[i, Column])) && (_bi[i + 1] / _data[i, Column] >= 0))
                {
                    min = _bi[i + 1] / _data[i, Column];
                    Row = i;
                }
                if (_data[i, Column] < 0)
                {
                    t1++;
                }
            }

            if (Row == -1 || t1 == _bi.Length - 1)
            {
                throw new Exception("Розв'язок має безліч рішень");
            }



            Baza[Row].Item2 = Column + 1;
            Baza[Row].Item1 = "x" + (Column + 1);
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




            //StringBuilder sb = new StringBuilder();
            //for (int i = 0; i < _data.GetLength(0); i++)
            //{
            //    for (int j = 0; j < _data.GetLength(1); j++)
            //    {
            //        sb.Append(_data[i, j]);
            //        sb.Append('\t');
            //    }
            //    sb.AppendLine();
            //}

            //MessageBox.Show(sb.ToString());
        }
    }

}