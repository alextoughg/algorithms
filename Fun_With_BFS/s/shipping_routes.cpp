// A BFS problem from UVa!
#include <map>
#include <queue>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class ShippingRoutes{
public:
	ShippingRoutes(){
		int D; cin >> D;
		cout << "SHIPPING ROUTES OUTPUT" << endl;
		cout << endl;
		for(int i=0;i<D;i++){
			cout << "DATA SET " << i+1 << endl;
			cout << endl;
			BFS();
			cout << endl;
		}
		cout << "END OF OUTPUT" << endl;
	}
private:
	// See whether this works! ==> Yes!
	struct Node_t{
		int wh;
		int legs;
		Node_t(int wh_){
			wh = wh_;
			legs = 0;
		}
		Node_t(int wh_, int legs_){
			wh = wh_;
			legs = legs_;
		}
	};
	void BFS(){
		int M,N,P; cin >> M >> N >> P;
		map<string,int> mapping;
		for(int i=0;i<M;i++){
			string c; cin >> c;
			mapping[c] = i;
		}
		// Adjacency list
		vector<int> adj[M];
		for(int i=0;i<N;i++){
			string l,r; cin >> l >> r;
			int l_ = mapping[l];
			int r_ = mapping[r];
			adj[l_].push_back(r_);
			adj[r_].push_back(l_);
		}
		for(int i=0;i<P;i++){		
			vector<bool> visited(M,false);
			int ship_size,start, finish;
			string s,f; 
			cin >> ship_size >> s >> f;
			start = mapping[s]; finish = mapping[f];
			queue<Node_t> Q;
			Q.push(Node_t(start));
			visited[start] = true;
			bool fi = false;
			while(!Q.empty()){
				Node_t c = Q.front(); Q.pop();
				if(c.wh == finish){
					cout << "$" << ship_size*c.legs*100 << endl;
					fi = true;
					break;
				}
				vector<int> suc = adj[c.wh];
				
				for(int j=0;j<suc.size();j++){
					if(!visited[suc[j]]){
						Q.push(Node_t(suc[j],c.legs+1));
						visited[suc[j]] = true;
					}
				}
			}
			if(!fi) {
				cout << "NO SHIPMENT POSSIBLE" << endl;
			}
		}
	}
};

int main(){
	// Will not work cause it's private now!
	//Node_t n = Node_t(3,4);
	//cout << n.wh << endl;
	ShippingRoutes s = ShippingRoutes();
	return 0;
}
