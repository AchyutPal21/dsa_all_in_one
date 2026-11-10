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

    // DFS (In-Order Traversal)
    void inOrderDisp(Node* ptr) {
        if (!ptr) return;
        inOrderDisp(ptr->leftNode);
        cout << ptr->val << " ";
        inOrderDisp(ptr->rightNode);
    }

    // Iterative In-Order Traversal
    void inOrderIterative() {
        stack<Node*> s;
        Node* curr = root;

        while (curr != nullptr || !s.empty()) {
            // Reach the leftmost node of the current node
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->leftNode;
            }

            // Current must be null at this point, so pop from stack
            curr = s.top();
            s.pop();

            cout << curr->val << " ";

            // We have visited the node and its left subtree. Now, do the right subtree.
            curr = curr->rightNode;
        }
    }

    // DFS (Pre-Order Traversal)
    void preOrderDisp(Node* ptr) {
        if (!ptr) return;
        cout << ptr->val << " ";
        preOrderDisp(ptr->leftNode);
        preOrderDisp(ptr->rightNode);
    }

    // Iterative Pre-Order Traversal
    void preOrderIterative() {
        if (!root) return;
        stack<Node*> s;
        s.push(root);

        while (!s.empty()) {
            Node* curr = s.top();
            s.pop();

            cout << curr->val << " ";

            // Push right first so that left is processed first (LIFO order)
            if (curr->rightNode != nullptr) {
                s.push(curr->rightNode);
            }
            if (curr->leftNode != nullptr) {
                s.push(curr->leftNode);
            }
        }
    }

    // DFS (Post-Order Traversal)
    void postOrderDisp(Node* ptr) {
        if (!ptr) return;
        postOrderDisp(ptr->leftNode);
        postOrderDisp(ptr->rightNode);
        cout << ptr->val << " ";
    }

    // Iterative Post-Order Traversal
    void postOrderIterative() {
        if (!root) return;

        stack<Node*> s1;
        stack<Node*> s2;
        s1.push(root);

        while (!s1.empty()) {
            Node* curr = s1.top();
            s1.pop();
            s2.push(curr);

            // Push left first, then right onto s1
            if (curr->leftNode != nullptr) {
                s1.push(curr->leftNode);
            }
            if (curr->rightNode != nullptr) {
                s1.push(curr->rightNode);
            }
        }

        // Print elements from stack 2
        while (!s2.empty()) {
            cout << s2.top()->val << " ";
            s2.pop();
        }
    }

    // Iterative Post-Order Single Stack Traversal
    void postOrderIterativeOpt() {
        stack<Node*> s;
        Node* curr{root};
        Node* lastVisited{nullptr};

        while (curr != nullptr || !s.empty()) {
            if (curr != nullptr) {
                s.push(curr);
                curr = curr->leftNode;
            } else {
                Node* stackTopNode = s.top();

                if (stackTopNode->rightNode != nullptr && stackTopNode->rightNode != lastVisited) {
                    curr = stackTopNode->rightNode;
                } else {
                    cout << stackTopNode->val << " ";
                    lastVisited = stackTopNode;
                    s.pop();
                }
            }
        }
    }

    // BFS (Level Order Traversal)
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

    cout << "Pre-Order Iterative Traversal: ";
    bt.preOrderIterative();
    cout << endl;

    cout << "In-Order Traversal:   ";
    bt.inOrderDisp(bt.getRootNode());
    cout << endl;

    cout << "In-Order Iterative Traversal: ";
    bt.inOrderIterative();
    cout << endl;

    cout << "Post-Order Traversal: ";
    bt.postOrderDisp(bt.getRootNode());
    cout << endl;

    cout << "Post-Order Iterative Traversal: ";
    bt.postOrderIterative();
    cout << endl;

    cout << "Post-Order Iterative Traversal Single Stack: ";
    bt.postOrderIterativeOpt();
    cout << endl;

    cout << "Level-Order Traversal: ";
    bt.levelOrderDisp(bt.getRootNode());
    cout << endl;

    return 0;
}