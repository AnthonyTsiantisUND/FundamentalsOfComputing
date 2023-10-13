#include <stdio.h>
#include <string.h>

struct Student {
	char name[20];
	int age;
	float gpa;
};


int main() {
	struct Student x;
	x.age = 19; // The . is the member operator
	x.gpa = 3.88; // . allows you to access a property of a struct
	strcpy(x.name, "Anthony");

	printf("%s is %d years old with a gpa of %.2f.\n", x.name, x.age, x.gpa);




	return 0;
}
