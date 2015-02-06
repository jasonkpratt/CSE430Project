#include<stdio.h>
#include<stdlib.h>

typedef struct item {
    int payload;
    struct item* prev;
    struct item* next;
    
} item;


typedef struct queue
{
    struct item* head;
    struct item* items;
    
}queue;



queue InitQueue( queue* head)
{
    /* Create a Queue */
    queue *Q=head;
    Q->head=NULL;
  		printf("Q address during InitQueue function call is %p\n",Q);
    /* Return the pointer */
        return *Q;
}

item* NewItem(int count) {
    
    item* I = (item *)malloc(sizeof(item));
    printf("item address created in function call is %p\n", I);
    I->payload=count;
    I->next=NULL;
    I->prev=NULL;
    return  I;
}

item DelQueue(queue *Q) {
    
    /*deletes head of list, places the next item as the head*/
    
    item* myItem= Q->head;
    printf("(in delqueue func) deleting element %d\n",myItem->payload);
    item* newHead=Q->head->next;
    newHead->prev=Q->head->prev;
    Q->head=newHead;
    Q->items->next=newHead;
    printf("(in delqueue func) deleted myItem address is %p\n",myItem);
    printf("(in delqueue func) new head address is %p\n",Q->head);
     printf("(in delqueue func) last address Next is pointing to %p\n",Q->items->next);
    printf("(in delqueue func) new head address Prev is pointing to %p\n",Q->head->prev);

        return *myItem;
}

void AddQueue(queue *Q,item* myItem)
{

    /* executes if queue is empty, sets head equal to address of first item, prev and next are set to the same */
    if(Q->head==NULL)
        
    {
        printf("(in addqueue func) item address is %p\n", myItem);
        printf("(in addqueue func) Head is null\n");
        printf("(in addqueue func) my head element address before add is %p\n",Q->head);
        myItem->prev=myItem;
        myItem->next=myItem;
        Q->head=myItem;
        printf("(in addqueue func) my head element address after add is %p\n",Q->head);
        printf("(in addqueue func) my head element value is %d\n",Q->head->payload);
        Q->items=myItem;
    }
   
    /*places item at the end of the list. sets next to point at head of list and prev to point at the prior last item, sets head to point to last item*/
    else
    {
       
        myItem->next=Q->head;
        myItem->prev=Q->items;
        Q->items->next=myItem;
        Q->items++;
        Q->items=myItem;
        Q->head->prev=myItem;
    }
    printf("(in addqueue func) my head element address is %p\n",Q->head);
    printf("(in addqueue func) current items element address is %p\n",Q->items);

    printf("(in addqueue func) current items payload is %d\n",Q->items->payload);
    
}


int mainChanged()
{
    int myCount=1;
    queue myQ;
    printf("myQ address b4 creating queue is %p \n",&myQ);
    myQ=InitQueue(&myQ);
    printf("myQ address after return from function call is %p \n",&myQ);

    item *getItem;
    printf("ITEM1: getItem address before NewItem function call is %p \n",getItem);
    getItem=NewItem(myCount);
    printf("ITEM1:  getItem address after function call is %p \n",getItem);

   AddQueue(&myQ, getItem);
    printf("first element's payload in queue %d\n",myQ.head->payload);
    
    /* set count so s to distinguish between the item variables. count is stored as the payload for each item*/
    myCount++;
    getItem=NewItem(myCount);
    printf("ITEM2: getItem address after is %p \n",getItem);
    AddQueue(&myQ, getItem);
    
    printf("second element's payload in queue is %d\n",myQ.items->payload);
    item deletedItem=DelQueue(&myQ);
    printf("element at head of queue after deleted item: %d\n",myQ.head->payload);
    printf("deleted element is %d",deletedItem.payload);
    return 0;
    


}
