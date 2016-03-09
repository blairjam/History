package edu.uca.cub.jblair;

public enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST;

    public Direction next() {
        return values()[(ordinal() + 1) % values().length];
    }

    public Direction previous() {
        return values()[(ordinal() + (values().length - 1)) % values().length];
    }
}
