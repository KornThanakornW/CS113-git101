// 6210407960 ,Thanakorn Wongsanit
#include <stdio.h> 
#include <stdlib.h>

struct node { 
   int data; 
   struct node *next; 
};


void allocate_list(struct node **head ,struct node *inputNum)
{
    
    struct node *pointNow;
    if(*head==NULL  ||  (*head)->data >= inputNum->data){
        inputNum->next = *head;
        *head = inputNum;
    }
    else{
        pointNow=*head;
        while(pointNow->next != NULL  &&  (pointNow->next)->data < inputNum->data ){
            pointNow = pointNow->next;
        }
        inputNum->next = pointNow->next;
        pointNow->next = inputNum;
    }
}


struct node *allocateNewNum(int input){
    struct node *inputNum = (struct node *)malloc(sizeof(struct node));
    inputNum->data  = input; 
    inputNum->next =  NULL; 
    return inputNum; 
}


int main()
{
    int X;
    struct node *head = NULL;
    while(scanf("%d" ,&X) == 1){
        if(X==-1){
            break;
        }
        else if(X>=0){
            struct Node *inputNum = allocateNewNum(X);
            allocate_list(&head ,inputNum);  
        } 
    }
    for( ;head ;head=head->next){
        printf("%d\n" ,head->data);
    }
}