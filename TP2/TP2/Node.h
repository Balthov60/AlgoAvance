#pragma once
#include "stdafx.h"


class Node {
	
private:
	int value;
	Node * next;

public:
	Node(float value) {
		this->value = value;
		this->next = NULL;
	}

	Node(float value, Node * next) {
		this->value = value;
		this->next = next;
	}

	float getValue() {
		return value;
	}
	Node * getNext() {
		return next;
	}
	void setNext(Node * node) {
		next = node;
	}
};