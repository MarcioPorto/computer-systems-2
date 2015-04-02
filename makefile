# Makefile for homework 2, 240 F14
# author: Marcio Porto  

#problem 1:
tsub_ok: tsub_ok.c
	gcc -o tsub_ok tsub_ok.c
	
#problem 2:
fpwr2: fpwr2.c
	gcc -o fpwr2 fpwr2.c
	
all: tsub_ok fpwr2

run_1: tsub_ok
	./tsub_ok
	
run_2: fpwr2
	./fpwr2
	
clean:
	rm tsub_ok fpwr2