# ElectronicBillboardNet

Implementation of a C++ program to connect all the sites (public places) within a neighborhood 
together via a wired network to install advertising terminals

# Usage
To run the tp3 program, execute it from the command line with the following syntax:
```sh
./tp3 carte.txt
```

Replace carte.txt with the filename that specifies the map of the neighborhood sites and the cost data associated with installing billboards on each street.

The program will output the results to the standard output (stdout) using the C++ std::cout stream.

### Format of carte.txt

The carte.txt file should be structured as follows:

1. List of sites (nodes), each specified by a name (a string).
2. Three dashes (---) as a separator.
3. List of streets for billboard installation, each specified by:
    - Street name (a string).
    - Colon (:).
    - Pair of sites representing the starting point and ending point of a street.
    - Installation cost on this street segment.
    - Semicolon (;).
4. Three dashes (---) as an end delimiter.

# Output Format

The tp3 program should display the output as follows:

1. First, display the sites, with one node per line.
2. Then, display the edges in ascending alphanumeric order of the starting nodes. If multiple edges have the same starting node, display them in ascending alphanumeric order of the ending nodes.
3. For each edge, display the following on a line:
    - Street name: street0
    - Edge vertices: a b
    - Label: 4
      
After displaying all edges:

1. Three dashes (---) as a separator.
2. The total cost of billboard installation on the last line.<br>
Example output format:  
```sh
a
b
c
d
e
f
g
h
i
rue0 a b 4
rue1 a h 8
rue6 c d 7
rue4 c i 2
rue8 d e 9
rue5 f c 4
rue10 g f 2
rue12 h g 1
---
37
```
