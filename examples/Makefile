CFLAGS ?= -O0 -g -Wall
#CFLAGS = -Os -g -Wall
#CFLAGS = -O1 -g -Wall
#CFLAGS = -O2 -g -Wall
#CFLAGS = -O3 -g -Wall
#CFLAGS = -O3 -Wall

TARGETS := \
	unw_get_proc_name \
	unw_get_proc_name_by_ip__cursor \
	unw_get_proc_name_by_ip__static \
	unw_get_proc_name_by_ip__dynamic \
	unw_get_proc_info \
	unw_get_proc_info_by_ip

all: $(TARGETS)

clean:
	rm -rf *.o
	rm -rf $(TARGETS)

unw_get_proc_name: unw_get_proc_name.o
	$(CC) $(LDFLAGS) -o $@ $^ -lunwind

unw_get_proc_info: unw_get_proc_info.o
	$(CC) $(LDFLAGS) -o $@ $^ -lunwind -ldl

unw_get_proc_info_by_ip: unw_get_proc_info_by_ip.o
	$(CC) $(LDFLAGS) -o $@ $^ -lunwind -ldl

# Build program using new API
unw_get_proc_name_by_ip__cursor: unw_get_proc_name_by_ip__cursor.o
	$(CC) $(LDFLAGS) -o $@ $^ -lunwind
unw_get_proc_name_by_ip__static: unw_get_proc_name_by_ip__static.o
	$(CC) $(LDFLAGS) -o $@ $^ -lunwind
unw_get_proc_name_by_ip__dynamic: unw_get_proc_name_by_ip__dynamic.o
	$(CC) $(LDFLAGS) -o $@ $^ -lunwind
