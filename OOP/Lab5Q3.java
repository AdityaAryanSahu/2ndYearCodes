import java.util.Scanner;

public class Lab5Q3 {
    static Scanner s = new Scanner(System.in);
    int regno;
    String name;
    short semester;
    float gpa;
    float cgpa;
    int year, month, day;

    // Constructor
    Lab5Q3(int regno, String name, short semester, float gpa, float cgpa, int year, int day, int month) {
        this.regno = regno;
        this.name = name;
        this.semester = semester;
        this.gpa = gpa;
        this.cgpa = cgpa;
        this.year = year;
        this.month = month;
        this.day = day;
    }

    // Method to handle array of students
    static void manageStudents() {
        System.out.println("Enter number of students (min 5):");
        int n = s.nextInt();

        Lab5Q3[] students = new Lab5Q3[n];
        int regno;
        String name;
        short semester;
        float gpa;
        float cgpa;
        int year, month, day;
        int position;

        for (int i = 0; i < n; i++) {
            System.out.println("Enter details of student " + (i + 1) + ":");
            System.out.println("Enter position:");
            position = s.nextInt();
            System.out.println("Enter day month year of joining:");
            day = s.nextInt();
            month = s.nextInt();
            year = s.nextInt();
            regno = calculateRegno(year, position);
            System.out.println("Registration number is: " + regno);
            s.nextLine(); // Consume the leftover newline
            System.out.println("Enter name:");
            name = s.nextLine();
            System.out.println("Enter semester:");
            semester = s.nextShort();
            System.out.println("Enter GPA and CGPA:");
            gpa = s.nextFloat();
            cgpa = s.nextFloat();
            s.nextLine(); // Consume the leftover newline

            students[i] = new Lab5Q3(regno, name, semester, gpa, cgpa, year, day, month);
        }

        // Display student details
        for (int i = 0; i < n; i++) {
            System.out.println("\nDetails of student " + (i + 1) + ":");
            students[i].display();
        }

        // Sorting by name
        sortByName(students);

        // Queries
        queryNamesStartingWith(students);
        queryNamesContainingSubstring(students);
        formatNames(students);

        // Display formatted names
        for (int i = 0; i < n; i++) {
            students[i].display();
        }
    }

    static void sortByName(Lab5Q3[] students) {
        // Bubble sort to sort by name
        int n = students.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (students[j].name.compareTo(students[j + 1].name) > 0) {
                    // Swap students[j] and students[j + 1]
                    Lab5Q3 temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
    }

    static void queryNamesStartingWith(Lab5Q3[] students) {
        System.out.println("\nQuery Names Starting With:");
        System.out.println("Enter a character:");
        char startChar = s.next().charAt(0);
        s.nextLine(); // Consume the leftover newline
        for (Lab5Q3 student : students) {
            if (student.name.startsWith(String.valueOf(startChar))) {
                System.out.println(student.name);
            }
        }
    }

    static void queryNamesContainingSubstring(Lab5Q3[] students) {
        System.out.println("\nQuery Names Containing Substring:");
        System.out.println("Enter substring to be searched:");
        String substring = s.nextLine();
        for (Lab5Q3 student : students) {
            if (student.name.contains(substring)) {
                System.out.println(student.name);
            }
        }
    }

    static void formatNames(Lab5Q3[] students) {
        for (Lab5Q3 student : students) {
            String[] parts = student.name.split(" ");
            StringBuilder formattedName = new StringBuilder();
            for (int i = 0; i < parts.length - 1; i++) {
                formattedName.append(Character.toUpperCase(parts[i].charAt(0))).append(". ");
            }
            formattedName.append(parts[parts.length - 1]);
            student.name = formattedName.toString();
        }
    }

    // Method to calculate registration number
    static int calculateRegno(int year, int position) {
        int temp = year % 100;
        int count = Integer.toString(position).length();
        return (temp * (int) Math.pow(10, count)) + position;
    }

    // Method for displaying student details
    void display() {
        System.out.println("Registration number: " + this.regno);
        System.out.println("Name: " + this.name);
        System.out.println("Semester: " + this.semester);
        System.out.println("GPA: " + this.gpa);
        System.out.println("CGPA: " + this.cgpa);
        System.out.println("Date of joining: " + this.day + "/" + this.month + "/" + this.year);
    }

    public static void main(String[] args) {
        System.out.println("Enter details of a test student:");
        manageStudents();
    }
}

