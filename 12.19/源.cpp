#include"Graph.h"
using namespace std;
int main() {
	Graph<char,int> G;
	BinTree<char,int> T;
	G.CreateVertices(cin);
	G.DFS_Forrest(T);
	return 0;
}