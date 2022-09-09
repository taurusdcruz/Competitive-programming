/*
ID: taurusd1
TASK: friday
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

int main ( )
{
	freopen("friday.in","r",stdin);//redirects standard input
	freopen("friday.out","w",stdout);//redirects standard output

	ll N;
	cin>>N;
	vll d28={1}, d30={3,5,8,10}, d31={0,2,4,6,7,9,11};
	//m month days
	//ml month days in leap year
	//rm rem of first day of month rm(0,1,..6)->(S,M,T,...S)
	//rml rem of first day of  month in leap year rml(0,1,..6)->(S,M,T,...S)
	vll
	m( d28.size() + d30.size() + d31.size(), -1),
	ml(m.size(), -1),
	rm(m.size(), -1),
	rml(m.size(), -1)
	 ;

	rep(i,0, m.size())
	{
	    if(find(all(d28),i)!=d28.end()) { ml[i]=(m[i]=28)+1; }
	    else if(find(all(d30),i)!=d30.end()) { m[i]=ml[i]=30; }
	    else if(find(all(d31),i)!=d31.end()) { m[i]=ml[i]=31; }
	    else{ cout<<"\ni !E[0,11]"; }

	}
	//debug4("", m,ml,rm,rml)

	rep(i,0,m.size())
	{
	    if(i==0) rm[i]=rml[i]=0;
	    else
        {
            rm[i]=(m[i-1]+rm[i-1])%7,rml[i]=(ml[i-1]+rml[i-1])%7;
        }
	}
	//debug2("",rm, rml)

	vll dy={(rm[11]+31)%7, (rml[11]+31)%7 };//delta year, delta leap year where delta id the change in remainder mod7 at the end of the passing of the year
	//debug("", dy)
	vvll tmp(12, vll(2));
	vvll tmp1{rm,rml};
	rep(i,0,12)rep(j,0,2) tmp[i][j]=tmp1[j][i];
    vector< vvll  > y(7,tmp);//y[FDOY][LY][MONTH], where FDOY(0,1,..6)->(S,M,T,...S) , MONTH(0,1,2, ...11)->(J,F,M, ...D), LY- is it a leap year
    vector< vvll  >cnt_day_y(7, vvll(7, vll{0,0} ) );//cnt_day_y[FDOY][DAY][LY], where FDOY(0,1,..6)->(S,M,T,...S) , DAY(0,1,..6)->(S,M,T,...S), LY- is it a leap year
    //debug2("", y, cnt_day_y)
    rep(FDOY, 0,7)
    {

         y[FDOY][0]={FDOY,FDOY};
        auto predicate=[](vll elem, ll amt_to_add)->vll{return (vll{((elem[0]+amt_to_add)%7), ((elem[1]+amt_to_add)%7)});};
        auto custom_transform =
         [](vvll::iterator first1, vvll::iterator last1, vvll::iterator d_first, ll amt_to_add, function< vll (vll,ll) > predicate)//Note that the type of predicate is function<vll (vll,vll)>
        {
            while (first1 != last1)
            {
                //debug3("", *first1,amt_to_add, *d_first)
                *d_first++ = predicate(*first1++, amt_to_add);
            }
            return d_first;
        };
        custom_transform( next(y[0].begin(),1), y[0].end(), next(y[FDOY].begin(),1), FDOY, predicate);
        //debug2("",FDOY,y[FDOY])



        rep(MONTH,0,12)
        {
            cnt_day_y[FDOY][ y[FDOY][MONTH][0] ][0]+=1;
            cnt_day_y[FDOY][ y[FDOY][MONTH][1] ][1] +=1;
        }
        //debug2("",FDOY,cnt_day_y[FDOY])
    }
    auto isyl= [](ll y)->bool{ return ( (y%400==0)?(true):( (y%100==0)?(false):( (y%4==0)?(true):(false) ) ) ) ;} ;
    ll FDOY;
    vvll cnt(7, vll(2,0)), res(7, vll(2,0) );
    //debug2("",cnt,res)
    bool ly;
    rep(i,1900, 1900+N)
    {
        if(i==1900)FDOY=1;//as it is known that FDOY for 1900 was Monday
        ly=isyl(i);
        cnt[FDOY][ly]+=1;
        //debug3("", FDOY, isyl(i), (cnt[FDOY]));
        (FDOY+=dy[ly])%=7;
    }
    //debug("",res)

    rep(FDOY,0,7)
    {
        auto predicate=[](vll res, vll elem2, vll cnt)->vll{ return (vll{(res[0] + (cnt[0]*elem2[0])),( res[1] + (cnt[1]*elem2[1]))});};

         auto custom_transform =
         [](vvll::iterator first1, vvll::iterator last1, vvll::iterator first2, vvll::iterator d_first, vll cnt, function< vll (vll,vll,vll) > predicate)//Note that the type of predicate is function<vll (vll,vll,vll)>
        {
            while (first1 != last1)
            {
                //debug4("", *first1,*first2,cnt,*d_first)
                *d_first++ = predicate(*first1++, *first2++, cnt);
            }
            return d_first;
        };

        custom_transform(all(res), cnt_day_y[FDOY].begin(),res.begin(),cnt[FDOY] ,predicate ) ;
        //debug2("",FDOY,y[FDOY])
        //debug("", res)

    }
    vll res1(7,0);
    rep(i,0,7)
    {
        ll ii=(i+1)%7;
        res1[i]= res[ii][0] + res[ii][1];
    }
    //debug("",res1)
    rep(i,0,7)cout<<((i==0)?(""):(" "))<<res1[i];
    cout<<"\n";
	return 0;
}

