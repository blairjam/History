package edu.uca.cub.jblair;

// Cannon class given by instructor.
public class Cannon {
    public static int nextSerialNumber = 1000;

    private final double G = 9.8;
    private final double PI = 3.1415926;
    private double chargeSize;
    private double initialVelocity;
    private int launchAngle;
    private int serialNumber;

    public Cannon() {
        this(45, 15.0);
    }

    public Cannon(int angle) {
        this(angle, 15.0);
    }

    public Cannon(int angle, double size) {
        setLaunchAngle(angle);
        setChargeSize(size);

        serialNumber = nextSerialNumber;
        nextSerialNumber++;
    }

    public static int getNextSerialNumber() {
        return nextSerialNumber;
    }

    public double fire() {
        if (Stockpile.ammo > 0 && Stockpile.powder >= chargeSize) {
            computeInitVel();

            // Reduces the amount of supplies in the stockpile.
            Stockpile.ammo--;
            Stockpile.powder -= chargeSize;

            return computeRange();
        } else {
            System.out.println("Cannot fire. Not enough ammo or powder.");
            return 0.0;
        }
    }

    public double getChargeSize() {
        return chargeSize;
    }

    public double getFlightTime() {
        computeInitVel();
        return computeTime();
    }

    public double getHeight() {
        computeInitVel();
        return computeHeight();
    }

    public double getRange() {
        computeInitVel();
        return computeRange();
    }

    public int getSerialNumber() {
        return serialNumber;
    }

    public void setChargeSize(double size) {
        if (size > 20) {
            chargeSize = 20;
        } else if (size < 1) {
            chargeSize = 1;
        } else {
            chargeSize = size;
        }
    }

    public void setLaunchAngle(int angle) {
        if (angle > 90) {
            launchAngle = 90;
        } else if (angle < 0) {
            launchAngle = 0;
        } else {
            launchAngle = angle;
        }
    }

    private double computeHeight() {
        return Math.pow(initialVelocity * Math.sin(launchAngle * (PI / 180.0)), 2) / (2 * G);
    }

    private void computeInitVel() {
        initialVelocity = chargeSize * 10.0;
    }

    private double computeRange() {
        return (Math.pow(initialVelocity, 2) / G) * Math.sin(2 * launchAngle * (PI / 180.0));
    }

    private double computeTime() {
        return (2 * initialVelocity * Math.sin(launchAngle * (PI / 180.0))) / G;
    }
}
