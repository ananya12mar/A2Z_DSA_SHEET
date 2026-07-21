int numberOfOnes(vector<int> a){
    int low=0;
    int high=a.size();
    int n = a.size();
    int ans=-1;
    while(low<=high){
        int mid =low+(high-low)/2;
        if(a[mid]==1){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    if(ans>=0) return n-ans;
    return -1;
}
int rowWithMax1s(vector < vector < int >> & mat) {
    int maxi=INT_MIN;
    int idx=-1;
    for(int i=0;i<mat[0].size();i++){
        int num = numberOfOnes(mat[i]);
        if(maxi<num){
            idx=i;
            maxi=num;
        }
    }
    if(maxi==-1) return -1;
    return idx;
}