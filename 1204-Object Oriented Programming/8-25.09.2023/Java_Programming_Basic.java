import java.util.Scanner;
public class Java_Programming_Basic 
{
    public static void main(String kargs[])
    {
        Scanner scan=new Scanner(System.in);

        // i)
        System.out.println("MD. ASAD-AL-ADIL");
        System.out.println("Rajshahi");

        // ii)
        int a=scan.nextInt(),b=scan.nextInt();
        System.out.println("Max Number: "+(a>b?a:b));

        // iii)
        int ax[]=new int[10];
        int sum=0;int mx=-100,mn=10000000;
        for(int i=0;i<10;i++)
        {
            System.out.print("Enter "+(i+1)+" number: " );
            ax[i]=scan.nextInt();
        }
          for(int i=0;i<10;i++)
        {
            sum=sum+ax[i];
            mx=mx>a?mx:ax[i];
            mn=mn<a?mn:ax[i];
        }
        System.out.println("The sum of 10 values is: "+sum);
        System.out.println("The MAX of 10 Values is: "+mx);
        System.out.println("The MAX of 10 Values is: "+mn);
        System.out.println(("The Average of 10 Values is: "+(float)sum/10)); // uses of type casting.......

        scan.close();
    }
}
