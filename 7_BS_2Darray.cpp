#include <bits/stdc++.h>
using namespace std;

int numberOfOnes(vector<int> a)
{
    int low = 0;
    int high = a.size();
    int n = a.size();
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == 1)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (ans >= 0)
        return n - ans;
    return -1;
}

int rowWithMax1s(vector<vector<int>> &mat)
{
    int maxi = INT_MIN;
    int idx = -1;
    for (int i = 0; i < mat[0].size(); i++)
    {
        int num = numberOfOnes(mat[i]);
        if (maxi < num)
        {
            idx = i;
            maxi = num;
        }
    }
    if (maxi == -1)
        return -1;
    return idx;
}

bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = (n * m) - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mat[mid / m][mid % m] == target)
        {
            return true;
        }
        if (mat[mid / m][mid % m] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}

bool searchMatrixII(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int i = 0;
    int j = m - 1;
    while (i < n && j >= 0)
    {
        if (matrix[i][j] == target)
        {
            return true;
        }
        if (matrix[i][j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}

int maxElementInACol(vector<vector<int>> &mat, int n, int m, int mid)
{
    int maxEle = INT_MIN;
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (mat[i][mid] > maxEle)
        {
            maxEle = mat[i][mid];
            idx = i;
        }
    }
    return idx;
}

vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = m - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int row = maxElementInACol(mat, n, m, mid);
        int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
        int right = mid + 1 < m ? mat[row][mid + 1] : -1;
        if (mat[row][mid] > left && mat[row][mid] > right)
        {
            return {row, mid};
        }
        else if (mat[row][mid] < left)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {-1, -1};
}

int upper_bound(vector<int> &matrix, int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (matrix[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int countSmallEqual(vector<vector<int>> &matrix, int n, int m, int mid)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += upper_bound(matrix[i], m, mid);
    }
    return cnt;
}

int findMedian(vector<vector<int>> &matrix)
{
    int low = INT_MAX;
    int high = INT_MIN;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        low = min(matrix[i][0], low);
        high = max(matrix[i][m - 1], high);
    }
    int req = (n * m) / 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int smallEqual = countSmallEqual(matrix, n, m, mid);
        if (smallEqual <= req)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans;
    ans = findMedian(arr);
    cout << ans;
    return 0;
}