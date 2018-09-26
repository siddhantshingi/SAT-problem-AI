#include "constraint.h"

constraint::constraint () {
}

constraint::constraint (vector< vector<int> > gr, int g, int e, int k) {
	// is doing the below ok ? will it do deep copy?
	graph = gr;
	G = g;
	E = e;
	K = k;
	c = 1;
}

vector< vector<int> > constraint::clause1(vector< vector<int> > setOfClauses) {

	for(int j=0; j<K; j++)
	{
		vector<int> v;
		for(int i=0; i<G; i++)
		{
			int l = j*G+i + 1;
			v.push_back(l);
		}
		setOfClauses.push_back(v);
	}
	return setOfClauses;

}

vector< vector<int> > constraint::clause2(vector< vector<int> > setOfClauses) {
	for(int i=0; i<G; i++)
	{
		for(int n=0; n<graph.at(i).size(); n++)
		{
			vector<int> dummy_var;
			int j = graph.at(i).at(n);
			for(int m=0; m<K; m++)
			{
				int l1 = m*G + i + 1;
				int l2 = m*G + j + 1;
				int d = (K-1)*G + (G-1) + c + 1;
				dummy_var.push_back(d);
				c++;

				vector<int> v1;
				v1.push_back(-1*l1);
				v1.push_back(-1*l2);
				v1.push_back(d);

				vector<int> v2;
				v2.push_back(l1);
				v2.push_back(-1*d);

				vector<int> v3;
				v3.push_back(l2);
				v3.push_back(-1*d);

				setOfClauses.push_back(v1);
				setOfClauses.push_back(v2);
				setOfClauses.push_back(v3);
					
			}
			setOfClauses.push_back(dummy_var);
	
		}
		
	}
	return setOfClauses;
}

vector< vector<int> > constraint::clause3(vector< vector<int> > setOfClauses) {
	for(int m=0; m<K; m++)
	{
		for(int n=0; n<K; n++)
		{
			if (m != n)
			{
				vector<int> dummy_var;
				for(int i=0; i<G; i++)
				{
					int l1 = m*G + i + 1;
					int l2 = n*G + i + 1;
					int d = (K-1)*G + (G-1) + c + 1;
					dummy_var.push_back(d);
					c++;

					vector<int> v1;
					v1.push_back(-1*l1);
					v1.push_back(l2);
					v1.push_back(d);

					vector<int> v2;
					v2.push_back(l1);
					v2.push_back(-1*d);

					vector<int> v3;
					v3.push_back(-1*l2);
					v3.push_back(-1*d);

					setOfClauses.push_back(v1);
					setOfClauses.push_back(v2);
					setOfClauses.push_back(v3);
				}
				setOfClauses.push_back(dummy_var);
	
			}
		}
	}
	return setOfClauses;
}

bool constraint::Edge(int i, int j) {
	for(int n=0; n<graph.at(i).size(); n++)
	{
		if (graph.at(i).at(n) == j)
			return true;
	}
	return false;
}

vector< vector<int> > constraint::clause4(vector< vector<int> > setOfClauses) {
	for(int i=0; i<G; i++)
	{
		for(int j=i+1; j<G; j++)
		{
			if (!Edge(i,j) && (i != j) && !Edge(j,i)) //Edge(i,j) returns true if graph k ith row me j is found
			{
				cout<<"    edge not found in i: "<<i<<" j: "<<j<<endl;
				for(int m=0; m<K; m++)
				{
					int l1 = m*G + i + 1;
					int l2 = m*G + j + 1;
					vector<int> v;
					v.push_back(-1*l1);
					v.push_back(-1*l2);
					setOfClauses.push_back(v);
				}
			}
		}
	}
	return setOfClauses;
}
void constraint::printclauses(vector<vector<int>> myvec){
	for(int i=0;i<myvec.size();i++){
		for(int j=0;j<myvec.at(i).size();j++){
			cout << myvec.at(i).at(j)<< " ";
		}
		cout<< endl;
	}
	cout << "clauses printed"<<endl;;
}