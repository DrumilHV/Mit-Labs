#include <stdio.h>

struct  complex
{
	int real;
	int imag;
};
 struct complex add(struct complex c1, struct complex c2){
 	struct complex c3;
 	c3.real = c1.real+c2.real;
 	c3.imag  = c1.imag + c2.imag;
 	return c3;
  }
 struct complex substract(struct complex c1,struct complex c2){
  	struct complex c3;
 	c3.real = c1.real - c2.real;
 	c3.imag  = c1.imag - c2.imag;
 	return c3;
  }
 struct complex multiply(struct complex c1,struct complex c2){
  	struct complex c3;
 	c3.real = c1.real*c2.real - c1.imag*c2.imag;
 	c3.imag  = c1.real*c2.imag + c2.imag*c1.real;
 	return c3;
  }
 struct complex accept(struct complex c){
  	scanf("%d %d",&c.real,&c.imag);
  	return c;
  }
  void display(struct complex c){
  	if(c.imag>0)
  		printf(" %d + %di",c.real,c.imag);
	else
	  	printf(" %d %di",c.real,c.imag);
  }
  void  main(){
  	struct complex c1,c2,c3;
  	printf("enter complex and imagnary part of complex no 1: \n");
  	c1 = accept(c1);
  	printf("enter complex and imagnary part of complex no 2: \n");
  	c2 = accept(c2);
  	printf("\nsum:");
  	display(add(c1,c2));
  	printf("\ndiffrence: ");
  	display(substract(c1,c2));
  	printf("\nMultiplication: ");
  	display(multiply(c1,c2));
  }