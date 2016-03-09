/* James Blair & John Carter
 * 3 - 16 - 15
 * Algorithms Project 2 : Topological Ordering
 */

package edu.uca.cub;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class FileInput {
    public static final int SYNTAX_ERROR = 2;
    public static final int FILE_NOT_FOUND_ERROR = 3;
    private String path;
    private Scanner fileIn;
    private ArrayList<Vertex> classes = new ArrayList<Vertex>();

    public ArrayList<Vertex> getClasses() {
        classes.trimToSize();
        return classes;
    }

    // Queries user for path to data file.
    public void obtainPath() {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the path to the XML data file: ");
        path = input.nextLine();
    }

    // Reads the file and takes the data from the XML elements and populates the classes list.
    public void parseFile() {
        try {
            fileIn = new Scanner(new File(path));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            System.exit(FILE_NOT_FOUND_ERROR);
        }

        // Possible tags that need to explicitly be accounted for.
        String xmlClasses = "<classes>";
        String xmlClassesEnd = "</classes>";
        String xmlClass = "<class>";
        String xmlClassEnd = "</class>";
        String xmlDesignation = "<designation>";
        String xmlName = "<name>";
        String xmlEdge = "<edge>";

        // Exits if the first line of the file isn't <classes>.
        if (fileIn.hasNextLine() && !fileIn.nextLine().equalsIgnoreCase(xmlClasses)) {
            printError("Syntax invalid. File should start with \'" + xmlClasses + "\' element.");
            System.exit(SYNTAX_ERROR);
        }

        int line = 2; // Current line the file is on.
        boolean newClassStarted = false; // Variable for determination of a new class.
        Vertex newClass = null; // Object to populate with information.

        while (fileIn.hasNext()) {
            String nextToken = fileIn.nextLine();
            String token = removeBeginningWhitespace(nextToken);

            if (token != null) {
                // Token found is </classes> and file has no more lines.
                if (token.equalsIgnoreCase(xmlClassesEnd) && !fileIn.hasNext()) {
                    break;
                }
                // Token found is </classes>, but file has more lines.
                else if (token.equalsIgnoreCase(xmlClassesEnd) && fileIn.hasNext()) {
                    printError("Syntax invalid. File should end with \'" + xmlClassesEnd + "\' element.");
                    System.exit(SYNTAX_ERROR);
                }
                // Token found is <class> and a new class has not been started. Initialize new class.
                else if (token.equalsIgnoreCase(xmlClass) && !newClassStarted) {
                    newClassStarted = true;
                    newClass = new Vertex();
                }
                // Token found is <class> and a new class has already been started.
                else if (token.equalsIgnoreCase(xmlClass) && newClassStarted) {
                    printError("Syntax invalid. Element \'" +
                                       xmlClass + "\' found before the previous element was closed.");
                    System.exit(SYNTAX_ERROR);
                }
                // Token found is </class> and a new class has not ended. Add new class to list.
                else if (token.equalsIgnoreCase(xmlClassEnd) && newClassStarted) {
                    newClassStarted = false;
                    classes.add(newClass);
                }
                // Token found is </class> and a new class has already ended.
                else if (token.equalsIgnoreCase(xmlClassEnd) && !newClassStarted) {
                    printError("Syntax invalid. Element \'" +
                                       xmlClassEnd + "\' found before the previous element was opened.");
                    System.exit(SYNTAX_ERROR);
                }
                // Token found is <designation>.
                else if (token.startsWith(xmlDesignation)) {
                    if (newClass != null)
                        newClass.setDesignation(extractData(token, xmlDesignation));
                }
                // Token found is <name>.
                else if (token.startsWith(xmlName)) {
                    if (newClass != null)
                        newClass.setName(extractData(token, xmlName));
                }
                // Token found is <edge>.
                else if (token.startsWith(xmlEdge)) {
                    Edge newEdge = new Edge(extractData(token, xmlEdge));
                    if (newClass != null)
                        newClass.addEdge(newEdge);
                }
                // Token found is unknown.
                else {
                    printError("Syntax invalid. Unknown element found in line: " + line + " \'" + token + "\'.");
                    System.exit(SYNTAX_ERROR);
                }
            } else {
                printError("Could not remove whitespace in token: " + nextToken + " at line: " + line);
            }

            line++;
        }

        fileIn.close();
    }

    // Finds the data inside the given XML element.
    private String extractData(String line, String xmlElement) {
        if (!line.startsWith(xmlElement)) {
            return null;
        } else {
            return line.substring(xmlElement.length(), line.length() - (xmlElement.length() + 1));
        }
    }

    // Error printing wrapper.
    private void printError(String message) {
        System.err.println("ERROR: " + message);
        System.err.flush();
    }

    // Removes the whitespace from the beginning of the given string.
    private String removeBeginningWhitespace(String str) {
        String spaceRemoved = null;

        // Runs until a non-whitespace character is found.
        for (int i = 0; i < str.length(); i++) {
            if (!Character.isWhitespace(str.charAt(i))) {
                spaceRemoved = str.substring(i);
                break;
            }
        }

        return spaceRemoved;
    }

    public static void main(String[] args) {
        FileInput fi = new FileInput();
        fi.obtainPath();
        fi.parseFile();

        DFS search = new DFS();
        search.setClasses(fi.getClasses());
        search.dfs();

        Sorter sorter = new Sorter();
        sorter.setClasses(search.getClasses());
        sorter.sortClasses();
        sorter.printClasses();
    }
}
