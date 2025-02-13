#include "node.hpp"

Node::Node(Node* prev, int data, Node* next) : data{data}, next{nullptr}, prev{nullptr} {}