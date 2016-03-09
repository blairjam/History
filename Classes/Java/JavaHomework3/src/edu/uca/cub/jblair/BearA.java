package edu.uca.cub.jblair;

public class BearA {

    private String name;
    private int posX;
    private int posY;
    private Direction direction;

    public BearA(String name, int posX, int posY, Direction direction) {
        this.name = name;
        this.posX = posX;
        this.posY = posY;
        this.direction = direction;
    }

    public void rotateRight() {
        System.out.println(name + " rotating right...");
        direction = direction.next();
    }

    public void rotateLeft() {
        System.out.println(name + " rotating left...");
        direction = direction.previous();
    }

    public void step() {
        step(1);
    }

    public void step(int stepLength) {
        System.out.println(name + " stepping " + direction.toString() + " " + stepLength + "...");
        switch (direction) {
            case NORTH:
                posY += stepLength;
                break;
            case SOUTH:
                posY -= stepLength;
                break;
            case EAST:
                posX += stepLength;
                break;
            case WEST:
                posX -= stepLength;
                break;
            default:
                System.out.println("Stepping wrong.");
        }
    }

    public void printLocation() {
        System.out.println("Name: " + name + " | Direction: " + direction.toString() + " | Location: (" + posX + ", " + posY + ").");
    }
}
