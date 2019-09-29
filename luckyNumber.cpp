/* given integer l and r, find a digit x such that no digits in x are the same, yet x is between l and r inclusive */

#include<bits/stdc++.h>
using namespace std;
 
 
int isLucky(int x);
bool answer(int start, int end);
int main()
{
    bool dontprint = false;
    int l, r;
    cin >> l >> r;
    
    for(int i = l; i <= r; i++)
    {
        if(isLucky(i))
        {
            cout << isLucky(i) << endl;
            dontprint = true;
            break;
        }
    }
    if(!dontprint){
        cout << -1 << endl;
    }
    
    
}
 
 
 
int isLucky(int x)
{
    bool arr[10];
    int digitCreated = 0;
    int counter = 0;
    for(int i = 0; i < 10; i++)
    {
        arr[i] = false;   
    }
    while(x > 0)
    {
        int digit = x % 10;
        if(arr[digit])
        {
            return 0;
        }
        else
        {
            arr[digit] = true;
            digitCreated = digitCreated + digit * pow(10, counter);
            counter++;
        }
        x/=10;
    }
    return digitCreated;
}
