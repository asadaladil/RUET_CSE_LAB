import java.util.ArrayList;
public class arraylist 
{
    public static void main(String Adil[])
    {
        ArrayList<Integer>ax=new ArrayList<>();
        ax.add(10);
        ax.add(50);
        ax.add(70);
        ax.add(30);
        Display(ax); //i)
        ax.add(1,60);
        Display(ax); //ii)
        System.out.println(ax.get(2)); //iii)
        ax.remove(3);
        Display(ax); // iv)
        ax.remove(ax.indexOf(10));
        Display(ax); // v)
        ax.sort(null);
        Display(ax); // vi)
        ax.clear();
        System.out.println(ax.size());

    }
    public static void Display(ArrayList<Integer>ax)
    {
        for(int i:ax)
        {
            System.out.print(i+" ");
        }
        System.out.println();
    }
}
