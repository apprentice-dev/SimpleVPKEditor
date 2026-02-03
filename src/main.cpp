//#include <iostream>
#include "wx/wx.h"
#include "windows/mainwindow.hpp"

class SVE : public wxApp{
  public:
	bool OnInit(){
		MainWindow *mainwindow = new MainWindow();
		mainwindow->Show();
		return true;
        }
}

DECLARE_APP(SVE);
IMPLEMENT_APP(SVE);



/*
int main(){
  
  //using namespace std;
  //cout << "hello world" << endl;
  return 0;
}*/
