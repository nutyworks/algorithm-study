#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    struct node *left, *right;
    int value;
} node_t;

typedef struct tree {
    node_t *top;
} tree_t;

void node_insert(node_t* node, int value) {
    if (node->value > value) {
        if (node->left == nullptr) {
            node_t *new_node = new node_t{nullptr, nullptr, value};
            node->left = new_node;
        } else {
            node_insert(node->left, value);
        }
    } else {
        if (node->right == nullptr) {
            node_t *new_node = new node_t{nullptr, nullptr, value};
            node->right = new_node;
        } else {
            node_insert(node->right, value);
        }
    }
}

void tree_insert(tree_t* tree, int value) {
    if (tree->top == nullptr) {
        node_t *new_node = new node_t{nullptr, nullptr, value};
        tree->top = new_node;
    } else {
        node_insert(tree->top, value);
    }
}

void node_traverse(node_t* node) {
    if (node == nullptr) return;

    node_traverse(node->left);
    node_traverse(node->right);
    cout << node->value << '\n';
}

void tree_traverse(tree_t* tree) {
    node_traverse(tree->top);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    tree_t tree {nullptr};

    while (true) {
        int t;
        cin >> t;
        if (cin.eof()) break;
        tree_insert(&tree, t);
    }

    tree_traverse(&tree);

    return 0;
}