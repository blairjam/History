package edu.uce.cub.jblair.vehicles;

import edu.uce.cub.jblair.Color;

public class Car extends Vehicle {
    private int doors;

    public Car(String make, String model, Color color, int doors) {
        super(make, model, color, 4);
        this.doors = doors;
    }

    public int getDoors() {
        return doors;
    }

    public void setDoors(int doors) {
        this.doors = doors;
    }

    @Override
    public String toString() {
        return super.toString() + "\t\t" + doors + "dr.";
    }
}
