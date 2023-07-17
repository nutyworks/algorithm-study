#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    bool edge_matrix[100][100];
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> edge_matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int conn = 0, old_conn = -1;

        while (conn != old_conn) {
            old_conn = conn;
            conn = 0;

            for (int j = 0; j < n; j++) {
                if (!edge_matrix[i][j]) continue;

                for (int k = 0; k < n; k++) {
                    edge_matrix[i][k] |= edge_matrix[j][k];
                }
            }

            for (int j = 0; j < n; j++) conn += edge_matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << edge_matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}