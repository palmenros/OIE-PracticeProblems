#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
#include <string>

using namespace std;

struct BSTNode {
	int data;
	BSTNode* left;
	BSTNode* right;
	BSTNode* parent;
	BSTNode(int d, BSTNode* parent) : data(d), left(nullptr), right(nullptr), parent(parent){}
};

void insertBST(BSTNode** head, int data)
{
	BSTNode* parent = nullptr;
	while (*head) {		
		parent = *head;
		if (data > (*head)->data) {
			head = &((*head)->right);
		} else {
			head = &((*head)->left);
		}
	}
	*head = new BSTNode(data, parent);
}

bool findBST(BSTNode* head, int value)
{
	while (head) {
		if (head->data == value) {
			return true;
		} else if (value > head->data) {
			head = head->right;
		} else {
			head = head->left;
		}
	}
	return false;
}

void printInOrderBST(BSTNode* head, bool printNewLine = true)
{
	if (head) {
		printInOrderBST(head->left, false);
		cout << head->data << " ";
		printInOrderBST(head->right, false);
	}
	if (printNewLine) { cout << endl; }
}

void printPreorderBST(BSTNode* head, bool printNewLine = true)
{
	if (head) {
		cout << head->data << " ";
		printPreorderBST(head->left, false);
		printPreorderBST(head->right, false);
	}
	if (printNewLine) { cout << endl; }
}

void printPostorderBST(BSTNode* head, bool printNewLine = true)
{
	if (head) {
		printPostorderBST(head->left, false);
		printPostorderBST(head->right, false);
		cout << head->data << " ";
	}
	if (printNewLine) { cout << endl; }
}

int getBSTMin(BSTNode* head)
{
	if (!head) { return -1; }
	while (head->left) {
		head = head->left;
	}
	return head->data;
}

BSTNode* getBSTMinNode(BSTNode* head)
{
	if (!head) { return nullptr; }
	while (head->left) {
		head = head->left;
	}
	return head;
}

BSTNode* getBSTMaxNode(BSTNode* head)
{
	if (!head) { return nullptr; }
	while (head->right) {
		head = head->right;
	}
	return head;
}


int getBSTMax(BSTNode* head)
{
	if (!head) { return -1; }
	while (head->right) {
		head = head->right;
	}
	return head->data;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int getBSTHeight(BSTNode* head)
{
	if (!head) {
		return -1;
	}
	return max(getBSTHeight(head->right), getBSTHeight(head->left)) + 1;
}

void levelOrderTraverseBST(BSTNode* head)
{
	if (!head) { return; }
	queue<BSTNode*> nodesToVisit;
	nodesToVisit.push(head);
	while (!nodesToVisit.empty()) {
		BSTNode* node = nodesToVisit.front();
		nodesToVisit.pop();
		cout << node->data << " ";
		if (node->left) { nodesToVisit.push(node->left); }
		if (node->right) { nodesToVisit.push(node->right); }
	}
	cout << endl;
}

void printBST(BSTNode* node, string indent = "", bool is_tail = false)
{
	cout << indent << (is_tail ? "|-- " : "|-- ");
	if (node == nullptr) {
		cout << "*" << endl;
		return;
	}
	cout << node->data << endl;
	if (node->left != nullptr || node->right != nullptr) {
		indent.append(is_tail ? "    " : "|   ");
		printBST(node->right, indent, false);
		printBST(node->left, indent, true);
	}
}

void printPreorderBSTIterative(BSTNode* head)
{
	if (!head) { return; }
	stack<BSTNode*> s;
	s.push(head);
	while (!s.empty()) {		
		BSTNode* node = s.top();
		s.pop();
		if (node->right) { s.push(node->right); }
		if (node->left) { s.push(node->left); }
		cout << node->data << " ";
	}
	cout << endl;
}

void printInorderBSTIterative(BSTNode* head)
{	
	if (!head) { return; }
	bool done = false;
	BSTNode* current = head;
	stack<BSTNode*> s;

	while (!done) {
		if (current) {
			s.push(current);
			current = current->left;
		} else {
			if (s.empty()) {
				done = true;
			} else {
				current = s.top();
				s.pop();
				cout << current->data << " ";
				current = current->right;
			}
		}
	}
}

void deleteBST(BSTNode* head)
{
	if (!head) { return; }
	deleteBST(head->left);
	deleteBST(head->right);
	delete head;
}

bool isBSTUtil(BSTNode* head, int min, int max)
{
	//Returns true if is binary search tree
	if (!head) { return true; }
	return head->data > min && head->data < max && isBSTUtil(head->right, head->data, max) && isBSTUtil(head->left, min, head->data);
}

bool isBST(BSTNode* head)
{
	return isBSTUtil(head, INT_MIN, INT_MAX);
}

BSTNode* searchNodeBST(BSTNode* head, int data)
{
	while (head) {
		if (head->data == data) {
			return head;
		} else if (head->data > data) {
			head = head->left;
		} else {
			head = head->right;
		}
	}
	return nullptr;
}

void deleteBST(BSTNode* head, int data)
{
	BSTNode* parent = nullptr;
	BSTNode* current = head;
	while (current) {
		if (current->data == data) {
			break;
		} else if (current->data > data) {
			parent = current;
			current = current->left;
		} else {
			parent = current;
			current = current->right;
		}
	}
	
	if (!current) {
		//Didnt find node
		return;
	}
	BSTNode*& ptr = parent->right == current ? parent->right : parent->left;
	if (!current->right && !current->left) {		
		delete current;
		ptr = nullptr;
	} else if (!current->right) {
		ptr = current->left;
		delete current;
	} else if (!current->left) {
		ptr = current->right;
		delete current;
	} else {
		//Has 2 child
		BSTNode* rightMin = getBSTMinNode(current->right);
		current->data = rightMin->data;
		deleteBST(current->right, rightMin->data);
	}

}

BSTNode* getSuccessor(BSTNode* root, int data)
{
	if (!root) { return nullptr; }	
	BSTNode* current = root;
	BSTNode* ancestor = nullptr;

	while (current) {
		if (current->data == data) {
			break;
		} else if (current->data > data) {
			ancestor = current;
			current = current->left;
		} else {
			current = current->right;
		}
	}

	if (!current) { return nullptr; }
	if (current->right) {
		BSTNode* successor = current->right;
		while (successor->left) {
			successor = successor->left;
		}
	} else {
		return ancestor;
	}

}

BSTNode* getPredecesor(BSTNode* root, int data)
{
	if (!root) { return nullptr; }
	BSTNode* current = root;
	BSTNode* ancestor = nullptr;

	while (current) {
		if (current->data == data) {
			break;
		} else if (current->data > data) {
			current = current->left;
		} else {
			ancestor = current;
			current = current->right;
		}
	}

	if (!current) { return nullptr; }
	if (current->left) {
		BSTNode* successor = current->left;
		while (successor->right) {
			successor = successor->right;
		}
	} else {
		return ancestor;
	}
}


int main()
{
	BSTNode* head = nullptr;
	insertBST(&head, 10);
	insertBST(&head, 5);
	insertBST(&head, 15);
	insertBST(&head, 2);
	insertBST(&head, 7);
	insertBST(&head, 12);
	insertBST(&head, 20);
	insertBST(&head, 1);
	insertBST(&head, 3);
	insertBST(&head, 6);
	insertBST(&head, 11);
	insertBST(&head, 13);
	insertBST(&head, 16);
	insertBST(&head, 21);

	cout << "10: " << findBST(head, 10) << "; 9: " << findBST(head, 9) << "; 13: " << findBST(head, 13) << endl << endl;

	//printPreorderBST(head);
	//printPreorderBSTIterative(head);
	//printInOrderBST(head);
	printInorderBSTIterative(head);
	cout << endl;
	int tmp;
	while (cin >> tmp) {
		cout << getPredecesor(head, tmp)->data << "; " << getSuccessor(head, tmp)->data << endl;
	}

	//printPostorderBST(head);
	//levelOrderTraverseBST(head);

	//cout << endl;
	//printBST(head);
	//cout << endl;
	//cout << isBST(head) << endl;
	//cout << "Height: " << getBSTHeight(head) << endl;
	//cout << "Max: " << getBSTMax(head) << "; Min: " << getBSTMin(head) << endl;

	deleteBST(head);

	cin.get();
}