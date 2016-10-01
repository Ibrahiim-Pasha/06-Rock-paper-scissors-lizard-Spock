/*
	+-----------------------------------------+
	| - Author : Ibrahim Mohamed Abdul-Meged. |
	+-----------------------------------------+
*/

#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class CSomeErrors
{
public:
	CSomeErrors();
	~CSomeErrors();

	void question(string aQuestion,void(*yFunction)(), void(*nFunction)());
	void insertWrong(string wrong);
	void exitProgram();
};

