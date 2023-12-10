#include "ButtonFactory.h"
#include "ProcessorSingleton.h"
#include "wx/tokenzr.h"
#include "../Sample-Test1/pch.h"
#include "cMain.h"

ButtonFactory::ButtonFactory(cMain* main) : main(main)
{
}

// Creates new calc button
void ButtonFactory::CreateBasicCalcButton(wxString label, wxPoint point, wxSize size)
{
    CreateBasicCalcButton(label, point, size, label);
}

// Creates new calc button with text
void ButtonFactory::CreateBasicCalcButton(wxString label, wxPoint point, wxSize size, wxString textToAdd)
{
    // Creating new button
    auto btn = new wxButton(main, 10000 + btn_count, label, point, size);

    wxFont font(wxFontInfo(18)); // Set font size 
    btn->SetFont(font);

    btn->SetForegroundColour(wxColour(3, 227, 252));
    btn->SetBackgroundColour(wxColour(0, 0, 0));

    //
    auto textCtrl = main->txt_box;
    auto func = [textCtrl, textToAdd](wxCommandEvent& evt) {
        textCtrl->AppendText(textToAdd);
        evt.Skip();
        };
    btn->Bind(wxEVT_BUTTON, func);

    btn_count++;
}

//
void ButtonFactory::CreateDeleteButton(wxPoint point, wxSize size)
{
    // Creating new button
    auto btn = new wxButton(main, 10000 + btn_count, L"<--", point, size);

    wxFont font(wxFontInfo(18)); // Set font size to 12 (you can adjust this value)
    btn->SetFont(font);

    btn->SetForegroundColour(wxColour(3, 227, 252));
    btn->SetBackgroundColour(wxColour(0, 0, 0));

    //
    auto textCtrl = main->txt_box;
    auto deleteHandler = [textCtrl](wxCommandEvent& evt) {
        if (textCtrl->GetLineLength(0) > 0)
            textCtrl->Remove(textCtrl->GetLastPosition() - 1, textCtrl->GetLastPosition());

        evt.Skip();
        };
    btn->Bind(wxEVT_BUTTON, deleteHandler);

    btn_count++;
}

//
void ButtonFactory::CreateClearButton(wxPoint point, wxSize size)
{
    // Creating new button
    auto btn = new wxButton(main, 10000 + btn_count, L"clr", point, size);

    wxFont font(wxFontInfo(18)); // Set font size to 12 (you can adjust this value)
    btn->SetFont(font);

    btn->SetForegroundColour(wxColour(3, 227, 252));//text colot
    btn->SetBackgroundColour(wxColour(0, 0, 0));//background color

    //
    auto textCtrl = main->txt_box;
    auto handler = [textCtrl](wxCommandEvent& evt) {
        textCtrl->Clear();
        evt.Skip();
        };
    btn->Bind(wxEVT_BUTTON, handler);

    btn_count++;
}

//
void ButtonFactory::CreateEqualsButton(wxPoint point, wxSize size)
{
    // Creating new button
    auto btn = new wxButton(main, 10000 + btn_count, L"=", point, size);

    wxFont font(wxFontInfo(18)); // Set font size to 12 (you can adjust this value)
    btn->SetFont(font);

    btn->SetForegroundColour(wxColour(3, 227, 252));
    btn->SetBackgroundColour(wxColour(0,0,0));

    //
    auto textCtrl = main->txt_box;
    auto handler = [textCtrl](wxCommandEvent& evt) {
        wxString result = ProcessorSingleton::GetInstance()->Calculate(textCtrl->GetLineText(0));
        //
        textCtrl->Clear();
        textCtrl->AppendText(result);

        evt.Skip();
        };
    btn->Bind(wxEVT_BUTTON, handler);

    btn_count++;
    
}