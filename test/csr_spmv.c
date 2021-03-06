/**
BEGIN_EXPECTED
A
    S0: int i;
    S1: int i;
    S2: product[i] += A[k] * x[col[k]];
    S3: return 0;
B
    S0: {[]}
    S1: {[]}
    S2: {[i, k]: 0 <= i < N and index(i) <= k < index(i + 1)}
    S3: {[]}
C
    S0:  {[]->[0,0,0,0,0]}
    S1:  {[]->[1,0,0,0,0]}
    S2:  {[i,k]->[2,i,0,k,0]}
    S3:  {[]->[3,0,0,0,0]}
END_EXPECTED
 */

// perform sparse matrix-vector multiplication using CSR format
int CSR_SpMV(int a, int N, int A[a], int index[N + 1], int col[a], int x[N], int product[N]) {
    int i;
    int k;
    for (i = 0; i < N; i++) {
        for (k = index[i]; k < index[i + 1]; k++) {
            product[i] += A[k] * x[col[k]];
        }
    }

    return 0;
}
