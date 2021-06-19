#ifndef BNC_H
#define BNC_H

#include <stdint.h>

// [entry macro replace main function]
#define entry int main(int argc, char* argv[])

// [datatypes]
typedef char charvar;
typedef char* stringvar;

// int
typedef int8_t int8var;
typedef uint8_t uint8var;
typedef int16_t int16var;
typedef uint16_t uint16var;
typedef int32_t int32var;
typedef uint32_t uint32var;
typedef int64_t int64var;
typedef uint64_t uint64var;
typedef int32var intvar;

// real
typedef float real32var;
typedef double real64var;
typedef real64var realvar;

// [stdout: ScreenType]
struct bnc__ScreenType {
    struct bnc__ScreenType (*show)(char*);
    struct bnc__ScreenType (*newline)();
    struct bnc__ScreenType (*c)(charvar);
};

// [stdin: Keyboard]
struct bnc__KeyboardType {
    charvar (*waitForChar)();
};

extern const struct bnc__ScreenType Screen;
extern const struct bnc__KeyboardType Keyboard;

#endif

