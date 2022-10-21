#include <iostream>
#include <vector>
using namespace std;
typedef long long lint;
int n, m, num, stall, cnt;
vector <int> graph[210];
int visited[210];
int match[210];

int DFS(int x){
    for(vector<int>::iterator itr = graph[x].begin(); itr != graph[x].end(); itr++){
        int y = *itr;
        if(!visited[y]){ 
            visited[y] = 1;
            if(!match[y] || DFS(match[y])){
                match[y] = x;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> n >> m){
        for(int i = 0; i < 210; i++){
            graph[i].clear();
            match[i] = 0;
        }
        cnt = 0;

        for(int i = 1; i <= n; i++){
            cin >> num;
            for(int j = 0; j < num; j++){
                cin >> stall;
                graph[i].push_back(stall);
            }
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 210; j++) visited[j] = 0;
            if(DFS(i)) cnt++;
        }
        
        cout << cnt << "\n";
    }
    return 0;
}