#include <iostream>
#include <queue>

using namespace std;

class Node {
   public:
    int val;
    Node* leftNode;
    Node* rightNode;

    Node(int val) {
        this->val = val;
        this->leftNode = nullptr;
        this->rightNode = nullptr;
    }
};

class BinaryTree {
   private:
    Node* root;

   public:
    BinaryTree() { this->root = nullptr; }

    BinaryTree(Node* node) { this->root = node; }

    Node* getRootNode() { return this->root; }

    void addLeftNode(Node* parent, Node* child) { parent->leftNode = child; }

    void addRightNode(Node* parent, Node* child) { parent->rightNode = child; }

    void inOrderDisp(Node* ptr) {
        if (!ptr) return;
        inOrderDisp(ptr->leftNode);
        cout << ptr->val << " ";
        inOrderDisp(ptr->rightNode);
    }

    void preOrderDisp(Node* ptr) {
        if (!ptr) return;
        cout << ptr->val << " ";
        preOrderDisp(ptr->leftNode);
        preOrderDisp(ptr->rightNode);
    }

    void postOrderDisp(Node* ptr) {
        if (!ptr) return;
        postOrderDisp(ptr->leftNode);
        postOrderDisp(ptr->rightNode);
        cout << ptr->val << " ";
    }

    void levelOrderDisp(Node* ptr) {
        queue<Node*> qNode;

        // Push the root node
        qNode.push(ptr);

        // Push and pop the nodes
        while (!qNode.empty()) {
            // Get the currect Node
            Node* currNode = qNode.front();
            qNode.pop();

            cout << currNode->val << " ";

            // Check if the left node is present push into queqe
            if (currNode->leftNode != nullptr) {
                qNode.push(currNode->leftNode);
            }

            // Check if the right node is present, push into queue
            if (currNode->rightNode != nullptr) {
                qNode.push(currNode->rightNode);
            }
        }
    }

    ~BinaryTree() { clear(); }

   private:
    void clear() {
        freeMemory(root);
        root = nullptr;
    }

    void freeMemory(Node* ptr) {
        if (!ptr) return;
        freeMemory(ptr->leftNode);
        freeMemory(ptr->rightNode);
        delete ptr;
    }
};

int main() {
    // 1. Create the root node and initialize the tree
    Node* rootNode = new Node(1);
    BinaryTree bt(rootNode);

    // 2. Create child nodes
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);

    // 3. Link the nodes to form the requested tree structure:
    //                1
    //          2        3
    //       4   5    6    7
    bt.addLeftNode(bt.getRootNode(), n2);
    bt.addRightNode(bt.getRootNode(), n3);

    bt.addLeftNode(n2, n4);
    bt.addRightNode(n2, n5);

    bt.addLeftNode(n3, n6);
    bt.addRightNode(n3, n7);

    // 4. Display the tree using different traversals
    cout << "Pre-Order Traversal:  ";
    bt.preOrderDisp(bt.getRootNode());
    cout << endl;

    cout << "In-Order Traversal:   ";
    bt.inOrderDisp(bt.getRootNode());
    cout << endl;

    cout << "Post-Order Traversal: ";
    bt.postOrderDisp(bt.getRootNode());
    cout << endl;

    cout << "Level-Order Traversal: ";
    bt.levelOrderDisp(bt.getRootNode());
    cout << endl;

    return 0;
}