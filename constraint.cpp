#include "constraint.h"

constraint::constraint () {
}

constraint::constraint (vector< vector<int> > gr, int g, int e, int k) {
	graph = gr;
	G = g;
	E = e;
	K = k;
}

vector< vector<int> > constraint::clause1(vector< vector<int> > setOfClauses) {

	for(int j=0; j<K; j++)
	{
		vector<int> v;
		for(int i=0; i<N; i++)
		{
			int l = j*K+i;
			v.push_back(l);
		}
		setOfClauses.push_back(v);
	}
	return setOfClauses;

}

vector< vector<int> > constraint::clause2(vector< vector<int> > setOfClauses) {
	
}

vector< vector<int> > constraint::clause3(vector< vector<int> > setOfClauses) {
	
}

bool constraint::Edge(int i, int j) {
	for(int k=0; k<G; k++)
	{
		if (graph.at(i).at(k) == j)
			return true;
	}
	return false;
}

vector< vector<int> > constraint::clause4(vector< vector<int> > setOfClauses) {
	for(int i=0; i<G; i++)
	{
		for(int j=0; j<G; j++)
		{
			if (!Edge(i,j)) //Edge(i,j) returns true if graph k ith row me j is found
			{
				for(int m=0; m<K; m++)
				{
					int l1 = m*K + i;
					int l2 = m*K + j;
					vector<int> v;
					v.push_back(-1*l1);
					v.push_back(-1*l2);
					setOfClauses.push_back(v);
				}
			}
		}
	}
}