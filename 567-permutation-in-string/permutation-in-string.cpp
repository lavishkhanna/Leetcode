class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> omap(26, 0);
        vector<int> omap2(26, 0);

        
        for (int i = 0; i < s1.size(); i++) {
            omap[s1[i] - 'a']++;
            omap2[s2[i] - 'a']++;
        }

        for (int i = 0; i <= s2.size() - s1.size(); i++) {
            if (omap == omap2) {
                return true;
            }

            
            if (i + s1.size() < s2.size()) {
                omap2[s2[i] - 'a']--;
                omap2[s2[i + s1.size()] - 'a']++;
            }
        }

        return false;
    }
};


// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {

//         if(s1.size()>s2.size()){
//             return false;
//         }

//         map<char,int>omap;
//         map<char,int>omap2;

//         for(int i=0;i<26;i++){
//             char c=i+97;
//             omap[c]=0;
//             omap2[c]=0;
//         }

//         for(int i=0;i<s1.size();i++){
//             omap[s1[i]]++;
//         }

//         for(int i=0;i<s1.size();i++){
//             omap2[s2[i]]++;
//         }

//         for(int i=0;i<=s2.size()-s1.size();i++){
//             if(i==0){
//                 map<char,int>::iterator it1=omap.begin();
//                 map<char,int>::iterator it2=omap2.begin();
//                 int count=0;
//                 while(it1!=omap.end() && it2!=omap2.end()){
//                     if(it1->second==it2->second){
//                         count++;
//                     }
//                     it1++;
//                     it2++;
//                 }
//                 if(count==26){
//                     return true;
//                 }
//             }

//             omap2[s2[i-1]]--;

//             omap2[s2[i+s1.size()-1]]++;

//             map<char,int>::iterator it1=omap.begin();
//             map<char,int>::iterator it2=omap2.begin();
//             int count=0;
//             while(it1!=omap.end() && it2!=omap2.end()){
//                 if(it1->second==it2->second){
//                     count++;
//                 }
//                 it1++;
//                 it2++;
//             }
//             if(count==26){
//                 return true;
//             }

            

//         }
//         return false;
//     }
// };