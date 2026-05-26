class A 
{
    int x;
    public A() 
    {
        x=0;
    }
    public A(int x) 
    {
        this.x=x;
    }
    public int getX() 
    {
        return (x+10);
    }
}
class B extends A 
{
    int x=20;
    B()
    {

    }
    B(int a)
    {
        super(a);
    }
    public int getX() 
    {
        return (x+10);
    }
    int  Display()
    {
        return super.x;
    }
    void getx_of_A()
    {
        System.out.println(super.getX());
    }
}

public class inheritance
{
    public static void main(String[] args) 
    {
        B b =new B(15);
        System.out.println(b.Display());
        b.getx_of_A();

    }
}