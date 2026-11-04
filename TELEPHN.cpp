#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while(T--) {
	    int N; cin >> N;
	    vector<int> A(N), D(2 * N, -1), Q;
	    for(int &X : A) cin >> X;
	    int M = *max_element(A.begin(),A.end());
	    for(int i = 0; i < N; i++) if(A[i] == M) D[2 * i] = 0, Q.push_back(2 * i);
	    for(int H = 0; H < (int)Q.size(); H++) {
	        int U = Q[H], i = U / 2, P = U & 1;
	        for(int j : {(i+1)%N,(i+N-1)%N}) {
	            int V = 2 * j + !P;
	            if (D[V] < 0) D[V] = D[U] + 1, Q.push_back(V);
	        }
	    }
	    int R = INT_MAX;
	    for(int P = 0; P < 2; P++) {
	        int M = 0;
	        for(int i = 0; i < N; i++) M = max(M, D[2 * i + P] < 0 ? INT_MAX : D[2 * i + P]);
	        R = min(R,M);
	    }
	    cout << (R == INT_MAX ? -1 : R) << "\n";
	}

}
