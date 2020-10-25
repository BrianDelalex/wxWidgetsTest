#include "wxImagePanel.hpp"

BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)
// catch paint events
EVT_PAINT(wxImagePanel::paintEvent)
//Size event
EVT_SIZE(wxImagePanel::OnSize)
END_EVENT_TABLE()

wxImagePanel::wxImagePanel(wxFrame* parent) :
wxPanel(parent)
{
    w = -1;
    h = -1;
}

void wxImagePanel::paintEvent(wxPaintEvent & evt)
{
    wxPaintDC dc(this);
    render(dc);
}

void wxImagePanel::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}

void wxImagePanel::render(wxDC&  dc)
{
    int neww, newh;
    dc.GetSize( &neww, &newh );
    
    if (image.IsOk()) {
        if( neww != w || newh != h )
        {
            resized = wxBitmap( image.Scale( neww, newh /*, wxIMAGE_QUALITY_HIGH*/ ) );
            w = neww;
            h = newh;
            dc.DrawBitmap( resized, 0, 0, false );
        }else{
            dc.DrawBitmap( resized, 0, 0, false );
        }
    } else {
        dc.DrawText("No Image loaded", wxPoint(0, 0));
    }
}

void wxImagePanel::OnSize(wxSizeEvent& event){
    Refresh();
    event.Skip();
}

void wxImagePanel::setImage(const wxString &file, wxBitmapType format)
{
    if (file == wxEmptyString)
        return;
    if (!image.LoadFile(file, format))
        return;
    h = -1;
    w = -1;
    paintNow();
}