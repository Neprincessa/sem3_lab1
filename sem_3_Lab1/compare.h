#ifndef __COMP__ALG__
#define __COMP__ALG__
#include "Header.h"
#include "mergeSort.h"
#include "templ.h"
#include <iostream>
#include <ctime>
#include "fixSortTime.h"

template<typename TElement>
void compareSorts(Sequence<TElement> *seq1, Sequence<TElement> *seq2, Sequence<TElement> *seq3) {
	cout << "Insert: " << TimeInsert(seq1)<<endl;
	cout << "Merge: " << TimeMerge(seq2) << endl;
	cout << "Shell: " << TimeShell(seq3) << endl;
}
#endif // !__COMP__ALG__
