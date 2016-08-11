#pragma once

#include "Walls.h"

namespace KarelRobot {

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
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:

	private:

		array <Cell^, 2>^ maze;
		static const int NUMROWS = 8;
		static const int NUMCOLS = 8;
		static const int CELLSIZE = 32;
	private: System::Windows::Forms::Button^  button1;
			 Graphics ^g;
			 Brush ^ blackBrush;
	private: Pen^ pen;
	private: Bitmap^ bmp;

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(13, 34);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(184, 158);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(261, 236);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(11, 14);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		g = pictureBox1->CreateGraphics();
		int row, col;

		//Construct maze array
		maze = gcnew array<Cell^, 2>(NUMROWS, NUMCOLS);
		for (row = 0; row < NUMROWS; row++)
		{
			for (col = 0; col < NUMCOLS; col++)
			{
				maze[row, col] = gcnew Cell(row, col, true);
			}
		}

		blackBrush = gcnew System::Drawing::SolidBrush(Color::Gray);
	}



	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		int offset = 32;
		for (int i = 1; i < 9; i++)
		{
			g->DrawLine(pen, 0, i*offset, 32, i*offset);
			g->DrawLine(pen, i*offset, 0, i*offset, 32);
		}
	}
	};
}
