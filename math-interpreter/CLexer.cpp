#include "CLexer.h"
#include <cctype>

CLexer::CLexer(std::string& input) : m_StrExpression(input)
{
}

void CLexer::parseExpression()
{
	while (!m_StrExpression.empty()) {
		if (m_StrExpression[0] == '.' || isdigit(m_StrExpression[0])) {
			size_t numEnd;
			double numVal = std::stod(m_StrExpression, &numEnd);
			m_StrExpression = m_StrExpression.substr(numEnd);
			m_TknExpression.push_back(SToken(TokenType::NUMBER, numVal));
			continue;
		}
		else if (m_StrExpression[0] == '+') {
			m_TknExpression.push_back(SToken(TokenType::PLUS));
		}
		else if (m_StrExpression[0] == '-') {
			m_TknExpression.push_back(SToken(TokenType::MINUS));
		}
		else if (m_StrExpression[0] == '*') {
			m_TknExpression.push_back(SToken(TokenType::MUL));
		}
		else if (m_StrExpression[0] == '/') {
			m_TknExpression.push_back(SToken(TokenType::DIV));
		}
		else if (m_StrExpression[0] == '(') {
			m_TknExpression.push_back(SToken(TokenType::LPARENT));
		}
		else if (m_StrExpression[0] == ')') {
			m_TknExpression.push_back(SToken(TokenType::RPARENT));
		}
		else if (m_StrExpression[0] == ' ') {
		}
		else {
			//Unsupported sym
		}
		m_StrExpression.erase(0, 1);
	}
}

const std::vector<SToken>& CLexer::getTokens()
{
	return m_TknExpression;
}
