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
		}
		// cout<<"G is "<<G<< " E is "<< E<< " K is "<<K<<endl;
	}
	else 
		cout << "Unable to open file"; 
}

void io::readInputSize() {
	ifstream file (inputFile);
	if (file.is_open())
	{
		file >> G >> E >> K;
	}
	else 
		cout << "Unable to open file"; 
}

void io::writeInputFile_SAT(vector< vector<int> > cons, int c, int clauses) {
	ofstream file (inputFile_SAT);
	if (file.is_open())
	{
		// cout <<"chatl kdfls"<<endl;
		file<<"p cnf "<<G*K + c - 1<<" "<<clauses<<endl;
		for(int i=0; i<cons.size(); i++)
		{
			for(int j=0; j<cons.at(i).size(); j++)
			{
				if (cons.at(i).at(j) >= 0)
					file<<cons.at(i).at(j)<<" ";
				else
					file<<cons.at(i).at(j)<<" ";
			}
			file<<"0"<<endl;
		}
	}
	else 
		cout << "Unable to open file";
}

vector<int> io::readOutputFile_SAT() {
	ifstream file (outputFile_SAT);
	vector<int> v;
	if (file.is_open())
	{
		string s;
		file >> s;
		if (s.at(0) == 'S')
		{	
			for(int i=0;i<K*G;i++)
			{
				int l;
				file >> l;
				v.push_back(l);
			}
		}
	}
	else 
		cout << "Unable to open file"; 
	return v;
}

void io::writeOutputFile(vector<int> subgraphs) {
	vector<int> output[K];
	for(int i=0; i<subgraphs.size(); i++)
	{
		if (subgraphs.at(i) > 0)
		{
			int m = subgraphs.at(i) - 1;
			int a = m/G;
			int b = m%G;
			output[a].push_back(b);
		}
	}
	ofstream file (outputFile);
	if (file.is_open())
	{
		if (subgraphs.size() == 0)
		{
			file<<"0"<<endl;
			return;
		}
		for(int i=0; i<K; i++)
		{
			file<<"#"<<i+1<<" "<<output[i].size()<<endl;
			for(int j=0; j<output[i].size(); j++)
			{
				file<<output[i].at(j)+1<<" ";
			}
			file<<endl;
		}
	}
	else 
		cout << "Unable to open file";
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