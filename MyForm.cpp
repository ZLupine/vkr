#include "MyForm.h"
#include <iostream>
#include <string>
#include "MAZE.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(cli::array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Лабиринт::MyForm form;
	Application::Run(% form);
}

//Глобальные динамические массивы maze и A
int** maze, ** A;

//Константы стена, проход, вход и выход
const int wall = 0, pass = 1, start = 2, finish = 3;

//Глобальные переменные высоты и ширины лабиринта
int height, width;


//Подпрограмма загрузки лабиринта из файла
//при нажатии на кнопку "Загрузить"
System::Void Лабиринт::MyForm::DOWN_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string FileOut;
	Convert_String_To_string(DownFile->Text->ToString(), FileOut);
	std::ifstream g(FileOut);
	if (g)
	{
		int b = 0, L=0, k, n;
		std::string s;
		while (!g.eof())
		{
			getline(g, s, '\n');
			k = s.size();
			for (int i = 0; i < k; i++)
			{
				if (s[i] != '#' && s[i] != ' ' &&
					s[i] != 'S' && s[i] != 'E')
				{
					L = 1;
					break;
				}

			}
			if (L == 1)
				break;
			if (b == 0)
				n = k;
			else if (k != n)
			{
				L = 1;
				break;
			}
			b++;
		}
		if (L == 1)
			MessageBox::Show(this, "Файл содержит ошибку!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else
		{
			g.seekg(0);
			height = b;
			width = k;
			CreateMap();
			maze = new int* [height];
			for (int i = 0; i < height; i++)
				maze[i] = new int[width];
			std::ifstream g(FileOut);
			for (int i = 0; i < height; i++)
			{
				getline(g, s, '\n');
				for (int j = 0; j < width; j++)
				{
					switch (s[j])
					{
					case '#':
						maze[i][j] = wall;
						break;
					case ' ':
						maze[i][j] = pass;
						break;
					case 'S':
						maze[i][j] = start;
						break;
					case 'E':
						maze[i][j] = finish;
						break;
					}
				}
			}
			VISUAL();
			g.close();
		}
	}
	else
		MessageBox::Show(this, "Файл отсутствует!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);;
}


//Подпрограмма сохранения лабиринта в файл
//при нажатии на кнопку "Сохранить"
System::Void Лабиринт::MyForm::SAVE_Click(System::Object^ sender, System::EventArgs^ e)
{
	int st=0, r=0, d=0, fn=0;
	std::string FileOut;
	Convert_String_To_string(SaveFile->Text->ToString(), FileOut);
	std::ofstream f(FileOut);
	FindChanges();
	if (f && FindBugs()) {
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				switch (maze[i][j])
				{
				case wall:
					f << "#";
					break;
				case pass:
					f << " ";
					break;
				case start:
					f << "S";
					break;
				case finish:
					f << "E";
					break;
				}
			}
			if (i != height - 1)
				f << '\n';
		}
		MessageBox::Show(this, "Карта рабочей зоны успешно сохранена в файл.", "Compleat", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
}


//Подпрограмма для генерации лабиринта в
//соответствии с введёнными параметрами
//при нажатии на кнопку "Применить"
System::Void Лабиринт::MyForm::APPLY_Click(System::Object^ sender, System::EventArgs^ e)
{
	width = Convert::ToInt32(InWidth->Value);
	height = Convert::ToInt32(InHeight->Value);
	if (width % 2 == 1 && height % 2 == 1)
	{
		int x1 = Convert::ToInt32(STX->Value)-1;
		int y1 = Convert::ToInt32(STY->Value)-1;
		int x2 = Convert::ToInt32(EXX->Value)-1;
		int y2 = Convert::ToInt32(EXY->Value)-1;
		if ((x1 != x2 || y1 != y2) && (x1 == 0 || x1 == width - 1 ||
			y1 == 0 || y1 == height - 1) && (x2 == 0 || x2 == width - 1 ||
				y2 == 0 || y2 == height - 1) && (x1 < width-1 && y1 < height-1 &&
					x2 < width-1 && y2 < height-1))
		{
			CreateMap();
			maze = new int* [height];
			for (int i = 0; i < height; i++)
				maze[i] = new int[width];
			switch (comboBox1->SelectedIndex)
			{
			case 0:
			{
				maze1(maze, height, width);
				maze[y1][x1] = start;
				maze[y2][x2] = finish;
				VISUAL();
			}
			break;
			case 1:
			{
				{
					A = new int* [height];
					for (int i = 0; i < height; i++)
						A[i] = new int[width];
					maze2(maze, A, height, width);
					maze[y1][x1] = start;
					maze[y2][x2] = finish;
					VISUAL();
				}
			}
			break;
			case 2:
			{
				mazer(maze, height, width);
				maze[y1][x1] = start;
				maze[y2][x2] = finish;
				VISUAL();
			}
			break;
			case 3:
			{
				mazeu(maze, height, width);
				maze[y1][x1] = start;
				maze[y2][x2] = finish;
				VISUAL();
			}
			break;
			default:
			{
				MessageBox::Show(this, "Не выбран способ генерации рабочей зоны!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			}
		}
		else
		{
			MessageBox::Show(this, "Введённые координаты входа или выхода некорректны!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		MessageBox::Show(this, "Введённые размеры рабочей зоны некорректны!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}


//Подпрограмма которая изменяет элемент
//лабиринта при нажатии на него со стены
//на проход, с входа на выход и наоборот
System::Void Лабиринт::MyForm::dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	int x, y;
	x = e->RowIndex;
	y = e->ColumnIndex;
	if (dataGridView1->Rows[x]->Cells[y]->Style->BackColor == Color::Black)
	{
		dataGridView1->Rows[x]->Cells[y]->Style->BackColor = Color::Empty;
		dataGridView1->Rows[x]->Cells[y]->Style->ForeColor = Color::Empty;
		dataGridView1->ClearSelection();
	}
	else if (dataGridView1->Rows[x]->Cells[y]->Style->BackColor == Color::Empty)
	{
		dataGridView1->Rows[x]->Cells[y]->Style->BackColor = Color::Black;
		dataGridView1->Rows[x]->Cells[y]->Style->ForeColor = Color::Black;
		dataGridView1->ClearSelection();
	}
	else if (dataGridView1->Rows[x]->Cells[y]->Style->BackColor == Color::Yellow)
	{
		dataGridView1->Rows[x]->Cells[y]->Style->BackColor = Color::Red;
		dataGridView1->Rows[x]->Cells[y]->Style->ForeColor = Color::Red;
		dataGridView1->ClearSelection();
	}
	else if (dataGridView1->Rows[x]->Cells[y]->Style->BackColor == Color::Red)
	{
		dataGridView1->Rows[x]->Cells[y]->Style->BackColor = Color::Yellow;
		dataGridView1->Rows[x]->Cells[y]->Style->ForeColor = Color::Yellow;
		dataGridView1->ClearSelection();
	}
}


//Подпрограмма которая изменяет элемент
//лабиринта при двойном нажатии на него со стены
//на вход, с прохода на выход и наоборот
System::Void Лабиринт::MyForm::dataGridView1_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	int x, y;
	x = e->RowIndex;
	y = e->ColumnIndex;
	if (dataGridView1->Rows[x]->Cells[y]->Style->BackColor == Color::Black)
	{
		dataGridView1->Rows[x]->Cells[y]->Style->BackColor = Color::Yellow;
		dataGridView1->Rows[x]->Cells[y]->Style->ForeColor = Color::Yellow;
		dataGridView1->ClearSelection();
	}
	else if (dataGridView1->Rows[x]->Cells[y]->Style->BackColor == Color::Empty)
	{
		dataGridView1->Rows[x]->Cells[y]->Style->BackColor = Color::Red;
		dataGridView1->Rows[x]->Cells[y]->Style->ForeColor = Color::Red;
		dataGridView1->ClearSelection();
	}
	else if (dataGridView1->Rows[x]->Cells[y]->Style->BackColor == Color::Yellow)
	{
		dataGridView1->Rows[x]->Cells[y]->Style->BackColor = Color::Black;
		dataGridView1->Rows[x]->Cells[y]->Style->ForeColor = Color::Black;
		dataGridView1->ClearSelection();
	}
	else if (dataGridView1->Rows[x]->Cells[y]->Style->BackColor == Color::Red)
	{
		dataGridView1->Rows[x]->Cells[y]->Style->BackColor = Color::Empty;
		dataGridView1->Rows[x]->Cells[y]->Style->ForeColor = Color::Empty;
		dataGridView1->ClearSelection();
	}
}

System::Void Лабиринт::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
}

//Выход из программы
System::Void Лабиринт::MyForm::EXIT_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}


//Подпрограмма которая создаёт таблицу
//dataGridView по заданным значениям 
//height и width
void Лабиринт::MyForm::CreateMap()
{
	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();
	for (int i = 0; i < width; i++) {
		DataGridViewTextBoxColumn^ column = gcnew DataGridViewTextBoxColumn();
		column->Width = 20;
		dataGridView1->Columns->Add(column);
	}

	for (int i = 0; i < height; i++) {
		dataGridView1->Rows->Add();
		dataGridView1->Rows[i]->Height = 20;
	}
	dataGridView1->ColumnHeadersVisible = false;
	dataGridView1->RowHeadersVisible = false;
	dataGridView1->ClearSelection();
}

//Подпрограмма которая окрашивает
//ячейки dataGridView в соответствии
//со значениеми ячеек лабиринта
void Лабиринт::MyForm::VISUAL()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			switch (maze[i][j])
			{
			case wall:
			{
				dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::Black;
				dataGridView1->Rows[i]->Cells[j]->Style->ForeColor = Color::Black;
				dataGridView1->ClearSelection();
			}
				break;
			case pass:
			{
				dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::Empty;
				dataGridView1->Rows[i]->Cells[j]->Style->ForeColor = Color::Empty;
				dataGridView1->ClearSelection();
			}
				break;
			case start:
			{
				dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::Yellow;
				dataGridView1->Rows[i]->Cells[j]->Style->ForeColor = Color::Yellow;
				dataGridView1->ClearSelection();
			}
				break;
			case finish:
			{
				dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::Red;
				dataGridView1->Rows[i]->Cells[j]->Style->ForeColor = Color::Red;
				dataGridView1->ClearSelection();
			}
				break;
			}
		}
	}
}

//Подпрограмма которая сравнивает сгенерированный
//лабиринт с текущим, и записывает изменения в динамический
//массив maze
void Лабиринт::MyForm::FindChanges()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (dataGridView1->Rows[i]->Cells[j]->Style->BackColor == Color::Black)
				maze[i][j] = wall;
			else if (dataGridView1->Rows[i]->Cells[j]->Style->BackColor == Color::Empty)
				maze[i][j] = pass;
			else if (dataGridView1->Rows[i]->Cells[j]->Style->BackColor == Color::Yellow)
				maze[i][j] = start;
			else if (dataGridView1->Rows[i]->Cells[j]->Style->BackColor == Color::Red)
				maze[i][j] = finish;
		}
	}
}

//Подпрограмма которая находит некоректности
//в текущем лабиринте, и выводит соответствующие
//сообщения об ошибках
int Лабиринт::MyForm::FindBugs()
{
	int st = 0, r = 0, d = 0, fn = 0, t=0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (maze[i][j] == start || maze[i][j] == finish)
			{
				if (maze[i][j] == start)
					st++;
				else
					fn++;
				if (i != 0 && i != height - 1 && j != 0 && j != width - 1)
					r++;
			}
			if (maze[i][j] == pass && (i == 0 || i == height - 1 || j == 0 || j == width - 1))
				d++;
		}
	}
	if (d == 0)
	{
		if (r == 0)
		{
			if (st == 1 && fn == 1)
			{
				t = 1;
			}
			else
			{
				MessageBox::Show(this, "Количество входов или выходов некорректно!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else
		{
			MessageBox::Show(this, "Вод или выход находится не на границе рабочей зоны!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		MessageBox::Show(this, "Нарушена целостность рабочей зоны!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	return t;
}