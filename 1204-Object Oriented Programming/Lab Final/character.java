import java.util.Scanner;
public class character
{
    public static void main(String Adil[])
    {
        Scanner scan=new Scanner(System.in);
        String s=scan.nextLine();
        s.toLowerCase();
        System.out.println(s);
        int vowels=0,conso=0,digit=0,sp_ch=0;
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)=='a'||s.charAt(i)=='e'||s.charAt(i)=='i'||s.charAt(i)=='o'||s.charAt(i)=='u')
            {
                vowels+=1;
            }
            else if(s.charAt(i)>='a'&&s.charAt(i)<='z')
            {
                conso+=1;
            }
            else if(s.charAt(i)==' ')
            {
                continue;
            }
            else if(s.charAt(i)>='0'&&s.charAt(i)<='9')
            {
                digit+=1;
            }
            else
            {
                sp_ch+=1;
            }
        }
        System.out.println("vowels = "+vowels);
        System.out.println("consonant = "+conso);
        System.out.println("Digits = "+digit);
        System.out.println("Special Character = "+sp_ch);


        scan.close();
    }
}