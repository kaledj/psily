

psily:
	gcc infinite.c -o infinite -std=c99
	gcc ttyParse.c -o ttyParse -std=c99
	gcc timeParse.c -o timeParse -std=c99

clean:
	rm infinite
