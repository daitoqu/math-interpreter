#pragma once
#include <string>
#include <vector>
#include "SToken.h"

class CLexer {
	std::string m_StrExpression;
	std::vector<SToken> m_TknExpression;

public:
	CLexer(std::string& input);
	void parseExpression();
	const std::vector<SToken>& getTokens();
};