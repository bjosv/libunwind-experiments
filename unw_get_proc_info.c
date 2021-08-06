#define _GNU_SOURCE
#include <stdio.h>
#include <assert.h>
#include <linux/limits.h>

// Add dladdr() and Dl_info, requires _GNU_SOURCE
#include <dlfcn.h>

#define UNW_LOCAL_ONLY
#include <libunwind.h>

void print_proc_info() {
    unw_cursor_t    cursor;
    unw_context_t   context;

    unw_getcontext(&context);
    unw_init_local(&cursor, &context);

    while (unw_step(&cursor) > 0) {
        unw_proc_info_t pip;
        pip.unwind_info = NULL;

        // Get procedure info
        if (unw_get_proc_info(&cursor, &pip)) {
            assert(0);
        }

        // Get procedure name that produced stack frame identified by cursor
        unw_word_t offset;
        char proc_name[PATH_MAX];
        if (unw_get_proc_name(&cursor, proc_name, PATH_MAX, &offset)) {
            assert(0);
        }

        void *ptr = (void *)(pip.start_ip + offset);

        // Translate address to symbolic information
        Dl_info dlinfo;
        const char *fname = "?";
        if (dladdr(ptr, &dlinfo) && dlinfo.dli_fname && *dlinfo.dli_fname) {
            // Pathname of shared object that contains address
            fname = dlinfo.dli_fname;
        }

        printf("%s (%s+0x%lx) [%p]\n", fname, proc_name, offset, ptr);
    }
}

void second() {
    print_proc_info();
}

void first() {
    second();
}

int main (int argc, char **argv) {
    first();
}
