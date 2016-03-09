package edu.uca.cub.jblair;

public class Woods {

    public void simulate() {
        BearA bearA = new BearA("Little Bear", 0, 0, Direction.NORTH);
        bearA.step();
        bearA.rotateRight();
        bearA.step();
        bearA.rotateLeft();
        bearA.step();
        bearA.printLocation();

        BearB bearB = new BearB("Big Bear", 0, 0, Direction.NORTH);
        bearB.step();
        bearB.step();
        bearB.step();
        bearB.rotateRight();
        bearB.step();
        bearB.step();
        bearB.step();
        bearB.rotateRight();
        bearB.step();
        bearB.step();
        bearB.step();
        bearB.rotateRight();
        bearB.step();
        bearB.step();
        bearB.step();
        bearB.printLocation();
    }

    public static void main(String[] args) {
        Woods woods = new Woods();
        woods.simulate();
    }
}
