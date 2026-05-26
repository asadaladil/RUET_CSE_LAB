import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class speed extends JFrame
{
    int x=0;
    speed()
    {
        velocity();
    }   
    public void velocity()
    {
        setBounds(300,200 ,300,200 );
        setTitle("Speed Tracker");
        //setResizable(true);
        ImageIcon icon=new ImageIcon("photo.jpg");
        setIconImage(icon.getImage());

        Container c;
        c=this.getContentPane();
        c.setLayout(null);
        c.setBackground(Color.LIGHT_GRAY);

        Font f=new Font("Times New Roamn",Font.BOLD,25);
        Font g=new Font("Times New Roamn",Font.BOLD,15);
        Font ff=new Font("Times New Roman",Font.BOLD,10);

        JLabel lb=new JLabel("00");
        lb.setBounds(130,20,140,50);
        lb.setFont(f);
        c.add(lb);

        JButton minus=new JButton("(-)");
        minus.setBounds(50,80,60,25);
        minus.setFont(g);
        minus.setToolTipText("It will decrease the speed");
        c.add(minus);

        JButton reset=new JButton("Reset");
        reset.setBounds(110,80,60,25);
        reset.setFont(ff);
        reset.setToolTipText("It will set the speed 0");
        c.add(reset);

        JButton plus=new JButton("(+)");
        plus.setBounds(170,80,60,25);
        plus.setFont(g);
        plus.setToolTipText("It will increase the speed");
        c.add(plus);


        minus.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent e) 
            {
                if(x==0)
                {
                    JOptionPane.showMessageDialog(null,"Your Speed is already minimum value");
                }
                else
                {
                    x=x-1;
                    String s="";
                    if(x<10)
                    {
                        s="0";
                    }
                    else
                    {
                        s="";
                    }
                    lb.setText(s+Integer.toString(x));

                }
            }
        });
        plus.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent e) 
            {
                if(x==50)
                {
                    JOptionPane.showMessageDialog(null,"Your Speed is already maximum value");
                }
                else
                {
                    x=x+1;
                    String s="";
                    if(x<10)
                    {
                        s="0";
                    }
                    else
                    {
                        s="";
                    }
                    lb.setText(s+Integer.toString(x));
                }
            }
        });
        reset.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent e) 
            {
                lb.setText("00");
                x=0;
            }
        });
    }
    public static void main(String[] args) 
    {
        speed sp=new speed();
        sp.setVisible(true);
        sp.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
