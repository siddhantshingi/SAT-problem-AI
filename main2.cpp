#include<iostream>
#include<bits/stdc++.h>
#include<fstream>

#include "io.h"
#include "constraint.h"

using namespace std;

int main(int argc, char** argv)
{
	string inputfilenametemp = argv[1];
	io *s = new io(inputfilenametemp+".graph",inputfilenametemp+".subgraphs",inputfilenametemp+".satinput",inputfilenametemp+".satoutput");
	vector<int> vect;
	s->readInputSize();
	vect = s->readOutputFile_SAT();
	s->writeOutputFile(vect);
	return 0;
}