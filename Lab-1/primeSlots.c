// A program coded in C for Closed Address Hashing - Chained Hashing
// Jay Gupta, Ritwik Kanodia, Swathi Kumar Vembu, Aryaman Shaan, Soham Dandapath
// CZ2001 Algorithms, Lab 2, Group SS3
// School of Computer Science and Engineering
// Nanyang Technological University

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define number of slots = h
// number of elements = n
// load factor = n/h

#define h 37

struct node
{
    int data;
    struct node *next;
};

struct node *slot[h];

void insert(int value);
void print();
void search(int item);

int main()
{
    clock_t start_1, start_2, end_1, end_2;

    printf("\nNumber of Slots = %d [PRIME]\n", h);

    float loadFactor;
    printf("Please enter the LOAD FACTOR (e.g. 0.20, 0.50, ...): ");
    scanf("%f", &loadFactor);
    int numberOfElements;
    numberOfElements = (int)(loadFactor * h);

    printf("\nNumber of Elements to be inserted for %.2f Load Factor: %d\n", loadFactor, numberOfElements);

    // Program Starting
    start_1 = clock();
    int i, j, searchItem;

    // initializing the whole array to NULL
    for (i = 0; i < h; i++)
        slot[i] = NULL;

    int data = 1000000;

    for (j = 0; j < numberOfElements; j++)
    {
        insert(data);
        data = data + 1000;
    }

    print();

    end_1 = clock();
    // Program Ending

    printf("Please enter a number to search: ");
    scanf("%d", &searchItem);

    // Program Starting
    start_2 = clock();

    search(searchItem);

    end_2 = clock();
    // Program Ending

    double time_taken = (((double)(end_1 - start_1)) / CLOCKS_PER_SEC) + (((double)(end_2 - start_2)) / CLOCKS_PER_SEC); // in seconds

    printf("CPU Time = %f", time_taken);
    printf("\n");

    return 0;
}

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
    if (slot[key] == NULL)
        // if empty, create a new node to the corresponding slot
        slot[key] = newNode;

    // If it is going to the else part, then, it is a collision
    else
    {
        // Add the node at the end of slot of the corresponding slot
        struct node *temp = slot[key];
        // iterate to the last node in the linked list
        while (temp->next)
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

    for (i = 0; i < h; i++)
    {
        struct node *temp = slot[i];
        printf("Slot %d -> ", i);
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("END\n");
    }
}

void search(int item)
{
    // Calculating Key
    int key = item % h;
    int no_of_key_comparisons = 0;
    int flag = 0;

    printf("\nSearching in Slot %d...\n", key);

    struct node *temp1 = slot[key];

    while (temp1 != NULL)
    {
        // track number of key comparisons
        no_of_key_comparisons++;
        if (temp1->data == item)
        {
            flag = 1;
            printf("\n%d is found in Slot %d!", item, key);
            printf("\nNumber of Key Comparisons Made = %d\n", no_of_key_comparisons);
            return;
        }
        temp1 = temp1->next;
    }

    if (flag == 0)
    {
        printf("\n%d Not Found!\n", item);
        printf("\nNumber of Key Comparisons Made = %d\n", no_of_key_comparisons);
        return;
    }
}