#include "FormEins.h"
#include "ZweiForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace std;

[STAThread]
void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TermTask::FormEins form;
	Application::Run(% form);
}
//TermTask::FormEins::FormEins(void)
//{
//	InitializeComponent();
//}

System::Void TermTask::FormEins::TSMAbout_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("��������� ��������� ���� <<��������-������>> ������������ ���� ���� ������� � ������ ����������. ����������� ����������� ������ ����������� �������� ���� � ������ ���������� ��� ��������");
}

System::Void TermTask::FormEins::TSMExit_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("����������?", "��������!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes)
	{
		Application::Exit();
	}
}

System::Void TermTask::FormEins::buttonStartGame_Click(System::Object^ sender, System::EventArgs^ e)
{
	int indexGameMode = LBGameMode->SelectedIndex;
	if (indexGameMode == -1) {
		MessageBox::Show("������ ����� ���� ����������!", "��������!");
		return;
	}

	int size;
	size = Convert::ToInt32(NUDSizeMap->Value);

	NUDWinCombination->Maximum = size;
	int length = Convert::ToInt32(NUDWinCombination->Value);


	ZweiForm^ form = gcnew ZweiForm();
	form->rows = size;
	form->columns = size;
	form->length = length;
	form->selectedGameMode = indexGameMode;
	form->Show();
	this->Hide();
}


