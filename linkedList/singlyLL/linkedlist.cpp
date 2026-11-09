#include <iostream>

using namespace std;

class Node {
   public:
    int val;
    Node* next{nullptr};

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class LinkedList {
   private:
    Node* head;

   public:
    LinkedList() { this->head = nullptr; }

    void append(Node* node) {
        if (this->head == nullptr) {
            this->head = node;
        } else {
            Node* ptr = head;
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }

            ptr->next = node;
        }
    }

    Node* remove(int val) {
        if (this->head == nullptr) return nullptr;

        Node* prev = nullptr;
        Node* curr = head;

        while (curr != nullptr && curr->val != val) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = nullptr;

        return curr;
    }

    void display() {
        Node* ptr{head};
        while (ptr != nullptr) {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
    }

    // Destructor to free dynamically allocated memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }
};

int main() {
    cout << "Hello from LinkedList page" << endl;
    LinkedList ll;
    ll.append(new Node(1));
    ll.append(new Node(2));
    ll.append(new Node(3));
    ll.append(new Node(4));
    ll.append(new Node(5));

    ll.display();
    cout << endl;
    Node* node = ll.remove(3);

    cout << "Deleted Node: " << node << " val: " << node->val << " ptr: " << (node->next == nullptr)
         << endl;

    ll.display();

    cout << endl;

    return 0;
}