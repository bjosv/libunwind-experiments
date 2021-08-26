#include <stdio.h>
#include <assert.h>
#include <linux/limits.h>

#define UNW_LOCAL_ONLY
#include <libunwind.h>

void print_proc_name(void* ptr) {
    unw_word_t offset;
    char proc_name[PATH_MAX];


    // Get procedure name for function pointer
    if (unw_get_proc_name_by_ip(unw_local_addr_space, (unw_word_t)ptr, proc_name, PATH_MAX, &offset, NULL)) {
        assert(0);
    }

    printf("[ptr: 0x%p] %s+0x%lx\n", ptr, proc_name, offset);
}

void second() {
    printf("This is 'second'");
}

void first() {
    printf("This is 'first'");
}

int main (int argc, char **argv) {
    print_proc_name(&first);
    print_proc_name(&second);
    print_proc_name(&second+1);
    print_proc_name(&second+2);
    print_proc_name(&second+40); // Probably sliding in to function `first`
}
