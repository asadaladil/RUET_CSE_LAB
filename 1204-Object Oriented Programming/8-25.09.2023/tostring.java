public class tostring 
{
    public static void main(String Adil[])
    {
        int ax[]={1,2,3,4,5,6,7};
        toString(ax);
        System.out.println(FindBig(ax[0],ax[1],ax[2],ax[3]));
    }
    public static void toString(int []ax)
    {
        for(int i:ax)
        {
            System.out.println(i);
        }
        System.out.println();
    }
    public static int FindBig(int...nums)
    {
        int x=-10;
        for(int i=0;i<4;i++)
        {
            x=nums[i]>x?nums[i]:x;
        }
        return x;
    }
}
