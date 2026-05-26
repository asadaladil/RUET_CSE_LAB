import java.util.Arrays;

public class anonymous_object 
{
    public static void main(String Adil[])
    {
        int A[]=InitialArray();
        for(int i:A)
        {
            System.out.print(i+" ");
        }
        System.out.println();
        int B[]=SortArray();
        for(int i:B)
        {
            System.out.print(i+" ");
        }
        System.out.println();
    }
    public static int[] InitialArray()
    {
        return new int[]{2,4,6,1,3,5};
    }
    public static int[] SortArray()
    {
        int A[]=InitialArray();
        Arrays.sort(A);
        return A;
    }
}
