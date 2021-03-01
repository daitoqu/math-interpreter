#pragma once
#include <memory>

class Node {
public:
	virtual double Evaluate() = 0;
};

class BinaryNode : public Node {
protected:
	std::unique_ptr<Node> m_Left;
	std::unique_ptr<Node> m_Right;
public:
	BinaryNode(Node* left, Node* right) {
		m_Left = std::make_unique<Node>(left);
		m_Right = std::make_unique<Node>(right);
	}
};

class UnaryNode : public Node {
protected:
	std::unique_ptr<Node> m_Right;
public:
	UnaryNode(Node* right) {
		m_Right = std::make_unique<Node>(right);
	}
};

class NumberNode : public Node {
private:
	double m_Value;
public:
	NumberNode(double val) : m_Value(val) {};
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
	SubtractNode(Node* left, Node* right) : BinaryNode(left, right) {};
	double Evaluate() {
		return m_Left->Evaluate() - m_Right->Evaluate();
	}
};

class DivideNode : public BinaryNode {
	DivideNode(Node* left, Node* right) : BinaryNode(left, right) {};
	double Evaluate() {
		return m_Left->Evaluate() / m_Right->Evaluate();
	}
};

class MutiplyNode : public BinaryNode {
	MutiplyNode(Node* left, Node* right) : BinaryNode(left, right) {};
	double Evaluate() {
		return m_Left->Evaluate() * m_Right->Evaluate();
	}
};