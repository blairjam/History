package edu.uca.cub.jblair;

public class IntWrapper {
    private boolean failedConversion = true; // Flag to specify whether a successful assignment has completed.
    private int value; // The base number that is being wrapped.

    public IntWrapper() {
        this(0);
    }

    public IntWrapper(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }

    public boolean isFailedConversion() {
        return failedConversion;
    }

    public void setFailedConversion(boolean failedConversion) {
        this.failedConversion = failedConversion;
    }

    public void setValue(int value) {
        this.value = value;
    }
}
