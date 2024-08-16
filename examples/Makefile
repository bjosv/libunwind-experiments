CFLAGS ?= -O0 -g -Wall -I$(HOME)/tmp/libunwind/include
LDFLAGS ?= -L$(HOME)/tmp/libunwind/lib -Wl,-rpath,$(HOME)/tmp/libunwind/lib

TARGETS := \
	unw_get_proc_name \
	unw_get_proc_info \
	unw_get_proc_info_by_ip \
	unw_backtrace

NEW_API_TARGETS := \
	unw_get_proc_name_by_ip__cursor \
	unw_get_proc_name_by_ip__static \
	unw_get_proc_name_by_ip__dynamic

all: $(TARGETS)

new: $(NEW_API_TARGETS)

clean:
	rm -rf *.o
	rm -rf $(TARGETS)
	rm -rf $(NEW_API_TARGETS)

unw_get_proc_name: unw_get_proc_name.o
	$(CC) $(LDFLAGS) -o $@ $^ -lunwind

unw_get_proc_info: unw_get_proc_info.o
	$(CC) $(LDFLAGS) -o $@ $^ -lunwind -ldl

unw_get_proc_info_by_ip: unw_get_proc_info_by_ip.o
	$(CC) $(LDFLAGS) -o $@ $^ -lunwind -ldl

unw_backtrace: unw_backtrace.o
	$(CC) $(LDFLAGS) -o $@ $^ -lunwind

# Build program using new API
unw_get_proc_name_by_ip__cursor: unw_get_proc_name_by_ip__cursor.o
	$(CC) $(LDFLAGS) -o $@ $^ -lunwind
unw_get_proc_name_by_ip__static: unw_get_proc_name_by_ip__static.o
	$(CC) $(LDFLAGS) -o $@ $^ -lunwind
unw_get_proc_name_by_ip__dynamic: unw_get_proc_name_by_ip__dynamic.o
	$(CC) $(LDFLAGS) -o $@ $^ -lunwind
