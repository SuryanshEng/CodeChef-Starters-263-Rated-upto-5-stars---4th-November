#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while(T--){
	    ll X,Y,D; cin >> X >> Y >> D;
	    ll G = __gcd(X,Y), B = LLONG_MAX;
	    for(ll A = 1; A <= Y/G; A++) {
	        ll V = A * X, R = V % Y;
	        if(R <= D && V >= Y) B = min(B,V);
	        if(Y - R <= D) B = min(B, V - R + Y);
	    }
	    cout << B << "\n";
	}
}
