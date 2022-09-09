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
const LD PI =(LD)acos(-1);
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
#define debug(m,x) cout <<"\n"<<(m)<<"| "<<#x<< (x);
#define debug2(m,x,y) cout <<"\n"<<(m)<<" "<<#x << ", "<<#y<<"| "<< (x) << " " << (y);
#define debug3(m,x,y,z) cout <<"\n"<<(m)<<" "<<#x<<", "<<#y<<", "<<#z<<"| "<< (x) << " " << (y) << " " << (z);
#define debug4(m,w,x,y,z) cout <<"\n"<<(m)<<" "<<#w<<", "<<#x<<", "<<#y<<", "<<#z<<"| "<<(w)<<" "<< (x) << " " << (y) << " " << (z);
#define _(x) cout <<"\n"<< (#x) <<" "<< (x) ;

//print a set of variables in one line
void pline(string message, ll indent_variable/*variable nof parameters*/)
{

}
void indent(ll indent_variable)
{
    cout<<"\n";rep(i,0,indent_variable)cout<<"\t";
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//functions

int main()
{
    /******************
    *CONSTANTS*
    *******************
    1.Floating
    2.Integer
    /**/

    /**1.FLOATING CONSTANTS
    Link:https://en.cppreference.com/w/c/language/floating_constant

    If the significand begins with the character sequence 0x or 0X, the floating constant is a hexadecimal floating constant.
    Otherwise, it is a decimal floating constant.

    For a hexadecimal floating constant, the significand is interpreted as a hexadecimal rational number,
    and the digit-sequence of the exponent is interpreted as the integer power of 2 to which the significand has to be scaled.

    double d = 0x1.2p3; // hex fraction 1.2 (decimal 1.125) scaled by 2^3, that is 9.0
    (since C99)
    For a decimal floating constant, the significand is interpreted as a decimal rational number,
    and the digit-sequence of the exponent is interpreted as the integer power of 10 to which the significand has to be scaled.

    double d = 1.2e3; // decimal fraction 1.2 scaled by 10^3, that is 1200.0
    An unsuffixed floating constant has type double.
    If suffix is the letter f or F, the floating constant has type float.
    If suffix is the letter l or L, the floating constant has type long double.

    The result of evaluating a floating constant is either the nearest representable value or
    the larger or smaller representable value immediately adjacent to the nearest representable value,
    chosen in an implementation-defined manner (in other words, default rounding direction during translation is implementation-defined).

    Floating-point constants may convert to more range and precision than is indicated by their type, if indicated by FLT_EVAL_METHOD.
    For example, the constant 0.1f may act as if it were 0.1L in an expression.

    (since C99)
    The result of evaluating a hexadecimal floating constant, if FLT_RADIX is 2,
    is the exact value represented by the floating constant, correctly rounded to the target type.

    (since C99)
    If the exponent is present and fractional part is not used, the decimal separator may be omitted:

    double x = 1e0; // floating-point 1.0 (period not used)
    For decimal floating constants, the exponent part is optional.
    If it is omitted, the period is not optional, and either the whole-number or the fraction must be present.

    double x = 1.; // floating-point 1.0 (fractional part optional)
    double y = .1; // floating-point 0.1 (whole-number part optional)
    For hexadecimal floating constants, the exponent is not optional to avoid ambiguity resulting from an f suffix being mistaken as a hexadecimal digit.

    (since C99)
    Notes
    Default rounding direction and precision are in effect when the floating constants are converted into internal representations,
    and floating-point exceptions are not raised even if #pragma STDC FENV_ACCESS is in effect
    (for execution-time conversion of character strings, strtod can be used).
    Note that this differs from arithmetic constant expressions of floating type.

    Letters in the floating constants are case-insensitive: 0x1.ep+3 and 0X1.EP+3 represent the same floating-point value 15.0.

    The decimal point specified by setlocale has no effect on the syntax of floating constants: the decimal point character is always the period.

    Unlike integers, not every floating value can be represented directly by decimal or even hexadecimal constant syntax:
    macros NAN and INFINITY as well as functions such as nan offer ways to generate those special values.
    Note that 0x1.FFFFFEp128f, which might appear to be an IEEE float NaN, in fact overflows to an infinity in that format.

    There are no negative floating constants; an expression such as -1.2 is the arithmetic operator unary minus applied to the floating constant 1.2.
    Note that the special value negative zero may be constructed with -0.0.


    /**/

    /**2.INTEGER CONSTANT
    Link:https://en.cppreference.com/w/c/language/integer_constant

    Syntax
    An integer constant is a non-lvalue expression of the form

    decimal-constant integer-suffix(optional)	(1)
    octal-constant integer-suffix(optional)	(2)
    hex-constant integer-suffix(optional)	(3)
    where

    decimal-constant is a non-zero decimal digit (1, 2, 3, 4, 5, 6, 7, 8, 9), followed by zero or more decimal digits (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
    octal-constant is the digit zero (0) followed by zero or more octal digits (0, 1, 2, 3, 4, 5, 6, 7)
    hex-constant is the character sequence 0x or the character sequence 0X followed by one or more hexadecimal digits (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, A, b, B, c, C, d, D, e, E, f, F)
    integer-suffix, if provided, may contain one or both of the following
    (if both are provided, they may appear in any order):
    unsigned-suffix (the character u or the character U)
    long-suffix (the character l or the character L) or the
    long-long-suffix (the character sequence ll or the character sequence LL) (since C99)
    Explanation
    1) Decimal integer constant (base 10, the first digit is the most significant).
    2) Octal integer constant (base 8, the first digit is the most significant).
    3) Hexadecimal integer constant (base 16, the first digit is the most significant, the letters 'a' through 'f' represent the decimal values 10 through 15).
    The following variables are initialized to the same value:

    int d = 42;
    int o = 052;
    int x = 0x2a;
    int X = 0X2A;
    The type of the integer constant
    The type of the integer constant is the first type in which the value can fit, from the list of types which depends on which numeric base and which integer-suffix was used.

    Types allowed for integer constants:
    no suffix
    *************
    int
    ,long int
    ,unsigned long int (until C99)
    ,long long int (since C99)

    u or U suffix
    *****************
    unsigned int
    ,unsigned long int
    ,unsigned long long int(since C99)

    l or L suffix
    *****************
    long int
    ,unsigned long int(until C99)
    ,long long int(since C99)

    both l/L and u/U suffix
    *****************************
    unsigned long int
    ,unsigned long long int(since C99)

    ll or LL suffix
    ******************
    long long int(since C99)

    both ll/LL and u/U suffix
    ********************************
    unsigned long long int(since C99)

    If the value of the integer constant is too big to fit in any of the types allowed by suffix/base combination and the compiler supports extended integer types (such as __int128), the constant may be given the extended integer type; otherwise, the program is ill-formed.

    Notes
    Letters in the integer constants are case-insensitive: 0xDeAdBaBeU and 0XdeadBABEu represent the same number (one exception is the long-long-suffix, which is either ll or LL, never lL or Ll)

    There are no negative integer constants. Expressions such as -1 apply the unary minus operator to the value represented by the constant, which may involve implicit type conversions.

    When used in a controlling expression of #if or #elif, all signed integer constants act as if they have type intmax_t and all unsigned integer constants act as if they have type uintmax_t.

    Integer constants may be used in integer constant expressions.

    Due to maximal munch, hexadecimal integer constants ending in e and E, when followed by the operators + or -, must be separated from the operator with whitespace or parentheses in the source:

    int x = 0xE+2;   // error
    int y = 0xa+2;   // OK
    int z = 0xE +2;  // OK
    int q = (0xE)+2; // OK
    Otherwise, a single invalid preprocessing number token is formed, which causes further analysis to fail.
    /**/
    return 0;
}
