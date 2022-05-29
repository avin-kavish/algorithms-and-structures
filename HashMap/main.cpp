//
// Created by avin on 5/29/22.
//

#include <iostream>
#include <vector>
#include <tuple>

const int NUM_BUCKETS = 1000;

class HashMap {
public:
    HashMap() : store(NUM_BUCKETS, std::vector<std::tuple<int, int>>(0)) {

    }

    void put(int key, int value) {
        auto idx = hash(key);
        for (auto ptr = this->store[idx].begin(); ptr < this->store[idx].end(); ptr++) {
            if (std::get<0>(*ptr) == key) {
                *ptr = std::make_tuple(key, value);
                return;
            }
        }
        this->store[idx].push_back(std::make_tuple(key, value));
    }

    int get(int key) {
        auto idx = hash(key);
        for (auto ptr = this->store[idx].begin(); ptr < this->store[idx].end(); ptr++) {
            if (std::get<0>(*ptr) == key) {
                return std::get<1>(*ptr);
            }
        }
        return -1;
    }

    void remove(int key) {
        auto idx = hash(key);
        for (auto ptr = this->store[idx].begin(); ptr < this->store[idx].end(); ptr++) {
            if (std::get<0>(*ptr) == key) {
                this->store[idx].erase(ptr);
                break;
            }
        }
    }

private:
    std::vector <std::vector<std::tuple < int, int>>>
    store;

    int hash(int key) {
        return key % NUM_BUCKETS;
    }
};

int main() {
    auto obj = new HashMap();

    obj->put(1, 10);

    int param_2 = obj->get(1);

    obj->remove(1);
};
