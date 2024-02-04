#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student{
	int rollno;
	char name[20];
	float CGPA;
};
struct student* accept(struct student *s){
	// s = (struct student*) malloc(sizeof(struct student));
	printf("\nenter rollno: ");
	scanf("%d",&s->rollno);
	printf("\nenter name: ");
	// gets(s->name);
	scanf("%s",s->name);
	printf("\nenter CGPA: ");
	scanf("%f",&s->CGPA);
	return s;
}
void display(struct student *s){
	printf("\nrollno: %d \nname: %s \nCGPA: %f",s->rollno,s->name,s->CGPA);
}
void sortStudent(struct student *s,int n){
	struct student temp;
	for (int i = 0;i<n;i++){
		for(int j=0;j<n-1-i;j++){
			if((s+i)->rollno>(s+i+1)->rollno){
				temp= *(s+i);
				*(s+i) = *(s+i+1);
				*(s+i+1) = temp; 
			}
		}
	}
}
void main(){
	// struct student 
	int n,i;
	printf("enter number of student:\n");
	scanf("%d",&n);
	struct student *s;
	s = (struct student*)calloc(n,sizeof(struct student));
	for(i=0;i<n;i++){
		printf("\nstudent: %d\n",i);
		 accept(s+i);
	}
	sortStudent(s,n);
	for ( i = 0; i < n; ++i)
	{
		printf("\nstudent: %d\n",i);
		display(s+i);
		printf("\n");
	}
	free(s);

}