TARGET= run
CC=g++
DEBUG=-g
OPT=-O0
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
OBJS= main.o numWorld.o
all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) 

main.o: main.cpp
	$(CC) -c $(CCFLAGS) main.cpp -o main.o

numWorld.o: numWorld.cpp
	$(CC) -c $(CCFLAGS) numWorld.cpp -o numWorld.o
 
clean:
	@rm -f *.o
