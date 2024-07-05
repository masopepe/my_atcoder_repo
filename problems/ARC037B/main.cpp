#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> es[110];
bool isvisited[110];


ll N,  M;

ll min_element()
{
  for(int i=0;i<N;i++)
    if(!isvisited[i])
      return i;
  return -1;
}

bool dfs(int s, int from)
{
  bool ret =true;
  if(isvisited[s])
    ret = false;
  isvisited[s]=true;
  for(int i=0;i<es[s].size();i++)
    {
      if(es[s][i] != from)
	{
	  if(isvisited[es[s][i]]) return false;
	  else return dfs(es[s][i],s);
	  /*cout <<"start:" << s << "to: " << es[s][i] << endl;*/
	}
    }
  return ret;
}

void  solve()
{
  ll  ans=0;
  while(true)
    {
      ll i = min_element();
      if(i<0) break;
      //cout << "visit, i = "<<isvisited[i]<<","<<i<<endl;
      if(!isvisited[i])
	{
	  if(dfs(i,i)) ans++;
	  //cout << "dfs end  " << endl;
	}
    }
  cout << ans  <<  endl;
}

int main(void)
{
  cin >> N >>  M;
  for(int i=0;i<N;i++)
    {isvisited[i]=false;}
  ll v1,v2;
  for(int i=0; i<M; i++)
    {
      cin >> v1 >> v2;
      v1=v1-1;
      v2=v2-1;
      es[v1].push_back(v2);
      es[v2].push_back(v1);
    }
  solve();
  return 0;
}
