########################
#Makefile for compilier#
########################

CC = gcc
LD = ld
CFLAGS = -I ./include -o
RM = rm -f

OBJ = lexicalAnalysis.o base.o error.o
.PHONY : clean
clean :
		   $(RM) $(OBJS)




error.o : error.c
	$(CC) $(CFLAGS) $@ $<

base.o : base.c
	$(CC) $(CFLAGS) $@ $<

lexicalAnalysis.o : lexicalAnalysis.c error.h base.h token.h
	$(CC) $(CFLAGS) $@ $<
