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
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define trr(c,i) for(auto i = (c).rbegin(); i != (c).rend(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define repc(c,i,l,r) for (auto b = next(c.begin(),(l)),i=b, e=next((c).begin(),(r)); i!=e; ++i)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define prall(m,arr) {cout<<"\n"<<(m); for (auto it = arr.begin(); it != arr.end(); ++it) cout << (*it) << " ";}
#define prrange(m,c,l,r) {cout<<"\n"<<(m);for (auto b = next(c.begin(),(l)),i=b, e=next(c.begin(),(r)); i != e; ++i) cout << (*i) << " ";}
#define debug(m,x) cout <<"\n"<<(m)<< (x);
#define debug2(m,x,y) cout <<"\n"<<(m)<<" "<< (x) << " " << (y);
#define debug3(m,x,y,z) cout <<"\n"<<(m)<< (x) << " " << (y) << " " << (z);
#define debug4(m,w,x,y,z) cout <<"\n"<<(m)<<" "<<(w)<<" "<< (x) << " " << (y) << " " << (z);
const LD EPS=1e-12;
const LD INF=1e100;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions
class Reroll
{
     int target;
     vector< int > dice;
public:
     int minimumDice(int target, vector <int> dice)
     {
        ll min_no_of_rolls=0;
        sort(all(dice));
        ll sum=0;
        rep(i,0,dice.size())
        {
            sum+=dice[i];
        }

        if(sum>target)
        {
            ll tmp_sum=sum;
            for(ll i=dice.size()-1;i>=0;i--)
            {
                tmp_sum-=dice[i]-1;
                min_no_of_rolls+=1;
                if(tmp_sum<=target) return min_no_of_rolls;
            }
        }
        else if(sum<target)
        {
            ll tmp_sum=sum;
            for(ll i=0;i<dice.size();i++)
            {
                tmp_sum+=6-dice[i];
                min_no_of_rolls+=1;
                if(tmp_sum>=target) return min_no_of_rolls;
            }
        }


        return min_no_of_rolls;
     }
};


int main ( )
{
	//freopen("in.txt","r",stdin);//redirects standard input
	//freopen("out.txt","w",stdout);//redirects standard output

    Reroll test;
    ll target=10;
    vector<int> dice={4,2,4,5};
    cout<<test.minimumDice(target, dice);

	return 0 ;
}

