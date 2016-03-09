/* James Blair & John Carter
 * 4 - 15 - 15
 * Algorithms Project 3 : Path Finding
 */

package edu.uca.cub;

import org.xml.sax.SAXException;
import org.w3c.dom.*;

import javax.xml.parsers.*;
import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class FileInput {
    private String path;

    // Priority Queue for Dijkstra's Algorithm.
    private PriorityQueue<Building> buildingQueue = new PriorityQueue<Building>();

    // Array List for Bellman-Ford Algorithm.
    private ArrayList<Building> buildingList = new ArrayList<Building>();

    public FileInput(String path) {
        this.path = path;
    }

    public ArrayList<Building> getBuildingList() {
        return buildingList;
    }

    public PriorityQueue<Building> getBuildingQueue() {
        return buildingQueue;
    }

    public void parseFile() {
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder;
        Document document = null;

        try {
            builder = factory.newDocumentBuilder();
            document = builder.parse(new File(path));
        } catch (ParserConfigurationException e) {
            e.printStackTrace();
            System.exit(9);
        } catch (SAXException e) {
            e.printStackTrace();
            System.exit(8);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(7);
        }

        // Normalize the document.
        document.getDocumentElement().normalize();

        // Obtain root element.
        Element root = document.getDocumentElement();

        // Find all nodes with the tag 'building'.
        NodeList nodeList = document.getElementsByTagName("building");

        Building building = null;
        // Loops over all buildings listed.
        for (int i = 0; i < nodeList.getLength(); i++) {
            Node node = nodeList.item(i);

            if (node.getNodeType() == Node.ELEMENT_NODE) {
                Element element = (Element) node;

                // Creates a new building, with the name taken from the 'name' tag.
                building = new Building(element.getElementsByTagName("name").item(0).getTextContent());

                // Creates a list of nodes with the 'edge' tag.
                NodeList edges = element.getElementsByTagName("edge");

                // Loops over all edges listed.
                for (int j = 0; j < edges.getLength(); j++) {
                    Node edge = edges.item(j);
                    Element edgeElement = (Element) edge;

                    String target = edgeElement.getElementsByTagName("name").item(0).getTextContent();
                    double distance = -1.0;
                    try {
                        distance = Double.parseDouble(
                                edgeElement.getElementsByTagName("distance").item(0).getTextContent());
                    } catch (NumberFormatException e) {
                        e.printStackTrace();
                        System.err.println("Building: " + building.getName() + " Edge target: " + target);
                    }

                    // Creates a new edge with the target and distance found.
                    Edge e = new Edge(target, distance);
                    building.addEdge(e);
                }
            }

            buildingQueue.add(building);
            buildingList.add(new Building(building));
        }
    }
}
