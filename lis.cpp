//
// Created by Mihail Plesa on 02.01.2021.
//

#include <iostream>
using namespace std;
int solve_lis(int input[100], int n)
{
    int lis[100]={0};
    lis[0]=1;
    for(int i=1; i<n; i++)
    {
        int max=0;
        for(int j=i-1; j>=0; j--)
        {
            if(input[j]<input[i])
            {
                if(lis[j]>max)
                {
                    max=lis[j];
                }

            }
        }
        lis[i]=max+1;
    }
    int max=1;
    for(int i=0; i<n; i++)
    {
        if(lis[i]>max)
        {
            max=lis[i];
        }
    }
    return max;

}
int main()
{
    int n;
    int input[100]={0};
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    cout<<solve_lis(input, n)<<endl;
}


















































/*
#include <iostream>
#include <time.h>
using namespace std;
int brute_force_lis(int input[100], int n)
{
    cout<<"Problema: "<<n<<endl;
    int max=1;
    for(int i=(n-2); i>=0; i--)
    {
        if(input[i]<input[n-1])
        {
            int tmp=brute_force_lis(input, i+1) + 1;
            if(tmp>max)
            {
                max=tmp;
            }
        }
    }
    return max;
}
int dp_lis(int input[100], int n, int dp[100])
{
    if(dp[n-1]!=0)
    {
        return dp[n-1];
    }
    int max=1;
    for(int i=(n-2); i>=0; i--)
    {
        if(input[i]<input[n-1])
        {
            int tmp=dp_lis(input, i+1, dp) + 1;
            if(tmp>max)
            {
                max=tmp;
            }
        }
    }
    dp[n-1]=max;
    return max;

}
void run()
{
    int input[100]={0};
    for(int n=1; n<100; n++)
    {
        int dp[100]={0};
        for(int j=0; j<n; j++)
        {
            input[j]=j;
        }
        clock_t begin = clock();
        int rez=brute_force_lis(input, n);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        cout<<"Input:"<<endl;
        cout<<"n="<<n<<endl;
        for(int j=0; j<n; j++)
        {
            cout<<input[j]<<" ";
        }
        cout<<endl;
        cout<<"Lungimea lis: "<<rez<<endl;
        cout<<"Timp de executie: "<<time_spent<<" secunde"<<endl;
        cout<<endl;

    }
}
int main()
{

    int input[100]={0};
    input[0]=50;
    input[1]=3;
    input[2]=10;
    input[3]=7;
    input[4]=40;
    input[5]=80;
    cout<<brute_force_lis(input, 6)<<endl;
    //run();
}
*/
