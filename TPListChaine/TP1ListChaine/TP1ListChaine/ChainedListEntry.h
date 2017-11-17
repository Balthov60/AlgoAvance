#pragma once

class ChainedListEntry {

public:

	ChainedListEntry * previous;
	int value;
	ChainedListEntry * next;

	ChainedListEntry(ChainedListEntry * previous, ChainedListEntry * next, int value) {
		this->previous = previous;
		this->next = next;
		this->value = value;
	}

	ChainedListEntry(int value) {
		this->previous = NULL;
		this->next = NULL;
		this->value = value;
	}
};