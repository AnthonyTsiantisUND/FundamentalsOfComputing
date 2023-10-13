#include <stdio.h>

typedef struct {
	char name[30];
	int age;
} Person;

int main() {
	Person prsn = {"Pat", 19};

	printf("%s is %d years old\n", prsn.name, prsn.age);

	Person *p;

	p = &prsn;
	
	printf("%s is %d years old\n", (*p).name, (*p).age);
	printf("%s is %d years old\n", p->name, p->age);


	return 0;
}
