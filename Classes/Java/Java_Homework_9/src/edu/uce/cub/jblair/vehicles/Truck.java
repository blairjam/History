package edu.uce.cub.jblair.vehicles;

import edu.uce.cub.jblair.Color;
import edu.uce.cub.jblair.TruckType;

public class Truck extends Vehicle {
    private TruckType type;

    public Truck(String make, String model, Color color, int tires, TruckType type) {
        super(make, model, color, tires);
        this.type = type;
    }

    public TruckType getType() {
        return type;
    }

    public void setType(TruckType type) {
        this.type = type;
    }

    public String toString() {
        return super.toString() + "\t\t" + type;
    }
}
