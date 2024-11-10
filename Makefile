###############################################################
 #
 #                     MAKEFILE
 #
 #     Assignment: CS 40 Homework 6 - um
 #     Authors:    Joel Lawore (jlawor01) and Henry Zhao (hzhao09)
 #     Last Updated:       11/7/2024
 #
 #     This Makefile is used to compile the um program.
 #
 ###############################################################


############## Variables ###############

# The compiler being used
CC = gcc

# Updating include path to use Comp 40 .h files and CII interfaces
IFLAGS = -I/comp/40/build/include -I/usr/sup/cii40/include/cii

# COMPILER FLAGS
CFLAGS = -g -std=c99 -Wall -Wextra -Werror -Wfatal-errors -pedantic $(IFLAGS)

# LINKER FLAGS
LDFLAGS = -g -L/comp/40/build/lib -L/usr/sup/cii40/lib64

# LINKER LIBRARIES
LDLIBS = -lbitpack -lum-dis -lcii -lcii40 

# Collect all .h files in your directory. This way, you can never forget to add
# a local .h file in your dependencies.
INCLUDES = $(shell echo *.h)

############### Rules ###############

all: um

## Compile step (.c files -> .o files)
%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

## Linking step (.o -> executable program)
um: um.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

clean:
	rm -f *.o um