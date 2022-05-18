//
//  main.cpp
//  C++DS_LinkedList
//
//  Created by Ancacion on 2022/5/2.
//

#include <iostream>
#include "Node.h"

using namespace std;

void headInsert(Nodeptr& head, int inputData);
void insertNode(Nodeptr after, int inputData);
void deleteNode(Nodeptr before, Nodeptr discard);
void printList(Nodeptr print);
Nodeptr search(Nodeptr head, int target);

void headInsert(Nodeptr& head, int inputData) {
    head = new Node(inputData, head);
}

void insertNode(Nodeptr after, int inputData) {
    after -> setNext(new Node(inputData, after -> getNext()));
}

void deleteNode(Nodeptr before, Nodeptr discard) {
    before -> setNext(discard -> getNext());
    delete discard;
}

void printList(Nodeptr head) {
    Nodeptr print = head;
    cout << "Linked_List: ";
    while(print) {
        cout << print -> getData() << " ";
        print = print -> getNext();
    }
    cout << endl;
}

Nodeptr search(Nodeptr head, int target) {
    Nodeptr current = head;
    if(current == nullptr) {
        return nullptr;
    }
    else {
        while(current -> getData() != target && current -> getNext() != nullptr) {
            current = current -> getNext();
        }
        if(current -> getData() == target) {
            return current;
        }
        else {
            return nullptr;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    Nodeptr Head;
    headInsert(Head, 1);
    insertNode(Head, 2);
    Nodeptr after = search(Head, 2);
    insertNode(after, 3);
    
    printList(Head);
    //cout << Head -> getData() << endl;
    //cout << Head -> getNext() -> getData() << endl;
    //cout << Head -> getNext() -> getNext() -> getData() << endl;
    Nodeptr discard = after -> getNext();
    deleteNode(after, discard);

    printList(Head);
    
    insertNode(after, 4);
    insertNode(after -> getNext(), 5);

    printList(Head);
    Nodeptr No3 = search(Head, 4);
    cout << No3 -> getNext() -> getData() << endl;
    
    return 0;
}
