#include <stdio.h>
#include<stdlib.h>
// #include <std.h>

struct date{
	int day;
	int month;
	int year;
};
struct address
{
	char houseNo[10];
	int zip;
	char state[];	
};
struct employee{
	char name[20];
	struct date DOB;
	struct address house;
};
void accept(struct employee *emp){
	printf("\nenter name:");
	scanf("%s",emp->name);
	printf("\nenter date of birth (dd mm yy) (put only spaces): ");
	scanf("%d%d%d",&emp->DOB.day,&emp->DOB.month,&emp->DOB.year);
	printf("enter address:\nhouse number: ");
	scanf("%s",emp->house.houseNo);
	printf("zip: ");
	scanf("%d",&emp->house.zip);
	printf("enter state: ");
	scanf("%s",emp->house.state);
}
// void accept(struct employee emp){
// 	printf("\nenter name:");
// 	scanf("%s",&emp.name);
// 	printf("\nenter date of birth (dd mm yy) (put only spaces): ");
// 	scanf("%d%d%d",&emp.DOB.day,&emp.DOB.month,&emp.DOB.year);
// 	printf("enter address:\nhouse number: ");
// 	scanf("%s",emp.house.houseNo);
// 	printf("zip: ");
// 	scanf("%d",emp->house.zip);
// 	printf("\nenter state: ");
// 	gets(emp.house.state);
// }
void display(struct employee *emp){
	printf("////////////////////////////////////////<>//////////////////////////////////");
	printf("\nname: %s\ndate of birth: %d/%d/%d \naddress:\nhouse: %s\nzip: %d\nstate: %s\n ",emp->name,emp->DOB.day,emp->DOB.month,emp->DOB.year,emp->house.houseNo,emp->house.zip,emp->house.state);
}
// void display(struct employee emp){
// 	printf("name: %d\ndate of birth: %d/%d/%d \naddress:\nhouse: %s\nzip: %d\nstate: %s ",emp.name,emp.DOB.day,emp.DOB.month,emp.DOB.year,emp.house.houseNo,emp.house.zip,emp.house.state);
// }
void main(){
	// struct employee *emp;
	int n,i;
	printf("enter number of emplyees: ");
	scanf("%d",&n);
	// emp = (struct employee *)calloc(n, sizeof(struct employee));
	struct employee emp[n],*empPtr;
	empPtr = emp;
	for(i=0;i<n;i++){
		accept(empPtr+i);
	}
	empPtr = emp;
	printf("\nThe employee list is :\n ");
	for(i=0;i<n;i++){
		display(empPtr+i);
	}

}