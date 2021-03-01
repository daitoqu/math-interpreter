#pragma once
#include <memory>

class Node {
public:
	virtual double Evaluate() = 0;
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
};

class UnaryNode : public Node {
protected:
	std::shared_ptr<Node> m_Right;
public:
	UnaryNode(std::shared_ptr<Node> right) {
		m_Right = right;
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