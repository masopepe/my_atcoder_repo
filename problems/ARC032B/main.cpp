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

  void solve(ll N)
  {
    for(int i=0;i<N;i++)
      root(i);
    sort(par.begin(),par.end());
    ll prev;
    ll ans=0;
    prev=par[0];
    for(int i=1;i<N;i++)
      {
	//cout << "prev:" << prev << "cur:" << par[i] << endl;
      if(prev!=par[i])
	{
	  ans=ans+1;
	  prev = par[i];
	}
      }
    cout << ans << endl;
  }
  
};

ll V,E;

int main(void)
{
  cin >> V >> E;
  UnionFind tree(V);
  ll a,b;
  for(int i=0;i<E;i++)
    {
      cin >> a >> b;
      a=a-1;
      b=b-1;
      tree.unite(a,b);
    }
  tree.solve(V);
  return 0;
}
