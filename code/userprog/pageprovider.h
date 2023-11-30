#include "bitmap.h"
#include "machine.h"
#include "synch.h"

class PageProvider
{
private:
    BitMap* bitmap;
    Lock* lock;
public:
    PageProvider(/* args */);
    ~PageProvider();
    int GetEmptyPage();
    void ReleasePage(int index);
    int NumAvailPage();
};