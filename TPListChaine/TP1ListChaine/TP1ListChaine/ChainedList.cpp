#pragma once
#include "stdafx.h"
#include "ChainedList.h"


int ChainedList::size() {
	int size = 0;
	ChainedListEntry * saveCursor = this->cursor;
	setAtBegining();

	while (!isAtEnd()) {
		size++;
		goToNextEntry();
	}
	size++;

	this->cursor = saveCursor;
	return size;
}
int ChainedList::sizeToEnd() {
	int size = 0;
	ChainedListEntry * saveCursor = this->cursor;

	while (!isAtEnd()) {
		size++;
		goToNextEntry();
	}

	this->cursor = saveCursor;
	return size;
}
int ChainedList::sizeToBegining() {
	int size = 0;
	ChainedListEntry * saveCursor = this->cursor;

	while (!isAtBegining()) {
		size++;
		goToPreviousEntry();
	}

	this->cursor = saveCursor;
	return size;
}

void ChainedList::goToNextEntry() {
	cursor = cursor->next;
}
void ChainedList::goToPreviousEntry() {
	cursor = cursor->previous;
}

void ChainedList::setAtBegining() {
	while (!isAtBegining()) {
		goToPreviousEntry();
	}
}
void ChainedList::setAtEnd() {
	while (!isAtEnd()) {
		goToNextEntry();
	}
}

ostream & operator<<(ostream & stream, ChainedList chainedList) {
	chainedList.setAtBegining();
	
	while (!chainedList.isAtEnd()) {
		stream << chainedList.cursor->value << ", ";
		chainedList.goToNextEntry();
	}
	stream << chainedList.cursor->value << endl;
	
	return stream;
}