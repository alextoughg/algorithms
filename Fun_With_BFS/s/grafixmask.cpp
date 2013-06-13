// An algorithm using BFS flood fill!
#include <queue>
#include <set>
#include <iostream>
#include <algorithm>
#include <string.h>
#define H 400
#define W 600

using namespace std;

// F if map[i][j] is a barrier, T otherwise.
bool map[H][W];

// Node type 
struct node_t{
	// Fields
	int h;
	int w;
	node_t(){
		h = 0; 
		w = 0;
	}
	node_t(int h_, int w_){
		h = h_;
		w = w_;
	}
};

// We define < operator so 
// 'seen' set can know what to do
bool operator<(const node_t &x, const node_t &y){
	if(x.w != y.w) 
		return x.w < y.w;
	else
		return x.h < y.h;
}

// Which nodes have already been seen
// Notice that this may vary depending on 
// what information you want to use to 
// classify a node as seen, although the 
// node should contain the information and 
// that information only. 
bool seen [H][W] ;

int BFS(node_t s, vector<node_t> (*successors)(node_t))
{

	int count = 0;
	queue<node_t> Q;
	
	Q.push(s);
	seen[s.h][s.w] = true;

	while(!Q.empty()){
		node_t n = Q.front(); 
		Q.pop();
		count += 1;
		// Who are n's successors?
		vector<node_t> succ = successors(n);
		for(int i=0;i<succ.size();i++){
			int h_ = succ[i].h;
			int w_ = succ[i].w;
			if(!seen[h_][w_] && map[h_][w_]){
				Q.push(succ[i]);
				seen[h_][w_] = true;
			}
		}
	}
	return count;
}


vector<node_t> successors(node_t n){
	vector<node_t> succ;
	int offset[4][2] = {{-1,0}, {1,0},{0,1}, {0,-1}};
	for(int i=0;i<4;i++){
		int h_ = n.h + offset[i][0];
		int w_ = n.w + offset[i][1];
		if(0 <= h_  && h_ < H){
			if(0 <= w_  && w_ < W){
				succ.push_back(node_t(h_,w_));
			}
		}
	}
	return succ;
}

vector<int> FloodFill(){
	vector<int> areas;
	int i,j;
	memset(seen, false, sizeof(seen));

	while(true){
		for(i=0;i<H;i++){
			for(j=0;j<W;j++){
				if(!seen[i][j] && map[i][j]) {
					break;
				}
			}
			if(j < W) break;
		}
		if(i == H && j == W) break;
		areas.push_back(BFS(node_t(i, j), &successors));	
	}
	
	// Sort areas from smallest to largest.
	sort(areas.begin(), areas.end());
	return areas;
}

void setMap(int rectangles[][4]){

	memset(map, true, sizeof(map));
	for(int k=0;k<4;k++){
		
		int row_tl = rectangles[k][0];
		int col_tl = rectangles[k][1];
		int row_br = rectangles[k][2];
		int col_br = rectangles[k][3];

		for(int i=row_tl;i<=row_br;i++){
			for(int j=col_tl;j<=col_br;j++){
				map[i][j] = false;
			}
		}
	}
}


vector<string> tokenizer(string f, string delim){
    vector<string> result;
    int p,t;
    if ((p = f.find(delim))== string::npos){
        result.push_back(f);
    }
    else{
        result.push_back(f.substr(0,p));
        t = p;
        while((p = f.find(delim, t+1)) != string::npos){
            result.push_back(f.substr(t+1, p-(t+1)));
            t = p;
        }
        result.push_back(f.substr(t+1, p-(t+1)));
    }
    return result;
}


int main(){
	
	int rectangles [][4] = {{50, 300, 199, 300}, {201, 300, 350, 300}, {200, 50, 200, 299}, {200, 301, 200, 550}};
	setMap(rectangles);
	vector<int> r = FloodFill();
	for(int i=0;i<r.size();i++){
		cout << r[i] << endl;
	}
	return 0;
}
