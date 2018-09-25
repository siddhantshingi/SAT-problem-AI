#include "io.h"

io::io () {
}

io::io (string inFile, string outFile,string inFile_SAT, string outFile_SAT) {
	inputFile = inFile;
	outputFile = outFile;	
	inputFile_SAT = inFile_SAT;
	outputFile_SAT = outFile_SAT;	
}

void io::readInputFile() {
	ifstream file (inputFile);
	if (file.is_open())
	{
		file >> G >> E >> K;
		cout << "read G,E,K : "<<G<<" "<<E<<" "<<K<<endl;
		for(int i=0;i<G;i++)
		{
			vector<int> v;
			graph.push_back(v);
		}
		for(int i=0;i<E;i++)
		{
			int s,l;
			file >> s >> l;
			graph.at(s-1).push_back(l-1);
			cout<<" edge added : "<<s-1<<" "<<l-1<<endl;
		}
	}
	else 
		cout << "Unable to open file"; 
}

void io::writeInputFile_SAT(vector< vector<int> > subgraphs) {

}

vector<int> io::readOutputFile_SAT() {

}

void io::writeOutputFile(vector<int> subgraphs) {

}

vector< vector<int> > io::getGraph() {
	return graph;
}

int io::getG() {
	return G;
}

int io::getE() {
	return E;
}

int io::getK() {
	return K;
}