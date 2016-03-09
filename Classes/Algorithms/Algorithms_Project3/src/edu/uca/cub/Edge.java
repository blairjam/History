/* James Blair & John Carter
 * 4 - 15 - 15
 * Algorithms Project 3 : Path Finding
 */

package edu.uca.cub;

public class Edge {
    private final String target;
    private final double distance;

    public Edge(String target, double distance) {
        this.target = target;
        this.distance = distance;
    }

    public double getDistance() {
        return distance;
    }

    // Returns a reference to the building represented by the name stored in target.
    // Uses Building's findByName method and specifies the list to use.
    public Building getTarget(int list) {
        return Building.findByName(target, list);

    }
}