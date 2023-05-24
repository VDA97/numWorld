#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <inttypes.h>
#include <cstring>

namespace bw
{

    constexpr char *_version = "21/05/2023";
    typedef uint64_t numnum;

    // allocate memory for string
    // clear the string buffer
    // append values to the string
    // create a recursive method, to track down larger values
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
                // std::memset(_buf, 0, sizeof(_buf));
                // printf("_buf cleaned:%s", _buf); // std::cout makes the program crash when printing nullptr.
            }
            /*       else
                  {
                      std::cout << "Already nullptr" << std::endl;
                  } */
            _buflen = 0;
            //  std::cout << "end clearbuf\n";
        };

        void initbuf()
        {
            // clearbuf();
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
            //  std::cout << "before initbuf\n";
            //  initbuf();
            // std::cout << "after initbuf\n";
            size_t slen = strnlen(s, _maxstr); // calculates the length of a given string considering the max size, this makes quickly the check.
            if (slen < 1)
            {
                //   std::cout << "slen?\n";
                return;
            }
            if ((slen + _buflen + 1) > _maxstr)
            {
                // std::cout << "slen2?\n";
                return;
            }
            memcpy(_buf + _buflen, s, slen); // copies s to _buf, considering the size.
            _buflen += slen;                 // update the occupied size.
                                             // clean the last index.
                                             // std::cout << "buf value: " << _buf << std::endl;
            _buf[_buflen] = 0;
            //  clearbuf();
        };

    public:
        nw() : _n(0){};
        nw(const numnum &num) : _n(num) { std::cout << "Object created\n"; };
        ~nw();
        char *shown()
        {
            if (_buf == nullptr)
            {
                // printf("No _buf to show, insert a value n");
                return nullptr;
            }
            return _buf;
            // printf("_buf value: %s \n", _buf);
        }
        char *words(const numnum &num)
        {
            _n = num;
            // std::cout << "num is " << _n << std::endl;
            //   const char *steste;
            //  lets check the singles first
            if (_n > 999)
            {
                printf("Is higher than 999, do the thousands: %ld \n", _n);
                clearbuf();
                return nullptr;
            }
            if (_n > 99 && _n < 1000)
            {
                printf("Doing the hundreds: %ld \n", _n);
                numnum _nrest;
                // first extract the hundreds
                _nrest = (_n - (_n % 100)) / 100; // do the singles.
                for (int i = 0; i <= 9; i++)
                {
                    if (_nrest == i)
                    {
                        // printf("before appendbuf: %ld \n", _n);
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
                        //   shown();
                        break;
                    }
                }
                return shown();
                /*  // then if there is an rest continue with the process, else return.
                 if (_n % 100 > 0)
                 {
                     _n = (_n % 100);
                     if (_n > 19 && _n < 100)
                     {
                         printf("Doing the ty: %ld \n", _n);
                         numnum _numty = 0;
                         // printf("_numty: %ld \n", _numty);
                         //  Check which ty 99 - 99/10, sobra 9. 99 - 9 = 90.ninety.
                         _numty = (_n - (_n % 10)) / 10;
                         //  printf(" new _numty: %ld \n", _numty);
                         if (_n % 10 > 0)
                         {
                             _n = _n % 10;
                             for (int i = 0; i <= 7; i++)
                             {

                                 if (_numty == (i + 2))
                                 {
                                     //           printf("before appendbuf: %ld \n", _numty);
                                     //    clearbuf();
                                     //   initbuf();
                                     appendbuf(" ");
                                     appendbuf(_nty[i]);
                                     break;
                                 }
                             }
                             for (int i = 0; i <= 9; i++)
                             {
                                 if (_n == i)
                                 {
                                     //         printf("before appendbuf: %ld \n", _n);
                                     // clearbuf();
                                     // initbuf();
                                     appendbuf(" ");
                                     appendbuf(_nun[i]);
                                     return shown();
                                     break;
                                 }
                             }
                             return nullptr;
                         }
                         else
                         {
                             for (int i = 0; i <= 7; i++)
                             {

                                 if (_numty == (i + 2))
                                 {
                                     //       printf("before appendbuf: %ld \n", _numty);
                                     //  clearbuf();
                                     // initbuf();
                                     appendbuf(" ");
                                     appendbuf(_nty[i]);
                                     return shown();
                                     break;
                                 }
                             }
                         }
                     }
                     if (_n > 9 && _n < 20)
                     {
                         printf("Doing the tens: %ld \n", _n);
                         for (int i = 0; i <= 9; i++)
                         {
                             if (_n == (i + 10))
                             {
                                 // printf("before appendbuf: %ld \n", _n);
                                 //  clearbuf();
                                 //  initbuf();
                                 appendbuf(" ");
                                 appendbuf(_nteen[i]);
                                 return shown();
                                 break;
                             }
                         }
                         return nullptr;
                     }
                     if (_n < 10)
                     {
                         for (int i = 0; i <= 9; i++)
                         {
                             if (_n == i)
                             {
                                 // printf("before appendbuf: %ld \n", _n);
                                 appendbuf(" ");
                                 appendbuf(_nun[i]);
                                 return shown();
                                 break;
                             }
                         }
                         return nullptr;
                     }
                 }
                 else
                 {
                     return shown();
                     return nullptr;
                 } */
            }
            if (_n > 19 && _n < 100)
            {
                printf("Doing the ty: %ld \n", _n);
                numnum _numty = 0;
                // printf("_numty: %ld \n", _numty);
                //  Check which ty 99 - 99/10, sobra 9. 99 - 9 = 90.ninety.
                _numty = (_n - (_n % 10)) / 10;
                //  printf(" new _numty: %ld \n", _numty);
                if (_n % 10 > 0)
                {
                    _n = _n % 10;
                    for (int i = 0; i <= 7; i++)
                    {

                        if (_numty == (i + 2))
                        {
                            //           printf("before appendbuf: %ld \n", _numty);
                            clearbuf();
                            initbuf();
                            appendbuf(_nty[i]);
                            break;
                        }
                    }
                    for (int i = 0; i <= 9; i++)
                    {
                        if (_n == i)
                        {
                            //         printf("before appendbuf: %ld \n", _n);
                            // clearbuf();
                            // initbuf();
                            appendbuf(" ");
                            appendbuf(_nun[i]);
                            return shown();
                            break;
                        }
                    }
                    return nullptr;
                }
                else
                {
                    for (int i = 0; i <= 7; i++)
                    {

                        if (_numty == (i + 2))
                        {
                            //       printf("before appendbuf: %ld \n", _numty);
                            clearbuf();
                            initbuf();
                            appendbuf(_nty[i]);
                            return shown();
                            break;
                        }
                    }
                }
            }
            if (_n > 9 && _n < 20)
            {
                printf("Doing the tens: %ld \n", _n);
                for (int i = 0; i <= 9; i++)
                {
                    if (_n == (i + 10))
                    {
                        // printf("before appendbuf: %ld \n", _n);
                        clearbuf();
                        initbuf();
                        appendbuf(_nteen[i]);
                        return shown();
                        break;
                    }
                }
            }
            if (_n < 10)
            {
                for (int i = 0; i <= 9; i++)
                {
                    if (_n == i)
                    {
                        // printf("before appendbuf: %ld \n", _n);
                        clearbuf();
                        initbuf();
                        appendbuf(_nun[i]);
                        return shown();
                        break;
                    }
                }
            }
        }
    };
};

int main(int argc, char **argv)
{
    uint64_t n[9] = {1, 12, 25, 98, 100, 101, 125, 256, 999};
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
    // std::cout << "spell the number " << obj->words(n) << std::endl;
    // std::printf("%" PRId64 "\n", n);
    return 0;
}