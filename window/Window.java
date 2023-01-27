package window;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Window extends JFrame implements ActionListener
{
	private JTextArea textArea;
	private JButton button1, button2, button3;
	private JPanel panel1;
	private JScrollPane scrollPane;

	public Window()
	{
		super("Window");
		setSize(700, 700);
		setDefaultCloseOperation(3);
		setLayout(new BorderLayout());

		textArea = new JTextArea();
		textArea.setEditable(false);
		add(textArea, BorderLayout.CENTER);
		scrollPane = new JScrollPane(textArea);
		add(scrollPane, BorderLayout.CENTER);

		panel1 = new JPanel();
		panel1.setLayout(new GridLayout(1, 3));
		button1 = new JButton("Button 1");
		button1.addActionListener(this);
		panel1.add(button1);
		button2 = new JButton("Button 2");
		button2.addActionListener(this);
		panel1.add(button2);
		button3 = new JButton("Button 3");
		button3.addActionListener(this);
		panel1.add(button3);
		add(panel1, BorderLayout.SOUTH);

		
		pack();
		setVisible(true);
	}

	public void actionPerformed(ActionEvent e)
	{
		if (e.getSource() == button1)
		{
			textArea.append("Ahahahaha");
		}
		else if (e.getSource() == button2)
		{
			textArea.append("Ohohohoho");
		}
		else if (e.getSource() == button3)
		{
			System.exit(0);
		}
	}
}