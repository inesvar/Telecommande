package window;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.ArrayList;

public class Window extends JFrame implements ActionListener
{
	private JTextArea textArea;
	private JMenuBar menuBar;
	private JToolBar toolBar;
	private JButton button1, button2, button3;
	private Action printAll, eraseAll, exit;
	private JPanel mainPanel, panel1, panel2, panel3;
	private JScrollPane scrollPane;
	private Client client;
	private ArrayList<String> onScreenElements;

	public Window(Client client)
	{
		super("Window");
		setSize(1500, 1500);
		setLayout(new BorderLayout());
		this.client = client;
		this.onScreenElements = new ArrayList<String>();

		printAll = new Action("print_all");
		eraseAll = new Action("erase_all");
		exit = new Action("exit", true);

		// creating the menu bar
		menuBar = new JMenuBar();
		toolBar = new JToolBar();
		toolBar.add(printAll);
		toolBar.add(eraseAll);
		toolBar.add(exit);
		
		menuBar.add(toolBar);

		// panels
		mainPanel = new JPanel();
		add(mainPanel, BorderLayout.SOUTH);
		add(toolBar, BorderLayout.NORTH);
		panel1 = new JPanel();
		mainPanel.add(panel1, BorderLayout.EAST); // terminal type panel
		panel2 = new JPanel();
		mainPanel.add(panel2, BorderLayout.NORTH); // the responses of the server
		panel3 = new JPanel();
		panel3.setLayout(new GridLayout(3, 3));
		mainPanel.add(panel3, BorderLayout.SOUTH); // the multimedia elements
		
		//panel3.add(printAll);

		// scroll text area
		textArea = new JTextArea(30,70); // 50 lignes, 50 colonnes
		textArea.setEditable(false);
		textArea.setLineWrap(true);
		panel2.add(textArea, BorderLayout.CENTER);

		scrollPane = new JScrollPane(textArea);
		panel2.add(scrollPane, BorderLayout.CENTER);
		
		setDefaultCloseOperation(3); // EXIT ON CLOSE
		pack();
		setVisible(true);
	}

	public void actionPerformed(ActionEvent e){}

	class Action extends AbstractAction {

		private String action;
		private boolean exit;

		public Action(String name) {
			super(name);
			this.action = name;
			this.exit = false;
			System.out.println("aha");
		}

		public Action(String name, boolean exit) {
			super(name);
			this.action = name;
			this.exit = exit;
		}

		public void actionPerformed(ActionEvent e) {
			if (exit) {
				System.exit(0);
			} else {
				String response = client.send(action);
				// replacing sequences of 95 spaces with \n
				response = response.replace("                                                                                               ", "\n");
				//response = response.replace("name", "aha");
				System.out.println(response);
				textArea.append(response + "\n");
				if (action.equals("print_all")) {
					String[] elements = response.split("\n");
					String[] files = new String[elements.length];
					for (int i = 0; i < elements.length; i++) {
						files[i] = elements[i].split(" ")[2];
					}
					for (String file : files) {
						if (!onScreenElements.contains(file)) {
							onScreenElements.add(file);
							//if (file.endsWith(".jpg") || file.endsWith(".png")) {
								button1 = new JButton(file);
								button1.setPreferredSize(new Dimension(250,100));
								//JLabel label = new JLabel(new ImageIcon(file));
								panel3.add(button1);
								pack();
								System.out.println("added " + file);
							/*} else if (file.endsWith(".mp3")) {
								// TODO
							} else if (file.endsWith(".mp4")) {
								// TODO
							}*/
						}
					}
				/*} else if (action.equals("erase_all")) {
					onScreenElements.clear();
					panel3.removeAll();*/
				}
			}
		}
	}
}