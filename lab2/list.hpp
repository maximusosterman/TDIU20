#ifndef LIST_H
#define LIST_H
#include <initializer_list>

class List {

public:
    List();
    List(std::initializer_list<int> values);

    void insert(int data);

    
    // get_first()
    // get_last()
    
    private:
    
    struct Node {
        Node* prev;
        int data;
        Node* next;
    };
    //Sentiel
    Node* first;
    Node* last;
    
};

#endif // LIST_H

std::ostream& operator<<(std::ostream& os, List& const list);