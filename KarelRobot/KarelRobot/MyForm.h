#pragma once
#include "Beeper.h"
#include "Cell.h"
#include "Robot.h"
#include "Wall.h"
#include "Item.h"
#include <string>

void readFromFile(array <System::String^>^ keywordArray, array<System::Int32, 2>^ twoDArray, int& number_read);
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
		static const int offset = 30;
		int direction; // North = 1/ East = 2/ South = 3/ West = 4

		int robot_x = 20;
		int beeper_counter = 0;
	public:
		int robot_y = 20;
		int x1, y1 = 0;
		
		//front_is_clear, front_is_blocked, left_is_clear, left_is_blocked, right_is_clear, 
		//right_is_blocked, next_to_a_beeper, facing_north, not_facing_north, facing_south, 
		//not_facing_south, facing_east, not_facing_east, facing_west, not_facing_west, 
		//any_beepers_in_beeper_bag, no_beepers_in_beeper_bag

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

		array <Beeper^>^ beepers; 
		array <Wall^>^ walls;
		Graphics^ g;
		Pen^ blackPen;
		array<Int32, 2>^  twoDArray;
		array <System::String^>^ keywordArray;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(290, 267);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(362, 167);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// U_but
			// 
			this->U_but->Location = System::Drawing::Point(350, 297);
			this->U_but->Name = L"U_but";
			this->U_but->Size = System::Drawing::Size(87, 28);
			this->U_but->TabIndex = 2;
			this->U_but->Text = L"UP";
			this->U_but->UseVisualStyleBackColor = true;
			this->U_but->Click += gcnew System::EventHandler(this, &MyForm::U_but_Click);
			// 
			// D_but
			// 
			this->D_but->Location = System::Drawing::Point(350, 382);
			this->D_but->Name = L"D_but";
			this->D_but->Size = System::Drawing::Size(87, 28);
			this->D_but->TabIndex = 3;
			this->D_but->Text = L"DOWN";
			this->D_but->UseVisualStyleBackColor = true;
			this->D_but->Click += gcnew System::EventHandler(this, &MyForm::D_but_Click);
			// 
			// L_but
			// 
			this->L_but->Location = System::Drawing::Point(251, 337);
			this->L_but->Name = L"L_but";
			this->L_but->Size = System::Drawing::Size(87, 28);
			this->L_but->TabIndex = 4;
			this->L_but->Text = L"LEFT";
			this->L_but->UseVisualStyleBackColor = true;
			this->L_but->Click += gcnew System::EventHandler(this, &MyForm::L_but_Click);
			// 
			// R_but
			// 
			this->R_but->Location = System::Drawing::Point(447, 337);
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
			this->label1->Location = System::Drawing::Point(357, 345);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"MOVEMENT";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(416, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Beeper Bag";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(345, 50);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(77, 76);
			this->pictureBox2->TabIndex = 8;
			this->pictureBox2->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(444, 80);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Number";
			// 
			// label_10
			// 
			this->label_10->AutoSize = true;
			this->label_10->Location = System::Drawing::Point(374, 232);
			this->label_10->Name = L"label_10";
			this->label_10->Size = System::Drawing::Size(37, 13);
			this->label_10->TabIndex = 10;
			this->label_10->Text = L"Status";
			// 
			// Status_Label
			// 
			this->Status_Label->AutoSize = true;
			this->Status_Label->Location = System::Drawing::Point(352, 265);
			this->Status_Label->Name = L"Status_Label";
			this->Status_Label->Size = System::Drawing::Size(85, 13);
			this->Status_Label->TabIndex = 11;
			this->Status_Label->Text = L"Text_Goes Here";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(567, 434);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		//...
		using namespace System;
		g = pictureBox1->CreateGraphics();
		blackPen = gcnew System::Drawing::Pen(Color::Black);
		bmp = gcnew Bitmap(L"Carol_back.bmp");
		
		beepers = gcnew array<Beeper^>(2);
		
		for (int i = 0; i < 2; i++)
		{
			beepers[i] = gcnew Beeper();
		}

		
		
	}
	private: System::Void U_but_Click(System::Object^  sender, System::EventArgs^  e) {
		direction = 1; // North = 1/ East = 2/ South = 3/ West = 4
		g = pictureBox1->CreateGraphics();
		bmp = gcnew Bitmap(L"Carol_back.bmp");
		Status_Label->Text = "Facing North";
		robot_y = robot_y - 16;
		g->DrawImage(bmp, robot_x, robot_y, offset, offset);
	}
private: System::Void L_but_Click(System::Object^  sender, System::EventArgs^  e) {
	direction = 4; // North = 1/ East = 2/ South = 3/ West = 4
	g = pictureBox1->CreateGraphics();
	bmp = gcnew Bitmap(L"Carol_left.bmp");
	Status_Label->Text = "Facing West";
	robot_x = robot_x - 16;
	g->DrawImage(bmp, robot_x, robot_y, offset, offset);
}
private: System::Void R_but_Click(System::Object^  sender, System::EventArgs^  e) {
	direction = 2; // North = 1/ East = 2/ South = 3/ West = 4
	g = pictureBox1->CreateGraphics();
	bmp = gcnew Bitmap(L"Carol_right.bmp");
	Status_Label->Text = "Facing East";
	robot_x = robot_x + 16;
	g->DrawImage(bmp, robot_x, robot_y, offset, offset);
}
private: System::Void D_but_Click(System::Object^  sender, System::EventArgs^  e) {
	direction = 3; // North = 1/ East = 2/ South = 3/ West = 4
	g = pictureBox1->CreateGraphics();
	bmp = gcnew Bitmap(L"Carol_for.bmp");
	Status_Label->Text = "Facing South";
	robot_y = robot_y + 16;
	g->DrawImage(bmp, robot_x, robot_y, offset, offset);
}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	
	

	//Start Reading from file
	twoDArray = gcnew array<Int32, 2>(10, 10);
	keywordArray = gcnew array<System::String^>(10);
	int number;
	readFromFile(keywordArray, twoDArray, number);
	//beeper array[3];
	


	for (int i = 0; i < 5; i++)
	{
		if (keywordArray[i] == "World")
		{
			Cell^ cell = gcnew Cell(twoDArray[i, 0], twoDArray[i, 1], true);

		}
		/*else if (keywordArray[i] == "Robot")
		Robot^ robot = gcnew Robot(twoDArray[i, 0], twoDArray[i, 1], twoDArray[i, 4]);
		*/
		else if (keywordArray[i] == "Wall")
		{
			//			Wall^ wall = gcnew Wall(twoDArray[i, 0], twoDArray[i, 1]);
		}
		else if (keywordArray[i] == "Beeper")
		{
			
			beepers[beeper_counter]->setX((offset * twoDArray[i, 0]));
			beepers[beeper_counter]->setY((offset * twoDArray[i, 1]));
			beepers[beeper_counter]->setNumBeepers(twoDArray[i, 2]);
			beeper_counter++;

		}
	}
	for (int z = 0; z < beeper_counter; z++)
	{
		Rectangle beeperRect = Rectangle(beepers[z]->getX(), beepers[z]->getX(), offset, offset);
		g->DrawIcon(beepers[z]->getIcon(), beeperRect);
	}

	int i;
	g = pictureBox1->CreateGraphics();
	bmp = gcnew Bitmap(L"road.bmp");


	for (i = 0; i < 9; i++)
	{
		g->DrawLine(blackPen, 30, i*offset, 270, i*offset);
		g->DrawLine(blackPen, 30 + i*offset, 0, 30 + i*offset, 8 * offset);
	}
	/*
	//road down left
	g->DrawImage(bmp, 60, 30, offset, offset);
	g->DrawImage(bmp, 60, 60, offset, offset);
	g->DrawImage(bmp, 60, 90, offset, offset);
	g->DrawImage(bmp, 60, 120, offset, offset);
	g->DrawImage(bmp, 60, 150, offset, offset);
	g->DrawImage(bmp, 60, 180, offset, offset);
	//road across
	g->DrawImage(bmp, 90, 180, offset, offset);
	g->DrawImage(bmp, 120, 180, offset, offset);
	g->DrawImage(bmp, 150, 180, offset, offset);
	g->DrawImage(bmp, 180, 180, offset, offset);
	g->DrawImage(bmp, 210, 180, offset, offset);
	//road up right
	g->DrawImage(bmp, 210, 30, offset, offset);
	g->DrawImage(bmp, 210, 60, offset, offset);
	g->DrawImage(bmp, 210, 90, offset, offset);
	g->DrawImage(bmp, 210, 120, offset, offset);
	g->DrawImage(bmp, 210, 150, offset, offset);

	*/
}
private: void drawWorld(int& NUMROWS, int& NUMCOLS)
{
	int row, col;
	int x, y;

	//drawWorld = gcnew array<Cell^, 2>(NUMROWS, NUMCOLS);
	array <Int32, 2>^ drawWorld = gcnew array<Int32, 2>(NUMROWS, NUMCOLS);
	for (row = 0; row < NUMROWS; row++)
	{
		for (col = 0; col < NUMCOLS; col++)
		{
			//drawWorld[row, col] = gcnew Cell(row, col, true);
		}
	}

	int CELLSIZE = 30;
	for (row = 0; row < NUMROWS; row++)
	{
		for (col = 0; col < NUMCOLS; col++)
		{
			x = col * CELLSIZE;
			y = row * CELLSIZE;
			Rectangle gridRect = Rectangle(x, y, CELLSIZE - 1, CELLSIZE - 1);
			g->DrawRectangle(blackPen, gridRect);
		};
	};
}
private: System::Void robot_pic_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
