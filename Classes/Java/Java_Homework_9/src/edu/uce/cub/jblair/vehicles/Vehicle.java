package edu.uce.cub.jblair.vehicles;

import edu.uce.cub.jblair.Color;

public class Vehicle {
    protected String make;
    protected String model;
    protected Color color;
    protected int tires;

    public Vehicle(String make, String model, Color color, int tires) {
        this.make = make;
        this.model = model;
        this.color = color;
        this.tires = tires;
    }

    public Color getColor() {
        return color;
    }

    public String getMake() {
        return make;
    }

    public String getModel() {
        return model;
    }

    public int getTires() {
        return tires;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public void setMake(String make) {
        this.make = make;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public void setTires(int tires) {
        this.tires = tires;
    }

    @Override
    public String toString() {
        return make + "\t\t" + model + "\t\t" + color + "\t\t" + tires;
    }
}
