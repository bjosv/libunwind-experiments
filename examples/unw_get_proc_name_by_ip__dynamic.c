#include <stdio.h>
#include <assert.h>
#include <linux/limits.h>
#include <sys/mman.h>

#define UNW_LOCAL_ONLY
#include <libunwind.h>

typedef unsigned int (*asmFunc)(void);

void print_proc_name(void *ptr) {
    unw_word_t offset;
    char proc_name[PATH_MAX];
    int r;

    // Get procedure name for function pointer
    if ((r = unw_get_proc_name_by_ip(unw_local_addr_space, (unw_word_t)ptr, proc_name, PATH_MAX, &offset, NULL))) {
        printf("unw_get_proc_name_by_ip() failure: %s (%d)\n", unw_strerror(r), r);
        assert(0);
    }

    printf("[ptr: 0x%p] %s+0x%lx\n", ptr, proc_name, offset);
}

int main (int argc, char **argv) {
    // Prepare for creating a function dynamically
    unsigned int codeBytes = 4096;
    void *virtualCodeAddress = 0;

    virtualCodeAddress = mmap(NULL,
                              codeBytes,
                              PROT_READ | PROT_WRITE | PROT_EXEC,
                              MAP_ANONYMOUS | MAP_PRIVATE,
                              0,
                              0);

    // Write some code in a function with signature:
    // unsigned int (*asmFunc)(void)
    //
    // The function will just return a constant using:
    // 0:	b8 44 33 22 11       	mov    eax,0x11223344
    // 5:	c3                   	ret
    unsigned char *code = (unsigned char *) (virtualCodeAddress);
    code[0] = 0xb8; // mov (load a 32-bit constant into eax/rax)
    code[1] = 0x44; //
    code[2] = 0x33; //
    code[3] = 0x22; //
    code[4] = 0x11; //
    code[5] = 0xc3; // ret (return)

    // Call created function
    asmFunc func = (asmFunc) (virtualCodeAddress);
    unsigned int out = func();
    assert(out == 0x11223344);

    // Not working!
    print_proc_name(&func);
}
