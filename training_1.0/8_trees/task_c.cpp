#include <iostream>
#include <fstream>
using namespace std;

struct Tree {
    int key;
    Tree* left;
    Tree* right;
};

void add(Tree*& root, int key) {
    if (!root) {
        root = new Tree;
        root->key = key;
        root->left = nullptr;
        root->right = nullptr;
    } else {
        if (root->key == key) {
            return;
        } else if (root->key > key) {
            add(root->left, key);
        } else {
            add(root->right, key);
        }
    }
}

int find_second_max(Tree* root, Tree* prev_node = nullptr, bool went_left_once = false) {
    if (root->right)
        return find_second_max(root->right, root, went_left_once);
    if (root->left && !went_left_once)
        return find_second_max(root->left, root, true);
    return (went_left_once ? root->key : prev_node->key);  
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    Tree* root = nullptr;

    int n;
    while (fin >> n) {
        if (n != 0) add(root, n);
    }

    fout << find_second_max(root);
}
