#include <iostream>
#include "Header.h"
#include "Exceptions.h"
#include "templ.h"
#include "fstream"
#include <time.h>
#include <ctime>
#include <random>

#define N 40
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

	//srand/*seed*/(time(NULL));

	//std::mt19937 e1; 
	//e1.seed(time(0)); 
	//std::cout << e1() << std::endl;

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
			// {85,36,2,0,-89,4,-7,777,15}
			test.Append(85);
			test.Append(36);
			test.Append(2);
			test.Append(0);
			test.Append(-89);
			test.Append(4);
			test.Append(-7);
			test.Append(777);
			test.Append(15);

			test.InsertSort();
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

			test.TestInsertSort(arr);
			test.Display();
			//test.MergeSort();
			test.Display();
			test.TestMergeSort(arr);
			
			ArraySequence<int> tmp;
			for (int i = 8; i >= 0; i--)
				tmp.Append(arr[i]);
			cout << "Set the steps" << endl;
			int *step = (int*)malloc(/*currentAmount*/1000000 * sizeof(int));
			step[0] = chooseforFirstIteration_ShellSort(test.getLength());
			int k = 1;
			realloc(step, sizeof(int) * 2);
			while (step[k - 1] != 0) {

				step[k] = chooseStep(step[k - 1], test.getLength());
				k++;
				realloc(step, sizeof(int)*(k + 2));
			}
			k--;
			tmp.Shell(tmp.getArr(), tmp.getLength(), step);
			tmp.Display();
			tmp.TestShellSort(arr);
			
			break;
		}
		case 40: {
			int amountOfElements;
			cout << "Fill in the amount of elements" << endl;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			amountOfElements = atoi(s);
			//int tmpEl;
			for (int i = 0; i < amountOfElements; i++) {
				srand(/*time(NULL)*/i*5631);
				/*std::mt19937 e1;
				e1.seed(time(0));*/
				std::random_device rd;
				std::mt19937_64 gen(rd());
			//	std::cout << e1() << std::endl;
				int tmpEl = rand()%10000+1;
				myArr.Append(tmpEl/*gen()*/);

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
					myArr.Append(element);
				if (mode == 2) 
					myArr.Prepend(element);
			}
			break;
		}
		case 60: {
			int amountOfElements;
			int tmpEl;
			ArraySequence<int> seq1;
			ArraySequence<int> seq2;
			ArraySequence<int> seq3;

			int amount;
			cout << "Input the amount of elements. if you dont't want to work in this mode, press 0" << endl;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			amount = atoi(s);
			for (int i = 0; i < amount; i++) {
				srand(/*time(NULL)*/i*5631);
				tmpEl = rand() % 10000+1;
				seq1.Append(tmpEl);
				seq2.Append(tmpEl);
				seq3.Append(tmpEl);
			}

			cout << "Data" << endl;
			seq1.Display();

			time_t start1, end1;
			time(&start1);
			seq1.InsertSort();
			time(&end1);

			time_t start2, end2;
			time(&start2);
			MergeSort(&seq2);
			time(&end2);

			cout << "Set the steps" << endl;
			int *arr = (int*)malloc(/*currentAmount*/1000000 * sizeof(int));
			arr[0] = chooseforFirstIteration_ShellSort(seq3.getLength());
			int k = 1;
			realloc(arr, sizeof(int)*2);
			while (arr[k-1] != 0) {
				
				arr[k] = chooseStep(arr[k - 1], seq3.getLength());
				k++;
				realloc(arr, sizeof(int)*(k + 2));
			}
			k--;

			time_t start3, end3;
			time(&start3);
			seq3.Shell(seq3.getArr(), seq3.getLength(),arr);
			time(&end3);

			time_t res1, res2, res3;
			res1 = end1 - start1;
			res2 = end2 - start2;
			res3 = end3 - start3;

			cout << "Insert time = " << res1 << endl;
			cout << "Merge time = " << res2 << endl;
			cout << "shell time = " << res3 << endl;
			break;
		}
		default:
			break;
		}
		//definiteFunc = 0;
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
		case 30: {
			ArraySequence<double> test;
			// {85,36,2,0,-89,4,-7,777,15}
			test.Append(85);
			test.Append(36);
			test.Append(2);
			test.Append(0);
			test.Append(-89.3);
			test.Append(4);
			test.Append(-7);
			test.Append(777);
			test.Append(15);

			test.InsertSort();
			double *arr = new double[9];
			arr[0] = -89.3;
			arr[1] = -7;
			arr[2] = 0;
			arr[3] = 2;
			arr[4] = 4;
			arr[5] = 15;
			arr[6] = 36;
			arr[7] = 85;
			arr[8] = 777;

			test.TestInsertSort(arr);
			test.Display();

			for (int i = 0; i < 9; i++)
				test.Remove(arr[i]);
			for (int i = 8; i >= 0; i--)
				test.Append(arr[i]);
			MergeSort(&test);
			test.TestMergeSort(arr);
			test.Display();

			ArraySequence<double> testDouble;
			for (int i = 8; i >= 0; i--)
				testDouble.Append(arr[i]);
			cout << "Set the steps" << endl;
			int *step = (int*)malloc(/*currentAmount*/1000000 * sizeof(int));
			step[0] = chooseforFirstIteration_ShellSort(test.getLength());
			int k = 1;
			realloc(step, sizeof(int) * 2);
			while (step[k - 1] != 0) {

				step[k] = chooseStep(step[k - 1], test.getLength());
				k++;
				realloc(step, sizeof(int)*(k + 2));
			}
			k--;
			testDouble.Shell(testDouble.getArr(), testDouble.getLength(), step);
			testDouble.Display();
			testDouble.TestShellSort(arr);
		
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
				srand(/*time(NULL)*/i * 5631);
				tmpEl = rand()%10000+1;
				myArr.Append(tmpEl);
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
			while (mode <1 || mode > 2) {
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
					myArr.Append(element);
				}
				if (mode == 2) {
					while (!checkDataType(p))
						cin >> s;
					element = atoi(s);
					myArr.Prepend(element);
				}	
			}
			break;
		}
		case 60: {
			int amountOfElements;
			int tmpEl;
			ArraySequence<double> seq1;
			ArraySequence<double> seq2;
			ArraySequence<double> seq3;

			int amount;
			cout << "Input the amount of elements. if you dont't want to work in this mode, press 0" << endl;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			amount = atoi(s);

			for (int i = 0; i < amount; i++) {
				srand(/*time(NULL)*/i * 5631);
				tmpEl = rand()%1000;
				seq1.Append(tmpEl);
				seq2.Append(tmpEl);
				seq3.Append(tmpEl);
			}

			cout << "Data" << endl;
			seq1.Display();

			time_t start1, end1;
			time(&start1);
			seq1.InsertSort();
			time(&end1);
			
			time_t start2, end2;
			time(&start2);
			MergeSort(&seq2);
			time(&end2);

			cout << "Set the steps" << endl;
			int *arr = (int*)malloc(/*currentAmount*/1000000 * sizeof(int));
			arr[0] = chooseforFirstIteration_ShellSort(seq3.getLength());
			int k = 1;
			realloc(arr, sizeof(int) * 2);
			while (arr[k - 1] != 0) {

				arr[k] = chooseStep(arr[k - 1], seq3.getLength());
				k++;
				realloc(arr, sizeof(int)*(k + 2));
			}
			k--;

			time_t start3, end3;
			time(&start3);
			seq3.Shell(seq3.getArr(), seq3.getLength(),arr);
			time(&end3);

			time_t res1, res2, res3;
			res1 = end1 - start1;
			res2 = end2 - start2;
			res3 = end3 - start3;

			cout << "Insert time = " << res1 << endl;
			cout << "Merge time = " << res2 << endl;
			cout << "shell time = " << res3 << endl;
			break;
		}
		default:
			break;
		}
		//definiteFunc = 0;
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