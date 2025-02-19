#ifndef NODE_HPP  // Check if NODE_HPP is not defined
#define NODE_HPP  // Define NODE_HPP

class Node {
    public:

        Node(Node* prev = nullptr, int data = {}, Node* next = nullptr);

        Node* get_next() const;
        Node* get_prev() const;
        int get_data() const;

        void set_next(Node* node);
        void set_next_null();
        void set_prev(Node* node);
        void set_prev_null();

    private:

        Node* prev;
        int data;
        Node* next;

};

#endif
