/* James Blair & John Carter
 * 4 - 15 - 15
 * Algorithms Project 3 : Path Finding
 */

package edu.uca.cub;

import java.util.ArrayList;
import java.util.Collections;

public class Building implements Comparable<Building> {
    public static final int LIST_1 = 1;
    public static final int LIST_2 = 2;

    // List to hold all currently created buildings.
    public static ArrayList<Building> List = new ArrayList<Building>();

    // Duplicate list.
    public static ArrayList<Building> List2 = new ArrayList<Building>();

    private String name;
    private ArrayList<Edge> adjacencies = new ArrayList<Edge>();
    private double minDistance = Double.POSITIVE_INFINITY;
    private Building previous = null;
    private String traversalPath = null;

    // Returns a reference to the building object with the given name. Returns null if the building cannot be found.
    public static Building findByName(String name, int list) {
        if (list == LIST_1) {
            for (Building building : List) {
                if (building.name.equalsIgnoreCase(name)) {
                    return building;
                }
            }
        } else {
            for (Building building : List2) {
                if (building.name.equalsIgnoreCase(name)) {
                    return building;
                }
            }
        }

        return null;
    }

    public Building(String name) {
        this.name = name;
        List.add(this);
    }

    public Building(Building toClone) {
        this.name = toClone.name;
        this.adjacencies = toClone.adjacencies;
        List2.add(this);
    }

    public void addEdge(Edge edge) {
        adjacencies.add(edge);
    }

    // Comparison for priority queue implementation.
    @Override
    public int compareTo(Building next) {
        return Double.compare(minDistance, next.minDistance);
    }

    public ArrayList<Edge> getAdjacencies() {
        return adjacencies;
    }

    public double getMinDistance() {
        return minDistance;
    }

    public String getName() {
        return name;
    }

    // Creates and returns a string representation of the traversal path required to get to the building.
    // Caches the calculated string.
    public String getPath() {
        if (traversalPath == null) {
            ArrayList<Building> path = new ArrayList<Building>();
            Building prev = this;

            // Add each sequential previous building to the list;
            while (prev != null) {
                path.add(prev);
                prev = prev.previous;
            }

            // Reverse the list so it starts with source building.
            Collections.reverse(path);

            traversalPath = "Path:[";
            for (int i = 0; i < path.size(); i++) {
                if (i != path.size() - 1) {
                    traversalPath += path.get(i).getName() + " > ";
                } else {
                    traversalPath += path.get(i).getName();
                }
            }

            traversalPath += "] Total Distance: " + minDistance;
        }

        return traversalPath;
    }

    public Building getPrevious() {
        return previous;
    }

    public void setMinDistance(double minDistance) {
        this.minDistance = minDistance;
    }

    public void setPrevious(Building previous) {
        this.previous = previous;
    }

    public String toString() {
        String toReturn = name + "\tDistance: " + minDistance + "\tPrevious Building: ";

        if (previous == null) {
            toReturn += "null";
        } else {
            toReturn += previous.name;
        }

        toReturn += "\tEdges: " + adjacencies.size();

        return toReturn;
    }
}
