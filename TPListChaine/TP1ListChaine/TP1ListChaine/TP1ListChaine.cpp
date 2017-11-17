#pragma once
#include "stdafx.h"
#include "ChainedList.h"

using namespace std;


int main()
{
	ChainedList list(5);
	list.appendAtBegining(new ChainedListEntry(NULL, NULL, 4));

	list.appendAtBegining(new ChainedListEntry(NULL, NULL, 4));

	list.appendAtBegining(new ChainedListEntry(NULL, NULL, 2));

	list.appendAtBegining(new ChainedListEntry(NULL, NULL, 4));
	cout << list;

	list.removeEntryMatching(2);
	cout << list;

	return 0;
}



