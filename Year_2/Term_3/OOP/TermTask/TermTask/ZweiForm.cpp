#include "ZweiForm.h"
#include "FormEins.h"

using namespace std;
enum GameMode {
	PvP = 0,//игрок против игрока
	PvE //игрок против ии
} gameMode;


//общие данные
GameMap map;
Gamer player1;
Gamer player2;
GamerStatus currentPlayer;//кто из игроков сделал ход
Vector2 selectedCellPlayer;//куда сделал ход
//флажки
bool canPlay;
bool endGame;
//данные ии
vector<Vector2> allMoves;//все возможные ходы
int currentMoves;//текущий ход, с которого начинать

System::Void TermTask::ZweiForm::ZweiForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	//инициализируем параметры
	if (selectedGameMode == 0)
	{
		gameMode = PvP;
	}
	else {
		gameMode = PvE;
	}

	NewGame();//запуск новой игры
}

System::Void TermTask::ZweiForm::TSMMenu_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void TermTask::ZweiForm::TSMNewGame_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Продолжить?", "ВНИМАНИЕ!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes)
	{
		NewGame();
	}
}

System::Void TermTask::ZweiForm::TSMBack_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Продолжить?", "ВНИМАНИЕ!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes)
	{
		FormEins^ form = gcnew FormEins();
		form->Show();
		this->Hide();
	}
}

System::Void TermTask::ZweiForm::TSMAbout_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Программа реализует игру <<Крестики-нолики>> стандартного типа двух игроков и против компьютера. Реализована возможность выбора размерности игрового поля и длинны комбинаций для выигрыша");
}

System::Void TermTask::ZweiForm::TSMExit_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Продолжить?", "ВНИМАНИЕ!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes)
	{
		Application::Exit();
	}
}

System::Void TermTask::ZweiForm::dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	auto senderGrid = (DataGridView^)sender;//преобразуем полученный объект в таблицу

	//запоминаем индексы выбранной ячейки
	selectedCellPlayer.x = e->RowIndex;
	selectedCellPlayer.y = e->ColumnIndex;

	//делаем ход
	SetPositionPlayer(selectedCellPlayer);


}

void TermTask::ZweiForm::GameLogic()
{
	//проверяем режим игры
	if (gameMode == PvE)
	{
		//если очередь ии
		if (currentPlayer == Computer)
		{
			//делаем ход
			StepAI();
		}
		Update();
	}
}

void TermTask::ZweiForm::Update()
{
	if (endGame)
	{
		return;
	}

	//проверка состояния игрового поля
	int state_game = map.CheckingWin();

	if (state_game == 1)
	{
		if (gameMode == PvP)
		{
			MessageBox::Show("Победил Игрок1!", "Поздравляем!");
		}
		else
		{
			MessageBox::Show("Победил Игрок!", "Поздравляем!");
		}
		UpdateGameGrid();
		endGame = true;
	}

	else if (state_game == 2) {
		if (gameMode == PvP)
		{
			MessageBox::Show("Победил Игрок2!", "Поздравляем!");
		}
		else
		{
			MessageBox::Show("Победил Компьтер!", "Поздравляем!");
		}
		UpdateGameGrid();
		endGame = true;
	}
	else if (state_game == 3) {
		MessageBox::Show("Ничья!", "Поздравляем!");

		UpdateGameGrid();
		endGame = true;
	}

	if (endGame)
	{
		if (MessageBox::Show("Запустить новую игру?", "ВНИМАНИЕ!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes)
		{
			NewGame();
		}
		return;
	}

	if (gameMode == PvE)
	{
		if (currentPlayer == Computer)
		{
			toolStripStatusLabel1->Text = "Ход: Игрока!";
			currentPlayer = Player;
			return;

		}
		else {
			toolStripStatusLabel1->Text = "Ход: Компьютера!";
			currentPlayer = Computer;

			GameLogic();
			UpdateGameGrid();
			return;
		}

	}
	else {
		if (currentPlayer == Player1)
		{
			toolStripStatusLabel1->Text = "Ход: 0!";
			currentPlayer = Player2;
		}
		else {
			toolStripStatusLabel1->Text = "Ход: X!";
			currentPlayer = Player1;

		}
	}

	GameLogic();
	UpdateGameGrid();

}

void TermTask::ZweiForm::NewGame()
{
	//инициализация данных

	map.SetMap(rows, columns, length);
	rand = gcnew Random();
	endGame = false;

	CreateGameGrid(map.GetSize());//создаем игровое поле

	//инициализируем все возможные ходы для ии
	currentMoves = 0;
	allMoves.clear();
	Vector2 buf;
	for (int i = 0; i < map.GetSize().x; i++)
	{
		for (int j = 0; j < map.GetSize().x; j++)
		{
			buf.x = i;
			buf.y = j;
			allMoves.push_back(buf);//добавление возможных позиций для хода
		}
	}

	//перемешиваем все возможные ходы несколько раз
	int num_mixing = rand->Next(1, 10);
	for (int i = 0; i < num_mixing; i++)
	{
		random_shuffle(allMoves.begin(), allMoves.end());
	}

	//проверка очередности и режима игры
	int state_gamer = rand->Next(1, 3);
	if (state_gamer == 1)
	{
		if (state_gamer == PvE)
		{
			player1.SetField(Player, 1);
			player2.SetField(Computer, 2);

			toolStripStatusLabel1->Text = "Ход: Игрока!";

			currentPlayer = Player;
		}
		else
		{
			player1.SetField(Player1, 1);
			player2.SetField(Player2, 2);

			toolStripStatusLabel1->Text = "Ход: X!";

			currentPlayer = Player1;
		}
	}
	else if (state_gamer == 2)
	{
		if (state_gamer == PvE)
		{
			player1.SetField(Player, 1);
			player2.SetField(Computer, 2);

			toolStripStatusLabel1->Text = "Ход: Компьютера!";

			currentPlayer = Computer;

			GameLogic();
			UpdateGameGrid();
		}
		else
		{
			player1.SetField(Player1, 1);
			player2.SetField(Player2, 2);

			toolStripStatusLabel1->Text = "Ход: 0!";

			currentPlayer = Player2;
		}
	}
	else {
		MessageBox::Show("Ошибка генерации выбора!", "ОШИБКА!");
		return;
	}

}

void TermTask::ZweiForm::StepAI()
{
	//проверка возможности ходить
	if (currentMoves < allMoves.size())
	{
		//проверка текущего кода
		if (map.IsEmpty(allMoves[currentMoves]))
		{
			//если свободно - делаем ход
			map.SetPosition(allMoves[currentMoves], player2.GetMark());
			currentMoves++;

		}
		else
		{
			//если занята, перемещаемся на след.ход и вызываем ф-цию рекурсивно
			currentMoves++;
			StepAI();
		}

	}

}

void TermTask::ZweiForm::UpdateGameGrid()
{
	for (int i = 0; i < map.GetSize().x; i++)
	{
		for (int j = 0; j < map.GetSize().y; j++)
		{
			if (!map.IsEmpty(i, j))
			{
				if (map.GetValue(i, j) == 1)
				{
					dataGridView->Rows[i]->Cells[j]->Value = "X";
				}
				else
				{
					dataGridView->Rows[i]->Cells[j]->Value = "0";
				}
			}
		}
	}
}

void TermTask::ZweiForm::CreateGameGrid(Vector2 size)
{
	//очищаем таблицу
	dataGridView->Rows->Clear();
	dataGridView->Columns->Clear();

	//задаем стиль
	System::Drawing::Font^ font = gcnew System::Drawing::Font("Microsoft Sans Serif", 14);
	dataGridView->DefaultCellStyle->Font = font;
	dataGridView->ColumnHeadersDefaultCellStyle->Font = font;
	dataGridView->RowHeadersDefaultCellStyle->Font = font;

	//создаем столбцы
	for (int i = 0; i < size.x; i++)
	{
		DataGridViewButtonColumn^ colomn = gcnew DataGridViewButtonColumn();
		colomn->HeaderCell->Value = Convert::ToString(i+1);
		colomn->Name = "colomn" + 1;
		colomn->Width = 50;
		dataGridView->Columns->Add(colomn);
	}

	//создаем строки
	for (int i = 0; i < size.y; i++)
	{
		dataGridView->Rows->Add();
		dataGridView->Rows[i]->HeaderCell->Value = Convert::ToString(i+1); 
		dataGridView->Rows[i]->Height = 50;
		
	}



}

void TermTask::ZweiForm::SetPositionPlayer(Vector2 cell)
{
	//проверяем режим игры
	if (gameMode == PvE)
	{
		//проверка очередности игрока
		if (currentPlayer == Player)
		{
			//делаем ход
			if (!map.SetPosition(cell, player1.GetMark()))
			{
				MessageBox::Show("Данная позиция занята!", "ВНИМАНИЕ!");
				return;
			}
		}
		else
		{
			MessageBox::Show("Сейчас не ваша очередь!", "ВНИМАНИЕ!");
			return;
		}

	}
	else
	{
		//проверяем очередь
		if (currentPlayer == Player1)
		{
			//делаем ход
			if (!map.SetPosition(cell, player1.GetMark()))
			{
				MessageBox::Show("Данная позиция занята!", "ВНИМАНИЕ!");
				return;
			}
		}
		else
		{
			//делаем ход
			if (!map.SetPosition(cell, player2.GetMark()))
			{
				MessageBox::Show("Данная позиция занята!", "ВНИМАНИЕ!");
				return;
			}
		}
	}
	Update();
}
