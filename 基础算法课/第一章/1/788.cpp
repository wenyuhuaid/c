#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 100010;
int n;    // n个数据
int q[N]; // 原数组
int t[N]; // 临时数组
LL res;   // 结果                    

void merge_sort(int q[], int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
        if (q[i] <= q[j])
            t[k++] = q[i++];
        else {
            t[k++] = q[j++];
            res += mid - i + 1;
        }
    while (i <= mid) t[k++] = q[i++];
    while (j <= r) t[k++] = q[j++];
    for (i = l, j = 0; i <= r; i++, j++) q[i] = t[j];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> q[i];
    merge_sort(q, 1, n);
    printf("%d\n", res);
    return 0;
}
