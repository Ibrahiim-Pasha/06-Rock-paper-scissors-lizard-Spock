/*
	+-----------------------------------------+
	| - Author : Ibrahim Mohamed Abdul-Meged. |
        +-----------------------------------------+
*/


#include "SomeErrors.h"



CSomeErrors::CSomeErrors()
{
}


CSomeErrors::~CSomeErrors()
{
}


void CSomeErrors::question(string aQuestion, void(*yFunction)(), void(*nFunction)())
{
	char answer;

	cout << endl << aQuestion << "[Y/N]? : ";
	cin >> answer;

	if (isalpha(answer))
	{
		if (toupper(answer) == 'Y')
		{
			system("CLS");
			(*yFunction)();
		}
		else if (toupper(answer) == 'N')
		{
			(*nFunction)();
		}
		else
		{
			insertWrong("Please enter Y to answer yes or N to answer no\n");
			question(aQuestion, *yFunction, *nFunction);
		}
	}
	else
	{
		cout << "\nYou entered is not alphabet!" << endl;
		question(aQuestion, *yFunction, *nFunction);
	}
}


void  CSomeErrors::insertWrong(string wrong)
{
	cout << endl << wrong;
	Sleep(2000);
	system("CLS");
}


void CSomeErrors::exitProgram()
{
	cout << endl << endl << "Goodbye! .. " << endl << endl;
	Sleep(2000);
	exit(0);
}
