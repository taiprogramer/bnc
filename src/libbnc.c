#include "bnc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static stringvar ARRAY strings = NULL;
static uint64var number_of_strings_that_have_been_allocated = 0;

static void clean_up() {
    for (int i = 0; i < number_of_strings_that_have_been_allocated; ++i) {
        free(strings[i]);
    }
    free(strings);
}

/**
 * Called automatically before execution enters main.
 */
INITIALIZER(setup) { atexit(clean_up); }

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

// [stdin: Keyboard]
stringvar keyboard_wait_for_string(uint8var max_length) {
    stringvar s = (stringvar)malloc(sizeof(charvar) * (max_length + 1));

    if (s == NULL) {
        return NULL;
    }

    fgets(s, max_length + 1, stdin);

    uint8var len = (uint8var)strlen(s);
    if (s[len - 1] == '\r' || s[len - 1] == '\n' || s[len - 1] == EOF) {
        s[len - 1] = '\0';
    }

    stringvar temp = s;
    s = (stringvar)malloc(sizeof(charvar) * (strlen(s) + 1));

    if (s == NULL) {
        free(temp);
        return NULL;
    }

    strcpy(s, temp);

    // add $s to $strings for auto free after used
    if (strings == NULL) {
        strings = (stringvar ARRAY)malloc(sizeof(stringvar));
    } else {
        strings = (stringvar ARRAY)realloc(
            strings, number_of_strings_that_have_been_allocated + 1);
    }

    if (strings == NULL) {
        free(s);
        free(temp);
        return NULL;
    }

    free(temp);
    strings[number_of_strings_that_have_been_allocated] = s;
    number_of_strings_that_have_been_allocated++;

    return s;
}

struct Keyboard Keyboard = {&keyboard_wait_for_string};

