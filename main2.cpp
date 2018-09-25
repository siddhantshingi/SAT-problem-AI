#include<iostream>
#include<bits/stdc++.h>
#include<fstream>

#include "io.h"
#include "constraint.h"

using namespace std;

int main()
{
	io *s = new io("input.txt","output.txt","input_SAT.txt","output_SAT.txt");
	vector<int> vect;
	s->readInputFile();
	vect = s->readOutputFile_SAT();
	s->writeOutputFile(vect);
	return 0;
}