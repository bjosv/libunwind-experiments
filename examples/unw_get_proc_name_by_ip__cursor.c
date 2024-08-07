#include <stdio.h>
#include <assert.h>
#include <linux/limits.h>

#define UNW_LOCAL_ONLY
#include <libunwind.h>

void print_proc_name() {
    unw_cursor_t    cursor;
    unw_context_t   context;

    unw_getcontext(&context);
    unw_init_local(&cursor, &context);

    while (unw_step(&cursor) > 0) {
        unw_word_t offset, pc;
        char proc_name[PATH_MAX];

        // Get program counter
        if (unw_get_reg(&cursor, UNW_REG_IP, &pc)) {
            assert(0);
        }

        // Get procedure name for instruction pointer (program counter)
        if (unw_get_proc_name_by_ip(unw_local_addr_space, pc, proc_name, PATH_MAX, &offset, NULL)) {
            assert(0);
        }

        printf("[pc: 0x%lx] %s+0x%lx\n", pc, proc_name, offset);
    }
}

void second() {
    print_proc_name();
}

void first() {
    second();
}

int main (int argc, char **argv) {
    first();
}
