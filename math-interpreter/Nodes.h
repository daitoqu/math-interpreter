#pragma once
#include <memory>

class Node {
public:
	virtual double Evaluate() = 0;
};

class BinaryNode : public Node {
protected:
	std::shared_ptr<Node> m_Left;
	std::shared_ptr<Node> m_Right;
public:
	BinaryNode(std::shared_ptr<Node> left, std::shared_ptr<Node> right) {
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
	AddNode(std::shared_ptr<Node> left, std::shared_ptr<Node> right) : BinaryNode(left, right) {};
	double Evaluate() {
		return m_Left->Evaluate() + m_Right->Evaluate();
	}
};

class SubtractNode : public BinaryNode {
public:
	SubtractNode(std::shared_ptr<Node> left, std::shared_ptr<Node> right) : BinaryNode(left, right) {};
	double Evaluate() {
		return m_Left->Evaluate() - m_Right->Evaluate();
	}
};

class DivideNode : public BinaryNode {
public:
	DivideNode(std::shared_ptr<Node> left, std::shared_ptr<Node> right) : BinaryNode(left, right) {};
	double Evaluate() {
		return m_Left->Evaluate() / m_Right->Evaluate();
	}
};

class MutiplyNode : public BinaryNode {
public:
	MutiplyNode(std::shared_ptr<Node> left, std::shared_ptr<Node> right) : BinaryNode(left, right) {};
	double Evaluate() {
		return m_Left->Evaluate() * m_Right->Evaluate();
	}
};