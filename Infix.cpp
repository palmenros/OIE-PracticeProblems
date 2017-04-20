#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

bool isOperator(const string& tmp)
{
	return tmp.size() == 1 && isOperator(tmp[0]);
}

vector<string> parseTokens(const string& exp)
{
	vector<string> res;
	string tmp = "";
	for (char c : exp) {
		if (isOperator(c)) {
			if (tmp != "") {
				res.push_back(tmp);
				tmp.clear();
			}
			res.push_back(string(1, c));
		} else if (c == ' ') {
			if (tmp != "") {
				res.push_back(tmp);
				tmp.clear();
			}
		} else {
			tmp.push_back(c);
		}
	}
	if (tmp != "") {
		res.push_back(tmp);
	}
	return res;
}

bool hasOperatorMorePrecedence(char op1, char op2)
{
	return (op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/');
}

vector<string> infixToPostfix(const string& exp)
{
	vector<string> returnTokens;
	vector<string> tokens = parseTokens(exp);

	stack<char> s;
	bool lastTokenOperand = false;
	for (const string& t : tokens) {
		if (isOperator(t)) {
			char op = t[0];
			if (op == '(') {
				if (lastTokenOperand) {
					s.push('*');
				}
				s.push(op);
			} else if (op == ')') {
				while (!s.empty() && s.top() != '(') {
					returnTokens.push_back(string(1, s.top()));
					s.pop();
				}
				if (s.empty()) {
					throw exception("SYNTAX ERROR");
				}
				s.pop();
				//Pop '('
			} else {
				//Operator is a math operator + - * /
				while (!s.empty() && !hasOperatorMorePrecedence(s.top(), op) && s.top() != '(') {
					returnTokens.push_back(string(1, s.top()));
					s.pop();
				}
				s.push(op);
			}
			lastTokenOperand = false;
		} else {
			//Operand
			lastTokenOperand = true;
			returnTokens.push_back(t);
		}
	}

	while (!s.empty()) {
		returnTokens.push_back(string(1, s.top()));
		s.pop();
	}

	return returnTokens;
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

int parsePostfix(const vector<string>& tokens)
{
	stack<int> operations;

	for (const string& token : tokens) {
		if (token[0] == '(') { throw exception("SYNTAX ERROR: Unbalanced parenthesis"); }
		if (isOperator(token)) {
			if (operations.size() < 2) {
				throw exception((string("SYNTAX ERROR: No operands for operator ") +token).c_str());
			}
			int sop = operations.top();
			operations.pop();
			int fop = operations.top();
			operations.pop();
			operations.push(calculateOperation(fop, sop, token[0]));
		} else {
			try {
				size_t loc;
				operations.push(stoi(token, &loc));
				if(loc != token.size()){
					throw exception((string("SYNTAX ERROR: Invalid argument ") + token).c_str());
				}
			} catch (invalid_argument& e) {
				throw exception((string("SYNTAX ERROR: Invalid argument ") + token).c_str());
			}
		}
	}

	if (operations.size() != 1) {
		throw exception("SYNTAX ERROR");
	}

	return operations.top();

}

int main()
{
	string tmp;
	while (getline(cin, tmp)) {
		try {
			double val = parsePostfix(infixToPostfix(tmp));
			cout << val << endl << endl;
		} catch (exception& e) {
			cout << e.what() << endl << endl;
		}
	}
}