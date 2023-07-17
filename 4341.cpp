#include <bits/stdc++.h>

using namespace std;
using ll = long long;

tuple<ll, ll, ll> extract_coefficients(string s) {
    tuple<ll, ll, ll, ll, ll, ll> coefficients = {0, 0, 0, 0, 0, 0};
    int eq_index = s.find_first_of('=');
    ll n = 0;
    bool negative = false, n_input = false;

    for (char c : s.substr(0, eq_index - 1)) {
        if (c == '-') negative = !negative;
        if (c >= '0' && c <= '9') {
            n = n * 10 + c - '0';
            n_input = true;
        }
        if (c == 'x') {
            get<0>(coefficients) += (n ? n : 1) * (negative ? -1 : 1);
            n = 0, negative = false, n_input = false;
        }
        if (c == 'y') {
            get<1>(coefficients) += (n ? n : 1) * (negative ? -1 : 1);
            n = 0, negative = false, n_input = false;
        }
        if (c == ' ' && n_input == true) {
            get<2>(coefficients) += n * (negative ? -1 : 1);
            n = 0, negative = false, n_input = false;
        }
    }
    get<2>(coefficients) += n * (negative ? -1 : 1);

    n = 0, negative = false, n_input = false;

    for (char c : s.substr(eq_index + 2, s.size())) {
        if (c == '-') negative = !negative;
        if (c >= '0' && c <= '9') {
            n = n * 10 + c - '0';
            n_input = true;
        }
        if (c == 'x') {
            get<3>(coefficients) += (n ? n : 1) * (negative ? -1 : 1);
            n = 0, negative = false, n_input = false;
        }
        if (c == 'y') {
            get<4>(coefficients) += (n ? n : 1) * (negative ? -1 : 1);
            n = 0, negative = false, n_input = false;
        }
        if (c == ' ' && n_input == true) {
            get<5>(coefficients) += n * (negative ? -1 : 1);
            n = 0, negative = false, n_input = false;
        }
    }
    get<5>(coefficients) += n * (negative ? -1 : 1);

    return {
        get<0>(coefficients) - get<3>(coefficients),
        get<1>(coefficients) - get<4>(coefficients),
        get<5>(coefficients) - get<2>(coefficients),
    };
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin.ignore();

        string eq1, eq2, empty;
        getline(cin, eq1);
        getline(cin, eq2);

        ll a, b, c, d, p, q;
        tie(a, b, p) = extract_coefficients(eq1);
        tie(c, d, q) = extract_coefficients(eq2);

        ll denominator = a * d - b * c;

        if (denominator == 0) {
            if (a != 0 && b == 0 && c != 0 && d == 0) {
                if (p == 0 && q == 0) {
                    cout << "0\ndon't know\n";
                } else if (p != 0 && q != 0) {
                    if (a * q == c * p) {
                        if (a < 0) a = -a, p = -p;
                        ll xgcd = gcd(p, a);
                        if (a == xgcd) {
                            cout << p / a << "\ndon't know\n";
                        } else {
                            cout << p / xgcd << '/' << a / xgcd << "\ndon't know\n";
                        }
                    } else {
                        cout << "don't know\ndon't know\n";
                    }
                } else {
                    cout << "don't know\ndon't know\n";
                }
            } else if (a == 0 && b != 0 && c == 0 && d != 0) {
                if (p == 0 && q == 0) {
                    cout << "0\ndon't know\n";
                } else if (p != 0 && q != 0) {
                    if (b * q == d * p) {
                        if (b < 0) b = -b, p = -p;
                        ll xgcd = gcd(p, b);
                        if (b == xgcd) {
                            cout << "don't know\n" << p / b << "\n";
                        } else {
                            cout << "don't know\n" << p / xgcd << '/' << b / xgcd << "\n";
                        }
                    } else {
                        cout << "don't know\ndon't know\n";
                    }
                } else {
                    cout << "don't know\ndon't know\n";
                }
            } else if (a == 0 && b == 0 && p == 0) {
                if (c != 0 && d == 0) {
                    if (c < 0) c = -c, q = -q;
                    ll xgcd = gcd(q, c);
                    if (c == xgcd) {
                        cout << q / c << "\ndon't know\n";
                    } else {
                        cout << q / xgcd << '/' << c / xgcd << "\ndon't know\n";
                    }
                } else if (c == 0 && d != 0) {
                    if (d < 0) d = -d, q = -q;
                    ll ygcd = gcd(q, d);
                    if (d == ygcd) {
                        cout << "don't know\n" << q / d << "\n";
                    } else {
                        cout << "don't know\n" << q / ygcd << '/' << d / ygcd << "\n";
                    }
                } else {
                    cout << "don't know\ndon't know\n";
                }
            } else if (c == 0 && d == 0 && q == 0) {
                if (a != 0 && b == 0) {
                    if (a < 0) a = -a, p = -p;
                    ll xgcd = gcd(p, a);
                    if (a == xgcd) {
                        cout << p / a << "\ndon't know\n";
                    } else {
                        cout << p / xgcd << '/' << a / xgcd << "\ndon't know\n";
                    }
                } else if (a == 0 && b != 0) {
                    if (b < 0) b = -b, p = -p;
                    ll ygcd = gcd(p, b);
                    if (b == ygcd) {
                        cout << "don't know\n" << p / b << "\n";
                    } else {
                        cout << "don't know\n" << p / ygcd << '/' << b / ygcd << "\n";
                    }
                } else {
                    cout << "don't know\ndon't know\n";
                }
            } else {
                cout << "don't know\ndon't know\n";
            }
        } else {
            ll x_t_deno = d * p - b * q, y_t_deno = a * q - c * p;

            if (denominator < 0) {
                denominator *= -1;
                x_t_deno *= -1;
                y_t_deno *= -1;
            }

            ll xgcd = gcd(x_t_deno, denominator), ygcd = gcd(y_t_deno, denominator);

            if (denominator == xgcd) {
                cout << x_t_deno / denominator << '\n';
            } else {
                cout << x_t_deno / xgcd << '/' << denominator / xgcd << '\n';
            }
            if (denominator == ygcd) {
                cout << y_t_deno / denominator << '\n';
            } else {
                cout << y_t_deno / ygcd << '/' << denominator / ygcd << '\n';
            }
        }
        if (tc) cout << '\n';
    }

    return 0;
}