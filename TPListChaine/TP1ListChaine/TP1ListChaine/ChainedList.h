#pragma once

#include <stdio.h>
#include <iostream>

#include "Node.h"
#include "stdafx.h"

using namespace std;


class ChainedList
{

private:
	Node * cursor;

public:
	ChainedList(int value) {
		this->cursor = new Node(NULL, NULL, value);
	};
	ChainedList(Node * entry) {
		cursor = entry;
	};
	ChainedList(int tab[], int size) {
		for (int i = 0; i < size; i++)
			appendAtBegining(new Node(tab[i]));
	};

	ChainedList duplicate();
	void concat(ChainedList * list);
	void sort();

	bool isAtBegining() {
		return (cursor->previous == NULL);
	}
	bool isAtEnd() {
		return (cursor->next == NULL);
	}
	bool isEmpty() {
		return (cursor == NULL);
	}

	int size();
	int sizeToEnd();
	int sizeToBegining();

	void setAtBegining();
	void setAtEnd();

	void appendAt(int pos, Node * entry);
	void appendAtCurrentPos(Node * entry);
	void appendAtBegining(Node * entry);
	void appendAtEnd(Node * entry);

	void removeEntryMatching(int value);
	void remove(int pos);
	void removeCurrent();
	void removeLast();
	void removeFirst();

	void swapWithPrecedent();

	void goToNextEntry();
	void goToPreviousEntry();
	void goTo(int pos);

	friend ostream & operator<<(ostream & stream, ChainedList chainedList);
	bool operator==(ChainedList chainedList);
};

