#include<iostream>

struct Node {
	int data;
	Node *left, *right;
	Node (int d = 0) {
		left = NULL;
		right = NULL;
		data = d;
	}
};

class AVLTree {
	Node *root;

	Node* insert(Node* current, int data) {
		if (current == NULL)
            return new Node(data);

        if (data < current -> data)
			current -> left = insert (current -> left, data);
		else
			current -> right = insert (current -> right, data);

        int balance = getBalance(current);
        if (balance > 1) {
            if (current -> left != NULL && data < current -> left -> data) {
                // left left case
                return rightRotate(current);
            }
            if (current -> left != NULL && data > current -> left -> data) {
                // left right case
                current -> left = leftRotate(current -> left);
                return rightRotate(current);
            }

        } else if (balance < -1) {
            if (current -> right != NULL && data > current -> right -> data) {
                // right right case
                return leftRotate(current);
            }
            if (current -> right != NULL && data < current -> right -> data) {
                // right left case
                current -> right = rightRotate(current -> right);
                return leftRotate(current);
            }
        }

		return current;
	}

	int height(Node* current) {
		if (current == NULL)
			return 0;
		else
			return std::max(height(current->left), height(current->right)) +1;
	}

    int getBalance(Node* node) {
        return height(node -> left) - height(node -> right);
    }

    Node* leftRotate(Node* node) {
        Node* right = node -> right;
        node -> right = right -> left;
        right -> left = node;
        return right;
    }

    Node* rightRotate(Node* node) {
        Node* left = node -> left;
        node -> left = left -> right;
        left -> right = node;
        return left;
    }

public:
	AVLTree () {
		root = new Node();
	}

	void insert(int data) {
		if (root == NULL)
			root = new Node(data);
		else if (data < root -> data)
			root -> left = insert(root -> left, data);
		else
			root -> right = insert(root -> right, data);
	}

	bool search(int data) {
		Node *current  = root;
		while (current != NULL) {
			if (current -> data == data)
				return true;
			if (data < current -> data)
				current = current -> left;
			else
				current = current -> right;
		}
		return false;
	}

    int height() {
		return height(root);
	}

};

int main () {
    AVLTree tree;
    int input, data;
    bool exit = false;

    while(!exit) {

        std::cout << "Menu:\n\t1. Insert\n\t2. Search\n\t3. Check height\n\t4. Exit\nChoice: ";
        std::cin >> input;
        std::cout << std::endl;

        switch(input) {
            case 1:
                std::cout << "Enter data: ";
                std::cin >> data;
            	tree.insert(data);
                break;

            case 2:
                std::cout << "Enter data: ";
                std::cin >> data;
                tree.search(data) ? std::cout << "Present\n" : std::cout << "Absent\n";
                break;

            case 3:
                std::cout << "Height of tree is " << tree.height() << ".";
                break;

            case 4:
                exit = true;
                break;

            default:
                std::cout << "\nInvalid option" << std::endl;
                break;
        }
        std::cout << std::endl;
    }

}
