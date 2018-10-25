#ifndef _EX__L__
#define _EX__L__

#include <iostream>
#include <exception>
#include <string.h>

enum TypeError
{
	NEGATIVE_INDEX,
	OVER_DIAPASON_INDEX,
	INCORRECT_END_INDEX,
	NORMAL_STATE
};

class CurrentError : public std::exception
{
public:

	TypeError getReason(int typeFunc, int start, int end, int len) const throw();
	const char* ToString(TypeError v);

	virtual const  char* what(int typeFunc, int start, int end, int len) const throw() {
		TypeError f = getReason(typeFunc, start, end, len);
		if (f == 0)
			return "NEGATIVE_INDEX";
		if (f == 1)
			return "OVER_DIAPASON_INDEX";
		if (f == 2)
			return "INCORRECT_END_INDEX";
		if (f == 3)
			return "NORMAL_STATE";
	}
}myEr;


#endif // !_EX__L__
