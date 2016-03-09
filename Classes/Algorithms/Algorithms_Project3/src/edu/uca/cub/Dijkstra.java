/* James Blair & John Carter
 * 4 - 15 - 15
 * Algorithms Project 3 : Path Finding
 */

package edu.uca.cub;

import java.util.PriorityQueue;
import java.util.ArrayList;

/* Some notes:
   The Java priority queue does not reorder the elements within it as the values of those elements change.
   So, every time the values of an element are altered, the element must be removed and re-inserted into the queue.
   This ensures that the queue will be reordered with the new values in consideration.
   For this reason, every modification of building values is surrounded by a removal and re-insertion of that building
   in the building queue.
 */

public class Dijkstra {
    private PriorityQueue<Building> buildingQueue;
    private ArrayList<Building> cloud = new ArrayList<Building>();

    public Dijkstra(PriorityQueue<Building> buildingQueue) {
        this.buildingQueue = buildingQueue;
    }

    // Implementation of Dijkstra's Algorithm.
    public void computePaths(Building source) {

        // Set the distance to the starting node to zero.
        buildingQueue.remove(source);
        source.setMinDistance(0.0);
        buildingQueue.add(source);

        while (!buildingQueue.isEmpty()) {
            // Remove the next building from the queue.
            Building nextShortest = buildingQueue.poll();

            // Loops over each edge of the current building.
            for (Edge edge : nextShortest.getAdjacencies()) {
                // If a new shorter distance is found, set the appropriate values and update the queue.
                if (edge.getTarget(
                        Building.LIST_1).getMinDistance() > nextShortest.getMinDistance() + edge.getDistance()) {
                    buildingQueue.remove(edge.getTarget(Building.LIST_1));
                    edge.getTarget(Building.LIST_1).setMinDistance(nextShortest.getMinDistance() + edge.getDistance());
                    edge.getTarget(Building.LIST_1).setPrevious(nextShortest);
                    buildingQueue.add(edge.getTarget(Building.LIST_1));
                }
            }

            // Add the removed node to the cloud.
            cloud.add(nextShortest);
        }
    }

    // Simply prints the paths to each building.
    public void printPaths() {
        for (Building building : cloud) {
            System.out.println(building.getName() + "\n\t" + building.getPath());
        }
    }

    public static void main(String[] args) {
        FileInput fi = new FileInput("res/buildings.xml");
        fi.parseFile();

        System.out.println("+++++Dijkstra+++++");
        Dijkstra dijkstra = new Dijkstra(fi.getBuildingQueue());
        dijkstra.computePaths(Building.findByName("Math-Computer Science", Building.LIST_1));
        dijkstra.printPaths();

        System.out.println("\n+++++Bellman-Ford+++++");
        BellmanFord bellmanFord = new BellmanFord(fi.getBuildingList());
        bellmanFord.computePaths(Building.findByName("Math-Computer Science", Building.LIST_2));
        bellmanFord.printPaths();
    }
}
