#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>





node create_LL(int data){
    node x;
    x.data = data;
    x.next = NULL;
    
    return x;
}

void add_node(node *head,int data){
    node *temp = head;
    while(temp->next != NULL) temp = temp->next;
    node *newNode = malloc(sizeof(node));
    temp->next = newNode;
    newNode->data = data;
    newNode->next = NULL;
    
}

void printLinkedList(node *head){
    if (sizeLL(head)==0)
        return;
        
    printf("[Head]");
    while(head != NULL){ 
        printf(" -> %d " ,head->data);
        head = head->next;
    }
    printf("-> [End]\n");
}

int sizeLL(node *head){
    int size = 0;
    while (head){
        head = head->next;
        size++;
    }
    return size;
    
}

void insertAtPos(node *head,int n,int data){
    node *temp = head;
    node *newNode = malloc(sizeof(node));


    if (n==0){
        newNode->next = NULL;
        node *x = head;
        while (temp->next!=NULL) temp = temp->next;
        
        temp->next = newNode;
        int size = sizeLL(head);
        int buff = x->data;
        for (int i = 0; i < size-1; i++)
        {
            
            x = x->next;
            int data2 = x->data;
            x->data = buff;
            buff = data2;
        
        }

        head->data = data;  


        return;
    }


    for (int i = 0; i < n-1 && temp->next != NULL; i++)
        temp = temp->next;
    

    

    newNode->next = temp->next;
    newNode->data = data;
    temp->next = newNode;
    
}

void sortLinkedList(node *head){
    int size = sizeLL(head);
    int swapped = 0;
    node *temp = head;
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-1; j++)
        {
            if (head->data > head->next->data){
                swapped = 1;
                head->data = head->data + head->next->data;
                head->next->data = head->data - head->next->data;
                head->data = head->data - head->next->data;
        }
            
            head = head->next;
        }
        if (!swapped) return;
        else
            swapped = 0;
        
        head = temp;

    }
    
}

void reverseLinkedList(node *head){
    int size = sizeLL(head);
    int iter = size / 2;
    node *behind = head;
    node *begining = head;
    while(iter--){
        
        for (int i = 0; i < size-1; i++)
        {
            behind = behind->next;
        }
        size--;
        behind->data = begining->data + behind->data;
        begining->data = behind->data - begining->data; 
        behind->data = behind->data - begining->data;
        
        
        behind = head;
        begining = begining->next;
    }
    
}

int pop(node *head){
    /* deletes last node and returns its value */
    node *temp = head;
    if(sizeLL(head) == 0)
        return -1;

    if (sizeLL(head) == 1){
        free(head);
        return 0;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    int value = temp->data;



    while(head->next->next != NULL){
        head = head->next;
    }
    free(temp);
    head->next = NULL;
    return value;
}