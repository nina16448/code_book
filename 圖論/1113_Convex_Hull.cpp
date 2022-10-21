#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define x first
#define y second
typedef long long lint;
int n, l;
double ans;
vector <pair <int, int> > point;
vector <pair <int, int> > L, U;

int Cross_Product(pair <int, int> o, pair <int, int> a, pair <int, int> b){
    return (o.x - a.x) * (b.y - o.y) - (b.x - o.x) * (o.y - a.y);
}

double Distance(pair <int, int> p1, pair <int, int> p2){
    return sqrt((double)(p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void Andrew_Monotone_Chain(){
    sort(point.begin(), point.end());

    for(int i = 0; i < n; i++){
        while(L.size() >= 2 && Cross_Product(L[L.size() - 2], L[L.size() - 1], point[i]) <= 0){
            ans -= Distance(L[L.size() - 2], L[L.size() - 1]);
            L.pop_back();
        }

        L.push_back(point[i]);
        if(L.size() >= 2) ans += Distance(L[L.size() - 2], L[L.size() - 1]);

    }

    for(int i = n - 1; i >= 0; i--){
        while(U.size() >= 2 && Cross_Product(U[U.size() - 2], U[U.size() - 1], point[i]) <= 0){
            ans -= Distance(U[U.size() - 2], U[U.size() - 1]);
            U.pop_back();
        }

        U.push_back(point[i]);
        if(U.size() >= 2) ans += Distance(U[U.size() - 2], U[U.size() - 1]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    pair <int, int> rec;
    ans = 0;

    cin >> n >> l;
    for(int i = 0; i < n; i++){
        cin >> rec.x >> rec.y;
        point.push_back(rec);
    }

    Andrew_Monotone_Chain();

    reverse(U.begin(), U.end());
    if(U == L) ans /= 2;

    cout << fixed << setprecision(0) << ans + 2 * 3.1415926 * l << "\n";
    return 0;
}