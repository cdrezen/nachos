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
    
    if(res) memset(0, machine->mainMemory[res * PageSize], sizeof(int));

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