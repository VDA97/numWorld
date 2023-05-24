#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <inttypes.h>
#include <cstring>
#include <math.h>

namespace bw
{

    constexpr char *_version = "21/05/2023";
    typedef uint64_t numnum;
    const size_t _maxstr = 1024;
    static const char *_nun[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    static const char *_nteen[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    static const char *_nty[] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    static const char *_nhundreds = "hundred";
    static const char *_nllions[] = {"thousand", "million", "billion"};

    class nw
    {
        numnum _n;
        char *_buf = nullptr;
        size_t _buflen;

        void clearbuf()
        {
            if (_buf != nullptr)
            {
                delete[] _buf;
                _buf = nullptr;
            }
            _buflen = 0;
        };

        void initbuf()
        {
            try
            {
                _buf = new char[_maxstr];
                *_buf = 0;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Not possible to init the buffer, fail:" << e.what() << '\n';
            }
        };

        void appendbuf(const char *s)
        {
            size_t slen = strnlen(s, _maxstr); // calculates the length of a given string considering the max size, this makes quickly the check.
            if (slen < 1)
            {
                return;
            }
            if ((slen + _buflen + 1) > _maxstr)
            {
                return;
            }
            memcpy(_buf + _buflen, s, slen); // copies s to _buf, considering the size.
            _buflen += slen;                 // update the occupied size.
                                             // clean the last index.
                                             // std::cout << "buf value: " << _buf << std::endl;
            _buf[_buflen] = 0;
        };

    public:
        nw() : _n(0){};
        nw(const numnum &num) : _n(num) { std::cout << "Object created\n"; };
        ~nw();
        char *shown()
        {
            if (_buf == nullptr)
            {
                return nullptr;
            }
            return _buf;
        }
        char *words(const numnum &num)
        {
            _n = num;
            if (_n > 999)
            {
                for (int i = 3; i > 0; i--)
                {
                    // Apply the exponencial according to index
                    numnum power = (numnum)pow(1000.0, i);
                    printf("Is higher than 999, do the thousands: %ld \n", _n);
                    numnum _nrest;
                    _nrest = (_n - (_n % power)) / power;
                    // check if we have a rest
                    if (_nrest)
                    {
                        // check the rest value, it could be started in hundred, so _nrest should be passed forward.
                        clearbuf();
                        initbuf();
                        nw *_nrec = new nw();
                        appendbuf(_nrec->words(_nrest)); // process the _nrest
                        appendbuf(" ");
                        appendbuf(_nllions[i]);
                        break;
                    }
                }
                return shown();
            }
            if (_n > 99 && _n < 1000)
            {
                printf("Doing the hundreds: %ld \n", _n);
                numnum _nrest;
                _nrest = (_n - (_n % 100)) / 100;
                for (int i = 0; i <= 9; i++)
                {
                    if (_nrest == i)
                    {
                        clearbuf();
                        initbuf();
                        appendbuf(_nun[i]);
                        appendbuf(" ");
                        appendbuf(_nhundreds);
                        // now send it again if we indeed have something to add
                        if (_n % 100 > 0)
                        {
                            _n = (_n % 100);
                            nw *_nrec = new nw();
                            appendbuf(" ");
                            appendbuf(_nrec->words(_n)); // process it again
                            break;
                        }
                        break;
                    }
                }
                return shown();
            }
            if (_n > 19 && _n < 100)
            {
                printf("Doing the ty: %ld \n", _n);
                numnum _numty = 0;
                _numty = (_n - (_n % 10)) / 10;
                for (int i = 0; i <= 7; i++)
                {

                    if (_numty == (i + 2))
                    {
                        clearbuf();
                        initbuf();
                        appendbuf(_nty[i]);
                        if (_n % 10 > 0)
                        {
                            _n = (_n % 10);
                            nw *_nrec = new nw();
                            appendbuf(" ");
                            appendbuf(_nrec->words(_n)); // process it again
                            break;
                        }
                        break;
                    }
                }
                return shown();
            }
            if (_n > 9 && _n < 20)
            {
                printf("Doing the tens: %ld \n", _n);
                for (int i = 0; i <= 9; i++)
                {
                    if (_n == (i + 10))
                    {
                        clearbuf();
                        initbuf();
                        appendbuf(_nteen[i]);
                        break;
                    }
                }
                return shown();
            }
            if (_n < 10)
            {
                for (int i = 0; i <= 9; i++)
                {
                    if (_n == i)
                    {
                        clearbuf();
                        initbuf();
                        appendbuf(_nun[i]);
                        break;
                    }
                }
                return shown();
            }
        }
    };
};

int main(int argc, char **argv)
{
    uint64_t n[12] = {1, 12, 25, 98, 100, 101, 125, 256, 999, 1000, 13400, 1256598};
    bw::nw *obj = new bw::nw();

    printf("n %ld, _buf:%s\n", n[0], obj->words(n[0]));
    printf("n %ld, _buf:%s\n", n[1], obj->words(n[1]));
    printf("n %ld, _buf:%s\n", n[2], obj->words(n[2]));
    printf("n %ld, _buf:%s\n", n[3], obj->words(n[3]));
    printf("n %ld, _buf:%s\n", n[4], obj->words(n[4]));
    printf("n %ld, _buf:%s\n", n[5], obj->words(n[5]));
    printf("n %ld, _buf:%s\n", n[6], obj->words(n[6]));
    printf("n %ld, _buf:%s\n", n[7], obj->words(n[7]));
    printf("n %ld, _buf:%s\n", n[8], obj->words(n[8]));
    printf("n %ld, _buf:%s\n", n[9], obj->words(n[9]));
    printf("n %ld, _buf:%s\n", n[10], obj->words(n[10]));
    printf("n %ld, _buf:%s\n", n[11], obj->words(n[11]));
    return 0;
}