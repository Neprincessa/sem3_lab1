#include <iostream>
#include "Header.h"
#include "Templ.h"


bool checkDataType(char *ptr) {
	bool isd = true;
	int flag = 0;
	if (*ptr == '-') {
		flag = 1;
		*ptr = *(ptr++);
	}

	while (*ptr)
		if (!isdigit(*ptr++))
		{
			isd = false;
			break;
		}

	if (!isd)
		cout << "Fill in  integer, not a string or a double number" << endl;
	return isd;
}

int setAmount() {
	int amount = 0;
	char s[256];
	char *p = s;

	cout << "Fill in the amount of elements" << endl;
	cin >> s;

	while (!checkDataType(p))
		cin >> s;
	amount = atoi(s);
	while (amount < 0) {
		cout << "Fill in the positive number" << endl;
		cin >> s;
		while (!checkDataType(p))
			cin >> s;
		amount = atoi(s);
	}

	return amount;
}

int typeOfDataOfSeq() {
	int typeData;
	char s[256];
	char *p = s;

	cout << "Do you want to work with int or double?" << endl;
	cout << "If you want to work with int, press 1" << endl;
	cout << "If you want to work with double, press 2" << endl;

	cin >> s;
	while (!checkDataType(p))
		cin >> s;
	typeData = atoi(s);
	while (typeData < 1 || typeData >2) {
		cout << "Fill in the number 1 or 2" << endl;
		cin >> s;
		while (!checkDataType(p))
			cin >> s;
		typeData = atoi(s);
	}
	return typeData;
}

int whatFunc() {
	int typeOfFunction;

	cout << "If you want to end work, press 0" << endl;
	cout << "If you want to append element, press 1" << endl;
	cout << "If you want to prepend element, press 2" << endl;
	cout << "If you want to get amount of elements, press 3" << endl;
	cout << "If you want to get first element, press 4" << endl;
	cout << "If you want to get last element, press 5" << endl;
	cout << "If you want to get element by index, press 6" << endl;
	cout << "If you want to verify that the sequence is empty or not, press 7" << endl;
	cout << "If you want to insert element at definite position, press 8" << endl;
	cout << "If you want to remove element, press 9" << endl;
	cout << "If you want tot get a sub sequence, press 10" << endl;
	cout << "If you want to see the whole sequence, press 20" << endl;
	cout << "If you want to switch TEST mode, press 30" << endl;
	cout << "If you want to set the sequence with random numbers, press 40" << endl;
	cout << "If you want to add current amount of elements, press 50" << endl;

	char s[256];
	char *p = s;
	cin >> s;
	while (!checkDataType(p))
		cin >> s;
	typeOfFunction = atoi(s);
	while (typeOfFunction < 0 || typeOfFunction > 10 && typeOfFunction != 20 && typeOfFunction != 30 && typeOfFunction != 40 && typeOfFunction != 50) {
		cout << "Fill in the number from 0 to 10, 20,30, 40 or 50" << endl;
		cin >> s;
		while (!checkDataType(p))
			cin >> s;
		typeOfFunction = atoi(s);
	}
	return typeOfFunction;
}

//in separate func the diap
int typeOfSequence() {
	cout << "If you want to work with array, press 1" << endl;
	cout << "If you want to work with list, press 2" << endl;
	char s[256];
	char *p = s;
	cin >> s;
	while (!checkDataType(p))
		cin >> s;
	int curSeq = atoi(s);
	while (curSeq < 1 || curSeq > 2) {
		cout << "Fill in the number 1 or 2" << endl;
		cin >> s;
		while (!checkDataType(p))
			cin >> s;
		curSeq = atoi(s);
	}

	return curSeq;
}

int chooseStep(int limit, int size) {
	cout << "Input the step of shell sort less than " << limit << endl;
	char s[256];
	char *p = s;
	cin >> s;
	while (!checkDataType(p))
		cin >> s;
	int result = atoi(s);
	while (result >= limit) {
		cout << "Input the element less than " << limit <<endl;
		cin >> s;
		while (!checkDataType(p))
			cin >> s;
		result = atoi(s);
	}
	return result;
}
int chooseforFirstIteration_ShellSort(int size) {
	int result;

	cout << "Input the step of shell sort less than " << size << endl;
	char s[256];
	char *p = s;
	cin >> s;
	while (!checkDataType(p))
		cin >> s;
	result = atoi(s);
	while (result > size || result < 0) {
		cout << "Input the positive number less than " << size << endl;
		cin >> s;
		while (!checkDataType(p))
			cin >> s;
		result = atoi(s);
	}
	
	return result;

}