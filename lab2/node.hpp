
class Node {
    public:

        Node(Node* prev = nullptr, int data = {}, Node* next = nullptr);


    private:

        Node* prev;
        int data;
        Node* next;

};