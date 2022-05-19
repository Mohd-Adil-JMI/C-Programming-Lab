#include <iostream>
#include <vector>
#define max INT16_MAX
using namespace std;

vector<int> v;
int main()
{
    int n;
    cout << "Enter size of an Array -> ";
    scanf("%d", &n);
    int arr[n];
    cout << "Enter Array Elements -> ";
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int sum = max;
    int temp;
    for (int i = 1; i <= n; i++) //grouping no. of elements
    {
        for (int j = 0; j <= n - i; j++) //iterating through these continous groups
        {
            temp = 0;
            v.clear();
            for (int k = j; k < j + i; k++) //iterating through elements of particular group
            {
                temp += arr[k];
                v.push_back(arr[k]);
            }
            if (temp <= sum)
            {
                sum = temp;
            }
        }
    }
    printf("Minimum sum -> %d\nSub Array : ", sum);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }

    return 0;
}