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
	int size = 1;
	ChainedListEntry * saveCursor = this->cursor;

	while (!isAtEnd()) {
		size++;
		goToNextEntry();
	}

	this->cursor = saveCursor;
	return size;
}
int ChainedList::sizeToBegining() {
	int size = 1;
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
void ChainedList::goTo(int pos) {
	int sizeToBegining = this->sizeToBegining();

	if (pos < sizeToBegining) {
		for (int i = 0; i < sizeToBegining - pos; i++) {
			goToPreviousEntry();
		}
	}
	else if (pos == sizeToBegining) {
		return;
	}
	else {
		int current = sizeToBegining;
		while (current != pos) {
			goToNextEntry();
			current++;
		}
	}
}

void ChainedList::appendAt(int pos, ChainedListEntry * entry) {
	if (pos <= 1) {
		appendAtBegining(entry);
		return;
	}
	else if (pos >= size()) {
		appendAtEnd(entry);
		return;
	}

	goTo(pos);
	appendAtCurrentPos(entry);
}
void ChainedList::appendAtCurrentPos(ChainedListEntry * entry) {
	ChainedListEntry * next = cursor;
	goToPreviousEntry();
	ChainedListEntry * previous = cursor;

	next->previous = entry;
	entry->next = next;
	entry->previous = previous;
	previous->next = entry;

	goToNextEntry();
}
void ChainedList::appendAtBegining(ChainedListEntry * entry) {
	setAtBegining();
	entry->previous = NULL;
	entry->next = cursor;
	cursor->previous = entry;
}
void ChainedList::appendAtEnd(ChainedListEntry * entry) {
	setAtEnd();
	entry->next = NULL;
	entry->previous = cursor;
	cursor->next = entry;
}

void ChainedList::removeEntryMatching(int value) 
{
	setAtBegining();

	while (!isAtEnd()) {
		if (cursor->value == value) {
			removeCurrent();
		}
		goToNextEntry();
	}
	if (cursor->value == value) {
		removeCurrent();
	}
}
void ChainedList::remove(int pos) {
	if (pos <= 1) {
		removeFirst();
		return;
	}
	else if (pos >= size()) {
		removeLast();
		return;
	}

	goTo(pos);
	removeCurrent();
}
void ChainedList::removeCurrent() {
	if (sizeToBegining() <= 1) {
		removeFirst();
		return;
	}
	else if (sizeToEnd() <= 1) {
		removeLast();
		return;
	}
	goToNextEntry();
	ChainedListEntry * next = cursor;
	goToPreviousEntry();
	goToPreviousEntry();

	delete cursor->next;
	cursor->next = next;
	next->previous = cursor;
}
void ChainedList::removeFirst() {
	setAtBegining();
	goToNextEntry();

	delete cursor->previous;
	cursor->previous = NULL;
}
void ChainedList::removeLast() 
{
	setAtEnd();
	goToPreviousEntry();

	delete cursor->next;
	cursor->next = NULL;
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