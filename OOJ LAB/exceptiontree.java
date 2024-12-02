import java.util.Scanner;


class WrongAgeException extends Exception {
    public WrongAgeException(String message) {
        super(message);
    }
}


class Father {
    int age;

    public Father(int age) throws WrongAgeException {
        if (age < 0) {
            throw new WrongAgeException("Father's age cannot be negative!");
        }
        this.age = age;
    }
}


class Son extends Father {
    int sonAge;

    public Son(int fatherAge, int sonAge) throws WrongAgeException {
        super(fatherAge); 
        if (sonAge < 0) {
            throw new WrongAgeException("Son's age cannot be negative!");
        }
        if (sonAge >= fatherAge) {
            throw new WrongAgeException("Son's age cannot be greater than or equal to Father's age!");
        }
        this.sonAge = sonAge;
    }
}


public class exceptioninheritancedemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {

            System.out.print("Enter Father's age: ");
            int fatherAge = scanner.nextInt();


            Father father = new Father(fatherAge);


            System.out.print("Enter Son's age: ");
            int sonAge = scanner.nextInt();


            Son son = new Son(fatherAge, sonAge);


            System.out.println("Father's age: " + father.age);
            System.out.println("Son's age: " + son.sonAge);

        } catch (WrongAgeException e) {
            System.out.println("Exception: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Invalid input. Please enter a valid integer for age.");
        } finally {
            scanner.close(); 
        }
    }
}
