import networkx as nx
import matplotlib.pyplot as plt
import argparse

if __name__=="__main__":
	parser = argparse.ArgumentParser()
	parser.add_argument("base_name")

	args = parser.parse_args()
	base_name = args.base_name
	G = nx.Graph()

	f =open(base_name+".graph")
	lines = f.readlines()
	for i in range(1,len(lines)):
		ab = lines[i].strip().split()
		G.add_edge(int(ab[0]),int(ab[1]))
	nx.draw(G, with_labels=True, font_weight='bold')
	# nx.draw(G,pos=nx.spring_layout(G))
	plt.show()
		# print(lines[i].strip())
