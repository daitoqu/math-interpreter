#pragma once
#include <vector>
#include "SToken.h"
#include "Nodes.h"


class CParser {
private:
	std::vector<SToken>& m_Tokens;
	Node* m_ExecTree;
	std::vector<SToken>::iterator m_CurrentIter;

	Node* expr();
	Node* term();
	Node* factor();
public:
	CParser(std::vector<SToken>& tokens);
	~CParser();
	void parseTokens();
	double evaluateTree();
};