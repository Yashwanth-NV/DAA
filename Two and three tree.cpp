#include <iostream>
using namespace std;

class Node {
public:
    int keys[3];      // max 3 keys (temporary)
    Node* child[4];   // max 4 children
    int n;            // number of keys
    bool leaf;

    Node(bool leaf = true) {
        this->leaf = leaf;
        n = 0;
        for (int i = 0; i < 4; i++) child[i] = NULL;
    }
};

class TwoThreeTree {
public:
    Node* root;

    TwoThreeTree() {
        root = new Node();
    }

    void insert(int key) {
        if (root->n == 2) {
            Node* newRoot = new Node(false);
            newRoot->child[0] = root;
            split(newRoot, 0);
            root = newRoot;
        }
        insertNonFull(root, key);
    }

    void insertNonFull(Node* node, int key) {
        int i = node->n - 1;

        if (node->leaf) {
            while (i >= 0 && key < node->keys[i]) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
            node->n++;
        } else {
            while (i >= 0 && key < node->keys[i]) i--;
            i++;

            if (node->child[i]->n == 2) {
                split(node, i);
                if (key > node->keys[i]) i++;
            }
            insertNonFull(node->child[i], key);
        }
    }

    void split(Node* parent, int i) {
        Node* node = parent->child[i];
        Node* newNode = new Node(node->leaf);

        int mid = node->keys[1];

        newNode->keys[0] = node->keys[2];
        newNode->n = 1;
        node->n = 1;

        if (!node->leaf) {
            newNode->child[0] = node->child[2];
            newNode->child[1] = node->child[3];
        }

        for (int j = parent->n; j > i; j--) {
            parent->keys[j] = parent->keys[j - 1];
            parent->child[j + 1] = parent->child[j];
        }

        parent->keys[i] = mid;
        parent->child[i + 1] = newNode;
        parent->n++;
    }

    void display(Node* node, int level = 0) {
        if (!node) return;

        for (int i = 0; i < level; i++) cout << "  ";
        for (int i = 0; i < node->n; i++) cout << node->keys[i] << " ";
        cout << endl;

        for (int i = 0; i <= node->n; i++)
            display(node->child[i], level + 1);
    }
};

int main() {
    TwoThreeTree t;

    int arr[] = {10, 20, 5, 15, 25};
    for (int x : arr) t.insert(x);

    t.display(t.root);

    return 0;
}