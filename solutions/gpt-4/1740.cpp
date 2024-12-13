#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct Event {
	ll x,y1,y2,type,idx;
	bool operator <(const Event& a) const {
		if(x!=a.x) return x<a.x;
		return type<a.type;
	}
};

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<Event> E;
	vector<ll> Y;
	for(int i=0; i<n; ++i) {
		ll x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1==x2) {
			E.push_back({x1,min(y1,y2),max(y1,y2),0,i});
			Y.push_back(y1);
			Y.push_back(y2);
		} else {
			E.push_back({min(x1,x2),y1,y1,1,i});
			E.push_back({max(x1,x2),y1,y1,2,i});
			Y.push_back(y1);
		}
	}
	sort(E.begin(),E.end());
	sort(Y.begin(), Y.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	ll ans=0;
	set<Event> now;
	for(auto &e:E) {
		e.y1=lower_bound(Y.begin(), Y.end(),e.y1)-Y.begin()+1;
		e.y2=lower_bound(Y.begin(), Y.end(),e.y2)-Y.begin()+1;
		
		if(e.type==0) {
			auto it=now.lower_bound(Event{-1,e.y1,-1,-1,-1});
			while(it!=now.end()&&it->y1<=e.y2) {
				if(it->type==1) ++ans;
				if(it->type==2) --ans;
				++it;
			}
		} else {
			if(e.type==1) {
				now.insert({-1,e.y1,-1,-1,e.idx});
			} else {
				now.erase({-1,e.y1,-1,-1,e.idx});
			}
		}
	}
	cout << ans << "\n";
}