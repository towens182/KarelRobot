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
		const int offset = 30;
		int robot_x = 20;
		int beeper_counter = 0;
		int wall_counter = 0;
		int num_walls = 4; //Need to change if adding new walls to specifics.txt
	public:
		int robot_y = 20;
		int x1, y1 = 0;
		
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
		Brush^ whiteBrush;
		array<Int32, 2>^  twoDArray;
		array <System::String^>^ keywordArray;
		Robot^ myRobot;
		array <Cell^, 2>^ drawWorld;
	private: System::Windows::Forms::Button^  U_but;
	private: System::Windows::Forms::Button^  D_but;
	private: System::Windows::Forms::Button^  L_but;
	private: System::Windows::Forms::Button^  R_but;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: Bitmap^ bmp;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->U_but = (gcnew System::Windows::Forms::Button());
			this->D_but = (gcnew System::Windows::Forms::Button());
			this->L_but = (gcnew System::Windows::Forms::Button());
			this->R_but = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label_10 = (gcnew System::Windows::Forms::Label());
			this->Status_Label = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(27, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(245, 242);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(272, 336);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// U_but
			// 
			this->U_but->Enabled = false;
			this->U_but->Location = System::Drawing::Point(394, 335);
			this->U_but->Name = L"U_but";
			this->U_but->Size = System::Drawing::Size(84, 23);
			this->U_but->TabIndex = 2;
			this->U_but->Text = L"UP";
			this->U_but->UseVisualStyleBackColor = true;
			this->U_but->Click += gcnew System::EventHandler(this, &MyForm::U_but_Click);
			// 
			// D_but
			// 
			this->D_but->Enabled = false;
			this->D_but->Location = System::Drawing::Point(394, 406);
			this->D_but->Name = L"D_but";
			this->D_but->Size = System::Drawing::Size(84, 23);
			this->D_but->TabIndex = 3;
			this->D_but->Text = L"DOWN";
			this->D_but->UseVisualStyleBackColor = true;
			this->D_but->Click += gcnew System::EventHandler(this, &MyForm::D_but_Click);
			// 
			// L_but
			// 
			this->L_but->Enabled = false;
			this->L_but->Location = System::Drawing::Point(302, 369);
			this->L_but->Name = L"L_but";
			this->L_but->Size = System::Drawing::Size(84, 23);
			this->L_but->TabIndex = 4;
			this->L_but->Text = L"LEFT";
			this->L_but->UseVisualStyleBackColor = true;
			this->L_but->Click += gcnew System::EventHandler(this, &MyForm::L_but_Click);
			// 
			// R_but
			// 
			this->R_but->Enabled = false;
			this->R_but->Location = System::Drawing::Point(480, 369);
			this->R_but->Name = L"R_but";
			this->R_but->Size = System::Drawing::Size(84, 23);
			this->R_but->TabIndex = 5;
			this->R_but->Text = L"RIGHT";
			this->R_but->UseVisualStyleBackColor = true;
			this->R_but->Click += gcnew System::EventHandler(this, &MyForm::R_but_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(398, 372);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"MOVEMENT";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(401, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 20);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Beeper Bag";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(444, 50);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(17, 18);
			this->label3->TabIndex = 9;
			this->label3->Text = L"0";
			// 
			// label_10
			// 
			this->label_10->AutoSize = true;
			this->label_10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_10->Location = System::Drawing::Point(421, 159);
			this->label_10->Name = L"label_10";
			this->label_10->Size = System::Drawing::Size(56, 18);
			this->label_10->TabIndex = 10;
			this->label_10->Text = L"Status";
			this->label_10->Click += gcnew System::EventHandler(this, &MyForm::label_10_Click);
			// 
			// Status_Label
			// 
			this->Status_Label->AutoSize = true;
			this->Status_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Status_Label->Location = System::Drawing::Point(399, 192);
			this->Status_Label->Name = L"Status_Label";
			this->Status_Label->Size = System::Drawing::Size(0, 18);
			this->Status_Label->TabIndex = 11;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(567, 434);
			this->Controls->Add(this->Status_Label);
			this->Controls->Add(this->label_10);
			this->Controls->Add(this->label3);
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
		whiteBrush = gcnew System::Drawing::SolidBrush(Color::White);
		bmp = gcnew Bitmap(L"Carol_back.bmp");
		
		
		//Create beepers
		beepers = gcnew array<Beeper^>(3);
		for (int i = 0; i < 3; i++)
		{
			beepers[i] = gcnew Beeper();
		}

		//Create walls
		walls = gcnew array<Wall^>(num_walls);
		for (int i = 0; i < num_walls; i++)
		{
			walls[i] = gcnew Wall();
		}
		
		
	}
	//Up button click
	private: System::Void U_but_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//For checking access
		int x, y = 0;

		x = myRobot->getX();
		y = myRobot->getY();

		myRobot->direction = 2;
		if(!edge() && drawWorld[x,(y - 1)]->getAccess())
		{
			draw_old();
			myRobot->goUp();
			draw_robot();
			checkbeeper();
		}
		Status_Label->Text = "Facing North";
	}
//Left button click
private: System::Void L_but_Click(System::Object^  sender, System::EventArgs^  e)
{
	//For checking access
	int x, y = 0;

	x = myRobot->getX();
	y = myRobot->getY();

	myRobot->direction = 1;
	if(!edge() && drawWorld[(x - 1), y]->getAccess())
	{
		draw_old();
		myRobot->goLeft();
		draw_robot();
		checkbeeper();
	}
	Status_Label->Text = "Facing West";
}
//Right button click
	private: System::Void R_but_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//For checking access
		int x, y = 0;

		x = myRobot->getX();
		y = myRobot->getY();

		myRobot->direction = 0;
		if (!edge() && drawWorld[(x + 1), y]->getAccess())
	{
		draw_old();
		myRobot->goRight();
		draw_robot();
		checkbeeper();
	}
	Status_Label->Text = "Facing East";
}
//Down button click
private: System::Void D_but_Click(System::Object^  sender, System::EventArgs^  e) 
{
	//For checking access
	int x, y = 0;

	x = myRobot->getX();
	y = myRobot->getY();

	myRobot->direction = 3;
	if(!edge() && drawWorld[x, (y + 1)]->getAccess())
	{
		draw_old();
		myRobot->goDown();
		draw_robot();
		checkbeeper();
	}
	Status_Label->Text = "Facing South";

}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	//Enable buttons to change direction
	U_but->Enabled = true;
	D_but->Enabled = true;
	R_but->Enabled = true;
	L_but->Enabled = true;
	

	//Start Reading from file
	twoDArray = gcnew array<Int32, 2>(10, 10);
	keywordArray = gcnew array<System::String^>(10);
	myRobot = gcnew Robot();
	label3->Text = "0";
	int number;
	int x, y;
	readFromFile(keywordArray, twoDArray, number);
	draw_World();

	for (int i = 0; i < 10; i++)
	{
		if (keywordArray[i] == "World")
		{
		//	Cell^ cell = gcnew Cell(twoDArray[i, 0], twoDArray[i, 1], true);

		}
		else if (keywordArray[i] == "Robot")
		{
			
			myRobot->setX((twoDArray[i, 0]));
			myRobot->setY((twoDArray[i, 1]));
			myRobot->setDirection(twoDArray[i, 2]);
			myRobot->setBeeps(twoDArray[i, 3]);
		
		}
		else if (keywordArray[i] == "Wall")
		{
			walls[wall_counter]->setX((twoDArray[i, 0]));
			walls[wall_counter]->setY((twoDArray[i, 1]));
			drawWorld[twoDArray[i, 0], twoDArray[i, 1]]->setAccess(false);
			wall_counter++;

		}
		else if (keywordArray[i] == "Beeper")
		{
			
			beepers[beeper_counter]->setX((twoDArray[i, 0]));
			beepers[beeper_counter]->setY((twoDArray[i, 1]));
			beepers[beeper_counter]->setNumBeepers(twoDArray[i, 2]);
			drawWorld[twoDArray[i, 0], twoDArray[i, 1]]->setBeeper(true);
			beeper_counter++;

		}
	}
	//Draws Beeper icon
	for (int z = 0; z < beeper_counter; z++)
	{
		x = beepers[z]->getX() * offset;
		y = beepers[z]->getY() * offset;

		Rectangle beeperRect = Rectangle(x, y, offset, offset);
		g->DrawIcon(beepers[z]->getIcon(), beeperRect);
	}
	//Draws wall icon
	for (int z = 0; z < wall_counter; z++)
	{
		x = walls[z]->getX() * offset;
		y = walls[z]->getY() * offset;
		Rectangle wallRect = Rectangle(x, y, offset, offset);
		g->DrawIcon(walls[z]->getIcon(), wallRect);
	}

	//Initial Robot drawing
	x = myRobot->getX() * offset;
	y = myRobot->getY() * offset;
	Rectangle robotRect = Rectangle(x, y, offset, offset);
	g->DrawIcon(myRobot->getIcon(), robotRect);
	

	g = pictureBox1->CreateGraphics();
	
	//Disable start button or else error when clicked
	button1->Enabled = false;
}
private: void draw_World()
{
	int row, col;
	int x, y;

	drawWorld = gcnew array<Cell^, 2>(8, 8);
	for (row = 0; row < 8; row++)
	{
		for (col = 0; col < 8; col++)
		{
			drawWorld[row, col] = gcnew Cell(row, col, true);
		}
	}

	int CELLSIZE = 30;
	for (row = 0; row < 8; row++)
	{
		for (col = 0; col < 8; col++)
		{
			x = col * CELLSIZE;
			y = row * CELLSIZE;
			Rectangle gridRect = Rectangle(x, y, CELLSIZE - 1, CELLSIZE - 1);
			g->FillRectangle(whiteBrush, gridRect);
			g->DrawRectangle(blackPen, gridRect);
		};
	};
}

private: System::Void draw_old()
{

	//Declare local variables;
	int x, y = 0;

	//Initializing local variables;
	x = myRobot->getX() * offset;
	y = myRobot->getY() * offset;

	//Cover robots last position
	Rectangle oldRect = Rectangle(x, y, offset - 1, offset - 1);
	g->FillRectangle(whiteBrush, oldRect);
	g->DrawRectangle(blackPen, oldRect);

}
private: System::Void draw_robot()
{
	int x, y = 0;
	int row, col = 0;

	//Draw robot at new location
	col = myRobot->getX();
	row = myRobot->getY();
	x = col * offset;
	y = row * offset;
	Rectangle robotRect = Rectangle(x, y, offset, offset);
	g->DrawIcon(myRobot->getIcon(), robotRect);


}
	//see if there is a beeper in the cell
	private: System::Void checkbeeper()
	{
		int x, y = 0;
		x = myRobot->getX();
		y = myRobot->getY();
		if (drawWorld[x, y]->getBeeper())
		{
			drawWorld[x, y]->setBeeper(false);
			myRobot->numbeepers++;
			if (myRobot->numbeepers == beeper_counter)
			{
				label3->Text = myRobot->numbeepers.ToString();
				MessageBox::Show("You found all the beepers!", "Congratulations!");
				exit(1);
			}
			else 
			{
				label3->Text = myRobot->numbeepers.ToString();				
			}
		}
	 }
public: bool edge()
	 {
				 if (myRobot->direction == 0) {
					 if (myRobot->getX() < 7) return false;
				 }
				 else if (myRobot->direction == 1) {
					 if (myRobot->getX() > 0) return false;
				 }
				 else if (myRobot->direction == 2) {
					 if (myRobot->getY() > 0) return false;
				 }
				 else if (myRobot->direction == 3) {
					 if (myRobot->getY() < 7) return false;
				 }
				 return true;

	}
private: System::Void robot_pic_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label_10_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
