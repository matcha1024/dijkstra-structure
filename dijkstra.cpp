const long long INF = 1LL << 60;
struct edge{long long to, cost;};
typedef pair<long long, long long> P;
struct graph{
  long long V;
  vector<vector<edge> > G;
  vector<long long> d;

  graph(long long n){
    V = n;
    G.resize(V);
    d.resize(V);
    fill(d.begin(), d.end(), INF);
  }

  void add_edge(long long s, long long t, long long cost){
    edge e1;
    e1.to = t, e1.cost = cost;
    G[s].push_back(e1);

    //無向グラフのとき
    //edge e2;
    //e2.to = s, e2.cost = cost;
    //G[t].push_back(e2);
  }

  void dijkstra(long long s){
    fill(d.begin(), d.end(), INF);
    d[s] = 0;
    priority_queue<P,vector<P>, greater<P> > pq;
    pq.push(P(0,s));
    while(!pq.empty()){
      P p = pq.top(); pq.pop();
      long long v = p.second;
      if(d[v]<p.first) continue;
      for(auto e : G[v]){
        if(d[e.to]>d[v]+e.cost){
          d[e.to] = d[v]+e.cost;
          pq.push(P(d[e.to],e.to));
        }
      }
    }
  }

  long long dist(long long t) {return d[t];}
};