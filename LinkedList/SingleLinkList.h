/*
 * Created by avin on 5/29/22.
 * This is an implementation of a Linked List that uses a single forward pointer for linkage.
 * It maintains head and tail pointers to achieve O(1) inserts on either end.
 */

#ifndef ALGORITHMS_SINGLELINKLIST_H
#define ALGORITHMS_SINGLELINKLIST_H

#include <iostream>

template<typename T>
struct Node {
    T value;
    Node *next = nullptr;

    Node(T x) : value(x) {

    }
};

template<typename T>
class SingleLinkList {
public:
    int get(int index) {
        Node<T> *ptr = head;
        for (int i = 0; i < index; ++i) {
            if (ptr == nullptr) break;
            ptr = ptr->next;
//            std::cout  << ptr << std::endl;
        }
        return ptr == nullptr ? -1 : ptr->value;
    }

    void addAtHead(T val) {
        auto curr_head = head;
        head = new Node<T>(val);
        head->next = curr_head;

        if (tail == nullptr) tail = head;
    }

    void addAtTail(T val) {
        if (tail == nullptr) {
            tail = new Node<T>(val);
            head = tail;
        } else {
            tail->next = new Node<T>(val);
            tail = tail->next;
        }
    }

    void addAtIndex(int index, T val) {
        // Special cases for first element
        if (index == 0) {
            if (head == nullptr) {
                auto obj = new Node<T>(val);
                head = obj;
                tail = obj;
            } else if (head == tail) {
                head = new Node<T>(val);
                head->next = tail;
            } else {
                auto next = head->next;
                head = new Node<T>(val);
                head->next = next;
            }
            return;
        }

        Node<T> *ptr = head;
        if (ptr == nullptr) return;
        for (int i = 0; i < index - 1; ++i) {
            ptr = ptr->next;
            if (ptr == nullptr) return;
        }

        auto next_next = ptr->next;
        ptr->next = new Node<T>(val);
        ptr->next->next = next_next;

        if (next_next == nullptr) {
            tail = ptr->next;
        }
    }

    void deleteAtIndex(int index) {
        // If the list has no elements, do nothing and return
        if (head == nullptr) return;

        // Special cases for first element
        if (index == 0) {
            // If the list has just one element, reset head and tail pointers to null
            if (head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            } else {
                // If the list has more than one element, delete first element and point head to second element
                auto next = head->next;
                delete head;
                head = next;
            }
            return;
        }

        // Iterate over linked list till the element preceding the element to be deleted is reached.
        Node<T> *prev = head;
        for (int i = 0; i < index - 1; ++i) {
            prev = prev->next;
            // If index is out of bounds of the list, do nothing and return
            if (prev == nullptr) return;
        }
        std::cout << "head: " << head << std::endl;
        std::cout << "prev: " << prev << std::endl;
        // Get the element to be deleted
        auto curr = prev->next;
        // If index is out of bounds of the list, do nothing and return
        if (curr == nullptr) return;

        // If the value being deleted is the tail, set the previous value as the tail.
        if (curr == tail) {
            tail = prev;
        }

        // Remove the element from the linked list by pointing over it to the next element.
        prev->next = curr->next;

        // Free up memory held by the removed element.
        delete curr;
    }

    void print() {
        Node<T> *ptr = head;
        while (ptr != nullptr) {
            std::cout << ptr->value << " ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
        std::cout << "current head:" << head << ": " << (head == nullptr ? -1 : head->value) << std::endl;
        std::cout << "current tail:" << tail << ": " << (tail == nullptr ? -1 : tail->value) << std::endl;
    }

private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
};

#endif //ALGORITHMS_SINGLELINKLIST_H
