#include <stdio.h>

char s[5000], *p = s;

g(char c) {
	switch (c) {
		case '<':
			p++; break;
		case '>':
			p--; break;
		case '.':
			*p ^= 1; break;
		case ',':
			printf("%c",*p); break;
		case '/':
			*p = (*p >> 3) | (*p << 5); break;
	}
}

main(int a, char** b) {
	char c;
	FILE *f = fopen(b[1], "r");
	while (fscanf(f, "%c", &c) != EOF) g(c);
}
