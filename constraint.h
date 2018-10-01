#ifndef CONSTRAINT_H
#define CONSTRAINT_H

// #include <bits/stdc++.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

class constraint 
{
	
	public:
	
		vector< vector<int> > graph;
		int G,E,K;
		int c; //no of dummy variables
		vector< vector<int> > Clauses;
			
		/**
		 * Empty constructor.
		 */
		constraint();


		/**
		 * Generates an empty board of the given size.
		 * @param size is the size of the board, i.e. number of hexagons.
		 */
		constraint(vector< vector<int> > gr, int g, int e, int k);

		void clause1();

		void clause2();
		
		void clause3();
		
		bool Edge(int i, int j);

		void clause4();
		void clause5();
		void clause6();
		void printclauses(vector< vector<int> > myvec);
		int getNumDummyVar();
		vector< vector<int> > getClauses();
};
#endif

