#ifndef _EX__E__
#define _EX__E__

#include <iostream>
#include <exception>
#include <string.h>

enum Reason
{
	NEGATIVE_INDEX,
	OVER_DIAPASON_INDEX,
	INCORRECT_END_INDEX,
	NORMAL_STATE
};

class Exception : public std::exception
{
public:

	Reason getReason(int typeFunc, int start, int end, int len) const throw();
	const char* ToString(Reason v);

	virtual const  char* what(int typeFunc, int start, int end, int len) const throw() {
		Reason f = getReason(typeFunc, start, end, len);
		if (f == 0)
			return "NEGATIVE_INDEX";
		if (f == 1)
			return "OVER_DIAPASON_INDEX";
		if (f == 2)
			return "INCORRECT_END_INDEX";
		if (f == 3)
			return "NORMAL_STATE";
	}
}myEx;


#endif // !_EX__E__
