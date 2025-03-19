//
//  DataDialog.h
//  Kyle Cox - 400009491
//
//
//  Created by Dr. John Charlery on 03/13/2024.
//  Copyright (c) 2024 University of the West Indies. All rights reserved.
//

#ifndef DATADIALOG_h
#define DATADIALOG_h

#include <iostream>
#include <iomanip>
#include <string>

#include <stdexcept>

using namespace std;


class DataInputDialog:public wxDialog{

public:
    // Constructor to initialize the dialog
    DataInputDialog(const wxString& title, const wxPoint& pos, const wxSize& size);

    // Text boxes for ID number, name, and surname
    wxTextCtrl* IdNumBox;
    wxTextCtrl* nameBox;
    wxTextCtrl* surnameBox;

    // Radio buttons for selecting major
    wxRadioButton* COMP;
    wxRadioButton* MATH;
    wxRadioButton* ELET;
    wxRadioButton* PHYS;
    wxRadioButton* IT;

    // Spinner control for selecting GPA
    wxSpinCtrlDouble* gpa;
};

// Implementation of the constructor
DataInputDialog::DataInputDialog(const wxString& title, const wxPoint& pos, const wxSize& size):wxDialog((wxDialog*)NULL, -1, title, pos, size)
{
    wxPanel *panel = new wxPanel(this, -1);

    // Define and position the StaticTexts and TextCtrl
    wxStaticText* idNOLabel = new wxStaticText(panel, wxID_ANY, wxT("ID Number"), wxPoint(15,25));
    IdNumBox = new wxTextCtrl(panel, wxID_ANY, wxT("--ID Number"), wxPoint(100,25), wxSize(170,-1));

    wxStaticText* nameLabel = new wxStaticText(panel, wxID_ANY, wxT("First Name"), wxPoint(15,65));
    nameBox = new wxTextCtrl(panel, wxID_ANY, wxT("First Name"), wxPoint(100,65), wxSize(170,-1));

    wxStaticText* surnameLabel = new wxStaticText(panel, wxID_ANY, wxT("Second Name"), wxPoint(15,105));
    surnameBox = new wxTextCtrl(panel, wxID_ANY, wxT("First Name"), wxPoint(100,105), wxSize(170,-1));


    wxStaticText* majorLabel = new wxStaticText(panel, wxID_ANY, wxT("Select Major"), wxPoint(340,25));
    COMP = new wxRadioButton(panel, -1, wxT("COMP"), wxPoint(340, 45));
    MATH = new wxRadioButton(panel, -1, wxT("MATH"), wxPoint(340, 65));
    ELET = new wxRadioButton(panel, -1, wxT("ELET"), wxPoint(340, 85));
    PHYS = new wxRadioButton(panel, -1, wxT("PHYS"), wxPoint(340, 105));
    IT = new wxRadioButton(panel, -1, wxT("IT"), wxPoint(340, 125));

    wxStaticText* gpaLabel = new wxStaticText(panel, wxID_ANY, wxT("Select GPA"), wxPoint(450,25));
    gpa = new wxSpinCtrlDouble(panel, -1, "", wxPoint(450, 65), wxSize(110, -1), wxSP_ARROW_KEYS, 0, 4, 2.0, 0.01);

    // OK and Cancel buttons
    wxButton* ok = new wxButton(panel, wxID_OK, wxT("&OK"), wxPoint(150,205), wxDefaultSize, 0);
    wxButton* cancel = new wxButton(panel, wxID_CANCEL, wxT("&CANCEL"), wxPoint(270,205), wxDefaultSize, 0);

    // Centre the dialog on the parent's window
    Centre();

    // Maximize the window
    Maximize();
}




class DataDeleteDialog:public wxDialog{

public:
    //Overloading Constructor
    DataDeleteDialog(const wxString& title, const wxPoint& pos, const wxSize& size);


    // Text boxes for ID number
    wxTextCtrl* IdNumBox;

};

DataDeleteDialog::DataDeleteDialog(const wxString& title, const wxPoint& pos, const wxSize& size):wxDialog((wxDialog*)NULL, -1, title, pos, size)
{
    wxPanel *panel =new wxPanel(this, -1);

    //Define and position the StaticTexts and TextCtrl
    wxStaticText* idNOLabel = new wxStaticText(panel, wxID_ANY, wxT("ID Number"), wxPoint(15,25));
    IdNumBox = new wxTextCtrl(panel, wxID_ANY, wxT("--ID Number"), wxPoint(100,65), wxSize(170,-1));

    wxButton* ok = new wxButton(panel, wxID_OK, wxT("&OK"), wxPoint(150,205), wxDefaultSize, 0);//The Ok Button
     wxButton* cancel = new wxButton(panel, wxID_CANCEL, wxT("&CANCEL"), wxPoint(270,205), wxDefaultSize, 0);//The Cancel Button


    Centre();//Centre the dialog on the parent's window

    Maximize(); //Maximize the window
}

#endif
