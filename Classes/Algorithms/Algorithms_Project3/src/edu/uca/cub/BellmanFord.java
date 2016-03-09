/* James Blair & John Carter
 * 4 - 15 - 15
 * Algorithms Project 3 : Path Finding
 */

package edu.uca.cub;

import java.util.ArrayList;

public class BellmanFord {
    private ArrayList<Building> buildings;

    public BellmanFord(ArrayList<Building> buildings) {
        this.buildings = buildings;
    }

    // Computes the shortest path from the source node to all other nodes.
    public void computePaths(Building source) {
        source.setMinDistance(0.0);

        // Runs n - 1 times.
        for (int i = 1; i < buildings.size() - 1; i++) {

            // Runs over all edges.
            for (Building building : buildings) {
                for (Edge edge : building.getAdjacencies()) {
                    if (edge.getTarget(
                            Building.LIST_2).getMinDistance() > building.getMinDistance() + edge.getDistance()) {
                        edge.getTarget(Building.LIST_2).setMinDistance(building.getMinDistance() + edge.getDistance());
                        edge.getTarget(Building.LIST_2).setPrevious(building);
                    }
                }
            }
        }

        if (hasNegativeCycle()) {
            System.err.println("Graph has a negative cycle. Shortest possible path cannot be computed!");
        }
    }

    // Simply prints the paths to each building.
    public void printPaths() {
        for (Building building : buildings) {
            System.out.println(building.getName() + "\n\t" + building.getPath());
        }
    }

    private boolean hasNegativeCycle() {
        // Runs over all edges.
        for (Building building : buildings) {
            for (Edge edge : building.getAdjacencies()) {
                if (edge.getTarget(Building.LIST_2).getMinDistance() > building.getMinDistance() + edge.getDistance()) {
                    return true;
                }
            }
        }

        return false;
    }
}
