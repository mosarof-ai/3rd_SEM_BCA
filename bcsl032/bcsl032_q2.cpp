#include <iostream>
#include <memory>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int v): data(v), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList(): head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList() {
        Node* cur = head;
        while(cur) {
            Node* t = cur->next;
            delete cur;
            cur = t;
        }
    }

    void insert(int value) {
        Node* n = new Node(value);
        n->prev = tail;
        if(!tail) head = n;
        else tail->next = n;
        tail = n;
        cout << "Inserted: " << value << '\n';
    }

    void deleteNode(int value) {
        if(!head) { cout << "List is empty!\n"; return; }
        Node* cur = head;
        while(cur && cur->data != value) cur = cur->next;
        if(!cur) { cout << "Value " << value << " not found!\n"; return; }
        if(cur->prev) cur->prev->next = cur->next; else head = cur->next;
        if(cur->next) cur->next->prev = cur->prev; else tail = cur->prev;
        delete cur;
        cout << "Deleted: " << value << '\n';
    }

    void search(int value) {
        Node* cur = head;
        int pos = 1;
        while(cur) {
            if(cur->data == value) { cout << "Found " << value << " at position " << pos << '\n'; return; }
            cur = cur->next; ++pos;
        }
        cout << "Value " << value << " not found!\n";
    }

    void displayForward() {
        if(!head) { cout << "List is empty!\n"; return; }
        cout << "\nForward: NULL <-> ";
        for(Node* cur = head; cur; cur = cur->next) {
            cout << cur->data;
            if(cur->next) cout << " <-> ";
        }
        cout << " <-> NULL\n";
    }

    void displayBackward() {
        if(!tail) { cout << "List is empty!\n"; return; }
        cout << "Backward: NULL <-> ";
        for(Node* cur = tail; cur; cur = cur->prev) {
            cout << cur->data;
            if(cur->prev) cout << " <-> ";
        }
        cout << " <-> NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;
    int choice = 0, value = 0;
    cout << "\n========================================\n";
    cout << "  DOUBLY LINKED LIST IMPLEMENTATION\n";
    cout << "========================================\n\n";
    while(true) {
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display Forward\n5. Display Backward\n6. Exit\n";
        cout << "Enter choice: ";
        if(!(cin >> choice)) break;
        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                dll.insert(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                dll.deleteNode(value);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                dll.search(value);
                break;
            case 4:
                dll.displayForward();
                break;
            case 5:
                dll.displayBackward();
                break;
            case 6:
                cout << "\nExiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}
