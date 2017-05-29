//
//  LinkedList.cpp
//  LinkedList
//
//  Created by bryce soto on 3/27/17.
//  Copyright © 2017 Bryce Soto. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"
#include <iostream>
using namespace std;


LL::LL(): head(NULL), size(0){};

LL::LL(int data){
    node* newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    
    head = newNode;
    size = 1;
}
LL::LL(const LL& rhs){
    if(rhs.head == NULL){
        head = NULL;
        size = 0;
    }else{
        head = new node;
        node* rhshead = rhs.head;
        node* link = head;
        link->data = rhshead->data;
        rhshead = rhshead->next;
        
        while(rhshead != NULL){
            node* after = new node;
            after->data = rhshead->data;
            link->next = after;
            link = link->next;
            rhshead = rhshead->next;
        }
        link->next = NULL;
    }
}

LL& LL::operator=(const LL& rhs){
    if(head == rhs.head) {
        return *this;
    }
    if (rhs.head == NULL){
        deleteList();
        return *this;
    }
    deleteList();
    head = new node;
    node* rhshead = rhs.head;
    node* link = head;
    link->data = rhshead->data;
    rhshead = rhshead->next;
    
    while(rhshead != NULL){
        node* after = new node;
        after->data = rhshead->data;
        link->next = after;
        link = link->next;
        rhshead = rhshead->next;
    }
    link->next = NULL;
    return *this;
}

void LL::deleteList(){
    
    node* current = head;
    //loops through deleting every node in the linked list
    while( current != 0 ) {
        node* next = current->next;
        delete current;
        current = next;
    }
    head = 0;
}

LL::~LL(){
    deleteList();
    cout << "Destructor called to delete list" << endl;
    
}


void LL::insertFront(int data){
    node* temp = head;
    node* newNode = new node;
    head = newNode;
    newNode->next = temp;
    newNode->data = data;
    size++;
    
}

void LL::append(int data){
    
    node* newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL){
        head = newNode;
        size++;
        return;
    }
    
    node* current = head;
    
    while(current->next != NULL){
        current = current->next;
    }
    
    current->next = newNode;
    size++;
}

void LL:: popFront(){
    if (head == NULL)
        return;
    node* current = head;
    head = head->next;
    delete current;
    size--;
}

void LL:: popBack(){
    node *ptr, *prev = nullptr;
    
    if (head==NULL){
        return;
    }else if (head->next ==NULL){
        ptr = head;
        head = NULL;
        delete ptr;
    }else{
        ptr = head;
        while(ptr->next != NULL){
            prev= ptr;
            ptr = ptr->next;
        }
        prev->next = NULL;
        delete ptr;
    }
}

bool LL::checkValue(int x){
    bool found = false;
    node *temp;
    temp=head;
    //searchs until finds the given value in the parameters,
    //then returns a boolean value if found (true/false)
    while(temp->next!=NULL)
    {
        if(temp->data == x) found=true;
        temp=temp->next;
    }
    
    return found;
}


void LL::popValue(int x){
    node *temp,*temp1,*temp2;
    temp=head;
    temp1=temp;
    //temp2=temp1;
    //loops until it finds the value matching the
    //given parameter 'x'
    for(int i=1;i<=size;i++)
    {
        if(temp->data==x)
        {
            if(temp->data!=1)
            {
                temp2=temp->next;
                //delete temp;
                temp1->next=temp2;
                //size--;
            }
            if(temp->data==1)
            {
                temp2=temp->next;
                delete temp;
                head=temp2;
                size--;
            }
            break;
        }
        temp1=temp;
        if(temp->data!=x)
        {
            temp=temp->next;
        }
    }
    
}



void LL::printList(){
    
    if (head == NULL){
        cout << "List is Empty!\n";
        return;
    }
    node* current = head;
    while(current->next != NULL){
        cout <<current->data << "->";
        current = current->next;
    }
    
    cout<< current->data << endl;
    
}

int LL::Size(){
    cout << size << endl;
    int sz = size;
    return sz;
}

int LL::MtoLastElement(int M){
    int MtoLast = size - M;
    cout << "MtoLast size = " << MtoLast << endl;
    int count = 1;
    node* current = head;
    
    while(current->next != NULL){
        current = current->next;
        count++;
        if (count == MtoLast)
            // int element = current->data;
            cout << "Element number is " << current->data <<endl;
        
    }
    return 0;
}

void LL::reverse(){
    node* prev = NULL;
    node* current = head;
    node* next;
    
    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
ostream &operator<<( ostream&output, const LL& Olist){
    LL::node *p;
    for(p = Olist.head; p != NULL; p->next){
        output << p->data << endl;
    }
    
    return output;
}




