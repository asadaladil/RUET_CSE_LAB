public class static_method
{
    public static void  print()
    {
        System.out.println("Hello java");
    }
    public int sum()
    {
        int a=10,b=20;
        return a+b;
    }
    public static void call()
    {
        print();
        //int x=sum();
    }
}
