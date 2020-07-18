# BNC - A cool way to write C program.

```c
#include "bnc.h"

ENTRY

Screen.show("Hello, world!").newline();

EXIT
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

```bash
gcc -o [executable] [sourcefile] -lbnc
```

## [Uninstallation]

If you don't want to use this library anymore, goto **bnc/** folder & run `make uninstall` to get rid of this library.

## [References]
- [libcs50](https://github.com/cs50/libcs50)
- [C Programming Tutorial: Creating Libraries](https://randu.org/tutorials/c/libraries.php)

