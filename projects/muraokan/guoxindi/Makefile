CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
#gcc -o randomtestcard1 randomtestcard1.c dominion.c rngs.c $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

# Here is the makefile command for assignment4
randomtestcard1: randomtestcard1.c dominion.o refactor.o rngs.o
	gcc -o randomtestcard1 -g  randomtestcard1.c dominion.o refactor.o rngs.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o refactor.o rngs.o
	gcc -o randomtestcard2 -g  randomtestcard2.c dominion.o refactor.o rngs.o $(CFLAGS)

randomtestcard3: randomtestcard3.c dominion.o refactor.o rngs.o
	gcc -o randomtestcard2 -g  randomtestcard3.c dominion.o refactor.o rngs.o $(CFLAGS)

randomtestcard1.out:  randomtestcard1
	./randomtestcard1 5 &> randomtestcard1.out
	gcov -b dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out
	gcov -b dominion.c >> randomtestcard1.out
	cat refactor.c.gcov >> randomtestcard1.out

randomtestcard2.out:  randomtestcard2
	./randomtestcard2 3 &> randomtestcard2.out
	gcov -b dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out
	gcov -b dominion.c >> randomtestcard2.out
	cat refactor.c.gcov >> randomtestcard2.out

randomtestcard3.out:  randomtestcard3
	./randomtestcard3 3 &> randomtestcard3.out
	gcov -b dominion.c >> randomtestcard3.out
	cat dominion.c.gcov >> randomtestcard3.out
	gcov -b dominion.c >> randomtestcard3.out
	cat refactor.c.gcov >> randomtestcard3.out
# Make file for assignment4 has finished in here

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
