#pragma once
#include <msclr\marshal_cppstd.h>

#include <iostream>
namespace GUIpng {

	using namespace System::Runtime::InteropServices;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PNGForm
	/// </summary>
	public ref class PNGForm : public System::Windows::Forms::Form
	{
	public:
		PNGForm(void)
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
		~PNGForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:

	protected:

	protected:

	private: System::Windows::Forms::Button^ quitButton;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ fileNameTextBox;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ selectImage;
	private: System::Windows::Forms::ToolStripMenuItem^ sToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ flipHorizontalToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ flipVerticalToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ removeGreenBlueToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ quitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PNGForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->quitButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->flipHorizontalToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->flipVerticalToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeGreenBlueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->fileNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->selectImage = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			resources->ApplyResources(this->pictureBox1, L"pictureBox1");
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->TabStop = false;
			// 
			// quitButton
			// 
			this->quitButton->BackColor = System::Drawing::SystemColors::InactiveCaption;
			resources->ApplyResources(this->quitButton, L"quitButton");
			this->quitButton->Name = L"quitButton";
			this->quitButton->UseVisualStyleBackColor = false;
			this->quitButton->Click += gcnew System::EventHandler(this, &PNGForm::onClickQuitButton);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			resources->ApplyResources(this->pictureBox2, L"pictureBox2");
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			resources->ApplyResources(this->pictureBox3, L"pictureBox3");
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			resources->ApplyResources(this->pictureBox4, L"pictureBox4");
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->helpToolStripMenuItem
			});
			resources->ApplyResources(this->menuStrip1, L"menuStrip1");
			this->menuStrip1->Name = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->sToolStripMenuItem,
					this->flipHorizontalToolStripMenuItem, this->flipVerticalToolStripMenuItem, this->removeGreenBlueToolStripMenuItem, this->quitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			resources->ApplyResources(this->fileToolStripMenuItem, L"fileToolStripMenuItem");
			// 
			// sToolStripMenuItem
			// 
			this->sToolStripMenuItem->Name = L"sToolStripMenuItem";
			resources->ApplyResources(this->sToolStripMenuItem, L"sToolStripMenuItem");
			this->sToolStripMenuItem->Click += gcnew System::EventHandler(this, &PNGForm::sToolStripMenuItem_Click);
			// 
			// flipHorizontalToolStripMenuItem
			// 
			this->flipHorizontalToolStripMenuItem->Name = L"flipHorizontalToolStripMenuItem";
			resources->ApplyResources(this->flipHorizontalToolStripMenuItem, L"flipHorizontalToolStripMenuItem");
			this->flipHorizontalToolStripMenuItem->Click += gcnew System::EventHandler(this, &PNGForm::flipHorizontalToolStripMenuItem_Click);
			// 
			// flipVerticalToolStripMenuItem
			// 
			this->flipVerticalToolStripMenuItem->Name = L"flipVerticalToolStripMenuItem";
			resources->ApplyResources(this->flipVerticalToolStripMenuItem, L"flipVerticalToolStripMenuItem");
			this->flipVerticalToolStripMenuItem->Click += gcnew System::EventHandler(this, &PNGForm::flipVerticalToolStripMenuItem_Click);
			// 
			// removeGreenBlueToolStripMenuItem
			// 
			this->removeGreenBlueToolStripMenuItem->Name = L"removeGreenBlueToolStripMenuItem";
			resources->ApplyResources(this->removeGreenBlueToolStripMenuItem, L"removeGreenBlueToolStripMenuItem");
			this->removeGreenBlueToolStripMenuItem->Click += gcnew System::EventHandler(this, &PNGForm::removeGreenBlueToolStripMenuItem_Click);
			// 
			// quitToolStripMenuItem
			// 
			this->quitToolStripMenuItem->Name = L"quitToolStripMenuItem";
			resources->ApplyResources(this->quitToolStripMenuItem, L"quitToolStripMenuItem");
			this->quitToolStripMenuItem->Click += gcnew System::EventHandler(this, &PNGForm::quitToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			resources->ApplyResources(this->helpToolStripMenuItem, L"helpToolStripMenuItem");
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			resources->ApplyResources(this->aboutToolStripMenuItem, L"aboutToolStripMenuItem");
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &PNGForm::aboutToolStripMenuItem_Click);
			// 
			// button2
			// 
			resources->ApplyResources(this->button2, L"button2");
			this->button2->Name = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &PNGForm::onClickHorizontal);
			// 
			// button3
			// 
			resources->ApplyResources(this->button3, L"button3");
			this->button3->Name = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &PNGForm::onClickVertical);
			// 
			// button4
			// 
			resources->ApplyResources(this->button4, L"button4");
			this->button4->Name = L"button4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &PNGForm::onClickRemoveGB);
			// 
			// fileNameTextBox
			// 
			resources->ApplyResources(this->fileNameTextBox, L"fileNameTextBox");
			this->fileNameTextBox->Name = L"fileNameTextBox";
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// selectImage
			// 
			resources->ApplyResources(this->selectImage, L"selectImage");
			this->selectImage->Name = L"selectImage";
			this->selectImage->UseVisualStyleBackColor = true;
			this->selectImage->Click += gcnew System::EventHandler(this, &PNGForm::onClickSelectImge);
			// 
			// PNGForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			resources->ApplyResources(this, L"$this");
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->Controls->Add(this->selectImage);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->fileNameTextBox);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->quitButton);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"PNGForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Show;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void onClickQuitButton(System::Object^ sender, System::EventArgs^ e) {
		//Close appliation
		Close();
	}
		   //function to select the image and dispay it in picturebox 1
private: System::Void onClickSelectImge(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ ofd;
	ofd = gcnew OpenFileDialog;

	ofd->Filter = "PNG Files(*.png) |*.png|""All Files(*.*)|*.*";

	ofd->FilterIndex = 1;

	ofd->Title = "Select the PNG image file";

	if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		this->fileNameTextBox->Clear();

		this->fileNameTextBox->Clear();
		this->fileNameTextBox->Text = ofd->FileName;

		pictureBox1->Load(ofd->FileName);
		pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;

		char* imageFile = (char*)(void*)Marshal::StringToHGlobalAnsi(fileNameTextBox->Text);
		
	}
}
	   //Function to flip the image horizontal
private: System::Void onClickHorizontal(System::Object^ sender, System::EventArgs^ e) {
		char* imageFile = (char*)(void*)Marshal::StringToHGlobalAnsi(fileNameTextBox->Text);
		pngwriter* original = new pngwriter();
		original->readfromfile(imageFile);

		int width = original->getwidth();
		int height = original->getheight();
		double gama = original->getgamma();


		pngwriter* flipped = new pngwriter(width, height, 1, "flipped_image.png");
		flipped->setgamma(gama);
		

		for (int y = 1; y <= height; ++y) {
			for (int x = 1; x <= width; ++x) {
				int red = original->read(x, y, 1);
				int green = original->read(x, y, 2);
				int blue = original->read(x, y, 3);
				flipped->plot(width - x + 1, y, red, green, blue);
			}
		}
		flipped->close();
		original->close();
		pictureBox2->Load("flipped_image.png");
		pictureBox2->SizeMode = PictureBoxSizeMode::StretchImage;
		Marshal::FreeHGlobal((System::IntPtr)imageFile);
	
}

	   //Function to flip the image vertical
private: System::Void onClickVertical(System::Object^ sender, System::EventArgs^ e) {
		char* imageFile = (char*)(void*)Marshal::StringToHGlobalAnsi(fileNameTextBox->Text);
		pngwriter* original = new pngwriter();

		original->readfromfile(imageFile);

		int width = original->getwidth();
		int height = original->getheight();
		double gama = original->getgamma();

		
		pngwriter* vflipped = new pngwriter(width, height, 1, "vflipped_image.png");
		vflipped->setgamma(gama);
		
		for (int y = 1; y <= height; ++y) {
			for (int x = 1; x <= width; ++x) {
				int red = original->read(x, y, 1);
				int green = original->read(x, y, 2);
				int blue = original->read(x, y, 3);



				vflipped->plot( x , height - y + 1, red, green, blue);
			}
		}
		//close  file
		vflipped->close();
		original->close();
		
		pictureBox3->Load("vflipped_image.png");
		pictureBox3->SizeMode = PictureBoxSizeMode::StretchImage;

		Marshal::FreeHGlobal((System::IntPtr)imageFile);
	

}
	   //fuction to remove green and blue from the image
private: System::Void onClickRemoveGB(System::Object^ sender, System::EventArgs^ e) {
	
		char* imageFile = (char*)(void*)Marshal::StringToHGlobalAnsi(fileNameTextBox->Text);
		pngwriter* original = new pngwriter();
		original->readfromfile(imageFile);

		int width = original->getwidth();
		int height = original->getheight();
		double gamma = original->getgamma();

		
		pngwriter* removeGB = new pngwriter(width, height, 1, "removeGB.png");
		removeGB->setgamma(gamma);

		for (int y = 1; y <= height; ++y) {
			for (int x = 1; x <= width; ++x) {
				int red = original->read(x, y, 1);
				int green = original->read(x, y, 2);
				int blue = original->read(x, y, 3);

				if (red > green && red > blue) {
					removeGB->plot(x, y, red, 0, 0);
				}
				else {
					removeGB->plot(x, y,  32767,32767,32767 );
				}
			}
		}
		removeGB->close();
		original->close();
		pictureBox4->Load("removeGB.png");
		pictureBox4->SizeMode = PictureBoxSizeMode::StretchImage;
		Marshal::FreeHGlobal((System::IntPtr)imageFile);
	
}

	   //fuctions to handle the sub menu for file
private: System::Void removeGreenBlueToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	this->onClickRemoveGB(sender, e);
}
private: System::Void flipVerticalToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	this->onClickVertical(sender, e);

}
private: System::Void flipHorizontalToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	this->onClickHorizontal(sender, e);
}
private: System::Void sToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	this->onClickSelectImge(sender, e);
}
private: System::Void quitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	
	this->onClickQuitButton(sender, e);
}
private: System::Void toolStripTextBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::MessageBox::Show(
		"Student Name: Kyle Cox \n ID Number: 400009491 \n Version: 2.0",
		"About",
		System::Windows::Forms::MessageBoxButtons::OK,
		System::Windows::Forms::MessageBoxIcon::Information
	);
}
};
}
