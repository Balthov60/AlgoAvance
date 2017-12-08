#pragma once
#include "stdafx.h"

#include "Lifo.h"

using namespace std;


float Lifo::unstack() {
	Node temp = *head;

	head = head->getNext();
	
	return temp.getValue();
}

void Lifo::display() {
	Node * temp = head;
	while (temp != NULL) {
		cout << temp->getValue() << " > ";
		temp = temp->getNext();
	}
	cout << endl;
}
