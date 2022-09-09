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

const ll mod = 1e9 + 7;
#define sz(a) int((a).size())
#define pb push_back
#define fi first
#define se second
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
    os << "]";
    return os;
}

// Overloading << operator for vectors
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

// Overloading << operator for vectors
template < class T >
ostream& operator << (ostream& os, const map<T, T>& v)
{
    os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

int main()
{
    freopen("in.txt","r",stdin);//redirects standard input
    ll n;cin>>n;
    vector<ll> a(n);
    rep(i,0,n)
    {
        cin>>a[i];
    }
    ll cnt=0;

    rep(i,1,n)
    {
        ll cnt1=0;
        for(;a[i]=a[i-1]+1;)
        {
            cnt1+=1;
            if(i+1==n)break;
            else
            {
                i+=1;
            }
        }
        if(cnt1>=2)
        {
            cnt+=cnt1;
        }
    }
    return 0;
}#PF-Assgn-20

def eligibility(salary,loan_type,loan_amount_expected,customer_emi_expected ):
    not_eligible=False
    if(salary> 2.5e4 and loan_type=="Car" and loan_amount_expected<=0.5e6 and customer_emi_expected<=3.6e1):
    elif(salary> 5.0e4 and loan_type=="House" and loan_amount_expected<=6.0e6 and customer_emi_expected<=6.0e1):
    elif(salary> 7.5e4 and loan_type=="Business" and loan_amount_expected<=7.5e6 and customer_emi_expected<=8.4e1):
    else:
        not_eligible=True

def calculate_loan(account_number,salary,account_balance,loan_type,loan_amount_expected,customer_emi_expected):
    eligible_loan_amount=0
    bank_emi_expected=0
    eligible_loan_amount=0
    #Start writing your code here
    an,s,ab,lt,lae,cee=account_number,salary,account_balance,loan_type,loan_amount_expected,customer_emi_expected

    #The account number should be of 4 digits and its first digit should be 1.
    flg1=(len(str(an))==4 and str(an)[0]=='1')

    #The customer should have a minimum balance of Rupees 1 Lakh in the account.
    flg2=ab>=100000

    #If the above rules are valid, determine the eligible loan amount and the EMI that the bank can provide to its customers based on their salary and the loan type they expect to avail.
    #The bank would provide the loan, only if the loan amount and the number of EMI’s requested by the customer is less than or equal to the loan amount and the number of EMI’s decided by the bank respectively.
    #SalaryLoantype	Eligibleloanamount	No.ofEMI’srequiredtorepay
    #> 25000	Car	500000	36
    #> 50000	House	6000000	60
    #> 75000	Business	7500000	84
    flg3=eligibility(salary,loan_type,loan_amount_expected,customer_emi_expected)


    #Display appropriate error messages for all invalid data.
    if(flg1 or flg2 or flg3):
        #Use the below given print statements to display the output, in case of invalid data.
        #print("The customer is not eligible for the loan")
        if(flg1)
        #print("Invalid account number")
        if(flg2)
        #print("Insufficient account balance")
        if(flg3)
        #print("Invalid loan type or salary")
    else:
        # If all the business rules are satisfied ,then display account number, eligible and requested loan amount and EMI’s.
        #Populate the variables: eligible_loan_amount and bank_emi_expected

        #Use the below given print statements to display the output, in case of success
        #print("Account number:", account_number)
        #print("The customer can avail the amount of Rs.", eligible_loan_amount)
        #print("Eligible EMIs :", bank_emi_expected)
        #print("Requested loan amount:", loan_amount_expected)
        #print("Requested EMI's:",customer_emi_expected)


    # Also, do not modify the above print statements for verification to work


#Test your code for different values and observe the results
calculate_loan(1001,40000,250000,"Car",300000,30)
