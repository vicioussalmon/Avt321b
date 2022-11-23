#pragma once
#include "GameMap.h"
#include "Gamer.h"

#include <Windows.h>
namespace TermTask {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ZweiForm
	/// </summary>
	public ref class ZweiForm : public System::Windows::Forms::Form
	{
	public:
		ZweiForm(void)
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
		~ZweiForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ TSMMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ TSMNewGame;
	private: System::Windows::Forms::ToolStripMenuItem^ TSMBack;
	private: System::Windows::Forms::ToolStripMenuItem^ TSMAbout;
	private: System::Windows::Forms::ToolStripMenuItem^ TSMExit;
	protected:





	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
	private: System::Windows::Forms::DataGridView^ dataGridView;

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
			this->TSMMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->TSMNewGame = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->TSMBack = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->TSMAbout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->TSMExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->TSMMenu, this->TSMAbout,
					this->TSMExit
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(10, 3, 0, 3);
			this->menuStrip1->Size = System::Drawing::Size(351, 31);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// TSMMenu
			// 
			this->TSMMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->TSMNewGame,
					this->TSMBack
			});
			this->TSMMenu->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TSMMenu->Name = L"TSMMenu";
			this->TSMMenu->Size = System::Drawing::Size(70, 25);
			this->TSMMenu->Text = L"Меню";
			this->TSMMenu->Click += gcnew System::EventHandler(this, &ZweiForm::TSMMenu_Click);
			// 
			// TSMNewGame
			// 
			this->TSMNewGame->Name = L"TSMNewGame";
			this->TSMNewGame->Size = System::Drawing::Size(170, 26);
			this->TSMNewGame->Text = L"Новая игра";
			this->TSMNewGame->Click += gcnew System::EventHandler(this, &ZweiForm::TSMNewGame_Click);
			// 
			// TSMBack
			// 
			this->TSMBack->Name = L"TSMBack";
			this->TSMBack->Size = System::Drawing::Size(170, 26);
			this->TSMBack->Text = L"Вернуться";
			this->TSMBack->Click += gcnew System::EventHandler(this, &ZweiForm::TSMBack_Click);
			// 
			// TSMAbout
			// 
			this->TSMAbout->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TSMAbout->Name = L"TSMAbout";
			this->TSMAbout->Size = System::Drawing::Size(129, 25);
			this->TSMAbout->Text = L"О программе";
			this->TSMAbout->Click += gcnew System::EventHandler(this, &ZweiForm::TSMAbout_Click);
			// 
			// TSMExit
			// 
			this->TSMExit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TSMExit->Name = L"TSMExit";
			this->TSMExit->Size = System::Drawing::Size(74, 25);
			this->TSMExit->Text = L"Выход";
			this->TSMExit->Click += gcnew System::EventHandler(this, &ZweiForm::TSMExit_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel1 });
			this->statusStrip1->Location = System::Drawing::Point(0, 249);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(351, 22);
			this->statusStrip1->TabIndex = 1;
			this->statusStrip1->Text = L"Ход:";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(30, 17);
			this->toolStripStatusLabel1->Text = L"Ход:";
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView->Location = System::Drawing::Point(0, 31);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->Size = System::Drawing::Size(351, 218);
			this->dataGridView->TabIndex = 2;
			this->dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ZweiForm::dataGridView_CellContentClick);
			// 
			// ZweiForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 21);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(351, 271);
			this->Controls->Add(this->dataGridView);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"ZweiForm";
			this->Text = L"Крестики-нолики";
			this->Load += gcnew System::EventHandler(this, &ZweiForm::ZweiForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//поля игры
	public: int rows;
	public: int columns;
	public: int length;
	public: int selectedGameMode;
	private: Random^ rand;
		   //методы игры
	private: void GameLogic();//реализация игровой логики
	private: void Update();//обновление
	private: void NewGame();//запуск игры
	private: void StepAI();//ход ии
	private: void UpdateGameGrid();//обновление игровой сетки
	private: void CreateGameGrid(Vector2);//создание игровой сетки
	private: void SetPositionPlayer(Vector2);//задавание позиции игрока в игровой сетке
		   //события игры
    private: System::Void ZweiForm_Load(System::Object^ sender, System::EventArgs^ e);
    private: System::Void TSMMenu_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void TSMAbout_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void TSMNewGame_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void TSMBack_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void TSMExit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
};
}
