#include "LinkedList.hpp"
#include <stdlib.h>
#include <iostream>

 using namespace std;
#include <stdio.h>

 LinkedList::LinkedList()
 {
     this->count = 0;
     this->head = NULL;
     this->tail = NULL;
     this->count = 0;
 }

 Node* LinkedList::getNodeAtIndex(int index)
 Node* LinkedList::get(int index)
 {
     if(index >= 0 && index < this->count)
     Node* node2Return = this->head;
     for(int i = 0; i < index; i++)
     {
         //return the node at that position in the list
         Node* currNode = this->head;
         for(int i = 0; i < index; i++)
         {
             currNode = currNode->getNextNode();
         }
         return currNode;
         node2Return = node2Return->getNextNode();
     }
     return NULL; //not a legal index!!!
     return node2Return;
 }

 void LinkedList::insertionSort()
 void LinkedList::swap(int index1, int index2)
 {
     //does this list need to potentially be sorted?
     if(this->count > 1)
     int smaller = index1;
     int larger = index2;
     if(larger < smaller)
     {
         Node* theFollowerNode;
         Node* swapNode;
         Node* beforeSwapNode;
         int theFollowerPos;

         for(int currStart = 1; currStart < this->count; currStart++)
         {
             theFollowerPos = currStart;
             theFollowerNode = this->getNodeAtIndex(theFollowerPos);
             while(theFollowerPos > 0 && theFollowerNode->getPayload() < this->getNodeAtIndex(theFollowerPos-1)->getPayload())
             {
                 //we need to do a swap between theFollowerNode and the node before him.
                 swapNode = this->getNodeAtIndex(theFollowerPos-1);
                 if(this->head == swapNode)
                 {
                     swapNode->setNextNode(theFollowerNode->getNextNode());
                     theFollowerNode->setNextNode(head);
                     this->head = theFollowerNode;
                 }
                 else
                 {
                     beforeSwapNode = this->head;
                     while(beforeSwapNode->getNextNode() != swapNode)
                     {
                        beforeSwapNode = beforeSwapNode->getNextNode();
                     }
                     swapNode->setNextNode(theFollowerNode->getNextNode());
                     theFollowerNode->setNextNode(swapNode);
                     beforeSwapNode->setNextNode(theFollowerNode);
                 }
                 if(this->tail == theFollowerNode) //resets tails if we are swapping away from tail
                 {
                     this->tail = swapNode;
                 }
                 theFollowerPos--;
             }
         } 
         smaller = index2;
         larger = index1;
     }
 }

 void LinkedList::addAtIndex(int value, int index)
 {
     if(index == 0)
     Node* smallerNode = this->get(smaller);
     Node* largerNode = this->get(larger);
     printf("smaller: %d, larger: %d\n", smaller, larger);
     smallerNode->setNextNode(largerNode->getNextNode());
     largerNode->setPrevNode(smallerNode->getPrevNode());
     largerNode->setNextNode(smallerNode);
     smallerNode->getNextNode()->setPrevNode(smallerNode);
     smallerNode->setPrevNode(largerNode);
     if(smaller == 0)
     {
         this->addFront(value);
         this->head = largerNode;
     }
     else if(index == this->count)

     if(larger == this->count-1)
     {
         this->addEnd(value);
     }
     else
     {
         Node* dude2Add = new Node(value);
         Node* prevDude = this->head;
         for(int i = 0; i < (index-1); i++)
         {
             prevDude = prevDude->getNextNode();
         }
         dude2Add->setNextNode(prevDude->getNextNode());
         prevDude->setNextNode(dude2Add);
         this->count++;
         this->tail = smallerNode;
     }

 }

 int LinkedList::removeAtIndex(int index)
 void LinkedList::insertionSortOnDefense()
 {
     if(this->head)
     int theFollower;
     for(int currStart = 1; currStart < this->count; currStart++)
     {
         if(index < 0 || index >= this->count)
         {
             cout << "ArrayIndexOutOfBoundException!!!!" << endl;
         }
         else
         theFollower = currStart;
         while(theFollower > 0 && this->get(theFollower)->getPayload()->getDefense() <
                 this->get(theFollower-1)->getPayload()->getDefense())
         {
             //I actuall have something to remove
             if(index == 0)
             {
                 return this->removeFront();
             }
             else if(index == this->count-1)
             {
                 return this->removeEnd();
             }
             else
             {
                 //we are removing from somewhere in the middle
                 Node* prevDude = this->head;
                 Node* dude2Remove = this->head;

                 //How do I get prevDude and dude2Remove set in a single loop?
                 //run dude2Remove to the correct index
                 for(int i = 0; i < index; i++)
                 {
                     dude2Remove = dude2Remove->getNextNode();
                 }

                 //now make preDude point to the node right before dude2Remove
                 while(prevDude->getNextNode() != dude2Remove)
                 {
                     prevDude = prevDude->getNextNode();
                 }

                 /* Identical result as the while loop above
                 //what is another way we could have written the while loop above?
                 for(int i = 0; i < index-1; i++)
                 {
                     prevDude = prevDude->getNextNode();
                 }
                 */

                //Now everything is position and we are ready to operate!!!
                prevDude->setNextNode(dude2Remove->getNextNode());
                dude2Remove->setNextNode(NULL);
                int value2Return = dude2Remove->getPayload();
                delete(dude2Remove);
                this->count--;
                return value2Return;
             }

             //I need to swap
             this->swap(theFollower, theFollower-1);
             theFollower--;
         }

     }
     else
     {
         cout << "Nothing to Remove from the Empty List" << endl;
     }

 }

 void LinkedList::addFront(int value)
 {
     if(this->head)
     {
         //add it to the front
         Node* n = new Node(value);
         n->setNextNode(this->head);
         this->head = n;
          this->count++;
     }
     else
     {
         //we have an empty list, so addFront and addEnd mean the same thing
         this->addEnd(value);
     }
 }

 int LinkedList::removeFront()
 void LinkedList::addEnd(Card* c)
 {
     if(this->head)
     {
         Node* currFront = this->head;
         this->head = this->head->getNextNode();
         currFront->setNextNode(NULL);
         int valueToReturn = currFront->getPayload();
         delete(currFront);
         this->count--;
         return valueToReturn;
     }

 }

 void LinkedList::addEnd(int value)
 {
     Node* n = new Node(value);
     if(head == NULL)
     Node* n = new Node(c);
     if(this->count == 0)
     {
         //we have the empty list
         this->head = n;
         this->tail = n;
     }
     else
     {
         //we have a list with at least one element in it, and we know that tail
         //points to the end of that list.
         n->setPrevNode(this->tail);
         this->tail->setNextNode(n);
         this->tail = n;
     }
     this->count++;
 }

 int LinkedList::removeEnd()
 int LinkedList::getCount()
 {
     if(this->count > 0)
     {
         Node* n = this->tail;
         int value = n->getPayload();
         if(this->count == 1)
         {
             this->head = NULL;
             this->tail = NULL;

         }
         else
         {
             Node* currNode = this->head;
             while(currNode->getNextNode() != this->tail)
             {
                 currNode = currNode->getNextNode();
             }
             this->tail = currNode;
             this->tail->setNextNode(NULL);
         }
         this->count--;
         delete(n); //if we didn't do this, we technically have a memory leak
         return value;
     }

     return this->count;
 }

 void LinkedList::display()
 {
     if(this->count == 0)
     Node* currNode = this->head;
     for(int i = 0; i < this->count; i++)
     {
         cout << "the empty list" << endl;
         currNode->getPayload()->display();
         currNode = currNode->getNextNode();
     }
     else
     {
         Node* currNode = this->head;
         while(currNode->getNextNode() != NULL)
         {
             cout << currNode->getPayload() << " -> ";
             currNode = currNode->getNextNode();
         }
         cout << currNode->getPayload() << endl;
     }

 } 
 }
