// #include<stdio.h>
// #include<stdlib.h>
// #define size 7

// struct node
// {
//   int data;
//   struct node *next;
// };

// struct node *chain[size];

// void init()
// {
//   int i;

//   for(i = 0; i < size; i++)
//     chain[i] = NULL;
// }

// void insert(int value)
// {
//   struct node *newNode = malloc(sizeof(struct node));

//   newNode->data = value;
//   newNode->next = NULL;

//   int key = value % size;

//   if(chain[key] == NULL)
//     chain[key] = newNode;

//   else
//   {
//     struct node *temp = chain[key];

//     while(temp->next)
//     {
//       temp = temp->next;
//     }

//     temp->next = newNode;
//   }
// }

// void print()
// {
//   int i;

//   for(i = 0; i < size; i++)
//   {
//     struct node *temp = chain[i];

//     printf("chain[%d]-->",i);

//     while(temp)
//     {
//       printf("%d -->",temp->data);
//       temp = temp->next;
//     }

//     printf("NULL\n");
//   }
// }

// int main()
// {
//   init();
//   insert(7);
//   insert(0);
//   insert(3);
//   insert(10);
//   insert(4);
//   insert(5);
//   print();

//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} NODE;
typedef struct node *nodeptr;
int function(int element, int m)
{
    return element % m;
}
NODE *create_node(int data)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = data;
    temp->link = NULL;
    return temp;
}
NODE *insert(int data, NODE *head)
{
    NODE *temp;
    temp = malloc(sizeof(NODE));
    temp->data = data;
    temp->link = NULL;
    NODE *ptr;
    ptr = head;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
    return head;
}
void display(NODE *head)
{
    NODE *ptr = head;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }
}
int main()
{
    int n, m, s;
    int opcount = 0;
    int arr[50];
    int b[50];
    int flag = 0;
    printf("no of elements :");
    scanf("%d", &n);
    printf("enter the value of m :");
    scanf("%d", &m);
    printf("enter the elements :");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++)
    {
        b[i] = function(arr[i], m);
    }
    NODE **a = (nodeptr *)malloc(m * sizeof(nodeptr));
    *a = malloc(sizeof(NODE));
    for (int i = 0; i < m; i++)
    {
        a[i] = create_node(i);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b[i] == (a[j]->data))
            {
                a[j] = insert(arr[i], a[j]);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        display(a[i]);
        printf("\n");
    }
    printf("enter the number to be searched :");
    scanf("%d", &s);
    int k = function(s, m);
    for (int j = 0; j < m; j++)
    {
        opcount++;
        if (k == (a[j]->data))
        {
            while (a[j]->link != NULL)
            {
                opcount++;
                if (s == a[j]->data)
                {
                    flag = 1;
                    break;
                }
                a[j] = a[j]->link;
            }
            if (flag == 0)
            {
                printf("the element is not found and the unsuccessful search is : %d", opcount);
                break;
            }
            else
            {
                printf("the element is found and the successful search is :%d", opcount);
                break;
            }
        }
    }
}