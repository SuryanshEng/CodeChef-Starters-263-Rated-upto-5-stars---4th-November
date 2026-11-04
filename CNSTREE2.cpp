#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T, n; cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n), p(n, -1), m(n, 3), s(n), l(n), f(n), d(n), r(n), o{0}, q;
        vector<vector<int>> g(n), e(n);
        for (int &x : a) cin >> x;
        for (int i = 1, u, v; i < n; i++) cin >> u >> v, g[--u].push_back(--v), g[v].push_back(u);
        for (int i = 0; i < n; i++) for (int c : g[o[i]]) if (c != p[o[i]]) p[c] = o[i], o.push_back(c);
        bool ok = 1;
        for (int i = n - 1; i >= 0 && ok; i--) {
            int v = o[i], P = p[v], k = !a[v] * (!s[v] + !l[v]);
            if (v) m[v] = (a[v] <= 0 && a[P] >= 0) | (a[v] >= 0 && a[P] <= 0) * 2;
            if (k > f[v]) { if (!v || k - f[v] > 1) ok = 0; else if (!f[v]) m[v] &= s[v] ? 1 : 2; }
            if (v) { if (!m[v]) ok = 0; (m[v] == 1 ? s : m[v] == 2 ? l : f)[P]++; }
        }
        if (!ok) { cout << "-1\n"; continue; }
        for (int v : o) {
            int x = s[v], y = l[v], u = p[v];
            if (v) m[v] == 1 ? y = 1 : x = 1;
            for (int c : g[v]) if (c != u && m[c] == 3) m[c] = !x ? (x = 1) : !y ? (y = 1, 2) : 1;
            if (v) m[v] == 1 ? (e[v].push_back(u), d[u]++) : (e[u].push_back(v), d[v]++);
        }
        for (int i = 0; i < n; i++) if (!d[i]) q.push_back(i);
        for (int i = 0; i < n; i++) {
            r[q[i]] = i + 1;
            for (int w : e[q[i]]) if (!--d[w]) q.push_back(w);
        }
        for (int x : r) cout << x << ' ';
        cout << '\n';
    }
}