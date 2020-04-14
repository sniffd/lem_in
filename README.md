# Lem-in
school21 good algorithmic project

In this project we have to lead ants from the start of anthill to the terminal.We will meet some graphs here.

### Lem-in algorithm
* parse and validate input
* choose better ways from graph(anthill)
* send ants to the exit

##### Parsing rules
* we keep all incoming rooms in our tree and after push all rooms(except rooms without adjecency) to the array of rooms  
* in the file(need to upload later)

##### Finding paths
We are using algorithm BFS to find shortest path(path itself is linked list). Then send its path to the Edmonds-Karp algorithm which fill path 0/1 with 1/1 and build reverse edges 0/-1 from B to A.
Edmonds-karp algorithm allows us to find disjoint paths this way. But i did not improve path selection.  
Path selection itself is a formula `t = (l + a) / k -(+) 1`
* where *t* = time for which this number of ants(*a*) reach the exit with the number of paths (*k*), and length of all paths (*l*);
* "-1" or "+1": if (l+a)%k == 0 then -1 else +1  

Distribution of ants along found paths occurs according to the formula `na = (l + a)/k - li`
* where (*na*) = number of ants which need to distribute on line (*li*)
