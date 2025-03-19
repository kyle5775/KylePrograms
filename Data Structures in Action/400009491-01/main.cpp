
////////////////////////////////////////////////////////////////////////////
//																		  //
//  Skeleton03.cpp														  //
//  Skeleton code for Project #1 for Semester II, 2023/24.				  //
//																		  //
//	PURPOSE:															  //
//	Program reads data from a text file and processing is done with the   //
//	Linear ADTs.  														  //
//																		  //
//  Created by Dr. John Charlery on 02/12/2024.							  //
//  Copyright (c) 2024 University of the West Indies. All rights reserved.//
//																		  //
////////////////////////////////////////////////////////////////////////////

//============================VERY IMPORTANT================================
//		You can use this code as a start-up, BUT, you are required to
//			modify the documentation and code accordingly. You should have
//			your own class names, your own functions' names, etc. You are
//			also required to have documentation within your code.
//
//		DO NOT SIMPLY SUBMIT THE CODE WHICH HAS BEEN GIVEN!
//==========================================================================

/*
 * Name     : main.cpp
 * Program   : Project 1
 * Author   : Kyle Cox
 * Date     : 25 February, 2024
 */

/************************************************************************************
  Step 1: Always include the header file wx.h
*************************************************************************************/
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#  include <wx/wx.h>
#endif

#include <iostream>
#include <fstream>
#include <string>


using namespace std;


struct record
    {
        long int idNo;
        string 	 name;
        string 	 surname;
        string 	 major;
        float  	 gpa;
    };
typedef struct record Record;



// Other miscellaneous functions' protypes
string makeRecord(long int, string, string, string, float);
string makeRecord(Record);



// the ADTs header files
#include "Queue.h"
#include "PriorityQueue.h"
#include "Deque.h"
#include "Stack.h"




//Global pointers for the ADT containers
Queue* queue = new Queue();
Deque* deque = new Deque();
PriorityQueue* priorityQueue = new PriorityQueue();
Stack* stack = new Stack();







/************************************************************************************
*************************************************************************************
  Step 2: Name an inherited application class from wxApp and declare it with
	  the function to execute the program
*************************************************************************************
*************************************************************************************/
class ProjectApp: public wxApp
  {
	 virtual bool OnInit();
  };





/************************************************************************************
*************************************************************************************
   Step 3: Declare the inherited main frame class from wxFrame. In this class
	   also will ALL the events handlers be declared
*************************************************************************************
*************************************************************************************/
class ProjectFrame: public wxFrame
  {
	 private:
		DECLARE_EVENT_TABLE() //To declare events items

	 public:
		ProjectFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

		//Functions for File Menu Items
		void OnOpenFile(wxCommandEvent& event);	//handle for Open File function
		void OnSave(wxCommandEvent& event);		//handle for Save  function
		void OnSaveAs(wxCommandEvent& event);	//handle for Save as function
		void OnExit(wxCommandEvent& event); 	//handle for Quit function

		void OnDisplay(wxCommandEvent& event);	//handle for Display function
		//Function for Help Menu Item
		void OnAbout(wxCommandEvent& event);	//handle for About function


		//Functions for the  Queue Menu Items
		void OnCreateQueue(wxCommandEvent& event);		//handle for Create queue File function
		void OnShowAllQueue(wxCommandEvent& event);		//handle for Show all queue File function
		void OnShowHeadQueue(wxCommandEvent& event);	//handle for show head queue File function
		void OnShowTailQueue(wxCommandEvent& event);	//handle for show tail queue File function
		void OnDequeueQueue(wxCommandEvent& event);		//handle for Dequeue queue File function

		//Functions for Deque Menu Items
		void OnCreateDeque(wxCommandEvent& event);		//handle for Create Deque File function
		void OnShowAllDeque(wxCommandEvent& event);		//handle for Show all Deque File function
		void OnShowHeadDeque(wxCommandEvent& event);	//handle for Show head Deque File function
		void OnShowTailDeque(wxCommandEvent& event);	//handle for Show tail Deque File function
		void OnDequeueHeadDeque(wxCommandEvent& event);	//handle for Dequeue head Deque File function
		void OnDequeueTailDeque(wxCommandEvent& event);	//handle for Dequeue tail Deque File function

		//Functions for Priority Queue Menu Items
		void OnCreatePQ(wxCommandEvent& event);		//handle for Create Priority Queue File function
		void OnShowAllPQ(wxCommandEvent& event);	//handle for Show all Priority Queue File function
		void OnShowTailPQ(wxCommandEvent& event);	//handle for Show tail Priority Queue File function
		void OnShowHeadPQ(wxCommandEvent& event);	//handle for Show Head Priority Queue File function
		void OnDequeuePQ(wxCommandEvent& event);	//handle for Show all Priority Queue File function

		//Functions for Stack Menu Items
	    void OnCreateStack(wxCommandEvent& event);		//handle for Create Stack File function
		void OnPopStack(wxCommandEvent& event);			//handle for Pop Stack File function
		void OnShowAllStack(wxCommandEvent& event);		//handle for SHow All Stack File function


		//Public attributes for the Client Area features
		wxTextCtrl* MainEditBox;
		wxTextCtrl* filenameTextBox;
		wxString CurrentDocPath;	// To store the Path to the file which has been opened

  };



/************************************************************************************
*************************************************************************************
  Step 4. Declare the compiler directives
*************************************************************************************
*************************************************************************************/
DECLARE_APP(ProjectApp)		// Declare Application class
IMPLEMENT_APP(ProjectApp)		// Create Application class object


enum
    {
      	// File menu items
		ID_OpenFile	= wxID_HIGHEST + 1,		//File menu item
		ID_Display,
		ID_Save,
		ID_SaveAs,
		ID_Exit,

		// Help menu items
		ID_About,


		// Queue menu items
		ID_CreateQueue,
		ID_ShowAllQueue,
		ID_ShowHeadQueue,
		ID_ShowTailQueue,
		ID_DequeueQueue,


		// Deque sub-menu items
		ID_CreateDeque,
		ID_ShowAllDeque,
		ID_ShowHeadDeque,
		ID_ShowTailDeque,
		ID_DequeueHeadDeque,
		ID_DequeueTailDeque,


		// Priority Queue sub-menu items
		ID_CreatePQ,
		ID_ShowAllPQ,
		ID_ShowHeadPQ,
		ID_ShowTailPQ,
		ID_DequeuePQ,

		// Stack sub-menu items

		ID_CreateStack,
		ID_PopStack,
		ID_ShowAllStack
    };



BEGIN_EVENT_TABLE ( ProjectFrame, wxFrame )
      // Events for the "File" menu items
      EVT_MENU ( ID_OpenFile, ProjectFrame::OnOpenFile )		//File Menu
      EVT_MENU ( ID_Save, 	ProjectFrame::OnSave )
      EVT_MENU ( ID_SaveAs, 	ProjectFrame::OnSaveAs )
      EVT_MENU ( ID_Exit, 	ProjectFrame::OnExit )
	  //Events for that "Display"
		EVT_MENU ( ID_Display, 	ProjectFrame::OnDisplay )
      // Events for the "Help" menu items
      EVT_MENU ( ID_About, ProjectFrame::OnAbout)

      // Events for the "deque" menu items
      EVT_MENU ( ID_CreateQueue,  	ProjectFrame::OnCreateQueue)
	  EVT_MENU ( ID_ShowAllQueue, ProjectFrame::OnShowAllQueue)
	  EVT_MENU(ID_ShowHeadQueue, ProjectFrame::OnShowHeadQueue)
	  EVT_MENU(ID_ShowTailQueue, ProjectFrame::OnShowTailQueue)
	   EVT_MENU(ID_DequeueQueue, ProjectFrame::OnDequeueQueue)

		// Events for the Deque sub-menu items

	  EVT_MENU ( ID_CreateDeque,  	ProjectFrame::OnCreateDeque)
	  EVT_MENU(ID_ShowAllDeque, ProjectFrame::OnShowAllDeque)
	  EVT_MENU(ID_ShowHeadDeque, ProjectFrame::OnShowHeadDeque)
	   EVT_MENU(ID_ShowTailDeque, ProjectFrame::OnShowTailDeque)
	  EVT_MENU(ID_DequeueHeadDeque, ProjectFrame::OnDequeueHeadDeque)
	  EVT_MENU(ID_DequeueTailDeque, ProjectFrame::OnDequeueTailDeque)

       // Events for the Priority Queue sub-menu items
	  EVT_MENU(ID_CreatePQ, ProjectFrame::OnCreatePQ)
	  EVT_MENU(ID_ShowAllPQ, ProjectFrame::OnShowAllPQ)
	   EVT_MENU(ID_ShowHeadPQ, ProjectFrame::OnShowHeadPQ)
	   EVT_MENU(ID_ShowTailPQ, ProjectFrame::OnShowTailPQ)
	   EVT_MENU(ID_DequeuePQ, ProjectFrame::OnDequeuePQ)


      // Events for the Stack submenu items
	  EVT_MENU(ID_CreateStack, ProjectFrame::OnCreateStack)
	  EVT_MENU(ID_ShowAllStack, ProjectFrame::OnShowAllStack)
	  EVT_MENU(ID_PopStack, ProjectFrame::OnPopStack)



END_EVENT_TABLE ()





/************************************************************************************
*************************************************************************************
  Step 5.  Define the Application class function to initialize the application
*************************************************************************************
*************************************************************************************/
bool ProjectApp::OnInit()
  {
      // Create the main application window
      ProjectFrame *frame = new ProjectFrame( wxT("COMP2611 - Students Registration Database"),
				    wxPoint(50,50),
				    wxSize(840,600) );

      // Display the window
      frame->Show(TRUE);

      SetTopWindow(frame);

      return TRUE;

  }




/************************************************************************************
*************************************************************************************
  Step 6:   Define the Constructor functions for the Frame class
*************************************************************************************
*************************************************************************************/
ProjectFrame::ProjectFrame ( const wxString& title, const wxPoint& pos, const wxSize& size)
		    : wxFrame((wxFrame *)NULL, -1, title, pos, size)
  {
	// Set the frame icon - optional
	SetIcon(wxIcon(wxT("projectIcon.xpm")));



	// Create the main-menu items
	wxMenu *menuFile  	   =   new wxMenu;;// File main menu item
	wxMenu *menuDisplayFile  	   =   new wxMenu; //Display file main menu item
	wxMenu *menuQueue  	   =   new wxMenu;			// Queue main menu item
	wxMenu *menuHelp  	   =   new wxMenu;          // Help main menu item
	wxMenu *menuDeque      =   new wxMenu;          // Deque main menu item
	wxMenu *menuPriorityQueue      =   new wxMenu;          // Priority Queue  main menu item
	wxMenu *menuStack      =   new wxMenu;          // Priority Queue  main menu item

	//Create a Main menu bar
	wxMenuBar *menuBar = new wxMenuBar;



	//Append the main menu items to the Menu Bar
	menuBar->Append( menuFile, 		wxT("File") );
	menuBar->Append(menuDisplayFile, wxT("Display File"));
	menuBar->Append( menuQueue, 	wxT("Queue") );
	menuBar->Append(menuDeque,      wxT("Deque"));
	menuBar->Append(menuPriorityQueue,      wxT("Priority Queue"));
	menuBar->Append(menuStack,      wxT("Stack"));
	menuBar->Append( menuHelp, 		wxT("Help") );


	//Append the sub-menu items to the Display File Main Menu item
	menuDisplayFile->Append( ID_Display, wxT("Display File"), wxT("Display File") );

	//Append the sub-menu items to the File Main Menu item
	menuFile->Append( ID_OpenFile, wxT("&Open File..."), 	wxT("Open an Existing file") );
	menuFile->Append( ID_Save, 	   wxT("&Save"), 			wxT("Save opened file") );
	menuFile->Append( ID_SaveAs,   wxT("Save &As..."), 		wxT("Save display as a new file") );
	menuFile->Append( ID_Exit, 	   wxT("E&xit"), 			wxT("Close and EXIT Program") );

	//Append the sub-menu items to the Help Main Menu item
	menuHelp->Append( ID_About, wxT("About"), wxT("About this program") );
	menuHelp->Append( ID_Exit,  wxT("E&xit"), wxT("Close and EXIT Program") );


	//Append the sub-menu items to the Queue Menu item
	menuQueue->Append( ID_CreateQueue,  wxT("Create Queue"), wxT("Create QUEUE from Records file"));
	menuQueue->Append( ID_ShowAllQueue, wxT("Display All"),  wxT("Display ALL the record"));
	menuQueue->Append(ID_ShowHeadQueue,wxT("Display Head"), wxT("Display Head"));
	menuQueue->Append(ID_ShowTailQueue,wxT("Display Tail"), wxT("Display Tail"));
	menuQueue->Append(ID_DequeueQueue, wxT("Dequeue Record"),wxT("Dequeue Record"));

	//Append the sub-menu items to the Deque Menu item
	menuDeque->Append( ID_CreateDeque,  wxT("Create Deque"), wxT("Create QUEUE from Records file"));
	menuDeque->Append( ID_ShowAllDeque, wxT("Display All"),  wxT("Display ALL the record"));
	menuDeque->Append(ID_ShowHeadDeque,wxT("Display Head"), wxT("Display Head"));
	menuDeque->Append(ID_ShowTailDeque,wxT("Display Tail"), wxT("Display Tail"));
	menuDeque->Append(ID_DequeueHeadDeque, wxT("Dequeue Head Record"),wxT("Dequeue Head Record"));
	menuDeque->Append(ID_DequeueTailDeque, wxT("Dequeue Tail Record"),wxT("Dequeue Tail Record"));

	//Append the sub-menu items to the Priority Queue Menu item
	menuPriorityQueue->Append( ID_CreatePQ,  wxT("Create Priority Queue"), wxT("Create Priority Queue"));
	menuPriorityQueue->Append(ID_ShowAllPQ,wxT("Display All"), wxT("Display All"));
	menuPriorityQueue->Append(ID_ShowHeadPQ,wxT("Display Head"), wxT("Display Head"));
	menuPriorityQueue->Append(ID_ShowTailPQ,wxT("Display Tail"), wxT("Display Tail"));
	menuPriorityQueue->Append(ID_DequeuePQ, wxT("Dequeue Record"),wxT("Dequeue  Record"));

	//Append the sub-menu items to the Stack Menu item
	menuStack->Append( ID_CreateStack,  wxT("Create Stack"), wxT("Create A Stack"));
	menuStack->Append(ID_PopStack,wxT("Pop Stack"), wxT("Pop Stack"));
	menuStack->Append( ID_ShowAllStack,  wxT("Display All"), wxT("Display All"));





	// ... and now... attach this main menu bar to the frame
	SetMenuBar( menuBar );

	// Create a status bar just for fun
	CreateStatusBar(3);

	//Put something in the first section of the status bar
	SetStatusText( wxT("Ready...") );

	//Put something in the Second section of the status bar
	SetStatusText( wxT("    Assignment: Kyle Cox"), 1 );

	//Put something in the Third section of the status bar
	SetStatusText( wxT("    400009491"), 2 );




	//Set up the panel for data display
//=========================================================================================
//=========================== DO NOT CHANGE THE CODE IN THIS SECTION ======================
//=========================================================================================

	wxPanel 	*panel = new wxPanel(this, -1);
	wxBoxSizer 	*vbox  = new wxBoxSizer(wxVERTICAL);		//Vertical sizer for main window
	wxBoxSizer 	*hbox1 = new wxBoxSizer(wxHORIZONTAL);		//Horizontal sizer for main window

	//Add two textboxes to the panel for data display
	wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);		//Horizontal sizer for filename window
	wxBoxSizer *hbox3 = new wxBoxSizer(wxHORIZONTAL);		//Horizontal sizer for display window

	wxStaticText *fileLabel    = new wxStaticText(panel, wxID_ANY, wxT("File Name"));
	wxStaticText *displayLabel = new wxStaticText(panel, wxID_ANY, wxT("Display"));

	//Initialize the filename textbox window
	filenameTextBox = new wxTextCtrl(panel, wxID_ANY, wxT("No File Opened Yet..."));

	//Initialize the display window
	MainEditBox = new wxTextCtrl(panel, wxID_ANY, wxT("No Data Available Yet..."),
				      wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE | wxTE_RICH);


	//Position the labels and textboxes in the panel
	hbox1->Add(fileLabel, 0, wxRIGHT, 8);
	hbox1->Add(filenameTextBox, 1);
	vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

	vbox->Add(-1, 10);
	hbox2->Add(displayLabel, 0);
	vbox->Add(hbox2, 0, wxLEFT | wxTOP, 10);
	vbox->Add(-1, 10);

	hbox3->Add(MainEditBox, 1, wxEXPAND);
	vbox->Add(hbox3, 1, wxLEFT | wxRIGHT | wxEXPAND, 10);

	vbox->Add(-1, 25);
	panel->SetSizer(vbox);

	Centre();

  }


//=====================================================================
//=========== Other Support Functions =================================
//=====================================================================


string makeRecord(long idNo, string name, string surname, string major, float gpa)
    {
        string record = to_string(idNo) + " \t";
        record.append(name);
        record.append("\t");
        record.append(surname);
        record.append("\t");
		record.append(major);
        record.append("\t");

		string num_text = to_string(gpa);
		string rounded = num_text.substr(0, num_text.find(".")+3);	// Reduce GPA to 2 decimal places
		record.append(rounded);

		return record;
     }





string makeRecord(Record rec)
    {
        string record = to_string(rec.idNo) + " \t";
        record.append(rec.name);
        record.append("\t");
        record.append(rec.surname);
        record.append("\t");
		record.append(rec.major);
        record.append("\t");

		string num_text = to_string(rec.gpa);
		string rounded = num_text.substr(0, num_text.find(".")+3);	// Reduce GPA to 2 decimal places
		record.append(rounded);

        return record;
    }




/************************************************************************************
*************************************************************************************
  Step 7:  Define member functions for the Frame class
*************************************************************************************
*************************************************************************************/


//===================================================================================
//=========== Definition for the File Functions =====================================
//===================================================================================

void ProjectFrame::OnOpenFile(wxCommandEvent& event )
    {
       	// Creates a "open file" dialog with 3 file types
    	wxFileDialog *OpenDialog = new wxFileDialog( this,
		(wxT("Choose a file to open")), wxEmptyString, wxEmptyString,
     		(wxT("Text files (*.txt)|*.txt|All files (*.*)|*.*")),
               	 wxFD_OPEN, wxDefaultPosition);

        if (OpenDialog->ShowModal() == wxID_OK)    // if the user click "Open" instead of "cancel"
			{
            	// Sets our current document to the file the user selected
            	CurrentDocPath = OpenDialog->GetPath();

				//Clean up filename textbox and Display file name in filename textbox
				filenameTextBox->Clear();
				filenameTextBox->AppendText(CurrentDocPath);

				MainEditBox->LoadFile(CurrentDocPath);   //Opens that file in the MainEditBox

				// Set the Title
				SetTitle(wxString(wxT("COMP2611 - Data Structures : 400009491")));
			}

    }




void ProjectFrame::OnSave(wxCommandEvent& event )
    {
		// Save to the already-set path for the document
		MainEditBox->SaveFile(CurrentDocPath);
    }



void ProjectFrame::OnSaveAs(wxCommandEvent& event)
    {
		wxFileDialog *SaveDialog = new wxFileDialog(this, (wxT("Save File As...?")),
						    wxEmptyString, wxEmptyString,
						    (wxT("Text files (*.txt)|*.txt|")),
						    wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);

		// Creates a Save Dialog with 4 file types
		if (SaveDialog->ShowModal() == wxID_OK) 	// If the user clicked "OK"
			{
				CurrentDocPath = SaveDialog->GetPath();

				// set the path of our current document to the file the user chose to save under
				MainEditBox->SaveFile(CurrentDocPath); // Save the file to the selected path

				// Set the Title to reflect the file open
				SetTitle(wxString(wxT("COMP2611 - Data Structures : 400009491")));
			}

    }




void ProjectFrame::OnDisplay(wxCommandEvent& event )
    {

		long    num;
        string  first;
        string  last;
        string  maj;
        float   score;

        string record;

		// Clear the edit box
		MainEditBox->Clear();



		//open the file
		ifstream infile(CurrentDocPath.mb_str(), ios::in);

		// Check to see if a valid file was opened.
		if (!infile)
			{
				MainEditBox->AppendText(wxT("\n\n\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
				return;
			}


        // Create a label for the displayed records
        string heading = "IDNo \tName \t\t\tSurname \t\tMajor \t\tGPA\n";
        heading.append("*******************************************************************************\n");

		 // Convert "heading" into a wxString and display it in the MainEditBox
        wxString headingLine(heading.c_str(), wxConvUTF8);
        MainEditBox->AppendText(headingLine);



        while (!infile.eof())
            {
                infile >> num >> first >> last >> maj >> score;

                if (!infile.eof())
                    {

                            record = makeRecord(num, first, last, maj, score);

                            record.append("\n");


                            wxString wxRecord(record.c_str(), wxConvUTF8);
                            MainEditBox->AppendText(wxRecord);

                            //Reset record variable
                            record = "";
                        }

            }  // End while



	}



void ProjectFrame::OnExit(wxCommandEvent& event)
    {
		wxMessageBox(wxT("Good-bye!"), wxT("Exit"), wxOK | wxICON_INFORMATION, this);
		Close(TRUE); // Close the window
    }




void ProjectFrame::OnAbout(wxCommandEvent& event )
    {
		wxMessageBox(wxT("COMP2611 Data Structure\n Project #1\n\nProgrammer: Kyle Cox\n Student ID# 400009491\n Program version: 5067"), wxT("About..."), wxOK | wxICON_INFORMATION, this);
    }






//=======================================================================================
//====================   Definition for the QUEUE Functions      ==========================
//=======================================================================================

void ProjectFrame::OnCreateQueue(wxCommandEvent& event)
  {
		long    num;
        string  first;
        string  last;
        string  maj;
        float   score;

        string record;

		// Clear the edit box
		MainEditBox->Clear();

		//Empty the Queue
		queue->purgeQueue();

		//open the file
		ifstream infile(CurrentDocPath.mb_str(), ios::in);

		// Check to see if a valid file was opened.
		if (!infile)
			{
				MainEditBox->AppendText(wxT("\n\n\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
				return;
			}


        // Create a label for the displayed records
        string heading = "IDNo \tName \t\t\tSurname \t\tMajor \t\tGPA\n";
        heading.append("*******************************************************************************\n");

		 // Convert "heading" into a wxString and display it in the MainEditBox
        wxString headingLine(heading.c_str(), wxConvUTF8);
        MainEditBox->AppendText(headingLine);



        while (!infile.eof())
            {
                infile >> num >> first >> last >> maj >> score;

                if (!infile.eof())
                    {
                        if (maj == "COMP") {
                            record = makeRecord(num, first, last, maj, score);

                            record.append("\t\t...Enqueued\n");
                            queue->enqueue(num, first, last, maj, score);

                            wxString wxRecord(record.c_str(), wxConvUTF8);
                            MainEditBox->AppendText(wxRecord);

                            //Reset record variable
                            record = "";
                        }
                    }
            }  // End while


}




void ProjectFrame::OnShowAllQueue(wxCommandEvent& event)
	{

 		// Clear the edit box
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("Displaying the Queue\n"));

		// Get the data from the queue Function which call showAll() as a string
		string str = queue->showAll();

		//Convert the string into a wxString
		wxString wxRecord(str.c_str(), wxConvUTF8);

		//Display the wxString in the MainEditBox
		MainEditBox->AppendText(wxRecord);

	}
void ProjectFrame::OnShowHeadQueue(wxCommandEvent& event)
	{

 		// Clear the edit box
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("Displaying the Head Record \n"));

		// Get the data from the queue Function which call showHead() as a string
		string str = queue->showHead();

		//Convert the string into a wxString
		wxString wxRecord(str.c_str(), wxConvUTF8);

		//Display the wxString in the MainEditBox
		MainEditBox->AppendText(wxRecord);

	}

void ProjectFrame::OnShowTailQueue(wxCommandEvent& event)
	{

 		// Clear the edit box
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("Displaying the Tail Record \n"));

		// Get the data from the queue Function which call showTail() as a string
		string str = queue->showTail();

		//Convert the string into a wxString
		wxString wxRecord(str.c_str(), wxConvUTF8);

		//Display the wxString in the MainEditBox
		MainEditBox->AppendText(wxRecord);

	}

void ProjectFrame::OnDequeueQueue(wxCommandEvent& event)
	{

 		// Clear the edit box
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("Dequeued this record\n"));

		// Get the data from the queue Function which call dequeue() as a string
		string str = queue->dequeue();

		//Convert the string into a wxString
		wxString wxRecord(str.c_str(), wxConvUTF8);

		//Display the wxString in the MainEditBox
		MainEditBox->AppendText(wxRecord);

	}

//=======================================================================================
//====================   Definition for the Deque Functions      ==========================
//=======================================================================================


void ProjectFrame::OnCreateDeque(wxCommandEvent& event)
  {
		long    num;
        string  first;
        string  last;
        string  maj;
        float   score;

        string record;

		// Clear the edit box
		MainEditBox->Clear();

		//Empty the Queue
		deque->purgeDeque();

		//open the file
		ifstream infile(CurrentDocPath.mb_str(), ios::in);

		// Check to see if a valid file was opened.
		if (!infile)
			{
				MainEditBox->AppendText(wxT("\n\n\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
				return;
			}


        // Create a label for the displayed records
        string heading = "IDNo \tName \t\t\tSurname \t\tMajor \t\tGPA\n";
        heading.append("*******************************************************************************\n");

		 // Convert "heading" into a wxString and display it in the MainEditBox
        wxString headingLine(heading.c_str(), wxConvUTF8);
        MainEditBox->AppendText(headingLine);



        while (!infile.eof())
            {
                infile >> num >> first >> last >> maj >> score;

                if (!infile.eof())
                    {
                        if (maj == "MATH") {
                            record = makeRecord(num, first, last, maj, score);

                            record.append("\t\t...Enqueued\n");
                            deque->enqueueHead(num, first, last, maj, score);

                            wxString wxRecord(record.c_str(), wxConvUTF8);
                            MainEditBox->AppendText(wxRecord);

                            //Reset record variable
                            record = "";
                        }
                         if (maj == "ELET") {
                            record = makeRecord(num, first, last, maj, score);

                            record.append("\t\t...Enqueued\n");
                            deque->enqueueTail(num, first, last, maj, score);

                            wxString wxRecord(record.c_str(), wxConvUTF8);
                            MainEditBox->AppendText(wxRecord);

                            //Reset record variable
                            record = "";
                        }
                    }
            }  // End while

  }

void ProjectFrame::OnShowAllDeque(wxCommandEvent& event)
	{

 		// Clear the edit box
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("Displaying the Queue\n"));

		// Get the data from the Deque Function which call showAll() as a string
		string str = deque->showAll();

		//Convert the string into a wxString
		wxString wxRecord(str.c_str(), wxConvUTF8);

		//Display the wxString in the MainEditBox
		MainEditBox->AppendText(wxRecord);

	}
void ProjectFrame::OnShowHeadDeque(wxCommandEvent& event)
	{

 		// Clear the edit box
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("Displaying the Head Record \n"));

		//Get the data from the Deque Function which call showHead() as a string
		string str = deque->showHead();

		//Convert the string into a wxString
		wxString wxRecord(str.c_str(), wxConvUTF8);

		//Display the wxString in the MainEditBox
		MainEditBox->AppendText(wxRecord);

	}
	void ProjectFrame::OnShowTailDeque(wxCommandEvent& event)
	{

 		// Clear the edit box
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("Displaying the Tail Record \n"));

		// Get the data from the Deque Function which call showTail() as a string
		string str = deque->showTail();

		//Convert the string into a wxString
		wxString wxRecord(str.c_str(), wxConvUTF8);

		//Display the wxString in the MainEditBox
		MainEditBox->AppendText(wxRecord);

	}

	void ProjectFrame::OnDequeueHeadDeque(wxCommandEvent& event)
	{

 		// Clear the edit box
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("Displaying the dequeued head Record \n"));

		// Get the data from the Deque Function which call dequeueHead() as a string
		string str = deque->dequeueHead();

		//Convert the string into a wxString
		wxString wxRecord(str.c_str(), wxConvUTF8);

		//Display the wxString in the MainEditBox
		MainEditBox->AppendText(wxRecord);

	}
	void ProjectFrame::OnDequeueTailDeque(wxCommandEvent& event)
	{

 		// Clear the edit box
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("Displaying the dequeued tail Record \n"));

		// Get the data from the Deque Function which call dequeueTail() as a string
		string str = deque->dequeueTail();

		//Convert the string into a wxString
		wxString wxRecord(str.c_str(), wxConvUTF8);

		//Display the wxString in the MainEditBox
		MainEditBox->AppendText(wxRecord);

	}
//=======================================================================================
//====================   Definition for the Priority Queue Functions      ==========================
//=======================================================================================

void ProjectFrame::OnCreatePQ(wxCommandEvent& event)
  {
		long    num;
        string  first;
        string  last;
        string  maj;
        float   score;

        string record;

		// Clear the edit box
		MainEditBox->Clear();

		//Empty the Queue
		priorityQueue->PurgePriorityQueue();

		//open the file
		ifstream infile(CurrentDocPath.mb_str(), ios::in);

		// Check to see if a valid file was opened.
		if (!infile)
			{
				MainEditBox->AppendText(wxT("\n\n\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
				return;
			}


        // Create a label for the displayed records
        string heading = "IDNo \tName \t\t\tSurname \t\tMajor \t\tGPA\n";
        heading.append("*******************************************************************************\n");

		 // Convert "heading" into a wxString and display it in the MainEditBox
        wxString headingLine(heading.c_str(), wxConvUTF8);
        MainEditBox->AppendText(headingLine);



        while (!infile.eof())
            {
                infile >> num >> first >> last >> maj >> score;

                if (!infile.eof())
                    {

                            record = makeRecord(num, first, last, maj, score);

                            record.append("\t\t...Enqueued\n");
                            priorityQueue->enqueueAscegOrder(num, first, last, maj, score);

                            wxString wxRecord(record.c_str(), wxConvUTF8);
                            MainEditBox->AppendText(wxRecord);

                            //Reset record variable
                            record = "";

                    }
            }  // End while


}


void ProjectFrame::OnShowAllPQ(wxCommandEvent& event) {
	// Clear the edit box
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("Displaying the priority Queue\n"));

		// Get the data from the Priority Queue Function which call showAll() as a string
		string str = priorityQueue->showAll();

		//Convert the string into a wxString
		wxString wxRecord(str.c_str(), wxConvUTF8);

		//Display the wxString in the MainEditBox
		MainEditBox->AppendText(wxRecord);

}
void ProjectFrame::OnShowHeadPQ(wxCommandEvent& event)
	{

 		// Clear the edit box
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("Displaying the Head Record \n"));

		// Get the data from the Priority Queue Function which call Show Head() as a string
		string str = priorityQueue->showHead();

		//Convert the string into a wxString
		wxString wxRecord(str.c_str(), wxConvUTF8);

		//Display the wxString in the MainEditBox
		MainEditBox->AppendText(wxRecord);

	}

	void ProjectFrame::OnShowTailPQ(wxCommandEvent& event)
	{

 		// Clear the edit box
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("Displaying the Tail Record \n"));

		// Get the data from the Priority Queue Function which call showTail() as a string
		string str = priorityQueue->showTail();

		//Convert the string into a wxString
		wxString wxRecord(str.c_str(), wxConvUTF8);

		//Display the wxString in the MainEditBox
		MainEditBox->AppendText(wxRecord);

	}

	void ProjectFrame::OnDequeuePQ(wxCommandEvent& event)
	{

 		// Clear the edit box
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("Displaying the dequeued Head Record \n"));

		// Get the data from the Priority Queue Function which call deque() as a string
		string str = priorityQueue->dequeue();

		//Convert the string into a wxString
		wxString wxRecord(str.c_str(), wxConvUTF8);

		//Display the wxString in the MainEditBox
		MainEditBox->AppendText(wxRecord);

	}
		//=======================================================================================
//====================   Definition for the Stack Functions      ==========================
//=======================================================================================


void ProjectFrame::OnCreateStack(wxCommandEvent& event)
  {
		long    num;
        string  first;
        string  last;
        string  maj;
        float   score;

        string record;

		// Clear the edit box
		MainEditBox->Clear();

		//Empty the Queue
		deque->purgeDeque();

		//open the file
		ifstream infile(CurrentDocPath.mb_str(), ios::in);

		// Check to see if a valid file was opened.
		if (!infile)
			{
				MainEditBox->AppendText(wxT("\n\n\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
				return;
			}


        // Create a label for the displayed records
        string heading = "IDNo \tName \t\t\tSurname \t\tMajor \t\tGPA\n";
        heading.append("*******************************************************************************\n");

		 // Convert "heading" into a wxString and display it in the MainEditBox
        wxString headingLine(heading.c_str(), wxConvUTF8);
        MainEditBox->AppendText(headingLine);



        while (!infile.eof())
            {
                infile >> num >> first >> last >> maj >> score;

                if (!infile.eof())
                    {
                        if (maj == "IT") {
                            record = makeRecord(num, first, last, maj, score);

                            record.append("\t\t...Enqueued\n");
                            stack->push(num, first, last, maj, score);

                            wxString wxRecord(record.c_str(), wxConvUTF8);
                            MainEditBox->AppendText(wxRecord);

                            //Reset record variable
                            record = "";
                        }

                    }
            }  // End while


}
void ProjectFrame::OnShowAllStack(wxCommandEvent& event)
	{

 		// Clear the edit box
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("Displaying the Stack\n"));

		// Get the data from the Stack Function which call showAll() as a string
		string str = stack->showAll();

		//Convert the string into a wxString
		wxString wxRecord(str.c_str(), wxConvUTF8);

		//Display the wxString in the MainEditBox
		MainEditBox->AppendText(wxRecord);

	}
void ProjectFrame::OnPopStack(wxCommandEvent& event)
	{

 		// Clear the edit box
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("Displaying the Popped Record\n"));

		// Get the data from the Stack Function which call pop() as a string
		string str = stack->pop();

		//Convert the string into a wxString
		wxString wxRecord(str.c_str(), wxConvUTF8);

		//Display the wxString in the MainEditBox
		MainEditBox->AppendText(wxRecord);

	}
