package edu.uca.cub.jblair;

public class BearB {
    private String name;
    private int posX;
    private int posY;
    private Direction direction;

    private int health = 100;

    public BearB(String name, int posX, int posY, Direction direction) {
        this.name = name;
        this.posX = posX;
        this.posY = posY;
        this.direction = direction;
    }

    public void rotateRight() {
        System.out.println(name + " rotating right...");
        direction = direction.next();
        health -= 5;
    }

    public void rotateLeft() {
        System.out.println(name + " rotating left...");
        direction = direction.previous();
        health -= 5;
    }

    public void step() {
        step(1);
    }

    public void step(int stepLength) {
        if (health > 0) {
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
            health -= stepLength * 4;
        } else {
            System.out.println(name + " is dead.");
        }
    }

    public void printLocation() {
        System.out.println("Name: " + name + " | Health: " + health + " | Direction: " + direction.toString() + " | Location: (" + posX + ", " + posY + ").");
    }
}
