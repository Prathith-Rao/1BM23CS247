import java.util.Scanner;
public class book {
    String name;
    String author;
    int price;
    int num_pages;
    public book()
    {
        name="";
        author="";
        price=0;
        num_pages=0;
    }
    public void set_details()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the book name :");
        name=sc.nextLine();
        System.out.println("Enter the author name :");
        author=sc.nextLine();
        System.out.println("Enter the price of the book :");
        price=sc.nextInt();
        System.out.println("Enter the number of pages in the book :");
        num_pages=sc.nextInt();
    }
    public void get_details()
    {
        System.out.println("Name = "+name"\nauthor = "+author+"Price ="+price+"\nNumber of pages = "+num_pages);
    }

    public String toString()
    {
        return "Name="+this.name+"\nauthor="+this.author+"\nPrice="+this.price+"\nNumber of pages="+this.num_pages;
    }
    public static void main(String[] args)
    {
        int i;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of books :");
        int num=sc.nextInt();
        book b[]=new book[num];
        for(i=0;i<num;i++)
        {
            System.out.println("Enter the details of book "+(i+1));
            b[i] = new book();
            b[i].set_details();
        }
        System.out.println("The details of "+ num+" books are :");
        for(i=0;i<num;i++)
        {
            System.out.println("Book "+(i+1));
            System.out.println(b[i].toString());
        }
    }
}