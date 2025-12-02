CC = gcc
CFLAGS = -Wall -Wextra -g -O0

all: insecure_app_fixed

insecure_app_fixed: insecure_app_fixed.c
	$(CC) $(CFLAGS) -o insecure_app_fixed insecure_app_fixed.c

clean:
	rm -f insecure_app_fixed

