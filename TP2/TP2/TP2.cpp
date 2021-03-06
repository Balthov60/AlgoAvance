#pragma once
#include "stdafx.h"

#include "Lifo.h"
#include "Fifo.h"

#include <iostream>
#include <string>

using namespace std;

float calculatrice();
bool isNumber(char entry);
bool isOperator(char entry);
float makeOperation(float first, float second, char op);

int main() {

	cout << calculatrice();

	return 0;
}

float calculatrice() {
	char entry[2];
	string expression = "";

	Lifo numbers = Lifo();

	while (1) {
		cout << "Entrer un nombre ou un opérateur : ";
		cin.getline(entry, 2);

		cout << (int)entry[0] << endl;

		if (entry[0] == '\0') {
			cout << expression << endl;
			return numbers.unstack();
		}
		if (entry[1] != '\0') {
			continue;
		}

		expression += entry;

		if (isNumber(entry[0])) {
			cout << "number" << endl;
			numbers.stack(entry[0] - 48);
		}
		else if (isOperator(entry[0])) {
			if (numbers.isEmpty()) {
				cout << "Mauvaise syntaxte" << endl;
				return 0;
			}
			float temp = numbers.unstack();

			if (numbers.isEmpty()) {
				cout << "Mauvaise syntaxte" << endl;
				return 0;
			}
			float temp2 = numbers.unstack();

			numbers.stack(makeOperation(temp, temp2, entry[0]));
		}
	}
}
bool isNumber(char entry) {
	return (entry >= 48 && entry <= 57);
}
bool isOperator(char entry) {
	return (entry == 42 || entry == 43 || entry == 45 || entry == 47);
}
float makeOperation(float first, float second, char op) {
	switch (op) {
	case 42:
		return first * second;

	case 43:
		return first + second;

	case 45:
		return first - second;

	case 47:
		return first / second;
	}
}