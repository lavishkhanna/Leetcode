class Solution {
public:
    int scoreOfString(string s) {
        cout<<int(s[0])<<endl;

        long long int sum=0;

        for(int i=0;i<s.size()-1;i++){

            sum=sum+int(abs( s[i]-s[i+1]));

        }
        return sum;
    }
};