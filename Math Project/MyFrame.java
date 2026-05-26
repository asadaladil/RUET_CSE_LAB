import javax.swing.*;
import java.awt.Color;
import java.awt.Container;
import java.awt.Cursor;
//import javax.swing.JPanel;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class MyFrame extends JFrame implements ActionListener {
    Container c;
    JButton btn1, btn2;
    JLabel label1, label2, label9;
    JTextField text1, text2;
    JPasswordField pass1;
    String[] username = { "zaman", "kamal" };
    String[] password = { "123", "user" };
    public MyFrame() 
    {
        c=this.getContentPane();
        c.setLayout(null);
        label1=new JLabel("Username");
        label1.setBounds(50,50,100,30);
        text1=new JTextField();
        text1.setBounds(120,50,180,30);
        label2=new JLabel("Password");
        label2.setBounds(50,80,100,30);
        pass1=new JPasswordField();
        pass1.setBounds(120,80,180,30);
        btn1=new JButton("Cancel");
        btn1.setBounds(100,150,100,30);
        btn2=new JButton("Login");
        btn2.setBounds(210,150,100,30);
        label9=new JLabel();
        label9.setBounds(120,200,180,30);
        btn1.addActionListener(this);
        btn2.addActionListener(this);
        c.add(label1);
        c.add(text1);
        c.add(label2);
        c.add(pass1);
        c.add(btn1);
        c.add(btn2);
        c.add(label9);
    }
    public void actionPerformed(ActionEvent e) 
    {
        int flag=0;
        String s=new String(pass1.getPassword());
        if(e.getSource()==btn1)
            dispose(); //close the frame
        if(e.getSource()==btn2) 
        {
            for(int i=0;i<username.length;i++) 
            {
                if(username[i].equals(text1.getText()))
                    if(password[i].equals(s))
                        flag++;
            }
            if(flag==1)
                label9.setText("Valid User");
            else
                label9.setText("Worng username/password");
        }
    }
}
class First 
{
    public static void main(String[] args) 
    {
        MyFrame frame=new MyFrame();
        frame.setBounds(200, 100,400,500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}

class Firstl {
    public static void main(String[] args) {
        MyFrame frame = new MyFrame();
        frame.setBounds(200, 100, 400, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}

class BackgroundExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Background Example");
        // Set the size and close operation
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // Get the content pane and set its background color
        Container c = frame.getContentPane();
        c.setLayout(new FlowLayout());
        // c.setBackground(Color.RED);
        Color cl = new Color(155, 100, 0);
        c.setBackground(cl);
        JLabel label = new JLabel("Username:");
        JLabel label2 = new JLabel("Name:");
        // label.setText(“User Name:”);
        // label.setBounds(0,0,0,0);
        // JTextField text=new JTextField();
        // text.setText("type here");
        // text.setBounds(50,30,100,20);
        // text.setForeground(Color.blue);
        // text.setBackground(Color.cyan);
        // text.setEditable(true);
        JPasswordField text = new JPasswordField();
        text.setBounds(50, 30, 100, 20);
        text.setForeground(Color.blue);
        text.setBackground(Color.cyan);
        text.setEchoChar('*');
        text.setEditable(true);
        JButton btn = new JButton("Submit");
        btn.setBounds(100, 50, 100, 30);
        Cursor cursor = new Cursor(Cursor.HAND_CURSOR);
        btn.setCursor(cursor);
        btn.setEnabled(true);
        c.add(btn);
        // c.add(text);
        c.add(label2);
        c.add(label);
        c.add(text);
        frame.setResizable(false);

        frame.setVisible(true);

    }
}
