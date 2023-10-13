#include <stdio.h>
#include <string.h>

struct Student {
	char name[20];
	int age;
	float gpa;
};


void display(struct Student);

int main() {
	struct Student x;
	x.age = 19; // The . is the member operator
	x.gpa = 3.88; // . allows you to access a property of a struct
	strcpy(x.name, "Anthony");

	struct Student st;
	st.age = 20;
	st.gpa = 3.91;
	strcpy(st.name, "Kevin");

	display(x);
	display(st);

	return 0;
}

// Struct is passed by value not a pointer
void display(struct Student x) {	
	printf("%s is %d years old with a gpa of %.2f.\n", x.name, x.age, x.gpa);
}
