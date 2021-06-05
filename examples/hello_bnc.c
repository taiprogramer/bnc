#include "bnc.h"

entry {
    struct bnc__ScreenType Screen = bnc__get_screen();
    Screen.show("Hello, world!").newline();
}

