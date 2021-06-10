#include "bnc.h"
#include <assert.h>

entry {
    assert(sizeof(charvar) == 1);
    assert(sizeof(int8var) == 1);
    assert(sizeof(uint8var) == 1);
    assert(sizeof(int16var) == 2);
    assert(sizeof(uint16var) == 2);
    assert(sizeof(int32var) == 4);
    assert(sizeof(uint32var) == 4);
    assert(sizeof(int64var) == 8);
    assert(sizeof(uint64var) == 8);
    assert(sizeof(intvar) == 4);
    assert(sizeof(real32var) == 4);
    assert(sizeof(real64var) == 8);
    assert(sizeof(realvar) == 8);
    return 0;
}
