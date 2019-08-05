CFLAGS= -Wall -fpic -coverage -lm -std=c99

runtest: testme
	-./testme
	gcov -b testme.c >> testresult.out
	cat testme.c.gcov >> testresult.out

testme: testme.c
	gcc -o testme testme.c -g $(CFLAGS)

clean:
	rm -rf *.o testme *.gcov *.gcda *.gcno *.so *.out *.dSYM