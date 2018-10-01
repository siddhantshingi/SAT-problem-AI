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

void constraint::clause1() {

	for(int j=0; j<K; j++)
	{
		vector<int> v;
		for(int i=0; i<G; i++)
		{
			int l = j*G+i + 1;
			v.push_back(l);
		}
		Clauses.push_back(v);
	}
	
}

void constraint::clause2() {
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

				Clauses.push_back(v1);
				Clauses.push_back(v2);
				Clauses.push_back(v3);
					
			}
			Clauses.push_back(dummy_var);
	
		}
		
	}
	
}

void constraint::clause3() {
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

					Clauses.push_back(v1);
					Clauses.push_back(v2);
					Clauses.push_back(v3);
				}
				Clauses.push_back(dummy_var);
	
			}
		}
	}
}

bool constraint::Edge(int i, int j) {
	for(int n=0; n<graph.at(i).size(); n++)
	{
		if (graph.at(i).at(n) == j)
			return true;
	}
	return false;
}

void constraint::clause4() {
	for(int i=0; i<G; i++)
	{
		for(int j=i+1; j<G; j++)
		{
			if (!Edge(i,j) && (i != j) && !Edge(j,i)) //Edge(i,j) returns true if graph k ith row me j is found
			{
				// cout<<"    edge not found in i: "<<i<<" j: "<<j<<endl;
				for(int m=0; m<K; m++)
				{
					int l1 = m*G + i + 1;
					int l2 = m*G + j + 1;
					vector<int> v;
					v.push_back(-1*l1);
					v.push_back(-1*l2);
					Clauses.push_back(v);
				}
			}
		}
	}
}

void constraint::clause5() {
	// vector<int> mytemp;
	// mytemp.push_back(1);
	// setOfClauses.push_back(mytemp);
	for(int i=0;i<K-1;i++){
		int l1 = i*G + 1;
		int l2 = (i+1)*G +1;
		vector<int> v;
		v.push_back(1*l1);
		v.push_back(-1*l2);
		Clauses.push_back(v);
	}
}

void constraint::clause6(){
	vector<int> mytemp;
	mytemp.push_back(1);
	Clauses.push_back(mytemp);
	vector<int> setvar;
	setvar.push_back(0);
	int graphdecidedcounter = 0;
	int tempsetvarsize= 0;
	while(tempsetvarsize!=setvar.size() && graphdecidedcounter<K-1){
		tempsetvarsize = setvar.size();
		for(int i=0;i<G;i++){
			auto it = find(setvar.begin(),setvar.end(),i);
			if(it == setvar.end()){
				bool exclusive= true;
				for(int j:setvar){
					if(Edge(i,j)||Edge(j,i)){
						exclusive=false;
						break;
					}
				}
				if(exclusive){
					//set i to true in graphdecidedcounter+1 and false for all 0 to graphdecidedcounter
					// cout << " setting stuff for i "<< i << " and graphdecidecounter "<< graphdecidedcounter<<endl;
					for(int j=0;j<=graphdecidedcounter;j++){
						int l1 = j*G+i+1;
						vector<int> temp;
						temp.push_back(-l1);
						Clauses.push_back(temp);
					}
					int l1 = (graphdecidedcounter+1)*G + i + 1;
					vector<int> temp;
					temp.push_back(l1);
					Clauses.push_back(temp);
					graphdecidedcounter++;
					setvar.push_back(i);
				}
			}
		}
	}
	for(int i=graphdecidedcounter+1;i<K-1;i++){
		int l1 = i*G + 1;
		int l2 = (i+1)*G +1;
		vector<int> v;
		v.push_back(1*l1);
		v.push_back(-1*l2);
		Clauses.push_back(v);
	}
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

int constraint::getNumDummyVar() {
	return c;
}

vector< vector<int> > constraint::getClauses() {
	return Clauses;
}