#include "list.hpp"
#include "node.hpp"
#include <initializer_list>
#include <sstream>
#include <string>
#include <iostream>
#include <stdexcept>

List::List() : first {nullptr}, last {nullptr} {};

List::List(std::initializer_list<int> values) {

    for (int value : values ) {
        List::insert(value);
    }
}

bool List::is_empty() {
    return first == nullptr;
}

void List::insert(int data) {
    if (is_empty()) { // if to insert into an empty list
        first = new Node{nullptr, data, nullptr};
        last = first;
        return;
    }
    last->set_next(new Node{last, data, nullptr});
    last = last->get_next();
}

Node* List::get_first() const {
    return first;
}

Node* List::get_last() const {
    return last;
}

std::ostream& operator<<(std::ostream& os, List &list) {
    if (list.is_empty()) {
        return os << "{}";
    }

    std::string output_str = "{";
    Node* current_node = list.get_first();

    while (current_node != nullptr) {
        output_str += std::to_string(current_node->get_data());

        if (current_node->get_next() != nullptr) {  // Only add ", " if not the last node
            output_str += ", ";
        }

        current_node = current_node->get_next();
    }

    output_str += "}";
    return os << output_str;
}

int List::get(int index) const {

    if (index < 0) throw std::logic_error("Index out of range!");

    Node* current_node = get_first();

    for (int node {}; node < index; node++) {
        if (current_node->get_next() == nullptr) {
            throw std::logic_error("Index out of range!");
        }
        current_node = current_node->get_next();
    }

    return current_node->get_data();
}


// Insert in correct order
// Remove at index
// Bonus
