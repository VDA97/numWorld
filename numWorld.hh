#ifndef __INCLUDE__NUMWORLD__H__
#define __INCLUDE__NUMWORLD__H__

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <inttypes.h>
#include <cstring>
#include <math.h>

namespace bw
{
    constexpr char const *_version = "21/05/2023"; // same as const char * const; constant ptr to a const char.
    typedef uint64_t numnum;
    const size_t _maxstr = 1024;
    static const char *_nun[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    static const char *_nteen[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    static const char *_nty[] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    static const char *_nhundreds = "hundred";
    static const char *_nllions[] = {"null", "thousand", "million", "billion"};
    class nw
    {
        numnum _n;
        char *_buf = nullptr;
        size_t _buflen;
        // Mark: - Private Methods
        void clearbuf();               // delets the buf using delete []
        void initbuf();                // creates a new buf using new
        void appendbuf(const char *s); // insets chars in the buf
        char *shown();

    public:
        char *words(const numnum &num); // Recursively checks the number and translate it to char
    };
};
#endif //__INCLUDE__NUMWORLD__H__