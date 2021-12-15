# common
CO = gcc -Ofast
# compiler args
CA = -c

S = src/
O = obj/

OBJS = $(O)main.o $(O)functions.o $(O)compute.o
all: $(OBJS)
	$(CO) $(OBJS) -o lr05

$(O)main.o: $(S)main.c
	$(CO) $(CA) $(S)main.c -o $(O)main.o

$(O)functions.o: $(S)functions.c
	$(CO) $(CA) $(S)functions.c -o $(O)functions.o

$(O)compute.o: $(S)compute.c
	$(CO) $(CA) $(S)compute.c -o $(O)compute.o

clean:
	rm obj/*.o && rm lr05
