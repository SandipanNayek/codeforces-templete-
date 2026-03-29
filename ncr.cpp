const int MOD = 1e9+7;
const int N = 200000;

long long fact[N+1], invfact[N+1];

long long power(long long a, long long b){
    long long r = 1;
    while(b){
        if(b&1) r = r*a % MOD;
        a = a*a % MOD;
        b >>= 1;
    }
    return r;
}

void init(){
    fact[0] = 1;
    for(int i=1;i<=N;i++) fact[i] = fact[i-1]*i % MOD;

    invfact[N] = power(fact[N], MOD-2);
    for(int i=N-1;i>=0;i--) invfact[i] = invfact[i+1]*(i+1) % MOD;
}

long long nCr(int n, int r){
    if(r<0 || r>n) return 0;
    return fact[n]*invfact[r]%MOD*invfact[n-r]%MOD;
}
