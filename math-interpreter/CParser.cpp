#include "CParser.h"

CParser::CParser(std::vector<SToken>& tokens) : m_Tokens(tokens)
{
	m_CurrentIter = m_Tokens.begin();
}

void CParser::parse()
{
	m_ExecTree = this->expr();
}

Node* CParser::expr()
{
	Node* result = this->term();

	while (m_CurrentIter != m_Tokens.end() && (m_CurrentIter->m_Type == TokenType::PLUS || m_CurrentIter->m_Type == TokenType::MINUS)) {
		if (m_CurrentIter->m_Type == TokenType::PLUS) {
			m_CurrentIter++;
			result = new AddNode(result, this->term());
		}
		else if (m_CurrentIter->m_Type == TokenType::MINUS) {
			m_CurrentIter++;
			result = new SubtractNode(result, this->term());
		}
	}

	return result;
}

Node* CParser::term()
{
	Node* result = this->factor();

	while (m_CurrentIter != m_Tokens.end() && (m_CurrentIter->m_Type == TokenType::MUL || m_CurrentIter->m_Type == TokenType::DIV)) {
		if (m_CurrentIter->m_Type == TokenType::MUL) {
			m_CurrentIter++;
			result = new MutiplyNode(result, this->factor());
		}
		else if (m_CurrentIter->m_Type == TokenType::DIV) {
			m_CurrentIter++;
			result = new DivideNode(result, this->factor());
		}
	}

	return result;
}

Node* CParser::factor() {
	SToken token = *m_CurrentIter;

	if (token.m_Type == TokenType::NUMBER) {
		m_CurrentIter++;
		return new NumberNode(token.m_Val);
	}
	else if (token.m_Type == TokenType::MINUS) {
		m_CurrentIter++;
		return new MinusNode(this->factor());
	}
	else if (token.m_Type == TokenType::PLUS) {
		m_CurrentIter++;
		return new PlusNode(this->factor());
	}
	else if (token.m_Type == TokenType::LPARENT) {
		m_CurrentIter++;
		Node* result = this->expr();
		if (m_CurrentIter->m_Type != TokenType::RPARENT) {
			//Error
		}
		m_CurrentIter++;
		return result;
	}
}

Node* CParser::getTree()
{
	return m_ExecTree;
}
