#include "linkedlist.h"
#include "guest.h"
#include "elevator.h"

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {
    // Constructor implementation
}

template <typename T>
LinkedList<T>::~LinkedList() {
    // Destructor implementation: Delete all nodes
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void LinkedList<T>::insert(const T& data) {
    // Insert a new element at the beginning of the list
    Node<T>* newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
}

template <typename T>
T& LinkedList<T>::get(int index) {
    Node<T>* current = head;
    for (int i = 0; current != nullptr && i < index; ++i) {
        current = current->next;
    }
    if (current == nullptr) {
        throw std::out_of_range("Index out of range"); // Or handle the error as appropriate
    }
    return current->data;
}

template <typename T>
bool LinkedList<T>::remove(const T& data) {
    // Remove an element from the list
    Node<T>* current = head;
    Node<T>* prev = nullptr;

    while (current != nullptr) {
        if (current->data == data) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false; // Element not found
}

template <typename T>
T* LinkedList<T>::find(const T& data) const {
    // Find an element in the list
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return &(current->data);
        }
        current = current->next;
    }
    return nullptr; // Element not found
}

template <typename T>
int LinkedList<T>::size() const {
    // Get the size of the list
    int count = 0;
    Node<T>* current = head;
    while (current != nullptr) {
        ++count;
        current = current->next;
    }
    return count;
}

template <typename T>
Node<T>* LinkedList<T>::getHead() const {
    return head; // Return the head of the list
}

// Implementing Iterator class methods (you need to fill in the details based on your design)
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin() const {
    return Iterator(head);
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end() const {
    return Iterator(nullptr);
}

template <typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++() {
    // Increment operator logic here
    // Example:
    current = current->next;
    return *this;
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++(int) {
    Iterator iterator = *this;
    ++(*this);
    return iterator;
}

template <typename T>
bool LinkedList<T>::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}

template <typename T>
T& LinkedList<T>::Iterator::operator*() const {
    return current->data;
}

// Explicit template instantiation
template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<Guest>;
template class LinkedList<Elevator>;