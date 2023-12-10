#pragma once
#include "wx/wx.h"

#ifndef PROCESSOR_SINGLETON_H
#define PROCESSOR_SINGLETON_H
class ProcessorSingleton
{
public:
	static ProcessorSingleton* GetInstance();
	// Calculates the math expression and returns result
	wxString Calculate(wxString expr);
protected:
	ProcessorSingleton();
	static ProcessorSingleton* instance_;
};
#endif 

