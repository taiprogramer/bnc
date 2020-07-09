#include <stdio.h>
#include "bnc.h"

// [stdout: Screen]
struct Screen screen_show(stringvar message) {
    printf("%s", message);
    return Screen;
}

struct Screen screen_i(int64var l) {
    printf("%lld", l);
    return Screen;
}

struct Screen screen_c(charvar c) {
    printf("%c", c);
    return Screen;
}

struct Screen screen_newline() {
    printf("\n");
    return Screen;
}

struct Screen screen_r(real64var r) {
    printf("%g", r);
    return Screen;
}

struct Screen screen_s(stringvar message) {
    screen_show(message);
    return Screen;
}

struct Screen Screen = {&screen_show,    &screen_i, &screen_c,
                        &screen_newline, &screen_r, &screen_s};


