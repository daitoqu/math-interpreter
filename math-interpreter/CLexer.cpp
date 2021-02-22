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
			m_TknExpression.push_back(SToken(NUMBER, numVal));
			continue;
		}
		else if (m_StrExpression[0] == '+') {
			m_TknExpression.push_back(SToken(PLUS));
		}
		else if (m_StrExpression[0] == '-') {
			m_TknExpression.push_back(SToken(MINUS));
		}
		else if (m_StrExpression[0] == '*') {
			m_TknExpression.push_back(SToken(MUL));
		}
		else if (m_StrExpression[0] == '/') {
			m_TknExpression.push_back(SToken(DIV));
		}
		else if (m_StrExpression[0] == '(') {
			m_TknExpression.push_back(SToken(LPARENT));
		}
		else if (m_StrExpression[0] == ')') {
			m_TknExpression.push_back(SToken(RPARENT));
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
