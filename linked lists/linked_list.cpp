#include<iostream>

template <typename T>

class LinkedList {

    class Node {
    public:
        T data;
        Node *next = NULL;

        Node (T data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

    Node* head;
    Node* current;
    int length;

public:
    LinkedList() {
        head = current = NULL;
        length = 0;
    }

    void insert(T data, int index = -1) {
        if(head == NULL) {              // list has no elements
            head = current = new Node(data);
        } else {
            if (index == -1) {            // insert at the end
                current -> next = new Node(data);
                current = current -> next;
            } else if (index == 0) {     // insert at head
                Node* oldHead = head;
                head = new Node(data);
                head -> next = oldHead;
            } else {                    // insert at given index
                if (index > length) {
                    throw "Invalid operation: index is greater than length of list.";
                }

                Node* temp = head;
                for (int i = 0; i < index - 1; i++)
                    temp = temp -> next;

                Node* newNode = new Node(data);
                newNode -> next = temp -> next;
                temp -> next = newNode;
            }
        }
        length++;
    }

    void remove(int index) {
        if (index >= length) {
            throw "Invalid operation: index is greater than length of list.";
        }

        if (index == 0) {       // remove the head
            Node* oldHead = head;
            head = head -> next;
            delete oldHead;
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; i++)
                temp = temp -> next;

            Node* toBeDeleted = temp -> next;
            temp -> next = temp -> next -> next;
            delete toBeDeleted;
        }
        length--;
    }

    T get(int index) {
        if (index >= length) {
            throw "Invalid operation: index is greater than length of list.";
        }

        Node* temp = head;
        for (int i = 0; i < index; i++)
            temp = temp -> next;
        return temp -> data;
    }

    void print() {
        std::cout << "List: ";
        Node* temp = head;
        while(temp != NULL) {
            std::cout << temp -> data << " ";
            temp = temp -> next;
        }
        std::cout << std::endl;
    }

};

int main() {

    LinkedList<int> list;

    int input, data, index;
    bool exit = false;

    while(!exit) {

        std::cout << "Menu:\n\t1. Insert\n\t2. Remove\n\t3. Get\n\t4. Print\n\t5. Exit\nChoice: ";
        std::cin >> input;
        std::cout << std::endl;

        switch(input) {
            case 1:
                std::cout << "Enter data: ";
                std::cin >> data;
                std::cout << "Enter index(-1 to insert at the end): ";
                std::cin >> index;
                try {
                    list.insert(data, index);
                } catch (const char* error) {
                    std::cout << error << std::endl;
                }
                break;

            case 2:
                std::cout << "Enter index: ";
                std::cin >> index;
                try {
                    list.remove(index);
                } catch (const char* error) {
                    std::cout << error << std::endl;
                }
                break;

            case 3:
                std::cout << "Enter index: ";
                std::cin >> index;
                try {
                    std::cout << list.get(index) << std::endl;
                } catch (const char* error) {
                    std::cout << error << std::endl;
                }
                break;

            case 4:
                list.print();
                break;

            case 5:
                exit = true;
                break;

            default:
                std::cout << "\nInvalid option" << std::endl;
                break;
        }
        std::cout << std::endl;
    }

}
