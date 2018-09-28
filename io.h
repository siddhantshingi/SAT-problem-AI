#ifndef IO_H
#define IO_H

#include <bits/stdc++.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class io 
{
	
	public:
	
		string inputFile,outputFile,inputFile_SAT,outputFile_SAT;
		vector< vector<int> > graph;
		int G,E,K;
			
		/**
		 * Empty constructor.
		 */
		io();


		/**
		 * Generates an empty board of the given size.
		 * @param size is the size of the board, i.e. number of hexagons.
		 */
		io(string inFile, string outFile,string inFile_SAT, string outFile_SAT);

		void readInputFile();
		void readInputSize();

		void writeInputFile_SAT(vector< vector<int> > subgraphs, int c, int clauses);

		vector<int> readOutputFile_SAT();

		void writeOutputFile(vector<int> subgraphs);


		vector< vector<int> > getGraph();

		int getG();

		int getE();
		
		int getK();
		


};
#endif
