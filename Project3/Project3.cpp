// Project3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CodeMap.h"
#include <iostream>

using namespace std;
int main()
{
	CodeMap handler;
	handler.initialize();
	handler.loadCodes();
	string input = "a e g i s";
	handler.encode(input);
	input = "__._ ._._ _ .";
	handler.decode(input);
	
	

	system("pause");
	return 0;
}

