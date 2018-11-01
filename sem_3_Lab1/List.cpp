#include <iostream>
#include "Header.h"
#include "templ.h"
#include "ExceptionsForList.h"
#include <time.h>
TypeError CurrentError::getReason(int typeFunc, int start, int end, int len) const throw() {
	//typeFunc = 1 - get, 2 - insert, 3 - getSub
	//hoe in func
	//indexex must be not--!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if (typeFunc == 1) {
		if (start < 1)
			return NEGATIVE_INDEX;
		if (start > len)
			return OVER_DIAPASON_INDEX;
		if (start >= 1 && start <= len)
			return NORMAL_STATE;
	}
	if (typeFunc == 2) {
		if (start < 0)
			return NEGATIVE_INDEX;
		else
			if (start > len)
				return OVER_DIAPASON_INDEX;
			else
			{
				if (end < start)
					return INCORRECT_END_INDEX;
				if (end > len)
					return OVER_DIAPASON_INDEX;
				if (end >= start && end <= len)
					return NORMAL_STATE;
			}

	}
}

const char* CurrentError::ToString(TypeError v) {
	switch (v)
	{
	case NEGATIVE_INDEX:
	{
		return "NEGATIVE_INDEX";
		break;
	}
	case OVER_DIAPASON_INDEX: {
		return "OVER_DIAPASON_INDEX";
		break;
	}
	case INCORRECT_END_INDEX: {
		return "INCORRECT_END_INDEX";
		break;
	}
	case NORMAL_STATE:
	{
		return "NORMAL_STATE";
		break;
	}
	default:
		break;
	}
}

void IntListSeq() {

	char s[256];
	char *p = s;

	ListSequence<int> myList;

	int number, element;
	int definiteFunc = -1;

	while (definiteFunc != 0) {

		definiteFunc = myList.chooseFunction();

		switch (definiteFunc)
		{
		case 0: {
			break;
		}
		case 1: {

			cout << "Fill in the number that you whant to append:" << endl;
			cin >> s;
			//only for int!!!!!
			while (!checkDataType(p))
				cin >> s;
			element = atoi(s);

			myList.Append(element);

			cout << "\n";
			break;
		}
		case 2: {

			cout << "Fill in the number that you whant to prepand:" << endl;
			cin >> s;
			while (!checkDataType(p)) // another check for double
				cin >> s;
			int a = atoi(s);

			myList.Prepend(a);

			cout << "\n";
			break;
		}
		case 3: {

			cout << "The amount of elements is: ";

			cout << myList.getLength() << endl;

			cout << "\n";
			break;
		}
		case 4: {
			myList.GetFirst();
			cout << "\n";
			break;
		}
		case 5: {
			myList.GetLast();
			cout << "\n";
			break;
		}
		case 6: {

			cout << "Fill in the number of element that you whant to get " << endl;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			number = atoi(s);

			/*while (number<0 || number > myList.getLength()) {
			cout << "Fill in the number from 1 to ";
			cout << myList.getLength() << " ";
			cin >> s;
			while (!checkDataType(p))
			cin >> s;
			number = atoi(s);
			}*/
			/*while (ind<0 || ind > myArr.getLength()) {
			cout << "Fill in the number from 1 to ";
			cout << myArr.getLength() << " ";
			cin >> s;
			while (!checkDataType(p))
			cin >> s;
			ind = atoi(s);
			}*/
			try
			{
				throw myEr;
			}
			catch (CurrentError& e)
			{
				if (e.what(1, number, number, myList.getLength()) == "NORMAL_STATE")
					int r = 0;
				else
				{
					cout << e.what(1, number, number, myList.getLength()) << endl;
					number = -1;
				}

			}
			if (number != -1)
				myList.Get(number);
			else
				cout << "You can't get an element" << endl;

			break;
		}
		case 7: {

			cout << "Is empty sequence?" << endl;

			if (myList.getIsEmpty() == 0)
				cout << "No" << endl;
			else
				cout << "Yes" << endl;
			cout << "\n";
			break;
		}
		case 8: {


			cout << "Fill in the item" << endl;
			int item;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			item = atoi(s);

			cout << "Insert element at number: " << endl;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			int indexForInsert = atoi(s);

			/*while (indexForInsert < 0 || indexForInsert>myArr.getLength()) {
			cout << "Fill in the number from 1 to ";
			cout << myArr.getLength() << endl;
			cin >> s;
			while (!checkDataType(p))
			cin >> s;
			}*/
			try
			{
				throw myEr;
			}
			catch (CurrentError& e)
			{
				if (e.what(1, indexForInsert, indexForInsert, myList.getLength()) == "NORMAL_STATE")
					int r = 0;
				else
				{
					cout << e.what(1, indexForInsert, indexForInsert, myList.getLength()) << endl;
					item = -8888;
				}

			}
			myList.InsertAt(indexForInsert, item);

			cout << "\n";
			break;
		}
		case 9: {

			cout << "Fill in the number to remove" << endl;
			int removeElement;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			removeElement = atoi(s);

			myList.Remove(removeElement);

			cout << "\n";
			break;
		}
		case 10: {

			int start, end;

			if (myList.getIsEmpty() != 1) {
				cout << "Fill in the start index of new sequence" << endl;
				cin >> s;
				while (!checkDataType(p))
					cin >> s;
				start = atoi(s);

				/*while (start< 0 || start > myArr.getLength() - 1) {
				cout << "Fill in number from 1 to ";
				cout << myArr.getLength() << endl;
				cin >> s;
				while (!checkDataType(p))
				cin >> s;
				start = atoi(s) - 1;
				}*/
				try
				{
					throw myEr;
				}
				catch (CurrentError& e)
				{
					if (e.what(1, start, end, myList.getLength()) == "NORMAL_STATE")
						int r = 1;
					else
					{
						cout << e.what(1, start, end, myList.getLength()) << endl;
						start = -1;
					}
				}
				if (start != -1) {
					start--;

					if (start == myList.getLength() - 1)
						end = myList.getLength() - 1;
					else {
						cout << "Fill in the end index of new sequence" << endl;
						cin >> s;
						while (!checkDataType(p))
							cin >> s;
						end = atoi(s);

						try
						{
							throw myEr;
						}
						catch (CurrentError& e)
						{
							if (e.what(2, start, end, myList.getLength()) == "NORMAL_STATE")
								int r = 0;
							else {
								cout << e.what(2, start, end, myList.getLength()) << endl;
								end = -1;
							}
						}

						/*		while (end<start || end>myArr.getLength() - 1) {
						cout << "Fill in the number from ";
						cout << start + 1;
						cout << " to ";
						cout << myArr.getLength();
						cout << "\n";
						cin >> s;
						while (!checkDataType(p))
						cin >> s;
						end = atoi(s) - 1;
						}*/
					}
				}

				if (end != -1)
				{
					end--;
					myList.GetSubSequence(start, end).Display();
				}

				else
					cout << "You cann't get a sub sequence" << endl;
			}

			else {
				cout << "You cann't get a sub seq from the empty seq" << endl;
				cout << "\n";
			}

			break;
		}
		case 20: {
			myList.Display();
			cout << "\n";
			break;
		}
		case 30: {
			ListSequence<int> testList;
			// {85,36,2,0,-89,4,-7,777,15}
			testList.Append(85);
			testList.Append(36);
			testList.Append(2);
			testList.Append(0);
			testList.Append(-89);
			testList.Append(4);
			testList.Append(-7);
			testList.Append(777);
			testList.Append(15);

			testList.InsertSort();
			int *arr = new int[9];
			arr[0] = -89;
			arr[1] = -7;
			arr[2] = 0;
			arr[3] = 2;
			arr[4] = 4;
			arr[5] = 15;
			arr[6] = 36;
			arr[7] = 85;
			arr[8] = 777;

			testList.TestInsertSort(arr);
			testList.Display();

			testList.MergeSort();
			testList.TestMergeSort(arr);
			testList.Display();

			testList.Shell(testList.getArr(), testList.getLength());
			testList.Display();
			testList.TestShellSort(arr);
			break;
		}
		case 40: {
			int amountOfElements;
			cout << "Fill in the amount of elements" << endl;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			amountOfElements = atoi(s);
			int tmpEl;
			for (int i = 0; i < amountOfElements; i++) {
				srand(time(NULL));
				tmpEl = rand();
				myList.Append(tmpEl);
			}
			break;
		}
		case 50: {
			int amount;
			cout << "Fill in the amount of elements" << endl;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			amount = atoi(s);

			cout << "Fill in 1 of you want to append and 2 if you want to prepand" << endl;
			int mode;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			mode = atoi(s);
			while (mode < 1 || mode > 2) {
				cout << "Fill in 1 or 2" << endl;
				cin >> s;
				while (!checkDataType(p))
					cin >> s;
				mode = atoi(s);
			}

			for (int i = 0; i < amount; i++) {
				cout << "Fill in the element" << endl;
				cin >> s;
				if (mode == 1) {
					while (!checkDataType(p))
						cin >> s;
					element = atoi(s);
					myList.Append(element);
				}
				if (mode == 2) {
					while (!checkDataType(p))
						cin >> s;
					element = atoi(s);
					myList.Prepend(element);
				}
			}
			break;
		}
		default:
			break;
		}
	}
}


void DoubleListSeq() {

	char s[256];
	char *p = s;

	ListSequence<double> myList;

	double element;
	int definiteFunc = -1;

	while (definiteFunc != 0) {

		definiteFunc = myList.chooseFunction();

		switch (definiteFunc)
		{
		case 0: {
			break;
		}
		case 1: {

			cout << "Fill in the number that you whant to append:" << endl;
			//cin >> s;
			////only for int!!!!!
			//while (!checkDataType(p))
			//	cin >> s;
			//element = atoi(s);
			cin >> element;
			myList.Append(element);

			cout << "\n";
			break;
		}
		case 2: {

			cout << "Fill in the number that you whant to prepand:" << endl;
			//cin >> s;
			//while (!checkDataType(p)) // another check for double
			//	cin >> s;
			//int a = atoi(s);
			double a;
			cin >> a;

			myList.Prepend(a);

			cout << "\n";
			break;
		}
		case 3: {

			cout << "The amount of elements is: ";

			cout << myList.getLength() << endl;

			cout << "\n";
			break;
		}
		case 4: {
			myList.GetFirst();
			cout << "\n";
			break;
		}
		case 5: {
			myList.GetLast();
			cout << "\n";
			break;
		}
		case 6: {
			int ind;
			cout << "Fill in the number of element that you whant to get " << endl;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			ind = atoi(s);
			/*while (ind<0 || ind > myList.getLength()) {
			cout << "Fill in the number from 1 to ";
			cout << myList.getLength() << " ";
			cin >> s;
			while (!checkDataType(p))
			cin >> s;
			ind = atoi(s);
			}
			*/

			try
			{
				throw myEr;
			}
			catch (CurrentError& e)
			{
				if (e.what(1, ind, ind, myList.getLength()) == "NORMAL_STATE")
					int r = 0;
				else
				{
					cout << e.what(1, ind, ind, myList.getLength()) << endl;
					ind = -1;
				}

			}

			if (ind != -1)
				myList.Get(ind);
			else
				cout << "You can't get an element" << endl;

			break;
		}
		case 7: {

			cout << "Is empty sequence?" << endl;

			if (myList.getIsEmpty() == 0)
				cout << "No" << endl;
			else
				cout << "Yes" << endl;
			cout << "\n";
			break;
		}
		case 8: {


			cout << "Fill in the item" << endl;
			double item;
			cin >> item;

			cout << "Insert element at number: " << endl;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			int indexForInsert = atoi(s);
			/*while (indexForInsert < 0 || indexForInsert>myList.getLength()) {
			cout << "Fill in the number from 1 to ";
			cout << myList.getLength() << endl;
			cin >> s;
			while (!checkDataType(p))
			cin >> s;
			}*/

			try
			{
				throw myEr;
			}
			catch (CurrentError& e)
			{
				if (e.what(1, indexForInsert, indexForInsert, myList.getLength()) == "NORMAL_STATE")
					int r = 0;
				else
				{
					cout << e.what(1, indexForInsert, indexForInsert, myList.getLength()) << endl;
					item = -8888;
				}

			}
			myList.InsertAt(indexForInsert, item);

			cout << "\n";
			break;
		}
		case 9: {

			cout << "Fill in the number to remove" << endl;
			double removeElement;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			removeElement = atoi(s);

			myList.Remove(removeElement);

			cout << "\n";
			break;
		}
		case 10: {

			int start, end;

			if (myList.getIsEmpty() != 1) {
				cout << "Fill in the start index of new sequence" << endl;
				cin >> s;
				while (!checkDataType(p))
					cin >> s;
				start = atoi(s);

				/*while (start< 0 || start > myArr.getLength() - 1) {
				cout << "Fill in number from 1 to ";
				cout << myArr.getLength() << endl;
				cin >> s;
				while (!checkDataType(p))
				cin >> s;
				start = atoi(s) - 1;
				}*/
				try
				{
					throw myEr;
				}
				catch (CurrentError& e)
				{
					if (e.what(1, start, end, myList.getLength()) == "NORMAL_STATE")
						int r = 1;
					else
					{
						cout << e.what(1, start, end, myList.getLength()) << endl;
						start = -1;
					}
				}
				if (start != -1) {
					start--;

					if (start == myList.getLength() - 1)
						end = myList.getLength() - 1;
					else {
						cout << "Fill in the end index of new sequence" << endl;
						cin >> s;
						while (!checkDataType(p))
							cin >> s;
						end = atoi(s);

						try
						{
							throw myEr;
						}
						catch (CurrentError& e)
						{
							if (e.what(2, start, end, myList.getLength()) == "NORMAL_STATE")
								int r = 0;
							else {
								cout << e.what(2, start, end, myList.getLength()) << endl;
								end = -1;
							}
						}

						/*		while (end<start || end>myArr.getLength() - 1) {
						cout << "Fill in the number from ";
						cout << start + 1;
						cout << " to ";
						cout << myArr.getLength();
						cout << "\n";
						cin >> s;
						while (!checkDataType(p))
						cin >> s;
						end = atoi(s) - 1;
						}*/
					}
				}

				if (end != -1)
				{
					end--;
					myList.GetSubSequence(start, end).Display();
				}

				else
					cout << "You cann't get a sub sequence" << endl;
			}

			else {
				cout << "You cann't get a sub seq from the empty seq" << endl;
				cout << "\n";
			}

			break;
		}
		case 20: {
			myList.Display();
			cout << "\n";
			break;
		}
		case 30: {
			ListSequence<double> testList;
			// {85,36,2,0,-89,4,-7,777,15}
			testList.Append(85.5);
			testList.Append(36.6);
			testList.Append(2.2);
			testList.Append(0);
			testList.Append(-89.3);
			testList.Append(4.7);
			testList.Append(-7.3);
			testList.Append(777.1);
			testList.Append(15.9);

			testList.InsertSort();
			double *arr = new double[9];
			arr[0] = -89.3;
			arr[1] = -7.3;
			arr[2] = 0;
			arr[3] = 2.2;
			arr[4] = 4.7;
			arr[5] = 15.9;
			arr[6] = 36.6;
			arr[7] = 85.5;
			arr[8] = 777.1;

			testList.TestInsertSort(arr);
			testList.Display();

			testList.MergeSort();
			testList.TestMergeSort(arr);
			testList.Display();

			testList.Shell(testList.getArr(), testList.getLength());
			testList.Display();
			testList.TestShellSort(arr);
			break;
		}
		case 40: {
			int amountOfElements;
			cout << "Fill in the amount of elements" << endl;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			amountOfElements = atoi(s);
			double tmpEl;
			for (int i = 0; i < amountOfElements; i++) {
				srand(time(NULL));
				tmpEl = rand();
				myList.Append(tmpEl);
			}
			break;
		}
		case 50: {
			int amount;
			cout << "Fill in the amount of elements" << endl;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			amount = atoi(s);

			cout << "Fill in 1 of you want to append and 2 if you want to prepand" << endl;
			int mode;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			mode = atoi(s);
			while (mode < 1 || mode > 2) {
				cout << "Fill in 1 or 2" << endl;
				cin >> s;
				while (!checkDataType(p))
					cin >> s;
				mode = atoi(s);
			}
			
			for (int i = 0; i < amount; i++) {
				cout << "Fill in the element" << endl;
				cin >> element;
				if (mode == 1)
					myList.Append(element);
				if (mode == 2)
					myList.Prepend(element);
			}
			break;
		}
		default:
			break;
		}
	}
}

template <typename TElement>
void ListSequence<TElement>::TestGet(TElement a, int index) {
	index++;
	int k = 0;

	try {
		throw myEr;
	}
	catch (CurrentError& e) {
		if (e.what(1, index, index, getLength()) == "NORMAL_STATE")
			int r = 0;
		else
		{
			cout << e.what(1, index, index, getLength()) << endl;
			k = -1;
		}
	}
	if (k != -1) {
		if (Get(index) == a)
			cout << "The function getting element works correctly" << endl;
		else
			cout << "The function of getting element works incorrectly" << endl;
	}

}

template <typename TElement>
void ListSequence<TElement>::TestInsert(int *ar, int index, TElement el) {
	int item = 0;
	try
	{
		throw myEr;
	}
	catch (CurrentError& e)
	{
		if (e.what(1, index, index, getLength()) == "NORMAL_STATE")
			int r = 0;
		else
		{
			cout << e.what(1, index, index, getLength()) << endl;
			item = -8888;
		}
	}

	if (item != -8888) {
		InsertAt(index, el);
		int fl = 0;
		Node<TElement> *tmp = head;
		int *tmpAr = new int[amount];
		tmpAr[index - 1] = el;
		for (int i = 1; i < amount; i++)
			tmpAr[i] = ar[i - 1];
		int i = 0;
		while (tmp) {
			if (tmp->data == tmpAr[i])
				fl++;
			tmp = tmp->Next;
			i++;
		}

		if (fl == 4)
			cout << "The function of insert works correctly" << endl;
		else
			cout << "The function of insert works incorrectly" << endl;
	}
}