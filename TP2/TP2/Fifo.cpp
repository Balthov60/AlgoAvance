#pragma once
#include "stdafx.h"

#include "Fifo.h"


float Fifo::unstack() {
	Node temp = *out;

	if (out == in) {
		out = in = NULL;
	}
	else {
		out = out->getNext();
	}

	return temp.getValue();
}

void Fifo::display() {
	Node * temp = out;
	while (temp != NULL) {
		cout << temp->getValue() << " > ";
		temp = temp->getNext();
	}
	cout << endl;
}

void Fifo::invert() {
	Lifo lifo;

	display();
	
	while (!isEmpty()) {
		lifo.stack(unstack());
		cout << "value " << lifo.getHead().getValue() << " value" << endl;
		cout << "adress " << out << " " << in << " adress" << endl;
	}

	lifo.display();

	while (lifo.isEmpty()) {
		stack(lifo.unstack());
	}

	display();
}