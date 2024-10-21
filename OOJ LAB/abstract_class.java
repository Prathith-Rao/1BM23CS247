abstract class shape{
    int l,b;
    abstract void printarea();
}
class rectangle extends shape{
    rectangle(int length,int breadth)
    {
        this.l=length;
        this.b=breadth;
    }
    @Override
    void printarea()
    {
        int area=l*b;
        System.out.println("Area of the rectangle ="+area);
    }
}
class triangle extends shape{
    triangle(int height,int width)
    {
        this.l=height;
        this.b=width;
    }
    @Override
    void printarea()
    {
        double area=0.5*l*b;
        System.out.println("Area of the triangle ="+area);
    }
}
class circle extends shape{
    circle(int radius)
    {
        this.l=radius;
    }
    @Override
    void printarea()
    {
        double area=3.14*l*l;
        System.out.println("Area of the circle ="+area);
    }
}
public class abstract_class
{
    public static void main(String []args)
    {
        
        shape rectangle = new rectangle(5, 10);
        shape triangle = new triangle(6, 8);
        shape circle = new circle(7);
        
        rectangle.printarea();
        triangle.printarea();
        circle.printarea();
    }
}
