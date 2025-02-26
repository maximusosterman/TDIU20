#ifndef LIST_HPP
#define LIST_HPP
#include "node.hpp"

#include <iostream>
#include <initializer_list>

// Komplettering: Implementationsdetaljer syns i det publika gränssnittet.
// HINT: Node ska vara helt privat. DONE

class List {

public:
    List();
    List(std::initializer_list<int> values);
    ~List();

    List(const List&) = delete;              // copy ctor
    List(List&& other);                   // move ctor
    List& operator=(const List&) = delete;   // copy assignment
    List& operator=(List&& other) = delete;        // move assignment

    bool is_empty() const;
    void insert(int data);
    void remove(int index);
    int index_of(int index) const;
    int get_length() const;

private:

    Node* get_first() const;
    Node* get_last() const;
    Node* get_node(int index) const;
    //Sentiel
    Node* first;
    Node* last;

};

std::ostream& operator<<(std::ostream& os, List &list);

#endif // LIST_H
