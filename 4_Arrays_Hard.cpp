#include <bits/stdc++.h>
using namespace std;

    vector<vector<int>> pascals;
    void pascal(){
        pascals.resize(31);
        for(int i=0;i<30;i++){
            pascals[i].resize(i+1);
            
            pascals[i][0] = 1;
            pascals[i][i] = 1;
    
            for(int j=1;j<i;j++){
                pascals[i][j]=pascals[i-1][j]+pascals[i-1][j-1];
            }
        }
    }
    
    int pascalTriangleI(int r, int c) {
        pascal();
        return pascals[r-1][c-1];
    }
    
    long long findPascalElement(int r, int c) {
        // Element is C(r-1, c-1)
        int n = r - 1;
        int k = c - 1;

        long long result = 1;
        // 1.2.3....r-1
        // 1.2.3....c-1 * 1.2.3...r-c
        // Compute C(n, k) using iterative formula
        for (int i = 0; i < k; i++) {
            result *= (n - i);
            result /= (i + 1);
        }

        return result;
    }
    
    vector<int> majorityElementTwo(vector<int>& nums) {
        int n = nums.size();
        int t = n/3 ;
        int count1=0,count2=0;
        int ele1=-1e9,ele2=-1e9;
        vector<int> majorityElements;
        for(int i=0;i<n;i++){
            if(count1==0 && nums[i]!=ele2){
                ele1 = nums[i];
                count1=1;
            }else if(count2==0 && nums[i]!=ele1){
                ele2=nums[i];
                count2=1;
            }else if(nums[i]==ele1) count1++;
            else if(nums[i]==ele2) count2++;
            else{
                count2--;
                count1--;
            }
        }
        if(count1>=t)majorityElements.push_back(ele1);
        if(count2>=t && ele1!=ele2)majorityElements.push_back(ele2);
        return majorityElements;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> threeSum;
        int n=nums.size();
        sort(nums.begin(), nums.end()); //sort the array first
        for(int i=0;i<n;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue; //handling duplicates
            int left=i+1;
            int right=n-1;
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum==0){
                    threeSum.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++; //handling duplicates
                    while (left < right && nums[right] == nums[right + 1]) right--; //handling duplicates
                }else if(sum>0) right--;
                else if(sum<0) left++;
            }
        }
        return threeSum;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> fourSum;
        int n=nums.size();
        sort(nums.begin(), nums.end()); //sort the array first
        for(int j=0;j<n;j++){
            if (j > 0 && nums[j] == nums[j - 1]) continue; //handling duplicates
            for(int i=j+1;i<n;i++){
                if (i > j + 1 && nums[i] == nums[i - 1]) continue;
                int left=i+1;
                int right=n-1;
                while(left<right){
                    int sum = nums[i] + nums[left] + nums[right]+nums[j];
                    if(sum==target){
                        fourSum.push_back({nums[j],nums[i],nums[left],nums[right]});
                        while (left < right && nums[left] == nums[left - 1]) left++; //handling duplicates
                        while (left < right && nums[right] == nums[right + 1]) right--; //handling duplicates
                        left++;
                        right--;
                    }else if(sum>target) right--;
                    else if(sum<target) left++;
                }
            }
        }
        return fourSum;
    }
    
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixSum(n);
        prefixSum[0]=arr[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+arr[i];
        }
        int maxAns=0;
        for(int left=0;left<n;left++){
            int right=n-1;
            while(left<right){
                if(prefixSum[left]==prefixSum[right]){
                    maxAns=max(maxAns,right-left);
                }
                right--;
            }
        }
        return maxAns;
    }
    
    int maxLen(int A[], int n) {
      unordered_map<int, int> mpp;
      int maxi = 0;
      int sum = 0;
    
      for (int i = 0; i < n; i++) {
        sum += A[i];
    
        // if sum is zero, subarray [0..i] has zero sum
        if (sum == 0) {
          // update best length
          maxi = i + 1;
        }
        // otherwise check if this sum was seen before
        else {
          // when seen, zero-sum segment between previous index + 1 and i
          if (mpp.find(sum) != mpp.end()) {
            // maximize length
            maxi = max(maxi, i - mpp[sum]);
          }
          // first time seeing this sum
          else {
            // record index
            mpp[sum] = i;
          }
        }
      }
    
      return maxi;
    }
    
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0]=1;
        int count=0;
        int prefixXOR=0;
        
        for(int v:nums){
            prefixXOR^=v; // Update prefix XOR
            int target=prefixXOR^k; // Compute required XOR
            // If target exists in map, add
            if (mpp.find(target) != mpp.end()) {
                count += mpp[target];
            }

            // Store current prefix XOR in map
            mpp[prefixXOR]++;
        }
        return count;
    }
    
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> merge;
        merge.push_back({arr[0][0],arr[0][1]});
        for(int i=1;i<arr.size();i++){
            if(arr[i][0]<=merge.back()[1]){
                merge.back()[1]=arr[i][1];
            }else{
                merge.push_back({arr[i][0],arr[i][1]});
            }
        }
        return merge;
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1, k=m+n-1;
        while(j>=0 && i>=0){
            if(nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }else if(nums1[i]<nums2[j]){
                nums1[k--]=nums2[j--];
            }
        }
        while(j>=0){
            nums1[k--] = nums2[j--];
        }
    }
    
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();
        int xr=0;
        for(int i=0;i<n;i++){
            xr=xr^nums[i];
            xr=xr^(i+1);
        }
        // 6(110) 5(101) => 110 & ~(101)= 110&010= 010 i.e. 2nd bit is different in duplicate and missing numbers 
        int differentiatingBit = xr & ~(xr-1); 
        
        int zero=0;
        int one=0;
        for(int i=0;i<n;i++){
            if(nums[i] & differentiatingBit != 0 ){
                one=one^nums[i];
            }else{
                zero=zero^nums[i];
            }
        }
        for(int i=1;i<=n;i++){
            if(i & differentiatingBit != 0 ){
                one=one^i;
            }else{
                zero=zero^i;
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==zero)cnt++;
        }
        if(cnt==2){
            return {zero,one};
        }else{
            return {one,zero};
        }
        
    }
    
    
    long long int merge(vector<int> &nums, int low, int mid, int high){
        vector<int> temp;
        int left=low;
        int right=mid+1;
        long long int count=0;
        while(left<=mid && right<=high){
            if(nums[left]>nums[right]){
                count+=mid-left+1;   //for counting numberOfInversions
                temp.push_back(nums[right]);
                right++;
            }else{
                temp.push_back(nums[left]);
                left++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for (int i = low; i <= high; i++)
            nums[i] = temp[i - low];
        
        return count;
    }
    long long int mergeSort(vector<int>& nums, int low, int high) {
        long long int cnt=0;
        if(low>=high)return cnt;
        int mid = low+(high-low)/2;
        cnt+=mergeSort(nums, low, mid);
        cnt+=mergeSort(nums, mid+1, high);
        cnt+=merge(nums, low, mid, high);
        return cnt;
    }
    long long int numberOfInversions(vector<int> nums) {
        int n = nums.size();
        return mergeSort(nums,0,n-1);
    }
    
    
    void mergeInversion(vector<int> &nums, int low, int mid, int high){
        vector<int> temp;
        int left=low;
        int right=mid+1;
        long long int count=0;
        while(left<=mid && right<=high){
            if(nums[left]>nums[right]){
                temp.push_back(nums[right]);
                right++;
            }else{
                temp.push_back(nums[left]);
                left++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for (int i = low; i <= high; i++)
            nums[i] = temp[i - low];
        
    }
    long long int countPairs(vector<int>& nums, int low, int mid, int high){
        long long int cnt=0;
        int right=mid+1;
        for(int i=low;i<mid+1;i++){
            while(right<=high && nums[i]>2*nums[right])right++;
            cnt+=right-mid-1;
        }
        return cnt;
    }
    long long int mergeSortInversion(vector<int>& nums, int low, int high) {
        long long int cnt=0;
        if(low>=high)return cnt;
        int mid = low+(high-low)/2;
        cnt+=mergeSortInversion(nums, low, mid);
        cnt+=mergeSortInversion(nums, mid+1, high);
        cnt+=countPairs(nums, low, mid, high);
        mergeInversion(nums, low, mid, high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSortInversion(nums,0,n-1);
    }
    
    int maxProductSubArray(vector<int>& arr) {
        int n = arr.size();
        int pre = 1, suff = 1;
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (pre == 0) pre = 1;
            if (suff == 0) suff = 1;
            pre *= arr[i];
            suff *= arr[n - i - 1];
            ans = max(ans, max(pre, suff));
        }
        return ans;
    }
    
    int main(){
        // int n1, k;
        // cin>>n1;
        // vector<int> arr1;
        // for(int i=0;i<n1;i++){
        //     int x;
        //     cin>>x;
        //     arr1.push_back(x);
        // }
        vector<int> arr = {6, -4, 1, 2, 7}; //31
        // vector<int> res=findMissingRepeatingNumbers(arr);
        // for(auto v:res){
        //     cout<<v<<" ";
        // }

        long long int a = maxProductSubArray(arr);
        cout<<a<<endl;
        // vector<vector<int>> b = {{1,5},{3,6},{6,10},{15,18}};
        // vector<vector<int>> res = mergeOverlap(b);
        
        // for (auto row : res) {
        //         cout << "[" << row[0] << "," << row[1] << "] ";
        // }

        // int target=5;
        // vector<vector<int>> res = fourSum(arr,target);
    
        // for (auto &triplet : b) {
        //     for (auto &num : triplet) cout << num << " ";
        //     cout << endl;
        // }
    
    }