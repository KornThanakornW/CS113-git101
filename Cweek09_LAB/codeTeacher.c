#include <stdio.h> 
#include <stdlib.h> 

//1)WAY1
struct node { 
   int data; 
   struct node *next; 
}; 
  
void queue_list(struct node **head, struct node **tail, int input[], int n)
{  int i;

   for (i=0; i < n; i++) {
      if (*head == NULL)
         *head = *tail = (struct node *)malloc(sizeof(struct node));
      else {
         (*tail)->next = (struct node *)malloc(sizeof(struct node));
         *tail = (*tail)->next;
      }
      (*tail)->data = input[i];
      (*tail)->next = NULL;
   }
}

void stack_list(struct node **head, struct node **tail, int input[], int n)
{  int i;
   struct node *tmp;

   for (i=0; i < n; i++) {
      tmp = (struct node *)malloc(sizeof(struct node));
      if (*head == NULL) {
         *head = *tail = tmp;
         tmp->next = NULL;
      }
      else {
         tmp->next = *head;
         *head = tmp;
      }
      (*head)->data = input[i];
   }
}

void print_list(struct node *head)
{
   for (; head; head = head->next)
      printf("%d ", head->data);
   putchar('\n');
}

struct node *delete_node(struct node **head, struct node **tail, int item)
{  struct node *prev, *tmp=*head;

   if (tmp && tmp->data == item) { 
      if (*head == *tail)
         *head = *tail = tmp->next;
      else
         *head = tmp->next;
      return tmp; 
   }    
   for (; tmp && tmp->data != item; tmp = tmp->next)
      prev = tmp;
   if (tmp) {
      prev->next = tmp->next;
      if (*tail == tmp)
         *tail = prev;
   }
   return tmp;
}

int main() 
{  int input[] = {1, 3, 5, 7, 2, 4, 8};
   int n, i;
   struct node *head=NULL, *tail=NULL, *tmp;

   n = sizeof(input)/sizeof(input[0]);
   queue_list(&head, &tail, input, n);
   //stack_list(&head, &tail, input, n);
   print_list(head);
   tmp = delete_node(&head, &tail, 8);
   free(tmp);
   print_list(head);
   tmp = delete_node(&head, &tail, 7);
   free(tmp);
   print_list(head);
   tmp = delete_node(&head, &tail, 1);
   free(tmp);
   print_list(head);
}



//2) WAY2
#include <stdio.h> 
#include <stdlib.h> 
  
typedef struct node { 
   struct node *prev;
   int data; 
   struct node *next; 
} Node; 
  
Node *create_list()
{  Node *first, *second, *third; 
  
   first = (Node *)malloc(sizeof(Node));
   second = (Node *)malloc(sizeof(Node));
   third = (Node *)malloc(sizeof(Node));
  
   first->data = 17; 
   first->prev = third;
   first->next = second;

   second->data = 29; 
   second->prev = first; 
   second->next = third; 
  
   third->data = 93;
   third->prev = second; 
   third->next = first; 
    
   return first;
}

int main() 
{  Node *head, *tmp;

   head = create_list();
   tmp = head;
   while (tmp) {
      printf("%d ", tmp->data);
      tmp = tmp->next;
      if (tmp == head)
         break;
   }
}
