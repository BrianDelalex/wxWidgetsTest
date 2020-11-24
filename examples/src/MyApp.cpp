# include <wx/wxprec.h>

#ifndef WX_PRECOMP
# include <wx/wx.h>
#endif

# include "../inc/MyFrame.hpp"

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    wxInitAllImageHandlers();
    MyFrame *frame = new MyFrame(nullptr, wxID_ANY, "MyFrame");

    frame->Show();
    return (true);
}
