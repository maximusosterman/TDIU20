#ifndef LIST_HPP
#define LIST_HPP
#include <initializer_list>
#include "node.hpp"
#include <iostream>

class List {

public:
    List();
    List(int value);


    bool is_empty();

    void insert(int data);

    Node* get_first() const;
    Node* get_last() const;
    // get_last()

    private:

    //Sentiel
    Node* first;
    Node* last;

};

#endif // LIST_H

std::ostream& operator<<(std::ostream& os, List &list);
