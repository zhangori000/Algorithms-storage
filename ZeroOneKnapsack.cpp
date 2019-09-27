This is the classic & famous knapsack problem : You are a thief carrying a single knapsack with limited (1 <= S <= 2000) capacity. The museum you stole had (1 <= N <= 2000) artifact that you could steal. Unfortunately you might not be able to steal all the artifact because of your limited knapsack capacity.

You have to cherry pick the artifact in order to maximize the total value (<= 2000000) of the artifacts you stole.

Input Format

On the first line you are given T as the test cases available (1 <= T <= 20). The next T testcases will started with two integer S and N. N lines follow with two integers on each line describing each artifact available at the museum. The first number is the weight of the artifact and the next is the value of the artifact.

Output Format

You should output a single integer on one line : the total maximum value from the best choice of artifacts you stole.

Sample Input

1
4 5
1 8
2 4
3 0
2 5
2 3

Sample Output

13

Explanation

The artifact with value 8 and 5 should be picked, summing up the value to the maximum of 13.

//code starts here

//Dynamic programming will be used to solve this problem.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int max(int x, int y)
{
    if(x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin >> t;
    while(t--)
    {
        int s, n;
        cin >> s >> n;
        int weight[n];
        int profit[n];
        int dp[n+1][s+1]; //rows indicate number of items to put in; columns indicate the weight
        for(int i = 0; i < n; i++)
        {
            cin >> weight[i] >> profit[i];
        }
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= s; j++)
            {
                if(i==0 || j == 0)
                {
                    dp[i][j] = 0;  //base case is that when the knapsack weight is 0... u canot put anything in it. 
                    //also wehn i == 0, (n=0 meaning putting zero items in the bag) obviously you have 0 profit.
                }
                else if(weight[i-1] > j)
                {
                  // if the weight of the item to put in is greater than the weight allowed in the knapsack then we will not inlcude the current item
                  //in other words, the profit of NOT putting the item we are currently looking at is the same as the profit
                  //of putting in i-1 items of weight j. 
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                //otherwise we can choose to put it in the knapsack or not (the item)
                //since we want to maximize the profit (hence the max function)
                //if we don't include, like the above if case, the profit would be the same as having i-1 items of j weight
                //if we do include the item, then the the profit would be equal to the profit PLUS the profit of the remaining weight
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i-1]] + profit[i-1]);
                }
            }
        }
        cout << dp[n][s] << endl;
    }
    return 0;
}
