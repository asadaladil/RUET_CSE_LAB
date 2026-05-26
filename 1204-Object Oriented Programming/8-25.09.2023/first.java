import java.util.Scanner;
import java.text.DecimalFormat;
import java.util.ArrayList; // for dynamic array
class first
{
    public static void main(String kargs[])
    {
        System.out.println("Enter your value: ");
        Scanner scan=new Scanner(System.in);
        int userinput=scan.nextInt();

        // Array declare....
        int A[]=new int[userinput];

        // Dynamic Array
        ArrayList<Integer>Adil=new  ArrayList<Integer>(); // for string-->String, char-->Character 
        ArrayList<Float>B=new ArrayList<Float>();

        B.add(10.27563453f); // for floatng point f must be add at the last of decimal digit.......
        // 6 is default as max
        DecimalFormat df= new DecimalFormat("#.##########");
        String s=df.format(B.get(0));
        // System.out.println(B.get(0));
        System.out.println(s);
        // for getting greater than 6 decimal 


        // System.out.println(userinput);
        for(int i=1;i<=userinput;i++)
        {
            A[i-1]=i;
            Adil.add(i);
        }
        for(int i=0;i<userinput;i++)
        {
            //System.out.println(A[i]);
            System.out.println(Adil.get(i));
        }
        
        scan.close();
    }
}