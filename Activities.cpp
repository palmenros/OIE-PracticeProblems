#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while (cin >> n) {
		
		vector<int> start, finish;
		int tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			start.push_back(tmp);
		}
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			finish.push_back(tmp);
		}

		sort(finish.begin(), finish.end);

		int count = 1;
		int next_start = finish[0];
		for (int i = 1; i < finish.size(); i++) {
			if (start[i] >= next_start) {
				count++;
				next_start = finish[i];
			}
		}

		cout << count << endl;


	}

	return 0;
}