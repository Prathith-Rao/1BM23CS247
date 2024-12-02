import java.util.Scanner;

abstract class Account {
    String customerName;
    String accountNumber;
    double balance;
    String accountType;

    public Account(String customerName, String accountNumber, String accountType, double balance) {
        this.customerName = customerName;
        this.accountNumber = accountNumber;
        this.accountType = accountType;
        this.balance = balance;
    }

    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposit successful. New balance: " + balance);
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

    public void displayBalance() {
        System.out.println("Account Balance: " + balance);
    }

    public abstract void withdraw(double amount);

    public abstract void updateBalance();
}

class CurAcct extends Account {
    private static final double MINIMUM_BALANCE = 1000;
    private static final double SERVICE_CHARGE = 50;

    public CurAcct(String customerName, String accountNumber, double balance) {
        super(customerName, accountNumber, "Current", balance);
    }

    @Override
    public void withdraw(double amount) {
        if (balance - amount >= 0) {
            balance -= amount;
            System.out.println("Withdrawal successful. New balance: " + balance);
            updateBalance();
        } else {
            System.out.println("Insufficient balance.");
        }
    }

    @Override
    public void updateBalance() {
        if (balance < MINIMUM_BALANCE) {
            balance -= SERVICE_CHARGE;
            System.out.println("Service charge imposed due to low balance. New balance: " + balance);
        }
    }
}

class SavAcct extends Account {
    private static final double INTEREST_RATE = 0.05;

    public SavAcct(String customerName, String accountNumber, double balance) {
        super(customerName, accountNumber, "Savings", balance);
    }

    public void computeInterest() {
        double interest = balance * INTEREST_RATE;
        balance += interest;
        System.out.println("Interest computed and added. New balance: " + balance);
    }

    @Override
    public void withdraw(double amount) {
        if (balance - amount >= 0) {
            balance -= amount;
            System.out.println("Withdrawal successful. New balance: " + balance);
        } else {
            System.out.println("Insufficient balance.");
        }
    }

    @Override
    public void updateBalance() {
        computeInterest();
    }
}

public class Bank {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter Customer Name: ");
        String name = scanner.nextLine();

        System.out.print("Enter Account Number: ");
        String accNum = scanner.nextLine();

        System.out.print("Enter Account Type (Savings/Current): ");
        String type = scanner.nextLine();

        System.out.print("Enter Initial Balance: ");
        double balance = scanner.nextDouble();

        Account account;
        if (type.equalsIgnoreCase("Savings")) {
            account = new SavAcct(name, accNum, balance);
        } else if (type.equalsIgnoreCase("Current")) {
            account = new CurAcct(name, accNum, balance);
        } else {
            System.out.println("Invalid Account Type.");
            scanner.close();
            return;
        }

        boolean quit = false;
        while (!quit) {
            System.out.println("\n1. Deposit\n2. Withdraw\n3. Display Balance\n4. Update Balance\n5. Quit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter amount to deposit: ");
                    double depositAmount = scanner.nextDouble();
                    account.deposit(depositAmount);
                    break;
                case 2:
                    System.out.print("Enter amount to withdraw: ");
                    double withdrawAmount = scanner.nextDouble();
                    account.withdraw(withdrawAmount);
                    break;
                case 3:
                    account.displayBalance();
                    break;
                case 4:
                    account.updateBalance();
                    break;
                case 5:
                    quit = true;
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }

        scanner.close();
        System.out.println("Thank you for banking with us.");
    }
}
