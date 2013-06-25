// Not completely functional. Use at own risk!
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node_t{
	
	bool to_right;
	int m_a;
	int m_b;
	int c_a;
	int c_b;
	int steps;

	Node_t(int M, int C){
		to_right = true;
		m_a = M; c_a = C; m_b = 0; c_b = 0;
		steps = 0;
	}

	Node_t(bool ctr, int cm_a, int cm_b, int cc_a, int cc_b, int csteps){
		to_right = ctr; m_a = cm_a; m_b = cm_b; c_a = cc_a; c_b = cc_b; steps = csteps;
	}
};

int calculatePos(int m_a, int m_b, int c_a, int c_b, int to_right, int M, int C){
	return (M*C*C*2)*m_a + (C*C*2)*m_b + (C*2)*c_a + 2*c_b + to_right;
}

// Appending & at the end of argument makes the compiler use call by reference 
// on that argument. Prepending const is for call by reference values that 
// the function will not change.
/*void successors(int s, queue<Node_t>& Q, vector<bool>& visited, int M, int C, 
	int R, int m, int c, const Node_t& cn){
	//cout << cn.c_a << endl;

	int m_a, m_b, c_a, c_b;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=c;j++){
			if(i+j>=s && i+j<=R && (i>=j || i==0)){
				if(cn.to_right){
					m_b = cn.m_b + i;
					c_b = cn.c_b + j;
					m_a = m-i;
					c_a = c-j;
				}
				else{
					m_a = cn.m_a + i;
					c_a = cn.c_a + j;
					m_b = m-i;
					c_b = c-j;
				}

				if((m_b>=c_b || m_b == 0) && (m_a>=c_a || m_a == 0)){
					if(!visited[calculatePos(m_a, m_b, c_a, c_b, M, C)]){
						Q.push(Node_t(!cn.to_right, m_a, m_b, c_a, c_b, cn.steps+1));
						//cout << m_a << ":" << m_b << ":" << c_a << ":" << c_b << endl;
						visited[calculatePos(m_a, m_b, c_a, c_b, M, C)] = true;
					}
				}
			}
		}
	}
}*/

int BFS(int M, int C, int R){
	vector<bool> visited(M*M*C*C*2, false);
	queue<Node_t> Q;
	Q.push(Node_t(M,C));
	bool first = true;
	int m,c;
	while(!Q.empty()){
		Node_t cn = Q.front(); Q.pop();
		if(cn.m_b == M && cn.c_b == C){
			return cn.steps;
		}

		//cout << cn.m_a << ":" << cn.m_b << ":" << cn.c_a << ":" << cn.c_b << endl;

		if(cn.to_right){
			m = cn.m_a; c = cn.c_a;
		} else{
			m = cn.m_b; c = cn.c_b;
		}

		if(!first){
			//successors(1, Q, visited, M, C, R, m, c, cn);
			int m_a, m_b, c_a, c_b;
			for(int i=0;i<=m;i++){
				for(int j=0;j<=c;j++){
					if(i+j>=1 && i+j<=R && (i>=j || i==0)){
						if(cn.to_right){
							m_b = cn.m_b + i;
							c_b = cn.c_b + j;
							m_a = m-i;
							c_a = c-j;
						}
						else{
							m_a = cn.m_a + i;
							c_a = cn.c_a + j;
							m_b = m-i;
							c_b = c-j;
						}

						if((m_b>=c_b || m_b == 0) && (m_a>=c_a || m_a == 0)){
							int t;
							if(cn.to_right){
								t = 1;
							} else{
								t = 0;
							}
							if(!visited[calculatePos(m_a, m_b, c_a, c_b, t, M, C)]){
								Q.push(Node_t(!cn.to_right, m_a, m_b, c_a, c_b, cn.steps+1));
								visited[calculatePos(m_a, m_b, c_a, c_b, t, M, C)] = true;
							}
						}
					}
				}
			}
		}
		else{
			//successors(2, Q, visited, M, C, R, m, c, cn);
			int m_a, m_b, c_a, c_b;
			for(int i=0;i<=m;i++){
				for(int j=0;j<=c;j++){
					if(i+j>=2 && i+j<=R && (i>=j || i==0)){
						if(cn.to_right){
							m_b = cn.m_b + i;
							c_b = cn.c_b + j;
							m_a = m-i;
							c_a = c-j;
						}
						else{
							m_a = cn.m_a + i;
							c_a = cn.c_a + j;
							m_b = m-i;
							c_b = c-j;
						}

						if((m_b>=c_b || m_b == 0) && (m_a>=c_a || m_a == 0)){
							int t;
							if(cn.to_right){
								t = 1;
							} else{
								t = 0;
							}
							if(!visited[calculatePos(m_a, m_b, c_a, c_b, t, M, C)]){
								Q.push(Node_t(!cn.to_right, m_a, m_b, c_a, c_b, cn.steps+1));
								visited[calculatePos(m_a, m_b, c_a, c_b, t, M, C)] = true;
							}
						}
					}
				}
			}
			first = false;
		}
	}
	return -1;
}

int main(){
	//cout << BFS(3,3,2) << endl;
	//cout << BFS(4,4,2) << endl;
	cout << BFS(10,8,3) << endl;
	//cout << BFS(100,100,20) << endl;
	//cout << BFS(100,99,2) << endl;
}
