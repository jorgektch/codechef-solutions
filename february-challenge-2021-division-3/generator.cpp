#include<bits/stdc++.h>
using namespace std;

//Delaunay Triangulation functions
typedef long long ll;
bool ge(const ll& a, const ll& b) { return a >= b; }
bool le(const ll& a, const ll& b) { return a <= b; }
bool eq(const ll& a, const ll& b) { return a == b; }
bool gt(const ll& a, const ll& b) { return a > b; }
bool lt(const ll& a, const ll& b) { return a < b; }
int sgn(const ll& a) { return a >= 0 ? a ? 1 : 0 : -1; }

struct pt {
  ll x, y;
  pt() { }
  pt(ll _x, ll _y) : x(_x), y(_y) { }
  pt operator - (const pt& p) const {
    return pt(x - p.x, y - p.y);
  }
  ll cross(const pt& p) const {
    return x * p.y - y * p.x;
  }
  ll cross(const pt& a, const pt& b) const {
    return (a - *this).cross(b - *this);
  }
  ll dot(const pt& p) const {
    return x * p.x + y * p.y;
  }
  ll dot(const pt& a, const pt& b) const {
    return (a - *this).dot(b - *this);
  }
  ll sqrLength() const {
    return this->dot(*this);
  }
  bool operator == (const pt& p) const {
    return eq(x, p.x) && eq(y, p.y);
  }
  bool operator < (const pt& p) const{
    if(x != p.x) return x < p.x;
    return y  <p.y;
  }
};
bool ccw(pt a,pt b,pt c){
  return ((b-a).cross(c-b))>0;
}
bool convex(pt a,pt b,pt c,pt d){
  return (
      (ccw(a,b,c) && ccw(b,c,d) && ccw(c,d,a) && ccw(d,a,b)) || 
      (ccw(a,d,c) && ccw(d,c,b) && ccw(c,b,a) && ccw(b,a,d))
      );
}
int sgn(int v){
  if(v > 0) return 1;
  else if(v < 0) return -1;
  assert(false);
  return 0;
}

const pt inf_pt = pt(1e18, 1e18);

struct QuadEdge {
  pt origin;
  QuadEdge* rot = nullptr;
  QuadEdge* onext = nullptr;
  bool used = false;
  QuadEdge* rev() const {
    return rot->rot;
  }
  QuadEdge* lnext() const {
    return rot->rev()->onext->rot;
  }
  QuadEdge* oprev() const {
    return rot->onext->rot;
  }
  pt dest() const {
    return rev()->origin;
  }
};

QuadEdge* make_edge(pt from, pt to) {
  QuadEdge* e1 = new QuadEdge;
  QuadEdge* e2 = new QuadEdge;
  QuadEdge* e3 = new QuadEdge;
  QuadEdge* e4 = new QuadEdge;
  e1->origin = from;
  e2->origin = to;
  e3->origin = e4->origin = inf_pt;
  e1->rot = e3;
  e2->rot = e4;
  e3->rot = e2;
  e4->rot = e1;
  e1->onext = e1;
  e2->onext = e2;
  e3->onext = e4;
  e4->onext = e3;
  return e1;
}

void splice(QuadEdge* a, QuadEdge* b) {
  swap(a->onext->rot->onext, b->onext->rot->onext);
  swap(a->onext, b->onext);
}

void delete_edge(QuadEdge* e) {
  splice(e, e->oprev());
  splice(e->rev(), e->rev()->oprev());
  delete e->rot;
  delete e->rev()->rot;
  delete e;
  delete e->rev();
}

QuadEdge* connect(QuadEdge* a, QuadEdge* b) {
  QuadEdge* e = make_edge(a->dest(), b->origin);
  splice(e, a->lnext());
  splice(e->rev(), b);
  return e;
}

bool left_of(pt p, QuadEdge* e) {
  return gt(p.cross(e->origin, e->dest()), 0);
}

bool right_of(pt p, QuadEdge* e) {
  return lt(p.cross(e->origin, e->dest()), 0);
}

template <class T>
T det3(T a1, T a2, T a3, T b1, T b2, T b3, T c1, T c2, T c3) {
  return a1 * (b2 * c3 - c2 * b3) - a2 * (b1 * c3 - c1 * b3) +
    a3 * (b1 * c2 - c1 * b2);
}

bool in_circle(pt a, pt b, pt c, pt d) {
  // If there is __int128, calculate directly.
  // Otherwise, calculate angles.
#if defined(__LP64__) || defined(_WIN64)
  __int128 det = -det3<__int128>(b.x, b.y, b.sqrLength(), c.x, c.y,
      c.sqrLength(), d.x, d.y, d.sqrLength());
  det += det3<__int128>(a.x, a.y, a.sqrLength(), c.x, c.y, c.sqrLength(), d.x,
      d.y, d.sqrLength());
  det -= det3<__int128>(a.x, a.y, a.sqrLength(), b.x, b.y, b.sqrLength(), d.x,
      d.y, d.sqrLength());
  det += det3<__int128>(a.x, a.y, a.sqrLength(), b.x, b.y, b.sqrLength(), c.x,
      c.y, c.sqrLength());
  return det > 0;
#else
  auto ang = [](pt l, pt mid, pt r) {
    ll x = mid.dot(l, r);
    ll y = mid.cross(l, r);
    long double res = atan2((long double)x, (long double)y);
    return res;
  };
  long double kek = ang(a, b, c) + ang(c, d, a) - ang(b, c, d) - ang(d, a, b);
  if (kek > 1e-8)
    return true;
  else
    return false;
#endif
}

pair<QuadEdge*, QuadEdge*> build_tr(int l, int r, vector<pt>& p) {
  if (r - l + 1 == 2) {
    QuadEdge* res = make_edge(p[l], p[r]);
    return make_pair(res, res->rev());
  }
  if (r - l + 1 == 3) {
    QuadEdge *a = make_edge(p[l], p[l + 1]), *b = make_edge(p[l + 1], p[r]);
    splice(a->rev(), b);
    int sg = sgn(p[l].cross(p[l + 1], p[r]));
    if (sg == 0)
      return make_pair(a, b->rev());
    QuadEdge* c = connect(b, a);
    if (sg == 1)
      return make_pair(a, b->rev());
    else
      return make_pair(c->rev(), c);
  }
  int mid = (l + r) / 2;
  QuadEdge *ldo, *ldi, *rdo, *rdi;
  tie(ldo, ldi) = build_tr(l, mid, p);
  tie(rdi, rdo) = build_tr(mid + 1, r, p);
  while (true) {
    if (left_of(rdi->origin, ldi)) {
      ldi = ldi->lnext();
      continue;
    }
    if (right_of(ldi->origin, rdi)) {
      rdi = rdi->rev()->onext;
      continue;
    }
    break;
  }
  QuadEdge* basel = connect(rdi->rev(), ldi);
  auto valid = [&basel](QuadEdge* e) { return right_of(e->dest(), basel); };
  if (ldi->origin == ldo->origin)
    ldo = basel->rev();
  if (rdi->origin == rdo->origin)
    rdo = basel;
  while (true) {
    QuadEdge* lcand = basel->rev()->onext;
    if (valid(lcand)) {
      while (in_circle(basel->dest(), basel->origin, lcand->dest(),
            lcand->onext->dest())) {
        QuadEdge* t = lcand->onext;
        delete_edge(lcand);
        lcand = t;
      }
    }
    QuadEdge* rcand = basel->oprev();
    if (valid(rcand)) {
      while (in_circle(basel->dest(), basel->origin, rcand->dest(),
            rcand->oprev()->dest())) {
        QuadEdge* t = rcand->oprev();
        delete_edge(rcand);
        rcand = t;
      }
    }
    if (!valid(lcand) && !valid(rcand))
      break;
    if (!valid(lcand) ||
        (valid(rcand) && in_circle(lcand->dest(), lcand->origin,
                                   rcand->origin, rcand->dest())))
      basel = connect(rcand, basel->rev());
    else
      basel = connect(basel->rev(), lcand->rev());
  }
  return make_pair(ldo, rdo);
}

vector<tuple<pt, pt, pt>> delaunay(vector<pt> p) {
  sort(p.begin(), p.end(), [](const pt& a, const pt& b) {
      return lt(a.x, b.x) || (eq(a.x, b.x) && lt(a.y, b.y));
      });
  auto res = build_tr(0, (int)p.size() - 1, p);
  QuadEdge* e = res.first;
  vector<QuadEdge*> edges = {e};
  while (lt(e->onext->dest().cross(e->dest(), e->origin), 0))
    e = e->onext;
  auto add = [&p, &e, &edges]() {
    QuadEdge* curr = e;
    do {
      curr->used = true;
      p.push_back(curr->origin);
      edges.push_back(curr->rev());
      curr = curr->lnext();
    } while (curr != e);
  };
  add();
  p.clear();
  int kek = 0;
  while (kek < (int)edges.size()) {
    if (!(e = edges[kek++])->used)
      add();
  }
  vector<tuple<pt, pt, pt>> ans;
  for (int i = 0; i < (int)p.size(); i += 3) {
    ans.push_back(make_tuple(p[i], p[i + 1], p[i + 2]));
  }
  return ans;
}
//End Delaunay functions

//dsu
vector<int> parent;
int gp(int u){ return (u == parent[u] ? u : parent[u] = gp(parent[u])); }

struct testCase{
  vector<pt> p; //points
  vector<vector<int> > t; //triangles
  vector<int> b; //areas
};

vector<testCase> all;

//integer to string
string itos(int v){
  if(v == 0) return "0";   
  string ans = "";
  for(; v != 0; v /= 10) ans = string(1, '0' + (v % 10)) + ans;
  return ans;
}

//print all test cases 
void printAll(){
  int tc = 0;
  for(auto tst : all){
    string fname = itos(tc) + ".in";
    auto fl = freopen(fname.c_str(), "w", stdout);
    int n = tst.p.size();
    int m = tst.t.size();
    int r = tst.b.size();    
    printf("%d %d %d\n", n, m, r);
    for(int i = 0; i < n; i++){
      printf("%lld %lld\n", tst.p[i].x, tst.p[i].y);
    }
    for(auto tri: tst.t){
      printf("%d %d %d\n", tri[0] + 1, tri[1] + 1, tri[2] + 1);
    }
    for(int i = 0; i < r; i++){
      if(i != 0) printf(" ");
      printf("%d", tst.b[i]);
    }
    puts("");
    fclose(fl);
    tc++;
  }
}
pair<int,int> makeEdge(int u, int v){
  return {min(u,v), max(u,v)};
}
void replaceDiagonal(map<pair<int,int>, set<int> >&mp, int u, int v, int x, int y){
  auto e = makeEdge(u, v);
  assert(mp[e].count(x));
  mp[e].erase(x);
  mp[e].insert(y);
  assert(mp[e].size() <= 2);
}

int main(){
  srand(time(NULL)); // a different seed is used in the judge files
  int n = 1024;
  int mxc = 1e5;
  for(int F : {0, 64, 256}){
    for(int M : {64, 128, 256, 512}){
      vector<pt> points;
      while((int) points.size() < n){
        pt p(rand() % mxc, rand() % mxc);
        bool ok = true;
        for(auto q : points) if (p==q) ok = false;
        int sz = points.size();
        // no 3 collinear points
        for(int i = 0; i < sz && ok; i++)
          for(int j = i + 1; j < sz && ok; j++) 
            if((p - points[j]).cross(p - points[i]) == 0ll)
              ok = false;                              
        if(ok) points.push_back(p);
      }
      //mp[u,v] = {x : triangle uvx is in the triangulation}
      map<pair<int,int>, set<int> > mp;
      sort(points.begin(), points.end());
      auto d = delaunay(points);
      vector<vector<int> > delaunayTriangulation;
      for(auto tri : d){
        pt p, q, r;
        tie(p,q,r) = tri;
        int i = lower_bound(points.begin(), points.end(), p) - points.begin();
        int j = lower_bound(points.begin(), points.end(), q) - points.begin();
        int k = lower_bound(points.begin(), points.end(), r) - points.begin();
        mp[makeEdge(i,j)].insert(k);
        mp[makeEdge(j,k)].insert(i);
        mp[makeEdge(k,i)].insert(j);        
        delaunayTriangulation.push_back({i, j, k});
      }
      //edges shared by two triangles
      vector<pair<int,int> > diagonals;
      diagonals.clear();
      for(auto p : mp)
        if(p.second.size() == 2) 
          diagonals.push_back(p.first);
      
      //flipping F diagonals
      random_shuffle(diagonals.begin(), diagonals.end());
      int flips = 0;
      for(int i = 0; i < int(diagonals.size()) && flips < F; i++){
        auto diag = diagonals[i];
        int x = diag.first;
        int y = diag.second;
        if(mp[diag].size() != 2) continue;
        int s = *mp[diag].begin();
        int t = *mp[diag].rbegin();
        if(!convex(points[s], points[x] , points[t], points[y])) continue;
        mp.erase(diag);
        mp[makeEdge(s,t)] = {x,y};
        replaceDiagonal(mp, x, s, y, t);
        replaceDiagonal(mp, s, y, x, t);
        replaceDiagonal(mp, y, t, x, s);
        replaceDiagonal(mp, t, x, y, s);        
        flips++;
      }
      diagonals.clear();                    
      vector<vector<int> >striangles;
      for(auto p : mp){
        if(p.second.size() == 2) 
          diagonals.push_back(p.first);        
        int x = p.first.first;
        int y = p.first.second;
        for(int z : p.second){
          vector<int> tri = {x, y, z};
          sort(tri.begin(), tri.end());
          striangles.push_back(tri);
        }
      }
      sort(striangles.begin(), striangles.end());
      int nt = unique(striangles.begin(), striangles.end()) - striangles.begin();
      striangles.resize(nt);
      parent.resize(nt);
      iota(parent.begin(), parent.end(), 0);
      random_shuffle(diagonals.begin(), diagonals.end());      
      //removing M edges
      for(int it = 0; it < M; it++){
        int i = diagonals[it].first;
        int j = diagonals[it].second;
        int k = *mp[diagonals[it]].begin();
        int l = *mp[diagonals[it]].rbegin();
        vector<int>t1 = {i, j, k};
        sort(t1.begin(), t1.end());
        vector<int>t2 = {i, j, l};
        sort(t2.begin(), t2.end());
        int u = lower_bound(striangles.begin(),striangles.end(), t1) - striangles.begin();
        int v = lower_bound(striangles.begin(),striangles.end(), t2) - striangles.begin();
        assert(gp(u) != gp(v));
        parent[gp(u)] = gp(v);
      }      
      map<int,int> areas;
      for(int i = 0; i < nt; i++){
        int pi = gp(i);
        int x = striangles[i][0];
        int y = striangles[i][1];
        int z = striangles[i][2];
        ll area = (points[y] - points[x]).cross(points[z] - points[x]);
        if(area < 0) area = -area;
        areas[pi] += area;
      }
      vector<int> b;
      for(auto p : areas) b.push_back(p.second);
      sort(b.begin(),b.end());
      testCase tst = {points, delaunayTriangulation, b};
      all.push_back(tst);
      assert(delaunayTriangulation.size() - M == b.size());
    }
  }
  printAll();
  return 0;
}
