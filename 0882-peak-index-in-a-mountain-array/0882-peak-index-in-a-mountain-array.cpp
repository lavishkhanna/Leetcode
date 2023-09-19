class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ind=0;
        int max=arr[0];

        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]>arr[i+1]){
                if(arr[i]>max){
                    max=arr[i];
                    ind=i;
                }
            }
        }
        return ind;
    }
};