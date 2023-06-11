#include "numWorld.hh"
namespace bw
{
    void nw::clearbuf()
    {
        if (_buf != nullptr)
        {
            delete[] _buf;
            _buf = nullptr;
        }
        _buflen = 0;
    };

    void nw::initbuf()
    {
        try
        {
            _buf = new char[_maxstr]();
            *_buf = 0; // the first char will be 0, for ptr which takes other values, then * returns these values. But for char, if we print _buf, the chars will appears. for numbers, the address will appear, so we need to dereference.
        }
        catch (const std::exception &e)
        {
            std::cerr << "Not possible to init the buffer, fail:" << e.what() << '\n';
        }
    };

    void nw::appendbuf(const char *s)
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
        _buf[_buflen] = 0;
    };

    char *nw::shown()
    {
        return _buf;
    }
    char *nw::words(const numnum &num)
    {
        _n = num;
        if (_n > 999)
        {
            for (size_t i = 3; i > 0; i--)
            {
                numnum power = (numnum)pow(1000.0, i); // pow, 1000^i
                numnum _nrest;
                _nrest = (_n - (_n % power)) / power;
                _n = (_n % power);
                if (_nrest)
                {
                    clearbuf();
                    initbuf();
                    nw *_nrec = new nw();
                    appendbuf(_nrec->words(_nrest)); // process the updated _n
                    appendbuf(" ");
                    appendbuf(_nllions[i]);
                    appendbuf(" ");

                    if (_n > 0)
                    {
                        nw *_nrec2 = new nw();
                        appendbuf(_nrec2->words(_n)); // process the updated _n
                    }
                    break;
                }
            }
            return shown();
        }
        if (_n > 99 && _n < 1000)
        {
            numnum _nrest;
            _nrest = (_n - (_n % 100)) / 100;
            for (size_t i = 0; i <= 9; i++)
            {
                if (_nrest == i)
                {
                    clearbuf();
                    initbuf();
                    appendbuf(_nun[i]);
                    appendbuf(" ");
                    appendbuf(_nhundreds);
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
            numnum _numty = 0;
            _numty = (_n - (_n % 10)) / 10;
            for (size_t i = 0; i <= 7; i++)
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
            //   printf("Doing the tens: %ld \n", _n);
            for (size_t i = 0; i <= 9; i++)
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
            for (size_t i = 0; i <= 9; i++)
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
        else
        {
            return shown();
        }
    }
};
