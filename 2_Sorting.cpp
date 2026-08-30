#include <bits/stdc++.h>
using namespace std;

vector<int> selectionSort(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[i])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    return nums;
}

vector<int> bubbleSort(vector<int> &nums)
{
    int n = nums.size();
    bool swap = false;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap = true;
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
        if (swap == false)
        {
            break;
        }
    }
    return nums;
}

vector<int> insertionSort(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
    return nums;
}

void merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else
        {
            temp.push_back(nums[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(nums[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
        nums[i] = temp[i - low];
}
void mergeSortF(vector<int> &nums, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSortF(nums, low, mid);
    mergeSortF(nums, mid + 1, high);
    merge(nums, low, mid, high);
}
vector<int> mergeSort(vector<int> &nums)
{
    mergeSortF(nums, 0, nums.size() - 1);
    return nums;
}

void bubble_sort(vector<int> &arr, int n)
{
    if (n == 1)
        return;

    int didSwap = 0;

    // One pass: push the largest element to the end
    for (int j = 0; j <= n - 2; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            // Swap arr[j] and arr[j + 1]
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
            didSwap = 1; // Mark that we did a swap
        }
    }

    if (didSwap == 0)
        return;

    bubble_sort(arr, n - 1);
}

vector<int> bubbleSortRecursive(vector<int> &nums)
{
    vector<int> arr = nums;
    bubble_sort(arr, arr.size());
    return arr;
}

void insertion_sort(vector<int> &arr, int i, int n)
{
    if (i == n)
        return;

    int j = i;

    while (j > 0 && arr[j - 1] > arr[j])
    {
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        j--;
    }
    insertion_sort(arr, i + 1, n);
}

vector<int> insertionSortRecursive(vector<int> &nums)
{
    vector<int> arr = nums;
    insertion_sort(arr, 0, arr.size());
    return arr;
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        // If element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            // Increment i and swap with j
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Place pivot in correct position
    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSortR(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSortR(arr, low, pivotIndex - 1);
        quickSortR(arr, pivotIndex + 1, high);
    }
}

vector<int> quickSort(vector<int> &nums)
{
    quickSortR(nums, 0, nums.size() - 1);
    return nums;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    quickSortR(arr, 0, arr.size() - 1);
    for (auto v : arr)
    {
        cout << v << " ";
    }
    cout << endl;
}