#include <stdio.h>

unsigned char s[5000], *p = s;

void printbinchar(char c)
{
	for (int i = 7; i >= 0; --i)
    {
        putchar( (c & (1 << i)) ? '1' : '0' );
    }
}

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
		case '\'':
			scanf("%c",p); break;
		case '/':
			*p = (*p >> 3) | (*p << 5); break;
	}
	/*printbinchar(*p);
	printf(" ");
	printbinchar(*p >> 3);
	printf(" ");
	printbinchar(*p << 5);
	printf(" %p %c\n", p, c);*/
}

main(int a, char** b) {
	char c;
	FILE *f = fopen(b[1], "r");
	while (fscanf(f, "%c", &c) != EOF) g(c);
}
