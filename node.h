#ifndef INC_340PROJECT_NODE_H
#define INC_340PROJECT_NODE_H
template <typename T>
class Node {
public:
    T data;
    Node* next;

    // Constructor initializing the node with data and optionally a next node.
    Node(const T& data, Node* next = nullptr);
};

#endif // NODE_H