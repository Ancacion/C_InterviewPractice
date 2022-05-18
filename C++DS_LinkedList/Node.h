//
//  Node.h
//  C++DS_LinkedList
//
//  Created by Ancacion on 2022/5/2.
//

#ifndef Node_h
#define Node_h

class Node {
public:
    Node () {}  //constructor
    Node (int inputData, Node* inputNext) : data(inputData), next(inputNext) {}
    int getData();
    Node* getNext();
    void setData(int inputData);
    void setNext(Node* ptr);
    
private:
    int data;
    Node *next;
};
typedef Node* Nodeptr;

int Node::getData() {
    return data;
}

Node* Node::getNext() {
    return next;
}

void Node::setData(int inputData) {
    data = inputData;
}

void Node::setNext(Node* ptr) {
    next = ptr;
}

#endif /* Node_h */
