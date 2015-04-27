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
#define rep(i,a,b) for( int i=(int)a;i<(int )(b);i++)
#define inf 10000000
#define mo 1000000000
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define trvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define si(a) scanf("%d",&a)
#define sli(a) scanf("%lld",&a)
typedef long long int lli;
#define gc getchar
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

#define pc(x) putchar(x);
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
    int temp=getchar();
    while(temp<'a'||temp>'z')
    temp=getchar();
    while(temp>='a'&&temp<='z')
    {
      i+=(char)temp;
        temp=getchar();
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
#define pb push_back
int main()
{
 
    int c = 1;
    while(1)
    {
        
        int mon;
        cin>>mon;
        if( mon == 0) break; 
        int esal , wsal, ssal;cin>>esal>>wsal>>ssal;
        int m = 0;
        int arr[mon+2];
        rep( i ,1 ,mon+1)
        {
            cin>>arr[i];
            m = max(m , arr[i]);
        }
        lli dp[26][37];
        rep( i, 0,26) rep( j , 0, 36) dp[i][j] = inf;
        rep( i, arr[1] , m+1)
        {
            int to_pay = (wsal + esal)*i;
            dp[1][i] = to_pay;
        }

        rep(i , 2 ,mon+1)
        {
            rep( j, arr[i] ,m+1)
            {
                rep( k , arr[i-1] , j+1)
                {
                    dp[i][j] = min( dp[i][j] ,  dp[i-1][k] + j*wsal + (j>k?(j-k)*esal : (k-j)*ssal)) ;   
                }

            }
        }
        lli ans = 9999999;
        rep( i , arr[mon] ,m+1)
        {
            ans = min(ans , dp[mon][i]);
        }
        cout<<"Case "<<c<<", cost = $"<<ans<<endl;
        c++;

    }

    return 0;
}

