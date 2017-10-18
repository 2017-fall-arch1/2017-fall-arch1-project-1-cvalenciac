all:demolab


demolab: BST.o BSTDemo.o
	cc -o $@ $^

BST.o: BST.c BST.h
	cc -c $(CFLAGS) BST.c

BSTDemo.o: BSTDemo.c BST.h 
	cc -c $(CFLAGS) BSTDemo.c

clean:
	rm -f *.o demolab

demo: demolab
	(echo first; echo "second line"; echo "third and last") | ./demolab
