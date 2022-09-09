
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
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " ";
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
const LD EPS=1e-12;
const LD INF=1e100;
#define CORRECT( i, N ) ((i) +(((i)>(N)-1)?-((N)):(i)<0?+((N)):0))
#define SIGN(i) ((i)>0?+1:(i)<0?-1:0)
#define ADJ(i1,i2,i3,delta,ad) ((i1==0 || i1% i3==0 )?SIGN(delta):ad)


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures
template< class T, class U>
struct pr
{
    mutable T first;
    mutable U second;




};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions


template< class T, class U >
 bool operator<(const pr<T,U>& a, const pr<T,U>& b)
{
  if (a.first < b.first) return true;
  else if ( (a.first == b.first) && (a.second < b.second) ) return true;
  else return false;
}

template< class T, class U >
ostream&  operator<<(ostream& out,const pr<T,U>& a)
{
  out<<"( "<<a.first<<", "<<a.second<<") ";
  return out;


}

template <template <class...> class TT, class ...T>
ostream& operator<<(ostream& out, const TT<T...>& c)
{
    out << "[ ";

    for(auto x : c)
    {
        out << x << " ";
    }

    out << "]";

    return out;
}

//is an element present in a  set of pairs as  first/second element
template< class T>
typename set< pr<T,T> > :: iterator p_s_p( set< pr<T,T> > &st_pr,const  int &searchby01 , const  T &searchfor)
{
    if(searchby01==0)
    {
        tr(st_pr,i)
        {
            if((*i).first == searchfor) return i ;
        }
    }else if( searchby01 ==1)
    {
        tr(st_pr,i)
        {
            if((*i).second == searchfor) return  i;
        }
    }
    else
    {
        cout<<"\nEnter 0 or 1 as second parameter";
    }

    return st_pr.end();
}

//insert into first element of set of pair and maintain a count value in the second element
 template< class T>
typename set< pr<T,T> > :: iterator i_s_p( set< pr<T,T> > &st_pr, const  T &insertthis)
{

    tr(st_pr,i)
    {
        if((*i).first == insertthis)
        {
            (*i).second+=1;
            return i;
        }
    }

    auto i=st_pr.insert(make_pair(insertthis, (ll)1));
    return i--;
}

int main ( )
{
    freopen("in.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    ll n;
    ll cnt=1;
    cin>>n;
    //val
    vll p(n+1);
    //val, index
    set<pr<ll,ll> > st;


    p[0]=-1;
    p[1]=1;
    pr<ll,ll>  tmp;
    set< pr<ll,ll> > :: iterator it;
    rep(i,2,n+1)
    {
        cin>>p[i];
        it=p_s_p(st,0,p[i]);
        if(it!=st.end())
        {
            (*it).second+=1;
        }
        else
        {
            tmp.first=p[i];
            tmp.second=1;
            st.insert(tmp);
        }
    }


    ll temp;
    cout<<"\nINFLORESCENCE:";
    print(p);
    cout<<"\nSET:";
    print(st);
    set< pr<ll,ll> > :: iterator it_flg;
    bool flg= true;
    while(flg)
    {

        cout<<"\ncnt="<<cnt;
        cout<<"\nTRAVERSING";
        cout<<"\nSET:";
        print(st);
        tr(st,i)
        {

            cout<<"\n\n\t*i "<<(*i).first;
            cout<<"\n\tdis "<<distance(i,st.end());
            cout<<"\n\tini ";print(st);
            cout<<"\n\tp["<<(*i).first<<"] "<<p[(*i).first];

            temp=(*i).first;
            if((*i).second>1) (*i).second-=1;
            else
            {
                i=st.erase(i);
                --i;
            }
            cout<<"\n\tDEL "<<temp;
            cout<<"\n\taft ";print(st);

            it=p_s_p(st,0,p[(*i).first]);
            if(it!=st.end())
            {

                (*it).second+=1;
            }
            else
            {
                tmp.first=p[(*i).first];
                tmp.second=1;
                st.insert(tmp);
            }
            cout<<"\n\tNEW *i "<<*(i);
        }
        it_flg= p_s_p(st,0,(ll)1);
        flg=p_s_p(st,0,(ll)1)!=st.end();
        if( flg && (*it_flg).second%2 !=0) cnt+=1;
    }

    cout<<"\ncnt"<<cnt;



	return 0 ;
}

