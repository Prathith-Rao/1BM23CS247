#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int stack[SIZE];
int top=-1;

void push(int a)
{
    if(top==SIZE-1)
    {
        printf("\nStack is full,overflow condition");
    }
    else
    {
        top++;
        stack[top]=a;
        printf("\nElement successfully pushed to stack");
    }
}
void pop()
{
    if(top==-1)
    {
        printf("\nStack is empty,underflow condition");
    }
    else
    {
        int ele = stack[top];
        printf("\nElement %d has been successfully popped",ele);
        top--;
    }
}
void display()
{
    if(top==-1)
    {
        printf("\nstack is empty,underflow condition");
    }
    else
    {
        for(int i=top;i>-1;i--)
        {
            printf("%d ",stack[i]);
        }
    }
}
void main()
{
    int c,e;
    while(1)
    {
        printf("\n\n1.push\n2.pop\n3.display\n4.exit\nEnter :");
        scanf("%d",&c);
        switch (c)
        {
            case 1: printf("\nEnter the element to push ");
                    scanf("%d",&e);
                    push(e);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(1);
            default : printf("\nInvalid input");
        }
    }
}