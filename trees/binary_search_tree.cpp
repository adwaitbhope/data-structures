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

class BinaryTree {
	Node *root;

	Node* insert(Node* current, int data) {
		if (current == NULL)
			current = new Node (data);
		else if (data < current -> data)
			current -> left = insert (current -> left, data);
		else
			current -> right = insert (current -> right, data);
		return current;
	}

	void inorder(Node *current) {
		if (current == NULL) return;
		inorder (current -> left);
		std::cout << current -> data << std::endl;
		inorder (current -> right);
	}

	int height(Node *current) {
		if (current == NULL)
			return 0;
		else
			return std::max(height(current->left), height(current->right)) +1;
	}

	void invertTree(Node *current) {
		if (current == NULL) return;
		std::swap(current -> left, current -> right);
		invertTree(current -> left);
		invertTree(current -> right);
	}

public:
	BinaryTree () {
		root = new Node();
	}

	void insert(int data) {
		if (root -> data == 0)
			root -> data = data;
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

	void inorder() {
		inorder(root);
	}

	int height() {
		return height(root);
	}

	void invertTree() {
		invertTree(root);
	}

	int min() {
		Node *current = root;
		while (current -> left != NULL)
			current = current -> left;
		return current -> data;
	}

};

int main () {

	BinaryTree bt;
    int input, data;
    bool exit = false;

    while(!exit) {

        std::cout << "Menu:\n\t1. Insert\n\t2. Print inorder traversal\n\t3. Search\n\t4. Check height\n\t5. Invert tree\n\t6. Exit\nChoice: ";
        std::cin >> input;
        std::cout << std::endl;

        switch(input) {
            case 1:
                std::cout << "Enter data: ";
                std::cin >> data;
            	bt.insert(data);
                break;

            case 2:
                bt.inorder();
                break;

            case 3:
                std::cout << "Enter data: ";
                std::cin >> data;
                bt.search(data) ? std::cout << "Present\n" : std::cout << "Absent\n";
                break;

            case 4:
                std::cout << "Height of tree is " << bt.height() << ".";
                break;

            case 5:
                bt.invertTree();
                break;

            case 6:
                exit = true;
                break;

            default:
                std::cout << "\nInvalid option" << std::endl;
                break;
        }
        std::cout << std::endl;
    }

}
