//
// Created by Issashu Greybeard on 6.09.22.
//

#ifndef OCADO_TEST_RER_GLOBALOVERLOADS_H
#define OCADO_TEST_RER_GLOBALOVERLOADS_H

#include <cstddef>

void* operator new(size_t size);
void operator delete(void* memory, size_t size);


#endif //OCADO_TEST_RER_GLOBALOVERLOADS_H
