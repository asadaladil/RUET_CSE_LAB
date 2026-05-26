class Student
{
    public int roll=10;
    Student()
    {

    }
    private void show()
    {
        System.out.println("Roll is: "+10);
    }
    public void call()
    {
        show();
    }
}
public class private_method
{
    public static void main(String Adil[])
    {
        Student info=new Student();
        //info.show();
        info.call();
    }    
}
