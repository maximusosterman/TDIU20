#include "list.hpp"
#include "node.hpp"
#include <initializer_list>
#include <sstream>
#include <string>
#include <iostream>

List::List() : first {nullptr}, last {nullptr} {};

List::List(std::initializer_list<int> values) {
    // for (int value : values ) {

    // }
}

void List::insert(int data) {
    if (first == nullptr) {
        first = new Node{nullptr, data, nullptr};
    }
}

Node* List::get_first() const {
    return first;
}

Node* List::get_last() const {
    return last;
}

std::ostream& operator<<(std::ostream& os, List &list) {
    std::string output_str = "{";
    Node* current_node = list.get_first();

    while (current_node->get_next() != nullptr) {
        output_str += std::to_string(current_node->get_next()->get_data());
    }

    output_str += "}";
    return os << output_str;
}
