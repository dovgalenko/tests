#pragma once

#include<time.h>
#include<stdlib.h>
#include<conio.h>

namespace FormProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ListBox^  listBox1;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(592, 350);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 32);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Старт";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(12, 12);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(655, 324);
			this->listBox1->TabIndex = 1;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(679, 394);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		time_t t;
		float max, min;
		float sum = 0;
		float side_sum = 0, main_sum = 0;

		//float arr[10][10];
		float arr[10][10] = {
			{ 0.34, 23, 34, 23, 2, 7, 75, 9, 45, 34 },
			{ 0, 23, 34, 23, 2, 7, 75, 9, 45, 34 },
			{ 0, 23, 34, 23, 2, 7, 75, 9, 45, 34 },
			{ 0, 23, 34, 23, 2, 7, 75, 9, 45, 34 },
			{ 0, 23, 34, 23, 2, 7, 75, 9, 45, 34 },
			{ 0, 23, 34, 23, 2, 7, 75, 9, 45, 34 },
			{ 0, 23, 34, 23, 2, 7.5, 75, 9, 45, 34 },
			{ 0, 23, 34, 23, 2, 7, 75, 9, 45, 34 },
			{ 0, 23, 34, 23, 2, 7, 75, 9, 45, 34 },
			{ 0, 23, 34, 23, 2, 7, 75, 9, 45, 93.6 }
		};

		listBox1->BeginUpdate();
		listBox1->Items->Add("Матрица с псевдослучайными значениями:");
		listBox1->Items->Add("");

		// Инициализация генератора
		srand((unsigned)time(&t));

		/*
		// Формируем массив чисел
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++) {
				arr[i][j] = rand() % 100;
			}
		}
		*/

		for (int i = 0; i < 10; i++)
		{
			String ^str = "";
			for (int j = 0; j < 10; j++) {
				str = str + arr[i][j] + "\t";
			}
			listBox1->Items->Add(str);
		}
		listBox1->Items->Add("");

		// Поиск минимального/максимального значения
		max = arr[0][0];
		min = arr[0][0];
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (arr[i][j] < min) {
					min = arr[i][j];
				}
				if (arr[i][j] > max) {
					max = arr[i][j];
				}
			}
		}
		listBox1->Items->Add(String::Format("Максимальный элемент матрицы : {0}", max));
		listBox1->Items->Add(String::Format("Минимальный элемент матрицы : {0}", min));

		// Сумма всех элементов матрицы
		for (int i = 0; i < 10; i++) {
			sum = sum + arr[i][i];
		}
		listBox1->Items->Add(String::Format("Сумма всех элементов матрицы : {0}", sum));

		// Сумма элементов на главной/побочной диагонали
		for (int i = 0; i < 10; i++) {
			// Сумма по основной диагонали
			main_sum = main_sum + arr[i][i];
			// Сумма по побочной диагонали
			side_sum = side_sum + arr[i][9 - i];
		}
		listBox1->Items->Add(String::Format("Сумма по главной диагонали : {0}", main_sum));
		listBox1->Items->Add(String::Format("Сумма по побочной диагонали : {0}", side_sum));

		listBox1->EndUpdate();
	}
	};
}
