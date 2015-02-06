#include<stdio.h>
#include<stdlib.h>


typedef struct item {
    int payload;
    struct item* prev;
    struct item* next;
    
} item;


/*
  Initializes Queue by setting head and tail pointers to NULL
*/
void InitQueue(item ** head)
{
    (*head) = NULL; //sets the pointer head to NULL since Queue is empty
}

 

/*
  Initializes new memoery for an item. Does not intialize fields of item. Only returns a pointer to that item.
*/
item * NewItem()
{
    item * new_item = (item*)malloc(sizeof(item));
    
    return new_item;
}

/*
 Inserts item at head->prev(tail of Queue)
*/
void AddQueue(item ** addr_head, item * newItem)
{
    
    if(*addr_head == NULL) //Queue is empty
    {
        *addr_head = newItem; //setting head equal to newItem
        newItem->prev = newItem; //set prev equal to itself since only 1 element in Queue
        newItem->next = newItem; //set next equal to itself since only 1 element in Queue
    }
    else if((*addr_head != NULL) && ((*addr_head)->next == (*addr_head))) //Queue has only one elements
    {
        newItem->prev = (*addr_head)->prev;
        newItem->next = (*addr_head)->next;
        (*addr_head)->prev = newItem;
        (*addr_head)->next = newItem;

    }
    else //there is at least 2 elements in the Queue
    {
        newItem->prev = (*addr_head)->prev;
        newItem->next = (*addr_head);
        (*addr_head)->prev = newItem;
        newItem->prev->next = newItem;
    }
    
}

/*
 Deletes item at head of Queue
*/
item * DelQueue(item ** addr_head)
{
    if((*addr_head) == NULL) //if Queue is empty
    {
        return NULL;
    }
    else if((*addr_head) == (*addr_head)->next) //if there is only one element in Queue
    {
        item * del_item = (*addr_head);
        (*addr_head) = NULL;
        return del_item;
    }
    else
    {
        item * del_item = (*addr_head);
        
        (*addr_head)->next->prev = (*addr_head)->prev;
        (*addr_head)->prev->next = (*addr_head)->next;
        
        *addr_head = (*addr_head)->next;
        
        return del_item;
    }
}


/*
 Moves head pointer to point at next element in Queue
*/
void RotateQ(item ** addr_head)
{
    if((*addr_head) == NULL) //if Queue is empty
    {
        *addr_head = NULL;
    }
    else //Queue is not empty
    {
        *addr_head = (*addr_head)->next;
    }
}


