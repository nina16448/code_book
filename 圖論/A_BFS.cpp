#include <bits/stdc++.h>
using namespace std;
int n, m, u, v, s, t;
int stp[30000];
queue <int> qu;
vector <int> mapp[30000];

void BFS(int level){
    qu.push(level);
    stp[level] = 1;
    
    while(!qu.empty()){
        level = qu.front();
        for(auto x: mapp[level]){
            if(stp[x] != 0) continue;

            qu.push(x);
            stp[x] = stp[level] + 1;
        }
        qu.pop();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        mapp[u].push_back(v);
        mapp[v].push_back(u);
    }

    cin >> s >> t;
    
    BFS(s);
    
    cout << stp[t] - 1 << "\n";
    return 0;
}