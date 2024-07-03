#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct UnionFind
{
  vector<ll> par;
  UnionFind(ll N) : par(N)
  {
    for(int i=0;i<N;i++)
      par[i]=i;
  }
  ll root(ll x)
  {
    if(par[x]==x) return x;
    return par[x] = root(par[x]);
  }

  void unite(ll x, ll y)
  {
    ll rx = root(x);
    ll ry = root(y);
    if(rx == ry) return;
    par[rx]=ry;
  }

  bool same(ll x, ll y)
  {
    ll rx = root(x);
    ll ry = root(y);
    return rx == ry;
  }
};

ll V,E;

ll p[100010];

int main(void)
{
  cin >> V >> E;
  UnionFind tree(V);
  ll p_;

  for(int i=0;i<V;i++)
    {
    cin >> p_;
    p[i] = p_ -1;
    }
  ll x,y;
  for(int i=0;i<E;i++)
    {
      cin >> x >> y;
      x=x-1;
      y=y-1;
      tree.unite(x,y);
    }
  int ans=0;
  for(int i=0;i<V;i++)
    {
      if(tree.same(p[i],i))
       ans++;
    }
  cout << ans << endl;
  return 0;
       
     
}
