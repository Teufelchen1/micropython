#include <unistd.h>
#include <hal/debug.h>
#include <windows.h>
#include "py/mpconfig.h"

// Receive single character, blocking until one is available.
int mp_hal_stdin_rx_chr(void) {
    unsigned char c = 0;
    c = 'A';
    Sleep(1000);
    //int r = read(STDIN_FILENO, &c, 1);
    //(void)r;
    return c;
}

// Send the string of given length.
void mp_hal_stdout_tx_strn(const char *str, mp_uint_t len) {
    //int r = write(STDOUT_FILENO, str, len);
    debugPrint(str);
    // (void)r;
}