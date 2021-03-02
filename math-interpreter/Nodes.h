#pragma once
#include <memory>
#include <iostream>

class Node {
public:
	virtual double Evaluate() = 0;
	virtual ~Node() {};
};

class BinaryNode : public Node {
protected:
	Node* m_Left;
	Node* m_Right;
public:
	BinaryNode(Node* left, Node* right) {
		m_Left = left;
		m_Right = right;
	}
	~BinaryNode() {
		delete m_Left;
		delete m_Right;
	}
};

class UnaryNode : public Node {
protected:
	Node* m_Right;
public:
	UnaryNode(Node* right) {
		m_Right = right;
	}
	~UnaryNode() {
		delete m_Right;
	}
};

class PlusNode : public UnaryNode {
public:
	PlusNode(Node* right) : UnaryNode(right) {};
	double Evaluate() {
		return m_Right->Evaluate();
	}
};

class MinusNode : public UnaryNode {
public:
	MinusNode(Node* right) : UnaryNode(right) {};
	double Evaluate() {
		return - m_Right->Evaluate();
	}
};

class NumberNode : public Node {
private:
	double m_Value;
public:
	NumberNode(double val) : m_Value(val) {};
	~NumberNode() {};
	double Evaluate() {
		return m_Value;
	}
};

class AddNode : public BinaryNode {
public:
	AddNode(Node* left, Node* right) : BinaryNode(left, right) {};
	double Evaluate() {
		return m_Left->Evaluate() + m_Right->Evaluate();
	}
};

class SubtractNode : public BinaryNode {
public:
	SubtractNode(Node* left, Node* right) : BinaryNode(left, right) {};
	double Evaluate() {
		return m_Left->Evaluate() - m_Right->Evaluate();
	}
};

class DivideNode : public BinaryNode {
public:
	DivideNode(Node* left, Node* right) : BinaryNode(left, right) {};
	double Evaluate() {
		return m_Left->Evaluate() / m_Right->Evaluate();
	}
};

class MutiplyNode : public BinaryNode {
public:
	MutiplyNode(Node* left, Node* right) : BinaryNode(left, right) {};
	double Evaluate() {
		return m_Left->Evaluate() * m_Right->Evaluate();
	}
};