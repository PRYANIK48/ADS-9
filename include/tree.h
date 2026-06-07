// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>
#include <cstddef>

class PMTree {
 public:
    struct Node {
        char ch;
        std::vector<Node*> children;
        explicit Node(char c) {
            ch = c;
        }
    };
    explicit PMTree(std::vector<char> arr) {
        top = new Node('\0');
        std::sort(arr.begin(), arr.end());
        createNode(top, arr);
    }
    ~PMTree() {
        deleteNode(top);
    }
    Node* getTop() {
        return top;
    }

 private:
    Node* top;
    void createNode(Node* node, std::vector<char> left) {
        if (left.empty()) {
            return;
        }
        std::sort(left.begin(), left.end());
        for (size_t i = 0; i < left.size(); i++) {
            Node* children = new Node(left[i]);
            node->children.push_back(children);
            std::vector<char> tmp = left;
            tmp.erase(tmp.begin() + i);
            createNode(children, tmp);
        }
    }
    void deleteNode(Node* node) {
        if (node == nullptr) {
            return;
        }
        for (size_t i = 0; i < node->children.size(); i++) {
            deleteNode(node->children[i]);
        }
        delete node;
    }
};

std::vector<std::vector<char>> getAllPerms(PMTree& tree);
std::vector<char> getPerm1(PMTree& tree, int num);
std::vector<char> getPerm2(PMTree& tree, int num);
#endif  // INCLUDE_TREE_H_
