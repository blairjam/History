/* James Blair
 * 3-11-15
 * Project 1 : Part 4
 *
 * You can view the development process at github.com/blairjam/Java_Project_1 under the commits tab.
 */

package edu.uca.cub.jblair;

import javax.swing.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Sorter {
    private Scanner fileIn;
    private PrintWriter fileOut;
    private String pathIn;
    private ArrayList<String> words = new ArrayList<String>();

    // Ask the user for the path to the data file.
    public void obtainFilePath() {
        // "Enhancement" for obtaining file path...
        pathIn = JOptionPane.showInputDialog(null, "Enter the path to the data file:",
                                             "File Path", JOptionPane.QUESTION_MESSAGE);

        if (pathIn == null) {
            System.err.println("No path given. Exiting...");
            System.exit(75);
        }
    }

    // Reads the whitespace separated string into the array list created.
    public void readFile() {
        System.out.println("Reading from file...");

        try {
            fileIn = new Scanner(new File(pathIn));
        } catch (FileNotFoundException e) {
            System.err.println("Could not open file at: " + pathIn);
            System.exit(404);
        }

        while (fileIn.hasNext()) {
            String nextWord = fileIn.next();
            if (!containsPunctuation(nextWord))
                words.add(nextWord);
        }

        fileIn.close();
    }

    public void setPathIn(String pathIn) {
        this.pathIn = pathIn;
    }

    // Sorts words alphabetically using a quick sort.
    public void sortAlphabetically() {
        System.out.println("Sorting words...");

        // Three lists to hold appropriate words.
        ArrayList<String> smaller = new ArrayList<String>();
        ArrayList<String> equal = new ArrayList<String>();
        ArrayList<String> bigger = new ArrayList<String>();

        String pivotWord = words.get(0);

        for (String string : words) {
            if (compareStrings(string, pivotWord) < 0) {
                smaller.add(string);
            } else if (compareStrings(string, pivotWord) == 0) {
                equal.add(string);
            } else {
                bigger.add(string);
            }
        }

        // Removes any excess space from the end of the list.
        smaller.trimToSize();
        equal.trimToSize();
        bigger.trimToSize();

        // Remove all the words from the the list.
        words.clear();

        // Repopulate the list with the smaller, equal, and bigger lists.
        words.addAll(sortAlphabetically(smaller));
        words.addAll(equal);
        words.addAll(sortAlphabetically(bigger));

        words.trimToSize();
    }

    // Writes the sorted list to file.
    public void writeFile() {
        System.out.println("Writing to file...");

        try {
            fileOut = new PrintWriter(new File(createPathOut()));
        } catch (FileNotFoundException e) {
            System.err.println("Could not print to file! Exiting...");
            System.exit(500);
        }

        String lastString = null;
        int numWords = 0;
        int uniqueWords = 0;
        int timesOccured = 1;

        for (String string : words) {
            if (!string.equals(lastString)) {
                // Prints out how many times the last word occurred.
                if (lastString != null) {
                    fileOut.write(lastString + " occurred " + timesOccured + (timesOccured > 1 ? " times." : " time."));
                    timesOccured = 1;
                    fileOut.println();
                }
                uniqueWords++;
            } else {
                timesOccured++;
            }

            numWords++;
            lastString = string;
        }

        fileOut.write(lastString + " occurred " + timesOccured + " times.");

        fileOut.close();

        System.out.println("Total words in file: " + numWords);
        System.out.println("Unique words in file: " + uniqueWords);
    }

    private int compareStrings(String strOne, String strTwo) {
        // Sets the length to the smaller of the two given strings.
        int length = strOne.length() <= strTwo.length() ? strOne.length() : strTwo.length();

        // Converts the strings to lowercase.
        String strOneComp = strOne.toLowerCase();
        String strTwoComp = strTwo.toLowerCase();

        // Checks each character of the strings for ascii values.
        for (int i = 0; i < length; i++) {
            if (strOneComp.charAt(i) < strTwoComp.charAt(i)) {
                return -1;
            } else if (strOneComp.charAt(i) > strTwoComp.charAt(i)) {
                return 1;
            }
        }

        // Check if strOne is smaller in length than strTwo, meaning at this point, it should be placed higher.
        if (strOneComp.length() < strTwoComp.length()) {
            return -1;
        } else if (strOneComp.length() > strTwoComp.length()) {
            return 1;
        }

        // Returns 0 if the strings are the same.
        return 0;
    }

    private boolean containsPunctuation(String str) {
        boolean doesContain = false;

        // Loops across all characters in the string,
        // testing ascii values against numbers, capital, and lower case letters.
        for (char c : str.toCharArray()) {

            if (!((c >= 48 && c <= 57) // 48 through 57 represents numbers.
                    || (c >= 65 && c <= 90) // 65 through 90 represents capital letters.
                    || (c >= 97 && c <= 122))) { // 97 through 122 represents lower case letters.
                doesContain = true;
            }
        }

        return doesContain;
    }

    private String createPathOut() {
        // Creates a file name based on the current given file.
        String pathOut;
        String appendage = "_sorted";

        int dot = pathIn.indexOf('.');

        // If the path has an extension in it, add the appendage before the extension. Else simply add the appendage.
        if (dot != -1) {
            pathOut = pathIn.substring(0, dot) + appendage + pathIn.substring(dot, pathIn.length());
        } else {
            pathOut = pathIn + appendage;
        }

        return pathOut;
    }

    private ArrayList<String> sortAlphabetically(ArrayList<String> list) {
        // Breaks the recursion loop if the length is one or less.
        if (list.size() <= 1) {
            return list;
        }

        // Three lists to hold appropriate words.
        ArrayList<String> smaller = new ArrayList<String>();
        ArrayList<String> equal = new ArrayList<String>();
        ArrayList<String> bigger = new ArrayList<String>();

        String pivotWord = list.get(0);

        for (String string : list) {
            if (compareStrings(string, pivotWord) < 0) {
                smaller.add(string);
            } else if (compareStrings(string, pivotWord) == 0) {
                equal.add(string);
            } else {
                bigger.add(string);
            }
        }

        // Removes any excess space from the end of the list.
        smaller.trimToSize();
        equal.trimToSize();
        bigger.trimToSize();

        // Remove all the words from the the list.
        list.clear();

        // Repopulate the list with the smaller, equal, and bigger lists.
        list.addAll(sortAlphabetically(smaller));
        list.addAll(equal);
        list.addAll(sortAlphabetically(bigger));

        list.trimToSize();

        return list;
    }

    public static void main(String[] args) {
        Sorter sorter = new Sorter();
        sorter.obtainFilePath();
        sorter.readFile();
        sorter.sortAlphabetically();
        sorter.writeFile();
    }
}
