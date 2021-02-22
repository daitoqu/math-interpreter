#pragma once

#include <memory>

enum TokenType {
	NUMBER,
	PLUS,
	MINUS,
	MUL,
	DIV,
	LPARENT,
	RPARENT
};

struct SToken {
	TokenType m_Type;
	std::unique_ptr<double> m_Val = nullptr;

	SToken(TokenType type, double val) : m_Type(type) {
		m_Val = std::make_unique<double>(val);
	};
	SToken(TokenType type) : m_Type(type) {};
};