#include<iostream>
#include<bits/stdc++.h>
#include<fstream>

#include "io.h"

using namespace std;

int main()
{
	io *s = new io("input.txt","output.txt");
	s->readInputFile();
	return 0;
}