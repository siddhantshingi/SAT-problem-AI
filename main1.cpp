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
	vector< vector<int> > vect;
	vect = t->clause1(vect);
	vect = t->clause2(vect);
	vect = t->clause3(vect);
	vect = t->clause4(vect);
	s->writeInput_SAT(vect);
	
	return 0;
}