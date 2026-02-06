#pragma once

#include "wx/wx.h"
#include "wx/filepicker.h"

class MainWindow : public wxFrame{
  public:
	MainWindow();
	void handleSize(wxSizeEvent &);
        void handleVPKPick(wxFileDirPickerEvent &);
	
	//more event handlers
  private:
		DECLARE_EVENT_TABLE()
                wxTextCtrl *filetext;


};

