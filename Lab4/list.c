/*  Corey Rondeau and Caroline Hester
 *  ECE 4680 Lab 4
 *  File Created: Jan. 31 2018
 *  File Name: list.c
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#include "functions.h"


listRoot *listConstruct()
{
    listRoot *listPtr;
    listPtr = (listRoot *)malloc(sizeof(listRoot));
    listPtr->head = NULL;
    listPtr->listSize = 0;
    return listPtr;
}

void listInsertSorted(listRoot *treeHeader, unsigned short int frequency, unsigned char symbol)
{
    listNode *newNode = (listNode *)malloc(sizeof(listNode));
    newNode->frequency = frequency;
    newNode->symbol = symbol;
    newNode->next = NULL;
    newNode->prev = NULL;

    listNode *currPtr = NULL;

    if(treeHeader->head == NULL)
    {
        treeHeader->head = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;
        treeHeader->listSize++;
        return;
    }
    else
    {
        currPtr = treeHeader->head;
        // Only one item in the list
        if(currPtr->next == NULL)
        {
            if(currPtr->frequency < newNode->frequency)
            {
                currPtr->next = newNode;
                newNode->next = NULL;
                newNode->prev = currPtr;
                treeHeader->listSize++;
                return;
            }
            else
            {
                newNode->next = currPtr;
                currPtr->prev = newNode;
                currPtr->next = NULL;
                treeHeader->head = newNode;
                treeHeader->listSize++;
                return;
            }
        }

        // Must be multiple list items
        while(currPtr != NULL)
        {
            if(currPtr->next != NULL)
            {
                // If the next node exists, check if it's frequency is higher than the new node
                // and insert it after the current node.
                if(currPtr->next->frequency > newNode->frequency)
                {
                    newNode->next = currPtr->next;
                    newNode->prev = currPtr;
                    currPtr->next->prev = newNode;
                    currPtr->next = newNode;
                    treeHeader->listSize++;
                    return;
                }
            }
            else
            {
                // Must be at the final node and new node must have the highest frequency
                currPtr->next = newNode;
                newNode->next = NULL;
                newNode->prev = currPtr;
                treeHeader->listSize++;
                return;

            }
            currPtr = currPtr->next;
        }
    }
}

void listRemove(listRoot *treeHeader, listNode *node)
{


}

void listDestruct(listRoot *treeHeader)
{


}

/*  The purpose of this recursive function is to print the list nodes' symbols
 *  and their frequencies.
 */
void printList(listNode *node)
{
    if(node->next != NULL) printList(node->next);
    printf("(%d) %c ->",node->frequency,node->symbol);
    return;
}