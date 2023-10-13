#include <stdio.h>

int max(int a, int b) {
	int m;
	m = (a > b) ? a : b;
	return m;
}

// YOU ARE NEVER ALLOWED TO PUT A FUNCTION BEFORE MAIN - PROF R
int main() {
	int a, b, m; 

	a = 5;
	b = 8;

	m = max(a, b);

	printf("max %d\n", m);

	int x = 33, y = 22, z;
	z = max(x, y);


	printf("other max %d\n", z);

	return 0;
}
