#include <bits/stdc++.h>
using namespace std;

    int findPeak(vector<int> &nums, int mid, int k){
        if(mid==nums.size()-1) return 0;
        return (nums[mid]>=nums[mid+1]);
    }
    
    template<typename CheckFunc>
    int binarySearch(vector<int> nums, int k, CheckFunc check){
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(nums,mid,k)==1){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    
    vector<int> sortedArray(vector<int> &nums, int k){
        int peak = binarySearch(nums,k,findPeak);
        int n=nums.size();
        vector<int> rotated(n);
        for(int i=0;i<n;i++){
            rotated[(i+n-peak-1)%n]=nums[i];
        }
        return rotated;
    }
//================================================================================================================================
    int search(vector<int> &nums, int target){
        int low =0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(target<nums[mid]){
                high=mid-1;
            }else if(target>nums[mid]){
                low=mid+1;
            }else{
                return mid;
            }
        }
        return -1;
    }
    
    int lowerBound(vector<int> &nums, int x){
        int low =0;
        int high = nums.size()-1;
        int ans= nums.size();
        while(low<=high){
            int mid = low+(high-low)/2;
            if(x<=nums[mid]){
                ans=mid;
                high=mid-1;
            }else if(x>nums[mid]){
                low=mid+1;
            }
        }
        return ans;        
    }
    
    int upperBound(vector<int> &nums, int x){
        int low =0;
        int high = nums.size()-1;
        int ans= nums.size();
        while(low<=high){
            int mid = low+(high-low)/2;
            if(x<nums[mid]){
                ans=mid;
                high=mid-1;
            }else if(x>=nums[mid]){
                low=mid+1;
            }
        }
        return ans; 
    }
    
    int searchInsert(vector<int> &nums, int target)  {
       int low=0;
       int high=nums.size()-1;
       int ans=nums.size();
       while(low<=high){
           int mid = low+(high-low)/2;
           if(target<=nums[mid]){
               ans=mid;
               high=mid-1;
           }else if(target>nums[mid]){
               low=mid+1;
           }
       }
       return ans;
    }
    
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int low=0;
       int high=nums.size()-1;
       int ceilNo=-1;
       while(low<=high){
           int mid = low+(high-low)/2;
           if(x<=nums[mid]){
               ceilNo=mid;
               high=mid-1;
           }else if(x>nums[mid]){
               low=mid+1;
           }
       }
        low=0;
        high=nums.size()-1;
        int floorNo=-1;
        while(low<=high){
           int mid = low+(high-low)/2;
           if(x<nums[mid]){
               high=mid-1;
           }else if(x>=nums[mid]){
               floorNo=mid;
               low=mid+1;
           }
       }
       return {nums[floorNo],nums[ceilNo]};
    }
    
    vector<int> searchRange(vector<int> &nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int start = -1;
        int end = -1;
        while(low<=high){
           int mid = low+(high-low)/2;
           if(nums[mid]==target){
                start=mid;
                high=mid-1;
           }else if(target<nums[mid]){
               high=mid-1;
           }else if(target>nums[mid]){
               low=mid+1;
           }
        }
        low=0;
        high=nums.size()-1;
        while(low<=high){
           int mid = low+(high-low)/2;
           if(nums[mid]==target){
                end=mid;
                low=mid+1;
           }else if(target<nums[mid]){
               high=mid-1;
           }else if(target>nums[mid]){
               low=mid+1;
           }
        }
        return {start,end};
    }
    
    int countOccurrences(vector<int>& arr, int target) {
        int low=0;
        int high=arr.size()-1;
        int start = -1;
        int end = -1;
        while(low<=high){
           int mid = low+(high-low)/2;
           if(arr[mid]==target){
                start=mid;
                high=mid-1;
           }else if(target<arr[mid]){
               high=mid-1;
           }else if(target>arr[mid]){
               low=mid+1;
           }
        }
        low=0;
        high=arr.size()-1;
        while(low<=high){
           int mid = low+(high-low)/2;
           if(arr[mid]==target){
                end=mid;
                low=mid+1;
           }else if(target<arr[mid]){
               high=mid-1;
           }else if(target>arr[mid]){
               low=mid+1;
           }
        }
        return end-start+1;
    }
    
    int search1(vector<int> &nums, int k) {
       int low=0;
       int high=nums.size()-1;
       while(low<=high){
           int mid=low+(high-low)/2;
           
           if(nums[mid]==k){
               return mid;
           }
           //left half sorted
           if(nums[low]<=nums[mid]){
               //if target element lies in left half
               if(nums[low]<=k && k<=nums[mid]){
                   high=mid-1;
               }else{
                   low=mid+1;
               }
               
           }else{  //right half sorted
                //if target element lies in right half
               if(nums[mid]<=k && k<=nums[high]){
                   low=mid+1;
               }else{
                   high=mid-1;
               }
           }
       }
       return -1;
    }
    
    bool searchInARotatedSortedArrayII(vector<int> &nums, int k)  {
      int low=0;
       int high=nums.size()-1;
       while(low<=high){
           int mid=low+(high-low)/2;
           
           if(nums[mid]==k){
               return 1;
           }
           if(nums[mid]==nums[low] && nums[mid]==nums[high]){
               low++;
               high--;
               continue;
           }
           //left half sorted
           if(nums[low]<=nums[mid]){
               //if target element lies in left half
               if(nums[low]<=k && k<=nums[mid]){
                   high=mid-1;
               }else{
                   low=mid+1;
               }
               
           }else{  //right half sorted
                //if target element lies in right half
               if(nums[mid]<=k && k<=nums[high]){
                   low=mid+1;
               }else{
                   high=mid-1;
               }
           }
       }
       return 0;
    }
    
    int findMin(vector<int> &arr)  {
        int low=0;
        int high=arr.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid==arr.size()-1) return arr[0];
            if(arr[mid]>arr[mid+1]){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return arr[ans+1];
    }
    
    int findKRotation(vector<int> &nums)  {
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid==nums.size()-1) return 0;
            if(nums[mid]>nums[mid+1]){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans+1;
    }
    
    int singleNonDuplicate(vector<int> &nums) {
        int low=1;
        int high=nums.size()-2;
        if(nums[0]!=nums[1])return nums[0];
        if(nums[high+1]!=nums[high]) return nums[high+1];
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if(mid%2==1 && nums[mid]==nums[mid-1] || mid%2==0 && nums[mid]==nums[mid+1]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return -1;
    }
    
    int findPeakElement(vector<int> &arr) {
        int low=0;
        int high=arr.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid==arr.size()-1) return -1;
            if(arr[mid]>arr[mid+1]){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
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
        vector<int> arr = {1, 1, 3, 5, 5}; //31
        // vector<int> res=sortedArray(arr, 6);
        // for(auto v:res){
        //     cout<<v<<" ";
        // }

        int a = singleNonDuplicate(arr);
        cout<<a<<endl;
        // vector<vector<int>> b = {{1,5},{3,6},{6,10},{15,18}};
        // vector<vector<int>> res = mergeOverlap(b);
        
        // for (auto row : pascals) {
        //         cout << "[" << row[0] << "," << row[1] << "] ";
        // }

        // int target=5;
        // vector<vector<int>> res = fourSum(arr,target);
    
        // for (auto &triplet : b) {
        //     for (auto &num : triplet) cout << num << " ";
        //     cout << endl;
        // }
        // pascal();
        // for (auto &row : pascals) {
        //     for (auto &val : row) cout << val << " ";
        //     cout << endl;
        // }
    }