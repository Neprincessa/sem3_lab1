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
	//char s[256];
	//char *p = s;

	//int i = /*1*/0;

	////to main!!!!!!!!!1
	//*if (index<1 || index > amount) {
	//	cout << "Fill in the index from 1 to ";
	//	cout << amount << " ";
	//	cin >> s;
	//	while (!checkDataType(p))
	//		cin >> s;
	//	index = atoi(s);
	//	while (index <1 || index > amount) {
	//		cout << "Fill in the index from 1 to ";
	//		cout << amount << " ";
	//		cin >> s;
	//		while (!checkDataType(p))
	//			cin >> s;
	//		index = atoi(s);
	//	}
	//}*/

	//if (getIsEmpty() != 1) {

	//	TElement result;
	//	int flag = 0;

	//	Node <TElement> *tmp = head;
	//	while (tmp) {
	//		if (i == index) {
	//			result = tmp->data;
	//			flag = 1;
	//		}
	//		tmp = tmp->Next;
	//		i++;
	//	}

	//	if (flag == 1) {
	//		//cout << "\n";
	//	//	cout << "The " << index << " element is: ";
	//	//	cout << result << endl;
	//		return result;
	//	}

	//	else {
	//		cout << "The element wasn't found" << endl;
	//		return -1;
	//	}
	//}
	//else {
	//	cout << "You can't get the element from the empty sequence" << endl;
	//	return -1;
	//}

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
	/*int i = 1;
	if (head != NULL) {
		TElement *forNewList = new TElement[amount + 2];
		Node <TElement> *tmp = head;

		while (i != index && tmp) {
			forNewList[i - 1] = tmp->data;
			tmp = tmp->Next;
			i++;
		}
		forNewList[i - 1] = item;
		while (tmp) {
			forNewList[i] = tmp->data;
			tmp = tmp->Next;
			i++;
		}
		amount++;
		int curAm = amount;
		head = NULL;
		tail = NULL;
		amount = 0;
		for (int i = 0; i < curAm; i++)
			Append(forNewList[i]);
	}
	else {
		Node <TElement> *temp = new Node<TElement>;
		temp->data = item;
		temp->Prev = NULL;
		amount++;
		head = tail = temp;
	}*/

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

//template <typename TElement>
//void ListSequence<TElement>:: MergeSort() {
//	sort(head);
//
//	// After the merge sort, tail pointer will be pointing to incorrect node
//	// Update the tail (*** Need a better way to update tail ***)
//	Node<TElement>* findTail = head;
//	while (findTail != nullptr) {
//		if (findTail->Next == nullptr) {
//			tail = findTail;
//		}
//
//		findTail = findTail->Next;
//	}
//}
//
//template <typename TElement>
//void ListSequence<TElement>::sort(Node<TElement>* &theHead) {
//	
//	Node<TElement>* a = nullptr;
//	Node<TElement>* b = nullptr;
//
//	// Base case
//	if (theHead == nullptr || theHead->Next == nullptr) {
//		return;
//	}
//
//	// Split the list in half
//	// For odd number of nodes, the extra node will be in the first half.
//	frontBackSplit(theHead, a, b);
//	// Recursively break the list down until the sublist contains 1 element (Sorted)
//	sort(a);
//	sort(b);
//
//	// Merge the two sorted lists
//	theHead = sortedMerge(a, b);
//}
//
//
//
//
/////**
////*  Take 2 Node Pointers, each pointing at the head of sorted sublist,
////*      merge them, and return the Node pointer to the head node of the merged list.
////*  @param a Node* Pointer to the head of the first sorted list
////*  @param b Node* Pointer to the head of the second sorted list
////*  @return Node* head of the merged list (nullptr if both given nodes are empty)
////*/
////
//
//
//template <typename TElement>
//Node<TElement>* ListSequence<TElement>::sortedMerge(Node<TElement>* a, Node<TElement>* b)
//{
//	Node<TElement>* headOfMerged;
//
//	// If one of the node is nullptr, return the other node
//	// No merging occurs this this case
//	if (a == nullptr) {
//		return b;
//	}
//	else if (b == nullptr) {
//		return a;
//	}
//
//	// First element in list, a, is less than the first element in b
//	if (a->data >=/*<=*/ b->data) {
//		headOfMerged = a;
//
//		while (b != nullptr) {
//			if (a->data /*>=*/<= b->data) {
//				if (a->Next == nullptr) {
//					a->Next = b;
//					b->Prev = a;
//					break;
//				}
//				a = a->Next;
//			}
//			else {
//				Node<TElement>* toAdd = b;
//				b = b->Next;
//				toAdd->Prev = a->Prev;
//				if (a->Prev!=NULL)
//					a->Prev->Next = toAdd;
//				toAdd->Next = a;
//				a->Prev = toAdd;
//			}
//		}
//	}
//	// First element in list, b, is less than the first element in a
//	else {
//		headOfMerged = b;
//
//		while (a != nullptr) {
//			if (b->data /*<=*/>= a->data) {
//				if (b->Next == nullptr) {
//					b->Next = a;
//					a->Prev = b;
//					break;
//				}
//				b = b->Next;
//			}
//			else {
//				Node<TElement>* toAdd = a;
//				a = a->Next;
//				toAdd->Prev = b->Prev;
//				b->Prev->Next = toAdd;
//				toAdd->Next = b;
//				b->Prev = toAdd;
//			}
//		}
//	}
//
//	return headOfMerged;
//}
//
//template <typename TElement>
//void ListSequence<TElement>::frontBackSplit(Node<TElement>* theHead, Node<TElement>* &frontRef, Node<TElement>* &backRef)
//{
//	Node<TElement>* fast;
//	Node<TElement>* slow;
//
//	// If the list is empty, both front and back points to null
//	// If there is only one element, front points to it and back points
//	//  to null.
//	if (theHead == nullptr || theHead->Next == nullptr) {
//		frontRef = theHead;
//		backRef = nullptr;
//	}
//	else {
//		slow = theHead;
//		fast = theHead->Next;
//
//		// Fast advances 2 nodes while slow advances 1 node
//		while (fast != nullptr) {
//			fast = fast->Next;
//
//			if (fast != nullptr) {
//				slow = slow->Next;
//				fast = fast->Next;
//			}
//		}
//
//		// slow should be pointing right before midpoint. Split at this point
//		frontRef = theHead;
//		backRef = slow->Next;
//
//		// Update the prev and next pointers
//		backRef->Prev = nullptr;
//		slow->Next = nullptr;
//	}
//}


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
void ListSequence<TElement>::Shell(TElement *arr, int size) {
	int count;
	int d = size;
	//d = d / 2;
	//d = chooseStep(1,size);
	d = chooseforFirstIteration_ShellSort(size);

	//добавить если первое вхождение то флаг о, там фиксированное значение иначе на вход подается значение d
	while (d>0) {
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
		//d = d / 2;
		d = chooseStep(d, size);
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

//template <typename TElement>
//void ListSequence<TElement>::mergeMeeeerge() {
//	mergesort(head);
//}
//
//template <typename TElement>
//Node<TElement>* ListSequence<TElement>::mergesort(Node<TElement> *&head) {
//	if (head == 0 || head->Next == 0) return head;
//	Node<TElement> *a = head, *b = head->Next;
//	while ((b != 0) && (b->Next != 0))
//	{
//		head = head->Next;
//		b = b->Next->Next;
//	}
//	b = head->Next; head->Next = NULL;
//	return merge(mergesort(a), mergesort(b));
//}
//
//template<typename TElement>
//Node<TElement>* ListSequence<TElement>::merge(Node<TElement> *a, Node<TElement> *b) {
//	if (!a)
//		return b;
//	if (!b)
//		return b;
//	Node<TElement> *c = NULL;
//	if (a->data <= b->data) {
//		c = a;
//		c->Next = merge(a->Next, b);
//	}
//	else {
//		c = b;
//		c->Next = merge(a, b->Next);
//	}
//	return c;
//}
#endif // !_LST__T__
