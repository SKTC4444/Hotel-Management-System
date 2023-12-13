#include "node.h"
#include "guest.h"
#include "elevator.h"

template <typename T>
Node<T>::Node(const T& data, Node* next) : data(data), next(next) {
    // The constructor initializes the node with the given data and next pointer.
}

// Explicit template instantiation
template class Node<int>;
template class Node<double>;
template class Node<Guest>;
template class Node<Elevator>;
