//
// Created by Issashu Greybeard on 6.09.22.
//

#include "GlobalOverloads.h"
#include <iostream>

namespace Statistics{
    size_t TotalAllocatedMemory = 0;
}

void* operator new(size_t size) {
    Statistics::TotalAllocatedMemory+=size;
   // std::cout << "Allocated total of : " << Statistics::TotalAllocatedMemory << "bytes" << std::endl;
    return malloc(size);
}

void operator delete(void* memory, size_t size) noexcept{
    free(memory);
    Statistics::TotalAllocatedMemory-=size;
    std::cout << "Total left unallocated : " << Statistics::TotalAllocatedMemory << "bytes" << std::endl;
}
