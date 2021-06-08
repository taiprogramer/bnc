#include "bnc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bnc__ScreenType bnc__screen_show(char* message) {
    fputs(message, stdout);
    return bnc__get_screen();
}

struct bnc__ScreenType bnc__screen_newline() {
    fputc('\n', stdout);
    return bnc__get_screen();
}

struct bnc__ScreenType bnc__screen_c(charvar c) {
    fputc(c, stdout);
    return bnc__get_screen();
}

struct bnc__ScreenType bnc__get_screen() {
    struct bnc__ScreenType Screen;
    Screen.newline = bnc__screen_newline;
    Screen.show = bnc__screen_show;
    Screen.c = bnc__screen_c;
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
    struct bnc__KeyboardType Keyboard;
    Keyboard.waitForChar = bnc__wait_for_char;
    return Keyboard;
}
