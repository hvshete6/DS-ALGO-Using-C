#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// ========== Insert At First ================
struct node *InsertFirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
// ========== Insert At End ================
struct node *InsertAtEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// ========== Insert In Between the Linked-List ================
struct node *InsertAtIndex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// ========== Insert After a Node In the Linked-List ================
struct node *InsertAfterNode(struct node *head, struct node *prevNode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

// ========== Display Function ================
void Traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element :- %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 11;
    head->next = second;

    second->data = 21;
    second->next = third;

    third->data = 31;
    third->next = fourth;

    fourth->data = 41;
    fourth->next = NULL;

    // head = InsertFirst(head, 56);

    // head = InsertAtIndex(head, 111, 2);

    // head = InsertAtEnd(head, 51);

    head = InsertAfterNode(head, second, 2);

    Traversal(head);

    return 0;
}
