#include <iostream>
#include <set>
#include <queue>
#include <stack>

using namespace std;

class Graph {
private:
	void DFSRecursive(int v, bool* visited, void(*callback)(int));
	void printDFSRecursive(int v, bool* visited);
	int vNum;
	set<int> *adjacencyList;
public:
	~Graph();
	Graph(int vNum);
	void insertEdge(int nodeA, int nodeB);
	void printAdjacencyList();
	void printDFS(int startVertex);
	void DFS(int startVertex, void(*callback)(int));
	void BFS(int startVertex);
	bool isCyclic();
	bool isCyclicUntil(int v, bool* visitedArr, bool* parentNodes);
};

Graph::Graph(int vNum)
{
	this->vNum = vNum;
	adjacencyList = new set<int>[vNum];
}

Graph::~Graph()
{
	delete[] adjacencyList;
}

void Graph::insertEdge(int nodeA, int nodeB)
{
	adjacencyList[nodeA].insert(nodeB);
}

void Graph::DFS(int startVertex, void (*callback)(int))
{
	bool* visitedArr = new bool[vNum] { false };

	DFSRecursive(startVertex, visitedArr, callback);
	cout << endl;

	delete[] visitedArr;
}

void Graph::DFSRecursive(int v, bool* visited, void (*callback)(int))
{
	if (visited[v]) { return; }
	
	visited[v] = true;
	callback(v);

	for (int n : adjacencyList[v]) {
		DFSRecursive(n, visited, callback);
	}
}

void Graph::printDFSRecursive(int v, bool* visited)
{
	if (visited[v]) { return; }

	visited[v] = true;
	cout << v << " ";

	for (int n : adjacencyList[v]) {
		printDFSRecursive(n, visited);
	}
}

void Graph::printDFS(int startVertex)
{
	bool* visitedArr = new bool[vNum] { false };

	printDFSRecursive(startVertex, visitedArr);
	cout << endl;

	delete[] visitedArr;
}

void Graph::printAdjacencyList()
{
	for (int i = 0; i < vNum; i++) {
		cout << i << ": ";
		for (int n : adjacencyList[i]) {
			cout << n << " ";
		}
		 cout << endl;
	}
}

void Graph::BFS(int startVertex)
{
	bool* visitedArr = new bool[vNum] {false};

	queue<int> q;
	q.push(startVertex);

	while (!q.empty()) {
		int n = q.front();
		q.pop();
	 if (!visitedArr[n]) {
			visitedArr[n] = true;
			cout << n << " ";
			for (int ed : adjacencyList[n]) {
				q.push(ed);
			}
		}
	}

	cout << endl;

	delete[] visitedArr;
}

bool Graph::isCyclicUntil(int n, bool* visited, bool* recursiveStack)
{
	if(!visited[n]){
		
		visited[n] = true;
		recursiveStack[n] = true;
			
		for (int nv : adjacencyList[n]) {
			if (!visited[nv] && isCyclicUntil(nv, visited, recursiveStack)) {
				return true;
			} else if (recursiveStack[nv]) {
				return true;
			}
		}

	}

	recursiveStack[n] = false;
	return false;
}

bool Graph::isCyclic()
{
	bool* visitedArr = new bool[vNum] {false};
	bool* recursiveStack = new bool[vNum] {false};

	bool result = false;

	for (int i = 0; i < vNum; i++) {
		if (isCyclicUntil(i, visitedArr, recursiveStack)) {
			result = true;
			break;
		}
	}

	delete[] visitedArr;
	delete[] recursiveStack;
	return result;
}

int main()
{
	
	Graph g(4);
	g.insertEdge(0, 1);
	g.insertEdge(0, 2);
	g.insertEdge(1, 2);
	g.insertEdge(2, 0);
	g.insertEdge(2, 3);
	g.insertEdge(3, 3);
	
	g.printAdjacencyList();
	cout << endl;
	g.BFS(0);
	g.printDFS(0);
	cout << endl;
	cout << g.isCyclic();
	

	cin.get();
	return 0;
}