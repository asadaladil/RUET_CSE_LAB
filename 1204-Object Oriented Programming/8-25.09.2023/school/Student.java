package school;
// within class
public class Student 
{
    private String name="Tom";
    int age=17;    
    public int roll=10;
    protected float result=4.95f; 
    public Student() 
    {

    }
    void show()
    {
        System.out.println(name);
        System.out.println(age);
        System.out.println(roll);
        System.out.println(result);
    }
}
