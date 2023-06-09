namespace Transport_lab
{
    partial class Transport_form
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.dataGridViewMatrix = new System.Windows.Forms.DataGridView();
            this.buttonRun = new System.Windows.Forms.Button();
            this.numericCol = new System.Windows.Forms.NumericUpDown();
            this.numericRow = new System.Windows.Forms.NumericUpDown();
            this.comboBoxMethod = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.ToExel = new System.Windows.Forms.Button();
            this.dataGridViewResult = new System.Windows.Forms.DataGridView();
            this.AnswerBox = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewMatrix)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericCol)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericRow)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewResult)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridViewMatrix
            // 
            this.dataGridViewMatrix.BackgroundColor = System.Drawing.Color.White;
            this.dataGridViewMatrix.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewMatrix.Location = new System.Drawing.Point(23, 280);
            this.dataGridViewMatrix.Margin = new System.Windows.Forms.Padding(4);
            this.dataGridViewMatrix.Name = "dataGridViewMatrix";
            this.dataGridViewMatrix.RowHeadersWidth = 51;
            this.dataGridViewMatrix.Size = new System.Drawing.Size(659, 345);
            this.dataGridViewMatrix.TabIndex = 0;
            // 
            // buttonRun
            // 
            this.buttonRun.BackColor = System.Drawing.Color.AliceBlue;
            this.buttonRun.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonRun.Location = new System.Drawing.Point(674, 187);
            this.buttonRun.Margin = new System.Windows.Forms.Padding(4);
            this.buttonRun.Name = "buttonRun";
            this.buttonRun.Size = new System.Drawing.Size(254, 36);
            this.buttonRun.TabIndex = 1;
            this.buttonRun.Text = "To Start";
            this.buttonRun.UseVisualStyleBackColor = false;
            this.buttonRun.Click += new System.EventHandler(this.buttonRun_Click);
            // 
            // numericCol
            // 
            this.numericCol.BackColor = System.Drawing.Color.LavenderBlush;
            this.numericCol.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.numericCol.Location = new System.Drawing.Point(558, 23);
            this.numericCol.Margin = new System.Windows.Forms.Padding(4);
            this.numericCol.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericCol.Name = "numericCol";
            this.numericCol.Size = new System.Drawing.Size(74, 35);
            this.numericCol.TabIndex = 2;
            this.numericCol.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericCol.ValueChanged += new System.EventHandler(this.numericCol_ValueChanged);
            // 
            // numericRow
            // 
            this.numericRow.BackColor = System.Drawing.Color.LavenderBlush;
            this.numericRow.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.numericRow.Location = new System.Drawing.Point(558, 80);
            this.numericRow.Margin = new System.Windows.Forms.Padding(4);
            this.numericRow.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericRow.Name = "numericRow";
            this.numericRow.Size = new System.Drawing.Size(70, 35);
            this.numericRow.TabIndex = 3;
            this.numericRow.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericRow.ValueChanged += new System.EventHandler(this.numericRow_ValueChanged);
            // 
            // comboBoxMethod
            // 
            this.comboBoxMethod.BackColor = System.Drawing.Color.GhostWhite;
            this.comboBoxMethod.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.comboBoxMethod.FormattingEnabled = true;
            this.comboBoxMethod.Items.AddRange(new object[] {
            "Minimum cost method",
            "Northwest angle method",
            "Vogel method"});
            this.comboBoxMethod.Location = new System.Drawing.Point(248, 187);
            this.comboBoxMethod.Margin = new System.Windows.Forms.Padding(4);
            this.comboBoxMethod.Name = "comboBoxMethod";
            this.comboBoxMethod.Size = new System.Drawing.Size(298, 35);
            this.comboBoxMethod.TabIndex = 4;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(357, 82);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(66, 27);
            this.label1.TabIndex = 6;
            this.label1.Text = "Rows";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(357, 31);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(97, 27);
            this.label2.TabIndex = 7;
            this.label2.Text = "Colomns";
            // 
            // ToExel
            // 
            this.ToExel.BackColor = System.Drawing.Color.Honeydew;
            this.ToExel.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ToExel.Location = new System.Drawing.Point(725, 31);
            this.ToExel.Margin = new System.Windows.Forms.Padding(4);
            this.ToExel.Name = "ToExel";
            this.ToExel.Size = new System.Drawing.Size(164, 68);
            this.ToExel.TabIndex = 8;
            this.ToExel.Text = "To Exel";
            this.ToExel.UseVisualStyleBackColor = false;
            this.ToExel.Click += new System.EventHandler(this.ToExel_Click);
            // 
            // dataGridViewResult
            // 
            this.dataGridViewResult.BackgroundColor = System.Drawing.Color.WhiteSmoke;
            this.dataGridViewResult.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewResult.Location = new System.Drawing.Point(725, 280);
            this.dataGridViewResult.Margin = new System.Windows.Forms.Padding(4);
            this.dataGridViewResult.Name = "dataGridViewResult";
            this.dataGridViewResult.RowHeadersWidth = 51;
            this.dataGridViewResult.Size = new System.Drawing.Size(626, 345);
            this.dataGridViewResult.TabIndex = 9;
            // 
            // AnswerBox
            // 
            this.AnswerBox.BackColor = System.Drawing.Color.Azure;
            this.AnswerBox.Location = new System.Drawing.Point(558, 135);
            this.AnswerBox.Margin = new System.Windows.Forms.Padding(4);
            this.AnswerBox.Name = "AnswerBox";
            this.AnswerBox.Size = new System.Drawing.Size(59, 22);
            this.AnswerBox.TabIndex = 10;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(357, 130);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(73, 27);
            this.label3.TabIndex = 11;
            this.label3.Text = "F(x) =";
            // 
            // Transport_form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.ClientSize = new System.Drawing.Size(1379, 659);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.AnswerBox);
            this.Controls.Add(this.dataGridViewResult);
            this.Controls.Add(this.ToExel);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.comboBoxMethod);
            this.Controls.Add(this.numericRow);
            this.Controls.Add(this.numericCol);
            this.Controls.Add(this.buttonRun);
            this.Controls.Add(this.dataGridViewMatrix);
            this.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Transport_form";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewMatrix)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericCol)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericRow)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewResult)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridViewMatrix;
        private System.Windows.Forms.Button buttonRun;
        private System.Windows.Forms.NumericUpDown numericCol;
        private System.Windows.Forms.NumericUpDown numericRow;
        private System.Windows.Forms.ComboBox comboBoxMethod;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button ToExel;
        private System.Windows.Forms.DataGridView dataGridViewResult;
        private System.Windows.Forms.TextBox AnswerBox;
        private System.Windows.Forms.Label label3;
    }
}

