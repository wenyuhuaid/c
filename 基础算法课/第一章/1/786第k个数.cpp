#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
int q[N];
int n, k;

void quick_sort(int q[], int l, int r, int k) {
    if (l >= r) return;
    int i = l - 1, j = r + 1, x = q[(l + r) >> 1];
    while (i < j) {
        do i++;
        while (q[i] > x);
        do j--;
        while (q[j] < x);
        if (i < j) swap(q[i], q[j]);
    }
    int len = j - l + 1; // 左侧长度
    if (k <= len)
        quick_sort(q, l, j, k); // 左侧
    else
        quick_sort(q, j + 1, r, k - len); // 右侧
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> q[i];
    quick_sort(q, 1, n, k);
    printf("%d", q[k]);
    return 0;
}
