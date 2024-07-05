#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <array>
#include <deque>
#include <forward_list>
#include <unordered_set>
#include <unordered_map>

// Helper function to print sequences
template <typename Iter>
void printSequence(Iter begin, Iter end) {
    if (begin == end) {
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[";
    Iter it = begin;
    std::cout << *it;
    for (++it; it != end; ++it) {
        std::cout << ", " << *it;
    }
    std::cout << "]" << std::endl;
}

// Helper function to print associative containers
template <typename Iter>
void printAssociative(Iter begin, Iter end) {
    if (begin == end) {
        std::cout << "{}" << std::endl;
        return;
    }
    std::cout << "{";
    Iter it = begin;
    std::cout << it->first << ": " << it->second;
    for (++it; it != end; ++it) {
        std::cout << ", " << it->first << ": " << it->second;
    }
    std::cout << "}" << std::endl;
}

// Template functions for different containers
template <typename T>
void printVector(const std::vector<T>& vec) {
    printSequence(vec.begin(), vec.end());
}

template <typename T>
void printStack(std::stack<T> st) {
    while (!st.empty()) {
        std::cout << st.top() << std::endl;
        st.pop();
    }
}

template <typename T, std::size_t N>
void printArray(const std::array<T, N>& arr) {
    printSequence(arr.begin(), arr.end());
}

template <typename T>
void printList(const std::list<T>& lst) {
    printSequence(lst.begin(), lst.end());
}

template <typename T>
void printDeque(const std::deque<T>& deq) {
    printSequence(deq.begin(), deq.end());
}

template <typename T>
void printForwardList(const std::forward_list<T>& flst) {
    printSequence(flst.begin(), flst.end());
}

template <typename T>
void printSet(const std::set<T>& s) {
    printSequence(s.begin(), s.end());
}

template <typename T>
void printMultiSet(const std::multiset<T>& ms) {
    printSequence(ms.begin(), ms.end());
}

template <typename K, typename V>
void printMap(const std::map<K, V>& m) {
    printAssociative(m.begin(), m.end());
}

template <typename K, typename V>
void printMultiMap(const std::multimap<K, V>& mm) {
    printAssociative(mm.begin(), mm.end());
}

template <typename T>
void printUnorderedSet(const std::unordered_set<T>& us) {
    printSequence(us.begin(), us.end());
}

template <typename T>
void printUnorderedMultiSet(const std::unordered_multiset<T>& ums) {
    printSequence(ums.begin(), ums.end());
}

template <typename K, typename V>
void printUnorderedMap(const std::unordered_map<K, V>& um) {
    printAssociative(um.begin(), um.end());
}

template <typename K, typename V>
void printUnorderedMultiMap(const std::unordered_multimap<K, V>& umm) {
    printAssociative(umm.begin(), umm.end());
}

template <typename T>
void printMatrix(const std::vector<std::vector<T>>& matrix) {
    std::cout << "[";
    for (size_t i = 0; i < matrix.size(); ++i) {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << "[";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            std::cout << matrix[i][j];
            if (j != matrix[i].size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]";
        if (i != matrix.size() - 1) {
            std::cout << std::endl;
        }
    }
    std::cout << "]" << std::endl;
}
