#ifndef LIST_HPP
#define LIST_HPP
#include <initializer_list>
#include "node.hpp"
#include <iostream>

class List {

public:
    List();
    List(std::initializer_list<int> values);
    ~List();


    bool is_empty() const;

    void insert(int data);
    void remove(int index);


    Node* get_first() const;
    Node* get_last() const;
    Node* get_node(int index) const;
    int get_length() const;

    int index_of(int index) const;

private:

    //Sentiel
    Node* first;
    Node* last;

};

#endif // LIST_H

std::ostream& operator<<(std::ostream& os, List &list);
