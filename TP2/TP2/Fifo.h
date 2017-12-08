#pragma once
#include "stdafx.h"

#include "Lifo.h"
#include <iostream>

using namespace std;


class Fifo {

private:
	Node * in;
	Node * out;

public:
	Fifo() {
		in = out = NULL;
	}
	Fifo(int value) {
		in = out = new Node(value, NULL);
	}

	void stack(float value) {
		Node * temp = new Node(value, NULL);
		in->setNext(temp);
		in = temp;
	}
	float unstack();

	Node getHead() {
		return *out;
	}
	bool isEmpty() {
		return in == NULL && out == NULL;
	}

	void display();

	void invert();
};