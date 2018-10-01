#include<iostream>
// #include<bits/stdc++.h>
#include<fstream>

#include "io.h"
#include "constraint.h"

using namespace std;

int main(int argc, char** argv)
{
	string inputfilenametemp = argv[1];
	// io *s = new io(inputfilenametemp+".graph",inputfilenametemp+".satinput",inputfilenametemp+".satoutput",inputfilenametemp+".subgraphs");
	io *s = new io(inputfilenametemp+".graph",inputfilenametemp+".subgraphs",inputfilenametemp+".satinput",inputfilenametemp+".satoutput");	
	// cout << "argument is "<< argv[1]<<endl;
	s->readInputFile();

	constraint *t = new constraint(s->getGraph(),s->getG(),s->getE(),s->getK());
	// cout<<"input file read done"<<endl;
	vector< vector<int> > vect;
	// t->printclauses(vect);
	// vector<int> tempvec;
	// tempvec.push_back(1);
	// vect.push_back(tempvec);
	t->clause6();
	// cout<< "6th clause applied"<<endl;
	// t->printclauses(vect);

	t->clause1();
	// cout<<"Clause1 done"<<endl;
	// cout<<"vector size: "<<vect.size()<<endl;

	// t->printclauses(vect);
	
	t->clause2();
	// cout<<"Clause2 done"<<endl;
	// cout<<"vector size: "<<vect.size()<<endl;
	// t->printclauses(vect);
	
	t->clause3();
	// cout<<"Clause3 done"<<endl;
	// cout<<"vector size: "<<vect.size()<<endl;
	// t->printclauses(vect);
	
	t->clause4();
	// cout<<"Clause4 done"<<endl;
	// cout<<"vector size: "<<vect.size()<<endl;
	// t->printclauses(vect);
	vect = t->getClauses();
	s->writeInputFile_SAT(vect,t->getNumDummyVar(),vect.size());
	
	return 0;
}