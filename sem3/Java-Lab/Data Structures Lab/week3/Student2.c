#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int day;
	int *month;
	int year;
} DOB;



typedef struct {
	char *collegeName;
	char universityName[50];
} COLLEGE;

typedef struct {
	DOB dob;
	
	struct {
		int regNo;
		char *name;
		char address[50];
	} info;
	
	COLLEGE college;

} STUDENT;

int main(){

	STUDENT *student;
	student = (STUDENT *) calloc(1, sizeof(STUDENT));
	student->dob.month = (int *) calloc(1, sizeof(int));
	student->info.name = (char *) calloc(50, sizeof(char));
	student->college.collegeName = (char *) calloc(50, sizeof(char));
	
	printf("Enter the student name, registration number and address: \n");
	scanf("%s %d %s", student->info.name, &(student->info.regNo), student->info.address);
	
	printf("Enter the date of birth: \n");
	scanf("%d %d %d", &(student->dob.day), student->dob.month, &(student->dob.year));
	
	printf("Enter the college and university name: \n");
	scanf("%s %s", student->college.collegeName, student->college.universityName);

	printf("***************\n");

	printf("Student %s, registration number %d, living at %s\n", student->info.name, student->info.regNo, student->info.address);
	printf("Student is born on %02d/%02d/%02d\n", student->dob.day, *student->dob.month, student->dob.year);
	printf("Student is studying at %s, %s\n", student->college.collegeName, student->college.universityName);

	// free();

	return 0;
}
