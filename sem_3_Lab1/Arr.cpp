#include <iostream>
#include "Header.h"
#include "Exceptions.h"
#include "templ.h"

Reason Exception::getReason(int typeFunc, int start, int end, int len) const throw() {
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

const char* Exception::ToString(Reason v) {
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


void IntArrSeq() {

	char s[256];
	char *p = s;

	ArraySequence<int> myArr;

	int number, element;
	int definiteFunc = -1;

	while (definiteFunc != 0) {

		definiteFunc = myArr.chooseFunction();
		//definiteFunc = 30;

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

			myArr.Append(element);

			cout << "\n";
			break;
		}
		case 2: {

			cout << "Fill in the number that you whant to prepand:" << endl;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			int a = atoi(s);

			myArr.Prepend(a);

			cout << "\n";
			break;
		}
		case 3: {

			cout << "The amount of elements is: ";

			cout << myArr.getLength() << endl;

			cout << "\n";
			break;
		}
		case 4: {
			myArr.GetFirst();
			cout << "\n";
			break;
		}
		case 5: {
			myArr.GetLast();
			cout << "\n";
			break;
		}
		case 6: {

			cout << "Fill in the number of element that you whant to get " << endl;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			number = atoi(s);

			try
			{
				throw myEx;
			}
			catch (Exception& e)
			{
				if (e.what(1, number, number, myArr.getLength()) == "NORMAL_STATE")
					int r = 0;
				else
				{
					cout << e.what(1, number, number, myArr.getLength()) << endl;
					number = -1;
				}

			}
			/*		while (number<0 || number > myArr.getLength()) {
			cout << "Fill in the number from 1 to ";
			cout << myArr.getLength() << " ";
			cin >> s;
			while (!checkDataType(p))
			cin >> s;
			number = atoi(s);
			}*/

			if (number != -1)
				myArr.Get(number);
			else
				cout << "You can't get an element" << endl;

			break;
		}
		case 7: {

			cout << "Is empty sequence?" << endl;

			if (myArr.getIsEmpty() == 0)
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

			try
			{
				throw myEx;
			}
			catch (Exception& e)
			{
				if (e.what(1, indexForInsert, indexForInsert, myArr.getLength()) == "NORMAL_STATE")
					int r = 0;
				else
				{
					cout << e.what(1, indexForInsert, indexForInsert, myArr.getLength()) << endl;
					item = -8888;
				}

			}
			/*while (indexForInsert < 0 || indexForInsert>myArr.getLength()) {
			cout << "Fill in the number from 1 to ";
			cout << myArr.getLength() << endl;
			cin >> s;
			while (!checkDataType(p))
			cin >> s;
			indexForInsert = atoi(s);
			}*/

			myArr.InsertAt(indexForInsert, item);

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

			myArr.Remove(removeElement);

			cout << "\n";
			break;
		}
		case 10: {

			int start, end;

			if (myArr.getIsEmpty() != 1) {
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
					throw myEx;
				}
				catch (Exception& e)
				{
					if (e.what(1, start, end, myArr.getLength()) == "NORMAL_STATE")
						int r = 1;
					else
					{
						cout << e.what(1, start, end, myArr.getLength()) << endl;
						start = -1;
					}
				}
				if (start != -1) {
					start--;

					if (start == myArr.getLength() - 1)
						end = myArr.getLength() - 1;
					else {
						cout << "Fill in the end index of new sequence" << endl;
						cin >> s;
						while (!checkDataType(p))
							cin >> s;
						end = atoi(s);

						try
						{
							throw myEx;
						}
						catch (Exception& e)
						{
							if (e.what(2, start, end, myArr.getLength()) == "NORMAL_STATE")
								int r = 0;
							else {
								cout << e.what(2, start, end, myArr.getLength()) << endl;
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
					myArr.GetSubSequence(start, end).Display();
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
			myArr.Display();
			cout << "\n";
			break;
		}
		case 30: {
			ArraySequence<int> test;
			test.TestLength(0);
			test.Append(23);
			test.TestLength(1);
			test.TestGetFirst(23);
			test.TestGetLast(23);
			test.TestGet(23, 0);
			test.TestGet(23, 1);
			test.TestGet(23, -1);
			break;
		}
		default:
			break;
		}
		definiteFunc = 0;
	}
}


void DoubleArrSeq() {

	char s[256];
	char *p = s;

	ArraySequence<double> myArr;

	double element;
	int definiteFunc = -1;

	while (definiteFunc != 0) {

		definiteFunc = myArr.chooseFunction();

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
			myArr.Append(element);

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

			myArr.Prepend(a);

			cout << "\n";
			break;
		}
		case 3: {

			cout << "The amount of elements is: ";

			cout << myArr.getLength() << endl;

			cout << "\n";
			break;
		}
		case 4: {
			myArr.GetFirst();
			cout << "\n";
			break;
		}
		case 5: {
			myArr.GetLast();
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
				throw myEx;
			}
			catch (Exception& e)
			{
				if (e.what(1, ind, ind, myArr.getLength()) == "NORMAL_STATE")
					int r = 0;
				else
				{
					cout << e.what(1, ind, ind, myArr.getLength()) << endl;
					ind = -1;
				}

			}
			if (ind != -1)
				myArr.Get(ind);
			else
				cout << "You can't get an element" << endl;

			break;
		}
		case 7: {

			cout << "Is empty sequence?" << endl;

			if (myArr.getIsEmpty() == 0)
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
			/*while (indexForInsert < 0 || indexForInsert>myArr.getLength()) {
			cout << "Fill in the number from 1 to ";
			cout << myArr.getLength() << endl;
			cin >> s;
			while (!checkDataType(p))
			cin >> s;
			}*/
			try
			{
				throw myEx;
			}
			catch (Exception& e)
			{
				if (e.what(1, indexForInsert, indexForInsert, myArr.getLength()) == "NORMAL_STATE")
					int r = 0;
				else
				{
					cout << e.what(1, indexForInsert, indexForInsert, myArr.getLength()) << endl;
					item = -8888;
				}

			}

			myArr.InsertAt(indexForInsert, item);

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

			myArr.Remove(removeElement);

			cout << "\n";
			break;
		}
		case 10: {

			int start, end;

			if (myArr.getIsEmpty() != 1) {
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
					throw myEx;
				}
				catch (Exception& e)
				{
					if (e.what(1, start, end, myArr.getLength()) == "NORMAL_STATE")
						int r = 1;
					else
					{
						cout << e.what(1, start, end, myArr.getLength()) << endl;
						start = -1;
					}
				}
				if (start != -1) {
					start--;

					if (start == myArr.getLength() - 1)
						end = myArr.getLength() - 1;
					else {
						cout << "Fill in the end index of new sequence" << endl;
						cin >> s;
						while (!checkDataType(p))
							cin >> s;
						end = atoi(s);

						try
						{
							throw myEx;
						}
						catch (Exception& e)
						{
							if (e.what(2, start, end, myArr.getLength()) == "NORMAL_STATE")
								int r = 0;
							else {
								cout << e.what(2, start, end, myArr.getLength()) << endl;
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
					myArr.GetSubSequence(start, end).Display();
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
			myArr.Display();
			cout << "\n";
			break;
		}
				 /*case 30: {
				 ArraySequence<int> test;
				 test.TestLength(0);
				 test.Append(23);
				 test.TestLength(1);
				 test.TestGetFirst(23);
				 test.TestGetLast(23);
				 test.TestGet(23, 0);
				 test.TestGet(23, 1);
				 test.TestGet(23, -1);
				 break;
				 }*/
		default:
			break;
		}
		definiteFunc = 0;
	}
}



template <typename TElement>
void ArraySequence<TElement>::TestGet(TElement a, int index) {
	index++;
	int k = 0;
	try {
		throw myEx;
	}
	catch (Exception& e) {
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
			cout << "The function getting elementworks correctly" << endl;
		else
			cout << "The function of getting element works incorrectly" << endl;
	}
}

template <typename TElement>
void ArraySequence<TElement>::TestInsert(int *ar, int index, TElement el) {
	int item = 0;
	try
	{
		throw myEx;
	}
	catch (Exception& e)
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
		int j = 0;
		int *tmp = new int[currentAmount];

		tmp[index - 1] = el;
		for (int i = 1; i < currentAmount; i++)
			tmp[i] = ar[i - 1];

		for (int i = 0; i < currentAmount; i++)
			if (tmp[i] == currentArr[i])
				fl++;
		if (fl == 4)
			cout << "The function of insert works correctly" << endl;
		else
			cout << "The function of insert works incorrectly" << endl;
	}

}