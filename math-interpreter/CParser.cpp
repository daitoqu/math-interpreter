#include "CParser.h"

CParser::CParser(std::vector<SToken>& tokens) : m_Tokens(tokens)
{
	m_CurrentIter = m_Tokens.begin();
}

void CParser::parse()
{
	m_ExecTree = this->expr();
}

std::shared_ptr<Node> CParser::expr()
{
	std::shared_ptr<Node> result = this->term();

	while (m_CurrentIter != m_Tokens.end() && (m_CurrentIter->m_Type == TokenType::PLUS || m_CurrentIter->m_Type == TokenType::MINUS)) {
		if (m_CurrentIter->m_Type == TokenType::PLUS) {
			m_CurrentIter++;
			result = std::make_shared<AddNode>(
				new AddNode(result, this->term())
			);
		}
		else if (m_CurrentIter->m_Type == TokenType::MINUS) {
			m_CurrentIter++;
			result = std::make_shared<SubtractNode>(
				new SubtractNode(result, this->term())
			);
		}
	}

	return result;
}

std::shared_ptr<Node> CParser::term()
{
	std::shared_ptr<Node> result = this->factor();

	while (m_CurrentIter != m_Tokens.end() && (m_CurrentIter->m_Type == TokenType::MUL || m_CurrentIter->m_Type == TokenType::DIV)) {
		if (m_CurrentIter->m_Type == TokenType::MUL) {
			m_CurrentIter++;
			result = std::make_shared<MutiplyNode>(
				new MutiplyNode(result, this->factor())
			);
		}
		else if (m_CurrentIter->m_Type == TokenType::DIV) {
			m_CurrentIter++;
			result = std::make_shared<DivideNode>(
				new DivideNode(result, this->factor())
			);
		}
	}

	return result;
}

std::shared_ptr<Node> CParser::factor() {
	SToken token = *m_CurrentIter;

	if (token.m_Type == TokenType::NUMBER) {
		m_CurrentIter++;
		return std::make_shared<NumberNode>(new NumberNode(token.m_Val));
	}
}
