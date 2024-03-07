class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        

        int low_m=0;
        int high_m=matrix.size()-1;


        while(low_m<=high_m){


            int mid_m=(low_m+high_m)/2;

            if( matrix[mid_m][0]==target ){
                low_m=mid_m+1;
                break;
            }



            if(target > matrix[mid_m][0]){
                low_m=mid_m+1;
            }
            else{
                high_m=mid_m-1;
            }
        }

        cout<<low_m-1<<endl;
        // low_m--;

        int low_n = 0;
        int high_n = 0;

        if (low_m != 0) {
            high_n = matrix[low_m - 1].size() - 1;
            low_m--;
        } else {
            high_n = matrix[low_m].size() - 1;
        }

        

        

        while(low_n<=high_n){


            int mid=(low_n+high_n)/2;

            if( matrix[low_m][mid]==target ){
                return true;
            }

            if( target > matrix[low_m][mid] ){
                low_n=mid+1;
            }
            else{
                high_n=mid-1;
            }
        }

        return false;


    }
};