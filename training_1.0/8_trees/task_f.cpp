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

void print(Tree*& root, ostream& out) {
    if (root) {
        print(root->left, out);
        if (root->left && root->right) 
            out << root->key << '\n';
        print(root->right, out);
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    Tree* root = nullptr;

    int n;
    while (fin >> n) {
        if (n != 0) add(root, n);
    }

    print(root, fout);
}
