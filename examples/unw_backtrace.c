#include <execinfo.h>
#include <unistd.h>

#define UNW_LOCAL_ONLY
#include <libunwind.h>

#define BACKTRACE_MAX_SIZE 100

void print_backtrace(void)
{
    void *trace[BACKTRACE_MAX_SIZE];
    int n = unw_backtrace(trace, BACKTRACE_MAX_SIZE);

    backtrace_symbols_fd(trace, n, STDOUT_FILENO);
}

void second() {
    print_backtrace();
}

void first() {
    second();
}

int main (int argc, char **argv) {
    first();
}
