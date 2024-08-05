#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>

// Template function to print elements of vector
template <typename T>
void printVector(const std::vector<T>& vec) {
    if (vec.empty()) {
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[";
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        std::cout << vec[i] << ", ";
    }
    std::cout << vec.back() << "]" << std::endl;
}

// Template function to print elements of list
template <typename T>
void printList(const std::list<T>& lst) {
    if (lst.empty()) {
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[";
    auto it = lst.begin();
    std::cout << *it++;
    for (; it != lst.end(); ++it) {
        std::cout << ", " << *it;
    }
    std::cout << "]" << std::endl;
}

// Template function to print elements of set
template <typename T>
void printSet(const std::set<T>& s) {
    if (s.empty()) {
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[";
    auto it = s.begin();
    std::cout << *it++;
    for (; it != s.end(); ++it) {
        std::cout << ", " << *it;
    }
    std::cout << "]" << std::endl;
}

// Template function to print elements of map
template <typename K, typename V>
void printMap(const std::map<K, V>& m) {
    if (m.empty()) {
        std::cout << "{}" << std::endl;
        return;
    }
    std::cout << "{";
    auto it = m.begin();
    std::cout << it->first << ": " << it->second;
    for (++it; it != m.end(); ++it) {
        std::cout << ", " << it->first << ": " << it->second;
    }
    std::cout << "}" << std::endl;
}
