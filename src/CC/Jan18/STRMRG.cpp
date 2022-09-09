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

#define INV1(i) ( a[i]==1)? 0:1)
#define INV_a(i)  a[i] =( (a[i]==1)? 0:((a[i]==0)?1:a[i]) )



void solve( vector< vll > char_index[], ll s_len[], string s[]){



        bool possible;









    }



int main()
{
    freopen("inSTRMRG.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output

    ll T, M, N;






    cin>>T;

    for(ll i1=0; i1< T && (cin>>N>>M); i1++)
    {

        string s[2];
        ll  s_len[2];
        cin>>s_len[0]>>s_len[1];

        cin>>s[0] >> s[1];
        cout<< "\nsize of stings"<<s[0].size()<< s[1].size();//Debug

        vector< vvll >char_index (2, vvll(26, vll(0,0) ) );

        cout <<"\n size"<<char_index[0].size()<<" "<< char_index[1].size();//Debug

        //for(ll i=0; i<26; i++) char_index.resize(1), char_index[0]=-1;//Debug//if  v of v was declared globally
        for(ll i=0; i<s_len[0]; i++) char_index[0][ s[0][i]- 'a'].push_back +=1;
        for(ll i=0; i<s_len[1]; i++) char_index[1][ s[0][i]- 'a'] +=1;


        solve( vector< vll > char_index[], ll s_len[], string s[]);
        cout << ((i1<T-1)?"\n":"");
    }
    return 0;
}
