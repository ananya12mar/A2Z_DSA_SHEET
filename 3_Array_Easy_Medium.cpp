#include <bits/stdc++.h>
using namespace std;

int secondLargestElement(vector<int>& nums) {
    int largest= -1e9;
    int secondLargest = -1e9;
    
    for(auto v: nums){
        if(v>largest){
            secondLargest=largest;
            largest = v;
        }else if(secondLargest<v && v<largest){
            secondLargest=v;
        }
    }
    if(secondLargest==-1e9) return -1;
    else return secondLargest;
}

bool isSorted(vector<int>& nums){
	int sorted=true;
	for(int i=1;i<nums.size();i++){
	    if(nums[i]<nums[i-1]){
	        return false;
	    }
	}
	return true;
}

int removeDuplicates(vector<int>& nums) {
    int lastUnique=0;
    int count=1;
    int i =0;
    int n = nums.size();
    while(i<n){
        if(nums[i]==nums[lastUnique]){
            i++;   
        }else if(nums[i]>nums[lastUnique]){
            lastUnique++;
            count++;
            nums[lastUnique] = nums[i];
            i++;
        }
    }
    return count;
}

void rotateArrayByOne(vector<int>& nums) {
    int first=nums[0];
    int n = nums.size();
    for(int i=1;i<n;i++){
        nums[i-1]=nums[i];
    }
    nums[n-1]=first;
}

void rotateArray(vector<int>& nums, int k) {
    int n = nums.size();
    int rotate = k%n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(),nums.begin()+n-rotate);
    reverse(nums.begin()+n-rotate,nums.end());
}

void moveZeroes(vector<int>& nums) {
    int a=-1;
    int n = nums.size();
    for(int i =0;i<n;i++){
        if(nums[i]==0){
            a=i;
            break;
        }
    }
    if(a==-1) return;
    for(int i=a+1;i<n;i++){
        if(nums[i]!=0){
            swap(nums[i], nums[a]);
            a++;
        }
    }
}

int linearSearch(vector<int>& nums, int target) {
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]==target){
            return i;
        }
    }
    return -1;
}

vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
    int p1=0;
    int p2=0;
    vector<int> arr;
    while(p1<nums1.size()&&p2<nums2.size()){
        if(nums1[p1]<nums2[p2]){
            if(arr.empty() || arr.back()!=nums1[p1]){
                arr.push_back(nums1[p1]);
            }
            p1++;
        }else if(nums1[p1]>nums2[p2]){
            if(arr.empty() || arr.back()!=nums2[p2]){
                arr.push_back(nums2[p2]);
            }
            p2++;
        }else{
            if (arr.empty() || arr.back()!= nums1[p1])
                arr.push_back(nums1[p1]);
            p1++;
            p2++;
        }
    }
        
    while (p1 < nums1.size()) {
        if (arr.back() != nums1[p1])
            arr.push_back(nums1[p1]);
        p1++;
    }

    while (p2 < nums2.size()) {
        if (arr.back() != nums2[p2])
            arr.push_back(nums2[p2]);
        p2++;
    }
    return arr;
}

int missingNumber(vector<int>& nums) {
    int sum =0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }
    int tot=0;
    for(int i=1;i<=n;i++){
        tot+=i;
    }
    return tot-sum;
}

int findMaxConsecutiveOnes(vector<int>& nums) {
    int max=0;
    int currentContinuous=0;
    for(auto v:nums){
        if(v==1){
            currentContinuous++;
            if(max<currentContinuous){
                max=currentContinuous;
            }
        }else if(v==0){
            currentContinuous=0;
        }
    }
    return max;
}

int singleNumber(vector<int>& nums){
    int ans=0;
    int i =0;
    while(i<nums.size()){
        ans^=nums[i];
        i++;
    }
    return ans;
}

int longestSubarray(vector<int> &nums, int k){
    int i=0,j=0;
    int n=nums.size();
    int maxCount=0;
    for(int i=0;i<n;i++){
        int j=i;
        int sum=0;
        int currentCount=0;
        while(j<n){
            if(sum==k){
                if(maxCount<currentCount){
                    maxCount=currentCount;
                    break;
                }
            }
            sum+=nums[j];
            currentCount++;
            j++;
        }
    }
    return maxCount;
}

vector<int> twoSum(vector<int>& nums, int target) {
    int n=nums.size();
    int i=0;
    int j=n-1;
    vector<pair<int,int>> mp;
    for(int i=0;i<n;i++){
        mp.push_back({nums[i],i});
    }
    sort(mp.begin(),mp.end());
    vector<int> two;
    while(i<j){
        if(mp[i].first+mp[j].first==target){
            two.push_back(mp[i].second);
            two.push_back(mp[j].second);
            sort(two.begin(),two.end());
            return two;
        }else if(mp[i].first+mp[j].first>target){
            j--;
        }else if(mp[i].first+mp[j].first<target){
            i++;
        }
    }
    return {-1,-1};
}

void sortZeroOneTwo(vector<int>& nums) {
    int low=0;
    int high=nums.size()-1;
    int mid=0;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            mid++;
            low++;
        }else if(nums[mid]==1){
            mid++;
        }else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}

int majorityElement(vector<int>& nums) {
    int count=1;
    int candidate=nums[0];
    int n=nums.size();
    for(int i=1;i<n;i++){
        if(nums[i]==candidate){
            count++;
        }else if(nums[i]!=candidate){
            count--;
        }else if(count==0){
            candidate=nums[i];
        }
    }
    return candidate;
}

int maxSubArray(vector<int>& nums) {
    int currentSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}
int stockBuySell(vector<int> arr, int n){
    int minPrice=arr[0];
    int profit=-1;
    for(int i=1;i<n;i++){
        if(arr[i]<minPrice){
            minPrice=arr[i];
        }
        profit=max(profit,arr[i]-minPrice);
    }
    return profit;
}

vector<int> rearrangeArray(vector<int>& nums) {
    int pos=0;
    int neg=1;
    int n = nums.size();
    vector<int> resarr(n);
    for(int i=0;i<nums.size();i++){
        if(nums[i]>=0){
            resarr[pos]=nums[i];
            pos+=2;
        }else if(nums[i]<0){
            resarr[neg]=nums[i];
            neg+=2;
        }
    }
    return resarr;
}

void nextPermutation(vector<int>& nums) {
    bool done=false;
    int n=nums.size();
    for(int i=n-1;i>0;i--){
        if(nums[i]>nums[i-1]){
            int temp=nums[i];
            nums[i]=nums[i-1];
            nums[i-1]=temp;
            done=true;
            break;
        }
    }
    if(done==false){
        reverse(nums.begin(),nums.end());
    }
}

vector<int> leaders(vector<int>& nums) {
    vector<int> leader;
    int n = nums.size();
    int max=nums[n-1];
    leader.push_back(max);
    for(int i=n-2;i>0;i--){
        if(max<nums[i]){
            max=nums[i];
            leader.push_back(max);
        }
        
    }
    reverse(leader.begin(),leader.end());
    return leader;
}

int longestConsecutive(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int count=1;
    int maxCount=-1e9;
    int n=nums.size();
    for(int i=1;i<n;i++){
        if(nums[i]-nums[i-1]==1){
            count++;
        }else{
            count=1;
        }
        if(maxCount<count){
            maxCount=count;
        }
    }
    return maxCount;
}

void setZeroes(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n = matrix[0].size();
    int col0=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                if(j!=0)
                    matrix[0][j]=0;
                else
                    col0=0;
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }
    }
    if(matrix[0][0]==0){
        for(int j=0;j<m;j++){
            matrix[0][j]=0;
        }
    }
    if(col0==0){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
        }
    }
}

void rotateMatrix(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n = matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j>i){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> spiral;
    int n=matrix.size()-1;
    int m = matrix[0].size()-1;
    int top=0, bottom=n;
    int right=m, left=0;
    while(top <= bottom && left <= right){
        for(int j=left;j<=right;j++){
            spiral.push_back(matrix[top][j]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            spiral.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int j=right;j>=left;j--){
                spiral.push_back(matrix[bottom][j]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                spiral.push_back(matrix[i][left]);
            }
            left++;
        }
        
    }
    return spiral;
}

int subarraySum(vector<int> &nums, int k){
    int count=0;
    int n=nums.size();
    int prefixSum[n+1]={0};
    prefixSum[0]=0;
    for(int i=1;i<=n;i++){
        prefixSum[i]=prefixSum[i-1]+nums[i-1];
    }
    
    int left=0;
    int right=1;
    while(left<=n && right<=n){
        if(prefixSum[right] - prefixSum[left]==k){
            count++;
            right++;
            
        }else if(prefixSum[right] - prefixSum[left]<k){
            right++;
        }else if(prefixSum[right] - prefixSum[left]>k){
            left++;
            right=left+1;
        }
    }
    return count;
}
int main(){
    // int n1,n2;
    // cin>>n1>>n2;
    int n1, k;
    cin>>n1>>k;
    vector<int> arr1;
    for(int i=0;i<n1;i++){
        int x;
        cin>>x;
        arr1.push_back(x);
    }
    // vector<int> arr2;
    // for(int i=0;i<n2;i++){
    //     int x;
    //     cin>>x;
    //     arr2.push_back(x);
    // }
    
    cout<<subarraySum(arr1,k);
    // leaders(arr1);
    // vector<int> res=leaders(arr1);
    // for(auto v: res){
    //     cout<<v<<" ";
    // }
    // cout<<endl;
    
//     vector<vector<int>> matrix = {
//         {1, 2, 3, 4},
//         {5, 6, 7, 8}
//     };
    
//     vector<int> res=spiralOrder(matrix);

//     for (int val : res) {
//         cout << val << " ";
//     }
//     cout << endl;
}