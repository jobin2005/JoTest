#include<stdio.h>
#define MAX 5
int f=-1,r=-1;
void insert(int queue[])
{
    int x;
    if(f==0&&r==MAX-1)
    {
        printf("Queue is full!");
        return;
    }
    else if(r==-1&&f==-1)
    {
        r++;
        f++;
    }
    else
     {
        r++;
     }
     printf("Enter the element to be inserted into the queue : ");
    scanf("%d",&x);
    queue[r]=x;
    printf("\n Element added to the queue successfully..");
}
void delete(int queue[])
{
    int x;
    if(f==-1)
    {
        printf("Queue is Empty!");
        return;
    }
    x=queue[f];
    printf("\nDeleted item: %d",x);
    if(f==r)
    {
        f=-1,r=-1;
    }
    else{
        f++;
    }
}
void display(int queue[])
{
    if(f==-1)
    {
        printf("Queue is Empty!");
        return;
    }
    printf("\nCurrent Contents of the queue: \n");
    for(int i=f;i<=r;i++)
    {
        printf("%d ",queue[i]);
    }
}
int main()
{
    int queue[MAX];
    int a;
    while(1)
    {
        printf("Select the operation you need to perform with the queue : \n 1. Enqueue 2. Dequeue 3. Exit from the program");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                    insert(queue);
                    display(queue);
                    break;
            case 2:
                    delete(queue);
                    display(queue);
                    break;
            case 3:
                    printf("\nExiting program..");
                    return 0;
            default:
                    printf("Invalid Choice!");

        }
    }


}