#pragma once
#include "Beeper.h"
#include "Robot.h"
#include "readFile.cpp"
#include "Wall.h"
#include "Item.h"
void readFromFile(array<System::Int32, 2>^ twoDArray, int& number_read);
void findInfo(std::string my_string, std::string& keyword, int& X, int& Y, int& Z, int& A);

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
		bool North;
		bool South;
		bool East;
		bool West;

		int robot_x = 20;
	private: System::Windows::Forms::PictureBox^  robot_pic;
	public:
		int robot_y = 20;

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
	private: System::Windows::Forms::Button^  button1;
	protected:

	private:

		array <Beeper^>^ beeper; 
		Graphics^ g;
		Pen^ blackPen;
	private: System::Windows::Forms::Button^  U_but;
	private: System::Windows::Forms::Button^  D_but;
	private: System::Windows::Forms::Button^  L_but;
	private: System::Windows::Forms::Button^  R_but;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: Bitmap^ bmp;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label_10;
	private: System::Windows::Forms::Label^  Status_Label;

		//static const int 



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
			this->U_but = (gcnew System::Windows::Forms::Button());
			this->D_but = (gcnew System::Windows::Forms::Button());
			this->L_but = (gcnew System::Windows::Forms::Button());
			this->R_but = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label_10 = (gcnew System::Windows::Forms::Label());
			this->Status_Label = (gcnew System::Windows::Forms::Label());
			this->robot_pic = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->robot_pic))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(13, 34);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(224, 195);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(513, 265);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// U_but
			// 
			this->U_but->Location = System::Drawing::Point(501, 395);
			this->U_but->Name = L"U_but";
			this->U_but->Size = System::Drawing::Size(87, 28);
			this->U_but->TabIndex = 2;
			this->U_but->Text = L"UP";
			this->U_but->UseVisualStyleBackColor = true;
			this->U_but->Click += gcnew System::EventHandler(this, &MyForm::U_but_Click);
			// 
			// D_but
			// 
			this->D_but->Location = System::Drawing::Point(501, 480);
			this->D_but->Name = L"D_but";
			this->D_but->Size = System::Drawing::Size(87, 28);
			this->D_but->TabIndex = 3;
			this->D_but->Text = L"DOWN";
			this->D_but->UseVisualStyleBackColor = true;
			this->D_but->Click += gcnew System::EventHandler(this, &MyForm::D_but_Click);
			// 
			// L_but
			// 
			this->L_but->Location = System::Drawing::Point(402, 435);
			this->L_but->Name = L"L_but";
			this->L_but->Size = System::Drawing::Size(87, 28);
			this->L_but->TabIndex = 4;
			this->L_but->Text = L"LEFT";
			this->L_but->UseVisualStyleBackColor = true;
			this->L_but->Click += gcnew System::EventHandler(this, &MyForm::L_but_Click);
			// 
			// R_but
			// 
			this->R_but->Location = System::Drawing::Point(598, 435);
			this->R_but->Name = L"R_but";
			this->R_but->Size = System::Drawing::Size(87, 28);
			this->R_but->TabIndex = 5;
			this->R_but->Text = L"RIGHT";
			this->R_but->UseVisualStyleBackColor = true;
			this->R_but->Click += gcnew System::EventHandler(this, &MyForm::R_but_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(508, 443);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"MOVEMENT";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(582, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Beeper Bag";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(511, 51);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(77, 76);
			this->pictureBox2->TabIndex = 8;
			this->pictureBox2->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(610, 81);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Number";
			// 
			// label_10
			// 
			this->label_10->AutoSize = true;
			this->label_10->Location = System::Drawing::Point(525, 330);
			this->label_10->Name = L"label_10";
			this->label_10->Size = System::Drawing::Size(37, 13);
			this->label_10->TabIndex = 10;
			this->label_10->Text = L"Status";
			// 
			// Status_Label
			// 
			this->Status_Label->AutoSize = true;
			this->Status_Label->Location = System::Drawing::Point(503, 363);
			this->Status_Label->Name = L"Status_Label";
			this->Status_Label->Size = System::Drawing::Size(85, 13);
			this->Status_Label->TabIndex = 11;
			this->Status_Label->Text = L"Text_Goes Here";
			// 
			// robot_pic
			// 
			this->robot_pic->Location = System::Drawing::Point(232, 288);
			this->robot_pic->Name = L"robot_pic";
			this->robot_pic->Size = System::Drawing::Size(32, 32);
			this->robot_pic->TabIndex = 12;
			this->robot_pic->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(722, 584);
			this->Controls->Add(this->robot_pic);
			this->Controls->Add(this->Status_Label);
			this->Controls->Add(this->label_10);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->R_but);
			this->Controls->Add(this->L_but);
			this->Controls->Add(this->D_but);
			this->Controls->Add(this->U_but);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->robot_pic))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		using namespace System;
		g = pictureBox1->CreateGraphics();
		blackPen = gcnew System::Drawing::Pen(Color::Black);
		g = robot_pic->CreateGraphics();
		bmp = gcnew Bitmap(L"Carol_back.bmp");
		beeper = gcnew array<Beeper^>(2);
		
		//Start Reading from file
		array<Int32, 2>^  twoDArray = gcnew array<Int32, 2>(10, 10);
		int number;
		readFromFile(twoDArray, number);

		
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void U_but_Click(System::Object^  sender, System::EventArgs^  e) {
		North = true;
		West = false;
		East = false;
		South = false;

		bmp = gcnew Bitmap(L"Carol_back.bmp");

		robot_y = robot_y - 5;
		robot_pic->Location = Point(robot_x, robot_y);
		Refresh();
	}
private: System::Void L_but_Click(System::Object^  sender, System::EventArgs^  e) {
	North = false;
	West = true;
	East = false;
	South = false;

	bmp = gcnew Bitmap(L"Carol_left.bmp");

	robot_x = robot_x - 5;
	robot_pic->Location = Point(robot_x, robot_y);
	Refresh();
}
private: System::Void R_but_Click(System::Object^  sender, System::EventArgs^  e) {
	North = false;
	West = false;
	East = true;
	South = false;

	bmp = gcnew Bitmap(L"Carol_right.bmp");

	robot_x = robot_x + 5;
	robot_pic->Location = Point(robot_x, robot_y);
	Refresh();
}
private: System::Void D_but_Click(System::Object^  sender, System::EventArgs^  e) {
	North = false;
	West = false;
	East = false;
	South = true;

	bmp = gcnew Bitmap(L"Carol_for.bmp");

	robot_y = robot_y + 5;
	robot_pic->Location = Point(robot_x, robot_y);
	Refresh();
}
private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	g->DrawImage(bmp, 20, 20, 32, 32);
}
};
}
