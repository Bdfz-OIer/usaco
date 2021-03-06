/*
ID: nathan.18
TASK: range
LANG: C++11
*/

#include <iostream>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <unordered_set>

using namespace std;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0R1(i, a) for (int i=1; i<=(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define F0Rd1(i, a) for (int i=a; i>0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())

#define INF 1000000010
#define LL_INF 4500000000000000000
#define LSOne(S) (S & (-S))
#define EPS 1e-9
#define pA first
#define pB second
#define mp make_pair
#define pb push_back
#define PI acos(-1.0)
#define ll long long
#define MOD (int)(2e+9+11)
#define SET(vec, val, size) for (int i = 0; i < size; i++) vec[i] = val;
#define SET2D(arr, val, dim1, dim2) F0R(i, dim1) F0R(j, dim2) arr[i][j] = val;
#define READGRID(arr, dim) F0R(i, dim) F0R(j, dim) cin >> arr[i][j];
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;

int main() {
    freopen("range.in", "r", stdin);
    freopen("range.out", "w", stdout);

    int n; cin >> n;
    int dp[251][251];
    int grid[251][251];
    F0R1(i, n) F0R1(j, n) { char c; cin >> c; grid[i][j] = c-'0'; }
    SET2D(dp, 0, 251, 251);

    int delta[500]; SET(delta, 0, 500);

    F0R1(i, n) {
        F0R1(j, n) {
            dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            if (grid[i][j] == 0) dp[i][j] = 0;
            if (dp[i][j] >= 2) {
                delta[2]++;
                delta[dp[i][j]+1]--;
            }
        }
    }

    int ans = 0;
    FOR(i, 2, 500) {
        ans += delta[i];
        if (ans > 0) {
            cout << i << " " << ans << endl;
        }
    }

    return 0;
}
