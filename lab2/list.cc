#include "list.hpp"
#include <initializer_list>
#include <sstream>
#include <string>


List::List() : first {nullptr}, last {nullptr} {};

List::List(std::initializer_list<int> values) {
    for (int value : values ) {

    }
}

void List::insert(int data) {
    if (first == nullptr) {
        first = new Node{nullptr, data, nullptr};
    }
}

std::ostream& operator<<(std::ostream& os, List& const list) {
    std::string output_str = "{";
    List::Node* current_node = first;
    
    do {
        output_str += std::to_string(current_node->data);
    }
    while (current_node->next != nullptr);
    output_str += "}";
    return os << output_str;
} 
