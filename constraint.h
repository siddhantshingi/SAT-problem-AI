#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include <bits/stdc++.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class constraint 
{
	
	public:
	
		vector< vector<int> > graph;
		int G,E,K;
		int c; //no of dummy variables
			
		/**
		 * Empty constructor.
		 */
		constraint();


		/**
		 * Generates an empty board of the given size.
		 * @param size is the size of the board, i.e. number of hexagons.
		 */
		constraint(vector< vector<int> > gr, int g, int e, int k);

		vector< vector<int> > clause1(vector< vector<int> > setOfClauses);

		vector< vector<int> > clause2(vector< vector<int> > setOfClauses);
		
		vector< vector<int> > clause3(vector< vector<int> > setOfClauses);
		
		bool Edge(int i, int j);

		vector< vector<int> > clause4(vector< vector<int> > setOfClauses);
		vector< vector<int> > clause5(vector< vector<int> > setOfClauses);
		vector< vector<int> > clause6(vector< vector<int> > setOfClauses);
		void printclauses(vector<vector<int>> myvec);
		int getNumDummyVar();
};
#endif

