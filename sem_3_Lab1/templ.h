#ifndef _TEMPL_L__
#define _TEMPL_L__

template <typename TElement>
struct Node
{
	TElement data;
	Node *Next, *Prev;
};

template <typename TElement>
class Sequence {
	int Length;
	int isEmpty;
public:
	Sequence() {
		Length = 0;
		isEmpty = 1;
	}
	virtual int getLength();//amount of elements
	virtual TElement GetFirst();
	virtual TElement GetLast();
	virtual void changeCondition(int);
	virtual TElement Get(int index); //get element by index
	virtual int getIsEmpty(); //feature that it is empty
	virtual void Append(TElement item); // add element at the end of the existing seq
	virtual void Prepend(TElement item); //add element at the begining of the seq
	virtual void InsertAt(int index, TElement item); //insert element in i position
	virtual void Remove(TElement item);
	virtual void Display();
	virtual TElement* getArr();
	virtual int chooseFunction(); // what to do with func

								  //virtual Sequence<TElement> GetSubSequence(int, int); //get the sequence from the start index to end one

								  //-----------------Test-------------------//
	virtual void TestAppend(TElement, int); //delete
	virtual void TestGetFirst(TElement);
	virtual void TestGetLast(TElement);
	virtual void TestInsert(int*, int, TElement);
	virtual void TestGet(TElement, int);
	virtual void TestGetSub(int, TElement);
	virtual void TestRemove(int*, TElement);
	virtual void TestLength(int);
	virtual void TestInsertSort(TElement*);
	virtual void TestMergeSort(TElement*);
	virtual void TestShellSort(TElement*);
	//virtual void mergeSort();


	//--------------------------Sorts------------------------------------//
	virtual void InsertSort();
	virtual void MergeSort(/*TElement *curArr, int lenD*/);
	virtual void Shell(TElement*, int/*, int*/);
};


template <typename TElement>
class ArraySequence : public Sequence<TElement> {
	int currentAmount;
	int isEmpty;
	TElement *currentArr = new TElement[10000]; //choose the type - for user interfce
public:
	ArraySequence() {
		currentAmount = 0;
		isEmpty = 1;
		for (int i = 0; i < getLength(); i++)
			currentArr[i] = 0;
	}
	void Append(TElement);
	int getLength();
	void changeCondition(int);
	int getIsEmpty(); //feature that it is empty
	void Display();
	TElement GetFirst();
	TElement GetLast();
	TElement Get(int); //get element by index
	void Prepend(TElement);
	void InsertAt(int, TElement);
	void Remove(TElement);
	ArraySequence<TElement> GetSubSequence(int, int);
	int chooseFunction();
	TElement* getArr();
	

	//--------------------------------------Test------------------------------//
	void TestAppend(TElement a, int);
	void TestGetFirst(TElement);
	void TestGetLast(TElement);
	void TestGet(TElement, int);
	void TestLength(int);
	void TestInsert(int*, int, TElement);
	void TestRemove(int*, TElement);
	void TestGetSub(int, TElement);
	void TestInsertSort(TElement*);
	void TestMergeSort(TElement*);
	void TestShellSort(TElement*);
	//------------------------------Sorts---------------------//
	void InsertSort();
	void MergeSort(/*TElement *curArr, int lenD*/);
	//void merge(int* merged, int lenD, int L[], int lenL, int R[], int lenR);
	void Shell(TElement*, int);

};


template <typename TElement>
class ListSequence : Sequence<TElement> {
	int amount;
	int isEmpty;
	Node<TElement> *head;
	Node<TElement> *tail;
public:
	ListSequence() {
		amount = 0;
		isEmpty = 1;
		head = NULL;
		tail = NULL;
	}
	void Append(TElement);
	void Prepend(TElement);
	int getLength();
	int getIsEmpty();
	void changeCondition(int);
	TElement GetFirst();
	TElement GetLast();
	TElement Get(int);
	void InsertAt(int, TElement);
	void Remove(TElement);
	ListSequence<TElement> GetSubSequence(int, int);
	int chooseFunction();
	TElement* getArr();
	void Display();
	//--------------------------------------Test------------------------------//
	void TestAppend(TElement a, int);
	void TestGetFirst(TElement);
	void TestGetLast(TElement);
	void TestGet(TElement, int);
	void TestLength(int);
	void TestInsert(int*, int, TElement);
	void TestRemove(int*, TElement);
	void TestGetSub(int, TElement);
	void TestInsertSort(TElement*);
	void TestMergeSort(TElement*);
	void TestShellSort(TElement*);
	//----------------------------Sorts-------------------//
	void InsertSort();
	void MergeSort();
	void Shell(TElement*, int);
private:
	void sort(Node<TElement>* &theHead);//формирование списка для слияния 
	Node<TElement>* sortedMerge(Node<TElement>* a, Node<TElement>* b); //слияние двух остортированных списков в один отсортированный
	void frontBackSplit(Node<TElement>* theHead, Node<TElement>* &frontRef, Node<TElement>* &backRef); //разбиение на подсписки
};

#include "templ_impl.h"
#include "templ_impl_ArrSeq.h"
#include "templ_impl_ListSeq.h"
#endif // _TEMPL_L__

