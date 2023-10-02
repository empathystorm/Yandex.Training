#include <iostream>
#include <fstream>
using namespace std;

struct Tree {
    int key;
    Tree* left;
    Tree* right;
    int depth;
};

Tree* add(Tree*& root, int key, int depth = 1) {
    if (!root) {
        root = new Tree;
        root->key = key;
        root->left = nullptr;
        root->right = nullptr;
        root->depth = depth;
        return root;
    } else {
        if (root->key == key) {
            return nullptr;
        } else if (root->key > key) {
            return add(root->left, key, depth+1);
        } else {
            return add(root->right, key, depth+1);
        }
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    Tree* root = nullptr;

    int n;
    while (fin >> n) {
        if (n != 0) {
            Tree* node = add(root, n);
            if (node) fout << node->depth << ' ';
        }
    }
}
