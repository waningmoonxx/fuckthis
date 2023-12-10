#pragma once
#include "wx/wx.h"

#include "ButtonFactory.h"

#ifndef CMAIN_H   // Include guard
#define CMAIN_H

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:
	ButtonFactory* button_factory = nullptr;

	wxButton* btn_0 = nullptr;
	wxButton* btn_1 = nullptr;
	wxButton* btn_2 = nullptr;
	wxButton* btn_3 = nullptr;
	wxButton* btn_4 = nullptr;
	wxButton* btn_5 = nullptr;
	wxButton* btn_6 = nullptr;
	wxButton* btn_7 = nullptr;
	wxButton* btn_8 = nullptr;
	wxButton* btn_9 = nullptr;

	wxButton* btn_Add = nullptr;
	wxButton* btn_Sub = nullptr;
	wxButton* btn_Div = nullptr;
	wxButton* btn_Mult = nullptr;
	wxButton* btn_Mod = nullptr;

	wxButton* btn_equals = nullptr;

	wxButton* btn_Neg = nullptr;
	wxButton* btn_decmial = nullptr;
	wxButton* btn_Clr = nullptr;
	wxButton* btn_Del = nullptr;

	wxButton* btn_Sin = nullptr;
	wxButton* btn_Cos = nullptr;
	wxButton* btn_Tan = nullptr;

	wxTextCtrl* txt_box = nullptr;
};
#endif