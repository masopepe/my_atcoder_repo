#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100001];
ll s[100001];

ll N,K;

const ll INF = 1LL << 60;

void solve()
{
  ll max = -INF;
  for(int i=0;i<N;i++)
    {
      if(i+K>=N)
	{
	  cout << max << endl;
	  return;
	}
      ll m = s[i+K] - s[i];
      if(m>max)
	max = m;
    }
}

int main(void)
{
  while(1)
    {
  cin >> N >> K;
  if(N == 0 && K == 0)
    return 0;
  for(int i=0;i<N;i++)
    cin >> a[i];
  s[0] = 0;
  for(int i=1;i<N+1;i++)
    s[i] = s[i-1]+a[i];
  solve();
    }
  return 0;
}
