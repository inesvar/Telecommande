package window;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Window extends JFrame implements ActionListener
{
	private JTextArea textArea;
	private JMenuBar menuBar;
	private JMenu menu;
	private JToolBar toolBar;
	private JButton button1, button2, button3;
	private Action action1, action2, action3;
	private JPanel panel1;
	private JScrollPane scrollPane;

	public Window()
	{
		super("Window");
		setSize(700, 700);
		setLayout(new BorderLayout());

		action1 = new Action("content", "\t:-)\n");
		action2 = new Action("pas content", "\t>= (\n");
		action3 = new Action("suicide");

		// creating the menu bar
		menuBar = new JMenuBar();
		menu = new JMenu("Menu");
		menu.add(action1);
		menu.add(action2);
		menu.add(action3);
		toolBar = new JToolBar();
		toolBar.add(action1);
		toolBar.add(action2);
		toolBar.add(action3);
		
		menuBar.add(menu);
		menuBar.add(toolBar);
		add(menuBar, BorderLayout.NORTH);

		// scroll text area
		textArea = new JTextArea(50,50); // 50 lignes, 50 colonnes
		textArea.setEditable(false);
		add(textArea, BorderLayout.CENTER);
		scrollPane = new JScrollPane(textArea);
		add(scrollPane, BorderLayout.CENTER);
		
		// three buttons in a panel
		/*panel1 = new JPanel();
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
		add(panel1, BorderLayout.SOUTH);*/

		setDefaultCloseOperation(3); // EXIT ON CLOSE
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

	class Action extends AbstractAction {

		private String write;

		public Action(String name, String write) {
			super(name);
			this.write = write;
		}

		public Action(String name) {
			super(name);
			this.write = null;
		}

		public void actionPerformed(ActionEvent e) {
			// if write is null
			if (write == null) {
				System.exit(0);
			} else {
				textArea.append(write);
			}
		}
	}
}