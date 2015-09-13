#include <stdio.h>

unsigned char s[5000], *p = s;
long q = 0;
int x = 0;

void printbinchar(char c)
{
	for (int i = 7; i >= 0; --i)
    {
        putchar( (c & (1 << i)) ? '1' : '0' );
    }
}

g(char c, FILE *f) {
	char u;
	if (x){if (c == '?') x = 0; return 0;}
	//printf("\n%d\n",q);

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
			scanf("%c",p);scanf("%c",&u); break;
		case '/':
			*p = (*p >> 3) | (*p << 5); break;
		case '?':
			if (*p % 2 == 0){ q = ftell(f); x = 1;} else {fseek(f, q+1, SEEK_SET);} break;
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
	while (fscanf(f, "%c", &c) != EOF) g(c,f);
	fclose(f);
}
