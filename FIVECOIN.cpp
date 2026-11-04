#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	cout << (N >= 5 ? 1 + N - 5 : N) << endl;
	return 0;
}
