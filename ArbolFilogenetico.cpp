#include <iostream>
#include <map>

using namespace std;

struct Node{
	int a, b;
	map<int, int> genes;
	Node* left;
	Node* right;
	Node(int a, int b) : a(a), b(b), left(nullptr), right(nullptr){}
	Node(int gene) : a(0), b(0), left(nullptr), right(nullptr) { genes[gene] = 1; }
};

Node* searchForSpecie(Node* root, int specie, int& pos)
{
	if (!root) { return nullptr; }
	if (root->a == specie) {
		pos = 0;
		return root;
	} else if(root->b == specie){
		pos = 1;
		return root;
	}

	Node* a = searchForSpecie(root->left, specie, pos);
	Node* b = searchForSpecie(root->right, specie, pos);
	if (a) {
		return a;
	} else if (b) {
		return b;
	}
}

void insertExtint(Node** root, int n, int a, int b)
{
	Node* node = new Node(a, b);
	if (!*root) {
		*root = node;
	} else {
		//Search for n
		int pos;
		Node* where = searchForSpecie(*root, n, pos);
		if (pos == 0) {
			where->left = node;
		} else {
			where->right = node;
		}
	}
}

void insertAlive(Node** root, int n, int gene)
{
	Node* node = new Node(gene);
	if (!*root) {
		*root = node;
	} else {
		int pos;
		Node* where = searchForSpecie(*root, n, pos);
		if (pos == 0) {
			where->left = node;
		} else {
			where->right = node;
		}
	}
}

int sol2()
{
	int n, g;
	while (cin >> n >> g) {
		//Especie - gene
		map<int, Node*> genes;
		Node* tree = nullptr;

		for (int i = 1; i <= n; i++) {
			//Leer especie
			char c;
			cin >> c;
			if (c == 'V') {
				//Viva
				int gene;
				cin >> gene;
				insertAlive(&tree, i, gene);
			} else {
				//Extint
				int a, b;
				cin >> a >> b;
				insertExtint(&tree, i, a, b);
			}
		}
		cin.get();
	}
}

#include <map>
int main()
{
	int n, g;
	while (cin >> n >> g) {
		//Especie - gene
		map<int, int> genes;
		 

		for (int i = 1; i <= n; i++) {
			//Leer especie
			char c;
			cin >> c;
			if (c == 'V') {
				//Viva
				int gene;
				cin >> gene;
				//if (find(genes.begin(), genes.end()), i);

			} else {
				//Extint
				int a, b;
				cin >> a >> b;

			}
		}
		cin.get();
	}

	return 0;
}