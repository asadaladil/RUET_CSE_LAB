package school;
// within package
public class Teacher extends Student
{
    public Teacher() 
    {

    }
    void show()
    {
        //System.out.println(name);
       System.out.println(age);
       System.out.println(roll);
       System.out.println(result);
    }
}
class sub extends Teacher
{
    sub()
    {

    }
    void show()
    {
       //System.out.println(name);
       System.out.println(age);
       System.out.println(roll);
       System.out.println(result);
    }
}
