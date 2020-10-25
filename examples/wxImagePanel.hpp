#include <wx/wx.h>
#include <wx/sizer.h>

class wxImagePanel : public wxPanel
{
    wxImage image;
    wxBitmap resized;
    int w, h;
    
public:
    wxImagePanel(wxFrame* parent);
    
    void paintEvent(wxPaintEvent & evt);
    void paintNow();
    void OnSize(wxSizeEvent& event);
    void render(wxDC& dc);
    void setImage(const wxString &file, wxBitmapType format);
    
    DECLARE_EVENT_TABLE()
};