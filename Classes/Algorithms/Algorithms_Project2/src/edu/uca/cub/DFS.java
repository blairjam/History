/* James Blair & John Carter
 * 3 - 16 - 15
 * Algorithms Project 2 : Topological Ordering
 */

package edu.uca.cub;

import java.util.ArrayList;

public class DFS {
    private ArrayList<Vertex> classes;
    private int visit = 1;

    // Performs a depth-first search on the classes list.
    public void dfs() {
        // Loops over each vertex in the list.
        for (Vertex vertex : classes) {
            //If it has not yet been visited, begin exploring the vertex.
            if (!vertex.isVisited()) {
                explore(vertex);
            }
        }
    }

    public ArrayList<Vertex> getClasses() {
        return classes;
    }

    public void setClasses(ArrayList<Vertex> classes) {
        this.classes = classes;
    }

    // Recursive continuation of the depth-first search.
    private void explore(Vertex vertex) {
        vertex.setVisited(true);

        // Assign the pre-visit number to the vertex.
        vertex.setPreVisit(visit);
        visit++;

        // Loop across all connected edges of the current vertex.
        for (Edge edge : vertex.getEdges()) {
            // Since each vertex is unique, a simple O(n) search is used to
            // find the vertex that is specified by the given edge.
            for (Vertex v : classes) {
                // The correct vertex has been found.
                if (edge.getDesignation().equalsIgnoreCase(v.getDesignation())) {
                    // Explore the vertex if it has not already been visited.
                    if (!v.isVisited()) {
                        explore(v);
                    }
                }
            }
        }

        // Assign the post-visit number to the vertex.
        vertex.setPostVisit(visit);
        visit++;
    }
}
