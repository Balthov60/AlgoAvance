#pragma once

#include <stdio.h>
#include <iostream>

#include "stdafx.h"

using namespace std;


class ChainedList
{
	typedef struct ChainedListEntry {
		ChainedListEntry * previous;
		int value;
		ChainedListEntry * next;
	} ChainedListEntry;

	ChainedListEntry * initListEntry(ChainedListEntry * previous, ChainedListEntry * next, int value) {
		ChainedListEntry * entry = new ChainedListEntry;
		entry->previous = previous;
		entry->next = next;
		entry->value = value;

		return entry;
	}

private:
	ChainedListEntry * cursor;

public:
	ChainedList(int value) {
		this->cursor = initListEntry(NULL, NULL, value);
	};

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

	void goToNextEntry();
	void goToPreviousEntry();

	friend ostream & operator<<(ostream & stream, ChainedList chainedList);
};

