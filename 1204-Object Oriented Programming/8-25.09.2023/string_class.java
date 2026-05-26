public class string_class 
{
    public static void main(String Adil[])
    {
        String s1="Java Programming ",s2="is good";
        String s3="";
        Integer x=1234567;
        System.out.println(s1.charAt(0));
        System.out.println(s1.compareTo(s2));
        s3=s1.concat(s2);
        System.out.println(s3);
        System.out.println(s1.equals(s2));
        System.out.println(s2.isEmpty());
        System.out.println(s1.length());
        System.out.println(s3.replace("Java","JAVA"));
        System.out.println(s3.substring(5, 16));
        System.out.println(s1.toLowerCase());
        System.out.println(s2.toUpperCase());
        s3=x.toString();
        System.out.println(s3.charAt(2));
        String s4="    Hello,Java      ";
        String s5=s4.trim();
        System.out.println(s5);
    }   
}
