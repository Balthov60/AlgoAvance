#pragma once
#include "stdafx.h"
#include "ChainedList.h"

using namespace std;


int main()
{
	
	/* Testing Chained List Class */
	/*
	ChainedList list(5);
	list.appendAtBegining(new Node(NULL, NULL, 4));
	list.appendAtBegining(new Node(NULL, NULL, 4));
	list.appendAtBegining(new Node(NULL, NULL, 2));
	list.appendAtBegining(new Node(NULL, NULL, 4));

	cout << list;

	ChainedList list2 = list.duplicate();
	list.removeEntryMatching(2);
	
	cout << list;
	cout << list2;

	list.concat(&list2);

	cout << list;
	cout << list2;

	list.sort();

	cout << list;

	list2 = list.duplicate();

	if (list2 == list)
		cout << "equals";

		*/

	ChainedList list(5);
	list.appendAtBegining(new Node(NULL, NULL, 4));
	list.appendAtBegining(new Node(NULL, NULL, 4));
	list.appendAtBegining(new Node(NULL, NULL, 2));
	list.appendAtBegining(new Node(NULL, NULL, 4));

	cout << list.size() << endl;
	cout << list;
	return 0;
}



