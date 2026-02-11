/*
  thread
*/
#ifndef PROCESS_DEFS
#define PROCESS_DEFS


class VPKProcessThread : public wxThread{
public:
    VPKProcessThread(char *filepath);
    wxThread::ExitCode *Entry();

private:
    char *filepath;

};


/*
 *
  tentative event declarations
  will add more or switch completely if needed
 *
*/


class SpecialAssetsCompleteEvent : public wxEvent{
public:
    //might have to accomodate winid because we may open 2 or 3 windows or more idk in the future
    ProcessCompleteEvent(wxEventType eventType, int winid, )
    virtual wxEvent *Clone() const { return new ProcessCompleteEvent(*this); }

private:
    //we are only pulling soundtracks for now

};
#endif


