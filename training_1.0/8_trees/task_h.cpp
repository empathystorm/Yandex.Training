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
    return max(max_depth(root->left), max_depth(root->right)) + 1;
}

int min_depth(Tree*& root) {
    if (!root) return 0;
    return min(max_depth(root->left), max_depth(root->right)) + 1;
}

bool is_balanced = true;

void check_avl_balanced(Tree*& root) {
    if (root->left) check_avl_balanced(root->left);
    if (max_depth(root) - min_depth(root) > 1) is_balanced = false;
    if (root->right) check_avl_balanced(root->right);
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    Tree* root = nullptr;

    int n;
    while (fin >> n) {
        if (n != 0) add(root, n);
    }

    check_avl_balanced(root);

    fout << (is_balanced ? "YES" : "NO");
}
