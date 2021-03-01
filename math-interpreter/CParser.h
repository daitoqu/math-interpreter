#pragma once
#include <vector>
#include "SToken.h"
#include "Nodes.h"


class CParser {
private:
	std::vector<SToken>& m_Tokens;
	std::shared_ptr<Node> m_ExecTree;
	std::vector<SToken>::iterator m_CurrentIter;
public:
	CParser(std::vector<SToken>& tokens);
	void parse();
	std::shared_ptr<Node> expr();
	std::shared_ptr<Node> term();
	std::shared_ptr<Node> factor();
};