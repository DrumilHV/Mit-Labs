#include "queue_fun.h"
void main(){
	queue *q;
		int c;
		int choise;
		int search;
	q  = (queue*)malloc(sizeof(queue));
	do{

		printf("\n1.insert\n2.delete\n3.display\n4.serch if present\nenter choise: ");
		scanf("%d",&choise);
		switch(choise){
			case 1: 
				printf("enter charecter: ");
				scanf("\n%d",&c);
				insertq(q,c);
				break;
			case 2: 
				printf("\ndeleted : %c",deleteq(q));
				break;
			case 3:
				deleteq(q);
				break;
			case 4: 
				printf("enter the element to serch: ");
				scanf("\n%d",&search);
				printf("the queue does");
				if(serchq(q,search)){
					printf("have element %d\n",search);
				}else{
					printf(" not have element %d\n",search);
				}
				break;

			default: 
				printf("wrong choise");
		}
		printf("do you want to continue?(y/n)");
		scanf("\n%c",&c);
	}while(c =='y');
}