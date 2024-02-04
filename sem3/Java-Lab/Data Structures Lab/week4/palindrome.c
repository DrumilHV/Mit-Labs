#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isPalindrome(char *s, int start,int end){
	if(start == end){
		return 1;
	}

	if(*(s+start)!=*(s+end)){
		return 0;
	}

	if(start < end +1){
		return(isPalindrome(s,start+1,end-1));
	}
 	return 1;
}
int main()
{
int start,end,i;
char *str;
str = (char*) malloc(20*sizeof(char));
printf("enter the string: ");
scanf("%s",str);
start = 0;
for(i=0;str[i]!='\0';i++){
printf("%c",str[i]);
};
printf("\n%c",str[0]);
printf("\n%c",str[i-1]);

end = i;
if(isPalindrome(str,start,i-1)==1){
	printf("\nthe string is palindrome.");
}else
  printf("\nthe string is NOT palindrome.");

}