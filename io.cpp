#include "io.h"

io::io () {
}

io::io (string inFile, string outFile) {
	inputFile = inFile;
	outputFile = outFile;	
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