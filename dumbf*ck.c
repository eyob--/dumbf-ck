#include <stdio.h>

g(char c) {

}

main(int a, char** b) {
	char c;
	FILE *f = fopen(b[1], "r");
	while (fscanf(f, "%c", &c) != EOF) g(c);
}
