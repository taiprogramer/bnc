#include "bnc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static struct bnc__ScreenType bnc__screen_show(char* message) {
    fputs(message, stdout);
    return Screen;
}

static struct bnc__ScreenType bnc__screen_newline() {
    fputc('\n', stdout);
    return Screen;
}

static struct bnc__ScreenType bnc__screen_c(charvar c) {
    fputc(c, stdout);
    return Screen;
}

static charvar bnc__wait_for_char() {
    charvar c = getchar();

    if (c == '\n' || c == EOF)
	return c;
    
    // clear stdin buffer
    charvar tmp;
    while(tmp = getchar(), tmp != '\n' && tmp != EOF);

    return c;
}

const struct bnc__KeyboardType Keyboard = {
    &bnc__wait_for_char
};

const struct bnc__ScreenType Screen = {
    &bnc__screen_show,
    &bnc__screen_newline,
    &bnc__screen_c
};

