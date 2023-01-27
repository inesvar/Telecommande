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
		setDefaultCloseOperation(3); // EXIT ON CLOSE
		setLayout(new BorderLayout());
		
		// scroll text area
		textArea = new JTextArea(50,50); // 50 lignes, 50 colonnes
		textArea.setEditable(false);
		add(textArea, BorderLayout.CENTER);
		scrollPane = new JScrollPane(textArea);
		add(scrollPane, BorderLayout.CENTER);

		// three buttons in a panel
		panel1 = new JPanel();
		panel1.setLayout(new GridLayout(1, 3));
		button1 = new JButton("content");
		button1.addActionListener(this);
		panel1.add(button1);
		button2 = new JButton("pas content");
		button2.addActionListener(this);
		panel1.add(button2);
		button3 = new JButton("suicide");
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
			textArea.append("\t:-)\n");
		}
		else if (e.getSource() == button2)
		{
			textArea.append("\t>= (\n");
		}
		else if (e.getSource() == button3)
		{
			System.exit(0);
		}
	}
}