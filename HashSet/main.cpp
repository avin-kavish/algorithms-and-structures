#include <iostream>
#include <vector>

const int NUM_BUCKETS = 1000;

class HashSet {
public:
    HashSet(): store(NUM_BUCKETS, std::vector<int>(0)) {
    }

    void add(int key) {
        auto idx = hash(key);
        for (auto ptr = this->store[idx].begin(); ptr < this->store[idx].end(); ptr++) {
            if (*ptr == key) {
                return;
            }
        }
        this->store[idx].push_back(key);
    }

    void remove(int key) {
        auto idx = hash(key);
        for (auto ptr = this->store[idx].begin(); ptr < this->store[idx].end(); ptr++) {
            if (*ptr == key) {
                this->store[idx].erase(ptr);
                break;
            }
        }
    }

    bool contains(int key) {
        auto idx = hash(key);
        for (auto ptr = this->store[idx].begin(); ptr < this->store[idx].end(); ptr++) {
            if (*ptr == key) {
                return true;
            }
        }
        return false;
    }

private:
    std::vector<std::vector<int>> store;

    int hash(int key) {
        return key % NUM_BUCKETS;
    }
};

int main() {

    std::cout << "Hello World!" << std::endl;

    auto c = new HashSet();
    c->add(10);
    c->add(20);

    std::cout << c->contains(10) << std::endl;

    c->remove(10);
    std::cout << c->contains(10) << std::endl;

    return 0;
}
