import java.util.*;

class bankAccount {
    String name;
    int accountNumber;
    String type;
    int bankBalance;
    static int rate = 8;

    bankAccount() {
        bankBalance = 0;
    }

    bankAccount(String name, int accountNumber, String type, int bankBalance, int rate) {
        this.name = name;
        this.accountNumber = accountNumber;
        this.type = type;
        this.bankBalance = bankBalance;
        new bankAccount().rate = rate;
    }

    bankAccount(String name, int accountNumber, String type, int bankBalance) {
        this.name = name;
        this.accountNumber = accountNumber;
        this.type = type;
        this.bankBalance = bankBalance;
    }

    void deposit(int amount) {
        bankBalance += amount;
        System.out.println("deposit added!!");
    }

    void withdraw(int amount) {
        if (bankBalance - amount < 0) {
            System.out.println("balance insufficient!\nPlese try again.");
            return;
        } else {
            bankBalance -= amount;
            System.out.println("withdrawal succsfull!\ncurrent balance: " + bankBalance);
        }
    }
  void display(){
System.out.println("Bank Details:\n\n");
System.out.println("Name: "+name+"\nAccount Number: "+accountNumber+"\nAccount type:"+type+"\nBank Balance: "+ bankBalance); }

    static void displayRate() {
        System.out.println("rate is: " + new bankAccount().rate + "%");
    }
}

class Bank {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name;
        int bankBalance;
        String type;
        int accountNumber;
        System.out.println("enter name: ");
        name = sc.next();
        System.out.println("enter Account Number: ");
        accountNumber = sc.nextInt();
        System.out.println("enter type");
        type = sc.next();
        System.out.println("enter the depost: ");
        bankBalance = sc.nextInt();
        bankAccount ano1 = new bankAccount(name, accountNumber, type, bankBalance);
        ano1.display();
        System.out.println("enter the widraw amount: ");
        int amount = sc.nextInt();
        ano1.withdraw(amount);
        ano1.displayRate();
    }
}