#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while(T--){
	    int N; string S; cin >> N >> S;
	    int R = INT_MAX;
	    for(int K = 0; K <= N; K++) {
	        if ((S[N-1] == '1') == (K == N)) continue;
	        if(K && S[K-1] == '1') continue;
	        int C = 0;
	        for(int i = 0; i < N; i++) C += (i < K) == (S[i] == '1');
	        R = min(R,C);
	    }
	    cout << R << "\n";
	}
}
