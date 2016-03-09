/* James Blair & John Carter
 * 3 - 16 - 15
 * Algorithms Project 2 : Topological Ordering
 */

package edu.uca.cub;

import java.util.ArrayList;

public class Sorter {
    private ArrayList<Vertex> classes;

    public ArrayList<Vertex> getClasses() {
        return classes;
    }

    // Prints the classes to the screen with arrows (\u25BC) separating them.
    public void printClasses() {
        for (int i = 0; i < classes.size(); i++) {
            System.out.println(classes.get(i));
            for (int j = 0; j < classes.get(i).toString().length(); j++) {
                if (i < classes.size() - 1) {
                    if (j == 8) {
                        System.out.print("\u25BC");
                        break;
                    } else {
                        System.out.print(" ");
                    }
                }
            }
            System.out.println();
        }
    }

    public void setClasses(ArrayList<Vertex> classes) {
        this.classes = classes;
    }

    // Entry point for the quick sort.
    public void sortClasses() {
        ArrayList<Vertex> smaller = new ArrayList<Vertex>();
        ArrayList<Vertex> equal = new ArrayList<Vertex>();
        ArrayList<Vertex> bigger = new ArrayList<Vertex>();

        // Set the pivot to the first element in the list.
        Vertex pivot = classes.get(0);
        // Add the pivot to the equal list.
        equal.add(pivot);

        // Determine the location of each subsequent vertex.
        for (int i = 1; i < classes.size(); i++) {
            Vertex current = classes.get(i);
            if (current.getPostVisit() < pivot.getPostVisit()) {
                smaller.add(current);
            } else if (current.getPostVisit() == pivot.getPostVisit()) {
                equal.add(current);
            } else {
                bigger.add(current);
            }
        }

        // Clean up any extra size on each list.
        smaller.trimToSize();
        equal.trimToSize();
        bigger.trimToSize();

        // Remove the current order of vertices.
        classes.clear();

        // Add the vertices back in order, biggest to smallest.
        classes.addAll(sortClasses(bigger));
        classes.addAll(equal);
        classes.addAll(sortClasses(smaller));

        // Clean up of extra size.
        classes.trimToSize();
    }

    private ArrayList<Vertex> sortClasses(ArrayList<Vertex> list) {
        // Returns when the list is of size 1 or less.
        if (list.size() <= 1) {
            return list;
        }

        ArrayList<Vertex> smaller = new ArrayList<Vertex>();
        ArrayList<Vertex> equal = new ArrayList<Vertex>();
        ArrayList<Vertex> bigger = new ArrayList<Vertex>();

        // Set the pivot to the first element in the list.
        Vertex pivot = list.get(0);
        // Add the pivot to the equal list.
        equal.add(pivot);

        // Determine the location of each subsequent vertex.
        for (int i = 1; i < list.size(); i++) {
            Vertex current = list.get(i);
            if (current.getPostVisit() < pivot.getPostVisit()) {
                smaller.add(current);
            } else if (current.getPostVisit() == pivot.getPostVisit()) {
                equal.add(current);
            } else {
                bigger.add(current);
            }
        }

        // Clean up any extra size on each list.
        smaller.trimToSize();
        equal.trimToSize();
        bigger.trimToSize();

        // Remove the current order of vertices.
        list.clear();

        // Add the vertices back in order, biggest to smallest.
        list.addAll(sortClasses(bigger));
        list.addAll(equal);
        list.addAll(sortClasses(smaller));

        // Clean up of extra size.
        list.trimToSize();

        return list;
    }
}
