# include "../inc/MyFrame.hpp"

# include <iostream>
# include <wx/filedlg.h>
# include <wx/bitmap.h>

MyFrame::MyFrame(wxWindow *parent, wxWindowID id, const wxString &title)
    : wxFrame(parent, id, title)
{
    _menuBar = new wxMenuBar(0);
    _menu = new wxMenu(0);
    _menuIt = new wxMenuItem(_menu, ID_MENU_IT1, "Open...");

    _menu->Append(_menuIt);
    _menuBar->Append(_menu, "File");

    this->SetMenuBar(_menuBar);
    _imagePanel = new wxImagePanel(this);

    Bind(wxEVT_MENU, &MyFrame::OnMenuItClicked, this, ID_MENU_IT1);
}

MyFrame::~MyFrame() {}

void MyFrame::OnMenuItClicked(wxCommandEvent &evt)
{
    wxString wildcard = "Image files (*.jpg;*.bmp;*.png)|*.jpg;*.bmp;*.png";
    wxFileDialog *fileDlg = new wxFileDialog(
        this,
        "Choissisez une image",
        wxEmptyString,
        wxEmptyString,
        wildcard,
        wxFD_OPEN
    );
    if (fileDlg->ShowModal() == wxID_CANCEL)
        return;
    _imagePanel->setImage(fileDlg->GetPath(), wxBITMAP_TYPE_ANY);
    std::cout << fileDlg->GetPath() << std::endl;
}