#include "node.hpp"

// Kommentar: Bra tänkt med detta, är det dock nödvändigt?
// Ni har bara ersatt en rad kod med ett funktions anrop istället,
// kan ni inte göra Node som en strukt och använda er av pekarsemantiken direkt istället?

Node::Node(Node* prev, int data, Node* next) : prev{prev}, data{data}, next{next} {}

Node* Node::get_next() const {
    return this->next;
}

Node* Node::get_prev() const {
    return this->prev;
}

int Node::get_data() const {
    return this->data;
}

void Node::set_next(Node* node) {
    this->next = node;
}

void Node::set_next_null() {
    this->next = nullptr;
}

void Node::set_prev(Node* node) {
    this->prev = node;
}

void Node::set_prev_null() {
    this->prev = nullptr;
}
