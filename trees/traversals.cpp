#include<iostream>
#include<stack>

struct Node {
	char data;
	Node *left, *right;
	Node (char d = '\0') {
		left = NULL;
		right = NULL;
		data = d;
	}
};

class BinaryTree {
	Node *root;

	void inorder_recursive (Node *current) {
		if (current == NULL)
			return;
		inorder_recursive(current -> left);
		std::cout << current -> data;
		inorder_recursive(current -> right);
	}

	void postorder_recursive (Node *current) {
		if (current == NULL)
			return;
		postorder_recursive(current -> left);
		postorder_recursive(current -> right);
		std::cout << current -> data;
	}

	void preorder_recursive (Node *current) {
		if (current == NULL)
			return;
		std::cout << current -> data;
		preorder_recursive(current -> left);
		preorder_recursive(current -> right);
	}

public:
	BinaryTree () {
		root = new Node();
	}

	void inorder_recursive () {
		std::cout << "\tInfix: ";
		inorder_recursive(root);
		std::cout << std::endl;
	}

	void postorder_recursive () {
		std::cout << "\tPostfix: ";
		postorder_recursive(root);
		std::cout << std::endl;
	}

	void preorder_recursive () {
		std::cout << "\tPrefix: ";
		preorder_recursive(root);
		std::cout << std::endl;
	}

	void inorder () {
		std::cout << "\tInfix: ";
		std::stack<Node*> data;
		Node *current = root;
		do {
			while (current != NULL) {
				data.push(current);
				current = current -> left;
			}
			if (current == NULL && !data.empty()) {
				std::cout << data.top() -> data;
				current = data.top() -> right;
				data.pop();
			}
			if (current == NULL && data.empty())
				break;
		} while (true);
		std::cout << std::endl;
	}

	void postorder() {
  		std::cout << "\tPostfix: ";

        Node* current = root;
        std::stack<Node*> s1;
        std::stack<Node*> s2;

        if (current == NULL)
            return;

        s1.push(current);

        while (!s1.empty()) {
            Node* temp = s1.top();
            s1.pop();
            s2.push(temp);

            if (temp -> left != NULL)
                s1.push(temp -> left);
            if (temp -> right != NULL)
                s1.push(temp -> right);
        }

        while (!s2.empty()) {
            Node* temp = s2.top();
            s2.pop();
            std::cout << temp -> data;
        }
        std::cout << std::endl;
    }

    void preorder() {
   		std::cout << "\tPrefix: ";

        Node* current = root;
        if (current == NULL) {
            return;
        }

        std::stack<Node*> data;
        data.push(current);

        while (! data.empty()) {

            Node* temp = data.top();
            std::cout << temp -> data;
            data.pop();

            if (temp -> right != NULL)
                data.push(temp -> right);
            if (temp -> left != NULL)
                data.push(temp -> left);
        }
        std::cout << std::endl;
    }

	void insert (char data) {
		Node *temp;
		if (root -> data =='\0') {
			root -> data = data;
			return;
		}
		temp = insert (data, root->right);
		if (temp != NULL)
			root -> right = temp;
		else
			root -> left = insert (data, root-> left);
	}

	Node* insert (char data, Node *node) {
		if (node == NULL)
			return new Node(data);
		switch (node -> data) {
			case '+':
			case '-':
			case '/':
			case '*':
				break;
			default:
				return NULL;
		}

		Node *temp = insert (data, node->right);
		if (temp != NULL) {
			node -> right = temp;
		}
		else {
			temp = insert (data, node->left);
			if (temp != NULL) {
				node -> left = temp;
			}
			else {
				return NULL;
			}
		}
		return node;
	}

	void print () {
		std::cout << root->data << std::endl;
	}

};

bool preceeds (char a, char b) {
	if (a == '+' || a == '-')
		return false;
	else
		if (b == '*' || b == '/')
			return false;
		else
			return true;
}

int main () {
	std::stack<char> postfix;
	std::stack<char> operators;

	std::string infix;
	std::cout << "Enter infix expression: ";
	std::cin >> infix;

	for(int i = 0; i < infix.length(); i++) {
		switch(infix[i]) {
			case '+':
			case '-':
			case '/':
			case '*':
				if (!operators.empty()) {
					if (! preceeds(infix[i], operators.top())) {
						while (!operators.empty()) {
							postfix.push(operators.top());
							operators.pop();
						}
					}
				}
				operators.push(infix[i]);
				break;
			default:
				postfix.push(infix[i]);
		}

	}

	while (!operators.empty()) {
		postfix.push(operators.top());
		operators.pop();
	}

	BinaryTree bt;
	while (!postfix.empty()) {
		bt.insert(postfix.top());
		postfix.pop();
	}

	std::cout << "\nRecursive:" << std::endl;
	bt.inorder_recursive();
	bt.postorder_recursive();
	bt.preorder_recursive();

	std::cout << "\nNon recursive:" << std::endl;
	bt.inorder();
	bt.postorder();
	bt.preorder();

}
