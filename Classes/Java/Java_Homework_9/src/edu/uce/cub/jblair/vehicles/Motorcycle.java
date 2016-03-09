package edu.uce.cub.jblair.vehicles;

import edu.uce.cub.jblair.Color;

public class Motorcycle extends Vehicle {
    private int engineSize;

    public Motorcycle(String make, String model, Color color, int engineSize) {
        super(make, model, color, 2);
        this.engineSize = engineSize;
    }

    public int getEngineSize() {
        return engineSize;
    }

    public void setEngineSize(int engineSize) {
        this.engineSize = engineSize;
    }

    public String toString() {
        return super.toString() + "\t\t" + engineSize + "cc";
    }
}
