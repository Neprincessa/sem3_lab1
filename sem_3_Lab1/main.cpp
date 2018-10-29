#include <iostream>
#include "Header.h"
#include "templ.h"
#include <string>
#include <exception>

using namespace std;


int main() {

	setlocale(LC_ALL, "rus");

	char s[256];
	char *p = s;

	//int wholeAmountOfElements = setAmount();

//	int typeData;

	int *arr = new int[4];
	arr[0] = 53;
	//arr[1] = 88;
	arr[1] = 23;
	arr[2] = 43;

	//int curSeq = typeOfSequence();	
	//typeData = typeOfDataOfSeq();

	cout << "TESTS for ArraySequence" << endl;
	cout << "\n";
	ArraySequence<int> test;
	test.TestLength(0);
	cout << "\n";
	test.Append(23);
	test.TestLength(1);
	cout << "\n";
	test.TestGetFirst(23);
	test.TestGetLast(23);
	test.TestGet(23, 0);
	test.TestGet(23, 1);
	test.TestGet(23, -1);
	test.Append(43);
	test.TestLength(2);
	cout << "\n";
	test.TestGetFirst(23);
	test.TestGetLast(43);
	test.TestGet(23, 0);
	test.TestGet(43, 1);
	test.TestGet(43, -1);
	test.TestGet(43, 2);
	test.Prepend(53);
	test.TestLength(3);
	cout << "\n";
	cout << "Prepend test" << endl;
	test.TestGetFirst(53);
	test.TestGetLast(43);
	test.TestGet(43, -1);
	test.TestGet(43, 3);
	//cout << "dsssssssssssssssssssssssssssssssssss" << endl;
	//test.Display();
	test.GetSubSequence(1, 1).TestGetSub(1, 23);
	cout << "\n";
	test.TestInsert(arr, 1, 63);
	cout << "\n";
	test.TestLength(4);
	cout << "\n";
	test.TestInsert(arr, -1, 33);
	cout << "\n";
	test.TestGet(23, 2);
	cout << "\n";
	test.Display();

	test.TestRemove(arr, 43);
	test.TestRemove(arr, 888881);


	cout << "Okey" << endl;
	test.Display();
	test.Append(454);
	test.Append(36);
	test.Append(0);
	test.Append(-99);
	test.Display();
	cout << "\n";
	//cout << "Insert" << endl;
	//test.InsertSort();
	/*cout << "Merge" << endl;
	test.MergeSort();*/
	cout << "Shell sort" << endl;
	test.Shell(test.getArr(), test.getLength());
	test.Display();


	cout << "\n";
	cout << "///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "TESTS for ListSequence" << endl;
	cout << "\n";
	ListSequence<int> testList;
	int *arrList = new int[4];
	arrList[0] = 53;
	//arrList[1] = 88;
	arrList[0] = 23;
	arrList[1] = 43;
	testList.TestLength(0);
	cout << "\n";
	testList.Append(23);
	testList.TestLength(1);
	cout << "\n";
	testList.TestGetFirst(23);
	cout << "\n";
	testList.TestGetLast(23);
	cout << "\n";
	testList.TestGet(23, 0);
	testList.TestGet(23, 1);
	testList.TestGet(23, -1);
	testList.Append(43);
	testList.TestLength(2);
	cout << "\n";
	testList.TestGetFirst(23);
	testList.TestGetLast(43);
	testList.TestGet(23, 0);
	testList.TestGet(43, 1);
	testList.TestGet(43, -1);
	testList.TestGet(43, 2);
	testList.Prepend(53);
	testList.TestLength(3);
	cout << "\n";
	cout << "Prepend test" << endl;
	testList.TestGetFirst(53);
	cout << "\n";
	testList.TestGetLast(43);
	cout << "\n";
	testList.TestGet(43, -1);
	testList.TestGet(43, 3);
	testList.GetSubSequence(1, 1).TestGetSub(1, 23);
	cout << "\n";
	testList.TestInsert(arr, 1, 63);
	cout << "\n";
	testList.TestInsert(arr, -1, 33);
	cout << "\n";
	testList.Display();
	testList.TestGet(23, 2);
	cout << "\n";
	cout << "\n";
	int *tmpAr = new int[3];
	tmpAr[0] = 63;
	tmpAr[1] = 53;
	tmpAr[2] = 23;
	testList.TestRemove(tmpAr, 43);
	testList.TestRemove(tmpAr, 888881);

	cout << "OKEY" << endl;
	testList.Display();
	testList.Append(25);
	testList.Append(-8);
	testList.Append(988);
	testList.Append(123);
	testList.Append(65);
	testList.Append(18);
	testList.Append(-999);
	testList.Display();

	//cout << "Insert sort" << endl;
	//testList.InsertSort();
	cout << "Merge sort" << endl;
	testList.MergeSort();
	testList.Display();

	//if (curSeq == 1) {
	//	if (typeData == 1)
	//		IntArrSeq();
	//	if (typeData == 2)
	//		DoubleArrSeq();
	//}
	//if (curSeq == 2) {	
	//	if (typeData == 1)
	//		IntListSeq();
	//	if (typeData == 2)
	//		DoubleListSeq();
	//}


	system("pause");
	return 0;
}