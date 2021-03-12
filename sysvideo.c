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

int sys_clearscreen(void) {
    clearscreen();
    return 0;
}

int sys_placepixel(void) {
    int x, y, colour;
    argint(0, &x), argint(1, &y), argint(2, &colour);
    setpixel(x, y ,colour);

    return 0;
}

// TODO: Implement your system call for switching video modes (and any other video-related syscalls)
// in here.
