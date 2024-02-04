#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char copy(char s[],char c[],int i){
	if(s[i]=='\0'){
		return '\0';
	}
	 c[i]=s[i];
	 return copy(s,c,i+1);
}
void main(){
	int i;
	char s[20],c[20];
	printf("enter the string you want to copy: ");

	scanf("%s",s);
	copy(s,c,0);
	printf("%s\n",c);
}  