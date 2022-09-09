/*
ID: taurusd1
TASK: pprime
LANG: C++14
*/

#include <bits/stdc++.h>
#include <typeinfo>
#include <string>
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
const LD PI =(LD)acos(-1);
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define some(c,l,r) next((c).begin(),l),next((c).begin(),r-1) //Range:[l.r)
#define rall(c) (c).rbegin(),(c).rend()
#define rsome(c,l,r) next((c).rbegin(),l),next((c).rbegin(),r-1) //Range:[l.r)
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define trr(c,i) for(auto i = (c).rbegin(); i != (c).rend(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define repc(c,i,l,r) for (auto b = next(c.begin(),(l)),i=b, e=next((c).begin(),(r)); i!=e; ++i)//Range:[l.r)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define prall(m,arr) {cout<<"\n"<<(m); for (auto it = arr.begin(); it != arr.end(); ++it) cout << (*it) << " ";}
#define prrange(m,c,l,r) {cout<<"\n"<<(m);for (auto b = next(c.begin(),(l)),i=b, e=next(c.begin(),(r)); i != e; ++i) cout << (*i) << " ";}//Range:[l/r)
#define debug(m,x) cout <<"\n"<<(m)<<#x<< (x);
#define debug2(m,x,y) cout <<"\n"<<(m)<<" "<<#x << ", "<<#y<<"| "<< (x) << " " << (y);
#define debug3(m,x,y,z) cout <<"\n"<<(m)<<" "<<#x<<", "<<#y<<", "<<#z<<"| "<< (x) << " " << (y) << " " << (z);
#define debug4(m,w,x,y,z) cout <<"\n"<<(m)<<" "<<#w<<", "<<#x<<", "<<#y<<", "<<#z<<"| "<<(w)<<" "<< (x) << " " << (y) << " " << (z);
#define _(x) cout <<"\n"<< (#x) <<" "<< (x) ;


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
    os << "]";
    return os;
}

// Overloading << operator for sets
template < class T >
ostream& operator << (ostream& os, const set<T>& v)
{
    os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

// Overloading << operator for vector<vector>
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
        os << "\n" << *ii;
    }
    os << "]";
    return os;
}

//print a set of variables in one line
void pline(string message, ll indent_variable/*variable nof parameters*/)
{

}



/**pprime**/
/*
Prime Palindromes
The number 151 is a prime palindrome because it is both a prime number and a palindrome (it is the same number when read forward as backward).
Write a program that finds all prime palindromes in the range of two supplied numbers a and b (5 <= a < b <= 100,000,000);
both a and b are considered to be within the range .

PROGRAM NAME: pprime
INPUT FORMAT
Line 1:	Two integers, a and b
SAMPLE INPUT (file pprime.in)
5 500
OUTPUT FORMAT
The list of palindromic primes in numerical order, one per line.
SAMPLE OUTPUT (file pprime.out)
5
7
11
101
131
151
181
191
313
353
373
383
/**/

/*ABOUT VARIABLES USED*
a,b------------------------> As Defined in input format
/**/

//class PPrime
//About members of the class:
/*
Member variables:
a,b----------------------------->As Defined in
vll pal_a2b;------------------>vector storing all Odd(length) Palindromes between a and b
vll primes;-------------------->vector storing all primes upto sqrt(max_b)
vll vpri_pal;------------------->vector storing the final result of all prime palindromes in the range:[a,b]

Member functions:

vll primes_upto(ll)----------->Return a sorted (ascending order) vector of all primes upto a given number, N
bool ispal(ll)------------------->checking if the number passed is a palindrome( without using strings)
string rev_str(string)-------->Returns the reverse of the passed string
ll stoll(string)------------------>std::stoll with error handling(empty string passed are converted to 0)
bool in_range(string, ll, ll)-> in_range(s,a,b) will checks if the string s, is in the allowed range:[a,b+1)
void solve()-------------------> Self Explanatory

*/
class PPrime
{
//By default data members are private
//
ll a,b;
vll pal_a2b;//vector storing all Odd(length) Palindromes between a and b
vll primes;// vector storing all primes upto sqrt(max_b)
vll vpri_pal;//vector storing primes nos in the range:[a,b]

public:
PPrime()
    :a
        (
         //Lambda for taking input and returning the value
            [=](){
                ll _R;cin>>_R;
                return _R;
            }
            ()//calling the lambda
        )
    ,b
        (
         //Lambda for taking input and returning the value
            [=](){
                ll _R;cin>>_R;
                return _R;
            }
            ()//calling the lambda
        )
    ,pal_a2b()
    ,primes()
    ,vpri_pal()
    {
    };

    /*****************
    *primes_upto*
    ******************/
    /*Return a sorted (ascending order) vector of all primes upto a given number, N*/
    vector<ll> primes_upto(ll N)
    {
        vector<bool> IP(N,true);//IsPrime
        vector<ll> PUN;//PrimesUptoNow
        for(ll i=2;i*i<N+1;++i)
        {
            if(!IP[i]) continue;

            //possibly prime
            for(ll j=0;j<PUN.size();++j)//traversing all the primes numbers found upto now
            {
                if( i%PUN[j]==0)
                {
                    IP[i]=false;
                }
            }
            if(IP[i])//definitely prime as undergone checking
            {
                PUN.push_back(i);
                //all multiples of numbers less than i have been marked as non prime so,
                // if k<i, then k*i being a multiple of  k(which is <i ) ===>IP[k*i] would have been marked as false before
                //choose k>i such that k is prime(possibly) and if IP[k*i] ==true, mark IP[k*i] as false
                for(ll k=i;k*i<N+1;++k)
                {
                    if(IP[k*i])
                    IP[k*i]=false;
                }
            }
        }
        // Note: PUN contains primes only up to sqrt(N)
        //Hence, we have to populate PUN  with  remaining primes (i.e where, sqrt(N) < primes <= N) )
        rep(i,floor(sqrt(N)),IP.size())
        {
            if(IP[i])
            {
                PUN.push_back(i);
            }
        }
        return PUN;
    }

    /*checking palindrome without using strings*/
    bool ispal(ll N)
    {
        ll l=pow(10,floor(log10(N)));
        ll r=1LL;
        for(;l>r;l/=10,r*=10)
        {
            ll ld=N/l %10;
            ll rd=N/r %10;
            if(ld!=rd)
            {
                //debug("X",N)
                return false;
            }
        }
        return true;
    }

    /**********
    *rev_str*
    ***********/
    /*Returns the reverse of the passed string*/
    string rev_str(string s)
    {
        string rev_s="";//the  reversed string
        for(ll i=s.size()-1; i>0-1;--i)
        {
            rev_s+=s[i];
        }
        return rev_s;
    }

    /*******
    *stoll*
    ********/
    /*std::stoll with error handling(empty string passed are converted to 0)*/
    ll stoll(string s)
    {
        if(s=="") return 0LL;
        else
        {
            return std::stoll(s);
        }
    }
    /*********************
    *check_in_range*
    **********************/
    /*checks if the number_string, s, is in the allowed range:[a,b+1)*/
    function< bool (string,ll,ll)> in_range
    =[&](string s, ll a, ll b)
    {
        ll N=stoll(s);
        //debug("in range",N)
        return (N>=a && N<=b);
    };

    void solve()
    {
        /*
        APPROACH:

        Abbrevations:
        OP:Odd Palindrome
        EP:Even Palindrome

        1.First calculate all  Palindromes(EP + OP) up to 100  ( so i dont miss out the only even palindrome which is prime i.e.11)
        2.Then calculate OP upwards of 100 (if b>=100)
            2.1change a to the smallest odd length integer >= max(100,a)
            2.2change b to the largest odd length integer <=b

            Illustration of the pattern:

            ____________________
            101-->10+1
            ...(Only OPs in this range)
            999-->99+9
            _____________________
            1001-->10+01
            ...(Only EPs in this range)
            9999-->99+99
            ______________________
            10001-->100+01
            ...(Only OPs in this range)
            99999-->999+99
            ______________________
            100001-->100+001
            ...(Only EPs in this range)
            999999-->999
            ______________________
            1000001-->1000+001
            ...(Only OPs in this range)
            9999999-->9999+999
            ______________________

            From the above it is obvious that  to generate all the  possible OPs
            change a<- minimum odd length number >=a
            change b<- maximum odd length number <=b

            Let
            2.3.no of digits in  updated a ,nd_a
            2.4.no of digits in updated b, nd_b

            Let
            2.5.start= number formed by first (nd_a+1)/ 2 digits of a
            2.6.end= number formed by first (nd_b+1)/ 2 digits of b

            2.6.Now all we have to do is generate from range:[start, stop+1) all OPs

            3.Now Generate a sorted  vector of all primes less than sqrt(b) (or better up to sqrt( max_b))
            4.Then check each of OPs  for primality  using the primes
            5.Print out result


        */
        //1.
        for(ll i=a;i<min(100LL,b)+1; ++i)
        {
            string s=to_string(i);
            if(s== rev_str(s))
            {
                /**
                debug2("",s, rev_str(s))
                /**/
                pal_a2b.push_back(i);
            }
        }
        //2.
        //2.1.
        //if (no digits in a)%2==0  or in other words
        // floor( log10(a)) %2==1,then,
        //  a <- (smallest odd digit number >=a)
        if((ll)floor(log10(a))%2==1)
        {
            a=pow(10,floor(log10(a))+1 );
        }

        //2.2.
        //if (no digits in b)%2==0  or in other words
        // floor( log10(b)) %2==1,then,
        //  b <- (largest odd digit number <= b)
        if((ll)floor(log10(b))%2==1)
        {
            b=pow(10,floor(log10(b))) -1;
        }

        //2.3.
        ll no_digits_a=floor(log10(a))+1;
        assert(no_digits_a%2==1);
        ll k_a=(no_digits_a-1)/2 ; //assume no_digits_a= 2*k_a +1
        ll start_loop=a/ (pow(10,k_a ));// i dont care about this value

        //2.4.
        ll no_digits_b=floor(log10(b))+1;
        assert(no_digits_b%2==1);
        ll k_b=(no_digits_b-1)/2 ; //assume no_digits_b= 2*k_b +1
        ll end_loop=b/ (pow(10,k_b ));

        //2.6.
        /*Execution proceeds further when b>=100*/
        /* Generate odd length palindromes*/
        for
            (
             ll i=max(10LL,start_loop)
             ; i< end_loop +1
             ;++i
             )
        {
            string tmp_1=to_string(i)+ rev_str(to_string(i/10));//eg. for i<-1234, tmp<- "1234" + str_rev(to_string(1234/10) ) ="1234"+"321"="1234321"

            if( in_range(tmp_1,a,b))
            {
                pal_a2b.push_back(stoll(tmp_1));
            }
        }

        sort(all(pal_a2b));

        /**
        debug("", pal_a2b)
        /**/

        //3.
        /*Generate all primes upto sqrt(max_b) which can be used to determine whether any number <=max_b is prime*/
        primes=primes_upto(1e4) ;// 10 000= sqrt(max_b) =sqrt(100 000 000)=10 000
        sort(all(primes));

        /**
        debug("",primes)
        /**/

        //4.
        /*weed out all palindromes, which are not prime by
        Given:
        pal_a2b
        primes

        Now populate ,vpri_pal
        ={
            x
            ,s.t.
            1. x E pal_a2b
            2. For all(V) p (p E primes, p*p <=x, )
                        p doesnt divide x
        }
        */
        for(ll i=0; i< pal_a2b.size();++i)
        {
            bool flg=true;
            for(ll j=0;primes[j]*primes[j]<= pal_a2b[i]; ++j)
            {
                if(pal_a2b[i]%primes[j]==0)
                {
                    flg=false;
                    break;
                }
            }
            if(flg)
            {
                vpri_pal.push_back(pal_a2b[i]);
            }
        }

        //5.
        //printing out result
        rep(i,0,vpri_pal.size())
        {
            cout<<vpri_pal[i]<<endl;
        }
    }
};

int main ( )
{
    /**
    freopen("in.txt","r",stdin);//redirects standard input
    /**/
	freopen("pprime.in","r",stdin);//redirects standard input
    freopen("pprime.out","w",stdout);//redirects standard output
    /**/
    //construct a class object and immediately call a function on it
    //instead of instantiating a class object and then calling a function using that object
    PPrime().solve();
	return 0;
}
