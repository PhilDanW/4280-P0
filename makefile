all: P0 

P0: 
	gcc -Wall main.c node.c tree.c -o P0

clean:
	rm P0 *order
