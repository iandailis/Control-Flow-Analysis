# Control-Flow-Analysis
Final project for amiyak2-ryanbk2-dcondr2-idailis2

Presentation: https://www.youtube.com/watch?v=GOxeJ-KGsDQ

In order to compile and run the program, the following commands must be used:

clang++ main.cpp -o main src/graph/graph.cpp src/graph/dfs.cpp src/graph/getLoopNest.cpp src/graph/getShortestPath.cpp src/ParseToVector/VectorTuple.cpp -Wall -Werror -std=c++11

./main

To get your own data (parsed data is provided in the data folder):
1. Go to the data subdirectory and make a main.cpp file with at least one function.
2. clang++ main.cpp -S -emit-llvm
3. opt main.ll -dot-cfg
4. Copy the data from one of the generated .dot files (depending upon which function you are interested in studying) into graph.dot.
5. To visualize this file, go to https://dreampuf.github.io/GraphvizOnline and copy the contents of the .dot file into the editor.
6. python parse.py (YOU MUST HAVE PYDOT INSTALLED. https://pypi.org/project/pydot/ The command to install is: pip install pydot)
7. Now you have a parsed file inside graph.txt. IF RUN ON EWS, THIS FILE MUST BE CREATED IN A LINUX ENVIRONMENT. WINDOWS ADDS ITS OWN LINE ENDINGS
(https://stackoverflow.com/questions/1552749/difference-between-cr-lf-lf-and-cr-line-break-types). 

BRIEF OVERVIEW OF THE FILES USED FOR THIS PROJECT:

main.cpp: the main file that runs every algorithm and prints the output to the terminal.

In docs:
* Contract.md is our contract.
* Proposal.md is our proposal.
* README.md is our readme.

In WrittenReport:
* GOALS.md contains our goals.
* DEVLOG.md is our development log.
* RESULTS.md contains our results.

In data:
* graph.dot is a visualization of what the graph looks like, through the DOT graph description language.
* graph.txt is the output of the parser script.
* parse.py is a Python script that takes graph.dot and parses it, outputting the graph.txt file, which is used by the C++ code.
* The main.cpp file contains an iterative quick sort implementation, from which a CFG graph is generated.

In src:

-Graph:
* graph.h and graph.cpp are header and implementation files which contain the following functions:
    * A parameterized constructor that takes in a vector of tuples with all of the node, edge, and weight information.
    * A private variable graph_ that is a graph represented by an adjacency list.
 * getShortestPath.cpp contains the code that implements Dijkstra's shortest path algorithm.
 * getLoopNests.cpp contains the code that implementa Tarjans strongly connected components algorithm.
 * DFS.cpp contains the code that implements a DFS traversal of the control flow graph.

-ParseToVector:
 * VectorTuple.h and VectorTuple.cpp are header and implementation files which contain the following functions:
    * createTuple takes in indivdual parameters from a line of the input text file, and creates a tuple using it.
    * decodeLine receives the entire line of the text and breaks them into three strings and an int
    * createMap creates a vector map that takes in a vector of tuples containing three strings and an int via deccodeLine
    * getVector receives a text file as an input and converts that text file into a vector of tuples

In sacred texts:
* Our sacred texts.

TO TEST THE CODE:
* Use the previous instructions to generate data.
* Visualize the .dot file in https://dreampuf.github.io/GraphvizOnline
* Compare the output of the code with what you can see in the graph visualization.  
