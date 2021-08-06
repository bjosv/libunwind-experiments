CFLAGS = -O0 -g -Wall
#CFLAGS = -Os -g -Wall
LDFLAGS = -lunwind

TARGETS := unw_get_proc_name unw_get_proc_info

all: $(TARGETS)

clean:
	rm -rf *.o
	rm -rf $(TARGETS)

unw_get_proc_name: unw_get_proc_name.o
	$(CC) $(LDLAGS) -o $@ $^ -lunwind

unw_get_proc_info: unw_get_proc_info.o
	$(CC) $(LDLAGS) -o $@ $^ -lunwind -ldl
