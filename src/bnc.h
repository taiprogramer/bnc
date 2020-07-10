#ifndef BNC_H
#define BNC_H

/**
 * Preprocessor magic to make initializers work somewhat portably
 * Modified from
 * http://stackoverflow.com/questions/1113409/attribute-constructor-equivalent-in-vc
 * I copy from cs50: https://github.com/cs50/libcs50/blob/develop/src/cs50.c
 */
#if defined(_MSC_VER) // MSVC
#pragma section(".CRT$XCU", read)
#define INITIALIZER_(FUNC, PREFIX)                                             \
    static void FUNC(void);                                                    \
    __declspec(allocate(".CRT$XCU")) void (*FUNC##_)(void) = FUNC;             \
    __pragma(comment(linker, "/include:" PREFIX #FUNC "_")) static void FUNC(  \
        void)
#ifdef _WIN64
#define INITIALIZER(FUNC) INITIALIZER_(FUNC, "")
#else
#define INITIALIZER(FUNC) INITIALIZER_(FUNC, "_")
#endif
#elif defined(__GNUC__) // GCC, Clang, MinGW
#define INITIALIZER(FUNC)                                                      \
    static void FUNC(void) __attribute__((constructor));                       \
    static void FUNC(void)
#else
#error The CS50 library requires some compiler-specific features, \
           but we do not recognize this compiler/version. Please file an issue at \
           https://github.com/cs50/libcs50
#endif

// [entry macro replace main function]
#define ENTRY int main(int argc, char* argv[]) {
#define EXIT                                                                   \
    return 0;                                                                  \
    }

// [datatypes]
// char
typedef char charvar;
typedef char* stringvar;

// int
typedef charvar int8var;
typedef unsigned char uint8var;
typedef short int16var;
typedef unsigned short uint16var;
typedef int int32var;
typedef unsigned int uint32var;
typedef long long int int64var;
typedef unsigned long long int uint64var;
typedef int32var intvar;

// real
typedef float real32var;
typedef double real64var;
typedef real64var realvar;

#define ARRAY *

// [stdout: Screen]
struct Screen {
    struct Screen (*show)(stringvar);
    struct Screen (*i)(int64var);
    struct Screen (*c)(charvar);
    struct Screen (*newline)();
    struct Screen (*r)(real64var);
    struct Screen (*s)(stringvar);
} Screen;

// [stdin: Keyboard]
struct Keyboard {
    stringvar (*waitForString)(uint8var max_length);
} Keyboard;

#endif

