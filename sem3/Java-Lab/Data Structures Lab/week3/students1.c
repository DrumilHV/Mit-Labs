#include<stdio.h>
#include <stdlib.h>

    struct DOB
    {
        int day;
        int *month;
        int year;
    }dob;
    struct STU_INFO{
        int regno;
        char *name;
        char adderess[30];
    }stu_info;
    struct COLLAGE
    {
        char *collage_name;
        char university_name[30];
    }collage;
    struct students
    {
        struct DOB *dob;
        // struct STU_INFO 
       struct STU_INFO stu_info;
        // struct COLLAGE
         struct COLLAGE collage;
    };
    void accept(struct students *s ){
        printf("\nenter dob day month year:\n");
        scanf("%d%d%d",&(s->dob->day),(s->dob->month),&(s->dob->year));
        printf("\nenter roll number,name,address:\n");
        scanf("%d%s%s",&(s->stu_info.regno),(s->stu_info.name),(s->stu_info.adderess));
        printf("\nenter collage name and university name: \n");
        scanf("%s%s",s->collage.collage_name,s->collage.university_name);

    }
    void display(struct students*s){
        printf("\nroll number: %d\nname: %s\naddress: %s",s->stu_info.regno,s->stu_info.name,s->stu_info.adderess);
        printf("\n%02d/%02d/%04d",s->dob->day,*s->dob->month, s->dob->year);
        printf("\ncollage name: %s and university name: %s\n",s->collage.collage_name,s->collage.university_name);
    }
void main(){
    int n,i;
    printf("enter the number of studnets: ");
    scanf("%d",&n);
    struct students *s;
    s = (struct students*)calloc(n,sizeof(struct students));
    for(i=0;i<n;i++){
        (s+i)->dob = (struct DOB*)malloc(sizeof(struct DOB));
        (s+i)->dob->month = (int*) malloc(sizeof(int));
        (s+i)->stu_info.name = (char*) calloc(20,sizeof(char));
        (s+i)->collage.collage_name = (char*)calloc(25,sizeof(char));
    }
    for(i=0;i<n;i++){
        accept(s+i);
    }
    for(i=0;i<n;i++){
        display(s+i);
    }
}

