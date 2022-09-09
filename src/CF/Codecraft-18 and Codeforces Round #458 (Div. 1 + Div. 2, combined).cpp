#include <bits/stdc++.h>
using namespace std;
//#include <bigInt.h>

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector< vll > vvll;


template<class T> T abs(T x) { return x > 0 ? x : -x;}

const ll mod = 1000000000 + 7;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)


int main ( )
{
    freopen("in.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output


    ll K, K1, N, N1, no_of_1s;
    string N0;

    cin>>N0>>K;
    N=count(N0.begin(),N0.end(),'1');
    cout<<"\n N :"<<N;
    K1=0;
    while(K1<=K)
    {
        N1=0, no_of_1s=0;
        cout<<"\nk"<<K1;
        while(1)
        {
            if(N & 1) {no_of_1s+=1;}
            N=N>>1;
            cout<<((no_of_1s==0)?"\n":"|")<<N;
            if(N==0) {N=no_of_1s , K1+=1; break;}
         }
    }





    return 0 ;
}
