import pydot

with open("graph.dot", "r") as f, open("graph.txt", "w") as w:
	dot_string = f.read()
	graphs = pydot.graph_from_dot_data(dot_string)
	graph = graphs[0]

	nodes = graph.get_nodes()
	edges = graph.get_edges()

	edge_index = 0
	for node_index in range(len(nodes)):
		
		labels = str(nodes[node_index].get_label()).split(',')
		w.write(str(nodes[node_index].get_name()) + " " + str(len(labels)))
		if (edge_index == len(edges)):
			break
		while (str(edges[edge_index].get_source()).split(':')[0] == str(nodes[node_index].get_name())):
			w.write(" " + str(edges[edge_index].get_destination()))
			edge_index += 1
			if (edge_index == len(edges)):
				break
			
		w.write("\n")
