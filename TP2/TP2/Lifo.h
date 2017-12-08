#pragma once
#include "stdafx.h"

#include "Node.h"
#include <iostream>


class Lifo {

private:
	Node * head;

public:
	Lifo() {
		head = NULL;
	}
	Lifo(Node * node) {
		head = node;
	}

	void stack(float value) {
		head = new Node(value, head);
	}
	float unstack();

	Node getHead() {
		return *head;
	}
	bool isEmpty() {
		return head == NULL;
	}

	void display();
};