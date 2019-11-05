# Project 4B
# A program coded in Python for "Application of BFS to flight scheduling"
# Jay Gupta, Ritwik Kanodia, Swathi Kumar Vembu, Aryaman Shaan, Soham Dandapath
# CZ2001 Algorithms, Lab 4, Group SS3
# School of Computer Science and Engineering
# Nanyang Technological University

import time
import pandas as pd

# Database

'''
#size = 5 LA to Sydney 3 Stops
graph = {'Los Angeles': ['Seoul'],
         'Seoul': ['Los Angeles', 'Singapore', ],
         'Singapore': ['Seoul', 'Hong Kong'],
         'Sydney': ['Hong Kong'],
         'Hong Kong': ['Singapore', 'Sydney'],
         }
'''


# size = 10 Sydney to Perth
graph = {'Los Angeles': ['Tokyo', 'Seoul'],
         'Seoul': ['Los Angeles', 'Tokyo', 'Singapore', 'Shanghai'],
         'Singapore': ['Sydney', 'Tokyo', 'Seoul', 'Shanghai', 'Hong Kong', 'Beijing'],
         'Sydney': ['Singapore', 'KL'],
         'Hong Kong': ['Singapore', 'Shanghai', 'Beijing'],
         'Shanghai': ['Hong Kong', 'Singapore', 'Seoul', 'Tokyo', 'Beijing'],
         'Beijing': ['Hong Kong', 'Singapore', 'Tokyo', 'Shanghai'],
         'Tokyo': ['Beijing', 'Shanghai', 'Seoul', 'Singapore', 'Los Angeles'],
         'Chicago': ['Perth', 'KL'],
         'KL': ['Chicago', 'Sydney'],
         'Perth': ['Chicago'],
         }


'''
#size = 15 Irvine to Seoul
graph = {'Los Angeles': ['Tokyo', 'Seoul', 'Paris'],
         'Seoul': ['Los Angeles', 'Tokyo', 'Singapore', 'Shanghai'],
         'Singapore': ['Sydney', 'Tokyo', 'Seoul', 'Shanghai', 'Hong Kong', 'Beijing', 'Chennai'],
         'Sydney': ['Singapore', 'KL', 'Paris'],
         'Hong Kong': ['Singapore', 'Shanghai', 'Beijing', 'Atlanta', 'New York'],
         'Shanghai': ['Hong Kong', 'Singapore', 'Seoul', 'Tokyo', 'Beijing'],
         'Beijing': ['Hong Kong', 'Singapore', 'Tokyo', 'Shanghai'],
         'Tokyo': ['Beijing', 'Shanghai', 'Seoul', 'Singapore', 'Los Angeles', 'Chennai'],
         'Chicago': ['Perth', 'KL', 'Chennai'],
         'KL': ['Chicago', 'Sydney'],
         'Perth': ['Chicago', 'Atlanta'],
         'Atlanta' : ['Perth', 'Irvine', 'Hong Kong'],
         'Irvine' : ['Atlanta', 'Chennai', 'Paris'],
         'Chennai' : ['Singapore', 'Tokyo', 'Chicago'],
         'Paris' : ['Los Angeles', 'Sydney'],
         'New York' : ['Hong Kong'],
         }
'''

'''
#size = 20 Barcelona to Hong Kong
graph = {'Los Angeles': ['Tokyo', 'Seoul', 'Paris'],
         'Seoul': ['Los Angeles', 'Tokyo', 'Singapore', 'Shanghai'],
         'Singapore': ['Sydney', 'Tokyo', 'Seoul', 'Shanghai', 'Hong Kong', 'Beijing', 'Chennai'],
         'Sydney': ['Singapore', 'KL', 'Paris', 'Venice'],
         'Hong Kong': ['Singapore', 'Shanghai', 'Beijing', 'Atlanta', 'New York'],
         'Shanghai': ['Hong Kong', 'Singapore', 'Seoul', 'Tokyo', 'Beijing'],
         'Beijing': ['Hong Kong', 'Singapore', 'Tokyo', 'Shanghai', 'Greece'],
         'Tokyo': ['Beijing', 'Shanghai', 'Seoul', 'Singapore', 'Los Angeles', 'Chennai'],
         'Chicago': ['Perth', 'KL', 'Chennai'],
         'KL': ['Chicago', 'Sydney', 'Venice', 'Greece'],
         'Perth': ['Chicago', 'Atlanta', 'Venice', 'Barcelona'],
         'Atlanta' : ['Perth', 'Irvine', 'Hong Kong', 'Greece'],
         'Irvine' : ['Atlanta', 'Chennai', 'Paris', 'Greece'],
         'Chennai' : ['Singapore', 'Tokyo', 'Chicago', 'Doha'],
         'Paris' : ['Los Angeles', 'Sydney', 'Doha'],
         'New York' : ['Hong Kong', 'Amsterdam', 'Doha'],
         'Amsterdam': ['New York', 'Barcelona'],
         'Doha': ['New York', 'Paris', 'Chennai'],
         'Venice':['KL', 'Perth', 'Sydney'],
         'Greece': ['Irvine', 'KL', 'Atlanta', 'Beijing'],
         'Barcelona': ['Amsterdam', 'Perth'],
         }
'''
# Displaying the graph as an adjacency matrix
graph_modifified = {}
graph_modified = {k: [v.strip() for v in vs] for k, vs in graph.items()}
edges = [(a, b) for a, bs in graph_modified.items() for b in bs]
df = pd.DataFrame(edges)
adj_matrix = pd.crosstab(df[0], df[1])

print(adj_matrix)

print()
print("--------------------------------\n")


# Breadth First Search Algorithm
def bfs(graph, depart, arrive):

    marked = []

    # Starting Vertex
    queue = [[depart]]

    while queue:
        # pop the first Vertex from the queue
        path = queue.pop(0)

        # get the last node from the Vertex
        node = path[-1]

        if node not in marked:
            neighbours = graph[node]

            for neighbour in neighbours:
                new_path = list(path)
                new_path.append(neighbour)
                queue.append(new_path)
                # return if neighbour is arrival destination
                if neighbour == arrive:
                    return new_path

            # set node as marked
            marked.append(node)

    # if no route is found.
    return "The route does not exist."


# depature destination
print("Enter Departure Destination:", end=" ")
departure = input()

# arrival destination
print("Enter Arrival Destination:", end=" ")
arrival = input()

# ---- OUTPUT ------
print("--------------------------------")

print("Departure:", departure)
print("Arrival:", arrival)

print()

print("Shortest Route: ")
start = time.time()
route = bfs(graph, departure, arrival)
print(route)
elapsed_time = time.time() - start

print()

no_of_stops = len(route) - 2
print("Number of Stops: ", no_of_stops)

print()

print("CPU Time:", elapsed_time*1000, "ms")

print("--------------------------------\n")

# ------ OUTPUT -------
