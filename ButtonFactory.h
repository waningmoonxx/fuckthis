#pragma once
#include "wx/wx.h"

class cMain;

/*
* Creates buttons for calculator
* Uses bind functionality since event table can only be used to bind buttons statically
*/
class ButtonFactory
{
public:
	// Constructor
	ButtonFactory(cMain* main);

	// Creates calc button which inserts text
	void CreateBasicCalcButton(wxString label, wxPoint point, wxSize size);
	// Creates calc button with custom text to add
	void CreateBasicCalcButton(wxString label, wxPoint point, wxSize size, wxString textToAdd);

	// Creates delete button which deletes one symbol from one end
	void CreateDeleteButton(wxPoint point, wxSize size);
	// Creates clear button which removes all text
	void CreateClearButton(wxPoint point, wxSize size);
	// Creates equals button which evaluates expression in text box
	void CreateEqualsButton(wxPoint point, wxSize size);
protected:
	// cMain to work with
	cMain* main;
	// Id for next button
	int btn_count = 0;
};
