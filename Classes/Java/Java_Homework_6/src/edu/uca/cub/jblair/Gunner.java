/* James Blair
   February 10, 2015
   HW-06 : Firing the cannon.
 */

package edu.uca.cub.jblair;

import java.util.Scanner;

public class Gunner {
    private int cannonToFire = 0; // Iterator to keep track of cannons.
    private Cannon[] cannons = new Cannon[2];
    private boolean hit = false; // Control for program loop. When target is hit, program will end.
    private double[] ranges = new double[2];

    // Initialize the cannons to default cannons.
    public Gunner() {
        cannons[0] = new Cannon();
        cannons[1] = new Cannon();
    }

    // The main logic of the program. Controls the firing of the cannons after the initial values have been obtained.
    public void fire() {
        while (!hit) {
            // Decides which cannon to load and aim.
            if (cannonToFire == 0) {
                setupCannon(cannonToFire, "one");
            } else {
                setupCannon(cannonToFire, "two");
            }

            // Fires the cannon. We don't currently care about the returned distance.
            cannons[cannonToFire].fire();

            // Check to see whether the cannon ball landed within 50 meters on either side of the target.
            if (cannons[cannonToFire].getRange() >= ranges[cannonToFire] - 50.0
                    && cannons[cannonToFire].getRange() <= ranges[cannonToFire] + 50.0) {
                hit = true;
                System.out.printf("Great shot! You hit the target at %8.2f meters.\n",
                                  cannons[cannonToFire].getRange());
            } else {
                System.out.printf("Missed... Your shot traveled %8.2f meters.\n", cannons[cannonToFire].getRange());
                System.out.println("You have " + Stockpile.ammo + " cannon balls remaining.");
                System.out.println("You have " + Stockpile.powder + " pounds of gun powder remaining.");
            }

            // Iterate the cannon to be fired. Modulus 2 keeps the cannons alternating.
            cannonToFire = (cannonToFire + 1) % 2;
        }
    }

    // Simple query of the distances of the targets from the two cannons.
    public void setCannonRanges() {
        ranges[0] = askForDouble("Enter the range of the target from cannon one: ");
        ranges[1] = askForDouble("Enter the range of the target from cannon two: ");
    }

    // Simple query of the amounts of supplies in the stockpile.
    public void setStockpileAmounts() {
        Stockpile.ammo = askForInt("Enter the number of cannon balls you have: ");
        Stockpile.powder = askForDouble("Enter the amount of gun powder you have: ");
    }

    // Simple query of the angle and charge size for the specified cannon.
    public void setupCannon(int cannon, String name) {
        cannons[cannon].setLaunchAngle(askForInt("Enter the angle of cannon " + name + ": "));
        cannons[cannon].setChargeSize(askForDouble("Enter the charge size of cannon " + name + ": "));
    }

    // Asks user for a number returned as a double.
    private double askForDouble(String prompt) {
        Scanner scanner = new Scanner(System.in);
        String input; // Stores the given input.
        DoubleWrapper double_; // Object to store the double in.

        // Tries to get a double from the user. Will loop until a compatible string is entered.
        do {
            System.out.print(prompt);
            input = scanner.next();
            double_ = stringToDouble(input);
        } while (double_.isFailedConversion());

        return double_.getValue();
    }

    // Asks user for a number returned as an int.
    private int askForInt(String prompt) {
        Scanner scanner = new Scanner(System.in);
        String input; // Store the given input.
        IntWrapper int_; // Object to store the int in.

        // Tries to get an int from the user. Will loop until a compatible string is entered.
        do {
            System.out.print(prompt);
            input = scanner.next();
            int_ = stringToInt(input);
        } while (int_.isFailedConversion());

        return int_.getValue();
    }

    // Converts a given string to a double.
    private DoubleWrapper stringToDouble(String in) {
        // Object to store the double in.
        DoubleWrapper double_ = new DoubleWrapper();

        /* Try to convert the given string to double.
           If successful, sets the value to the converted number, and sets the failed flag to false.
           If unsuccessful, sets the failed flag to true.
         */
        try {
            double_.setValue(Double.parseDouble(in));
            double_.setFailedConversion(false);
        } catch (NumberFormatException e) {
            System.out.println("Please enter a number.");
            double_.setFailedConversion(true);
        }
        return double_;
    }

    // Converts a given string to an int.
    private IntWrapper stringToInt(String in) {
        // Object to store the int in.
        IntWrapper int_ = new IntWrapper();

        /* Try to convert the given string to int.
           If successful, sets the value to the converted number, and sets the failed flag to false.
           If unsuccessful, sets the failed flag to true.
         */
        try {
            int_.setValue(Integer.parseInt(in));
            int_.setFailedConversion(false);
        } catch (NumberFormatException e) {
            System.out.println("Please enter a number.");
            int_.setFailedConversion(true);
        }
        return int_;
    }

    public static void main(String[] args) {
        Gunner gunner = new Gunner();
        gunner.setStockpileAmounts();
        gunner.setCannonRanges();
        gunner.fire();
    }
}
