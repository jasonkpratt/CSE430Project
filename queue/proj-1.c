#include<stdio.h>
#include<stdlib.h>
#include "q.h"

int main()
{
    item * head; //local variable to head of queue
    
    InitQueue(&head); //Initializes Queue by setting head pointer to NULL;
    
    item * newItem = NewItem();
    //Initialized field of new item below
    newItem->payload = 1;
    newItem->next = NULL;
    newItem->prev = NULL;
    
    AddQueue(&head, newItem);
    
    //Testing first add
    printf("After first add (1 element in Queue):\n");
    printf("Head->payload = %d\n", head->payload);
    //
    
    newItem = NewItem();
    //Initialized field of new item below
    newItem->payload = 2;
    newItem->next = NULL;
    newItem->prev = NULL;
    
    AddQueue(&head, newItem);
    
    //Testing second add
    printf("After second add (2 elements in Queue):\n");
    printf("Head->payload = %d\n", head->payload);
    printf("Head->next->payload = %d\n", head->next->payload);
    // test
    
    
    newItem = NewItem();
    //Initialized field of new item below
    newItem->payload = 3;
    newItem->next = NULL;
    newItem->prev = NULL;
    
    AddQueue(&head, newItem);
    
    //Testing third add
    printf("After third add (3 elements in Queue):\n");
    printf("Head->payload = %d\n", head->payload);
    printf("Head->next->payload = %d\n", head->next->payload);
    printf("Head->next->next->payload = %d\n", head->next->next->payload);
    //

    newItem = NewItem();
    //Initialized field of new item below
    newItem->payload = 4;
    newItem->next = NULL;
    newItem->prev = NULL;
    
    AddQueue(&head, newItem);
    
    //Testing fourth add
    printf("After fourth add (4 elements in Queue):\n");
    printf("Head->payload = %d\n", head->payload);
    printf("Head->next->payload = %d\n", head->next->payload);
    printf("Head->next->next->payload = %d\n", head->next->next->payload);
    printf("Head->next->next->next->payload = %d\n", head->next->next->next->payload);
    printf("Head->next->next->next->next->payload = %d\n", head->next->next->next->next->payload);
    printf("Head->next->next->next->next->next->payload = %d\n", head->next->next->next->next->next->payload);
    
    //
    
    /*
    //Loop for testing DelQueue function
    for(int i=0; i<10; i++)
    {
        printf("\n\n");
        
        item * del = DelQueue(&head);
        
        if(del != NULL) printf("Deleted payload = %d\n", del->payload);
        
        if(head == NULL)
        {
            printf("Queue is empty\n");
            continue;
        }
        
        printf("After delete:\n");
        printf("Head->payload = %d\n", head->payload);
        
    }
    */
    
    //loop for testing RotateQ function
    for(int i=0; i<10; i++)
    {
        printf("head->payload = %d\n\n", head->payload);
        
        RotateQ(&head);
    }
    
    
    return 0;
    
}
