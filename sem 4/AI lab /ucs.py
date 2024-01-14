# Import the PriorityQueue class from the queue module
from queue import PriorityQueue

# Define the uniform_cost_search function that takes a graph, start node, and goal node as input
def uniform_cost_search(graph, start, goal):
    
    # Create an empty priority queue
    frontier = PriorityQueue()
    
    # Add the start node to the priority queue with a path cost of 0
    frontier.put((0, start))

    # Create an empty dictionary to keep track of the path
    came_from = {}

    # Create a dictionary to keep track of the cost of reaching each node
    cost_so_far = {start: 0}

    # Continue searching until the priority queue is empty or the goal is found
    while not frontier.empty():
        
        # Dequeue the node with the lowest path cost from the priority queue
        current_cost, current_node = frontier.get()

        # If the goal is found, return the path and its cost
        if current_node == goal:
            
            # Create a list to store the optimal path from start to goal
            path = [current_node]
            
            # Traverse the came_from dictionary to construct the optimal path
            while current_node in came_from:
                current_node = came_from[current_node]
                path.append(current_node)
                
            # Reverse the path so that it goes from start to goal
            path.reverse()
            
            # Return the optimal path and its cost
            return path, cost_so_far[goal]

        # Explore the neighbors of the current node
        for neighbor, weight in graph[current_node].items():
            
            # Calculate the new cost of reaching the neighbor through the current node
            new_cost = cost_so_far[current_node] + weight

            # If the neighbor has not been visited or the new cost is lower than the previous cost
            if neighbor not in cost_so_far or new_cost < cost_so_far[neighbor]:
                
                # Update the cost of reaching the neighbor
                cost_so_far[neighbor] = new_cost

                # Add the neighbor to the priority queue with its path cost as its priority
                priority = new_cost
                frontier.put((priority, neighbor))

                # Update the came_from dictionary
                came_from[neighbor] = current_node

    # If the goal is not found, return None
    return None, None

# Define the graph as a dictionary with nodes as keys and their neighbors and weights as values
graph = {
    "s": {"1": 2, "3": 5},
    "1": {"g": 1},
    "2": {"1": 4},
    "3": {"1": 5, "g": 6, "4": 2},
    "4": {"2": 4, "5": 5},
    "5": {"2": 6, "g": 5},
    "g": {"4": 7}
}
graph_nodes = {'A': {'B':2,'E': 3},
               'B': {'A': 2, 'C': 1, 'G': 9},
               'C': {'B': 1},
               'D': {'E': 6, 'G': 1},
               'E': {'A': 3, 'D': 6},
               'G': {'B': 9, 'D': 1}}

start_node = 'A'
goal_node = 'G'

# Call the uniform_cost_search function with the graph, start node, and goal node as input
path, cost = uniform_cost_search(graph_nodes, "A", "G")

# Print the optimal path and its cost
print("Optimal path:", path)
print("Cost of optimal path:", cost)
