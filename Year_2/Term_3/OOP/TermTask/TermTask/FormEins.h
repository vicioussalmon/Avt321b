#pragma once

namespace TermTask {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для FormEins
	/// </summary>
	public ref class FormEins : public System::Windows::Forms::Form
	{
	public:
		FormEins(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FormEins()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ TSMAbout;
	private: System::Windows::Forms::ToolStripMenuItem^ TSMExit;

	private: System::Windows::Forms::Button^ buttonStartGame;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::NumericUpDown^ NUDSizeMap;
	private: System::Windows::Forms::NumericUpDown^ NUDWinCombination;
	private: System::Windows::Forms::ListBox^ LBGameMode;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->TSMAbout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->TSMExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buttonStartGame = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->NUDSizeMap = (gcnew System::Windows::Forms::NumericUpDown());
			this->NUDWinCombination = (gcnew System::Windows::Forms::NumericUpDown());
			this->LBGameMode = (gcnew System::Windows::Forms::ListBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUDSizeMap))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUDWinCombination))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->TSMAbout, this->TSMExit });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(10, 3, 0, 3);
			this->menuStrip1->Size = System::Drawing::Size(524, 31);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// TSMAbout
			// 
			this->TSMAbout->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TSMAbout->Name = L"TSMAbout";
			this->TSMAbout->Size = System::Drawing::Size(129, 25);
			this->TSMAbout->Text = L"О программе";
			this->TSMAbout->Click += gcnew System::EventHandler(this, &FormEins::TSMAbout_Click);
			// 
			// TSMExit
			// 
			this->TSMExit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TSMExit->Name = L"TSMExit";
			this->TSMExit->Size = System::Drawing::Size(74, 25);
			this->TSMExit->Text = L"Выход";
			this->TSMExit->Click += gcnew System::EventHandler(this, &FormEins::TSMExit_Click);
			// 
			// buttonStartGame
			// 
			this->buttonStartGame->Location = System::Drawing::Point(208, 178);
			this->buttonStartGame->Name = L"buttonStartGame";
			this->buttonStartGame->Size = System::Drawing::Size(129, 34);
			this->buttonStartGame->TabIndex = 1;
			this->buttonStartGame->Text = L"Новая игра";
			this->buttonStartGame->UseVisualStyleBackColor = true;
			this->buttonStartGame->Click += gcnew System::EventHandler(this, &FormEins::buttonStartGame_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(193, 21);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Выберите режим игры";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 93);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(239, 21);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Выберите размерность поля";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 136);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(359, 21);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Выберите длину выигрышных комбинаций";
			// 
			// NUDSizeMap
			// 
			this->NUDSizeMap->Location = System::Drawing::Point(392, 85);
			this->NUDSizeMap->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->NUDSizeMap->Name = L"NUDSizeMap";
			this->NUDSizeMap->Size = System::Drawing::Size(120, 29);
			this->NUDSizeMap->TabIndex = 5;
			this->NUDSizeMap->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// NUDWinCombination
			// 
			this->NUDWinCombination->Location = System::Drawing::Point(392, 128);
			this->NUDWinCombination->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->NUDWinCombination->Name = L"NUDWinCombination";
			this->NUDWinCombination->Size = System::Drawing::Size(120, 29);
			this->NUDWinCombination->TabIndex = 6;
			this->NUDWinCombination->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// LBGameMode
			// 
			this->LBGameMode->FormattingEnabled = true;
			this->LBGameMode->ItemHeight = 21;
			this->LBGameMode->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"PvP", L"PvE" });
			this->LBGameMode->Location = System::Drawing::Point(392, 46);
			this->LBGameMode->Name = L"LBGameMode";
			this->LBGameMode->Size = System::Drawing::Size(120, 25);
			this->LBGameMode->TabIndex = 7;
			// 
			// FormEins
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 21);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(524, 224);
			this->Controls->Add(this->LBGameMode);
			this->Controls->Add(this->NUDWinCombination);
			this->Controls->Add(this->NUDSizeMap);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonStartGame);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(5);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(540, 263);
			this->MinimumSize = System::Drawing::Size(540, 263);
			this->Name = L"FormEins";
			this->Text = L"New Game";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUDSizeMap))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUDWinCombination))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void TSMAbout_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void TSMExit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonStartGame_Click(System::Object^ sender, System::EventArgs^ e);
};
}
