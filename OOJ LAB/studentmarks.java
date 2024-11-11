import java.util.Scanner;

class Student {
    String name;
    String usn;
    int sem;

    Student() {
        this.name = "";
        this.usn = "";
        this.sem = 0;
    }

    void setDetails(Scanner sc) {
        System.out.print("Enter the name, usn, and semester of the student: ");
        name = sc.nextLine();
        usn = sc.nextLine();
        sem = sc.nextInt();
        sc.nextLine(); // To consume the newline character after nextInt()
    }

    void getDetails() {
        System.out.println("Name: " + this.name);
        System.out.println("USN: " + this.usn);
        System.out.println("Semester: " + this.sem);
    }
}

class Internal {
    int[] marks = new int[5];

    void setIntMarks(Scanner sc) {
        System.out.print("Enter the marks of 5 subjects of the student: ");
        for (int i = 0; i < 5; i++) {
            marks[i] = sc.nextInt();
        }
    }

    void getIntMarks() {
        System.out.println("The marks in 5 subjects in internals are: ");
        for (int i = 0; i < 5; i++) {
            System.out.println("Subject " + (i + 1) + ": " + this.marks[i]);
        }
    }
}

class External extends Student {
    int[] semMarks = new int[5];

    void setMarks(Scanner sc) {
        System.out.print("Enter the marks of 5 subjects of the student in the external exam: ");
        for (int i = 0; i < 5; i++) {
            semMarks[i] = sc.nextInt();
        }
    }

    void getMarks() {
        System.out.println("The marks in 5 subjects in external exams are: ");
        for (int i = 0; i < 5; i++) {
            System.out.println("Subject " + (i + 1) + ": " + this.semMarks[i]);
        }
    }
}

public class StudentDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        External a = new External();
        Internal b = new Internal();
        
        a.setDetails(sc);
        b.setIntMarks(sc);
        a.setMarks(sc);
        
        a.getDetails();
        b.getIntMarks();
        a.getMarks();

        sc.close();  // Close the scanner once all input has been collected
    }
}
