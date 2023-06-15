﻿namespace Simplex_Method
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.buttonOk = new System.Windows.Forms.Button();
            this.textBoxNumberOfVariables = new System.Windows.Forms.TextBox();
            this.textBoxNumberOfConstraints = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(12, 32);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(201, 21);
            this.label1.TabIndex = 0;
            this.label1.Text = "Enter number of variables";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(12, 113);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(222, 21);
            this.label2.TabIndex = 1;
            this.label2.Text = "Enter number of constraints ";
            // 
            // buttonOk
            // 
            this.buttonOk.BackColor = System.Drawing.Color.Linen;
            this.buttonOk.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonOk.Location = new System.Drawing.Point(153, 197);
            this.buttonOk.Name = "buttonOk";
            this.buttonOk.Size = new System.Drawing.Size(81, 31);
            this.buttonOk.TabIndex = 2;
            this.buttonOk.Text = "GO";
            this.buttonOk.UseVisualStyleBackColor = false;
            this.buttonOk.Click += new System.EventHandler(this.buttonOk_Click);
            // 
            // textBoxNumberOfVariables
            // 
            this.textBoxNumberOfVariables.BackColor = System.Drawing.Color.NavajoWhite;
            this.textBoxNumberOfVariables.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.textBoxNumberOfVariables.Location = new System.Drawing.Point(16, 56);
            this.textBoxNumberOfVariables.MaxLength = 2;
            this.textBoxNumberOfVariables.Name = "textBoxNumberOfVariables";
            this.textBoxNumberOfVariables.Size = new System.Drawing.Size(71, 29);
            this.textBoxNumberOfVariables.TabIndex = 3;
            // 
            // textBoxNumberOfConstraints
            // 
            this.textBoxNumberOfConstraints.BackColor = System.Drawing.Color.NavajoWhite;
            this.textBoxNumberOfConstraints.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.textBoxNumberOfConstraints.Location = new System.Drawing.Point(16, 137);
            this.textBoxNumberOfConstraints.MaxLength = 2;
            this.textBoxNumberOfConstraints.Name = "textBoxNumberOfConstraints";
            this.textBoxNumberOfConstraints.Size = new System.Drawing.Size(71, 29);
            this.textBoxNumberOfConstraints.TabIndex = 4;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoScroll = true;
            this.AutoSize = true;
            this.BackColor = System.Drawing.Color.NavajoWhite;
            this.ClientSize = new System.Drawing.Size(382, 240);
            this.Controls.Add(this.textBoxNumberOfConstraints);
            this.Controls.Add(this.textBoxNumberOfVariables);
            this.Controls.Add(this.buttonOk);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "Simplex-method calculator";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button buttonOk;
        private System.Windows.Forms.TextBox textBoxNumberOfVariables;
        private System.Windows.Forms.TextBox textBoxNumberOfConstraints;
    }
}

