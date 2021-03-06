#include "types.h"

#include <stdarg.h>

using namespace std;

string mformat(const char *fmt, ...)
{
	size_t size = 1024;
	char* buf = new char[size];
	while (1)
	{
		va_list args;
		int n;

		va_start(args, fmt);
		n = vsprintf(buf, fmt, args);
		va_end(args);

		if ((n > -1) && (static_cast<size_t>(n) < size))
		{
			std::string s(buf);
			delete[] buf;
			return s;
		}
		// Else try again with more space.
		size = (n > -1) ?
			n + 1 :   // ISO/IEC 9899:1999
			size * 2; // twice the old size

		delete[] buf;
		buf = new char[size];
	}

}