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

int max_depth(Tree*& root) {
    if (!root) return 0;

    int left = max_depth(root->left);
    int right = max_depth(root->right);

    if (left <= right) return right+1;
    else return left+1;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    Tree* root = nullptr;

    int n;
    while (fin >> n) {
        if (n != 0) add(root, n);
    }

    fout << max_depth(root);
}
