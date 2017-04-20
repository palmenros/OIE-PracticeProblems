#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void visit(const vector<vector<char> >& v, int x, int y, int d, vector<vector<int> >& distances, queue<pair<int, int> >& q, int tx, int ty)
{
	if (x >= tx || x < 0) { return; }
	if (y >= ty || y < 0) { return; }

	if (distances[y][x] != -1) { return; }
	if (v[y][x] == '#') { return; }

	//valid point
	distances[y][x] = d;

	//visit neighbours
	q.push(make_pair(x, y));

}

int BFS(const vector<vector<char> >& v, int tx, int ty, int cx, int cy, const vector<pair<int, int> >& targets)
{
	vector<vector<int> > distance(ty, vector<int>(tx, -1));
	queue<pair<int, int> > q;
	q.push(make_pair(cx, cy));
	distance[cy][cx] = 0;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		int x = p.first, y = p.second;
		int d = distance[y][x];

		visit(v, x + 2, y + 1, d + 1, distance, q, tx, ty);
		visit(v, x + 2, y - 1, d + 1, distance, q, tx, ty);

		visit(v, x - 2, y + 1, d + 1, distance, q, tx, ty);
		visit(v, x - 2, y - 1, d + 1, distance, q, tx, ty);

		visit(v, x + 1, y + 2, d + 1, distance, q, tx, ty);
		visit(v, x - 1, y + 2, d + 1, distance, q, tx, ty);

		visit(v, x + 1, y - 2, d + 1, distance, q, tx, ty);
		visit(v, x - 1, y - 2, d + 1, distance, q, tx, ty);
	}

	int minTarget = INT_MAX;
	for (pair<int, int> p : targets) {
		int nd = distance[p.second][p.first];
		if (nd != -1 && nd < minTarget) {
			minTarget = nd;
		}
	}
	
	if (minTarget == INT_MAX) {
		return -1;
	} else {
		return minTarget;
	}

}

int main()
{
	int n, m;
	while (cin >> n >> m) {

		vector<vector<char> > matrix;
		vector<pair<int, int> > targets;

		int cx, cy;

		for (int i = 0; i < n; i++) {
			vector<char> tmp;
			for (int j = 0; j < m; j++) {
				char c;
				cin >> c;
				if (c == 'C') {
					cx = j;
					cy = i;
				} else if (c == 'X') {
					targets.push_back(make_pair(j, i));
				}

				tmp.push_back(c);
			}
			matrix.push_back(tmp);
		}

		cout << BFS(matrix, m, n, cx, cy, targets) << endl;

	}

	return 0;
}