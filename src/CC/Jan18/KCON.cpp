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





/*
ll f(vector<ll> a, ll N, ll NK)
{
    ll max_[] = {LLONG_MIN, 0};
    int so_far=0, ending_here=1;

    for (ll i = 0; i < NK; i++)
    {
        max_[ending_here] += a[i%N];
        (max_[so_far] < max_[ending_here])?   max_[so_far] = max_[ending_here]: i+=0;

        (max_[ending_here] < 0)?  max_[ending_here] = 0: i+=0 ;
    }
    return max_[so_far];
*/


ll solve(vll a, ll N, ll K){
        vector< vector<ll> > dp(N,vector<ll>(K, LLONG_MIN) );
        pair< ll, ll > max_overall_beg(0, 0);
        pair< ll, ll > max_overall_end(0, 0);
        vector<ll > max_overall(K, LLONG_MIN);
        dp[0][0] = a[0];
        ll sum=0,k=0, result;


        //cout<<k<<" "<<dp[0][0];//Debug//printdp
        for (ll j = 1;j <N && k<K ; j++)
        {



            if( k>=1 && j==1) //transition
            {
                //cout<<"\n blk 1";//Debug
                dp[0][k]=MAX(dp[N-1][k-1]+a[0] ,a[0]);
                 if(max_overall[k] < dp[0][k])
                {

                    max_overall[k]=dp[0][k];
                    if((dp[N-1][k]+a[0] <a[0]) )max_overall_beg.first=0, max_overall_beg.second=k,max_overall_end.first=0, max_overall_end.second=k ;
                    else if( dp[N-1][k]+a[0] >a[0]) max_overall_end.first=0, max_overall_end.second=k;

                    //cout<<"\n( "<<max_overall_beg.first<<", "<<max_overall_beg.second<<"), ("<<max_overall_end.first<<", "<<max_overall_end.second<<")";//Debug
                }

                //cout<< " "<<dp[0][k];//Debug//printdp
            }

            dp[j][k] =MAX(dp[j-1][k]+a[j] ,a[j]);
            //cout<<" "<<dp[j][k];//Debug//printdp

            if(max_overall[k] < dp[j][k])
            {
                //cout<<"\n blk 2";//Debug
                max_overall[k]=dp[j][k];
                if((dp[j-1][k]+a[j] <a[j]) )max_overall_beg.first=j, max_overall_beg.second=k,max_overall_end.first=j, max_overall_end.second=k ;
                else if( dp[j-1][k]+a[j] >a[j]) max_overall_end.first=j, max_overall_end.second=k;

                //cout<<"\n( "<<max_overall_beg.first<<", "<<max_overall_beg.second<<"), ("<<max_overall_end.first<<", "<<max_overall_end.second<<")";//Debug
            }




            if(j==N-1) //transition
            {
                //cout<<"\n blk 3";//Debug
                if(k>=2 && max_overall[k] ==max_overall[k-1]) {result=max_overall[k]; break; }
                result=max_overall[k] ;
                k+=1,j=0;

                //cout<<(( j<N && k<K)?"\ncan go next iter":"\nsorry");//Debug
                //cout<<"\n"<<k;//Debug//printdp

            }

        }


        //print
        /*
        for(ll j=max_overall_beg.first, k=max_overall_beg.second;  (k<max_overall_end.second ) || (k==max_overall_end.second &&j<=max_overall_end.first); j++)
        {
            if(k>= max_overall_beg.second +1 && j==0) //transition

            if(k>= max_overall_beg.second +1 && j==N-1) //transition


        }
        */


        return result;
    }


int main()
{
    freopen("inKCON.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output

    ll T, N, K;
    vector<ll> a;


    cin>>T;

    for(ll i1=0; i1< T; i1++)
    {


        cin>>N>>K;
        //cout<<"\n"<<N<<" "<<K<<"\n";//Debug


        a.resize(N);
        rep(i11, 0, N)
        {
            cin>>a[i11];
            //cout<<a[i11]<<((i11<N-1)?" ":"\n");//Debug
        }

    ll res = solve(a, N, K);
    //cout<<"\n res ";//Debug
    cout << res<< ((i1<T-1)?"\n":"");
    }
    return 0;
}
