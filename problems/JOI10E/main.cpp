#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

typedef pair<ll,ll> P;

char maze[1001][1001];
ll H,W,N;
ll sx,sy,gx,gy;

ll d[1001][1001];
ll min_ = INF;
ll dx[4] = {1,0,-1,0};
ll dy[4] = {0,1,0,-1};
ll gxs[1001];
ll gys[1001];


void clear()
{
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++) d[i][j]=INF;
}

ll bfs()
{
  queue<P> que;
  que.push(P(sx,sy));
  d[sx][sy]=0;
  while(que.size())
    {
      P p = que.front();
      que.pop();
      //cout << "d["<<p.first<<"]["<<p.second<<"] = "<<d[p.first][p.second]<<endl;
      if(p.first == gx && p.second == gy) break;
      for(int i=0;i<4;i++)
	{
	  int nx = p.first+dx[i];
	  int ny = p.second+dy[i];
	  if(0<=nx && nx < H && 0<=ny && ny < W && maze[nx][ny]!='X' && d[nx][ny]==INF)
	    {
	      //cout << "(nx,ny) = " << nx << "," << ny << endl;
	      que.push(P(nx,ny));
	      d[nx][ny]=d[p.first][p.second]+1;
	    }
	}
    }
  return d[gx][gy];
}

void solve()
{
  ll ans=0;
  for(int i=0;i<N;i++)
    {
      gx=gxs[i];
      gy=gys[i];
      //cout <<"(sx,sy)"<<sx<<","<<sy<<endl;
      //cout <<"(gx,gy)"<<gx<<","<<gy<<endl;
      ans+=bfs();
      //cout << "ans"<< ans<<endl;
      clear();
      sx=gx;
      sy=gy;
    }
  cout << ans << endl;
}

int main(void)
{
  cin >> H >> W >> N;
  for(int i=0;i<H;i++)
    {
      for(int j=0;j<W;j++)
	d[i][j] = INF;
    }
  for(int i=0;i<H;i++)
    {
      for(int j=0;j<W;j++)
	{
	  char s;
	  cin >> s;
	  maze[i][j]=s;
	  if(s=='S')
	    {sx = i; sy  =j;}
	  else if(s!='X' && s!='.')
	    {int c=s-'0'; gxs[c-1]=i; gys[c-1]=j;}
	}
    }
  solve();
  return 0;
}
