# common
CO = gcc -Ofast
# compiler args
CA = -c

S = src/
O = obj/

OBJS = $(O)Lr06.o $(O)my_funk.o $(O)compute.o
all: $(OBJS)
	$(CO) $(OBJS) -o lr06

$(O)Lr06.o: $(S)Lr06.c
	$(CO) $(CA) $(S)Lr06.c -o $(O)Lr06.o

$(O)my_funk.o: $(S)my_funk.c
	$(CO) $(CA) $(S)my_funk.c -o $(O)my_funk.o

$(O)compute.o: $(S)compute.c
	$(CO) $(CA) $(S)compute.c -o $(O)compute.o

clean:
	rm obj/*.o && rm lr06
