#include <stdio.h>
#include <string.h>

typedef struct {
	char name[20];
	int age;
	float gpa;
} Student;


void display(Student);

// Use typedef to create an alias
typedef double d;

int main() {
	Student class[3];

	class[0].age = 19; // The . is the member operator
	class[0].gpa = 3.88; // . allows you to access a property of a struct
	strcpy(class[0].name, "Anthony");

	class[1].age = 20;
	class[1].gpa = 3.91;
	strcpy(class[1].name, "Kevin");
	
	class[2].age = 18;
	class[2].gpa = 4.00;
	strcpy(class[2].name, "Al");
	

	for (int i = 0; i < 3; i++) {
		display(class[i]);
	}

	return 0;
}

// Struct is passed by value not a pointer
void display(Student x) {	
	printf("%s is %d years old with a gpa of %.2f.\n", x.name, x.age, x.gpa);
}

