#include "queue_fun_char.h"
void main(){
	queue *q;
	q  = (queue*)malloc(sizeof(queue));
				char c;
		int choise;
	do{

		printf("\n1.insert\n2.delete\n3.display\nenter choise: ");
		scanf("%d",&choise);
		switch(choise){
			case 1: 
				printf("enter charecter: ");
				scanf("\n%c",&c);
				insertq(q,c);
				break;
			case 2: 
				printf("\ndeleted : %c",deleteq(q));
				break;
			case 3:
				displayq(q);
				break;
			default: 
				printf("wrong choise");
		}
		printf("do you want to continue?(y/n)");
		scanf("\n%c",&c);
	}while(c =='y');
}