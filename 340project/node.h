//
// Created by Subhan Khan on 12/10/23.
//

#ifndef INC_340PROJECT_NODE_H
#define INC_340PROJECT_NODE_H
template <typename T>
class Node {
public:
    T data;
    Node* next;

    // Constructor initializing the node with data and optionally a next node.
    Node(const T& data, Node* next = nullptr);

    // Additional methods can be added here if needed
};

#endif // NODE_H