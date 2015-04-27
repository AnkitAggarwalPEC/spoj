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
#define pb push_back
int main()
{
    int t;input(t);
    while(t--)
    {
        int r,c; input(r);input(c);
        vii v;
        int sr,sc; sr= sc = 0;
        char arr[r][c];
        int dist[r][c];
       // cout<< r << " "<< c<<endl;
        rep(i,0,r)
        {
            string s; cin>>s;
            //cout<<s;

            repj(j,0,c)
            {
                arr[i][j] = s[j];
                dist[i][j] = inf;
               // cout<<arr[i][j]<<endl;
                if(s[j] == 'S') v.pb(std::make_pair(i,j));
                else if( s[j] == 'C')
                {
                    sr = i;sc = j;
                }
            }
        }
        queue< ii > q;
        q.push(std::make_pair(sr,sc));
        dist[sr][sc] = 0;
        int max_dis= 0;
        int ri=0;
        int rc =0;
        while(!q.empty())
        {
            ii a = q.front(); q.pop();
            int u = a.first; int v = a.second;
            //cout<<u <<" "<<v<<endl;
            //cout<<dist[u][v]<<endl;
            if( u - 1 >= 0 && (arr[u-1][v] == '.'|| arr[u-1][v] == 'S') && dist[u-1][v] > dist[u][v]+1)
            {   
                dist[ u-1 ][v] = dist[u][v]+1;
                q.push(std::make_pair(u-1 , v));
                if(arr[u-1][v] == 'S' && dist[u-1][v] >max_dis) 
                {
                    max_dis = dist[u-1][v];
                    ri = u-1;rc = v;
                }
            }   
            if( u + 1 < r && (arr[u +1][v] == '.' || arr[u +1][v] == 'S') && dist[u+1][v] > dist[u][v]+1)
            {
                dist[ u+1 ][v] = dist[u][v]+1;
                q.push(std::make_pair(u+1 , v));
                if(arr[u+1][v] == 'S' && dist[u+1][v] >max_dis)
                {
                    max_dis = dist[u+1][v];
                    ri = u+1;rc = v;
                }
            }
            if( v - 1 >= 0 && (arr[u][v - 1] == '.' || arr[u][v -1] == 'S') && dist[u][v-1] > dist[u][v]+1)
            {   
                dist[u][v-1] = dist[u][v]+1;
                q.push(std::make_pair(u , v - 1));
                if(arr[u][v-1] == 'S' && dist[u][v-1] >max_dis)
                {
                    max_dis = dist[u][v-1];
                    ri = u;rc = v-1;
                }
            }
            if( v + 1 < c && (arr[u][v +1] == '.' || arr[u][v+1] == 'S') && dist[u][v+1] > dist[u][v]+1)
            {

                dist[u][v+1] = dist[u][v]+1;
                q.push(std::make_pair(u,v+1));
                if(arr[u][v+1] == 'S' && dist[u][v+1] >max_dis)
                {
                    max_dis = dist[u][v+1];
                    ri = u;rc = v+1;
                }   
            }
        }
        int sz  = v.size();
        lli ans = sz* 60;
        ans += max_dis;
        dist[ri][rc] =0;
        trvii(v,it)
        {
            ans+= (2*dist[ it->first][it->second]);
        }
        cout<<ans<<endl;

    }
    return 0;
}