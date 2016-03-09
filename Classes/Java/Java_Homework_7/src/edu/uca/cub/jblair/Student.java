package edu.uca.cub.jblair;

public class Student {
    private String forename;
    private String surname;
    private String studentID;
    private float gpa;

    public Student(String forename, String surname, String studentID, float gpa) {
        this.forename = forename;
        this.surname = surname;
        this.studentID = studentID;
        this.gpa = gpa;
    }

    public String getForename() {
        return forename;
    }

    public float getGpa() {
        return gpa;
    }

    public String getName() {
        return forename + " " + surname;
    }

    public String getStudentID() {
        return studentID;
    }

    public String getSurname() {
        return surname;
    }

    public void setForename(String forename) {
        this.forename = forename;
    }

    public void setGpa(float gpa) {
        this.gpa = gpa;
    }

    public void setStudentID(String studentID) {
        this.studentID = studentID;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public String toString() {
        return forename + " " + surname + " " + studentID + " " + gpa;
    }
}
