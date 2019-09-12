#include<stdio.h>
#include<stdlib.h>

#define NO_OF_SLOTS 7

struct node
{
    int data;
    struct node *next;
};

struct node *chain[NO_OF_SLOTS];

void insert(int value)
{
    // Create a new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    // Hashing Function
    int key = value % NO_OF_SLOTS;

    // Checking if chain[key] is empty
    if(chain[key] == NULL)
        chain[key] = newNode;
    
    // If it is going to the else part, then, it is a collision
    else
    {
        // Add the node at the end of chain
        struct node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void print()
{
    int i;

    for(i = 0; i < NO_OF_SLOTS; i++)
    {
        struct node *temp = chain[i];
        printf("chain[%d]-->",i);
        while(temp)
        {
            printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    //init array of list to NULL
    int i;
    for(i = 0; i < NO_OF_SLOTS; i++)
        chain[i] = NULL;

    insert(7);
    insert(0);
    insert(3);
    insert(10);
    insert(4);
    insert(5);

    print();

    return 0;
}
