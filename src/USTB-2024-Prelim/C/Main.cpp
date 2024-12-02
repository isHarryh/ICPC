#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> maze(n, vector<int>(m));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            scanf("%d", &maze[y][x]); // Use fast-io
        }
    }

    vector<int> up_row(m, 0), cur_row(m, 0);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cur_row[x] = (y == 0 && x == 0) ? maze[0][0] : 0;
            if (maze[y][x] != 0) {
                if (y > 0) cur_row[x] += up_row[x]; // From up
                if (x > 0) cur_row[x] += cur_row[x - 1]; // From left
                cur_row[x] %= MOD;
            }
        }
        up_row = cur_row;
    }

    if (up_row[m - 1] == 0) cout << -1 << endl;
    else cout << up_row[m - 1] << endl;

    return 0;
}
