# SAT problem | AI
C++ project which formulates the following problem as a SAT problem and solves it using miniSAT.

# Problem Statement
You are an investigative agency working on uncovering the hidden connections between the various drug agencies. You have got telephone records of various telephone numbers which are believed to be associated with the mafia. Some external source has suggested that there are K different drug agencies with several people part of multiple agencies. Your goal is to automatically uncover the various drug agencies from the telephone records. To solve this problem, you make a few assumptions:

# Each person has exactly one phone.
All drug agencies are very close-knit: if two people are in the same agency they must have called each other.
People don't directly call anyone outside their agency.
No agency is a strict subsidiary of another agency.
# Input Format
The first line has three numbers: number of vertices in G, number of edges in G and K. Nodes are represented by positive integers starting from 1. Each subsequent line represents an edge between two nodes.

# Output Format
Each subgraph will be prefaced with a #i |Gi| indicating that it is the ith subgraph of number of vertices |Gi|. Post that, mention the vertices in one line.

# Installation
Requirements
Linux
miniSAT
Sublime-text
matplotlib

`$ sudo apt-get install minisat`

For visualizing the test.graph  
You need to do the following to do the visualization of program  
`
sudo pip install matplotlib  
`  
` 
sudo pip install networkx  
`


# SAT PROBLEM - A3 COL333  
`./compile.sh`  
For compiling the core programs  
`g++ -o makegraph graphgenerator.cpp  `  
For compiling the tester program  
Install MiniSat and put the binary of any other minisat if you need in this folder itself  
`./run.sh test`  
For running the program if the file was test.graph  
`./rungenerator.sh G K U`  
Where G is number of nodes, K is number of subgraphs, U is unsat or sat  
`python visualize_graph.py test  `  

