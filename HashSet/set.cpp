//
// WIP Implementation of a set as a BST.
//

#include <iostream>

class Node {
public:
    int value;

    Node *lleaf = NULL;
    Node *rleaf = NULL;

    Node(int value) {
        this->value = value;
    }
};

class Set {
public:
    Set() {
    }

    void add(int key) {
        auto node = this->recursiveSearch(key, &this->root);
        if (*node == nullptr) {
            *node = new Node(key);
        }
    }

    void remove(int key) {
        // TODO: not implemented
    }

    bool contains(int key) {
        auto node = this->recursiveSearch(key, &this->root);
        return *node != nullptr;
    }

private:
    Node *root;

    Node **recursiveSearch(int key, Node **node) {
        if (*node == nullptr) {
            return node;
        }

        if ((*node)->value == key) return node;

        if (key < root->value)
            return this->recursiveSearch(key, &root->lleaf);
        else
            return this->recursiveSearch(key, &root->rleaf);
    }
};

int main() {

    std::cout << "Hello World!" << std::endl;

    auto c = new Set();
    c->add(10);
    c->add(20);

    std::cout << c->contains(10) << std::endl;

    return 0;
}
