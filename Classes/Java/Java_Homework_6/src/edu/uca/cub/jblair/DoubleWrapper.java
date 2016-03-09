package edu.uca.cub.jblair;

public class DoubleWrapper {
    private boolean failedConversion = true; // Flag to specify whether a successful assignment has completed.
    private double value; // The base number that is being wrapped.

    public DoubleWrapper() {
        this(0.0);
    }

    public DoubleWrapper(double value) {
        this.value = value;
    }

    public double getValue() {
        return value;
    }

    public boolean isFailedConversion() {
        return failedConversion;
    }

    public void setFailedConversion(boolean failedConversion) {
        this.failedConversion = failedConversion;
    }

    public void setValue(double value) {
        this.value = value;
    }
}
