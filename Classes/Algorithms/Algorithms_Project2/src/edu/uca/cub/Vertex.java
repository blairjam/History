/* James Blair & John Carter
 * 3 - 16 - 15
 * Algorithms Project 2 : Topological Ordering
 */

package edu.uca.cub;

import java.util.ArrayList;

public class Vertex {
    private String designation;
    private String name;
    private ArrayList<Edge> edges = new ArrayList<Edge>();
    private boolean visited = false;
    private int preVisit;
    private int postVisit;

    public Vertex() {
        this(null, null);
    }

    public Vertex(String designation, String name) {
        this.designation = designation;
        this.name = name;
    }

    public void addEdge(Edge edge) {
        edges.add(edge);
    }

    public String getDesignation() {
        return designation;
    }

    public ArrayList<Edge> getEdges() {
        return edges;
    }

    public String getName() {
        return name;
    }

    public int getPostVisit() {
        return postVisit;
    }

    public int getPreVisit() {
        return preVisit;
    }

    public boolean isVisited() {
        return visited;
    }

    public void setDesignation(String designation) {
        this.designation = designation;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setPostVisit(int postVisit) {
        this.postVisit = postVisit;
    }

    public void setPreVisit(int preVisit) {
        this.preVisit = preVisit;
    }

    public void setVisited(boolean visited) {
        this.visited = visited;
    }

    public String toString() {
        return designation + " " + name;
    }
}
