#include <stdio.h>
void max(int A[], int constraint, int N) {
    int i, j, sum = 0, s[N], n, B[N];
    for (i = 0; i < N; i++) {
        if (A[i] <= constraint) {
            sum = A[i];
        }
        for (j = i + 1; j < N; j++) {
            if (sum + A[j] <= constraint) {
                sum = sum + A[j];
            } else {
                break;
            }
        }
        s[i] = sum;
        B[i] = i;
    }
    int ss, bb;
    ss = s[0];
    bb = B[0];
    for (i = 1; i < N; i++) {
        if (ss < s[i]) {
            ss = s[i];
            bb = B[i];
        }
    }
    sum = 0;
    i = 0;
    for (j = bb; j < N; j++) {
        if (sum + A[j] <= constraint) {
            sum = sum + A[j];
            printf("%d", A[j]);
        }
    }
    printf("\nHighest:%d", ss);
}
int main() {
    int N, i;
    printf("Enter the size of array:");
    scanf("%d", &N);
    int A[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (i = 0; i < N; i++) {
        printf("%d", A[i]);
    }
    int constraint;
    printf("\nEnter the value of constraint:");
    scanf("%d", &constraint);
    max(A, constraint, N);
    return 0;
}
