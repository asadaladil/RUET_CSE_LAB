import java.util.Scanner;

public class equation
{
    public static void main(String Adil[])
    {
        Scanner scan =new Scanner(System.in);
        int a,b,c;
        a=scan.nextInt();
        b=scan.nextInt();
        c=scan.nextInt();

        double D=b*b-4*a*c;
        if(D==0)
        {
            System.out.println("x="+(-b/2));
        }
        else if(D>0)
        {
            System.out.println("x1="+((-b+Math.sqrt(D))/2));
            System.out.println("x1="+((-b-Math.sqrt(D))/2));
        }
        else
        {
            D*=-1;
            System.out.println("x1="+(-b/2)+"+"+Math.sqrt(D)+"i");
            System.out.println("x1="+(-b/2)+"-"+Math.sqrt(D)+"i");
        }
        scan.close();
    }
}