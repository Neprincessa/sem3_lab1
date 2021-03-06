#ifndef _ARR__T__
#define _ARR__T__

using namespace std;
#include <malloc.h>
//----------------------------------------------------------ArraySequence-------------------------------------------//

template <typename TElement>
int ArraySequence<TElement>::getLength() {
	return currentAmount;
}

template <typename TElement>
void ArraySequence<TElement>::changeCondition(int condition) {
	isEmpty = condition;
}

template <typename TElement>
void ArraySequence<TElement>::Append(TElement item) {
	if (getLength() == 0) {
		realloc(currentArr, 2*sizeof(TElement));
		currentArr[0] = item;
		currentAmount++;
	}
	else {
	
		TElement *newArr = new TElement[getLength() + 1];
		for (int i = 0; i < getLength(); i++)
			newArr[i] = currentArr[i];
		newArr[getLength()] = item;
		
		TElement a = newArr[getLength()];
		currentAmount++;
			
		/*cout << "Check 1" << endl;
		for (int i = 0; i < currentAmount-1; i++)
			cout << i + 1 << ") " << currentArr[i] << endl;*/

		realloc(currentArr, (currentAmount + 2) * sizeof(TElement));

		for (int i = 0; i < getLength(); i++)
			currentArr[i] = newArr[i];
		
		/*cout << "Check 2" << endl;
		for (int i = 0; i < currentAmount; i++)
			cout << i + 1 << ") " << currentArr[i] << endl;
		*/
	}

	changeCondition(0);
}

template <typename TElement>
int ArraySequence<TElement>::getIsEmpty() {
	return isEmpty;
}

template <typename TElement>
ArraySequence<TElement> ArraySequence<TElement>::GetSubSequence(int startIndex, int endIndex) {

	ArraySequence<TElement> result/*(endIndex - startIndex+1)*/;
	result.currentAmount = /*endIndex - startIndex + 1*/0;
	int j = startIndex;
	for (int i = 0; i < endIndex - startIndex + 1; i++) {
		result.Append(currentArr[j]/*, i*/);
		j++;
	}
	result.currentAmount = endIndex - startIndex + 1;
	return result;
}

template <typename TElement>
void ArraySequence<TElement>::Display() {
	if (getIsEmpty() == 0) {
		cout << "Current array sequence:" << endl;
		for (int i = 0; i < getLength(); i++) {
			cout << i + 1 << ") ";
			cout << currentArr[i];
			cout << "\n";
		}
	}
	else
		cout << "It is an empty sequence" << endl;
}

template <typename TElement>
TElement ArraySequence<TElement>::GetFirst() {
	//cout << "\n";
	if (getIsEmpty() != 1) {
		/*cout << "The first element is: ";
		cout << currentArr[0];
		cout << "\n";*/
		return currentArr[0];
	}
	else {
		cout << "You can't get the element from the empty sequence :(" << endl;
		cout << "\n";
		return -1;
	}
}

template <typename TElement>
TElement ArraySequence<TElement>::GetLast() {
	//cout << "\n";
	if (getIsEmpty() != 1) {
		/*cout << "The last element is: ";
		cout << currentArr[getLength() - 1];
		cout << "\n";*/
		return currentArr[getLength() - 1];
	}
	else {
		cout << "You can't get element from the empty sequence" << endl;
		cout << "\n";
		return -1;
	}
}

template <class TElement>
TElement ArraySequence<TElement>::Get(int index) {
	//cout << "\n";
	if (getIsEmpty() != 1) {
		/*cout << "The current element is: ";
		cout << currentArr[index - 1] << endl;*/
		return currentArr[index/* - 1*/];
	}
	else {
		cout << "You can't get element from the empty sequence" << endl;
		return -1;
	}

}

template <typename TElement>
void ArraySequence<TElement>::Prepend(TElement item) {

	if (getLength() == 0) {
		realloc(currentArr, 2);
		currentArr[0] = item;
		currentAmount++;
	}
	else {
		TElement *newArr = new TElement[getLength() + 1];
		for (int i = 1; i < getLength() + 1; i++)
			newArr[i] = currentArr[i - 1];
		newArr[0] = item;
		currentAmount++;

		for (int i = 0; i < getLength(); i++)
			currentArr[i] = newArr[i];
	}
	changeCondition(0);
}

template <typename TElement>
void ArraySequence<TElement>::InsertAt(int index, TElement item) {
	this->currentAmount++;
	TElement *newArray = new TElement[this->currentAmount];
	for (int i = 0; i < index; i++) {
		newArray[i] = currentArr[i];
	}
	newArray[index] = item;
	for (int i = index + 1; i < this->currentAmount; i++) {
		newArray[i] = currentArr[i - 1];
	}
	currentArr = newArray;
}

template <typename TElement>
void ArraySequence<TElement>::Remove(TElement item) {

	int i = 0;
	int j = 0;
	bool flag = false;

	if (getIsEmpty() == 1)
		cout << "You can't remove element from empty sequence" << endl;
	else {
		TElement *newArr = new TElement[getLength() - 1];
		while (i<getLength()) {
			if (currentArr[i] != item) {
				newArr[j] = currentArr[i];
				j++;
			}
			if (currentArr[i] == item)
				flag = true;
			i++;
		}
		if (flag == false)
			cout << "The element to remove hasn't been found" << endl;
		else
		{
			currentAmount--;
			for (int i = 0; i < getLength(); i++)
				currentArr[i] = newArr[i];
		}
	}
}

template <typename TElement>
int ArraySequence<TElement>::chooseFunction() {
	int typeOfFunction = whatFunc();
	return typeOfFunction;
}

//--------------------------------Test--------------------------------//
template <typename TElement>
void  ArraySequence<TElement>::TestAppend(TElement a, int len) {
	if (len == 0) {
		if (getLength() == 0)
			cout << "The length of a sequence is 0. Function of getting length is working correctly" << endl;
		else
			cout << "The length of a sequence is 0. Function of getting length is working incorrectly" << endl;
		Append(a);
		if (getLength() == 1)
			cout << "The length of a sequence is 1. Function of append element is working correctly " << endl;
		else
			cout << "The length of a sequence is 1. Function of append element is working incorrectly " << endl;
	}
}

template <typename TElement>
void ArraySequence<TElement>::TestGetFirst(TElement a) {
	if (GetFirst() == a)
		cout << "The function of getting a first element is correctly" << endl;
	else
		cout << "The function of getting a first element is incorrectly" << endl;
}

template <typename TElement>
void ArraySequence<TElement>::TestGetLast(TElement res) {
	if (GetLast() == res)
		cout << "The function of getting last works correctly" << endl;
	else
		cout << "The function of getting last works incorrectly" << endl;
}

template <typename TElement>
void ArraySequence<TElement>::TestLength(int l) {
	if (getLength() == l)
		cout << "The function of getting length works correctly" << endl;
	else
		cout << "The function of getting length works incorrectly" << endl;
}

template <typename TElement>
void ArraySequence<TElement>::TestGetSub(int len, TElement curEl) {
	if (getLength() == len) {
		if (GetFirst() == GetLast() && GetFirst() == 23)
			cout << "The function of getting sub seq works correctly" << endl;
		else
			cout << "The function of getting sub seq works incorrectly" << endl;
	}
	else
		cout << "The function of getting sub seq works correctly" << endl;
}


template <typename TElement>
void ArraySequence<TElement>::TestRemove(int *arr, TElement elemem) {
	Remove(elemem);
	int fl = 0;
	for (int i = 0; i < currentAmount; i++)
		if (currentArr[i] == arr[i])
			fl++;
	if (fl == currentAmount)
		cout << "the function of removing works correctly" << endl;
	else
		cout << "the function of removing works incorrectltly" << endl;
}

template <typename TElement>
void ArraySequence<TElement>::InsertSort() {

	TElement temp; // ��������� ���������� ��� �������� �������� �������� ������������ �������
	int	item; // ������ ����������� ��������
	for (int counter = 1; counter < currentAmount; counter++)
	{
		TElement a = currentArr[counter];
		temp = currentArr[counter]; // �������������� ��������� ���������� ������� ��������� �������� �������
		item = counter - 1; // ���������� ������ ����������� �������� �������
		while (item >= 0 && currentArr[item] > temp) // ���� ������ �� ����� 0 � ���������� ������� ������� ������ ��������
		{
			currentArr[item + 1] = currentArr[item]; // ������������ ��������� �������
			currentArr[item] = temp;
			item--;
		}
	}
}

template <typename TElement>
TElement* ArraySequence<TElement>:: getArr() {
	return currentArr;
}

template <typename TElement>
void ArraySequence<TElement>::RemoveByIndex(int index) {
	this->currentAmount--;
	TElement *newArray = new TElement[this->currentAmount];
	for (int j = 0; j < index; j++) {
		newArray[j] = currentArr[j];
	}
	for (int k = index; k < this->currentAmount; k++) {
		newArray[k] = currentArr[k + 1];
	}
	currentArr = newArray;
}

template <typename TElement>
void ArraySequence<TElement>::Shell(TElement* arr, int size, int *steps) {
	int count;
	int d = size;
	//d = d / 2;
	//d = chooseStep(1,size);
//	d = chooseforFirstIteration_ShellSort(size);
	int k = 0;
	//�������� ���� ������ ��������� �� ���� �, ��� ������������� �������� ����� �� ���� �������� �������� d
	while (/*d>0*/steps[k]) {
		for (int i = 0; i<size - /*d*/steps[k]; i++) {
			int j = i;
			while (j >= 0 && arr[j]>arr[j + /*d*/steps[k]]) {
				count = arr[j];
				arr[j] = arr[j + /*d*/steps[k]];
				arr[j + /*d*/steps[k]] = count;
				j--;
			}
		}
		//d = d / 2;
		k++;
		//d = chooseStep(d,size);
	}

	//safe step = 1 if user didn't input 1
	d = 1;
	for (int i = 0; i<size - d; i++) {
		int j = i;
		while (j >= 0 && arr[j]>arr[j + d]) {
			count = arr[j];
			arr[j] = arr[j + d];
			arr[j + d] = count;
			j--;
		}
	}
}

template <typename TElement>
void ArraySequence<TElement>::TestInsertSort(TElement *ideal) {
	
	int flag = 0;
	for (int i = 0; i < currentAmount; i++)
		if (currentArr[i] == ideal[i])
			flag++;

	if (flag == 9)
		cout << "Insert sort works correctly" << endl;
	else
		cout << "Insert sort works incorrectly" << endl;
}

template <typename TElement>
void ArraySequence<TElement>::TestMergeSort(TElement *ideal) {
	
	int flag = 0;
	int j = 0;
	for (int i = 0; i <currentAmount; i++) {
		TElement a = ideal[i];
		TElement b = currentArr[j];
		if (ideal[i] == currentArr[j])
			flag++;
		j++;
	}
		
		
	if (flag == currentAmount)
		cout << "The merge sort works correctly" << endl;
	else
		cout << "The merge sort works incorrectly" << endl;
}

template <typename TElement>
void ArraySequence<TElement>::TestShellSort(TElement *ideal) {
	int flag = 0;
	for (int i = 0; i < this->currentAmount; i++) {
		TElement a = currentArr[i];
		TElement b = ideal[i];
		if (this->currentArr[i] == ideal[i])
			flag++;
	}
		
	if (flag == this->currentAmount)
		cout << "The shell sort works correctly" << endl;
	else
		cout << "The shell sort works incorrectly" << endl;
}
#endif // !_ARR__T__
