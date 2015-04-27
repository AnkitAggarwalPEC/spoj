#include<iostream>
#include<vector>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include <queue>
#include<map>
#include<math.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector <ii> vii;
#define repj(j,a,b) for(int j=(int)a;j<int(b);j++)
#define rep(i,a,b) for( long long int i=(long long int)a;i<(long long int )(b);i++)
#define inf 10000000
#define mo 1000000000
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define trvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define si(a) scanf("%d",&a)
#define sli(a) scanf("%lld",&a)
typedef long long int lli;
#define gc getchar_unlocked
int inline  gcd(int a,int b)
{   if(b>a) return gcd(b,a);
    if(b==0) return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{   int k=gcd(a,b);a/=k;
    return a*b;
}
inline int mid(int a, int b)
{
    return a + (b-a)/2;
}

#define pc(x) putchar_unlocked(x);
inline void writeInt (int n)
{
    int N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}
string ip()
{
    string i="";
    int temp=getchar_unlocked();
    while(temp<'a'||temp>'z')
    temp=getchar_unlocked();
    while(temp>='a'&&temp<='z')
    {
      i+=(char)temp;
        temp=getchar_unlocked();
    }
    return i;
}
void inline input(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc())
    {   x = (x<<1) + (x<<3) + c - 48;}
}
int mypow( int base, int pow, int mod ){
    if( pow == 0 ) return 1;
    if( pow % 2 == 0 ){
        int tmp = mypow( base, pow >> 1, mod );
        return tmp * tmp % mod;
    }
    else
    {
        return base * mypow( base, pow - 1, mod ) % mod;
    }
}
int dp[1000][1000];
int arr[1000][3];

int solve(int k , int index , int n)
{
}
int main()
{
    int t;input(t);
    while(t--)
    {
        int n;input(n);
        memset(dp , 0 , sizeof(dp));
        memset( arr, 0 ,sizeof(arr));
        rep(i, 0, n)
        {
            input(arr[i][0]);input(arr[i][1]);input(arr[i][2]);
        }
        dp[0][0] = arr[0][0];dp[0][1] = arr[0][1];dp[0][2] = arr[0][2];
        solve(1 , 0, n );
        //cout<<"array"<<endl;
        rep( i , 1 ,n)
        {
            arr[i][0] = arr[i][0] + min(arr[i-1][1] , arr[i-1][2]);
            arr[i][1] = arr[i][1] + min(arr[i-1][0] , arr[i-1][2]);
            arr[i][2] = arr[i][2] + min(arr[i-1][1] , arr[i-1][0]);

        }
        /*rep(i,0,n)
        {
            repj(j,0,3) cout<<arr[i][j]<< " ";
            cout<<endl;
        }*/
        int ans = min(arr[n-1][0] ,min(arr[n-1][1] ,arr[n-1][2]));
        writeInt(ans);putchar_unlocked('\n'); 
    }
    return 0;
}