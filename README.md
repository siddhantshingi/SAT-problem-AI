# SAT PROBLEM - A3 COL333  
`./compile.sh`  
For compiling the core programs  
`g++ -o makegraph graphgenerator.cpp  `  
For compiling the tester program  
Install MiniSat and put the binary minisat in this folder itself  
`./run.sh test`  
For running the program if the file was test.graph  
`./rungenerator.sh G K U`  
Where G is number of nodes, K is number of subgraphs, U is unsat or sat  
`python visualize_graph.py test  `  
For visualizing the test.graph  
You need to do the following to do the visualization of program  
`
sudo pip install matplotlib  
`  
` 
sudo pip install networkx  
`

