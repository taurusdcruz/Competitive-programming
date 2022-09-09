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
#define rall(c) (c).rbegin(),(c).rend()
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
#define CORRECT( i, N ) ((i) +(((i)>(N)-1)?-((N)):(i)<0?+((N)):0))
#define SIGN(i) ((i)>0?+1:(i)<0?-1:0)


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//functions

//Overriding << operator
template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  out<<"( "<<a.first<<", "<<a.second<<") ";
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
    os << " ]";
    return os;
}


// Overloading << operator for vectors
template < class T >
ostream& operator << (ostream& os, const set<T>& s)
{
    os << "{";
    for (auto ii = s.begin(); ii != s.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << " }";
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
    os << " ]";
    return os;
}

int main()
{
    //SET


    //insert into a set from a vector
    vll a(10,1);
    set<ll> sa;
    sa.insert(all(a));


    /*******************************************
    *Demo for Merging two stl vectors*
    ********************************************

    ll ex1[]={0, 1, 2, 4 ,5, 8, 10};
    ll ex2[]={0, 2, 4, 5, 6, 11, 13};

    vll example1, example2;
    ll len_ex1=sizeof(ex1)/sizeof(ex1[0]);
    ll len_ex2=sizeof(ex2)/sizeof(ex2[0]);

    example1.assign(ex1, ex1+ len_ex1);
    example2.assign(ex2, ex2 + len_ex2);
    debug("example1", example1);
    debug("example2", example2);
    vll mergeunique;
    insert_iterator < vll > it(mergeunique, mergeunique.end()) ;
    merge(all(example1), all(example2), it );
    debug("mergeunique", mergeunique);
    mergeunique.erase( unique(all(mergeunique)), mergeunique.end());
    debug("mergeunique", mergeunique);
    /*****************************
    *XXXENDOFDEMOXXX*
    *****************************/


    /************************************************************************
    *Demo for STL's lower_bound()/upper_bound() functions*
    *************************************************************************
    About variables:
    vEl------->vector of elements sorted according to the cmp , taking into account  the direction of iteration
    bv-------->bounding value for which we want to find the lower_bound /upper_bound
    cv-------->the value in vEl currently being point to during the iteration process within lower_bound/upper_bound


    bool cmp( bv, cv) ------>Binary function that accepts two arguments (the first is always val, and the second of the type pointed by the Iterator), and returns a value convertible to bool.
    The value returned indicates whether the first argument is considered to go before the second.

    LB, UB----------------------->lower_bound/upper_bound on container iterating in forward direction
    LBr, UBr-------------------->lower_bound/upper_bound on container iterating in reverse direction
    */

    /*  *<DELETE THIS>/

    auto cmp_Lss=[](ll bv, ll cv){ return bv<cv;};
    auto cmp_Lss_Eql=[](ll bv, ll cv){ return bv<=cv;};
    auto cmp_Grt=[](ll bv, ll cv){ return bv>cv;};
    auto cmp_Grt_Eql=[](ll bv, ll cv){ return bv>=cv;};

    //auto make_forward=[](ReverseIterator )
    auto LB=[=](vll vEl, ll bv,function<bool (ll,ll)> cmp){cout<<"value:"<<*lower_bound(all(vEl),bv,cmp)<<" index"<< distance(vEl.begin(),lower_bound(all(vEl),bv,cmp))<<endl;};
    auto UB=[=](vll vEl, ll bv,function<bool (ll,ll)> cmp){cout<<"value:"<<*upper_bound(all(vEl),bv,cmp)<<" index"<< distance(vEl.begin(),upper_bound(all(vEl),bv,cmp))<<endl;};
    auto LBr=[=](vll vEl, ll bv,function<bool (ll,ll)> cmp){cout<<"value:"<<*lower_bound(rall(vEl),bv,cmp)<<" index"<< distance(vEl.begin(),--lower_bound(rall(vEl),bv,cmp).base())<<endl;};
    auto UBr=[=](vll vEl, ll bv,function<bool (ll,ll)> cmp){cout<<"value:"<<*upper_bound(rall(vEl),bv,cmp)<<" index"<< distance(vEl.begin(),--upper_bound(rall(vEl),bv,cmp).base())<<endl;};
    vll vEl={10,10,13,13,14,14,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,20,20,20,20,20,20,20,30,30,30,30,35,35,35,35,35,40,40,40,40,40};
    ll bv=11;//try TEST CASES:bv =first_element, last_element, element_on_the_list, element_not_on_the_list
    debug("",vEl)
    //Goal:
    //g1:index of last element less than bv
    //g2:index of first element equal to bv
    //g3:index of last element equal to bv
    //g4:index of first element greater than bv
    cout<<"\ng1:index of last element less than bv"<<endl;
    LBr(vEl, bv,cmp_Grt_Eql);
    UBr(vEl, bv,cmp_Grt);

    cout<<"\ng2:index of first element equal to bv"<<endl;
    LB(vEl, bv,cmp_Lss);
    UB(vEl, bv,cmp_Lss_Eql);

    cout<<"\ng3:index of last element equal to bv"<<endl;

    LBr(vEl, bv,cmp_Grt);
    UBr(vEl, bv,cmp_Grt_Eql);

    cout<<"\ng4:index of first element greater than bv"<<endl;
    LB(vEl, bv,cmp_Lss_Eql);
    UB(vEl, bv,cmp_Lss);
    /*****************************
    *XXXENDOFDEMOXXX*
    *****************************/

    /*****************************
    *Demo for std::tie
    *****************************
    About Demo:
    1.Assigning multiple variables in one line
    2.Assigning complex pairs

    */
    /**<DELETE THIS>/
    //1.
    ll lval1, lval2 , lval3, lval4;
    ll rval1=1, rval2=2, rval3=3, rval4=4;
    //method 1
    std::tie(lval1,lval2,lval3,lval4)=std::tie(rval1,rval2,rval3,rval4);
    //method 2
    std::tie(lval1,lval2,lval3,lval4)=std::make_tuple(rval1,rval2,rval3,rval4);

    //2.
    pair< pair<char,string>,pair<ll,LD > > some_complex_pair;
    some_complex_pair=make_pair(pair<char,string>('1',"2"),pair<ll,LD>(3ll,4.0l));
    char some_char;
    string some_string;
    ll some_long;
    LD some_long_double;
    std::forward_as_tuple(std::tie(some_char,some_string), std::tie(some_long,some_long_double))=some_complex_pair;
    cout<<some_char<<" "<<some_string<<" "<<some_long<<" "<<some_long_double<<endl;
    /**/
    /*****************************
    *XXXENDOFDEMOXXX*
    *****************************/


    /*****************************
    *Demo for push_back() vs emplace_back()
    *****************************
    About Demo:
    pushing some_complex_pair into a vector<some_complex_pair> using
    -push_back()
    -using emplace_back()
    */
    /**<DELETE THIS>/
    vector
    <
        pair
        <
            ll
            ,pair
            <
                pair<char,string>
                , pair<int, long long int>
             >
         >
     >
     vp;
    vp.push_back(make_pair(1ll,make_pair(make_pair('1',"1"),make_pair(1,1ll))));
    vp.emplace_back(2ll,make_pair(make_pair('2',"2"),make_pair(2,2ll)));
    vp.emplace_back(piecewise_construct,forward_as_tuple(2ll),forward_as_tuple(make_pair('3',"3"),make_pair(3,3ll) ));
    debug("",vp)

    /**/

    /*****************************
    *XXXENDOFDEMOXXX*
    *****************************/
    /***********************************************
    *Demo: piecewise construction in pairs*
    ************************************************
    That is, if the types T1 and T2 can be constructed from a set of arguments a1, a2, ... and b1, b2, ...,
    then morally speaking we can make a pair

    "pair<T1, T2> p(a1, a2, ..., b1, b2, ...)":

    std::pair<T1, T2> p(std::piecewise_construct,
                        std::forward_as_tuple(a1, a2, ...),
                        std::forward_as_tuple(b1, b2, ...));
    */
    /**<DELETE THIS>/*/
    vector< pair<vector<int>, set<int> >> v1;
    v1.emplace_back(piecewise_construct, forward_as_tuple(vector<int>{1,2,3,4,5}),forward_as_tuple(set<int>{6,7,8,9,10}));
    debug("",v1)
    /**/

    /*****************************
    *XXXENDOFDEMOXXX*
    *****************************/
    return 0;
}
