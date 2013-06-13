#include <queue>
#include <set>
#include <iostream>

using namespace std;

// Node type 
struct node_t{
	// Fields
	int n;
	// Constructor(s)
	node_t(){
		n = 0;
	}
	node_t(int s){
		n = s;
	}
};

// We define < operator so 
// 'seen' set can know what to do
bool operator<(const node_t &x, const node_t &y){
	return x.n < y.n;
}

// Which nodes have already been seen
// Notice that this may vary depending on 
// what information you want to use to 
// classify a node as seen, although the 
// node should contain the information and 
// that information only. 
set<node_t> seen;

void BFS(node_t s, bool (*goal)(node_t), void (*calculateSolution)(node_t), 
	vector<node_t> (*successors)(node_t))
{
	
	queue<node_t> Q;
	
	Q.push(s);
	seen.insert(s);

	while(!Q.empty()){
		node_t n = Q.front(); 
		Q.pop();
		if(goal(n)){
			calculateSolution(n);
			break;
		}
		// Who are n's successors?
		vector<node_t> succ = successors(n);
		for(int i=0;i<succ.size();i++){
			if(seen.count(succ[i]) == 0){
				Q.push(succ[i]);
				seen.insert(succ[i]);
			}
		}
	}
}

// Some examples
// Find the smallest number larger than 15 that 
// is a multiple of 3.
bool goal(node_t n){
	if(n.n > 15 && (n.n % 3 == 0)) return true;
	return false;
}

void calculateSolution(node_t n){
	cout << n.n << endl;
}

vector<node_t> successors(node_t n){
	vector<node_t> succ;
	for(int i=0;i<3;i++){
		succ.push_back(node_t(n.n + i));
	}
	return succ;
}

int main(){
	BFS(node_t(), &goal, &calculateSolution, &successors);
	return 0;
}