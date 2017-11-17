#pragma once

#include <stdio.h>
#include <iostream>

#include "ChainedListEntry.h"
#include "stdafx.h"

using namespace std;


class ChainedList
{

private:
	ChainedListEntry * cursor;

public:
	ChainedList(int value) {
		this->cursor = new ChainedListEntry(NULL, NULL, value);
	};
	ChainedList(ChainedListEntry * entry) {
		cursor = entry;
	};
	ChainedList(int tab[], int size) {
		for (int i = 0; i < size; i++)
			appendAtEnd(new ChainedListEntry(tab[i]));
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

	void appendAt(int pos, ChainedListEntry * entry);
	void appendAtCurrentPos(ChainedListEntry * entry);
	void appendAtBegining(ChainedListEntry * entry);
	void appendAtEnd(ChainedListEntry * entry);

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

