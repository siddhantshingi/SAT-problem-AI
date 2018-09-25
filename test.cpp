#include<iostream>
#include<bits/stdc++.h>
#include<fstream>

using namespace std;

int main()
{
	ofstream file ("input_SAT.txt");
	if (file.is_open())
	{
		int s=3;
		file<<"p cnf ";
	}
	else 
		cout << "Unable to open file";
	return 0;
}