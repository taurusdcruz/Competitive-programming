/*
ID: taurusd1
TASK: beads
LANG: C++14
*/

#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;

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

const ll mod = (ll)(1e9 + 7);
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
#define debug(m,x) cout <<"\n"<<(m)<<#x<< (x);
#define debug2(m,x,y) cout <<"\n"<<(m)<<" "<<#x << ", "<<#y<<"| "<< (x) << " " << (y);
#define debug3(m,x,y,z) cout <<"\n"<<(m)<<" "<<#x<<", "<<#y<<", "<<#z<<"| "<< (x) << " " << (y) << " " << (z);
#define debug4(m,w,x,y,z) cout <<"\n"<<(m)<<" "<<#w<<", "<<#x<<", "<<#y<<", "<<#z<<"| "<<(w)<<" "<< (x) << " " << (y) << " " << (z);
#define _(x) cout <<"\n"<< (#x) <<" "<< (x) ;


//Overriding << operator
template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  out<<"( "<<a.first<<", "<<a.second<<") \n";
  return out;
}

// Overloading << operator for vectors
template < class T >
ostream& operator << (ostream& os, const vector<T>& v)
{
    os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

// Overloading << operator for vectors
template < class T >
ostream& operator << (ostream& os, const vector< vector<T> >& v)
{
    os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os << ((ii != v.begin() )?("\n") :("\n") )<< *ii;
    }
    os << "]";
    return os;
}

// Overloading << operator for maps
template < class T, class U >
ostream& operator << (ostream& os, const map<T, U>& mp)
{
    os << "mp:[";
    for (auto ii = mp.begin(); ii != mp.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}
//sub_neclace with continuous beads of same colour
struct necklace
{
    char bead;
    ll beg_indx;
    ll no_beads;

public:
    necklace() : bead('-'), beg_indx(-1), no_beads(0) { }
    necklace(char _bead, ll _beg_indx, ll _no_beads) : bead(_bead), beg_indx(_beg_indx), no_beads(_no_beads) { }
    necklace& operator= (const necklace& n);
};

necklace& necklace::operator= (const necklace& n)
{

    this->bead=n.bead;
    this->beg_indx=n.beg_indx;
    this->no_beads=n.no_beads;
    return *this;
}

//Overloading operator<< for struct
ostream& operator<< ( ostream& os, const necklace& n)
{
    os << "( "<<(n.bead)<<", "<<(n.beg_indx )<<", "<< (n.no_beads)<<" ) ";
    return os;
}

int main ( )
{
	freopen("beads.in","r",stdin);//redirects standard input
	freopen("beads.out","w",stdout);//redirects standard output
	ll N;
	cin>>N;
	/*
	vector<char> c{'a','b','c'};
	string sc;
	rep(i,0,c.size()) sc+=string(1,c[i]);

	debug("",sc)
	*/
	vector<necklace > NK;//Necklace
	string s;
	cin>>s;
	s+=s;
	//debug("",s)
	ll i=0;
	necklace t_;
	char prev_bead=s[0];
	t_={s[0],0,1};//temp
	//Learn about how the parser works in c++
	//What to do when the parser gives the error that parser is still parsing files

	while(++i<s.size())
	{
	    ll i_c=i%s.size();
	    ll i_p=(i-1)%s.size();
	    if(s[i_c]==s[i_p] )
        {
            t_.no_beads+=1;

            //debug("add 1",t_)
            //debug("\tNK resulting add",NK)

        }
	    else
        {
            //debug4("prev!=curr",s[i_p],s[i_c], i_p,i_c)
            NK.pb(t_);
            //debug("\tNK resulting push",NK)
            ll delta=NK.size();
            vector<char> last3(3,'-');
            //debug("",NK)
            auto rget_bead= [=](ll i)->char{ return prev(NK.end(),i)->bead ;} ;
            if(delta>=3){last3={rget_bead(3), rget_bead(2), rget_bead(1)};}



            if(last3==vector<char>{'b','w','b'} || last3==vector<char>{'r','w','r'})
            {



                ll tmp_no_bead=0;
                //debug("\t\t\tpop1",NK.back())
                tmp_no_bead+=NK.back().no_beads;NK.pop_back();
                //debug("\t\t\tpop2",NK.back())
                tmp_no_bead+=NK.back().no_beads;NK.pop_back();
                NK.back().no_beads+=tmp_no_bead;
                //debug("\t\t\tpop3",NK.back())
                if(NK.back().bead ==s[i_c]) {t_=NK.back();NK.pop_back();} else{t_={s[i_c],i_c,1};}
                //debug("\t\t\tNK resulting after pops",NK)
                //debug4("\t\t\t<-",delta, NK.back(), last3, t_)


            }
            else
            {
                //debug("\t\tpush",NK.back())
                //debug("\t\t\tNK resulting after push",NK)
                t_={s[i_c],i_c,1};
                //debug2("\t\t\t->",NK.back(),t_)

            }

        }
        if(i>=s.size()-1)NK.pb(t_);


	}
    ll l_indx=(NK[1].bead=='w')?(2):(1);
    ll r_indx=l_indx+ (NK[l_indx+1].bead=='w')?(1):(0);
    ll l_sum=NK[l_indx].no_beads+(NK[l_indx-1].bead=='w')?(NK[l_indx-1].no_beads):(0) ;
    ll  r_sum=NK[r_indx].no_beads+(NK[r_indx-1].bead=='w')?(NK[r_indx-1].no_beads):(0);
    ll mx_sm=0;
	while(r_indx+2<NK.size())
	{


        if(NK[r_indx+1].bead=='w')
        {


            mx_sm=max( (l_sum+r_sum+NK[r_indx+1].no_beads), mx_sm);
            l_indx=r_indx, l_sum=r_sum;

            r_sum=NK[r_indx+1].no_beads+ NK[r_indx+2].no_beads;
            r_indx+=2;

        }
        else
        {
            mx_sm=max( (l_sum+r_sum), mx_sm);
            l_indx=r_indx, l_sum=r_sum;

            r_sum=NK[r_indx+1].no_beads;
            r_indx+=1;

        }

	}
	//debug("hhhhhhhhhhhhhhhhhhhhhaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",mx_sm)

	//mapping indexes of s to indexes of NK
	map<ll,ll> mp;
	rep(i,0,NK.size())
	{
	    mp[NK[i].beg_indx]=i;
	}


	rep(i,0,NK.size())
    {
        if(NK[i].beg_indx>s.size()/2 -1)
        {
            //debug("", *(next(NK.begin(),mp[NK[i].beg_indx])) )
            //erasing end part
            NK.erase(next(NK.begin(),mp[NK[i].beg_indx]), NK.end());
            //debug("After deleting ending",NK)
            NK[i].beg_indx%=s.size()/2;
            //erasing beginning part
            NK.erase(NK.begin(),next(NK.begin(),mp[NK[i].beg_indx]));
            //debug("after deleting beginning", NK)
            i=NK.size();
        }
    }
    if(NK.size()<=2)
    {
        ll sm=0;
        rep(i,0,NK.size())
        {
            sm+=NK[i].no_beads;
        }
        cout<<min(N,sm)<<"\n";
        return 0;
    }

    cout<<min(N,mx_sm)<<"\n";
	return 0;
}

