#include <bits/stdc++.h>

using namespace std;

int solve(){
    int m, c; cin >> m >> c;
    vector<vector<int>> price(c);
    for (int i = 0; i < c; ++i){
        int k; cin >> k;
        price[i].resize(k);
        for (int j = 0; j < k; ++j){
            cin >> price[i][j];
        }
    }
    vector<vector<int>> reachable(c, vector<int>(m + 1));
    for (auto p : price[0]){
        if(p <= m) reachable[0][m - p] = true;
    }
    for (int g = 1; g < c; ++g){
        for (int money = 0; money <= m; ++money){
            if (reachable[g - 1][money]){
                for (auto p : price[g]){
                    if (p <= money) reachable[g][money - p] = true;
                }
            }
        }
    }
    for (int money = 0; money < m; ++money){
        if (reachable[c - 1][money]) return m - money;
    }
    return -1;
}

int main(){
    int t; cin >> t;
    while (t--) {
        int ans = solve();
        if (ans == -1) cout << "no solution\n";
        else cout << ans << "\n";
    }
}
