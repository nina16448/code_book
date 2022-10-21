#include <iostream>
#include <vector>
using namespace std;
typedef long long lint;
#define ID first
#define weight second
int u, v, w, diameter, point;
int visited[10010];
vector <pair <int, int> > graph[10010];

void init(){
    for(int i = 0; i < 10010; i++) visited[i] = 0;
    diameter = 0;
}

void DFS(int level, int stp){
    visited[level] = 1;
    
    for(int i = 0; i < graph[level].size(); i++){
        pair <int, int> x = graph[level][i];
        if(visited[x.ID]) continue;

        DFS(x.ID, stp + x.weight);
    }

    if(stp > diameter){
        point = level;
        diameter = stp;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> u >> v >> w){
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    init();
    DFS(1, 0);

    init();
    DFS(point, 0);

    cout << diameter << "\n";
    return 0;
}