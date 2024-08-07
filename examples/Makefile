CFLAGS = -O0 -g -Wall
#CFLAGS = -Os -g -Wall
#CFLAGS = -O1 -g -Wall
#CFLAGS = -O2 -g -Wall
#CFLAGS = -O3 -g -Wall
#CFLAGS = -O3 -Wall
LDFLAGS = -lunwind

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
	$(CC) $(LDLAGS) -o $@ $^ -lunwind

# Build program using new API, set rpath to own built library path
unw_get_proc_name_by_ip__cursor: unw_get_proc_name_by_ip__cursor.o
	$(CC) $(LDLAGS) -o $@ $^ -Wl,-rpath=/usr/local/lib/ -lunwind
unw_get_proc_name_by_ip__static: unw_get_proc_name_by_ip__static.o
	$(CC) $(LDLAGS) -o $@ $^ -Wl,-rpath=/usr/local/lib/ -lunwind
unw_get_proc_name_by_ip__dynamic: unw_get_proc_name_by_ip__dynamic.o
	$(CC) $(LDLAGS) -o $@ $^ -Wl,-rpath=/usr/local/lib/ -lunwind

unw_get_proc_info: unw_get_proc_info.o
	$(CC) $(LDLAGS) -o $@ $^ -lunwind -ldl

unw_get_proc_info_by_ip: unw_get_proc_info_by_ip.o
	$(CC) $(LDLAGS) -o $@ $^ -lunwind -ldl
