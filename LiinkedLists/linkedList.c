#include "linkedLists.h"
#include <stdlib.h>
#include <stdio.h>

List* initList() {
    List* list = (List*)malloc(sizeof(List));  // Allocate memory for the List
    if (list == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

Node* createNode(int data) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        return NULL;
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void append(int data,List *list) {

    // If the Linked List is empty, make
    // the new Node as the head and return
    if (list->head == NULL) {
        // Create a new Node
        list->head = createNode(data);
        list->tail = list->head;
        list->length++;
        printf("\nNode succesfully created\n");
        return;
    }
    Node* newNode = createNode(data);
    list->tail->next=newNode;
    list->tail = newNode;
    list->length++;
    printf("\nNode succesfully appended\n");
}

void add(int data,List *list){
    // If the Linked List is empty, make
    // the new Node as the head and return
    if (list->head == NULL) {
        // Create a new Node
        list->head = createNode(data);
        list->tail = list->head;
        printf("\nNode succesfully created\n");
        list->length++;
        return;
    }
    Node* newNode = createNode(data);

    newNode->next=list->head;
    list->head=newNode;
    // If there is only one Node in the list, update tail
    if (list->tail == NULL) {
        list->tail = newNode;
    }
    list->length++;
    printf("\nNode succesfully added\n");
}

void printList(List *list){
    Node *current=list->head;
    while(current!=NULL){
        printf("%d -> ",current->data);
        current=current->next;
    }
    printf("NULL\n");
    if(list->head!=NULL && list->tail!=NULL)printf("Yo soy la cabeza %d\nYo soy la cola %d\n",list->head->data,list->tail->data);
}

int listLength(const Node *head){
    int length=0;
    Node* current=head;
    while(current!=NULL){
        length++;
        current=current->next;
    }
    return length;
}

int insertAt(int index,int data,List list){

    if(index<1 || index>listLength(list.head)+1){
        return 0;
    }
    Node* newNode = createNode(data);
    if (newNode == NULL) return 0; // malloc failed

    if(index==1){
        newNode->next=list.head;
        list.head=newNode;
        if (list.tail == NULL) list.tail = newNode;
        return 1;
    }
    Node* current=list.head;
    int indexCounter=2;
    while(indexCounter<index){
        current=current->next;
        indexCounter++;
    }
    newNode->next=current->next;
    current->next=newNode;
    if(newNode->next == NULL){
    list.tail = newNode;
    }
    return 1;
}
/*

2. Manipulation Functions:

deleteAt(index, head, tail): Deletes a Node at a specific index.

deleteByValue(data, head, tail): Deletes the first Node with the specified data.

reverseList(head, tail): Reverses the entire linked list.

3. Search Functions:
find(data, head): Finds the first Node with the specified data.

getNthNode(index, head): Retrieves the Node at the specified index.

isEmpty(head): Checks whether the list is empty.

4. Utility Functions:
length(head): Returns the number of Nodes in the list.

clearList(head, tail): Clears the entire list and frees all allocated memory.

sortList(head): Sorts the list in ascending or descending order.

mergeLists(head1, head2): Merges two sorted linked lists into a single sorted list.

copyList(head): Creates a copy of the list.

5. Traversal and Data Operations:
printListReverse(head): Prints the elements in reverse order using recursion or an auxiliary stack.

sumList(head): Returns the sum of all data values in the list (for numeric data types).

findMiddle(head): Finds and returns the middle Node in the list.

6. Advanced Operations:
detectCycle(head): Detects if there is a cycle in the linked list (Floyd's Cycle-Finding Algorithm).

removeCycle(head): Removes a cycle from the linked list if detected.

rotateList(head, k): Rotates the linked list by k positions.

mergeSortedLists(head1, head2): Merges two sorted lists into a sorted linked list.

isPalindrome(head): Checks if the linked list is a palindrome.

7. Miscellaneous:
getTail(head): Returns the tail Node (last Node) of the list.

getHead(): Returns the head Node of the list.

Optional / Advanced Operations:
flattenList(head): Flattens a list of lists into a single linked list (for lists with child lists).

removeDuplicates(head): Removes duplicate Nodes based on data.
*/
