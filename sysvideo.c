#include "types.h"
#include "defs.h"

int sys_getch(void) {
    return consoleget();
}

int sys_greeting(void) {
    cprintf("Hello, user\n");

    return 0;
}

int sys_setvideomode(void) {
    consolevgamode(0x13);
    cprintf("Video mode set (VGA mode 13h).");

    return 0;
}

// TODO: Implement your system call for switching video modes (and any other video-related syscalls)
// in here.
