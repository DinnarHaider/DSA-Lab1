#include <iostream>
using namespace std;
// Adding two matrices
void add(int A[][20], int B[][20], int C[][20], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}
void subtract(int A[][20], int B[][20], int C[][20], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}
void Nmultiply(int A[][20], int B[][20], int C[][20], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;

            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}
void strassen(int A[][20], int B[][20], int C[][20], int n)
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int half = n / 2;
    int A11[20][20] = {}, A12[20][20] = {};
    int A21[20][20] = {}, A22[20][20] = {};
    int B11[20][20] = {}, B12[20][20] = {};
    int B21[20][20] = {}, B22[20][20] = {};
    for (int i = 0; i < half; i++)
        for (int j = 0; j < half; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
                        A21[i][j] = A[i + half][j];
        A22[i][j] = A[i + half][j + half];
            B11[i][j] = B[i][j];
        B12[i][j] = B[i][j + half];
         B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
int M1[20][20], M2[20][20], M3[20][20];
    int M4[20][20], M5[20][20], M6[20][20], M7[20][20];
    int X[20][20], Y[20][20];
    // M1 = (A11 + A22)(B11 + B22)
    add(A11, A22, X, half);
        add(B11, B22, Y, half);
    strassen(X, Y, M1, half);
    // M2 = (A21 + A22)B11
add(A21, A22, X, half);
    strassen(X, B11, M2, half);
    // M3 = A11(B12 - B22)
        subtract(B12, B22, Y, half);
    strassen(A11, Y, M3, half);
    // M4 = A22(B21 - B11)
        subtract(B21, B11, Y, half);
    strassen(A22, Y, M4, half);
    // M5 = (A11 + A12)B22
    add(A11, A12, X, half);
    strassen(X, B22, M5, half);
    // M6 = (A21 - A11)(B11 + B12)
    subtract(A21, A11, X, half);
add(B11, B12, Y, half);
    strassen(X, Y, M6, half);
    // M7 = (A12 - A22)(B21 + B22) 
       subtract(A12, A22, X, half);
    add(B21, B22, Y, half);
    strassen(X, Y, M7, half);
    // C11 = M1 + M4 - M5 + M7
    for (int i = 0; i < half; i++)
        for (int j = 0; j < half; j++)
        {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            // C12 = M3 + M5
            C[i][j + half] = M3[i][j] + M5[i][j];
            // C21 = M2 + M4
                C[i + half][j] = M2[i][j] + M4[i][j];
            // C22 = M1 - M2 + M3 + M6
            C[i + half][j + half] =
                M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
}
int main()
{
    int A[20][20] = {
        {1, 2},
        {3, 4}
    };
    int B[20][20] = {
        {5, 6},
        {7, 8}
    };
        int C1[20][20] = {};
    int C2[20][20] = {};
    // Strassen
    strassen(A, B, C1, 2);
    // Normal multiplication
    Nmultiply(A, B, C2, 2);
    cout << "Strassen Result:\n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << C1[i][j] << " ";
        cout << endl;
    }
    cout << "\nNormal Multiplication Result:\n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << C2[i][j] << " ";
        cout << endl;
    }
    return 0;
}