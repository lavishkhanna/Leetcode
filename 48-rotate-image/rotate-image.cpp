class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(i>j){
                    continue;
                }
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        for(int i=0;i<matrix.size();i++){

            int st=0;
            int lt=matrix[i].size()-1;
            while(st<lt){
                int temp=matrix[i][st];
                matrix[i][st]=matrix[i][lt];
                matrix[i][lt]=temp;
                st++;
                lt--;
            }

        }
    }
};