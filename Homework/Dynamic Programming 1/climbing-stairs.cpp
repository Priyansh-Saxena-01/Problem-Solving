class Solution {
// private:
//     int helper(int n,vector<int>& cache){
//         if(n==0 || n==1) return 1;
//         if(cache[n]!=-1) return cache[n];

//         return cache[n]=helper(n-1,cache)+helper(n-2,cache);
//     }
public:
    int climbStairs(int n) {
        // solution using recursion

        // if( n<0){
        //     return 0;
        // }
        // if(n==0 || n==1) return 1;
        // return climbStairs(n-1)+climbStairs(n-2);

        // using memoization
        // vector<int>cache(n+1,-1);
        // return helper(n,cache);

        // solution using dp with space optimization

        int previous=0,secondPrevious=1,finalSteps=0;
        for(int i=0;i<n;i++){
            finalSteps=previous+secondPrevious;
            previous=secondPrevious;
            secondPrevious=finalSteps;
        }
        return finalSteps;
    }
};