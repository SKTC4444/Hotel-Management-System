#ifndef INC_340PROJECT_LINKEDLIST_H
#define INC_340PROJECT_LINKEDLIST_H

#include "node.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList(); // Constructor
    ~LinkedList(); // Destructor

    void insert(const T& data); // Insert a new element
    bool remove(const T& data); // Remove an element
    T* find(const T& data) const; // Find an element
    int size() const; // Get the size of the list

    Node<T>* getHead() const; // Get the head of the list

    T& get(int index);
    // Additional methods tailored for tracking guests and elevators can be added here...

    // Iterator class for LinkedList
    class Iterator {
    private:
        Node<T>* current;

    public:
        Iterator(Node<T>* node) : current(node) {}

        Iterator& operator++(); // Pre-increment
        Iterator operator++(int); // Post-increment
        bool operator!=(const Iterator& other) const;
        T& operator*() const;
    };

    Iterator begin() const;
    Iterator end() const;
};

#endif // LINKEDLIST_H