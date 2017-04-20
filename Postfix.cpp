#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isOperator(const string& str)
{
	if (str.size() != 1) {
		return false;
	}
	return isOperator(str[0]);
}

vector<string> parseTokens(const string& exp)
{
	vector<string> result;

	string tmp = "";
	for (char c : exp) {
		if (isOperator(c)) {
			if (tmp != "") {
				result.push_back(tmp);
				tmp.clear();
			}			
			result.push_back(string(1, c));
		} else if(c == ' ') {
			if (tmp != "") {
				result.push_back(tmp);
				tmp.clear();
			}
		} else {
			tmp.push_back(c);
		}
	}

	if (tmp != "") {
		result.push_back(tmp);
	}

	return result;
}

int calculateOperation(int f, int s, char op)
{
	switch (op) {
	case '+':
		return f + s;
	case '-':
		return f - s;
	case '*':
		return f * s;
	case '/':
		return f / s;
	}
}

int parseExpression(const string& exp)
{
	vector<string> tokens = parseTokens(exp);
	
	stack<int> operations;

	for (const string& token : tokens) {
		if (isOperator(token)) {
			if (operations.size() < 2) {
				cout << "Syntax error" << endl;
				return INT_MAX;
			}
			int sop = operations.top();
			operations.pop();
			int fop = operations.top();
			operations.pop();
			operations.push(calculateOperation(fop, sop, token[0]));
		} else {
			try {
				operations.push(stoi(token));
			} catch (invalid_argument& e) {
				cout << "Syntax error" << endl;
				return INT_MAX;
			}
		}
	}

	if (operations.size() != 1) {
		cout << "Syntax error" << endl;
		return INT_MAX;
	}

	return operations.top();

}

int main()
{
	string tmp;

	while (getline(cin, tmp)) {
		int val = parseExpression(tmp);
		if(val != INT_MAX){
			cout << val << endl;
		}
	}

	return 0;
}