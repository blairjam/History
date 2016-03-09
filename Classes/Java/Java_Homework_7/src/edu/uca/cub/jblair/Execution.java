package edu.uca.cub.jblair;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Execution {
    private final int NUM_STUDENTS = 9; // The total number of students.
    private Student[] students = new Student[NUM_STUDENTS]; // Array to hold all students.
    private Student[] deansList; // Array to hold students on dean's list.
    private Scanner fileIn;
    private PrintWriter fileOut;

    // Calculates the size for the dean's list.
    public void calculateDeansListSize() {
        int size = 0;

        // Increase the size if a student has a gpa at least 3.5.
        for (int i = 0; i < NUM_STUDENTS; i++) {
            if (students[i].getGpa() >= 3.5f) {
                size++;
            }
        }

        deansList = new Student[size];
    }

    // Copies students whose gpa is over 3.5 to the dean's list array.
    public void populateDeansList() {
        for (int i = 0, j = 0; i < NUM_STUDENTS; i++) {
            if (students[i].getGpa() >= 3.5f) {
                deansList[j] = students[i];
                j++;
            }
        }
    }

    // Fills the students array with data from the given file.
    public void populateFromFile() {
        boolean opened; // Whether or not the file has been opened successfully.
        String path; // The path to the file.

        do {
            path = obtainFilePath("Enter the path to your data file: ");
            opened = openFile(path);
        } while (!opened);

        // Takes tokens from the file and populates each student.
        for (int i = 0; i < NUM_STUDENTS; i++) {
            String forename = fileIn.next();
            String surname = fileIn.next();
            String studentId = fileIn.next();
            float gpa = fileIn.nextFloat();

            students[i] = new Student(forename, surname, studentId, gpa);
        }

        fileIn.close();
    }

    // Writes the data from the dean's list array to the given file.
    public void writeDeansListToFile() {
        String path = obtainFilePath("Enter the path to the deans list file: ");

        try {
            fileOut = new PrintWriter(path);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            System.err.println("An error occurred while writing to file. Now exiting.");
            System.exit(1);
        }

        System.out.println("Students on the Dean's List: ");

        for (int i = 0; i < deansList.length; i++) {
            fileOut.write(deansList[i].toString() + "\n");
            System.out.println(deansList[i].getName());
        }

        fileOut.close();
    }

    // Asks the user for a file path.
    private String obtainFilePath(String prompt) {
        Scanner userInput = new Scanner(System.in);
        String filePath;

        System.out.print(prompt);
        filePath = userInput.next();

        return filePath;
    }

    // Tries to open the file at the given path. Returns true if the file was opened, false if it could not be.
    private boolean openFile(String path) {
        boolean success;

        try {
            fileIn = new Scanner(new File(path));
            success = true;
        } catch (FileNotFoundException e) {
            System.err.println("Could not find the file located at '" + path + "'.");
            System.err.flush();
            success = false;
        }

        return success;
    }

    public static void main(String[] args) {
        Execution ex = new Execution();
        ex.populateFromFile();
        ex.calculateDeansListSize();
        ex.populateDeansList();
        ex.writeDeansListToFile();
    }
}
