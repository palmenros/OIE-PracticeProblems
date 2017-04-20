#include <iostream>
#include <queue>
#include <functional>
#include <stack>

using namespace std;
struct Node;

stack<Node*> toDelete;

struct Node {
	Node* left;
	Node* right;
	char letter;
	int value;
	Node(Node* left, Node* right, int value) : left(left), right(right), value(value), letter('\0') { toDelete.push(this); }
	Node(char letter, int value) : letter(letter), value(value), left(nullptr), right(nullptr) { toDelete.push(this); }
};


struct compare {
	bool operator()(Node* a, Node* b)
	{
		return a->value > b->value;
	}
};

void deleteNodes()
{
	while (!toDelete.empty()) {
		Node* n = toDelete.top();
		toDelete.pop();
		delete n;
	}
}

void printCodes(Node* root, vector<int>& digits)
{
	if (root->left) {
		digits.push_back(0);
		printCodes(root->left, digits);
	}

	if (root->right) {
		digits.push_back(1);
		printCodes(root->right, digits);
	}
	
	//If leaf node, print
	
	if (!root->left && !root->right) {
		cout << root->letter << ": ";
		for (int i : digits) {
			cout << i;
		}
		cout << endl;
	}
	if (!digits.empty()) {
		digits.pop_back();
	}
}

int main()
{
	int n;
	while (cin >> n) {
		priority_queue < Node*, vector<Node*>, compare> q;
		for (int i = 0; i < n; i++) {
			char letter;
			int frequency;
			cin >> letter >> frequency;
			q.push(new Node(letter, frequency));
		}

		//Construct huffman tree

		while (q.size() != 1) {
			Node* a = q.top();
			q.pop();
			Node* b = q.top();
			q.pop();
			q.push(new Node(a, b, a->value + b->value));
		}

		Node* root = q.top();

		//Print values
		cout << endl;
		
		vector<int> digits;
		printCodes(root, digits);

		//Delete values
		deleteNodes();

		cout << endl;
	}
}