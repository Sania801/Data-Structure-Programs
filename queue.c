#include <stdio.h>
int arr[10];

void enqueue();
void dequeue();
void display();
void  close();
int rear=0;
int front=1;
int item,i;
int main()
{
    int c;
    char ans;
    do
    {
       printf("\n Enter 1 for enqueue: ");
       printf("\n Enter 2 for dequeue: ");
       printf("\n Enter 3 for Display:  ");
       printf("\n Enter 4 for exit:");
       printf("\nEnter your choice: ");
       scanf("%d",&c);
       switch (c)
       {
          case 1:
           enqueue();
           break;
          case 2:
           dequeue();
           break;
          case 3:
           display();
            break;
          case 4:
            exit(1);
          default:
            printf("wrong input");
        }
        printf("\ndo you want to continue?yes/no:");
        scanf("%s",&ans);
    }while(ans=='y');
}
void enqueue()
{
    if(rear<11)
    {
        rear=rear+1;
        printf("enter the item to be inserted:");
        scanf("%d",&arr[rear]);
    }
    else
    {
        printf("Queue overflow");
    }
}
void dequeue()
{
      if(rear>=front)
      {
        printf(" %d   is removed",arr[front]);
        front=front+1;
      }
      else
      {
        printf("underflow");
      }
}
void display()
{
    printf("the queue is:");
    for(i=front;i<=rear;i++)
    {
        printf("\n%d",arr[i]);
    }
}
