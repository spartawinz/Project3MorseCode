// Project3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CodeMap.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int main()
{
	CodeMap handler;
	string message;
	handler.initialize();
	handler.loadCodes();
	int input = 0;
	string inputString;
	while (input != 1 && input != 2 && input != 3)
	{
		cout << "[1] ENCODE. \n" << "[2] DECODE. \n" << "[3] QUIT.\n" << "Please choose an option: ";
		cin >> input;
		if (input != 1 && input != 2 && input != 3)
		{
			cout << "invalid input.\n";
			cin.clear();
			cin.ignore();
		}
	}
	switch (input)
	{
	case 1:
		cout << "please input your decoded message: ";
		cin.ignore();
		getline(cin, message);
		handler.encode(message);
		cin.clear();
		cin.ignore();
		main();
		break;
	case 2:
		cout << "please input your encoded message: ";
		cin.ignore();
		getline(cin, message);
		handler.decode(message);
		cin.clear();
		cin.ignore();
		main();
		break;
	case 3:
		break;
	}
	return 0;
}

