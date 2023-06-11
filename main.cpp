#include "numWorld.hh"

int main(int argc, char **argv)
{
    std::vector<uint64_t> n = {0, 15350, 28542, 456098, 1598097};
    bw::nw *obj = new bw::nw();

    for (int i = 0; i < n.size(); i++)
    {
        printf("vector %ld, _buf:%s\n", n[i], obj->words(n[i]));
    }

    return 0;
}