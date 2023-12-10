#include "ProcessorSingleton.h"
#include "../Sample-Test1/pch.h"
#include "wx/tokenzr.h"




// Initialize static member
ProcessorSingleton* ProcessorSingleton::instance_ = nullptr;

//
ProcessorSingleton* ProcessorSingleton::GetInstance()
{
	if (ProcessorSingleton::instance_ == nullptr)
		ProcessorSingleton::instance_ = new ProcessorSingleton;
	return ProcessorSingleton::instance_;
}

wxString ProcessorSingleton::Calculate(wxString expr)
{
	wxStringTokenizer tokenizer(expr, " ");
	wxString processedString = "";
	// Processing Sin, Cos and Tan
	while (tokenizer.HasMoreTokens())
	{
		wxString token = tokenizer.GetNextToken();
		if (token == "Sin" || token == "Cos" || token == "Tan")
		{
			//
			if (!tokenizer.HasMoreTokens()) return "INVALID EXPRESSION";
			//
			wxString operStr = tokenizer.GetNextToken();
			double oper;
			if (!operStr.ToDouble(&oper)) return "INVALID EXPRESSION";
			//
			double result;
			if (token == "Sin") result = sin(oper);
			else if (token == "Cos") result = cos(oper);
			else result = tan(oper);

			//
			wxString resultStr;
			resultStr << result;
			if (processedString == "") processedString = resultStr;
			else processedString += " " + resultStr;
		}
		else
		{
			if (processedString == "") processedString = token;
			else processedString += " " + token;
		}
	}

	// Processing *, / and modulo
	wxStringTokenizer tokenizer2(processedString, " ");
	wxString processedString2 = "";
	wxString op1Str = "";
	while (tokenizer2.HasMoreTokens())
	{
		wxString token = tokenizer2.GetNextToken();
		if (token == "*" || token == "/" || token == "%")
		{
			//
			if (op1Str == "" || !tokenizer2.HasMoreTokens()) return "INVALID EXPRESSION";
			//
			wxString op2Str = tokenizer2.GetNextToken();
			double op1, op2;
			if (!op1Str.ToDouble(&op1) || !op2Str.ToDouble(&op2)) return "INVALID EXPRESSION";
			//
			double result;
			if (token == "*") result = op1 * op2;
			else if (token == "/")
			{
				if (op2 == 0) return "DIVISION BY 0";
				result = op1 / op2;
			}
			else
			{
				if (op2 == 0) return "MODULO BY 0";

				//
				int op1i, op2i;
				if (!op1Str.ToInt(&op1i) || !op2Str.ToInt(&op2i)) return "INVALID EXPRESSION";
				result = op1i % op2i;
			}

			op1Str = "";
			op1Str << result;
		}
		else
		{
			if (op1Str == "") op1Str = token;
			else {
				if (processedString2 == "") processedString2 = op1Str + " " + token;
				else processedString2 += " " + op1Str + " " + token;
				op1Str = "";
			}
		}
	}
	if (op1Str != "")
	{
		if (processedString2 == "") processedString2 = op1Str;
		else processedString2 += " " + op1Str;
	}

	// Processing + and - 
	wxStringTokenizer tokenizer3(processedString2, " ");
	wxString processedString3 = "";
	op1Str = "";
	while (tokenizer3.HasMoreTokens())
	{
		wxString token = tokenizer3.GetNextToken();
		if (token == "+" || token == "-")
		{
			//
			if (op1Str == "" || !tokenizer3.HasMoreTokens()) return "INVALID EXPRESSION";
			//
			wxString op2Str = tokenizer3.GetNextToken();
			double op1, op2;
			if (!op1Str.ToDouble(&op1) || !op2Str.ToDouble(&op2)) return "INVALID EXPRESSION";
			//
			double result = 0.0;
			if (token == "+") result = op1 + op2;
			else result = op1 - op2;

			op1Str = "";
			op1Str << result;
		}
		else
		{
			if (op1Str == "") op1Str = token;
			else {
				if (processedString3 == "") processedString3 = op1Str + " " + token;
				else processedString3 += " " + op1Str + " " + token;
				op1Str = "";
			}
		}
	}
	if (op1Str != "")
	{
		if (processedString3 == "") processedString3 = op1Str;
		else processedString3 += " " + op1Str;
	}

	return processedString3;
}

ProcessorSingleton::ProcessorSingleton()
{
}

