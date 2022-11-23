#include "ZweiForm.h"
#include "FormEins.h"

using namespace std;
enum GameMode {
	PvP = 0,//����� ������ ������
	PvE //����� ������ ��
} gameMode;


//����� ������
GameMap map;
Gamer player1;
Gamer player2;
GamerStatus currentPlayer;//��� �� ������� ������ ���
Vector2 selectedCellPlayer;//���� ������ ���
//������
bool canPlay;
bool endGame;
//������ ��
vector<Vector2> allMoves;//��� ��������� ����
int currentMoves;//������� ���, � �������� ��������

System::Void TermTask::ZweiForm::ZweiForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	//�������������� ���������
	if (selectedGameMode == 0)
	{
		gameMode = PvP;
	}
	else {
		gameMode = PvE;
	}

	NewGame();//������ ����� ����
}

System::Void TermTask::ZweiForm::TSMMenu_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void TermTask::ZweiForm::TSMNewGame_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("����������?", "��������!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes)
	{
		NewGame();
	}
}

System::Void TermTask::ZweiForm::TSMBack_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("����������?", "��������!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes)
	{
		FormEins^ form = gcnew FormEins();
		form->Show();
		this->Hide();
	}
}

System::Void TermTask::ZweiForm::TSMAbout_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("��������� ��������� ���� <<��������-������>> ������������ ���� ���� ������� � ������ ����������. ����������� ����������� ������ ����������� �������� ���� � ������ ���������� ��� ��������");
}

System::Void TermTask::ZweiForm::TSMExit_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("����������?", "��������!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes)
	{
		Application::Exit();
	}
}

System::Void TermTask::ZweiForm::dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	auto senderGrid = (DataGridView^)sender;//����������� ���������� ������ � �������

	//���������� ������� ��������� ������
	selectedCellPlayer.x = e->RowIndex;
	selectedCellPlayer.y = e->ColumnIndex;

	//������ ���
	SetPositionPlayer(selectedCellPlayer);


}

void TermTask::ZweiForm::GameLogic()
{
	//��������� ����� ����
	if (gameMode == PvE)
	{
		//���� ������� ��
		if (currentPlayer == Computer)
		{
			//������ ���
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

	//�������� ��������� �������� ����
	int state_game = map.CheckingWin();

	if (state_game == 1)
	{
		if (gameMode == PvP)
		{
			MessageBox::Show("������� �����1!", "�����������!");
		}
		else
		{
			MessageBox::Show("������� �����!", "�����������!");
		}
		UpdateGameGrid();
		endGame = true;
	}

	else if (state_game == 2) {
		if (gameMode == PvP)
		{
			MessageBox::Show("������� �����2!", "�����������!");
		}
		else
		{
			MessageBox::Show("������� ��������!", "�����������!");
		}
		UpdateGameGrid();
		endGame = true;
	}
	else if (state_game == 3) {
		MessageBox::Show("�����!", "�����������!");

		UpdateGameGrid();
		endGame = true;
	}

	if (endGame)
	{
		if (MessageBox::Show("��������� ����� ����?", "��������!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes)
		{
			NewGame();
		}
		return;
	}

	if (gameMode == PvE)
	{
		if (currentPlayer == Computer)
		{
			toolStripStatusLabel1->Text = "���: ������!";
			currentPlayer = Player;
			return;

		}
		else {
			toolStripStatusLabel1->Text = "���: ����������!";
			currentPlayer = Computer;

			GameLogic();
			UpdateGameGrid();
			return;
		}

	}
	else {
		if (currentPlayer == Player1)
		{
			toolStripStatusLabel1->Text = "���: 0!";
			currentPlayer = Player2;
		}
		else {
			toolStripStatusLabel1->Text = "���: X!";
			currentPlayer = Player1;

		}
	}

	GameLogic();
	UpdateGameGrid();

}

void TermTask::ZweiForm::NewGame()
{
	//������������� ������

	map.SetMap(rows, columns, length);
	rand = gcnew Random();
	endGame = false;

	CreateGameGrid(map.GetSize());//������� ������� ����

	//�������������� ��� ��������� ���� ��� ��
	currentMoves = 0;
	allMoves.clear();
	Vector2 buf;
	for (int i = 0; i < map.GetSize().x; i++)
	{
		for (int j = 0; j < map.GetSize().x; j++)
		{
			buf.x = i;
			buf.y = j;
			allMoves.push_back(buf);//���������� ��������� ������� ��� ����
		}
	}

	//������������ ��� ��������� ���� ��������� ���
	int num_mixing = rand->Next(1, 10);
	for (int i = 0; i < num_mixing; i++)
	{
		random_shuffle(allMoves.begin(), allMoves.end());
	}

	//�������� ����������� � ������ ����
	int state_gamer = rand->Next(1, 3);
	if (state_gamer == 1)
	{
		if (state_gamer == PvE)
		{
			player1.SetField(Player, 1);
			player2.SetField(Computer, 2);

			toolStripStatusLabel1->Text = "���: ������!";

			currentPlayer = Player;
		}
		else
		{
			player1.SetField(Player1, 1);
			player2.SetField(Player2, 2);

			toolStripStatusLabel1->Text = "���: X!";

			currentPlayer = Player1;
		}
	}
	else if (state_gamer == 2)
	{
		if (state_gamer == PvE)
		{
			player1.SetField(Player, 1);
			player2.SetField(Computer, 2);

			toolStripStatusLabel1->Text = "���: ����������!";

			currentPlayer = Computer;

			GameLogic();
			UpdateGameGrid();
		}
		else
		{
			player1.SetField(Player1, 1);
			player2.SetField(Player2, 2);

			toolStripStatusLabel1->Text = "���: 0!";

			currentPlayer = Player2;
		}
	}
	else {
		MessageBox::Show("������ ��������� ������!", "������!");
		return;
	}

}

void TermTask::ZweiForm::StepAI()
{
	//�������� ����������� ������
	if (currentMoves < allMoves.size())
	{
		//�������� �������� ����
		if (map.IsEmpty(allMoves[currentMoves]))
		{
			//���� �������� - ������ ���
			map.SetPosition(allMoves[currentMoves], player2.GetMark());
			currentMoves++;

		}
		else
		{
			//���� ������, ������������ �� ����.��� � �������� �-��� ����������
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
	//������� �������
	dataGridView->Rows->Clear();
	dataGridView->Columns->Clear();

	//������ �����
	System::Drawing::Font^ font = gcnew System::Drawing::Font("Microsoft Sans Serif", 14);
	dataGridView->DefaultCellStyle->Font = font;
	dataGridView->ColumnHeadersDefaultCellStyle->Font = font;
	dataGridView->RowHeadersDefaultCellStyle->Font = font;

	//������� �������
	for (int i = 0; i < size.x; i++)
	{
		DataGridViewButtonColumn^ colomn = gcnew DataGridViewButtonColumn();
		colomn->HeaderCell->Value = Convert::ToString(i+1);
		colomn->Name = "colomn" + 1;
		colomn->Width = 50;
		dataGridView->Columns->Add(colomn);
	}

	//������� ������
	for (int i = 0; i < size.y; i++)
	{
		dataGridView->Rows->Add();
		dataGridView->Rows[i]->HeaderCell->Value = Convert::ToString(i+1); 
		dataGridView->Rows[i]->Height = 50;
		
	}



}

void TermTask::ZweiForm::SetPositionPlayer(Vector2 cell)
{
	//��������� ����� ����
	if (gameMode == PvE)
	{
		//�������� ����������� ������
		if (currentPlayer == Player)
		{
			//������ ���
			if (!map.SetPosition(cell, player1.GetMark()))
			{
				MessageBox::Show("������ ������� ������!", "��������!");
				return;
			}
		}
		else
		{
			MessageBox::Show("������ �� ���� �������!", "��������!");
			return;
		}

	}
	else
	{
		//��������� �������
		if (currentPlayer == Player1)
		{
			//������ ���
			if (!map.SetPosition(cell, player1.GetMark()))
			{
				MessageBox::Show("������ ������� ������!", "��������!");
				return;
			}
		}
		else
		{
			//������ ���
			if (!map.SetPosition(cell, player2.GetMark()))
			{
				MessageBox::Show("������ ������� ������!", "��������!");
				return;
			}
		}
	}
	Update();
}
