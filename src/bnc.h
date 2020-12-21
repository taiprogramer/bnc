#ifndef BNC_H
#define BNC_H

// [entry macro replace main function]
#define entry int main(int argc, char* argv[])

// [stdout: ScreenType]
struct bnc__ScreenType {
    struct bnc__ScreenType (*show)(char*);
    struct bnc__ScreenType (*newline)();
};

struct bnc__ScreenType bnc__get_screen();

#endif

