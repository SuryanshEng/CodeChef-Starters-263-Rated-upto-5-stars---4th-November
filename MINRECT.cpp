#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T,N,M;
	cin >> T;
	while(T--) {
	    cin >> N >> M;
	    int R1 = N, R2 = -1, C1 = M, C2 = -1;
	    for(int i = 0; i < N; i++) {
	        string S;
	        cin >> S;
	        for(int j = 0; j < M; j++)
	           if (S[j] == '1') {
	               R1 = min(R1,i); R2 = max(R2,i);
	               C1 = min(C1,j); C2 = max(C2,j);
	           }
	    }
	    cout << (R2 - R1 + 1) * (C2 - C1 + 1) << "\n";
	}

}
