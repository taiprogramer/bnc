#ifndef BNC_H
#define BNC_H

// [entry macro replace main function]
#define entry int main(int argc, char* argv[])

// [datatypes]
typedef char charvar;

// [stdout: ScreenType]
struct bnc__ScreenType {
    struct bnc__ScreenType (*show)(char*);
    struct bnc__ScreenType (*newline)();
    struct bnc__ScreenType (*c)(charvar);
};

struct bnc__ScreenType bnc__get_screen();

// [stdin: Keyboard]
struct bnc__KeyboardType {
    charvar (*waitForChar)();
};

struct bnc__KeyboardType bnc__get_keyboard();

#endif

