#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int l, r;
} Interval;

int cmp(const void *a, const void *b) {
    Interval *x = (Interval *)a;
    Interval *y = (Interval *)b;
    if (x->l != y->l) return x->l - y->l;
    return x->r - y->r;
}

int main() {
    int len, m;
    scanf("%d %d", &len, &m);

    Interval *a = (Interval *)malloc(m * sizeof(Interval));
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a[i].l, &a[i].r);
    }

    // 按左端点排序，左端点相同按右端点
    qsort(a, m, sizeof(Interval), cmp);

    int count = len + 1;          // 初始总棵树
    int L = a[0].l, R = a[0].r;   // 当前合并区间

    for (int i = 1; i < m; i++) {
        if (a[i].l <= R) {
            // 重叠：扩展右边界
            if (a[i].r > R) R = a[i].r;
        } else {
            // 不重叠：结算上一个合并区间，开启新区间
            count -= R - L + 1;
            L = a[i].l;
            R = a[i].r;
        }
    }
    // 结算最后一个合并区间
    count -= R - L + 1;

    printf("%d\n", count);

    free(a);
    return 0;
}
