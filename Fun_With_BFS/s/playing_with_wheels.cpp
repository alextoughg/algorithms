// An example from UVa!

#include <set>
#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h> 

using namespace std;

struct Node_t{
	int config;
	int presses;
	Node_t(int init_config){
		config = init_config;
		presses = 0;
	}
	Node_t(int config_, int presses_){
		config = config_;
		presses = presses_;
	}
};

class PlayingWithWheels{
public:
	PlayingWithWheels(){
		int n;
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			printf("%d\n", BFS()); 
		}
	}
private:
	int BFS(){
		int init_config = readConfigAsInt();
		int target_config = readConfigAsInt();
		set<int> fc; int f; scanf("%d", &f);
		for(int i=0;i<f;i++){
			fc.insert(readConfigAsInt());
		}
		vector<bool> visited(9999, false);
		queue<Node_t> Q;
		if(fc.count(init_config) == 0){
			Q.push(Node_t(init_config));
			visited[init_config] = true;
		}

		while(!Q.empty()){
			Node_t c = Q.front(); Q.pop();
			int cc = c.config;
			if(cc == target_config){
				return c.presses;
			}
			int r[8];
			int one = cc / 1000;
			int one_r = cc % 1000;
			r[0] = ((one + 1)%10)*1000 + one_r;
			r[1] = ((one + 9)%10)*1000 + one_r;

			
			int two = one_r / 100;
			int two_r = one_r % 100;
			r[2] = one*1000+((two + 1)%10)*100 + two_r;
			r[3] = one*1000+((two + 9)%10)*100 + two_r;

			int three = two_r / 10;
			int three_r = two_r % 10;
			r[4] = one*1000+two*100+((three + 1)%10)*10 + three_r;
			r[5] = one*1000+two*100+((three + 9)%10)*10 + three_r;

			int four = three_r / 1;
			r[6] = one*1000+two*100+three*10+((four + 1)%10);
			r[7] = one*1000+two*100+three*10+((four + 9)%10);

			for(int j=0;j<8;j++){
				if(!visited[r[j]] && (fc.count(r[j]) == 0)){
					Q.push(Node_t(r[j], c.presses+1));
					visited[r[j]] = true;
				}
			}
		}
		return -1;
	}
	// x^y, efficiently. How can I make this iterative?
	int toThe(int x, int y){
		if(y == 0) return 1;
		else{
			if(y % 2 == 0){
				int t = toThe(x,y/2);
				return t*t;
			}
			else{
				int t = toThe(x, y-1);
				return x*t;
			}
		}
	}
	int readConfigAsInt(){
		int config = 0;
		for(int i=0;i<4;i++){
			int t;
			scanf("%d", &t);
			config += t*toThe(10,3-i);
		}
		return config;
	}
};

int main(){
	PlayingWithWheels p = PlayingWithWheels();
	return 0;
}
