class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string start_ = to_string(start-1), finish_ = to_string(finish);

        return calculate(finish_, s, limit)-calculate(start_, s, limit);
    }

    long long calculate(string num, string s, int limit){
        // it will find powerful number less than or equal num

        if(num.length()<s.length())
            return 0;

        if(num.length()==s.length()){
            return num >= s ? 1 : 0;
        }

        string s_ = num.substr(num.length() - s.length(), s.length());
        //it is the suffix of num of length of s.length

        long long ans = 0;
        int n = num.length() - s.length();

        for (int i = 0; i < n;i++){
            if(limit<(num[i]-'0')){
                ans+=(long)pow(limit+1, n-i);
                return ans;
                //if current digit is larger than limit then we can take all combinations with limit+1 (including 0) digits
            }
            ans += (long)(num[i] - '0') * (long)pow(limit + 1, n - 1 - i);
            //0 to num[i]-1 have no problem with rest of digits [0->limit]
            //for num[i] we need to check the rest of digits to ensure all combinations do not exceed the num

        }
        if(s_>=s)
            ans++;
        return ans;
    }
};
//class Solution {
//public:
//    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
//        int l = s.length();
//        int suffix = stoi(s);    
//        int step = pow(10,l);
//        vector<int> res;
//        int curr = suffix;
//        while(curr <= finish) {
//            for (int i = 0; i < limit; i++) {
//    
//            }
//        }
//        return ans;
//    }
//};