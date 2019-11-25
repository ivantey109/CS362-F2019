CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

unittest1: unittest1.c dominion.o refactor.o rngs.0
	gcc -o unittest1 -g unittest1.c dominion.o refactor.o rngs.o $(CFLAGS)

unittest1.out: unittest1
	./unittest1 5 &> unittest1.out
	gcov -b dominion.c >> unittest1.out
	cat dominion.c.gcov >> unittest1.out
	gcov -b refactor.c >> unittest1.out
	cat refactor.c.gcov >> unittest1.out

unittest2: unittest2.c dominion.o refactor.o rngs.0
	gcc -o unittest2 -g unittest2.c dominion.o refactor.o rngs.o $(CFLAGS)

unittest2.out: unittest2
	./unittest2 5 &> unittest2.out
	gcov -b dominion.c >> unittest2.out
	cat dominion.c.gcov >> unittest2.out
	gcov -b refactor.c >> unittest2.out
	cat refactor.c.gcov >> unittest2.out

unittest3: unittest3.c dominion.o refactor.o rngs.0
	gcc -o unittest3 -g unittest3.c dominion.o refactor.o rngs.o $(CFLAGS)

unittest3.out: unittest3
	./unittest3 5 &> unittest3.out
	gcov -b dominion.c >> unittest3.out
	cat dominion.c.gcov >> unittest3.out
	gcov -b refactor.c >> unittest3.out
	cat refactor.c.gcov >> unittest3.out

unittest4: unittest4.c dominion.o refactor.o rngs.0
	gcc -o unittest4 -g unittest4.c dominion.o refactor.o rngs.o $(CFLAGS)

unittest4.out: unittest4
	./unittest4 5 &> unittest4.out
	gcov -b dominion.c >> unittest4.out
	cat dominion.c.gcov >> unittest4.out
	gcov -b refactor.c >> unittest4.out
	cat refactor.c.gcov >> unittest4.out

unittest5: unittest5.c dominion.o refactor.o rngs.0
	gcc -o unittest5 -g unittest.c dominion.o refactor.o rngs.o $(CFLAGS)

unittest5.out: unittest1
	./unittest5 5 &> unittest5.out
	gcov -b dominion.c >> unittest5.out
	cat dominion.c.gcov >> unittest5.out
	gcov -b refactor.c >> unittest5.out
	cat refactor.c.gcov >> unittest5.out

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

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
