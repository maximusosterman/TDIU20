#ifndef LIST_H
#define LIST_H

class List {

public:
    List();

private:

    struct Node {
        Node* prev;
        int data;
        Node* next;
    };

    Node* first;
    Node* last;

};

#endif // LIST_H
