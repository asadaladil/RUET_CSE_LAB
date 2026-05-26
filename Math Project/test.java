import java.awt.Point;
import java.util.ArrayList;
import java.util.Stack;
import java.time.Instant;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.time.ZoneId;
import java.time.format.DateTimeFormatter;
public class test 
{
    public static void main(String[] args) 
    {
    //     String r="",s1="(((10+45.25)*4)/13)",s="(5*(6+2)-12/4)";
    //     Stack<Character>st =new Stack<>();
    //     Stack<Double>std=new Stack<>();
    //     for(int i=0;i<s.length();i++)
    //     {
    //         char k=s.charAt(i);
    //         if(k>='0'&&k<='9'||k=='.')
    //         {
    //             r+=k;
    //         }
    //         else
    //         {
    //             try
    //             {
    //                 if (r.length()!=0)
    //                 {
    //                     Double d=Double.parseDouble(r);
    //                     std.push(d);
    //                     r="";
    //                 }
    //             }
    //             catch(Exception e)
    //             {

    //             }
    //             if(k=='('||st.empty()||prec(st.peek())<=prec(k)&&k!=')')
    //             {
    //                 st.push(k);
    //             }
    //             else if(k==')')
    //             {
    //                 while(!st.empty()&&st.peek()!='(')
    //                 {
    //                     Double d1=std.peek();std.pop();
    //                     Double d2=std.peek();std.pop();
    //                     if (st.peek()=='+')
    //                     {
    //                         std.push(d2+d1);
    //                     }
    //                     else if (st.peek()=='-')
    //                     {
    //                         std.push(d2-d1);
    //                     }
    //                     else if (st.peek()=='*')
    //                     {
    //                         std.push(d2*d1);
    //                     }
    //                     else if (st.peek()=='/')
    //                     {
    //                         std.push(d2/d1);
    //                     }
    //                     st.pop();
    //                 }
    //                 st.pop(); 
    //             }
    //             else if(prec(st.peek())>prec(k))
    //             {
    //                 while(!st.empty()&&prec(st.peek())>prec(k))
    //                 {
    //                     Double d1=std.peek();std.pop();
    //                     Double d2=std.peek();std.pop();
    //                     if (st.peek()=='+')
    //                     {
    //                         std.push(d2+d1);
    //                     }
    //                     else if (st.peek()=='-')
    //                     {
    //                         std.push(d2-d1);
    //                     }
    //                     else if (st.peek()=='*')
    //                     {
    //                         std.push(d2*d1);
    //                     }
    //                     else if (st.peek()=='/')
    //                     {
    //                         std.push(d2/d1);
    //                     }
    //                     st.pop();
    //                 }
    //                 st.push(k);
    //             }
    //         }
    //     }
    //     System.out.println(std.peek());
        LocalDateTime local=LocalDateTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("MM");
        String k=local.format(formatter);
        System.out.println(k);

        // long timestamp = 1711431795L; // Unix timestamp
        // Instant instant = Instant.ofEpochSecond(timestamp); // Convert timestamp to Instant
        // LocalDateTime dateTime = LocalDateTime.ofInstant(instant, ZoneId.systemDefault()); // Convert Instant to LocalDateTime
        // DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        // String formattedDate = dateTime.format(formatter);
        // System.out.println("Formatted Date: " + formattedDate);
        


    }
    // private static int prec(char k)
    // {
    //     if(k=='+'||k=='-')
    //     {
    //         return 0;
    //     }
    //     else if (k=='*'||k=='/')
    //     {
    //         return 1;
    //     }
    //     return -2;
    //
     //}


}
class AssetLocation {
    private String assetDescription;
    private int assetId;
    private double latitude;
    private double longitude;

    public AssetLocation(String assetDescription, int assetId, double latitude, double longitude) {
        this.assetDescription = assetDescription;
        this.assetId = assetId;
        setLatitude(latitude);
        setLongitude(longitude);
    }

    public String getAssetDescription() {
        return assetDescription;
    }

    public int getAssetId() {
        return assetId;
    }

    public double getLatitude() {
        return latitude;
    }

    public double getLongitude() {
        return longitude;
    }

    public void setLatitude(double latitude) {
        if (isValidLatitude(latitude)) {
            this.latitude = latitude;
        } else {
            throw new IllegalArgumentException("Invalid latitude value");
        }
    }

    public void setLongitude(double longitude) {
        if (isValidLongitude(longitude)) {
            this.longitude = longitude;
        } else {
            throw new IllegalArgumentException("Invalid longitude value");
        }
    }

    private boolean isValidLatitude(double latitude) {
        return latitude >= -90.0 && latitude <= 90.0;
    }

    private boolean isValidLongitude(double longitude) {
        return longitude >= -180.0 && longitude <= 180.0;
    }

    public static void main(String[] args) {
        // Example usage
        AssetLocation mobileAsset = new AssetLocation("Vehicle", 1, -35.0, -75.0);
        System.out.println("Mobile Asset Location: Latitude " + mobileAsset.getLatitude() +
                ", Longitude " + mobileAsset.getLongitude());

        AssetLocation staticAsset = new AssetLocation("Warehouse", 2, 40.0, -120.0);
        System.out.println("Static Asset Location: Latitude " + staticAsset.getLatitude() +
                ", Longitude " + staticAsset.getLongitude());

        // Try setting an invalid latitude
        // try {
        //     mobileAsset.setLatitude(100.0);
        // } catch (IllegalArgumentException e) {
        //     System.out.println("Error: " + e.getMessage());
        // }
    }
}
