#include <iostream>
using namespace std;
int mode(int a[], int n)
{
    if (n == 0)
        return -1;
    int most = a[0];
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
                count++;
        }
        if (count > max)
        {
            max = count;
            most = a[i];
        }
    }
    return most;
}
int main()
{
    int a[] = {1, 2, 2, 3, 4};
    cout << mode(a, 5);
    return 0;
}