#include "bnc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bnc__ScreenType bnc__screen_show(char* message) {
    printf("%s", message);
    return bnc__get_screen();
}

struct bnc__ScreenType bnc__screen_newline() {
    printf("\n");
    return bnc__get_screen();
}

struct bnc__ScreenType bnc__get_screen() {
    const struct bnc__ScreenType Screen = {
	&bnc__screen_show,
	&bnc__screen_newline
    };
    return Screen;
}

