/* James Blair
   HW09 : Inheritance
 */

package edu.uce.cub.jblair;

import edu.uce.cub.jblair.vehicles.Car;
import edu.uce.cub.jblair.vehicles.Motorcycle;
import edu.uce.cub.jblair.vehicles.Truck;
import edu.uce.cub.jblair.vehicles.Vehicle;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Road {
    private ArrayList<Vehicle> vehicles = new ArrayList<Vehicle>();
    private Scanner fileIn;
    private PrintWriter fileOut;
    private String filePathIn = "/home/conner/Code/Java/HW09/Vehicles.txt";
    private String filePathOut = "/home/conner/Code/Java/HW09/VehiclesByType.txt";

    public void printFile() {
        try {
            fileOut = new PrintWriter(filePathOut);
        } catch (FileNotFoundException e) {
            System.err.println("Could not write to file at '" + filePathOut + "'.");
            System.err.println("Exiting...");
            System.exit(404);
        }

        for (Vehicle vehicle : vehicles) {
            fileOut.write(vehicle.toString());
            fileOut.println();
        }

        fileOut.close();
    }

    public void readFile() {
        try {
            fileIn = new Scanner(new File(filePathIn));
        } catch (FileNotFoundException e) {
            System.err.println("File could not be found at '" + filePathIn + "'.");
            System.err.println("Exiting...");
            System.exit(404);
        }

        Vehicle vehicle;

        while (fileIn.hasNext()) {
            String make = fileIn.next();
            String model = fileIn.next();
            String color = fileIn.next();
            int tires = fileIn.nextInt();
            String specification = fileIn.next();

            // Vehicle is a car.
            if (specification.endsWith("dr.")) {
                vehicle = new Car(make, model, determineColor(color), Integer.parseInt(specification.substring(0, 1)));
            }
            // Vehicle is a motorcycle.
            else if (specification.endsWith("cc")) {
                vehicle = new Motorcycle(make, model, determineColor(color),
                                         Integer.parseInt(specification.substring(0, specification.length() - 2)));
            }
            // Vehicle is a truck.
            else {
                vehicle = new Truck(make, model, determineColor(color), tires, determineTruckType(specification));
            }

            vehicles.add(vehicle);
        }

        fileIn.close();
    }

    private Color determineColor(String color) {
        Color c;

        if (Color.BLACK.toString().equalsIgnoreCase(color)) {
            c = Color.BLACK;
        } else if (Color.BLUE.toString().equalsIgnoreCase(color)) {
            c = Color.BLUE;
        } else if (Color.BROWN.toString().equalsIgnoreCase(color)) {
            c = Color.BROWN;
        } else if (Color.GREEN.toString().equalsIgnoreCase(color)) {
            c = Color.GREEN;
        } else if (Color.ORANGE.toString().equalsIgnoreCase(color)) {
            c = Color.ORANGE;
        } else if (Color.PINK.toString().equalsIgnoreCase(color)) {
            c = Color.PINK;
        } else if (Color.PURPLE.toString().equalsIgnoreCase(color)) {
            c = Color.PURPLE;
        } else if (Color.RED.toString().equalsIgnoreCase(color)) {
            c = Color.RED;
        } else if (Color.SILVER.toString().equalsIgnoreCase(color)) {
            c = Color.SILVER;
        } else if (Color.WHITE.toString().equalsIgnoreCase(color)) {
            c = Color.WHITE;
        } else {
            c = Color.YELLOW;
        }

        return c;
    }

    private TruckType determineTruckType(String type) {
        TruckType tt;

        if (TruckType.BOX.toString().equalsIgnoreCase(type)) {
            tt = TruckType.BOX;
        } else if (TruckType.PICKUP.toString().equalsIgnoreCase(type)) {
            tt = TruckType.PICKUP;
        } else {
            tt = TruckType.SEMI;
        }

        return tt;
    }

    public static void main(String[] args) {
        Road road = new Road();
        road.readFile();
        road.printFile();
    }
}
