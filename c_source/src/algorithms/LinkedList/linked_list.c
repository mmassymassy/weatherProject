#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct ListNode
{
    int data;
    struct ListNode *next;
    struct ListNode *prev;
};

struct ListNode *add_sorted_asc(struct ListNode *root, int data)
{
    if (root == NULL)
    {
        root = malloc(sizeof(struct ListNode));
        root->data = data;
        root->next = NULL;
        root->prev = NULL;
        return root;
    }

    struct ListNode *cuurent = root;

    while(cuurent != NULL){
        if(cuurent->data >= data){
            struct ListNode* newNode = malloc(sizeof(struct ListNode));
            newNode->data = data;
            newNode->next = cuurent->next ;
            newNode->prev = cuurent ;
            cuurent->next = newNode;
            return root;
        }

        cuurent = cuurent->next;
    }
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->prev = cuurent;
    cuurent->next = newNode;

    return root;
}

struct ListNode *add_sorted_dec(struct ListNode *root, int data)
{
    if (root == NULL)
    {
        root = malloc(sizeof(struct ListNode));
        root->data = data;
        root->next = NULL;
        root->prev = NULL;
        return root;
    }

    struct ListNode *cuurent = root;

    while(cuurent != NULL){
        if(cuurent->next->data <= data){
            struct ListNode* newNode = malloc(sizeof(struct ListNode));
            newNode->data = data;
            newNode->next = cuurent->next ;
            newNode->prev = cuurent ;
            cuurent->next = newNode;
            return root;
        }

        cuurent = cuurent->next;
    }
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->prev = cuurent;
    cuurent->next = newNode;

    return root;
}

void printList(struct ListNode *root)
{
    if (root == NULL)
    {
        return;
    }

    struct ListNode *cuurent = root;

    while (cuurent != NULL)
    {
        printf("\n%d", cuurent->data);
        cuurent = cuurent->next;
    }
}