using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.Common;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Excel = Microsoft.Office.Interop.Excel;

namespace Transport_lab
{
    public partial class Transport_form : Form
    {
        public Transport_form()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            comboBoxMethod.SelectedIndex = 0;
        }

        public int[,] createMas()
        {
            int[,] data = new int[Convert.ToInt32(numericRow.Value), Convert.ToInt32(numericCol.Value)];
            for(int i = 0; i < numericRow.Value; i++)
            {
                for (int j = 0; j < numericCol.Value; j++)
                {
                    data[i,j] = Convert.ToInt32(dataGridViewMatrix.Rows[i].Cells[j].Value);
                }
            }
            return data;
        }

        public int[] createDemand()
        {
            int[] demand = new int[Convert.ToInt32(numericCol.Value)];
            for (int i = 0; i < numericCol.Value; i++)
            {
                demand[i] = Convert.ToInt32(dataGridViewMatrix.Rows[dataGridViewMatrix.RowCount-1].Cells[i].Value);
            }

            return demand;
        }
        public int[] createSupply()
        {
            int[] supply = new int[Convert.ToInt32(numericRow.Value)];
            for (int i = 0; i < numericRow.Value; i++)
            {
                supply[i] = Convert.ToInt32(dataGridViewMatrix.Rows[i].Cells[dataGridViewMatrix.ColumnCount - 1].Value);
            }

            return supply;
        }

        public void createNewTable(int[,] Odata2, int[,] data, int[]demand, int[]supply)
        {
            dataGridViewResult.AllowUserToAddRows = false;
            // Создаем новую таблицу
            DataTable table = new DataTable();

            // Добавляем строки в таблицу
            for (int i = 1; i <= demand.Length + 1; i++)
            {
                table.Columns.Add(i.ToString());

            }

            for (int i = 1; i <= supply.Length + 1; i++)
            {
                DataRow row = table.NewRow();
                table.Rows.Add(row);
            }
            
            dataGridViewResult.DataSource = table;
            //dataGridViewMatrix.Columns= 70;
            for (int i = 1; i <= supply.Length; i++)
            {
                dataGridViewResult.Rows[i - 1].HeaderCell.Value = Convert.ToString("A" + i);
            }
            for (int i = 1; i <= demand.Length; i++)
            {
                dataGridViewResult.Columns[i - 1].HeaderCell.Value = Convert.ToString("B" + i);
            }
            int colCount = Convert.ToInt32(numericCol.Value);
            int rowCount = Convert.ToInt32(numericRow.Value);
            dataGridViewResult.Rows[supply.Length].HeaderCell.Value = Convert.ToString("Demand");
            dataGridViewResult.Columns[demand.Length].HeaderCell.Value = Convert.ToString("Supply");
            for (int i = 0; i < supply.Length; i++)
            {
                for(int j = 0; j < demand.Length; j++)
                {
                    dataGridViewResult.Rows[i].Cells[j].Value =  data[i, j].ToString();
                }
            }
            for (int i = 0; i < supply.Length; i++)
            {
                dataGridViewResult.Rows[i].Cells[demand.Length].Value = supply[i];
            }
            for (int i = 0; i < demand.Length; i++)
            {
                dataGridViewResult.Rows[supply.Length].Cells[i].Value = demand[i];
            }
            dataGridViewResult.AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode.AutoSizeToAllHeaders);
        }

        private void buttonRun_Click(object sender, EventArgs e)
        {
            string menu = comboBoxMethod.Text.ToString();
            int[,] data = createMas();
            int[] demand = createDemand();
            int[] supply = createSupply();
            int numRow = Convert.ToInt32(numericRow.Value);
            int numCol = Convert.ToInt32(numericCol.Value);
            
            switch (menu)
            {
                case "Northwest angle method":
                    Northwest_angle_method method = new Northwest_angle_method();
                    method.SetColumn(numCol);
                    method.SetRow(numRow);
                    method.PopulateCosts(data);
                    method.PopulateOffers(supply);
                    method.PopulateDemands(demand);
                    method.AllocateMatrix();
                    int sum = method.GetSum();
                    int[,] Odata = method.GetData();
                    int[] Odemand = method.GetDemand();
                    int[] Osupply = method.GetSupply();
                    int[,] Odata2 = method.GetData2();
                    createNewTable(Odata2 ,Odata, Odemand, Osupply);
                    AnswerBox.Text=Convert.ToString(sum);
                    break;

                case "Minimum cost method":
                    int[][] dataNew = convert(data);
                    Minimum_cost_method met = new Minimum_cost_method(dataNew, supply, demand);
                    int[] MC_demand = met.GetDemand();
                    int[] MC_supply = met.GetSupply();
                    met.Calculate();
                    int SUM = met.TotalSum();
                    int[][] MC = met.GetData();
                    
                    
                    int[][] initial = met.GetInitial();
                    int[,] MC2 = ConvertJ(MC);
                    int[,] initial2 = ConvertJ(initial);
                    createNewTable(initial2, MC2, MC_demand, MC_supply);
                    AnswerBox.Text = Convert.ToString(SUM);
                    break;

                case "Vogel method":
                    List<List<int>> dataList = convert2(data);
                    List<int> demandList = demand.ToList();
                    List<int> supplyList = supply.ToList();

                    Vogel_method li = new Vogel_method(dataList, demandList, supplyList);
                    
                    List<int> demandList2 = li.GetDemand();
                    List<int> supplyList2 = li.GetSupply();
                    
                    li.AlgoritmWork();
                    int Sum = li.GetSum();
                    List<List<int>> copyList2 = li.GetCopy();
                    List<List<int>> dataList2 = li.GetResult();
                    demand = demandList2.ToArray();
                    supply = supplyList2.ToArray();
                    data = ConvertL(dataList2);
                    int[,]data2 = ConvertL(copyList2);
                    createNewTable(data2, data, demand, supply);
                    AnswerBox.Text = Convert.ToString(Sum);
                    break;
            }
        }
        public int[,] ConvertJ(int[][] MC)
        {
            int[,] twoDimensionalArray = new int[MC.Length, MC.Max(subArray => subArray.Length)];
            for (int i = 0; i < MC.Length; i++)
            {
                for (int j = 0; j < MC[i].Length; j++)
                {
                    twoDimensionalArray[i, j] = MC[i][j];
                }
            }
            return twoDimensionalArray;
        }

        public int[,] ConvertL(List<List<int>> list)
        {
            int[,] twoDimensionalArray = new int[list.Count, list.Max(l => l.Count)];
            for (int i = 0; i < list.Count; i++)
            {
                for (int j = 0; j < list[i].Count; j++)
                {
                    twoDimensionalArray[i, j] = list[i][j];
                }
            }
            return twoDimensionalArray;
        }
        public List<List<int>> convert2(int[,] data)
        {
            List<List<int>> list = new List<List<int>>();
            for (int i = 0; i < data.GetLength(0); i++)
            {
                List<int> innerList = new List<int>();
                for (int j = 0; j < data.GetLength(1); j++)
                {
                    innerList.Add(data[i, j]);
                }
                list.Add(innerList);
            }
            return list;
        }
        public int[][] convert(int[,] data)
        {
            int[][] copy = new int[data.GetLength(0)][];
            for (int i = 0; i < data.GetLength(0); i++)
            {
                copy[i] = new int[data.GetLength(1)];
                for (int j = 0; j < data.GetLength(1); j++)
                {
                    copy[i][j] = data[i, j];
                }
            }
            return copy;
        }

        private void numericRow_ValueChanged(object sender, EventArgs e)
        {

            createTable();
        }

        private void numericCol_ValueChanged(object sender, EventArgs e)
        {
            createTable();
        }

        private void createTable()
        {
            dataGridViewMatrix.AllowUserToAddRows = false;
            // Создаем новую таблицу
            DataTable table = new DataTable();

            // Добавляем строки в таблицу
            for (int i = 1; i <= numericCol.Value+1; i++)
            {
                table.Columns.Add(i.ToString());

            }

            for (int i = 1; i <= numericRow.Value+1; i++)
            {
                DataRow row = table.NewRow();
                table.Rows.Add(row);
            }
            
            dataGridViewMatrix.DataSource = table;
            //dataGridViewMatrix.Columns= 70;
            for (int i = 1; i <= numericRow.Value; i++)
            {
                dataGridViewMatrix.Rows[i-1].HeaderCell.Value = Convert.ToString("A"+i);
            }
            for (int i = 1; i <= numericCol.Value; i++)
            {
                dataGridViewMatrix.Columns[i - 1].HeaderCell.Value = Convert.ToString("B" + i);
            }
            int colCount = Convert.ToInt32(numericCol.Value);
            int rowCount = Convert.ToInt32(numericRow.Value);
            dataGridViewMatrix.Rows[rowCount].HeaderCell.Value = Convert.ToString("Demand");
            dataGridViewMatrix.Columns[colCount].HeaderCell.Value = Convert.ToString("Supply");
            foreach (DataRow row in table.Rows)
            {
                foreach (DataColumn col in table.Columns)
                {
                    row[col] = 0;
                }
            }
            dataGridViewMatrix.AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode.AutoSizeToAllHeaders);
        }

        private void ToExel_Click(object sender, EventArgs e)
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

            foreach (DataGridViewColumn column in dataGridViewMatrix.Columns)
            {
                worksheet.Cells[row, col] = column.HeaderText;
                col++;
            }

            row = 2;
            for (int i = 0; i < dataGridViewMatrix.Rows.Count; i++)
            {
                // Записываем значение из крайнего левого столбца
                worksheet.Cells[row, 1] = dataGridViewMatrix.Rows[i].HeaderCell.Value;

                for (int j = 0; j < dataGridViewMatrix.Columns.Count; j++)
                {
                    worksheet.Cells[row, j + 2] = dataGridViewMatrix.Rows[i].Cells[j].Value;
                }
                row++;
            }

            // Добавляем промежуток в две клетки
            row += 2;

            // Записываем данные из второго DataGridView
            col = 1;

            // Записываем крайний левый столбец
            worksheet.Cells[row, col] = "Result"; // Замените "ID" на заголовок столбца, если нужно
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
            workbook.SaveAs("C:\\mm\\Transport_lab\\Transport_lab\\Transport_Lab.xlsx");
            workbook.Close();
            excelApp.Quit();
        }
    }
}
