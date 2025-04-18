#include <iostream>
#include <cstring>
using namespace std;

const int MANX = 100010;
int fa[MANX];

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx!= fy) fa[fx] = fy;
}

int main() {
    int n, m;
    cin >> n >> m;
    memset(fa, 0, sizeof(fa));
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 0; i < m; i++) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 0) merge(x, y);
        else {
            int fx = find(x), fy = find(y);
            if (fx == fy) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
    return 0;
}