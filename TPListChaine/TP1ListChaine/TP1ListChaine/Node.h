#pragma once
#include <stdio.h>

class Node {

public:

	Node * previous;
	Node * next;
	int value;

	Node(Node * previous, Node * next, int value) {
		this->previous = previous;
		this->next = next;
		this->value = value;
	}

	Node(int value) {
		this->previous = NULL;
		this->next = NULL;
		this->value = value;
	}
};