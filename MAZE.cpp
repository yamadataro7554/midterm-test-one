#include <bits/stdc++.h>

using namespace std;

struct top {
    long x, y;
};

int a[1005][1005];
bool fr[1005][1005];
top tr[1005][1005];
long m, n, k, l;

void DFS(long i, long j) {
    if (!fr[i][j])
        return;
    
    fr[i][j] = false;
    
    if (i == 1 || i == m || j == 1 || j == n)
        return;

    if (a[i-1][j] == 1 && fr[i-1][j]) {
        tr[i-1][j].x = i;
        tr[i-1][j].y = j;

        DFS(i-1, j);
    }

    if (a[i+1][j] == 1 && fr[i+1][j]) {
        tr[i+1][j].x = i;
        tr[i+1][j].y = j;

        DFS(i+1, j);
    }

    if (a[i][j-1] == 1 && fr[i][j-1]) {
        tr[i][j-1].x = i;
        tr[i][j-1].y = j;

        DFS(i, j-1);
    }

    if (a[i][j+1] == 1 && fr[i][j+1]) {
        tr[i][j+1].x = i;
        tr[i][j+1].y = j;

        DFS(i, j+1);
    }
}

void writeAnswer(long i, long j) {
    string s, s1, s2;
    long i1;

    s = "";
    
    while (i != k || j != l) {
        s1 = to_string(i);
        s2 = to_string(j);

        s = "->(" + s1 + "," + s2 + ")" + s;
        i1 = i;

        i = tr[i][j].x;
        j = tr[i1][j].y;
    }

    s1 = to_string(i);
    s2 = to_string(j);

    s = "(" + s1 + "," + s2 + ")" + s;

    cout << s;
}

void problemHandler() {
    int i, j;

    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            if (a[i][j] == 2) {
                DFS(i, j);

                k = i;
                l = j;

                break;
            }

    for (int i=1; i<=m; i++) {
        if (!fr[i][1])
            writeAnswer(i, 1);

        if (!fr[i][n])
            writeAnswer(i, n);
    }

    for (int j=1; j<=n; j++) {
        if (!fr[1][j])
            writeAnswer(1, j);
        
        if (!fr[m][j])
            writeAnswer(m, j);
    }

    // cout << tr[2][2].x << " " << tr[2][2].y;

    // writeAnswer(1, 2);

    // for(int i=1; i<=n; i++)
        // cout << fr[1, i] << " ";
}

int main() {
    freopen("MAZE.inp", "r", stdin);
    freopen("MAZE.out", "w", stdout);

    cin >> m >> n;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
    
    for (int i=0; i<=1004; i++)
        for (int j=0; j<=1004; j++)
            fr[i][j] = true;

    problemHandler();

    return 0;
}