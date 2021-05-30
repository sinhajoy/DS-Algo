// Created by Priyanshu

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;
using namespace std;

#define M                    1000000007
#define pi                   3.14159265358979323846
#define ll                   long long
#define lld                  long double

// Pair
#define pii                  pair<int, int>
#define pll                  pair<ll, ll>

// Vector
#define vl                   vector<ll >
#define vi                   vector<int>
#define vpi                  vector<pii>
#define vpl                  vector<pll>
#define pb                   push_back
#define mp                   make_pair


// Search
#define lb                   lower_bound
#define ub                   upper_bound
#define mina                 *min_element
#define mama                 *max_element
#define bsrch                binary_search


////////
#define F                    first
#define S                    second
#define cel(x,a)             (((x) + (a) - 1) / (a))
#define all(v)               v.begin(), v.end()
#define countofbits(n)       __builtin_popcountll(n)
#define lcm(m, n)            (((m) / __gcd((m), (n)))*(n))
#define oset                 tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define deb(...)             cout << "(" << #__VA_ARGS__ << "):", dbg(__VA_ARGS__)
#define ms(arr, v)           memset(arr, v, sizeof(arr))
#define pf(x,y)              setfill('x')<<setw(y)
#define ps(x,y)              fixed << setprecision(y) << x
#define _X_                  ios_base::sync_with_stdio(false); cin.tie(NULL)


///////////////////////////////

int II;
long long I_O;
char CC, SS[20];
const int N = 1e5 + 4;

///////////////////////////////


// Input / Output
#define scn(str)             scanf("%s", str)
#define pri(str)             printf("%s\n", str)
#define inp(a, n)            for(int Ele=0; Ele<(n); Ele++)a[Ele]=read()
#define inp1(a, n)           for(int Ele=1; Ele<=(n); Ele++)a[Ele]=read()
inline  ll  read()           { II = 1, I_O = 0; while (!isdigit(CC = getchar())) if (CC == '-') II = -1; while (isdigit(CC)) I_O = I_O * 10 + CC - '0', CC = getchar(); return I_O * II;}
inline void wonl()           { putchar('\n');}
inline void  wws()           { }
inline void  dbg()           { cout << endl; }
inline void ww(ll k)         { if (k < 0) putchar('-'), k *= -1; II = 0; while (k)SS[++II] = k % 10, k /= 10; if (!II) SS[++II] = 0; while (II)putchar(SS[II--] + '0');}
inline void ww(pll p)        { ww(p.F), putchar(' '), ww(p.S); }


// bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {return (a.S < b.S);}

// struct compare {
//     bool operator()(const pair<int, int>& value, const int& key) {return (value.F < key);}
//     bool operator()(const int& key, const pair<int, int>& value) {return (key < value.F);}
// };




template <typename T, typename... V>
inline void wonl(T t, V... v) {ww(t); if (sizeof...(v))putchar(' '); wonl(v...);}


template <typename T, typename... V>
inline void  wws(T t, V... v) {ww(t); putchar(' '); wws(v...);}


template <typename T, typename... V>
inline void  dbg(T t, V... v) {cout << ' ' << t; dbg(v...);}


// always type cast before using v.size()


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



vi g[N];
bool vis[N];
int n;
const int LG = 20;

int parent[LG][N];
int level[N];

void dfs(int k, int par)
{
    parent[0][k] = par;
    for (auto it : g[k])
        if (it != par) {
            level[it] = level[k] + 1;
            dfs(it, k);
        }
}



void precompute()
{
    for (int i = 1; i < LG; i++)
        for (int j = 1; j <= n; j++)
            if (parent[i - 1][j])
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
}

int LCA(int u, int v)
{
    if (level[u] < level[v])
        swap(u, v);
    int diff = level[u] - level[v];
    for (int i = LG - 1; i >= 0; i--)
    {
        if ((1 << i) & diff)
        {
            u = parent[i][u];
        }
    }
    if (u == v)
        return u;
    for (int i = LG - 1; i >= 0; i--)
    {
        if (parent[i][u] && parent[i][u] != parent[i][v])
        {
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}

int dist(int u, int v)
{
    return level[u] + level[v] - 2 * level[LCA(u, v)];
}


int walk(int u, int h)
{
    for (int i = LG - 1; i >= 0; i--)
    {
        if ((h >> i) & 1)
            u = parent[i][u];
    }
    return u;
}


void inpgraph(int m) {
    int a, b;
    while (m--)a = read(), b = read(), g[a].emplace_back(b), g[b].emplace_back(a);
}








void solve() {



    n = read();
    int Q = read();
    for (int i = 0; i <= n; i++) {

        for (int j = 0; j < LG; j++)
            parent[j][i] = 0;

        vis[i] = 0;
        level[i] = 0;
        g[i].clear();
    }

    inpgraph(n - 1);

    dfs(1, 0);
    precompute();


    while (Q--) {

        int k = read();
        vi v(k);

        for (int i = 0; i < k; i++)
            v[i] = read();

        int act = -1;
        int node = -1, sec = -1;

        for (int i = 0; i < k; i++) {
            int dis = dist(v[i], v[0]);

            if (dis > act)
                act = dis, node = v[i];
        }



        act = -1;

        for (int i = 0; i < k; i++) {

            int dis = dist(v[i], node);

            if (dis > act)
                act = dis, sec = v[i];

        }





        if (level[node] < level[sec])
            swap(node, sec);


        if (act & 1) {


            act /= 2;

            node = walk(node, act);

            sec = parent[0][node];

            if (node > sec)
                swap(node, sec);

            wonl(2, node, sec);

        }
        else
            wonl(1, walk(node, act / 2));




    }


}












int main()
{
    // _X_;
    // clock_t time_req = clock();


    int t = read();
    while (t--)
        solve();


    // time_req = clock() - time_req;
    // cout << (float)time_req / CLOCKS_PER_SEC;
    return 0;
}
