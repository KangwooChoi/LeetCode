class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        int n=words.size();
        vector<string> ans(n);
        vector<int> prefix(n);
        for(int i=0;i<n;i++){
            ans[i]=abbreviation(words[i],0);
        }
        for(int i=0;i<n;i++){
            while(true){
                set<int>s;
                for(int j=i+1;j<n;j++){
                    if(ans[i]==ans[j]){
                        s.insert(j);
                    }
                }
                if(s.empty()){
                    break;
                }
                s.insert(i);
                for(auto&k:s){
                    ans[k]=abbreviation(words[k],prefix[k]++);
                }
            }
        }
        return ans;
    }
    
    string abbreviation(string word, int i){
        int n=word.size();
        if(n-i<=3){//like : god
            return word;
        }//like = n-i-2
        return word.substr(0,i+1)+to_string(n-i-2)+word[n-1];
    }
};