#include "system.h"
#ifndef SYSTEM_H
#include "pageprovider.h"
#endif

PageProvider::PageProvider(/* args */)
{
    bitmap = new BitMap(NumPhysPages);
    lock = new Lock("pageslock");
}

PageProvider::~PageProvider()
{
    delete bitmap;
}

int PageProvider::GetEmptyPage()
{
    lock->Acquire();

    int res = bitmap->Find();

    if(!res) { lock->Release(); return res; }

    memset(machine->mainMemory+(res * PageSize), 0, PageSize);

    lock->Release();
    
    return res;
}

void PageProvider::ReleasePage(int index)
{
    lock->Acquire();
    bitmap->Clear(index);
    lock->Release();
}

int PageProvider::NumAvailPage()
{
    return bitmap->NumClear();
}