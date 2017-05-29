//
//  LinkedList.h
//  LinkedList
//
//  Created by bryce soto on 3/27/17.
//  Copyright © 2017 Bryce Soto. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class LL{
private:
    struct node{
        node *next;
        int data;
    };
    node *head;
    int size;
    
public:
    //Default constructor
    LL();
    
    // constuctor
    LL(int data);
    
    // copy constructor
    LL(const LL& rhs);
    
    // Overload operator
    LL& operator=(const LL& rhgs);
    
    //destructor
    virtual ~LL();
    
    void popFront();
    void popBack();
    
    bool checkValue(int x);
    void popValue(int x);
    
    // print list
    void printList();
    
    //return size of list
    int Size();
    
    //delete list
    void deleteList();
    
    
    //Insert front mutator
    void insertFront(int data);
    
    //Insert append mutator
    void append(int data);
    
    int MtoLastElement(int M);
    
    void reverse();
    
    friend ostream &operator<<(ostream&, const LL& );
    
    
    
};



#endif /* LinkedList_h */
