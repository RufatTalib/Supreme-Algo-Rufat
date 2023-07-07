/*
    I was inspired by Hackerrank's "Beautiful Triplet Problem" when designing this method.
    This is a more general case of the problem.
*/

#include <bits/stdc++.h>

using namespace std;

int beautifulKtets(int k, int differences, vector<int> a) {
    int res = 0;
    int n = a.size();
    int counts[k], temp, i, nCount, bindex;
    
    while(n > k-1)
    {
        i = nCount = bindex = 0;
        for (int cnt_i = 0; cnt_i < k; cnt_i++) counts[cnt_i] = 0;
        
        temp = a[i];
        
        for(; i < n; i++)
        {
            if(a[i] == temp)
                counts[bindex]++;
            else if(a[i] - temp == differences)
            {
                if(bindex == k-1)
                {
                    int product = counts[0];
                    for (int cnt_i = 1; cnt_i < k; cnt_i++) product *= counts[cnt_i];                    
                    res += product;
                    for (int cnt_i = 1; cnt_i < k; cnt_i++)
                    {
                        counts[cnt_i-1] = counts[cnt_i];
                        if(cnt_i == k-1)
                            counts[cnt_i] = 1;
                    }
                }
                else
                    counts[++bindex] = 1;
                
                temp = a[i];
            }
            else
                a[nCount++] = a[i];
        }

        int product = counts[0];
        for (int cnt_i = 1; cnt_i < k; cnt_i++) product *= counts[cnt_i];                    
        res += product;

        if(n == nCount)
            break;

        n = nCount;
    }
    
    return res;
}



int main()
{
    int n, k, d;
    vector<int> arr;

    cin >> n >> k >> d;

    for (int i = 0; i < n; i++)
    {
        int _in;
        cin >> _in;
        arr.push_back(_in);
    }

    cout << "Result --> " << beautifulKtets(k,d,arr);
    
    



    return 0;
}

