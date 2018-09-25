#include<iostream>
#include<bits/stdc++.h>
#include<fstream>

#include "io.h"
#include "constraint.h"

using namespace std;

int main()
{
	io *s = new io("input.txt","output.txt","input_SAT.txt","output_SAT.txt");
	s->readInputFile();

	constraint *t = new constraint(s->getGraph(),s->getG(),s->getE(),s->getK());
	cout<<"input file read done"<<endl;
	vector< vector<int> > vect;
	
	vect = t->clause1(vect);
	cout<<"Clause1 done"<<endl;
	cout<<"vector size: "<<vect.size()<<endl;
	
	vect = t->clause2(vect);
	cout<<"Clause2 done"<<endl;
	cout<<"vector size: "<<vect.size()<<endl;
	
	vect = t->clause3(vect);
	cout<<"Clause3 done"<<endl;
	cout<<"vector size: "<<vect.size()<<endl;
	
	vect = t->clause4(vect);
	cout<<"Clause4 done"<<endl;
	cout<<"vector size: "<<vect.size()<<endl;
	
	s->writeInputFile_SAT(vect);
	
	return 0;
}