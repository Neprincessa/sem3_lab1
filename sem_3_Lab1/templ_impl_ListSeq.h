#ifndef _LST__T__
#define _LST__T__
using namespace std;

//----------------------------------------------------------ListSequence-------------------------------------------//

template <typename TElement>
void ListSequence<TElement>::Append(TElement item) {

	Node<TElement> *temp = new Node<TElement>;
	temp->Next = NULL;
	temp->data = item;

	if (head != NULL)   //if list is not empty
	{
		amount++;
		temp->Prev = tail;
		tail->Next = temp;
		tail = temp;
	}
	else  //if list is empty
	{
		amount++;
		temp->Prev = NULL;
		head = tail = temp;
	}
	changeCondition(0);
}


template <typename TElement>
void ListSequence<TElement>::Prepend(TElement item) {

	Node<TElement> *temp = new Node<TElement>;
	temp->Prev = NULL;
	temp->data = item;

	if (head != NULL)   //if list is not empty
	{
		amount++;
		temp->Next = head;
		head->Prev = temp;
		head = temp;
	}
	else  //if list is empty
	{
		amount++;
		temp->Prev = NULL;
		head = tail = temp;
	}
	changeCondition(0);
}

template <typename TElement>
void ListSequence<TElement>::Display() {

	Node<TElement> *temp = head;
	int i = 0;
	if (head == NULL)
		cout << "Sequence is empty" << endl;
	else {
		while (temp /*!= NULL*/)
		{
			i++;
			cout << i << ") ";
			cout << temp->data;
			cout << "\n";
			temp = temp->Next;
		}
	}
	cout << "\n";
}

template <typename TElement>
int ListSequence<TElement>::getLength() {
	return this->amount;
}

template <typename TElement>
void ListSequence<TElement>::changeCondition(int state) {
	isEmpty = state;
}


template <typename TElement>
int ListSequence<TElement>::getIsEmpty() {
	return isEmpty;
}

template <typename TElement>
TElement ListSequence <TElement>::GetFirst() {
	//cout << "\n";
	if (getIsEmpty() != 1) {
		/*cout << "The first element is: ";
		cout << head->data;
		cout << "\n";*/
		return head->data;
	}
	else {
		cout << "You can't get the element from the emptry sequence" << endl;
		//cout << "\n";
		return -1;
	}
}

template <typename TElement>
TElement ListSequence<TElement>::GetLast() {
//	cout << "\n";
	if (getIsEmpty() != 1) {
		/*cout << "The last element is: ";
		cout << tail->data;
		cout << "\n";
		*/return tail->data;
	}
	else {
		cout << "You can't get the element from the emptry sequence" << endl;
	//2	cout << "\n";
		return -1;
	}
}

template <typename TElement>
TElement ListSequence<TElement>::Get(int index) {
	

	if (index < 0 || index > this->amount - 1) {
		return -1;
		//throw Error;/*ExceptionOutOfBounds(index);*/
	}
	if (index == 0) return GetFirst();
	if (index == this->amount - 1) return GetLast();
	else {
		Node<TElement> *temp = new Node<TElement>;
		temp->Next = head->Next;
		while (index - 1) {
			temp->Next = temp->Next->Next;
			index--;
		}
		return temp->Next->data;
	}
}


template <typename TElement>
void ListSequence<TElement>::InsertAt(int index, TElement item) {
	
	if (this->isEmpty == 1) this->isEmpty = 0;
	if (index == 0) Prepend(item);
	else if (index == this->amount) Append(item);
	else {
		this->amount++;
		Node<TElement> *temp = new Node<TElement>;
		temp->data = item;
		temp->Next = head->Next;
		temp->Prev = head;
		head->Next = temp;
		if (index != 1) {
			while (index - 1) {
				Node<TElement> *r = temp->Next;
				Node<TElement> *l = temp->Prev;

				l->Next = r;
				r->Prev = l;

				temp->Next = r->Next;
				temp->Prev = r;

				index--;
			}
		}
		if (temp->Next != NULL) {
			temp->Next->Prev = temp;
		}
		temp->Prev->Next = temp;
	}
}

template <typename TElement>
void ListSequence<TElement>::Remove(TElement item) {

	if (head != NULL) {
		int i = 0;
		TElement *forNewList = new TElement[amount - 1];
		Node<TElement> *tmp = new Node<TElement>;
		tmp = head;
		bool flag = false;

		//for head think and tail
		while (tmp && tmp->data != item) {
			forNewList[i] = tmp->data;
			tmp = tmp->Next;
			i++;
		}
		if (tmp)
			tmp = tmp->Next;
		while (tmp) {
			forNewList[i] = tmp->data;
			tmp = tmp->Next;
			i++;
		}

		int tmpAm = amount - 1;
		amount = 0;
		head = tail = NULL;
		for (int i = 0; i< tmpAm; i++)
			Append(forNewList[i]);
	}
	else {
		cout << "You can't remove element from the empty sequence" << endl;
		cout << "\n";
	}
}


template <typename TElement>
int ListSequence<TElement>::chooseFunction() {
	int typeOfFunction = whatFunc();
	return typeOfFunction;
}


template <typename TElement>
ListSequence<TElement> ListSequence<TElement>::GetSubSequence(int startIndex, int endIndex) {

	ListSequence<TElement> resulList;
	resulList.amount = endIndex - startIndex + 1;
	resulList.isEmpty = 0;

	int leftFlag = startIndex;

	int i = 1;

	Node<TElement> *tmp = new Node<TElement>;
	tmp = head;
	while (tmp) {
		if (i >= startIndex && i <= endIndex)
			resulList.Append(tmp->data);
		tmp = tmp->Next;
		i++;
	}

	return resulList;
}

//--------------------------------Test--------------------------------//
template <typename TElement>
void  ListSequence<TElement>::TestAppend(TElement a, int len) {
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
void ListSequence<TElement>::TestGetFirst(TElement a) {
	if (GetFirst() == a)
		cout << "The function of getting a first element is correctly" << endl;
	else
		cout << "The function of getting a first element is incorrectly" << endl;
}

template <typename TElement>
void ListSequence<TElement>::TestGetLast(TElement res) {
	if (GetLast() == res)
		cout << "The function of getting last works correctly" << endl;
	else
		cout << "The function of getting last works incorrectly" << endl;
}

template <typename TElement>
void ListSequence<TElement>::TestLength(int l) {
	if (getLength() == l)
		cout << "The function of getting length works correctly" << endl;
	else
		cout << "The function of getting length works incorrectly" << endl;
}

template <typename TElement>
void ListSequence<TElement>::TestGetSub(int len, TElement curEl) {
	if (getLength() == len) {
		if (GetFirst() == GetLast() && GetFirst() == 23)
			cout << "The function of getting sub seq works correctly" << endl;
		else
			cout << "The function of getting sub seq works incorrectly" << endl;
	}
	else
		cout << "The gunction of getting sub seq works correctly" << endl;
}

template <typename TElement>
void ListSequence<TElement>::TestRemove(int *arr, TElement elemem) {
	Remove(elemem);
	int fl = 0;
	Node<TElement> *tmp = head;
	int i = 0;
	while (tmp) {
		if (tmp->data == arr[i])
			fl++;
		i++;
		tmp = tmp->Next;
	}

	if (fl == amount)
		cout << "the function of removing works correctly" << endl;
	else
		cout << "the function of removing works incorrectltly" << endl;
}

template <typename TElement>
void ListSequence<TElement>::InsertSort() {

	Node<TElement> *t;
	TElement x;
	Node<TElement> curElement;
	t = head->Next;
	while (t) {
		x = t->data;
		curElement.data = t->data;
		Node<TElement> *b = t->Prev;
		while (b != NULL && x < b->data) {
			b->Next->data = b->data;
			b = b->Prev;
		}
		if (b == NULL)
			head->data = curElement.data;
		else
			b->Next->data = curElement.data;
		t = t->Next;
	}
}

template <typename TElement>
TElement* ListSequence<TElement>::getArr() {
	
	TElement *result = new TElement[amount];
	Node<TElement> *tmp = head;
	int i = 0;
	while (tmp) {
		result[i] = tmp->data;
		tmp = tmp->Next;
		i++;
	}

	return result;
}

template <typename TElement>
void ListSequence<TElement>::Shell(TElement *arr, int size, int *steps) {
	int count;
	int d = size;
	//d = d / 2;
	//d = chooseStep(1,size);
	//d = chooseforFirstIteration_ShellSort(size);
	int k = 0;
	//добавить если первое вхождение то флаг о, там фиксированное значение иначе на вход подается значение d
	while (/*d>0*/steps[k]) {
		for (int i = 0; i<size - /*d*/steps[k]; i++) {
			int j = i;
			int a = arr[j];
			int b = arr[j + /*d*/steps[k]];
			while (j >= 0 && arr[j]>arr[j + /*d*/steps[k]]) {
				count = arr[j];
				arr[j] = arr[j + /*d*/steps[k]];
				arr[j + /*d*/steps[k]] = count;
				j--;
			}
		}
		//d = d / 2;
		k++;
		//d = chooseStep(d, size);
	}

	d = 1;
	for (int i = 0; i<size - d; i++) {
		int j = i;
		int a = arr[j];
		int b = arr[j + d];
		while (j >= 0 && arr[j]>arr[j + d]) {
			count = arr[j];
			arr[j] = arr[j + d];
			arr[j + d] = count;
			j--;
		}
	}
	
	head = tail = NULL;
	for (int k = 0; k < size; k++)
		Append(arr[k]);

}

template <typename TElement>
void ListSequence<TElement>::TestInsertSort(TElement *ideal) {
	Node<TElement> *tmp = head;
	int flag = 0;
	int i = 0;
	while (tmp) {
		if (tmp->data == ideal[i])
			flag++;
		i++;
		tmp = tmp->Next;
	}
	if (flag == amount)
		cout << "Insert sort works correctly" << endl;
	else
		cout << "Insert sort works incorrectly" << endl;
}


template <typename TElement>
void ListSequence<TElement>::TestMergeSort(TElement *ideal) {
	Node<TElement> *tmp = head;
	int flag = 0;
	int i = 0;
	while (tmp) {
		TElement id = ideal[i];
		TElement cur = tmp->data;
		if (tmp->data == ideal[i])
			flag++;
		i++;
		tmp = tmp->Next;
	}
	if (flag == amount)
		cout << "The merge sort works correctly" << endl;
	else
		cout << "The merge sort works incorrectly" << endl;
}

template <typename TElement>
void ListSequence<TElement>::TestShellSort(TElement *ideal) {
	Node<TElement> *tmp = head;
	int flag = 0;
	int i =0;

	while (tmp) {
		TElement id = ideal[i];
		TElement cur = tmp->data;
		if (tmp->data == ideal[i])
			flag++;
		i++;
		tmp = tmp->Next;
	}
	if (flag == 9)
		cout << "The shell sort works correctly" << endl;
	else
		cout << "The shell sort works incorrectly" << endl;
}


template <typename TElement>
void ListSequence<TElement>::RemoveByIndex(int index) {
	Node<TElement> *current = head;
	Node<TElement> *temp = nullptr;
	int i = 0;
	if (index == 0) {
		current = head->Next;
		temp = head;
		head = current;
		//delete temp;
	}
	else if (index == this->getLength() - 1) {
		current = tail->Prev;
		current->Next = NULL;
		temp = tail;
		tail = current;
	}
	else {
		while (current->Next != NULL && i != index) {
			current = current->Next;
			i++;
		}
		current = current->Prev;
		temp = current->Next;
		current->Next = temp->Next;
		temp->Next->Prev = current;
	}
	this->amount--;
	delete temp;
}
#endif // !_LST__T__
