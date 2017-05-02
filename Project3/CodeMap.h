#pragma once
#include "stdafx.h"
#include "Binary_Tree.h"
#include "BTNode.h"
#include <string>
#include <vector>
#include <map>
#include <fstream>



class CodeMap
{
public:
	CodeMap();
	void loadCodes();
	void encode(std::string message);
	void decode(std::string message);
	void initialize();


private:
	std::vector<std::string> split(std::string message);
	std::map<std::string, std::string> CodesDecode;
	std::map<std::string, std::string> CodesEncode;
	std::vector<std::string> Nodes2Be;
	std::vector<std::string>Data2Be;
	std::fstream input;
	std::string inputSection;
	std::vector<std::string> letters;
	std::vector<std::string> code;
	Binary_Tree<std::string> morseTree;
	BTNode<std::string>* root = new BTNode<std::string>("");
	BTNode<std::string>* currentNode;
	BTNode<std::string>* newNode;
};

