/*
Activity selection using Greedy method:

Problem Statement:
Determine the maximum number of activities that can be performed by a single person given a set of activities with start and finish times, assuming that the person can only work on one activity at a time. The goal is to complete as many activities as possible.
Input:
The first line of input contains the integer N, which represents the number of activities. The following N lines each contain two integers si and fi, which represent the start and end times of the ith activity.
Output:
Give the maximum number of activities that can be performed, along with their start and end times.
Constraints:
•	1 ≤ N ≤ 100
•	1 ≤ si < fi ≤ 100
Sample Input
6
1 4
3 5
0 6
5 7
3 8
5 9
Sample Output 
2
(1,4) (5,7)
Note:
•	Compute the running time complexity, for your working code.
*/

#include <stdio.h>
#include <stdlib.h>

struct keys {
    int si;
    int fi;
};

int cmp(const void *a, const void *b) {
    struct keys *k1 = (struct keys *)a;
    struct keys *k2 = (struct keys *)b;
    return k1->fi - k2->fi;
}

int main() {
    int n = 6;
    int si[6] = {1, 3, 0, 5, 3, 5};
    int fi[6] = {4, 5, 6, 7, 8, 9};
    struct keys k[n];
    for (int i = 0; i < n; i++) {
        k[i].si = si[i];
        k[i].fi = fi[i];
    }
    qsort(k, n, sizeof(struct keys), cmp);
    int count = 1;
    int end = k[0].fi;
    struct keys s[n];
    s[0] = k[0];
    int sc = 1;
    for (int i = 1; i < n; i++) {
        if (k[i].si >= end) {
            count++;
            s[sc] = k[i];
            end = k[i].fi;
            sc++;
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("(%d,%d) ", s[i].si, s[i].fi);
    }
    return 0;
}
