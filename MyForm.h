#pragma once

namespace Лабиринт {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::NumericUpDown^ EXY;
	private: System::Windows::Forms::NumericUpDown^ EXX;
	private: System::Windows::Forms::NumericUpDown^ STY;
	private: System::Windows::Forms::NumericUpDown^ STX;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::NumericUpDown^ InHeight;
	private: System::Windows::Forms::NumericUpDown^ InWidth;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ APPLY;
	private: System::Windows::Forms::Button^ DOWN;
	private: System::Windows::Forms::Button^ SAVE;



	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ DownFile;
	private: System::Windows::Forms::TextBox^ SaveFile;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

















	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ EXIT;





















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
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->EXY = (gcnew System::Windows::Forms::NumericUpDown());
			this->EXX = (gcnew System::Windows::Forms::NumericUpDown());
			this->STY = (gcnew System::Windows::Forms::NumericUpDown());
			this->STX = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->InHeight = (gcnew System::Windows::Forms::NumericUpDown());
			this->InWidth = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SaveFile = (gcnew System::Windows::Forms::TextBox());
			this->DownFile = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->APPLY = (gcnew System::Windows::Forms::Button());
			this->SAVE = (gcnew System::Windows::Forms::Button());
			this->DOWN = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->EXIT = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EXY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EXX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->STY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->STX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InHeight))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InWidth))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(355, 125);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(16, 16);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Y";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(293, 125);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(15, 16);
			this->label5->TabIndex = 10;
			this->label5->Text = L"X";
			// 
			// EXY
			// 
			this->EXY->BackColor = System::Drawing::SystemColors::Control;
			this->EXY->ForeColor = System::Drawing::SystemColors::MenuText;
			this->EXY->Location = System::Drawing::Point(342, 177);
			this->EXY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->EXY->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->EXY->Name = L"EXY";
			this->EXY->Size = System::Drawing::Size(51, 22);
			this->EXY->TabIndex = 9;
			this->EXY->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// EXX
			// 
			this->EXX->BackColor = System::Drawing::SystemColors::Control;
			this->EXX->ForeColor = System::Drawing::SystemColors::MenuText;
			this->EXX->Location = System::Drawing::Point(273, 177);
			this->EXX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->EXX->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->EXX->Name = L"EXX";
			this->EXX->Size = System::Drawing::Size(54, 22);
			this->EXX->TabIndex = 8;
			this->EXX->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			// 
			// STY
			// 
			this->STY->BackColor = System::Drawing::SystemColors::Control;
			this->STY->ForeColor = System::Drawing::SystemColors::MenuText;
			this->STY->Location = System::Drawing::Point(342, 144);
			this->STY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->STY->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->STY->Name = L"STY";
			this->STY->Size = System::Drawing::Size(51, 22);
			this->STY->TabIndex = 7;
			this->STY->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// STX
			// 
			this->STX->BackColor = System::Drawing::SystemColors::Control;
			this->STX->ForeColor = System::Drawing::SystemColors::MenuText;
			this->STX->Location = System::Drawing::Point(273, 144);
			this->STX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->STX->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->STX->Name = L"STX";
			this->STX->Size = System::Drawing::Size(54, 22);
			this->STX->TabIndex = 6;
			this->STX->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 177);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(251, 16);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Координаты выхода из рабочей зоны";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 144);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(235, 16);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Координаты входа в рабочую зону";
			// 
			// InHeight
			// 
			this->InHeight->BackColor = System::Drawing::SystemColors::Control;
			this->InHeight->ForeColor = System::Drawing::SystemColors::MenuText;
			this->InHeight->Location = System::Drawing::Point(273, 77);
			this->InHeight->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 19, 0, 0, 0 });
			this->InHeight->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->InHeight->Name = L"InHeight";
			this->InHeight->Size = System::Drawing::Size(120, 22);
			this->InHeight->TabIndex = 3;
			this->InHeight->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// InWidth
			// 
			this->InWidth->BackColor = System::Drawing::SystemColors::Control;
			this->InWidth->ForeColor = System::Drawing::SystemColors::MenuText;
			this->InWidth->Location = System::Drawing::Point(273, 44);
			this->InWidth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 19, 0, 0, 0 });
			this->InWidth->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->InWidth->Name = L"InWidth";
			this->InWidth->Size = System::Drawing::Size(120, 22);
			this->InWidth->TabIndex = 2;
			this->InWidth->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(184, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Высота рабочей зоны (н/ч):";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 46);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(187, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ширина рабочей зоны (н/ч):";
			// 
			// SaveFile
			// 
			this->SaveFile->BackColor = System::Drawing::SystemColors::Control;
			this->SaveFile->ForeColor = System::Drawing::SystemColors::MenuText;
			this->SaveFile->Location = System::Drawing::Point(262, 375);
			this->SaveFile->Name = L"SaveFile";
			this->SaveFile->Size = System::Drawing::Size(100, 22);
			this->SaveFile->TabIndex = 4;
			this->SaveFile->Text = L"Save.txt";
			// 
			// DownFile
			// 
			this->DownFile->BackColor = System::Drawing::SystemColors::Control;
			this->DownFile->ForeColor = System::Drawing::SystemColors::MenuText;
			this->DownFile->Location = System::Drawing::Point(262, 320);
			this->DownFile->Name = L"DownFile";
			this->DownFile->Size = System::Drawing::Size(100, 22);
			this->DownFile->TabIndex = 2;
			this->DownFile->Text = L"Download.txt";
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::SystemColors::Control;
			this->comboBox1->ForeColor = System::Drawing::SystemColors::MenuText;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Первый способ", L"Второй способ", L"Случайная генерация",
					L"Ручная генерация"
			});
			this->comboBox1->Location = System::Drawing::Point(241, 259);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(158, 24);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->Text = L"Способ генерации";
			// 
			// APPLY
			// 
			this->APPLY->BackColor = System::Drawing::SystemColors::Control;
			this->APPLY->ForeColor = System::Drawing::SystemColors::MenuText;
			this->APPLY->Location = System::Drawing::Point(262, 291);
			this->APPLY->Name = L"APPLY";
			this->APPLY->Size = System::Drawing::Size(104, 23);
			this->APPLY->TabIndex = 3;
			this->APPLY->Text = L"Применить";
			this->APPLY->UseVisualStyleBackColor = false;
			this->APPLY->Click += gcnew System::EventHandler(this, &MyForm::APPLY_Click);
			// 
			// SAVE
			// 
			this->SAVE->BackColor = System::Drawing::SystemColors::Control;
			this->SAVE->ForeColor = System::Drawing::SystemColors::MenuText;
			this->SAVE->Location = System::Drawing::Point(52, 374);
			this->SAVE->Name = L"SAVE";
			this->SAVE->Size = System::Drawing::Size(104, 23);
			this->SAVE->TabIndex = 1;
			this->SAVE->Text = L"Сохранить";
			this->SAVE->UseVisualStyleBackColor = false;
			this->SAVE->Click += gcnew System::EventHandler(this, &MyForm::SAVE_Click);
			// 
			// DOWN
			// 
			this->DOWN->BackColor = System::Drawing::SystemColors::Control;
			this->DOWN->ForeColor = System::Drawing::SystemColors::MenuText;
			this->DOWN->Location = System::Drawing::Point(52, 320);
			this->DOWN->Name = L"DOWN";
			this->DOWN->Size = System::Drawing::Size(104, 23);
			this->DOWN->TabIndex = 2;
			this->DOWN->Text = L"Загрузить";
			this->DOWN->UseVisualStyleBackColor = false;
			this->DOWN->Click += gcnew System::EventHandler(this, &MyForm::DOWN_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 262);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(223, 16);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Способ генерации рабочей зоны";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(407, 15);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(523, 476);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellClick);
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellDoubleClick);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(13, 224);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(69, 16);
			this->label8->TabIndex = 20;
			this->label8->Text = L"Действия";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(13, 15);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(173, 16);
			this->label9->TabIndex = 21;
			this->label9->Text = L"Настройки рабочей зоны";
			// 
			// EXIT
			// 
			this->EXIT->BackColor = System::Drawing::SystemColors::Control;
			this->EXIT->ForeColor = System::Drawing::SystemColors::MenuText;
			this->EXIT->Location = System::Drawing::Point(117, 434);
			this->EXIT->Name = L"EXIT";
			this->EXIT->Size = System::Drawing::Size(169, 23);
			this->EXIT->TabIndex = 22;
			this->EXIT->Text = L"Выйти";
			this->EXIT->UseVisualStyleBackColor = false;
			this->EXIT->Click += gcnew System::EventHandler(this, &MyForm::EXIT_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(932, 493);
			this->Controls->Add(this->EXIT);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->SAVE);
			this->Controls->Add(this->EXY);
			this->Controls->Add(this->SaveFile);
			this->Controls->Add(this->EXX);
			this->Controls->Add(this->DOWN);
			this->Controls->Add(this->STY);
			this->Controls->Add(this->STX);
			this->Controls->Add(this->DownFile);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->APPLY);
			this->Controls->Add(this->InHeight);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->InWidth);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"ГЕНЕРАТОР КАРТЫ РАБОЧЕЙ ЗОНЫ ДЛЯ МОБИЛЬНЫХ РОБОТОВ";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EXY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EXX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->STY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->STX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InHeight))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InWidth))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void DOWN_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void SAVE_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void APPLY_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void dataGridView1_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	   void Лабиринт::MyForm::CreateMap();
	   void Лабиринт::MyForm::VISUAL();
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
	   void Лабиринт::MyForm::FindChanges();
	   int Лабиринт::MyForm::FindBugs();
private: System::Void EXIT_Click(System::Object^ sender, System::EventArgs^ e);
};
}
