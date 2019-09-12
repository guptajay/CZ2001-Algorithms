// A program coded in C for Closed Address Hashing - Chained Hashing
// Jay Gupta, Ritwik Kanodia, Swathi Kumar Vembu, Aryaman Shaan, Soham Dandapath
// CZ2001 Algorithms, Lab 2, Group SS3
// School of Computer Science and Engineering
// Nanyang Technological University

#include<stdio.h>
#include<stdlib.h>

// Define number of slots = h
// number of elements = n
// load factor = n/h

#define h 7

struct node
{
    int data;
    struct node *next;
};

struct node *slot[h];

void insert(int value)
{
    // Create a new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    // Hashing Function
    // key = value mod h
    int key = value % h;

    // Checking if chain[key] is empty
    if(slot[key] == NULL)
        // if empty, create a new node to the corresponding slot
        slot[key] = newNode;

    // If it is going to the else part, then, it is a collision
    else
    {
        // Add the node at the end of chain of the corresponding slot
        struct node *temp = slot[key];
        // iterate to the last node in the linked list
        while(temp->next)
        {
            temp = temp->next;
        }
        // insert the value
        temp->next = newNode;
    }
}

void print()
{
    int i;

    for(i = 0; i < h; i++)
    {
        struct node *temp = slot[i];
        printf("Slot %d -> ", i);
        while(temp != NULL)
        {
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("END\n");
    }
}

int main()
{
    int i;

    // initializing the whole array to NULL
    for(i = 0; i < h; i++)
        slot[i] = NULL;

    insert(7);
    insert(0);
    insert(3);
    insert(10);
    insert(4);
    insert(5);

    print();

    return 0;
}
