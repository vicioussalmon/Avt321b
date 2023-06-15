using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Excel = Microsoft.Office.Interop.Excel;

namespace Simplex_lab
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //comboExtr.SelectedIndex = 1;
        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            createTable();
        }
        private void numericConstrain_ValueChanged(object sender, EventArgs e)
        {
            createTable();
        }
        private void createTable()
        {
            dataGridViewStart.AllowUserToAddRows = false;
            int col = Convert.ToInt32(numericVariable.Value + 2);
            int row = Convert.ToInt32(numericConstrain.Value + 1);
            // Создаем новую таблицу
            DataTable table = new DataTable();

            // Добавляем строки в таблицу
            for (int i = 1; i <= col; i++)
            {
                table.Columns.Add(i.ToString());

            }

            for (int i = 1; i <= row; i++)
            {
                DataRow rows = table.NewRow();
                table.Rows.Add(rows);
            }

            dataGridViewStart.DataSource = table;

            for (int i = 1; i <= row; i++)
            {
                dataGridViewStart.Rows[i - 1].HeaderCell.Value = Convert.ToString("Constrains" + (i -1));
            }
            for (int i = 1; i <= col; i++)
            {
                dataGridViewStart.Columns[i - 1].HeaderCell.Value = Convert.ToString("X" + i);
            }
            listsSign();

            dataGridViewStart.Rows[0].HeaderCell.Value = Convert.ToString("F(x)");
            dataGridViewStart.Columns[col - 1].HeaderCell.Value = Convert.ToString("Bi");
            dataGridViewStart.Columns[col - 2].HeaderCell.Value = Convert.ToString("Sign");
            dataGridViewStart.Rows[0].Cells[col - 2].Value = "=";
            dataGridViewStart.Rows[0].Cells[col - 2].ReadOnly = true;
            dataGridViewStart.Rows[0].Cells[col - 1].ReadOnly = true;


            dataGridViewStart.AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode.AutoSizeToAllHeaders);
        }

        private double[,] createData(int col, int row)
        {
            double[,] data = new double[Convert.ToInt32(row), Convert.ToInt32(col)];
            for (int i = 1; i < row+1; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    data[i - 1, j] = Convert.ToDouble(dataGridViewStart.Rows[i].Cells[j].Value);
                }
            }
            return data;
        }

        private string[] createSign(int col, int row)
        {
            string[] sign = new string[Convert.ToInt32(row)];
            for (int i = 1; i < row + 1; i++)
            {
                sign[i - 1] = (dataGridViewStart.Rows[i].Cells[col].Value).ToString();
            }
            return sign;
        }

        private double[] createBi(int col,int row)
        {
            double[] bi = new double[Convert.ToInt32(row + 1)];
            bi[0] = 0;
            for (int i = 1; i < row + 1; i++)
            {
                bi[i] = Convert.ToDouble(dataGridViewStart.Rows[i].Cells[col + 1].Value);
            }
            return bi;
        }

        private double[] createF(int col, int row)
        {
            double[] F = new double[Convert.ToInt32(col)];
            for (int i = 0; i < col; i++)
            {
                F[i] = Convert.ToDouble(dataGridViewStart.Rows[0].Cells[i].Value);
            }
            return F;
        }

        private void createNewTable(double[,] data, double[] bi, double[] F, string[] sign, bool menu)
        {
            if (menu)
            {
                int sizeF = F.Length;
                bool check = true;
                bool whilecheck = true;



                Simplex S = new Simplex(data, bi, F, sign);
                try
                {
                    //  MessageBox.Show((bi.Length).ToString());

                    S.Modernize();

                    //MessageBox.Show((bi.Length).ToString());
                }
                catch (Exception e)
                {
                    MessageBox.Show(e.Message);
                }
                (string, int)[] Baza;
                List<string> GiperBaza = new List<string>();


                data = S.GetData();
                dataGridViewResult.AllowUserToAddRows = false;
                int col = Convert.ToInt32(data.GetLength(1) + 1);
                int row = Convert.ToInt32(data.GetLength(0) + 2);
                int rowIndex = 0;
                int rowCount = 0;

                // Создаем новую таблицу
                DataTable table = new DataTable();

                // Добавляем строки в таблицу
                for (int i = 0; i < col; i++)
                {
                    table.Columns.Add(i.ToString());

                }

                //bool menu = comboExtr.Text.ToString() == "Min";
                try
                {





                    while (S.Is_Optimal(menu))
                    {
                        if (menu)
                        {
                            S.CalculateMin();

                        }
                        else
                        {
                            S.CalculateMax();
                        }
                        rowCount += row;
                        data = S.GetData();
                        bi = S.GetBi();
                        F = S.GetF();
                        Baza = S.GetBaza();
                        for (int i = 0; i < row; i++)
                        {
                            DataRow rows = table.NewRow();
                            table.Rows.Add(rows);
                        }
                        for (int i = rowIndex, dataI = 0; i < rowCount - 2; i++, dataI++)
                        {
                            for (int j = 0; j < data.GetLength(1); j++)
                            {
                                table.Rows[i][j] = data[dataI, j].ToString("F4");
                            }
                        }
                        for (int i = 1; i < bi.Length; i++)
                        {
                            table.Rows[rowIndex + i - 1][col - 1] = bi[i].ToString("F4");

                        }
                        for (int i = 0; i < F.Length; i++)
                        {
                            table.Rows[rowCount - 2][i] = F[i].ToString("F4");
                        }

                        rowIndex += row;
                        table.Rows[rowIndex - 2][col - 1] = bi[0].ToString("F4");
                        dataGridViewResult.DataSource = table;

                        for (int i = 0; i < Baza.Length; i++)
                        {
                            //  dataGridViewResult.Rows[rowIndex - row + i].HeaderCell.Value = Convert.ToString(Baza[i].Item1);
                            GiperBaza.Add(Baza[i].Item1);
                        }
                        dataGridViewResult.Rows[rowCount - 2].HeaderCell.Value = Convert.ToString("F");

                    }
                }
                catch (Exception e)
                {
                    MessageBox.Show(e.Message);
                }
                dataGridViewResult.DataSource = table;
                for (int i = 0; i < data.GetLength(1); i++)
                {
                    dataGridViewResult.Columns[i].HeaderCell.Value = Convert.ToString("X" + (i + 1));
                }
                dataGridViewResult.Columns[col - 1].HeaderCell.Value = Convert.ToString("B");
                dataGridViewResult.TopLeftHeaderCell.Value = "Base";
                dataGridViewResult.AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode.AutoSizeToAllHeaders);
                FBox.Text = S.FResult().ToString("F4");


                Baza = S.GetBaza();

                Gomori obj = new Gomori(data, bi, F, Baza, sizeF);



                if (obj.isGemoroi())
                {
                    table.Rows[rowCount - 1][2] = "Gomori method";

                }
                else
                {
                    table.Rows[rowCount - 1][2] = "Only simplex";
                }



                while (obj.isGemoroi())
                {

                    obj.Modernize();

                    table.Columns.Add();
                    DataRow rows = table.NewRow();
                    table.Rows.Add(rows);
                    col++;
                    row++;    /// 

                    data = obj.GetgomoriData();
                    bi = obj.GetgomoriBi();
                    F = obj.GetgomoriF();
                    Baza = obj.GetgomoriBaza();

                    sizeF += 1;
                    check = false;

                    obj.CalZalUpaProMAxDouble();

                    data = obj.GetgomoriData();
                    bi = obj.GetgomoriBi();
                    F = obj.GetgomoriF();
                    Baza = obj.GetgomoriBaza();

                    rowCount += row;

                    for (int i = 0; i < row; i++)
                    {
                        rows = table.NewRow();
                        table.Rows.Add(rows);
                    }
                    for (int i = rowIndex, dataI = 0; i < rowCount - 2; i++, dataI++)
                    {
                        for (int j = 0; j < data.GetLength(1); j++)
                        {
                            table.Rows[i][j] = data[dataI, j].ToString("F4");
                        }
                    }
                    for (int i = 1; i < bi.Length; i++)
                    {
                        table.Rows[rowIndex + i - 1][col - 1] = bi[i].ToString("F4");

                    }
                    for (int i = 0; i < F.Length; i++)
                    {
                        table.Rows[rowCount - 2][i] = F[i].ToString("F4");
                    }

                    rowIndex += row;
                    table.Rows[rowIndex - 2][col - 1] = bi[0].ToString("F4");
                    dataGridViewResult.DataSource = table;

                    for (int i = 0; i < Baza.Length; i++)
                    {
                        // dataGridViewResult.Rows[rowIndex - row + i].HeaderCell.Value = Convert.ToString(Baza[i].Item1);
                        GiperBaza.Add(Baza[i].Item1);
                    }
                    dataGridViewResult.Rows[rowCount - 2].HeaderCell.Value = Convert.ToString("F");


                }
                FBox.Text = bi[0].ToString("F4");






                dataGridViewResult.DataSource = table;


                for (int i = 0, j = 0; j < GiperBaza.Count && i < dataGridViewResult.RowCount - 1; i++, j++)
                {


                    if (dataGridViewResult.Rows[i + 1].Cells[0].Value != DBNull.Value)
                    {
                        dataGridViewResult.Rows[i].HeaderCell.Value = Convert.ToString(GiperBaza[j]);
                    }
                    else
                    {

                        dataGridViewResult.Rows[i].HeaderCell.Value = Convert.ToString("F");
                        i++;

                        j--;
                    }



                }



                for (int i = 0; i < data.GetLength(1); i++)
                {
                    dataGridViewResult.Columns[i].HeaderCell.Value = Convert.ToString("X" + (i + 1));
                }

                dataGridViewResult.Columns[col - 1].HeaderCell.Value = Convert.ToString("B");
                dataGridViewResult.TopLeftHeaderCell.Value = "Base";
                dataGridViewResult.AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode.AutoSizeToAllHeaders);


                Excel.Application excelApp = new Excel.Application();
                Excel.Workbook workbook = excelApp.Workbooks.Add();
                Excel.Worksheet worksheet = workbook.ActiveSheet;

                // Записываем данные из первого DataGridView
                int row1 = 1;
                int col1 = 1;

                // Записываем крайний левый столбец
                worksheet.Cells[row1, col1] = "Table"; // Замените "ID" на заголовок столбца, если нужно
                col1++;

                foreach (DataGridViewColumn column in dataGridViewStart.Columns)
                {
                    worksheet.Cells[row1, col1] = column.HeaderText;
                    col1++;
                }

                row1 = 2;
                for (int i = 0; i < dataGridViewStart.Rows.Count; i++)
                {
                    // Записываем значение из крайнего левого столбца
                    worksheet.Cells[row1, 1] = dataGridViewStart.Rows[i].HeaderCell.Value;

                    for (int j = 0; j < dataGridViewStart.Columns.Count; j++)
                    {
                        worksheet.Cells[row1, j + 2] = dataGridViewStart.Rows[i].Cells[j].Value;
                    }
                    row1++;
                }

                // Добавляем промежуток в две клетки
                row1 += 2;

                // Записываем данные из второго DataGridView
                col1 = 1;

                // Записываем крайний левый столбец
                worksheet.Cells[row1, col1] = "Base"; // Замените "ID" на заголовок столбца, если нужно
                col1++;

                foreach (DataGridViewColumn column in dataGridViewResult.Columns)
                {
                    worksheet.Cells[row1, col1] = column.HeaderText;
                    col1++;
                }

                row1++;
                for (int i = 0; i < dataGridViewResult.Rows.Count; i++)
                {
                    // Записываем значение из крайнего левого столбца
                    worksheet.Cells[row1, 1] = dataGridViewResult.Rows[i].HeaderCell.Value;

                    for (int j = 0; j < dataGridViewResult.Columns.Count; j++)
                    {
                        worksheet.Cells[row1, j + 2] = dataGridViewResult.Rows[i].Cells[j].Value;
                    }
                    row1++;
                }

                // Сохраняем и закрываем Excel
                excelApp.Visible = true;
                workbook.SaveAs("GomoriMin.xlsx");
                workbook.Close();
                excelApp.Quit();

            }
            else
            {
                int sizeF = F.Length;
                bool check = true;
                bool whilecheck = true;



                Simplex S = new Simplex(data, bi, F, sign);
                try
                {
                    //  MessageBox.Show((bi.Length).ToString());

                    S.Modernize();

                    //MessageBox.Show((bi.Length).ToString());
                }
                catch (Exception e)
                {
                    MessageBox.Show(e.Message);
                }
                (string, int)[] Baza;
                List<string> GiperBaza = new List<string>();


                data = S.GetData();
                dataGridView1.AllowUserToAddRows = false;
                int col = Convert.ToInt32(data.GetLength(1) + 1);
                int row = Convert.ToInt32(data.GetLength(0) + 2);
                int rowIndex = 0;
                int rowCount = 0;

                // Создаем новую таблицу
                DataTable table = new DataTable();

                // Добавляем строки в таблицу
                for (int i = 0; i < col; i++)
                {
                    table.Columns.Add(i.ToString());

                }

                //bool menu = comboExtr.Text.ToString() == "Min";
                try
                {





                    while (S.Is_Optimal(menu))
                    {
                        if (menu)
                        {
                            S.CalculateMin();

                        }
                        else
                        {
                            S.CalculateMax();
                        }
                        rowCount += row;
                        data = S.GetData();
                        bi = S.GetBi();
                        F = S.GetF();
                        Baza = S.GetBaza();
                        for (int i = 0; i < row; i++)
                        {
                            DataRow rows = table.NewRow();
                            table.Rows.Add(rows);
                        }
                        for (int i = rowIndex, dataI = 0; i < rowCount - 2; i++, dataI++)
                        {
                            for (int j = 0; j < data.GetLength(1); j++)
                            {
                                table.Rows[i][j] = data[dataI, j].ToString("F4");
                            }
                        }
                        for (int i = 1; i < bi.Length; i++)
                        {
                            table.Rows[rowIndex + i - 1][col - 1] = bi[i].ToString("F4");

                        }
                        for (int i = 0; i < F.Length; i++)
                        {
                            table.Rows[rowCount - 2][i] = F[i].ToString("F4");
                        }

                        rowIndex += row;
                        table.Rows[rowIndex - 2][col - 1] = bi[0].ToString("F4");
                        dataGridView1.DataSource = table;

                        for (int i = 0; i < Baza.Length; i++)
                        {
                            //  dataGridViewResult.Rows[rowIndex - row + i].HeaderCell.Value = Convert.ToString(Baza[i].Item1);
                            GiperBaza.Add(Baza[i].Item1);
                        }
                        dataGridView1.Rows[rowCount - 2].HeaderCell.Value = Convert.ToString("F");

                    }
                }
                catch (Exception e)
                {
                    MessageBox.Show(e.Message);
                }
                dataGridView1.DataSource = table;
                for (int i = 0; i < data.GetLength(1); i++)
                {
                    dataGridView1.Columns[i].HeaderCell.Value = Convert.ToString("X" + (i + 1));
                }
                dataGridView1.Columns[col - 1].HeaderCell.Value = Convert.ToString("B");
                dataGridView1.TopLeftHeaderCell.Value = "Base";
                dataGridView1.AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode.AutoSizeToAllHeaders);
                textBox1.Text = S.FResult().ToString("F4");


                Baza = S.GetBaza();

                Gomori obj = new Gomori(data, bi, F, Baza, sizeF);



                if (obj.isGemoroi())
                {
                    table.Rows[rowCount - 1][2] = "Gomori method";

                }
                else
                {
                    table.Rows[rowCount - 1][2] = "Only simplex";
                }



                while (obj.isGemoroi())
                {

                    obj.Modernize();

                    table.Columns.Add();
                    DataRow rows = table.NewRow();
                    table.Rows.Add(rows);
                    col++;
                    row++;    /// 

                    data = obj.GetgomoriData();
                    bi = obj.GetgomoriBi();
                    F = obj.GetgomoriF();
                    Baza = obj.GetgomoriBaza();

                    sizeF += 1;
                    check = false;

                    obj.CalZalUpaProMAxDouble();

                    data = obj.GetgomoriData();
                    bi = obj.GetgomoriBi();
                    F = obj.GetgomoriF();
                    Baza = obj.GetgomoriBaza();

                    rowCount += row;

                    for (int i = 0; i < row; i++)
                    {
                        rows = table.NewRow();
                        table.Rows.Add(rows);
                    }
                    for (int i = rowIndex, dataI = 0; i < rowCount - 2; i++, dataI++)
                    {
                        for (int j = 0; j < data.GetLength(1); j++)
                        {
                            table.Rows[i][j] = data[dataI, j].ToString("F4");
                        }
                    }
                    for (int i = 1; i < bi.Length; i++)
                    {
                        table.Rows[rowIndex + i - 1][col - 1] = bi[i].ToString("F4");

                    }
                    for (int i = 0; i < F.Length; i++)
                    {
                        table.Rows[rowCount - 2][i] = F[i].ToString("F4");
                    }

                    rowIndex += row;
                    table.Rows[rowIndex - 2][col - 1] = bi[0].ToString("F4");
                    dataGridView1.DataSource = table;

                    for (int i = 0; i < Baza.Length; i++)
                    {
                        // dataGridViewResult.Rows[rowIndex - row + i].HeaderCell.Value = Convert.ToString(Baza[i].Item1);
                        GiperBaza.Add(Baza[i].Item1);
                    }
                    dataGridView1.Rows[rowCount - 2].HeaderCell.Value = Convert.ToString("F");


                }
                textBox1.Text = bi[0].ToString("F4");






                dataGridView1.DataSource = table;


                for (int i = 0, j = 0; j < GiperBaza.Count && i < dataGridView1.RowCount - 1; i++, j++)
                {


                    if (dataGridView1.Rows[i + 1].Cells[0].Value != DBNull.Value)
                    {
                        dataGridView1.Rows[i].HeaderCell.Value = Convert.ToString(GiperBaza[j]);
                    }
                    else
                    {

                        dataGridView1.Rows[i].HeaderCell.Value = Convert.ToString("F");
                        i++;

                        j--;
                    }



                }



                for (int i = 0; i < data.GetLength(1); i++)
                {
                    dataGridView1.Columns[i].HeaderCell.Value = Convert.ToString("X" + (i + 1));
                }

                dataGridView1.Columns[col - 1].HeaderCell.Value = Convert.ToString("B");
                dataGridView1.TopLeftHeaderCell.Value = "Base";
                dataGridView1.AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode.AutoSizeToAllHeaders);



                Excel.Application excelApp = new Excel.Application();
                Excel.Workbook workbook = excelApp.Workbooks.Add();
                Excel.Worksheet worksheet = workbook.ActiveSheet;

                // Записываем данные из первого DataGridView
                int row1 = 1;
                int col1 = 1;

                // Записываем крайний левый столбец
                worksheet.Cells[row1, col1] = "Table"; // Замените "ID" на заголовок столбца, если нужно
                col1++;

                foreach (DataGridViewColumn column in dataGridViewStart.Columns)
                {
                    worksheet.Cells[row1, col1] = column.HeaderText;
                    col1++;
                }

                row1 = 2;
                for (int i = 0; i < dataGridViewStart.Rows.Count; i++)
                {
                    // Записываем значение из крайнего левого столбца
                    worksheet.Cells[row1, 1] = dataGridViewStart.Rows[i].HeaderCell.Value;

                    for (int j = 0; j < dataGridViewStart.Columns.Count; j++)
                    {
                        worksheet.Cells[row1, j + 2] = dataGridViewStart.Rows[i].Cells[j].Value;
                    }
                    row1++;
                }

                // Добавляем промежуток в две клетки
                row1 += 2;

                // Записываем данные из второго DataGridView
                col1 = 1;

                // Записываем крайний левый столбец
                worksheet.Cells[row1, col1] = "Base"; // Замените "ID" на заголовок столбца, если нужно
                col1++;

                foreach (DataGridViewColumn column in dataGridView1.Columns)
                {
                    worksheet.Cells[row1, col1] = column.HeaderText;
                    col1++;
                }

                row1++;
                for (int i = 0; i < dataGridView1.Rows.Count; i++)
                {
                    // Записываем значение из крайнего левого столбца
                    worksheet.Cells[row1, 1] = dataGridView1.Rows[i].HeaderCell.Value;

                    for (int j = 0; j < dataGridView1.Columns.Count; j++)
                    {
                        worksheet.Cells[row1, j + 2] = dataGridView1.Rows[i].Cells[j].Value;
                    }
                    row1++;
                }

                // Сохраняем и закрываем Excel
                excelApp.Visible = true;
                workbook.SaveAs("GomoriMax.xlsx");
                workbook.Close();
                excelApp.Quit();
            }
        }







        private void buttonCulculate_Click(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
            {
                int col = Convert.ToInt32(numericVariable.Value);
                int row = Convert.ToInt32(numericConstrain.Value);
                double[,] data = createData(col, row);
                string[] sign = createSign(col, row);
                double[] bi = createBi(col, row);
                double[] F = createF(col, row);
                createNewTable(data, bi, F, sign, true);
            }
            if (checkBox2.Checked)
            {
                int col = Convert.ToInt32(numericVariable.Value);
                int row = Convert.ToInt32(numericConstrain.Value);
                double[,] data = createData(col, row);
                string[] sign = createSign(col, row);
                double[] bi = createBi(col, row);
                double[] F = createF(col, row);
                createNewTable(data, bi, F, sign, false);
            }
        }

        public void listsSign()
        {
            DataGridViewComboBoxColumn signComboBoxColumn = new DataGridViewComboBoxColumn();
            signComboBoxColumn.HeaderText = "Sign";
            signComboBoxColumn.DataPropertyName = "Sign";
            signComboBoxColumn.Name = "SignComboBoxColumn";
            signComboBoxColumn.Items.AddRange("=", "<=", ">=");

            // Replace the existing "Sign" column with the new DataGridViewComboBoxColumn
            int signColumnIndex = dataGridViewStart.ColumnCount - 2; // Index of the "Sign" column
            for (int i = 0; i < dataGridViewStart.RowCount; i++)
            {
                DataGridViewComboBoxCell comboBoxCell = new DataGridViewComboBoxCell();
                comboBoxCell.Items.AddRange("=", "<=", ">=");

                dataGridViewStart.Rows[i].Cells[signColumnIndex] = comboBoxCell;
            }
        }

        private void ToExcelButton_Click(object sender, EventArgs e)
        {
            Excel.Application excelApp = new Excel.Application();
            Excel.Workbook workbook = excelApp.Workbooks.Add();
            Excel.Worksheet worksheet = workbook.ActiveSheet;

            // Записываем данные из первого DataGridView
            int row = 1;
            int col = 1;

            // Записываем крайний левый столбец
            worksheet.Cells[row, col] = "Table"; // Замените "ID" на заголовок столбца, если нужно
            col++;

            foreach (DataGridViewColumn column in dataGridViewStart.Columns)
            {
                worksheet.Cells[row, col] = column.HeaderText;
                col++;
            }

            row = 2;
            for (int i = 0; i < dataGridViewStart.Rows.Count; i++)
            {
                // Записываем значение из крайнего левого столбца
                worksheet.Cells[row, 1] = dataGridViewStart.Rows[i].HeaderCell.Value;

                for (int j = 0; j < dataGridViewStart.Columns.Count; j++)
                {
                    worksheet.Cells[row, j + 2] = dataGridViewStart.Rows[i].Cells[j].Value;
                }
                row++;
            }

            // Добавляем промежуток в две клетки
            row += 2;

            // Записываем данные из второго DataGridView
            col = 1;

            // Записываем крайний левый столбец
            worksheet.Cells[row, col] = "Base"; // Замените "ID" на заголовок столбца, если нужно
            col++;

            foreach (DataGridViewColumn column in dataGridViewResult.Columns)
            {
                worksheet.Cells[row, col] = column.HeaderText;
                col++;
            }

            row++;
            for (int i = 0; i < dataGridViewResult.Rows.Count; i++)
            {
                // Записываем значение из крайнего левого столбца
                worksheet.Cells[row, 1] = dataGridViewResult.Rows[i].HeaderCell.Value;

                for (int j = 0; j < dataGridViewResult.Columns.Count; j++)
                {
                    worksheet.Cells[row, j + 2] = dataGridViewResult.Rows[i].Cells[j].Value;
                }
                row++;
            }

            // Сохраняем и закрываем Excel
            excelApp.Visible = true;
            workbook.SaveAs("Simplexs_lab.xlsx");
            workbook.Close();
            excelApp.Quit();
        }
    }
}
