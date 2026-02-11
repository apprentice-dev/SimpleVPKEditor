#include "mainwindow.hpp"
#include <iostream>
#include "wx/listctrl.h"



MainWindow::MainWindow():wxFrame(NULL,wxID_ANY, wxT("Simple VPK Editor V1.0"),wxDefaultPosition,wxSize(200,200),wxDEFAULT_FRAME_STYLE|wxRESIZE_BORDER){
  wxBoxSizer *topSizer = new wxBoxSizer (wxVERTICAL); 
  wxBoxSizer *filechooserlayout = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer *actionslayout = new wxBoxSizer(wxHORIZONTAL);  

  topSizer->Add(filechooserlayout, 0, wxEXPAND|wxALL,10);
  
  wxTextCtrl *fileTxtBox = new wxTextCtrl(this, wxID_ANY);
  filetext = fileTxtBox;
  wxFilePickerCtrl *filePickerBox = new wxFilePickerCtrl(this, wxID_HIGHEST+67, wxT(""), wxT("Pick VPK to edit"), wxT("*.vpk"),wxDefaultPosition,wxDefaultSize,wxFLP_OPEN|wxFLP_FILE_MUST_EXIST);

  filechooserlayout->Add(fileTxtBox, 1, wxRIGHT,10);
  //filechooserlayout->Add(fileTxtBox, wxSizerFlags().
  filechooserlayout->Add(filePickerBox, 0, 0,0);

  //wxDataViewCtrl *assetsTable = new wxDataViewCtrl(this, wxID_ANY);
  //assetsTable->

  wxListCtrl *assetsTable = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
  assetsTable->InsertColumn(0,wxT("Handle"),wxLIST_FORMAT_LEFT,wxLIST_AUTOSIZE_USEHEADER);
  assetsTable->InsertColumn(1,wxT("File Size"),wxLIST_FORMAT_LEFT,wxLIST_AUTOSIZE_USEHEADER);
  assetsTable->InsertColumn(2, wxT("Translated Name"),wxLIST_FORMAT_LEFT,wxLIST_AUTOSIZE_USEHEADER);



  topSizer->Add(assetsTable,1,wxEXPAND|wxALL,10);

  topSizer->Add(actionslayout,0,wxALL|wxALIGN_CENTER_HORIZONTAL,10);

  wxButton *process = new wxButton(this, wxID_ANY, wxT("Process"));
  wxButton *cancel = new wxButton(this, wxID_ANY, wxT("Cancel"));

   

  actionslayout->Add(process, 0, wxRIGHT, 10);
  actionslayout->Add(cancel,0,0,0);

  

  SetSizer(topSizer);
  topSizer->SetSizeHints(this);
  //topSizer->Fit(this);
  SetMinClientSize(wxSize(400,400));

  

  CreateStatusBar(1);
  wxLogStatus(this, wxT("Ready"));

  
  
}

void MainWindow::handleSize(wxSizeEvent &evt){
  using namespace std;
  cout << this->GetMinClientSize().GetHeight() << " " <<  this->GetMinClientSize().GetWidth() << "    " << this->GetClientSize().GetHeight() << " " <<  this->GetClientSize().GetWidth() << endl;
  //SetClientSize(this->GetMinClientSize());
  //SetSize(wxSize(200,200));
  evt.Skip();
}

void MainWindow::handleVPKPick(wxFileDirPickerEvent &evt){
  using namespace std;
  //cout << "picked VPK: " << evt.GetPath() << endl;
  filetext->WriteText(evt.GetPath());
  
}


BEGIN_EVENT_TABLE(MainWindow, wxFrame)
  //EVT_SIZE(MainWindow::handleSize)
  EVT_FILEPICKER_CHANGED(wxID_HIGHEST+67,MainWindow::handleVPKPick)
END_EVENT_TABLE()
