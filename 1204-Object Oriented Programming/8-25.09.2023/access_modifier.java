// Outside of package....
import school.Student;
public class access_modifier extends Student
{
    access_modifier()
    {

    }   
}
class sub extends access_modifier
{
    sub()
    {

    }
    void call()
    {
        //System.out.println(name);
        //System.out.println(age);
        System.out.println(result);
        System.out.println(roll);
    }

}
