#include<stdio.h>
int multiply(int a[][5],b[][5],int result[][5],int r1 , int c2, int r2 , int c1){
    int *aWalk,*bWalk,*aLast, *bLast,*aInner;
    for (aWalk= a,aLast = a+r1-1;aWalk<aLast;aWalk++){
        for(bWalk=b,bLast=b+c2-1;bWalk<bLast;bWalk++){
            for(aInner=a;aInner<a+c1;aInner++){
                *(*(result+aWalk)+bWalk)  = *(*(a+aWalk)+aInner) + *(*(b+aInner)+bWalk);
            }
        }
    }
    return result;

}