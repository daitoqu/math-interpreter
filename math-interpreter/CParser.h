#pragma once
#include <vector>
#include "SToken.h"
#include "Nodes.h"


class CParser {
private:
	std::vector<SToken>& m_Tokens;
	Node* m_ExecTree;
	std::vector<SToken>::iterator m_CurrentIter;
public:
	CParser(std::vector<SToken>& tokens);
	void parse();
	Node* expr();
	Node* term();
	Node* factor();
};