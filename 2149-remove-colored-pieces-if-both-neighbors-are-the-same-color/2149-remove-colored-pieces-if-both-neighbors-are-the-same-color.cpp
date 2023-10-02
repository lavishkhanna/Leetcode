class Solution {
public:
    bool winnerOfGame(string colors) {
        int count_a=0;
        int count_b=0;
        if(colors.size()<=2){
            return false;
        }

        for(int i=0;i<colors.size()-2;i++){
            string now=colors.substr(i,3);
            cout<<now<<endl;

            if(now=="AAA"){
                count_a++;
            }
            else if(now=="BBB"){
                count_b++;
            }
        }
        cout<<count_a<<" "<<count_b<<endl;

        if(count_a>count_b){
            return true;
        }
        return false;
        
    }
};