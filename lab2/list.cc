#include "list.hpp"
#include "node.hpp"

// Komplettering: Initiera variabler med måsvingar. DONE

// Komplettering: Inkludera endast de bibliotek som används. DONE

// Komplettering: använd inte this i onödan. DONE

List::List() : first {nullptr}, last {nullptr} {};

List::List(std::initializer_list<int> values) : first {nullptr}, last {nullptr} {

    for (int value : values ) {
        List::insert(value);
    }
}

List::~List() {
    Node* current {first};
    while (current != nullptr) {
        Node* next {current->get_next()};
        delete current;
        current = next;
    }
}

List::List(const List& other)
    : first{nullptr}, last{nullptr} {
    first = last = nullptr;  // Start with an empty list

    Node* current = other.first;
    while (current) {
        insert(current->get_data());  // Copy each node
        current = current->get_next();
    }
}

List::List(List&& other)
    : first{other.first}, last{other.last} {
    other.first = nullptr;
    other.last = nullptr;
}

List& List::operator=(const List& other) {
    if (this == &other) {
        return *this;
    }


    Node* current = first;
    while (current) {
        Node* next = current->get_next();
        delete current;
        current = next;
    }

    first = last = nullptr;

    Node* other_current = other.first;
    while (other_current) {
        insert(other_current->get_data());  // Allocate new nodes
        other_current = other_current->get_next();
    }

    return *this;
}

List& List::operator=(List&& other) {
    if (this == &other) {  // Step 1: Self-assignment check
        return *this;
    }

    // Step 2: Free existing nodes (to avoid memory leaks)
    Node* current = first;
    while (current) {
        Node* next = current->get_next();
        delete current;
        current = next;
    }

    // Step 3: Transfer ownership from `other`
    first = other.first;
    last = other.last;

    // Step 4: Leave `other` in a valid empty state
    other.first = nullptr;
    other.last = nullptr;

    return *this;
}

bool List::is_empty() const {
    return first == nullptr;
}

void List::insert(int data) {
    if (is_empty()) { // if to insert into an empty list
        first = new Node{nullptr, data, nullptr};
        last = first;
        return;
    }

    if (get_first()->get_data() >= data) {
        first->set_prev(new Node{nullptr, data, first});
        first = first->get_prev();
        return;
    }

    if (get_last()->get_data() <= data ) {
        last->set_next(new Node{last, data, nullptr});
        last = last->get_next();
        return;
    }

    int list_length {get_length()};
    Node* current_node {};
    Node* prev_node {};
    Node* new_node {};

    for (int node {}; node < list_length; node++) {
        current_node = get_node(node); // The current node in the iteration
        prev_node = current_node->get_prev();

        if (current_node->get_data() >= data) {
            new_node = new Node{prev_node, data, current_node};
            current_node->set_prev(new_node);
            prev_node->set_next(new_node);
        }
    }
}

int List::get_length() const {

    if (is_empty()) return 0;

    int length {1};
    Node* node {get_first()};

    while(node->get_next() != nullptr) {
        node = node->get_next();
        length += 1;
    }

    return length;
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

    std::string output_str {"{"};
    int list_length {list.get_length()};

    for (int index {}; index < list_length; index++) {
        output_str += std::to_string(list.index_of(index));

        if (index + 1 != list_length) {
            output_str += ", "; // only add if not last element of list
        }
    }

    output_str += "}";
    return os << output_str;
}

Node* List::get_node(int index) const {

    Node* current_node {get_first()};

    if (!current_node || index < 0) {
        throw std::logic_error("Index out of range!");
    }

    for (int node {}; node < index; node++) {
        if (current_node->get_next() == nullptr) {
            throw std::logic_error("Index out of range!");
        }
        current_node = current_node->get_next();
    }

    return current_node;
}

int List::index_of(int index) const {
    return get_node(index)->get_data();
}

void List::remove(int index) {
    Node* node {get_node(index)};

    if (node == get_first() && node == get_last()) {
        first = last = nullptr;
    }

    else if (node == get_first()) {
        first = node->get_next();
        first->set_prev_null();

    }
    else if (node == get_last()) {
        last = node->get_prev();
        last->set_next_null();
    }
    else {
        Node* right_node {node->get_next()};
        Node* left_node {node->get_prev()};

        left_node->set_next(right_node);
        right_node->set_prev(left_node);
    }

    delete node;
    node = nullptr;
}

// Bonus
