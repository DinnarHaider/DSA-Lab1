#include <iostream>
using namespace std;
void pascal(int n)
{
    int a[20][20] = {};
    for (int i = 0; i < n; i++)
    {
        a[i][0] = 1;
        a[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }
    for (int i = 0; i < n; i++) // loop use to print
    {
        for (int j = 0; j <= i; j++)
        {
            cout << a[i][j] << " "; //printss the pascal triangle
        }
        cout << endl;
    }
}
int main() // main function
{
    pascal(5); //test case
    return 0;
}