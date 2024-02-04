#include<stdio.h>
#include<stdlib.h>

void tower(int n, char from,char aux , char to){
	if(n==1){
		printf("move the disk form %C to %c",from,to);
		return;
	}
	tower(n-1,from,to,aux);
	printf("\nmove disk %d from %c to %c",n,from,to);
	tower(n-1,aux,from,to);
}
void  main()
{
	int n;
	char a,b,c;
	printf("enter the number and charecters: ");
	scanf("%d",&n);
	// scanf("%c",&a);
	// scanf("%c",&b);
	// scanf("%c",&b);
	tower(n,'a','b','c');
}