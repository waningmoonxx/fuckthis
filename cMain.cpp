#include "cMain.h"

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(100, 100), wxSize(470, 750))
 {
	txt_box = new wxTextCtrl(this, 16006, wxEmptyString, wxPoint(10, 10), wxSize(430, 35));
	txt_box->Enable(false);

	button_factory = new ButtonFactory(this);

	button_factory->CreateBasicCalcButton(L"0", wxPoint(120, 600), wxSize(100, 100));
	button_factory->CreateBasicCalcButton(L"1", wxPoint(10, 490), wxSize(100, 100));
	button_factory->CreateBasicCalcButton(L"2", wxPoint(120, 490), wxSize(100, 100));
	button_factory->CreateBasicCalcButton(L"3", wxPoint(230, 490), wxSize(100, 100));
	button_factory->CreateBasicCalcButton(L"4", wxPoint(10, 380), wxSize(100, 100));
	button_factory->CreateBasicCalcButton(L"5", wxPoint(120, 380), wxSize(100, 100));
	button_factory->CreateBasicCalcButton(L"6", wxPoint(230, 380), wxSize(100, 100));
	button_factory->CreateBasicCalcButton(L"7", wxPoint(10, 270), wxSize(100, 100));
	button_factory->CreateBasicCalcButton(L"8", wxPoint(120, 270), wxSize(100, 100));
	button_factory->CreateBasicCalcButton(L"9", wxPoint(230, 270), wxSize(100, 100));

	button_factory->CreateBasicCalcButton(L"Sin", wxPoint(10, 160), wxSize(100, 100), L" Sin ");
	button_factory->CreateBasicCalcButton(L"Cos", wxPoint(120, 160), wxSize(100, 100), L" Cos ");
	button_factory->CreateBasicCalcButton(L"Tan", wxPoint(230, 160), wxSize(100, 100), L" Tan ");

	button_factory->CreateBasicCalcButton(L"+", wxPoint(340, 490), wxSize(100, 100), L" + ");
	button_factory->CreateBasicCalcButton(L"-", wxPoint(340, 380), wxSize(100, 100), L" - ");
	button_factory->CreateBasicCalcButton(L"*", wxPoint(340, 270), wxSize(100, 100), L" * ");
	button_factory->CreateBasicCalcButton(L"/", wxPoint(340, 160), wxSize(100, 100), L" / ");
	button_factory->CreateBasicCalcButton(L"%", wxPoint(340, 50), wxSize(100, 100), L" % ");

	button_factory->CreateBasicCalcButton(L"+/-", wxPoint(10, 600), wxSize(100, 100), L"-");


	button_factory->CreateBasicCalcButton(L".", wxPoint(10, 50), wxSize(100, 100));
	button_factory->CreateDeleteButton(wxPoint(230, 50), wxSize(100, 100));
	button_factory->CreateClearButton(wxPoint(120, 50), wxSize(100, 100));
	button_factory->CreateEqualsButton(wxPoint(240, 600), wxSize(200, 100));
}

cMain::~cMain()
{
}