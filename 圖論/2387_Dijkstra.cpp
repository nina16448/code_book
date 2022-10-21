#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long lint;
#define d first
#define p second
priority_queue <pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > pq;
vector <pair <int, int> > arr[1010];
int T, N, a, b, dis;
int stp[1010];
int visited[1010];

void greedy(int level){
    visited[level] = 1;
    for(vector<pair <int, int> >::iterator i = arr[level].begin(); i != arr[level].end(); i++){
        if(visited[i->p]) continue;

        i->d += stp[level];
        stp[i->p] = min(stp[i->p], i->d);
        // i->d = stp[i->p];
        pq.push(*i);
    }

    while(!pq.empty() && visited[pq.top().p]) pq.pop();
    if(pq.empty()) return;

    greedy(pq.top().p);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T >> N;
    for(int i = 0; i < T; i++){
        cin >> a >> b >> dis;
        arr[a].push_back(make_pair(dis, b));
        arr[b].push_back(make_pair(dis, a));
    }
    for(int i = 0; i < 1010; i++) stp[i] = 0x3f3f3f3f;
    stp[N] = 0;
    greedy(N);

    cout << stp[1] << "\n";
    return 0;
}