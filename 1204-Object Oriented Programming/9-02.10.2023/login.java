import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class login extends JFrame implements ActionListener 
{
    private JTextField usernameField;
    private JPasswordField passwordField;
    private JButton submitButton, refreshButton;

    public login() 
    {
        setTitle("Login Form");
        
        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new GridLayout(3, 2));
        JLabel usernameLabel = new JLabel("   Login   ");
        usernameField = new JTextField();
        JLabel passwordLabel = new JLabel("   Password   ");
        passwordField = new JPasswordField();
        
        submitButton = new JButton("Submit");
        submitButton.addActionListener(this);
        refreshButton = new JButton("Refresh");
        refreshButton.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e) 
            {
                usernameField.setText("");
                passwordField.setText("");
            }
        });
        mainPanel.add(usernameLabel);
        mainPanel.add(usernameField);
        mainPanel.add(passwordLabel);
        mainPanel.add(passwordField);
        mainPanel.add(submitButton);
        mainPanel.add(refreshButton);
        add(mainPanel);
        setSize(300, 150);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    @Override
    public void actionPerformed(ActionEvent e)
     {
        String username = usernameField.getText();
        String password = new String(passwordField.getPassword());

        String correctUsername = "admin";
        String correctPassword = "password";

        if (username.equals(correctUsername) && password.equals(correctPassword)) 
        {
            JOptionPane.showMessageDialog(this, "Login Successful", "Success", JOptionPane.INFORMATION_MESSAGE);
        } 
        else 
        {
            JOptionPane.showMessageDialog(this, "Invalid login/password", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public static void main(String[] args) 
    {
        SwingUtilities.invokeLater(() -> 
        {
            login loginForm = new login();
            loginForm.setVisible(true);
        });
    }
}
