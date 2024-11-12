#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

// Function to compute (a^b) % MOD using fast exponentiation
long long modExp(long long a, long long b, long long mod)
{
    long long result = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

// Function to compute factorial % MOD
vector<long long> fact(200002, 1);
void factorial()
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 200000; ++i)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

vector<long long> ans(100000);

// Function to compute the number of ways to triangulate the polygon
void triangulate()
{
    for (int n = 1; n <= 100000; n++)
    {
        if (n < 3)
        {
            ans[n] = 0;
            continue;
        }

        long long numerator = fact[2 * (n - 2)];
        long long denominator = (fact[n - 1] * fact[n - 2]) % MOD;

        // Applying modular inverse using Fermat's little theorem
        long long result = (numerator * modExp(denominator, MOD - 2, MOD)) % MOD;

        ans[n] = result;
    }
}

int main()
{
    factorial();
    triangulate();
    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        cout << ans[n] << endl;
    }

    return 0;
}