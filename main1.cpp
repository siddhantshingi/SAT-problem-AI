#include<iostream>
#include<bits/stdc++.h>
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

	vect = t->clause1(vect);
	// cout<<"Clause1 done"<<endl;
	// cout<<"vector size: "<<vect.size()<<endl;

	// t->printclauses(vect);
	
	vect = t->clause2(vect);
	// cout<<"Clause2 done"<<endl;
	// cout<<"vector size: "<<vect.size()<<endl;
	// t->printclauses(vect);
	
	vect = t->clause3(vect);
	// cout<<"Clause3 done"<<endl;
	// cout<<"vector size: "<<vect.size()<<endl;
	// t->printclauses(vect);
	
	vect = t->clause4(vect);
	// cout<<"Clause4 done"<<endl;
	// cout<<"vector size: "<<vect.size()<<endl;
	// t->printclauses(vect);
	
	s->writeInputFile_SAT(vect,t->getNumDummyVar(),vect.size());
	
	return 0;
}