#include <bits/stdc++.h>

using namespace std;

vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
{
    map<int, int> freq;
    vector<int> Union;
    for (int i = 0; i < n; i++)
        freq[arr1[i]]++;
    for (int i = 0; i < m; i++)
        freq[arr2[i]]++;
    for (auto &it : freq)
        Union.push_back(it.first);
    return Union;
}

// arr1 = {1, 2, 3, 5}
//  | i | arr1[i] | freq after insertion |
//  | - | ------- | -------------------- |
//  | 0 | 1       | {1:1}                |
//  | 1 | 2       | {1:1, 2:1}           |
//  | 2 | 3       | {1:1, 2:1, 3:1}      |
//  | 3 | 5       | {1:1, 2:1, 3:1, 5:1} |

// arr2 = {2, 3, 4, 4, 5}
// | i | arr2[i] | freq after insertion      |
// | - | ------- | ------------------------- |
// | 0 | 2       | {1:1, 2:2, 3:1, 5:1}      |
// | 1 | 3       | {1:1, 2:2, 3:2, 5:1}      |
// | 2 | 4       | {1:1, 2:2, 3:2, 4:1, 5:1} |
// | 3 | 4       | {1:1, 2:2, 3:2, 4:2, 5:1} |
// | 4 | 5       | {1:1, 2:2, 3:2, 4:2, 5:2} |

// Union = [1, 2, 3, 4, 5]

int main()
{
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    vector<int> Union = FindUnion(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is " << endl;
    for (auto &val : Union)
        cout << val << " ";
    return 0;
}