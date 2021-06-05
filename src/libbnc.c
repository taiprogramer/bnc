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

charvar bnc__wait_for_char() {
    charvar c = getchar();

    if (c == '\n' || c == EOF)
	return c;
    
    // clear stdin buffer
    charvar tmp;
    while(tmp = getchar(), tmp != '\n' && tmp != EOF);

    return c;
}

struct bnc__KeyboardType bnc__get_keyboard() {
    struct bnc__KeyboardType Keyboard = {
	&bnc__wait_for_char
    };
    return Keyboard;
}
