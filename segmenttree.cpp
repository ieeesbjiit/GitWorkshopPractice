#include <bits/stdc++.h>
using namespace std;
//QUERRY CODE
int querry(int segTree[], int low, int high, int pos, int qh, int ql)
{
    if (low >= ql && high <= qh)
    {
        return segTree[pos];
    }
    if (low < ql && high > qh)
    {
        int mid = (low + high) / 2;
        int q1 = querry(segTree, low, mid, 2 * pos + 1, qh, ql);
        int q2 = querry(segTree, mid + 1, high, 2 * pos + 2, qh, ql);
        return min(q1, q2);
    }
    else
    {
        return INT_MAX;
    }
}
//BUILD TREE
void consTree(int input[], int low, int high, int pos, int segTree[])
{
    if (low == high)
    {
        segTree[pos] = input[low];
    }
    int mid = (low + high) / 2;
    consTree(input, low, mid, 2 * pos + 1, segTree);
    consTree(input, mid + 1, high, 2 * pos + 2, segTree);
    segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
}
//UPDATE CODE
int main()
{
    int n;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int *segTree = new int[2 * n - 1];
    int pos = 0;
    consTree(input, 0, n - 1, pos, segTree);

    for (int i = 0; i < 2 * n - 1; i++)
    {
        cout << segTree[i];
    }
    int qh, ql;
    cin >> qh >> ql;

    return 0;
}