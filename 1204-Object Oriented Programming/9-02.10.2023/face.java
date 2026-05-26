interface AI 
{
    void PrintA();
}
interface BI 
{
    void PrintB();
}
interface CI 
{
    void PrintC();
}
class A implements AI 
{
    @Override
    public void PrintA() 
    {
        System.out.println("Method PrintA() in class A");
    }
}
class B extends A implements BI 
{
    @Override
    public void PrintB() 
    {
        System.out.println("Method PrintB() in class B");
    }
}

class C extends B implements CI 
{
    @Override
    public void PrintC() 
    {
        System.out.println("Method PrintC() in class C");
    }
}

public class face 
{
    public static void main(String[] args) 
    {
        C c = new C();
        c.PrintA();
        c.PrintB();
        c.PrintC();
    }
}
