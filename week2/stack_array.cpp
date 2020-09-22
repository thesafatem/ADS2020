#include <iostream>
using namespace std;

const int BAD = -736598273;

struct Stack {
	int sz;
	int a[10000];

	Stack() {
		sz = 0;
	}

	int size() {
		return sz;
	}

	void push(int x) {
		a[sz] = x;
		sz++;
	}

	int back() {
		if (sz == 0) return BAD;
		return a[sz - 1];
	}

	int pop() {
		if (sz == 0) return BAD;
		else {
			sz--;
			return a[sz];
		}
	}

	void clear() {
		sz = 0;
	}

	bool empty() {
		return sz == 0;
	}
};

struct Queue {
	Stack left, right;

	Queue() {}

	void push(int x) {
		right.push(x);
	}

	void carry() {
		while (!right.empty()) {
			left.push(right.back());
			right.pop();
		}
	}

	int front() {
		if (left.empty()) carry();
		return left.back();
	} 

	int pop() {
		if (left.empty()) carry();
		return left.pop();
	}

	int size() {
		return left.sz + right.sz;
	}

	void clear() {
		left.clear();
		right.clear();
	}

	bool empty() {
		return left.empty() and right.empty();
	}
};

int main() {
	Queue q;
	string str;
	while (cin >> str) {
		if (str == "exit") {
			cout << "bye" << endl;
			break;
		} else if (str == "size") {
			cout << q.size() << endl;
		} else if (str == "clear") {
			q.clear();
			cout << "ok" << endl;
		} else if (str == "front") {
			int result = q.front();
			if (result == BAD) {
				cout << "error" << endl;
			} else {
				cout << result << endl;
			}
		} else if (str == "pop") {
			int result = q.pop();
			if (result == BAD) {
				cout << "error" << endl;
			} else {
				cout << result << endl;
			}
		} else {
			int x; cin >> x;
			q.push(x);
			cout << "ok" << endl;
		}
	}
}
