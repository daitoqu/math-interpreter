#pragma once

#include <memory>

enum class TokenType {
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
	double m_Val;

	SToken(TokenType type, double val) : m_Type(type) {
		m_Val = val;
	};
	SToken(TokenType type) : m_Type(type) {};
};