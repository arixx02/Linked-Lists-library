#ifndef LINKEDLIST_H

#define LINKEDLIST_H

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct {
    Node *head;
    Node *tail;
    int length;
} List;

List* initList();

Node* createNode(int data);

void append(int data,List *list);

void add(int data,List *list);

void printList(List *list);

int insertAt(int index,int data,List list);

int listLength(const Node *head);

#endif // LINKEDLIST_H
