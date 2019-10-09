/*
tutoral for beginners.

given a rod of length n, and a profit array that tells you how much a rod of length k sells for (k is anything between 1 and n), 
determine the best way to cut up the rod to maximize profit
*/

/* we can consider a naive solution by finding the max of different tasks
  for example, in a rod of n = 1, we can say the max profit is either p1 (profit of rod n = 1) + r0 (revenue of the REMAINING)
  r0 in our case would be 0, that can be a base case.
  in a rod of n=2, we can say profit is the max of itehr taking the profit of n = 1, + revenue of remaining (1), and also
  consider taking profit of n = 2 (the length of rod) with the remaining (which obvously would be 0). 
  So a time consuming recursive approach is available to us*/
  
#include<bits/stdc++.h>
using namespace std;

int cut_rod(int p[], int n);
int main() {
	// your code goes here
	int arr[4] = {1,5,8,9};
	int n = 4;
	cout << cut_rod(arr, n) << endl;
	return 0;
}
int cut_rod(int p[], int n)
{
    if (n == 0) {
        return 0;
    }
    int q = INT_MIN; //this way the first comparisno won't need an edge case
    // profit[length 1, 2, .. n] + the remaining of length-i
    for(int i = 0; i < n; i++)
    {
        q = max(q, p[i] + cut_rod(p, n-i-1));
    }
    return q;
}
//this is super inefficient because you're callig cut_rod over and voer again, this is the essense that dp solves

//hint: make a recursion tree and you realize that you are computing the same values over and voer again. It is almost 2^n expn time.
// instead of recomputing the function, just sotre the value of the function in some kind of array. 
//this type of solution where tis simple recursion with memorizing values is called top down with memoization. 
//now there is another method: bottom up
// bottom up is basically solving subproblems that rely on "smaller" problems. Solve the "smallest first" and work our way up. 

#include<bits/stdc++.h>

using namespace std;

void show(int arr[], int n);
int memoized_cut_rod(int p[], int n); //main call of function, will return answer
int auxillery(int p[], int n, int r[]); //helper method to fill the revenue arrays
int main() {
	
	int test1[4] = {1,5,8,9};
	int n1 = 4;
	int test2[1] = {1};
	int n2 = 1;
	cout << memoized_cut_rod(test1, n1) << endl;
	//cout << memoized_cut_rod(test2, n2) << endl;
	return 0;
}
int memoized_cut_rod(int p[], int n) {
    
    int r[n+1]; //n+1 because r[0] is equal to 0. we need space to store the 0
    for(int i = 0; i <= n; i++)
    {
        r[i] = INT_MIN;
    }
    
    return auxillery(p, n, r);
    
}
int auxillery(int p[], int n, int r[]) 
{
    int q = 0;
    if(r[n] >= 0) 
    {
        return r[n];
    }
    if(n == 0)
    {
        q = 0;
    }
    else
    {
        q = INT_MIN;
        for(int i = 1; i <= n; i++)
        {
            q = max(q, p[i-1] + auxillery(p, n-i, r));
        }
    }
    r[n] = q;
    return q;
}

//bottom up approach:
 #include<bits/stdc++.h>
using namespace std;

int bottomup_cut_rod(int p[], int n);
int main()
{
    int temp1[4] = {1,5,8,9};
    int n1 = 4;
    //int temp2[1] = {1};
    //int n2 = 1;
    cout << bottomup_cut_rod(temp1, n1) << endl;
    return 0;
}

/* outer for loop variable i represents current size:
    for size n = 1: whats the max revenue, and then size n = 2, whats the max revenue, all the way until n
    and the j in this case would be the calulcatio for max revenue, since there are diff combos
    The bottom up approach basically does this. base case is r0 is 0 rihgt?
    now how do we get r1? we need r0. how do we get r2. we need r1. which is solved. r3? we need r2. and on and on.
    
    PAY attention to the i's and j's common mistake is for people to mess these values up or not know the meaning of them. 
    */
int bottomup_cut_rod(int p[], int n)
{
    int r[n+1]; //remmeber the r0 case makes our size n+1 instead of n 
    r[0] = 0; //this is our base case.
    for(int i = 1; i <= n; i++) //the i in this case will be the temporary size.
    {
        int q = INT_MIN;
        for(int j = 1; j <= i; j++) //calculates maximum revenue.. make sure j <= i not n: common mistake
        {
            q = max(q, p[j-1] + r[i-j]);
            printf("profit of length %d and max remaining of %d\n", i, i-j);
        }
        r[i] = q; //store the max revenue for size i in this array 
        
    }
    for(int i = 0; i < n; i++)
    {
        cout << r[i] << endl;
    }
    return r[n];
}









