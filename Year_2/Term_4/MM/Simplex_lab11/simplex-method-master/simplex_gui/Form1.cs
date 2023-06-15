using System;
using System.Windows.Forms;
using System.Collections;
using System.IO;
using OfficeOpenXml;
using System.Data.Common;


namespace Simplex_Method
{
    public partial class Form1 : Form
    {
        private int number_of_variables, number_of_constraints;
        private double[,] matrix;
        private ArrayList string_c;
        private ArrayList string_r;
        private int x, y;

        public Form1()
        {
            InitializeComponent();
        }

        private void buttonOk_Click(object sender, EventArgs e)
        {
            try
            {
                number_of_variables = int.Parse(textBoxNumberOfVariables.Text);
                number_of_constraints = int.Parse(textBoxNumberOfConstraints.Text);
                if (number_of_variables < 1 || number_of_constraints < 1 || number_of_variables > 10 || number_of_constraints > 10)
                    throw new Exception();
            }
            catch
            {
                MessageBox.Show("Incorrect value!");
                this.Close();
            }

            Controls.Clear();

            x = 0;
            y = 0;

            Label label_coef = new Label();
            label_coef.Text = "Objective function to maximize:";
            label_coef.AutoSize = true;
            label_coef.Font = new System.Drawing.Font("TimesNewRoman", 14);
            label_coef.Location = new System.Drawing.Point(x, y);
            Controls.Add(label_coef);
            
            y += 40;
            x = 0;
            
            for (int i = 0; i < number_of_variables; i++) 
            {
                TextBox txtbx = new TextBox();
                txtbx.Location = new System.Drawing.Point(x+20, y);
                txtbx.Name = "txtbxFuncCoef" + i;
                txtbx.MaxLength = 3;
                txtbx.TextAlign = HorizontalAlignment.Center;
                txtbx.Font = new System.Drawing.Font("TimesNewRoman", 14);
                txtbx.Size = new System.Drawing.Size(30, 30);
                Controls.Add(txtbx);
                
                x += 50;

                Label lab = new Label();
                lab.Location = new System.Drawing.Point(x, y + 3);
                lab.Size = new System.Drawing.Size(30, 30);
                lab.Font = new System.Drawing.Font("TimesNewRoman", 14);
                lab.Text = "x" + (i + 1);
                Controls.Add(lab);

                x += 20;
            }

            Label lab1 = new Label();
            lab1.Location = new System.Drawing.Point(x+20, y+3);
            lab1.Size = new System.Drawing.Size(20, 20);
            lab1.Font = new System.Drawing.Font("TimesNewRoman", 14);
            lab1.Text = "=";
            Controls.Add(lab1);
            
            x += 10;

            TextBox txtbx2 = new TextBox();
            txtbx2.Location = new System.Drawing.Point(x + 50, y);
            txtbx2.Name = "txtbxFuncRhs";
            txtbx2.Text = "0";
            txtbx2.MaxLength = 3;
            txtbx2.Font = new System.Drawing.Font("TimesNewRoman", 14);
            txtbx2.Size = new System.Drawing.Size(30, 30);
            txtbx2.TextAlign = HorizontalAlignment.Center;
            Controls.Add(txtbx2);

            y += 40;
            
            Label label_const = new Label();
            label_const.Text = "Constraints:";
            label_const.Font = new System.Drawing.Font("TimesNewRoman", 14);
            label_const.Location = new System.Drawing.Point(0, y);

            Controls.Add(label_const);

            y += 40;
            x = 0;
            
            for (int i = 0; i < number_of_constraints; i++)
            {
                for (int j = 0; j < number_of_variables; j++)
                {
                    TextBox txtbx = new TextBox();
                    txtbx.Location = new System.Drawing.Point(x + 20, y);
                    txtbx.Name = "txtbxConst" + (i * number_of_variables + j);
                    txtbx.MaxLength = 3;
                    txtbx.TextAlign = HorizontalAlignment.Center;
                    txtbx.Font = new System.Drawing.Font("TimesNewRoman", 14);
                    txtbx.Size = new System.Drawing.Size(30, 30);
                    Controls.Add(txtbx);
                    
                    x += 50;

                    Label lab = new Label();
                    lab.Location = new System.Drawing.Point(x, y+3);
                    lab.Size = new System.Drawing.Size(30, 30);
                    lab.Font = new System.Drawing.Font("TimesNewRoman", 14);
                    lab.Text = "x" + (j + 1);
                    Controls.Add(lab);
                    
                    x += 20;
                }
                
                Label lab2 = new Label();
                lab2.Location = new System.Drawing.Point(x + 15, y+3);
                lab2.Size = new System.Drawing.Size(40, 30);
                lab2.Font = new System.Drawing.Font("TimesNewRoman", 14);
                lab2.Text = "<=";
                Controls.Add(lab2);
            
                TextBox txtbx3 = new TextBox();
                txtbx3.Location = new System.Drawing.Point(x + 60, y);
                txtbx3.Name = "txtbxConstRhs"+i;
                txtbx3.TextAlign = HorizontalAlignment.Center;
                txtbx3.Font = new System.Drawing.Font("TimesNewRoman", 14);
                txtbx3.MaxLength = 3;
                txtbx3.Size = new System.Drawing.Size(30, 30);
                Controls.Add(txtbx3);
                
                y += 40;
                x = 0;
            }

            y += 10; 
            Button butSolve = new Button();
            butSolve.Location = new System.Drawing.Point(x + 90, y);
            butSolve.Name = "butSolve";
            butSolve.Text = "Solve!";
            butSolve.Size = new System.Drawing.Size(90, 30);
            butSolve.Font = new System.Drawing.Font("TimesNewRoman", 14);
            Controls.Add(butSolve);
            butSolve.Click += new System.EventHandler(this.butSolve_Click);

        }

        private void butSolve_Click(object sender, EventArgs e)
        {
            if (File.Exists("simplex.xlsx"))
            {
                File.Delete("simplex.xlsx");
            }
            ExcelPackage.LicenseContext = OfficeOpenXml.LicenseContext.NonCommercial;
            using (var excelPackage = new ExcelPackage("simplex.xlsx"))
            {
                // Создание листа
                ExcelWorksheet worksheet = excelPackage.Workbook.Worksheets.Add("simplex");

                worksheet.Cells["A1"].Value = " ";

                // Сохранение файла
                excelPackage.SaveAs(new FileInfo("simplex.xlsx"));
            }




            matrix = new double[number_of_constraints + 1, number_of_variables + number_of_constraints + 1];

            try
            {
                for (int i = 0; i < number_of_variables; i++)
                {
                    matrix[0, i] = -1*double.Parse(Controls.Find("txtbxFuncCoef" + i, false)[0].Text);
                }
                
            }
            catch
            {
                MessageBox.Show("Incorrect value!");
                this.Close();
            }

            for (int i = number_of_variables; i < number_of_variables + number_of_constraints; i++)
            {
                matrix[0, i] = 0;
            }

            Control[] funcRhs = Controls.Find("txtbxFuncRhs", false);
            try
            {
                matrix[0, number_of_variables + number_of_constraints] = double.Parse(funcRhs[0].Text);
            }
            catch
            {
                MessageBox.Show("Incorrect value!");
                this.Close();
            }

            try
            {
                for (int i = 1; i < number_of_constraints + 1; i++)
                {
                    for (int j = 0; j < number_of_variables; j++)
                    {
                        matrix[i, j] = double.Parse(Controls.Find("txtbxConst" + ((i - 1) * number_of_variables + j), false)[0].Text);
                    }
                }
            }
            catch
            {
                MessageBox.Show("Incorrect value!");
                this.Close();
            }

            for (int i = 1; i < number_of_constraints + 1; i++)
            {
                for (int j = number_of_variables; j < number_of_variables + number_of_constraints; j++)
                {
                    if (j - number_of_variables + 1 == i) matrix[i, j] = 1;
                    else matrix[i, j] = 0;
                }
            }

            try
            {
                for (int i = 1; i < number_of_constraints + 1; i++)
                {
                    double n = double.Parse(Controls.Find("txtbxConstRhs" + (i - 1), false)[0].Text);
                    if (n < 0) throw new Exception();
                    matrix[i, number_of_variables + number_of_constraints] = n;
                }
            }
            catch
            {
                MessageBox.Show("Incorrect value!");
                this.Close();
            }

            string_c = new ArrayList();
            for (int i = 0; i < number_of_constraints; i++)
            {
                string str = "y" + (i+1); // baza sboky
                string_c.Add(str);
            }

            string_r = new ArrayList();
            for (int i = 0; i < number_of_variables + number_of_constraints; i++)
            {
                if (i >= number_of_variables)
                {
                    string str = "y" + (i - number_of_variables + 1); // верх 
                    string_r.Add(str);
                }
                else
                {
                    string str = "x" + (i + 1);
                    string_r.Add(str);
                }
            }
            
            Controls.Clear();
            x = 0;
            y = 0;
            PrintTable();
            toExcel();
            while (!IsOptimal())
            {
                
                int guiding_column = FindGuidingColumn();
                int guiding_row = FindGuidingRow(guiding_column);
                y += 40;
                Label lab0 = new Label();
                lab0.Location = new System.Drawing.Point(x, y);
                lab0.AutoSize = true;
                lab0.Font = new System.Drawing.Font("TimesNewRoman", 14);
                lab0.Text = "Guiding element:" + matrix[guiding_row, guiding_column].ToString("F2");
                Controls.Add(lab0);

                y += 40;

                MakeNewGuidingRow(guiding_row, matrix[guiding_row, guiding_column]);
                RecalculationOfTable(guiding_row, guiding_column);
                PrintTable();
                toExcel();
            } ;
            
            y += 40;
            for (int i = 1; i < number_of_constraints + 1; i++)
            {
                Label lab2 = new Label();
                lab2.Location = new System.Drawing.Point(x, y);
                lab2.AutoSize = true;
                lab2.Font = new System.Drawing.Font("TimesNewRoman", 14);
                lab2.Text = (string)string_c[i - 1] + " = " + matrix[i, number_of_variables + number_of_constraints].ToString("F2");
                Controls.Add(lab2);

                y += 30;
            }


            Label lab = new Label();
            lab.Location = new System.Drawing.Point(x, y);
            lab.AutoSize = true;
            lab.Font = new System.Drawing.Font("TimesNewRoman", 14);
            lab.Text = "F(max) = " + matrix[0, number_of_variables + number_of_constraints].ToString("F2");
            Controls.Add(lab);

            y += 30;
            Console.WriteLine(string_r);
            Console.WriteLine(string_c);
        }

        private void PrintTable() 
        {
            x += 50; 
            for (int j = 0; j < number_of_constraints + number_of_variables + 1; j++)
            {
                if (j == number_of_variables + number_of_constraints)
                {
                    Label lab2 = new Label();
                    lab2.Location = new System.Drawing.Point(x, y);
                    lab2.Font = new System.Drawing.Font("TimesNewRoman", 14);
                    lab2.AutoSize = true;
                    lab2.Text = "bi";
                    Controls.Add(lab2);

                    x = 0;
                }
                else 
                {
                    Label lab2 = new Label();
                    lab2.Location = new System.Drawing.Point(x, y);
                    lab2.Size = new System.Drawing.Size(30, 30);
                    lab2.Text = (string)string_r[j];
                    lab2.Font = new System.Drawing.Font("TimesNewRoman", 14);
                    Controls.Add(lab2);

                    x += 50;
                }
            }

            y += 50;

            for (int i = 0; i < number_of_constraints + 1; i++)
            {
                for (int j = 0; j < number_of_constraints + number_of_variables + 2; j++)
                {
                    if (j == 0)
                    {
                        if (i == 0)
                        {
                            Label lab2 = new Label();
                            lab2.Location = new System.Drawing.Point(x, y);
                            lab2.Size = new System.Drawing.Size(30, 30);
                            lab2.Font = new System.Drawing.Font("TimesNewRoman", 14);
                            lab2.Text = "F";
                            Controls.Add(lab2);

                            x += 50;
                        }
                        else
                        {
                            Label lab2 = new Label();
                            lab2.Location = new System.Drawing.Point(x, y);
                            lab2.Size = new System.Drawing.Size(30, 30);
                            lab2.Font = new System.Drawing.Font("TimesNewRoman", 14);
                            lab2.Text = (string)string_c[i - 1];
                            Controls.Add(lab2);

                            x += 50;
                        }    
                    }
                    else
                    {
                        Label lab2 = new Label();
                        lab2.Location = new System.Drawing.Point(x, y);
                        lab2.AutoSize = true;
                        lab2.Font = new System.Drawing.Font("TimesNewRoman", 14);
                        //lab2.Size = new System.Drawing.Size(20, 20);
                        lab2.Text = matrix[i, j - 1].ToString("F2");
                        Controls.Add(lab2);

                        x += 50;                        
                    }
                }
                y += 50;
                x = 0;
            }
        }


        public void WriteArrayToExcel(string filePath, string sheetName, double[,] array)
        {

            FileInfo file = new FileInfo(filePath);
            ExcelPackage.LicenseContext = OfficeOpenXml.LicenseContext.NonCommercial;
            using (var package = new ExcelPackage(file))
            {
                ExcelWorksheet worksheet = package.Workbook.Worksheets[sheetName];

                int lastRow = worksheet.Dimension.End.Row + 1;

                int rows = array.GetLength(0);
                int columns = array.GetLength(1);


                for (int column = 2; column <= columns; column++)
                {
                    worksheet.Cells[1, column].Value = string_r[column-2];
                    
                }
                worksheet.Cells[1, columns+1].Value = "bi";
                // Записываем значения массива в ячейки
                for (int row = lastRow + 1; row <= lastRow + rows; row++)
                {
                    if (row == lastRow + 1)
                    {
                        worksheet.Cells[row, 1].Value = 'F';
                    }
                    else
                    {
                        worksheet.Cells[row, 1].Value =string_c[row- lastRow - 2];
                    }
                    //worksheet.Cells[row, 1].Value = string_r[row-lastRow-1];
                    for (int column = 2; column <= columns + 1; column++)
                    {
                        worksheet.Cells[row, column].Value = array[row - lastRow - 1, column - 2];
                    }
                }

                package.Save();
            }
        }

        public void toExcel()
        {
            WriteArrayToExcel("simplex.xlsx", "simplex", matrix);
        }

        bool IsOptimal()
        {
            for (int j = 0; j < number_of_constraints + number_of_variables + 1; j++)
            {
                if (matrix[0, j] < 0) return false;
            }
            return true;
        }

        int FindGuidingColumn()
        {
            double min = -0.000000000001;
            int num = 0;

            for (int j = 0; j < number_of_constraints + number_of_variables; j++)
            {
                if (matrix[0, j] < min)
                {
                    min = matrix[0, j];
                    num = j;
                }
            }
            return num;
        }

        int FindGuidingRow(int guidingColumn)
        {
            double min = int.MaxValue;
            int num = 0;

            for (int i = 1; i < number_of_constraints + 1; i++)
            {
                if (matrix[i, guidingColumn] > 0)
                {
                    if (matrix[i, number_of_constraints + number_of_variables] / matrix[i, guidingColumn] < min)
                    {
                        min = matrix[i, number_of_constraints + number_of_variables] / matrix[i, guidingColumn];
                        num = i;
                    }
                }
            }
            return num;
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        void MakeNewGuidingRow(int guidingRow, double guidingElement)
        {
            for (int j = 0; j < number_of_constraints + number_of_variables + 1; j++)
            {
                matrix[guidingRow, j] /= guidingElement;
            }
        }

        void RecalculationOfTable(int guiding_row, int guiding_column)
        {
	        string_c[guiding_row-1] = string_r[guiding_column];

	        for(int i = 0; i < number_of_constraints+1; i++)
	        {
		        if(matrix[i, guiding_column] != 0)
		        {
			        if(i == guiding_row)
			        {
				        continue;
			        } 
			
			        double[] row = new double[number_of_variables+number_of_constraints+1];
			        for(int j = 0; j < number_of_variables+number_of_constraints+1; j++)
			        {
				        row[j] = matrix[guiding_row, j];
			        }
			
			        for(int j = 0; j < number_of_variables+number_of_constraints+1; j++)
			        {
				        row[j] *= matrix[i, guiding_column];
			        }
			
			        for(int j = 0; j < number_of_variables+number_of_constraints+1; j++)
			        {
				        matrix[i, j] -= row[j];
			        }
		        }
	        }
        }
    }
}