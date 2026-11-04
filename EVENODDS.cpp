#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while(T--) {
	    int N,C = 0,F = 0,L = 0; cin >> N;
	    for(int i = 1,X; i <= N; i++) {
	        cin >> X;
	        if(X&1){
	            C++;if(!F)F = i;L = i;
	        }
	    }
	    cout << (C%2==0?N:max(N-F,L-1)) << '\n';
	}
}
