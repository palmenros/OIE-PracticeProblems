#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <functional>

using namespace std;

class Graph {
private:
	int vNum;
	//Node, weight
	vector<pair<int, int> >* adjacencyList;
public:
	~Graph();
	Graph(int vNum);
	void addEdge(int v1, int v2, int weight);
	int Dijkstra();
};

Graph::Graph(int vNum)
{
	this->vNum = vNum;
	adjacencyList = new vector<pair<int, int> > [vNum];
}

Graph::~Graph()
{
	delete[] adjacencyList;
}

void Graph::addEdge(int v1, int v2, int weight)
{
	adjacencyList[v1].push_back(make_pair(v2, weight));
}

void visita(int vertex, int distance, vector<int>& distances, priority_queue < pair<int, int>, vector < pair<int, int> >, greater<pair<int, int> > >& pq)
{
	if (distances[vertex] < distance && distances[vertex] != -1) { return; }
	distances[vertex] = distance;
	pq.push(make_pair(distance, vertex));
}

int myMax(int a, int b) { return a > b ? a : b; }

int Graph::Dijkstra()
{
	//Find smallest path from 0 to vNum - 1
	vector<int> dist(vNum, -1);
	priority_queue < pair<int, int>, vector < pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0, 0));
	dist[0] = 0;

	while (!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		int d = p.first;
		int v = p.second;
		for (pair<int, int> p2 : adjacencyList[v]) {
			int vertex = p2.first;
			int distance = myMax(dist[v], p2.second);

			visita(vertex, distance, dist, pq);
		}
	}
	
	return dist[vNum - 1];

}

int main()
{
	int n;
	while (cin >> n) {
		Graph g(n);
		cin.ignore();
		for (int i = 0; i < n - 1; i++) {
			string tmp;
			getline(cin, tmp);
			//parse string
			stringstream ss(tmp);
			int crap;
			char litter;
			ss >> crap >> litter;
			int time;
			ss >> time;
			int friendNumber;
			while (ss >> friendNumber) {
				g.addEdge(i, friendNumber - 1, time);
			}
		}

		//Grafo construido
		cout << g.Dijkstra() << endl;
	}
	return 0;
}