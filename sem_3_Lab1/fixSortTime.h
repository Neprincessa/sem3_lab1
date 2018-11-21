#ifndef __TIME__T__
#define __TIME__T__
#include "Header.h"
#include "mergeSort.h"
#include "templ.h"
#include <iostream>
#include <ctime>

template <typename TElement>
long int TimeInsert(Sequence<TElement> *seq) {
	long int startS, endS;
	startS = clock();
	seq->InsertSort();
	endS = clock();

	return (endS - startS);
}

template <typename TElement>
long int TimeMerge(Sequence<TElement> *seq) {
	long int startS, endS;
	startS = clock();
	MergeSort(seq);
	endS = clock();

	return (endS - startS);
}

template <typename TElement>
long int TimeShell(Sequence<TElement> *seq) {
	int *arr = new int[50];
	for (int i = 0; i < 50;i++)
		arr[i] = i;

	long int startS, endS;
	startS = clock();
	seq->Shell(seq->getArr(), seq->getLength(), arr);
	endS = clock();

	return (endS - startS);
}
#endif // !__TIME__T__
