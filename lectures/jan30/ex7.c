#include <stdio.h>

int main() {
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	
	if (n >= 0) {	
		printf("Number is positive\n");

	} else {
		printf("Number is negative\n");
	}


	if (n > 4) {
		printf("hi\n");
	} else {
		printf("bye\n");
	}

	return 0;
}


/* 

logical operators:
>
>=
<
<=
==
!=

! --> not
&& --> and
|| --> or

*/
