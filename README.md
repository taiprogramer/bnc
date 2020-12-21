# BNC - A cool way to write C program.

**Note**: This library is under development. Enjoy it if you like. But **DO NOT** use in production.


`hello_bnc.c`

```c
#include "bnc.h"

entry {
    struct bnc__ScreenType Screen = bnc__get_screen();
    Screen.show("Hello, world!").newline();
}
```

## [Installation]

**On Linux**:

1. Clone this repo or [download a zip archive](https://github.com/taiprogramer/bnc/archive/master.zip).

```
git clone https://github.com/taiprogramer/bnc
```

If you choose to download a zip file, remember to extract.

2. Goto **bnc/** folder & run make command

Require `sudo` or `root` user.

```
make install
```

Now, you're ready to go!

To compile your program, just simply add -lbnc flag.

```sh
tcc -o [executable] [sourcefile] -lbnc
```

## [Uninstallation]

If you don't want to use this library anymore, goto **bnc/** folder & run `make uninstall` to get rid of this library.

## [References]
- [C Programming Tutorial: Creating Libraries](https://randu.org/tutorials/c/libraries.php)

