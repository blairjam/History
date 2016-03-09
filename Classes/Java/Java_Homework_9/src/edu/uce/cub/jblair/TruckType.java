package edu.uce.cub.jblair;

public enum TruckType {
    PICKUP {
        @Override
        public String toString() {
            return "Pickup";
        }
    },
    SEMI {
        @Override
        public String toString() {
            return "Semi";
        }
    },
    BOX {
        @Override
        public String toString() {
            return "Box";
        }
    };
}
