#include <wx/wxprec.h>

#ifndef WX_PRECOMP
# include <wx/wx.h>
#endif /* !WX_PRECOMP */

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    wxFrame *frame = new wxFrame(nullptr, wxID_ANY, "MyFrame");
    frame->Show();
    return (true);
}