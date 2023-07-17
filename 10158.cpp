#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int w, h, w0, h0, dt;

    cin >> w >> h >> w0 >> h0 >> dt;

    int calc_w_dt = dt % (w << 1);
    int calc_h_dt = dt % (h << 1);
    int wf, hf;

    if (calc_w_dt < w - w0) wf = w0 + calc_w_dt;
    else if (calc_w_dt <= 2 * w - w0) wf = 2 * w - w0 - calc_w_dt;
    else wf = (w0 + calc_w_dt) % w;

    if (calc_h_dt < h - h0) hf = h0 + calc_h_dt;
    else if (calc_h_dt <= 2 * h - h0) hf = 2 * h - h0 - calc_h_dt;
    else hf = (h0 + calc_h_dt) % h;

    cout << wf << ' ' << hf;

    return 0;
}