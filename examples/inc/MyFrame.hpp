#ifndef MYFRAME_HPP
# define MYFRAME_HPP

# include <wx/frame.h>
# include <wx/menu.h>
# include "../inc/wxImagePanel.hpp"

class MyFrame : public wxFrame
{
public:
    MyFrame(wxWindow *parent, wxWindowID id, const wxString &title);
    ~MyFrame();
    void OnMenuItClicked(wxCommandEvent &evt);
private:
    wxMenuBar* _menuBar;
    wxMenu* _menu;
    wxMenuItem* _menuIt;
    wxImagePanel* _imagePanel;
    enum
    {
        ID_MENU_IT1 = wxID_HIGHEST + 1
    };
};

#endif /* !MYFRAME_HPP */