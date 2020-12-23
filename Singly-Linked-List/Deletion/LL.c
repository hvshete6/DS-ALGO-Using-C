#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void Display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element :- %d\n", ptr->data);
        ptr = ptr->next;
    }
}

//Deleting 1st element from LL.

struct node *deleteFirst(struct node *head)
{
    struct node *ptr = head;

    head = head->next;
    free(ptr);
    return head;
}

// Delete At a given Index
struct node *deleteAtIndex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return head;
}

// Delete The Last Element
struct node *deleteLast(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);

    return head;
}

// Delete Element with a given value
struct node *deleteGivenValue(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }

    return head;
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

    printf("Linked List is :- \n");
    Display(head);

        // head = deleteFirst(head);
    // printf("=================Linked List After Deletion @ First position================= \n");
    // Traversal(head);

    // head = deleteLast(head);
    // printf("=================Linked List After Deletion @ Last Position================= \n");
    // Display(head);

    // head = deleteAtIndex(head, 2);
    // printf("=================Linked List After Deletion @ Given Index ================= \n");
    // Display(head);

    // head = deleteGivenValue(head, 21);
    // printf("=================Linked List After Deletion of Given Value ================= \n");
    // Display(head);

    return 0;
}
