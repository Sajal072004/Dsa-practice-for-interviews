class Solution {

    long long vectorToNumber(vector<int>&num){
        long long ans = 0;
        for(int digit : num){
            ans = ans*10 + digit;
        }
        return ans;
    }

    long long fact(int n){
        long long ans = 1;
        for(int i = 2; i<=n; i++) ans*=i;
        return ans;
    }

    long long Total_Permutations(map<int,int>&freq , int n){
        long long totalPermutations = fact(n);
        for(auto it : freq){
            totalPermutations/=fact(it.second);
        }
        return totalPermutations;
    }

    long long PermutationsStartingWithZero(map<int,int>freq , int n){
        if(freq.find(0) == freq.end() || freq[0] == 0) return 0;
        freq[0]--;

        long long permutationWithZero = fact(n-1);
        for(auto i : freq) permutationWithZero /= fact(i.second);
        return permutationWithZero;
    }

    long long calc(map<int,int>&freq , int n){
        long long a = Total_Permutations(freq,n);
        long long b = PermutationsStartingWithZero(freq,n);
        return a-b;
    }



public:

    long long ans  = 0;
    set<map<int,int>>vis;

    void generatePalindrome(vector<int>&num , int l, int r , int k , int n){
        if(l > r){
            long long pali = vectorToNumber(num);
            if(pali % k == 0){
                map<int,int>m;
                while(pali){
                    m[pali%10]++;
                    pali/=10;
                }
                if(vis.find(m) == vis.end()){
                    ans += calc(m,n);
                    vis.insert(m);
                }
            }
            return;
        }

        for(int digit = (l == 0) ? 1 : 0; digit <=9; digit++){
            num[l] = num[r] = digit;
            generatePalindrome(num , l+1 , r - 1 , k , n);
        }
    }


    long long countGoodIntegers(int n, int k) {
        vector<int>num(n,0);
        generatePalindrome(num,0,n-1, k,n);
        return ans;
    }
};