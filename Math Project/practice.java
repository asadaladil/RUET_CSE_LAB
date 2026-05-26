import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class practice extends JFrame
{
    practice()
    {
        control();
    }
    class Actionn implements ActionListener
        {
            public void actionPerformed(ActionEvent e) 
            {
                String s=e.getActionCommand();
                if(s.isEmpty())
                {
                    JOptionPane.showMessageDialog(null,"You did not enter any messeges");
                    return;    
                }
                JOptionPane.showMessageDialog(null,s);
            }
        }
    public void control()
    {
        Container c;
        c=this.getContentPane();
        c.setLayout(null);
        c.setBackground(Color.lightGray);

        Font f=new Font("Times New Roman",Font.BOLD,15);

        JTextField f1;
        
        JLabel lb=new JLabel();
        f1=new JTextField();
        lb.setText("Username:");
        lb.setBounds(30,2,200,40);
        f1.setBounds(100, 2, 200, 40);
        f1.setHorizontalAlignment(JTextField.CENTER);
        f1.setFont(f);
        c.add(f1);
        lb.setFont(f);
        lb.setForeground(Color.GREEN);
        lb.setOpaque(true);
        lb.setBackground(Color.black);
        lb.setToolTipText("Enter your Username here");
        c.add(lb);  

        JLabel pass=new JLabel();
        pass.setText("Password:");
        pass.setBounds(30,50,150,40);
        // f2=new JTextField();
        // f2.setBounds(100, 50, 200, 40);
        // f1.setFont(f);
        // c.add(f2);
        JPasswordField f2=new JPasswordField();
        f2.setBounds(100, 50, 200, 40);
        f2.setHorizontalAlignment(JTextField.CENTER);
        f2.setEchoChar('*');
        f2.setFont(f);
        c.add(f2);
        pass.setFont(f);
        pass.setForeground(Color.GREEN);
        pass.setOpaque(true);
        pass.setBackground(Color.black);
        pass.setToolTipText("Enter your Password Here");
        c.add(pass);


        setBounds(400,300 ,400,400 );
        setTitle("TitileBar");
        setResizable(false);
        ImageIcon icon=new ImageIcon("photo.jpg");
        setIconImage(icon.getImage());

        JButton bt=new JButton("Submit");
        bt.setBounds(60,100,100,40);
        bt.setFont(f);
        c.add(bt);
        JButton bt2=new JButton("Cancel");
        bt2.setBounds(170,100,100,40);
        bt2.setFont(f);
        c.add(bt2);

        Cursor cr=new Cursor(Cursor.HAND_CURSOR);
        bt.setCursor(cr);

        // Action Lisner::::::
        //Actionn act=new Actionn();
        //f1.addActionListener(act);
        //f2.addActionListener(act);
        // bt.addActionListener(act);
        // bt2.addActionListener(act);
        bt.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent e) 
            {
                String s,r;
                s=f1.getText();
                r=f2.getText();
                System.out.println(r);
                if(s.isEmpty()||r.isEmpty())
                {
                    JOptionPane.showMessageDialog(null, "Login Failed");
                    return;
                }
                JOptionPane.showMessageDialog(null, "Login Successful");
                
            }
        });
        bt2.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent e) 
            {
                f1.setText("");
                f2.setText("");
            }
        });

    }
    public static void main(String[] args) 
    {
        //JOptionPane.showInputDialog("Enter your name:",JOptionPane.showInputDialog("First name"));
        //JOptionPane.showConfirmDialog(null, "Do you want to quit?", "Decision", JOptionPane.YES_NO_CANCEL_OPTION);
        practice frame=new practice();
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }   

}
