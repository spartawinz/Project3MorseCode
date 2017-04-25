#include "stdafx.h"
#include "CodeMap.h"
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>


using namespace std;

CodeMap::CodeMap()
{
}
// loads the codes into the map
void CodeMap::loadCodes()
{
	for (int i = 0; i < letters.size(); i++)
	{
		CodesEncode[letters[i]] = code[i];
		CodesDecode[code[i]] = letters[i];
	}
}
// encode/decode
void CodeMap::encode(string& message)
{
	vector<string> splitMessage = split(message);
	vector<string> result;
	for (int i = 0; i < splitMessage.size(); i++)
	{
		map<string, string>::const_iterator itr = CodesEncode.find(splitMessage[i]);
		if (itr != CodesEncode.end())
			result.push_back(itr->second);
		else
		{
			cout << "Incorrect entry.";
			throw exception("oops! Wrong input.");
		}
	}
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	cout << "\n";
}
void CodeMap::decode(string message)
{
	vector<string> splitMessage = split(message);
	vector<string> result;
	
	for (int i = 0; i < splitMessage.size(); i++)
	{
		map<string, string>::const_iterator itr = CodesDecode.find(splitMessage[i]);
		if (itr != CodesDecode.end())
			result.push_back(itr->first);
		else
		{
			cout << "item not in map.";
			throw exception("oops! wrong input.");
		}
	}
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	cout << "\n";
}
// reads file and puts it into vectors
void CodeMap::initialize()
{
	// opens file
	input.open("morse.txt");
	if (input.fail())
	{
		cout << "something wrong with the morse.txt file/not found.\n";
		throw exception("File not found.");
	}
	// while not end of file it will split the text into two vectors.
	while (!input.eof())
	{
		input >> inputSection;
		string* hold = new string[inputSection.length() + 1];
		*hold = *inputSection.c_str();
		letters.push_back(hold[0]);
		code.push_back(inputSection.substr(1, inputSection.length() - 1));
		delete[] hold;
	}
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < letters.size(); j++)
		{
			if (code[j].length() == i)
			{
				Nodes2Be.push_back(letters[j]);
				Data2Be.push_back(code[j]);
			}
		}
	}
}

vector<string> CodeMap::split(string message)
{
	vector<string> result;
	string hold = message;
	string temp;
	while (hold.find(" ", 0) != string::npos)
	{
		int pos = hold.find(" ", 0);
		temp = hold.substr(0, pos);
		hold.erase(0, pos + 1);
		result.push_back(temp);
	}
	return result;
}
