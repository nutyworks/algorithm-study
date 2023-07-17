#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    using p = pair<int, int>;
    priority_queue<p, vector<p>, greater<p>> pq;
    int N, L;

    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        pq.push({a, i + L});
        
        while (i >= pq.top().second) pq.pop();

        cout << pq.top().first << ' ';
    }

    return 0;
}