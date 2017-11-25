#pragma once
#include "stdafx.h"
#include "ChainedList.h"


ChainedList ChainedList::duplicate() {
	setAtBegining();
	ChainedList duplicatedList(cursor->value);
	
	while (!isAtEnd()) {
		goToNextEntry();
		duplicatedList.appendAtEnd(new Node(duplicatedList.cursor, NULL, cursor->value));
		duplicatedList.goToNextEntry();
	}

	return duplicatedList;
}

void ChainedList::concat(ChainedList * list) {
	setAtEnd();
	list->setAtBegining();

	cursor->next = list->cursor;
	list->cursor->previous = cursor;
}
void ChainedList::sort() {
	int size = this->size();
	if (size <= 1)
		return;

	bool flag = true;
	while (flag) {
		flag = false;
		goTo(2);

		while (!isAtEnd()) {
			if (cursor->previous->value > cursor->value) {
				swapWithPrecedent();
				flag = true;
			}
			goToNextEntry();
		}
	}
}
 
int ChainedList::size() {
	setAtBegining();
	return sizeToEnd();
}
int ChainedList::sizeToEnd() {
	int size = 1;
	Node * saveCursor = this->cursor;

	while (!isAtEnd()) {
		size++;
		goToNextEntry();
	}

	this->cursor = saveCursor;
	return size;
}
int ChainedList::sizeToBegining() {
	int size = 1;
	Node * saveCursor = this->cursor;

	while (!isAtBegining()) {
		size++;
		goToPreviousEntry();
	}

	this->cursor = saveCursor;
	return size;
}

void ChainedList::swapWithPrecedent() {
	if (sizeToBegining() < 2) {
		return;
	}

	Node * temp = cursor->previous;

	// Handling Outside Values;
	if (temp->previous != NULL)
		temp->previous->next = cursor;
	if (cursor->next != NULL)
		cursor->next->previous = temp;

	temp->next = cursor->next;
	cursor->next = temp;
	cursor->previous = temp->previous;
	temp->previous = cursor;
}

void ChainedList::goToNextEntry() {
	cursor = cursor->next;
}
void ChainedList::goToPreviousEntry() {
	cursor = cursor->previous;
}
void ChainedList::goTo(int pos) {
	int sizeToBegining = this->sizeToBegining();

	if (pos == sizeToBegining) {
		return;
	}
	else if (pos < sizeToBegining) {
		for (int i = 0; i < sizeToBegining - pos; i++) {
			goToPreviousEntry();
		}
	}
	else {
		int current = sizeToBegining;
		while (current != pos) {
			goToNextEntry();
			current++;
		}
	}
}

void ChainedList::appendAt(int pos, Node * entry) {
	if (pos <= 1) {
		appendAtBegining(entry);
	}
	else if (pos >= size()) {
		appendAtEnd(entry);
	}
	else {
		goTo(pos);
		appendAtCurrentPos(entry);
	}
}
void ChainedList::appendAtCurrentPos(Node * entry) {
	Node * next = cursor;
	Node * previous = cursor->previous;

	next->previous = entry;
	entry->next = next;
	entry->previous = previous;
	previous->next = entry;
}
void ChainedList::appendAtBegining(Node * entry) {
	setAtBegining();
	entry->previous = NULL;
	entry->next = cursor;
	cursor->previous = entry;
}
void ChainedList::appendAtEnd(Node * entry) {
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
	}
	else if (pos >= size()) {
		removeLast();
	}
	else {
		goTo(pos);
		removeCurrent();
	}
}
void ChainedList::removeCurrent() {
	if (sizeToBegining() <= 1) {
		removeFirst();
	}
	else if (sizeToEnd() <= 1) {
		removeLast();
	}
	else {
		Node * next = cursor->next;

		goToPreviousEntry();
		delete cursor->next;

		cursor->next = next;
		next->previous = cursor;
	}
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

bool ChainedList::operator==(ChainedList chainedList) {
	if (this->size() != chainedList.size())
		return false;

	this->setAtBegining();
	chainedList.setAtBegining();
	
	if (this->cursor->value != chainedList.cursor->value)
		return false;

	while (this->isAtEnd()) {
		this->goToNextEntry();
		chainedList.goToNextEntry();

		if (this->cursor->value != chainedList.cursor->value)
			return false;
	}

	return true;
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