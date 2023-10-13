#include <stdio.h>

void disp(int a, int b) {
	printf("%d %d\n", a, b);
}

void fun(int *p, int sz) {
	for (int i = 0; i < sz; i++) {
		(*p)++;
		p++;
	}

}

int main() {
	int a = 2;
	int b = 4;
	int arr[] = {b, a, b};
	int *p = arr;
	fun(p, 3);
	disp(a, b);
	disp(*p, p[1]);
	

	return 0;
}
