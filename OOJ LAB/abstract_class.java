
abstract class Shape {
    int dimension1, dimension2;
    
    abstract void printArea();
}

class Rectangle extends Shape {

    Rectangle(int length, int width) {
        this.dimension1 = length;
        this.dimension2 = width;
    }
    
    @Override
    void printArea() {
        int area = dimension1 * dimension2;
        System.out.println("Area of Rectangle: " + area);
    }
}

class Triangle extends Shape {

    Triangle(int base, int height) {
        this.dimension1 = base;
        this.dimension2 = height;
    }
    
    @Override
    void printArea() {
        double area = 0.5 * dimension1 * dimension2;
        System.out.println("Area of Triangle: " + area);
    }
}

class Circle extends Shape {
    
    Circle(int radius) {
        this.dimension1 = radius;
    }
    
    @Override
    void printArea() {
        double area = Math.PI * dimension1 * dimension1;
        System.out.println("Area of Circle: " + area);
    }
}

public class Main {
    public static void main(String[] args) {

        Shape rectangle = new Rectangle(5, 10);
        Shape triangle = new Triangle(6, 8);
        Shape circle = new Circle(7);
        
        rectangle.printArea();
        triangle.printArea();
        circle.printArea();
    }
}
