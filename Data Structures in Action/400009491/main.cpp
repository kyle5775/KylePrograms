////////////////////////////////////////////////////////////////////////////
//																		  //
//  Skeleton04.cpp														  //
//  Skeleton code for Project #2 for Semester II, 2023/24.				  //
//																		  //
//	PURPOSE:															  //
//	Program reads data from a Random Access file and processing is done   //
//	with the Hierarchical and Set ADTs.  								  //
//																		  //
//  Created by Kyle Cox on 03/10/2024.							  //
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


/************************************************************************************
  Step 1: Always include the header file wx.h					    
*************************************************************************************/
#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
# include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/listbox.h>
#endif

#include <iostream>
#include <fstream>
#include <string>

#include <sstream>      // Using this header file to set precision for the GPA field
#include <vector>

using namespace std;


struct record
    {
        int idNo;
        char name[15];
        char surname[20];
        char major[6];
        float gpa;
    };
typedef struct record Record;



// Other miscellaneous functions' protypes
string makeRecord(int, string, string, string, float);
string makeRecord(Record);
string trim(float);			// Function to reduce floating point to 2 places of decimal



// the ADTs header files
#include "BSTree.h"		// This is only PARTIAL! You must complete
#include "AVLTree.h"
#include "DataDialog.h"
#include "RBTree.h"
#include "SplayTree.h"
#include "Set.h"
#include "MinHeap.h"
#include "MaxHeap.h"



//Global pointers for the ADT containers
BSTree* bst = new BSTree();
AVLTree* AVL = new AVLTree();
RBTree* rbt = new RBTree();
SplayTree* splay = new SplayTree();
Set* setA = new Set();
Set* setB = new Set();
Set* setInter = new Set();
Set* setUnion = new Set();
MaxHeap* maxHeap = new MaxHeap();
MinHeap* minHeap = new MinHeap();
// ... Add in other ADTs as global containers





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
		void OnOpenFile(wxCommandEvent& event);
		void OnCreateADTs(wxCommandEvent& event);
		void OnAddData(wxCommandEvent& event);
		void OnDisplay(wxCommandEvent& event);
		void OnSave(wxCommandEvent& event);
		void OnSaveAs(wxCommandEvent& event);	
		void OnClearWindow(wxCommandEvent& event);
		void OnExit(wxCommandEvent& event); 	//handle for Quit function



		//Function for Help Menu Item
		void OnAbout(wxCommandEvent& event);

		
		//Functions for the Partial BST Menu Items
		void OnInorderBST(wxCommandEvent& event);
		void OnPreorderBST(wxCommandEvent& event);
		void OnPostorderBST(wxCommandEvent& event);
		void OnRemoveFromBST(wxCommandEvent& event);
		

		
				
		//Functions for AVL Menu Items
		void OnInorderAVL(wxCommandEvent& event);
		void OnPreorderAVL(wxCommandEvent& event);
		void OnPostorderAVL(wxCommandEvent& event);
		void OnRemoveFromAVL(wxCommandEvent& event);
				
		//Functions for RBT Menu Items
		void OnInorderRBT(wxCommandEvent& event);
		void OnPreorderRBT(wxCommandEvent& event);
		void OnPostorderRBT(wxCommandEvent& event);
		void OnRemoveFromRBT(wxCommandEvent& event);

		//Functions for Splay Menu Items
		void OnInorderSplay(wxCommandEvent& event);
		void OnPreorderSplay(wxCommandEvent& event);
		void OnPostorderSplay(wxCommandEvent& event);
		void OnRemoveFromSplay(wxCommandEvent& event);

		//Functions for SET Menu Items
		void OnDisplaySetA(wxCommandEvent& event);
		void OnDisplaySetB(wxCommandEvent& event);
		void OnDisplayInter(wxCommandEvent& event);
		void OnDisplayUnion(wxCommandEvent& event);
		void OnDeleteSetA(wxCommandEvent& event);
		void OnDeleteSetB(wxCommandEvent& event);
		
		//Functions for MaxHeap Menu Items
		void OnDisplayAllMax(wxCommandEvent& event);
		void OnDeleteDataMax(wxCommandEvent& event);
		void OnHeapSortMax(wxCommandEvent& event);

		//Functions for MinHeap Menu Items
		void OnDisplayAllMin(wxCommandEvent& event);
		void OnDeleteDataMin(wxCommandEvent& event);
		void OnHeapSortMin(wxCommandEvent& event);
		
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
		ID_CreateADTs,
		ID_AddData,
		ID_Display,
		ID_Save,
		ID_SaveAs,
		ID_ClearWindow,
		ID_Exit,


		// Help menu items
		ID_About,
		

		// BST menu items
		ID_InorderBST,
		ID_PreorderBST,
		ID_PostorderBST,
		ID_DeleteFromBST,

		
		
		// AVL sub-menu items
		ID_InorderAVL,
		ID_PreorderAVL,
		ID_PostorderAVL,
		ID_DeleteFromAVL,
		// RBT sub-menu items
	    ID_InorderRBT,
		ID_PreorderRBT,
		ID_PostorderRBT,
		ID_DeleteFromRBT,
		// Splay sub-menu items
		ID_InorderSplay,
		ID_PreorderSplay,
		ID_PostorderSplay,
		ID_DeleteFromSplay,

		// Set sub-menu items
		ID_DisplaySetA,
		ID_DisplaySetB,
		ID_DisplayInter,
		ID_DisplayUnion,
		ID_DeleteSetA,
		ID_DeleteSetB,

		
		//Max Heap sub-menu items
		ID_DisplayAllMax,
		ID_DeleteDataMax,
		ID_HeapSortMax,

	//Min Heap sub-menu items
		ID_DisplayAllMin,
		ID_DeleteDataMin,
		ID_HeapSortMin,
    };

    
    
BEGIN_EVENT_TABLE ( ProjectFrame, wxFrame )
      // Events for the "File" menu items
      EVT_MENU ( ID_OpenFile, 	 ProjectFrame::OnOpenFile )		//File Menu 
      EVT_MENU ( ID_CreateADTs,  ProjectFrame::OnCreateADTs )
      EVT_MENU ( ID_AddData,  	 ProjectFrame::OnAddData )
      EVT_MENU ( ID_Display,  	 ProjectFrame::OnDisplay )
      EVT_MENU ( ID_Save, 	  	 ProjectFrame::OnSave )
      EVT_MENU ( ID_SaveAs,   	 ProjectFrame::OnSaveAs )
      EVT_MENU ( ID_ClearWindow, ProjectFrame::OnClearWindow )
      EVT_MENU ( ID_Exit, 	  	 ProjectFrame::OnExit )


      // Events for the "Help" menu items
      EVT_MENU ( ID_About, ProjectFrame::OnAbout)

      // Events for the "BST" menu items
      EVT_MENU ( ID_InorderBST,  	ProjectFrame::OnInorderBST)
	  EVT_MENU ( ID_PreorderBST, 	ProjectFrame::OnPreorderBST)
	  EVT_MENU ( ID_PostorderBST, 	ProjectFrame::OnPostorderBST)
	  EVT_MENU ( ID_DeleteFromBST, 	ProjectFrame::OnRemoveFromBST)

 
      // Events for the AVL sub-menu items
      EVT_MENU ( ID_InorderAVL,  	ProjectFrame::OnInorderAVL)
	  EVT_MENU ( ID_PreorderAVL, 	ProjectFrame::OnPreorderAVL)
	  EVT_MENU ( ID_PostorderAVL, 	ProjectFrame::OnPostorderAVL)
	  EVT_MENU ( ID_DeleteFromAVL, 	ProjectFrame::OnRemoveFromAVL)
      
      // Events for the RBT sub-menu items
      
      EVT_MENU ( ID_InorderRBT,  	ProjectFrame::OnInorderRBT)
	  EVT_MENU ( ID_PreorderRBT, 	ProjectFrame::OnPreorderRBT)
	  EVT_MENU ( ID_PostorderRBT, 	ProjectFrame::OnPostorderRBT)
	  EVT_MENU ( ID_DeleteFromRBT, 	ProjectFrame::OnRemoveFromRBT)
      // Events for the Splay submenu items
	  EVT_MENU ( ID_InorderSplay,  	ProjectFrame::OnInorderSplay)
	  EVT_MENU ( ID_PreorderSplay, 	ProjectFrame::OnPreorderSplay)
	  EVT_MENU ( ID_PostorderSplay, 	ProjectFrame::OnPostorderSplay)
	  EVT_MENU ( ID_DeleteFromSplay, 	ProjectFrame::OnRemoveFromSplay)
      
      // Events for the "Set" menu items
      EVT_MENU ( ID_DisplaySetA,  	ProjectFrame::OnDisplaySetA)
	  EVT_MENU ( ID_DisplaySetB,  	ProjectFrame::OnDisplaySetB)
	  EVT_MENU ( ID_DisplayInter, 	ProjectFrame::OnDisplayInter)
	  EVT_MENU ( ID_DisplayUnion, 	ProjectFrame::OnDisplayUnion)
	  EVT_MENU ( ID_DeleteSetA, 	ProjectFrame::OnDeleteSetA)
	 EVT_MENU ( ID_DeleteSetB, 	ProjectFrame::OnDeleteSetB)

	 // Events for the "Max Heap" menu items
	  EVT_MENU ( ID_DisplayAllMax,  	ProjectFrame::OnDisplayAllMax)
	  EVT_MENU ( ID_DeleteDataMax, 	ProjectFrame::OnDeleteDataMax)
	 EVT_MENU ( ID_HeapSortMax, 	ProjectFrame::OnHeapSortMax)
      

	  // Events for the "Max Heap" menu items
	  EVT_MENU ( ID_DisplayAllMin,  	ProjectFrame::OnDisplayAllMin)
	  EVT_MENU ( ID_DeleteDataMin, 	ProjectFrame::OnDeleteDataMin)
	 EVT_MENU ( ID_HeapSortMin, 	ProjectFrame::OnHeapSortMin)

END_EVENT_TABLE () 
  




/************************************************************************************
*************************************************************************************
  Step 5.  Define the Application class function to initialize the application
*************************************************************************************
*************************************************************************************/
bool ProjectApp::OnInit()
  {
      // Create the main application window
      ProjectFrame *frame = new ProjectFrame( wxT("COMP2611 - Registration Database"),
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
//	SetIcon(wxIcon(wxT("UWIIcon.xpm")));

	
	
	// Create the main-menu items
	wxMenu *menuFile  	   =   new wxMenu;			// File main menu item
	wxMenu *menuBST  	   =   new wxMenu;			// BST main menu item
	wxMenu *menuAVL  	   =   new wxMenu;			// AVL main menu item
	wxMenu *menuRBT  	   =   new wxMenu;			// BRT main menu item
	wxMenu *menuSplay  	   =   new wxMenu;			// Splay Tree main menu item
	wxMenu *menuSET  	   =   new wxMenu;			// SET main menu item
	wxMenu *menuMax  	   =   new wxMenu;			// MaxHeap main menu item
	wxMenu *menuMin  	   =   new wxMenu;			// MinHeap main menu item
	wxMenu *menuHelp  	   =   new wxMenu;			// Help main menu item

	//Create a Main menu bar
	wxMenuBar *menuBar = new wxMenuBar;
		


	//Append the main menu items to the Menu Bar
	menuBar->Append( menuFile, 		wxT("File") );
	menuBar->Append( menuBST, 		wxT("BST") );
	menuBar->Append( menuAVL, 		wxT("AVL") );
	menuBar->Append( menuRBT, 		wxT("RBT") );
	menuBar->Append( menuSplay, 		wxT("Splay") );
	menuBar->Append( menuSET, 		wxT("SET") );
	menuBar->Append( menuMax, 		wxT("Max Heap") );
	menuBar->Append( menuMin, 		wxT("Min Heap") );
	menuBar->Append( menuHelp, 		wxT("Help") );
	// Etc... Etc...

	
	
	//Append the sub-menu items to the File Main Menu item
	menuFile->Append( ID_OpenFile, 		wxT("Open File..."), 	wxT("Open an Existing file") );
	menuFile->Append( ID_CreateADTs,	wxT("Create ADTs"),		wxT("Populate ADTs from opened file") );
	menuFile->Append( ID_AddData,  		wxT("Add Data"),		wxT("Add a new record to the ADTs") );
	menuFile->Append( ID_Display,  		wxT("Display File..."),	wxT("Display contents of opened file") );
	menuFile->Append( ID_Save, 	   		wxT("Save File"), 		wxT("Save to opened file") );
	menuFile->Append( ID_SaveAs,   		wxT("Save As"), 		wxT("Save display as a new file") );
	menuFile->Append( ID_ClearWindow,  	wxT("Clear Window"),	wxT("Clear display window") );
	menuFile->Append( ID_Exit, 	   		wxT("Exit"), 			wxT("Close and EXIT Program") );
	


	//Append the sub-menu items to the BST Main Menu item
	menuBST->Append( ID_InorderBST,   wxT("Inorder"), 	wxT("Inorder traversal on BST"));
	menuBST->Append( ID_PreorderBST,  wxT("Preorder"), 	wxT("Preorder traversal on BST"));
	menuBST->Append( ID_PostorderBST, wxT("Postorder"),	wxT("Inorder traversal on BST"));
	menuBST->Append( ID_DeleteFromBST,wxT("Delete Data"), wxT("Remove a record from the BST"));

	//Append the sub-menu items to the AVL Main Menu item
	menuAVL->Append( ID_InorderAVL,   wxT("Inorder"), 	wxT("Inorder traversal on AVL"));
	menuAVL->Append( ID_PreorderAVL,  wxT("Preorder"), 	wxT("Preorder traversal on AVL"));
	menuAVL->Append( ID_PostorderAVL, wxT("Postorder"),	wxT("Inorder traversal on AVL"));
	menuAVL->Append( ID_DeleteFromAVL,wxT("Delete Data"), wxT("Remove a record from the AVL"));

	//Append the sub-menu items to the RBT Main Menu item
	menuRBT->Append( ID_InorderRBT,   wxT("Inorder"), 	wxT("Inorder traversal on RBT"));
	menuRBT->Append( ID_PreorderRBT,  wxT("Preorder"), 	wxT("Preorder traversal on RBT"));
	menuRBT->Append( ID_PostorderRBT, wxT("Postorder"),	wxT("Inorder traversal on RBT"));
	menuRBT->Append( ID_DeleteFromRBT,wxT("Delete Data"), wxT("Remove a record from the RBT"));

	//Append the sub-menu items to the Splay Main Menu item
	menuSplay->Append( ID_InorderSplay,   wxT("Inorder"), 	wxT("Inorder traversal on Splay Tree"));
	menuSplay->Append( ID_PreorderSplay,  wxT("Preorder"), 	wxT("Preorder traversal on Splay Tree"));
	menuSplay->Append( ID_PostorderSplay, wxT("Postorder"),	wxT("Inorder traversal on Splay Tree"));
	menuSplay->Append( ID_DeleteFromSplay,wxT("Delete Data"), wxT("Remove a record from the Splay Tree"));

	//Append the sub-menu items to the SET Main Menu item
	menuSET->Append( ID_DisplaySetA,   wxT("Display SetA"), 	wxT("Display SetA"));
	menuSET->Append( ID_DisplaySetB,  wxT("Display SetB "), 	wxT("Display SetB"));
	menuSET->Append( ID_DisplayInter, wxT("Display Intersection"),	wxT("Display Intersection"));
	menuSET->Append( ID_DisplayUnion,   wxT("Display Union"), 	wxT("Display Union"));
	menuSET->Append( ID_DeleteSetA,  wxT("Delete SetA "), 	wxT("Delete  SetA"));
	menuSET->Append( ID_DeleteSetB,  wxT("Delete SetB"), 	wxT("Delete  SetB"));

	//Append the sub-menu items to the Max Heap Main Menu item
	menuMax->Append( ID_DisplayAllMax,   wxT("Display Max Heap"), 	wxT("Display Max Heap"));
	menuMax->Append( ID_DeleteDataMax,  wxT("Delete Data "), 	wxT("Delete  Data"));
	menuMax->Append( ID_HeapSortMax,  wxT("Heap Sort Max Heap"), 	wxT("Heap Sort Max Heap"));

	//Append the sub-menu items to the Max Heap Main Menu item
	menuMin->Append( ID_DisplayAllMin,   wxT("Display Min Heap"), 	wxT("Display Min Heap"));
	menuMin->Append( ID_DeleteDataMin,  wxT("Delete Data "), 	wxT("Delete  Data"));
	menuMin->Append( ID_HeapSortMin,  wxT("Heap Sort Min Heap"), 	wxT("Heap Sort Min Heap"));


	//Append the sub-menu items to the Help Main Menu item
	menuHelp->Append( ID_About, wxT("About"), wxT("About this program") );
	menuHelp->Append( ID_Exit,  wxT("E&xit"), wxT("Close and EXIT Program") );

	
	//Append the other sub-menu items to the the other Main Menu item


	
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
    
    
 // Function to reduce floating point val to 2 places of decimal
string trim(float val)
     {
         ostringstream strVal;
         strVal << fixed << setprecision(2) << val;
         return strVal.str();
     }

  
  
  
  
string makeRecord(int idNo, string name, string surname, string major, float gpa)
    {
        string recordStr = to_string(idNo) + " \t";
        
        recordStr.append(name);
        recordStr.append("\t\t");
        recordStr.append(surname);
        recordStr.append("\t\t");
		recordStr.append(major);
        recordStr.append("\t\t");
		recordStr.append(trim(gpa));		// 2 decimal places for gpa

		return recordStr;
     }
  



string makeRecord(Record rec)
    {
        string recordStr = to_string(rec.idNo) + " \t";
        recordStr.append(rec.name);
		recordStr.append("\t\t");
        recordStr.append(rec.surname);
		recordStr.append("\t\t");
		recordStr.append(rec.major);
		recordStr.append("\t\t");
		recordStr.append(trim(rec.gpa));			// 2 decimal places for gpa

        return recordStr;
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
			(wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|All files (*.*)|*.*")),
			wxFD_OPEN, wxDefaultPosition);
 
        if (OpenDialog->ShowModal() == wxID_OK)    // if the user click "Open" instead of "cancel"
			{
            	// Sets our current document to the file the user selected
            	CurrentDocPath = OpenDialog->GetPath();

				//Clean up filename textbox and Display file name in filename textbox
				filenameTextBox->Clear();
				filenameTextBox->AppendText(CurrentDocPath);

				// Set the Title
				SetTitle(wxString(wxT("COMP2611 - Student Registration Database")));


				//Opens the file and display the contents in the MainEditBox
 				ifstream infile(CurrentDocPath.mb_str(), ios::in|ios::binary);

  				// Check to see if a valid file was opened.
				if (!infile)
					{
						MainEditBox->AppendText(wxT("\n\n\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
						return;
					}
								
     			Record rec;				// variable to read the data from the binary file
     			string strRecord ="Hello";		// Variable to store record as a string
    
        		infile.seekg(0);

         		while (!infile.eof())
            		{
						infile.read(reinterpret_cast<char* >(&rec), sizeof(Record));

						// Make sure rec is not an empty record before trying to display it
						if (rec.idNo > 1000)
							{
								strRecord = makeRecord(rec);

								// Convert record (a string) to wxRecord (a wxWidget string)
								wxString wxRecord(strRecord.c_str(), wxConvUTF8);
								MainEditBox->AppendText(wxRecord);
								MainEditBox->AppendText(wxT("\n"));

								//Reset the record variable
								strRecord = "";
                    		}

            		}  // End while
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
				SetTitle(wxString(wxT("COMP2611 - Student Registration Database")));
			}
	    
    }
  
 


 
 
void ProjectFrame::OnDisplay(wxCommandEvent& event )
    {
		Record  rec;
		string strRecord;

		// Clear the MainEditBox
		MainEditBox->Clear();

		//open the file
		ifstream infile(CurrentDocPath.mb_str(), ios::in|ios::binary);

		// Check to see if a valid file was opened.
		if (!infile)
			{
				MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
				return;
			}

		infile.seekg(0);

        while (!infile.eof())
            {
				infile.read(reinterpret_cast<char*>(&rec),sizeof(Record));

				// Make sure rec is not an empty record before trying to display it
				if (rec.idNo > 1000)
					{
						strRecord = makeRecord(rec);

						// Convert record (a string) to wxRecord (a wxWidget string)
						wxString wxRecord(strRecord.c_str(), wxConvUTF8);
						MainEditBox->AppendText(wxRecord);
						MainEditBox->AppendText(wxT("\n"));

						//Reset the record variable
						strRecord = "";
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
		wxMessageBox(wxT("COMP2611 Data Structure\n Project #2\n\nProgrammer: Kyle Cox\n Student ID# 400009491\n Program version: 5067"), wxT("About..."), wxOK | wxICON_INFORMATION, this);
	}
  



void ProjectFrame::OnCreateADTs(wxCommandEvent& event)
	{
		Record  rec;
		string strRecord;
		string major;

		// Clear the MainEditBox
		MainEditBox->Clear();

		//open the file
		ifstream infile(CurrentDocPath.mb_str(), ios::in|ios::binary);

		// Check to see if a valid file was opened.
		if (!infile)
			{
				MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
				return;
			}

		infile.seekg(0);
        while (!infile.eof())
            {
				infile.read(reinterpret_cast<char*>(&rec),sizeof(Record));

				// Make sure rec is not an empty record before trying to display it
				if (rec.idNo > 1000)
					{
						// Load record into the ADRs
						// 1. BST takes all the recordStr
						bst->insert(rec);

						// 2. If Major equals  to COMP record goes to AVL
						for(int i = 0; i < 5; i++){
							major += rec.major[i];
				        if(major == "COMP"){

						AVL->insert(rec);
						}
					// 3. If Major equals  to IT record goes to RBT
					 if(major == "IT"){
                             rbt->insert(rec);

						}
						//7. If gpa more than 3.0 record goes to setA or if gpa less than or equal to 3.0 record goes to setB
						if(rec.gpa < 3.0 ){

						setA->add(rec);

						}

						if(rec.gpa >= 3.0 ){
							setB->add(rec);

						}
						//4. If Major equals  to MATH record goes to SPLAY
						if(major == "MATH"){

						splay->insert(rec);
						}
						//5. If Major equals or Pysics record goes to Max Heap
						if(major == "ELET" || major == "PHYS" ){

						maxHeap->addMaxHeap(rec);

						}
						//6. If Major equals  to COMP record goes to Min heap
						if(major == "MATH"){

						minHeap->addMinHeap(rec);
							}
						}

						// Display the record in the MainEditBox
						strRecord = makeRecord(rec);

						// Convert record (a string) to wxRecord (a wxWidget string)
						wxString wxRecord(strRecord.c_str(), wxConvUTF8);
						MainEditBox->AppendText(wxRecord);
						MainEditBox->AppendText(wxT("\n"));

						//Reset the record variable
						strRecord = "";
						major="";
                    }
            }  // End while

	}



void ProjectFrame::OnAddData(wxCommandEvent& event)
{
    // Declare variables to store data
    int ID;
    string name, surname, major, StrIdNum;
    float gpa;
    double DDGpa;

    // Create a new instance of the DataInputDialog
    DataInputDialog* dataInputdialog = new DataInputDialog(wxT("Input Data"), wxPoint(200, 200), wxSize(600, 300));

    // Clear the main edit box
    MainEditBox->Clear();

    // Show the data input dialog and proceed if OK is pressed
    if (dataInputdialog->ShowModal() == wxID_OK) {
        // Extract data from the dialog controls
        StrIdNum = dataInputdialog->IdNumBox->GetValue();
        ID = stoi(StrIdNum);

        DDGpa = dataInputdialog->gpa->GetValue();
        try {
            gpa = static_cast<float>(DDGpa);
        } catch (invalid_argument& e) {
            // Handle the invalid argument exception here

            wxMessageBox("Invalid GPA value entered. Please enter a valid floating-point number.", "Error", wxICON_ERROR | wxOK);
            // Optionally, return from the function or perform cleanup
            return;
        }

        // Determine the selected major
        if (dataInputdialog->COMP->GetValue() == true)
            major = "COMP";
        if (dataInputdialog->MATH->GetValue() == true)
            major = "MATH";
        if (dataInputdialog->ELET->GetValue() == true)
            major = "ELET";
        if (dataInputdialog->PHYS->GetValue() == true)
            major = "PHYS";
        if (dataInputdialog->IT->GetValue() == true)
            major = "IT";

        // Extract name and surname
        name = dataInputdialog->nameBox->GetValue();
        surname = dataInputdialog->surnameBox->GetValue();

        // Insert data into appropriate data structures based on major and GPA
        bst->insert(ID, name, surname, major, gpa);
        if (major == "COMP") {
            AVL->insert(ID, name, surname, major, gpa);
        }
        if (major == "IT") {
            rbt->insert(ID, name, surname, major, gpa);
        }
        if (major == "MATH") {
            splay->insert(ID, name, surname, major, gpa);
            minHeap->addMinHeap(ID, name, surname, major, gpa);
        }
        if (major == "ELET" || major == "PHYS") {
            maxHeap->addMaxHeap(ID, name, surname, major, gpa);
        }
        if (gpa < 3.0) {
            setA->add(ID, name, surname, major, gpa);
        }
        if (gpa >= 3.0) {
            setB->add(ID, name, surname, major, gpa);
        }

        // Close and destroy the data input dialog
        dataInputdialog->Close();
        dataInputdialog->Destroy();
    } else {
        // Close and destroy the data input dialog if Cancel is pressed
        dataInputdialog->Close();
        dataInputdialog->Destroy();
    }
}




void ProjectFrame::OnClearWindow(wxCommandEvent& event)
	{
 		//Clear the MainEditBox
		MainEditBox->Clear();
	}

  
//=======================================================================================
//====================   Definition for the BST Functions      ==========================
//=======================================================================================

void ProjectFrame::OnInorderBST(wxCommandEvent& event)
	{
		// Clear the MainEditBox
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("\t\tResult from Inorder Traversal...\n"));

		// Get the string from the inorder traversal
		string record = bst->inOrder();

		// Convert record (a string) to wxRecord (a wxWidget string)
		wxString wxRecord(record.c_str(), wxConvUTF8);

		// Display the string in the MainEditBox
		MainEditBox->AppendText(wxRecord);
	}

void ProjectFrame::OnPreorderBST(wxCommandEvent& event)
	{
			// Clear the MainEditBox
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("\t\tResult from preorder Traversal...\n"));

		// Get the string from the preorder traversal
		string record = bst->preOrder();

		// Convert record (a string) to wxRecord (a wxWidget string)
		wxString wxRecord(record.c_str(), wxConvUTF8);

		// Display the string in the MainEditBox
		MainEditBox->AppendText(wxRecord);
	}


void ProjectFrame::OnPostorderBST(wxCommandEvent& event)
	{
		//Clear the MainEditBox
			// Clear the MainEditBox
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("\t\tResult from post order Traversal...\n"));

		// Get the string from the preorder traversal
		string record = bst->postOrder();

		// Convert record (a string) to wxRecord (a wxWidget string)
		wxString wxRecord(record.c_str(), wxConvUTF8);

		// Display the string in the MainEditBox
		MainEditBox->AppendText(wxRecord);
	}


void ProjectFrame::OnRemoveFromBST(wxCommandEvent& event)
	{
		string StrIdNum;
		DataDeleteDialog* datadialog = new DataDeleteDialog(wxT("Delete node by ID"),wxPoint(200,200),wxSize(500,300));

		if(datadialog->ShowModal() == wxID_OK){

			StrIdNum = datadialog->IdNumBox->GetValue();
			datadialog->Close();
			datadialog->Destroy();
		}




		int IdNum = stoi(StrIdNum);
		bst->remove(IdNum);

	}
//=======================================================================================
//====================   Definition for the AVL Functions      ==========================
//=======================================================================================

void ProjectFrame::OnInorderAVL(wxCommandEvent& event)
	{
		// Clear the MainEditBox
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("\t\tResult from Inorder Traversal...\n"));

		// Get the string from the inorder traversal
		string record = AVL->inOrder();

		// Convert record (a string) to wxRecord (a wxWidget string)
		wxString wxRecord(record.c_str(), wxConvUTF8);

		// Display the string in the MainEditBox
		MainEditBox->AppendText(wxRecord);
	}

void ProjectFrame::OnPreorderAVL(wxCommandEvent& event)
	{
			// Clear the MainEditBox
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("\t\tResult from preorder Traversal...\n"));

		// Get the string from the preorder traversal
		string record = AVL->preOrder();

		// Convert record (a string) to wxRecord (a wxWidget string)
		wxString wxRecord(record.c_str(), wxConvUTF8);

		// Display the string in the MainEditBox
		MainEditBox->AppendText(wxRecord);
	}


void ProjectFrame::OnPostorderAVL(wxCommandEvent& event)
	{
		//Clear the MainEditBox
			// Clear the MainEditBox
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("\t\tResult from post order Traversal...\n"));

		// Get the string from the preorder traversal
		string record = AVL->postOrder();

		// Convert record (a string) to wxRecord (a wxWidget string)
		wxString wxRecord(record.c_str(), wxConvUTF8);

		// Display the string in the MainEditBox
		MainEditBox->AppendText(wxRecord);
	}


void ProjectFrame::OnRemoveFromAVL(wxCommandEvent& event)
	{
		string StrIdNum;
		DataDeleteDialog* datadialog = new DataDeleteDialog(wxT("Delete node by ID"),wxPoint(200,200),wxSize(500,300));

		if(datadialog->ShowModal() == wxID_OK){

			StrIdNum = datadialog->IdNumBox->GetValue();

			datadialog->Close();
			datadialog->Destroy();

		}




		int IdNum = stoi(StrIdNum);
		AVL->remove(IdNum);

	}
//=======================================================================================
//====================   Definition for the RBT Functions      ==========================
//=======================================================================================

void ProjectFrame::OnInorderRBT(wxCommandEvent& event)
	{
		// Clear the MainEditBox
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("\t\tResult from Inorder Traversal...\n"));

		// Get the string from the inorder traversal
		string record = rbt->inOrder();

		// Convert record (a string) to wxRecord (a wxWidget string)
		wxString wxRecord(record.c_str(), wxConvUTF8);

		// Display the string in the MainEditBox
		MainEditBox->AppendText(wxRecord);
	}

void ProjectFrame::OnPreorderRBT(wxCommandEvent& event)
	{
			// Clear the MainEditBox
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("\t\tResult from preorder Traversal...\n"));

		// Get the string from the preorder traversal
		string record = rbt->preOrder();

		// Convert record (a string) to wxRecord (a wxWidget string)
		wxString wxRecord(record.c_str(), wxConvUTF8);

		// Display the string in the MainEditBox
		MainEditBox->AppendText(wxRecord);
	}


void ProjectFrame::OnPostorderRBT(wxCommandEvent& event)
	{
		//Clear the MainEditBox
			// Clear the MainEditBox
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("\t\tResult from post order Traversal...\n"));

		// Get the string from the preorder traversal
		string record = rbt->postOrder();

		// Convert record (a string) to wxRecord (a wxWidget string)
		wxString wxRecord(record.c_str(), wxConvUTF8);

		// Display the string in the MainEditBox
		MainEditBox->AppendText(wxRecord);
	}


void ProjectFrame::OnRemoveFromRBT(wxCommandEvent& event)
	{
		string StrIdNum;
		DataDeleteDialog* datadialog = new DataDeleteDialog(wxT("Delete node by ID"),wxPoint(200,200),wxSize(500,300));

		if(datadialog->ShowModal() == wxID_OK){

			StrIdNum = datadialog->IdNumBox->GetValue();
	datadialog->Close();
			datadialog->Destroy();
		}




		int IdNum = stoi(StrIdNum);
		rbt->remove(IdNum);

	}

//=======================================================================================
//====================   Definition for the Splay Functions      ==========================
//=======================================================================================

void ProjectFrame::OnInorderSplay(wxCommandEvent& event)
	{
		// Clear the MainEditBox
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("\t\tResult from Inorder Traversal...\n"));

		// Get the string from the inorder traversal
		string record = splay->inOrder();

		// Convert record (a string) to wxRecord (a wxWidget string)
		wxString wxRecord(record.c_str(), wxConvUTF8);

		// Display the string in the MainEditBox
		MainEditBox->AppendText(wxRecord);
	}

void ProjectFrame::OnPreorderSplay(wxCommandEvent& event)
	{
			// Clear the MainEditBox
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("\t\tResult from preorder Traversal...\n"));

		// Get the string from the preorder traversal
		string record = splay->preOrder();

		// Convert record (a string) to wxRecord (a wxWidget string)
		wxString wxRecord(record.c_str(), wxConvUTF8);

		// Display the string in the MainEditBox
		MainEditBox->AppendText(wxRecord);
	}


void ProjectFrame::OnPostorderSplay(wxCommandEvent& event)
	{
		//Clear the MainEditBox
			// Clear the MainEditBox
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("\t\tResult from post order Traversal...\n"));

		// Get the string from the preorder traversal
		string record = splay->postOrder();

		// Convert record (a string) to wxRecord (a wxWidget string)
		wxString wxRecord(record.c_str(), wxConvUTF8);

		// Display the string in the MainEditBox
		MainEditBox->AppendText(wxRecord);
	}


void ProjectFrame::OnRemoveFromSplay(wxCommandEvent& event)
	{
		string StrIdNum;
		DataDeleteDialog* datadialog = new DataDeleteDialog(wxT("Delete node by ID"),wxPoint(200,200),wxSize(500,300));

		if(datadialog->ShowModal() == wxID_OK){

			StrIdNum = datadialog->IdNumBox->GetValue();




			datadialog->Close();
			datadialog->Destroy();
	}
		int IdNum = stoi(StrIdNum);
		splay->remove(IdNum);

	}
//=======================================================================================
//====================   Definition for the SET Functions      ==========================
//=======================================================================================

void ProjectFrame::OnDisplaySetA(wxCommandEvent& event)
	{
		// Clear the MainEditBox
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("\t\tResult from Display SetA...\n"));

		// Get the string from the inorder traversal
		string record = setA->display();

		// Convert record (a string) to wxRecord (a wxWidget string)
		wxString wxRecord(record.c_str(), wxConvUTF8);

		// Display the string in the MainEditBox
		MainEditBox->AppendText(wxRecord);
	}

	void ProjectFrame::OnDisplaySetB(wxCommandEvent& event)
	{
		// Clear the MainEditBox
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("\t\tResult from Display SetB...\n"));

		// Get the string from the inorder traversal
		string record = setB->display();

		// Convert record (a string) to wxRecord (a wxWidget string)
		wxString wxRecord(record.c_str(), wxConvUTF8);

		// Display the string in the MainEditBox
		MainEditBox->AppendText(wxRecord);
	}

void ProjectFrame::OnDisplayInter(wxCommandEvent& event)
	{
		// Clear the MainEditBox
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("\t\tResult from the Intersection Set ...\n"));


		setInter->intersectionSet(setA, setB);
		// Get the string from the inorder traversal
		string record = setInter->display();

		// Convert record (a string) to wxRecord (a wxWidget string)
		wxString wxRecord(record.c_str(), wxConvUTF8);

		// Display the string in the MainEditBox
		MainEditBox->AppendText(wxRecord);
	}
void ProjectFrame::OnDisplayUnion(wxCommandEvent& event)
	{
		// Clear the MainEditBox
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("\t\tResult from Display SetB...\n"));
			setUnion->unionSet( setA,  setB);
		// Get the string from the inorder traversal
		string record = setUnion->display();

		// Convert record (a string) to wxRecord (a wxWidget string)
		wxString wxRecord(record.c_str(), wxConvUTF8);

		// Display the string in the MainEditBox
		MainEditBox->AppendText(wxRecord);
	}

	void ProjectFrame::OnDeleteSetA(wxCommandEvent& event)
	{
			string StrIdNum;
		DataDeleteDialog* datadialog = new DataDeleteDialog(wxT("Delete node by ID"),wxPoint(200,200),wxSize(500,300));

		if(datadialog->ShowModal() == wxID_OK){

			StrIdNum = datadialog->IdNumBox->GetValue();



			datadialog->Close();
			datadialog->Destroy();
		}
		int IdNum = stoi(StrIdNum);
		setA->deleteFromSet(IdNum);

	}


	void ProjectFrame::OnDeleteSetB(wxCommandEvent& event)
	{
	string StrIdNum;
		DataDeleteDialog* datadialog = new DataDeleteDialog(wxT("Delete node by ID"),wxPoint(200,200),wxSize(500,300));

		if(datadialog->ShowModal() == wxID_OK){

			StrIdNum = datadialog->IdNumBox->GetValue();



			datadialog->Close();
			datadialog->Destroy();
		}
		int IdNum = stoi(StrIdNum);
		setB->deleteFromSet(IdNum);
	}

	//=======================================================================================
//====================   Definition for the Max Heap Functions      ==========================
//=======================================================================================

void ProjectFrame::OnDisplayAllMax(wxCommandEvent& event)
	{
		// Clear the MainEditBox
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("\t\tDisplaying result...\n"));

		// Get the string from the inorder traversal
		string record = maxHeap->displayHeap();

		// Convert record (a string) to wxRecord (a wxWidget string)
		wxString wxRecord(record.c_str(), wxConvUTF8);

		// Display the string in the MainEditBox
		MainEditBox->AppendText(wxRecord);
	}

void ProjectFrame::OnHeapSortMax(wxCommandEvent& event)
	{
			// Clear the MainEditBox
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("\t\tResult from Sorting the Max Heap...\n"));

		// Get the string from the preorder traversal
		string record = maxHeap->sortMaxHeap();

		// Convert record (a string) to wxRecord (a wxWidget string)
		wxString wxRecord(record.c_str(), wxConvUTF8);

		// Display the string in the MainEditBox
		MainEditBox->AppendText(wxRecord);
	}



void ProjectFrame::OnDeleteDataMax(wxCommandEvent& event)
	{
		string StrIdNum;
		DataDeleteDialog* datadialog = new DataDeleteDialog(wxT("Delete node by ID"),wxPoint(200,200),wxSize(500,300));

		if(datadialog->ShowModal() == wxID_OK){

			StrIdNum = datadialog->IdNumBox->GetValue();



			datadialog->Close();
			datadialog->Destroy();
		}
		int IdNum = stoi(StrIdNum);
		maxHeap->deleteMaxHeap(IdNum);

	}
//=======================================================================================
//====================   Definition for the Min Heap Functions      ==========================
//=======================================================================================

void ProjectFrame::OnDisplayAllMin(wxCommandEvent& event)
	{
		// Clear the MainEditBox
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("\t\tDisplaying result...\n"));

		// Get the string from the inorder traversal
		string record = minHeap->displayHeap();

		// Convert record (a string) to wxRecord (a wxWidget string)
		wxString wxRecord(record.c_str(), wxConvUTF8);

		// Display the string in the MainEditBox
		MainEditBox->AppendText(wxRecord);
	}

void ProjectFrame::OnHeapSortMin(wxCommandEvent& event)
	{
			// Clear the MainEditBox
		MainEditBox->Clear();

		MainEditBox->AppendText(wxT("\t\tResult from Sorting The Min Heap...\n"));

		// Get the string from the preorder traversal
		string record = minHeap->sortMinHeap();

		// Convert record (a string) to wxRecord (a wxWidget string)
		wxString wxRecord(record.c_str(), wxConvUTF8);

		// Display the string in the MainEditBox
		MainEditBox->AppendText(wxRecord);
	}



void ProjectFrame::OnDeleteDataMin(wxCommandEvent& event)
	{
		string StrIdNum;
		DataDeleteDialog* datadialog = new DataDeleteDialog(wxT("Delete node by ID"),wxPoint(200,200),wxSize(500,300));

		if(datadialog->ShowModal() == wxID_OK){

			StrIdNum = datadialog->IdNumBox->GetValue();



			datadialog->Close();
			datadialog->Destroy();
		}
		int IdNum = stoi(StrIdNum);
		minHeap->deleteMinHeap(IdNum);

	}
