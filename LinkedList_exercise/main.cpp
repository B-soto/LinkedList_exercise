//
//  main.cpp
//  LinkedList
//
//  Created by bryce soto on 3/27/17.
//  Copyright © 2017 Bryce Soto. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

using namespace std;


int main() {
    LL* list1 = new LL;
    int num, size;
    cout << "What would you like your first value in your Linked list to be:";
    cin >> num;
    LL* user = new LL(num);
    
    //////////////////////////////////////////////////////
    cout << "----Test append function----\n";
    cout << "How many numbers do you want to enter to the back of the list:";
    cin >> size;
    for (int i = 0; i < size; i++){
        cout << "\nNew back number:";
        int data;
        cin >> data;
        user->append(data);
    }
    cout << "\nLinked List size is:";
    user->Size();
    cout << "Linked list:\t";
    user->printList();
    
    //////////////////////////////////////////////////////
    //////////////////////////////////////////////////////
    
    cout << "----Test Insert Front function----\n";
    cout << "How many numbers do you want to enter in the front of the list:";
    cin >> size;
    for (int i = 0; i < size; i++){
        cout << "\nNew front number:";
        int data;
        cin >> data;
        user->insertFront(data);
    }
    cout << "\nLinked List size is:";
    user->Size();
    cout << "Linked list:\t";
    user->printList();
    
    
    //////////////////////////////////////////////////////
    //////////////////////////////////////////////////////
    
    
    cout << "---Test Copy constructor---\n";
    
    cout << "First Linked list\nSize:";
    user->Size();
    cout << "List=\t";
    user->printList();
    
    LL *list3 = user;
    
    cout << "Second Linked list\nSize:";
    list3->Size();
    cout << "List=\t";
    list3->printList();
    
    //////////////////////////////////////////////////////
    //////////////////////////////////////////////////////
    
    cout << "---Test Pop Front Function---\n";
    list3->popFront();
    cout << "List=\t";
    list3->printList();
    
    cout << "---Test popBack function---\n";
    list3->popBack();
    cout << "List=\t";
    list3->printList();
    
    //////////////////////////////////////////////////////
    //////////////////////////////////////////////////////
    
    cout << "What number would you like to delete from the List:";
    cin >> num;
    
    list3->checkValue(num);
    //check if its in list, if it is delete it, check again, if its not, break.
    if(list3->checkValue(num) == false){
        cout << "Number is not found\n";
    }
    while(list3->checkValue(num)==true){
        list3->popValue(num);
    }
    cout << "List=\t";
    
    list3->printList();
    
    cout << " ---Test MtoLast function---\n";
    cout << "What MtoLast number would you like to see from the List:";
    cin >> num;
    list3->MtoLastElement(num);
    
    cout << " ---Test reverse function---\n";
    
    list3->reverse();
    list3->printList();
    
    delete list3;
    
    return 0;
}
