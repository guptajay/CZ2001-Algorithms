// A program coded in C for Closed Address Hashing - Chained Hashing
// Jay Gupta, Ritwik Kanodia, Swathi Kumar Vembu, Aryaman Shaan, Soham Dandapath
// CZ2001 Algorithms, Lab 2, Group SS3
// School of Computer Science and Engineering
// Nanyang Technological University

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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

    // Checking if slot[key] is empty
    if(slot[key] == NULL)
        // if empty, create a new node to the corresponding slot
        slot[key] = newNode;

    // If it is going to the else part, then, it is a collision
    else
    {
        // Add the node at the end of slot of the corresponding slot
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

void search(int item) {

    // Calculating Key
    int key = item % h;
    int no_of_key_comparisons = 0;
    int flag = 0;

    struct node *temp1 = slot[key];

    while(temp1 != NULL) {

        no_of_key_comparisons++;

        if (temp1->data == item) {
            flag = 1;
            printf("\n%d is found in Slot %d!", item, key);
            printf("\nNumber of Key Comparisons Made = %d\n", no_of_key_comparisons);
            return;
        }
        temp1 = temp1->next;
    }

    if(flag == 0) {
        printf("\n%d Not Found!\n");
        printf("\nNumber of Key Comparisons Made = %d\n", no_of_key_comparisons);
        return;
    }
}

int main()
{
    clock_t t1, t2;

    // Program Starting
    t1 = clock();
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

    t1 = clock() - t1;
    // Program Ending

    // Exclude printing time in CPU Time
    print();

    // Program Starting
    t2 = clock();

    search(10);

    t2 = clock() - t2;
    // Program Ending

    double time_taken = ((double)t1)/CLOCKS_PER_SEC + ((double)t2)/CLOCKS_PER_SEC; // in seconds

    printf("CPU Time = %f\n", time_taken);

    return 0;
}
