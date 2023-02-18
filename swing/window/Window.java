package window;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.ArrayList;
import java.util.Arrays;

public class Window extends JFrame implements ActionListener
{
	private JTextArea serverAnswerTextZone, terminalTextZone;
	private JPanel terminalPanel, serverMsgPanel, mediaButtonsPanel;
	private Client client;
	private ArrayList<String> onScreenElements = new ArrayList<String>();
	private int nbRequests = 0;
	private enum RequestOrigin {TERMINAL, BUTTON, IMPLICIT};

	public Window(Client client)
	{
		super("Window");
		setSize(1500, 1500);
		setLayout(new BorderLayout());
		this.client = client;

		AbstractAction printAll = new sendRequestAction("print_all");
		AbstractAction eraseAll = new sendRequestAction("erase_all");
		AbstractAction saveAll = new sendRequestAction("save userSave");
		AbstractAction restoreAll = new sendRequestAction("restore userSave");
		AbstractAction exit = new exitAction();

		// creating the tool bar
		JToolBar toolBar = new JToolBar();
		toolBar.add(printAll);
		toolBar.add(eraseAll);
		toolBar.add(saveAll);
		toolBar.add(restoreAll);
		toolBar.add(exit);
		toolBar.setFloatable(false);

		// panels
		JPanel mainPanel = new JPanel();
		mainPanel.setLayout(new BorderLayout());
		add(mainPanel, BorderLayout.CENTER);
		add(toolBar, BorderLayout.NORTH);
		terminalPanel = new JPanel();
		mainPanel.add(terminalPanel, BorderLayout.EAST); // terminal type panel
		serverMsgPanel = new JPanel();
		mainPanel.add(serverMsgPanel, BorderLayout.WEST); // the responses of the server panel
		mediaButtonsPanel = new JPanel();
		mediaButtonsPanel.setLayout(new GridLayout(3, 3));
		add(mediaButtonsPanel, BorderLayout.SOUTH); // media buttons panel

		mediaButtonsPanel.add(new JLabel("Media will appear here."));

		// terminal area
		terminalTextZone = new JTextArea(30,80); // 50 lignes, 50 colonnes
		terminalTextZone.setEditable(true);
		terminalTextZone.setLineWrap(true);
		terminalPanel.add(terminalTextZone, BorderLayout.CENTER);
		terminalTextZone.append("The possible requests are : find <name>, find_g <group_name>, ");
		terminalTextZone.append("play <name>, print <name>, print_g <group_name>, create_photo <name> <path>, ");
		terminalTextZone.append("create_film <name> <path>, create_video <name> <path>, create_g <name>, erase <name>, ");
		terminalTextZone.append("erase_g <name>, save <filename>, restore <filename>, print_all, erase_all\n\n");
		terminalTextZone.append("Welcome to the client terminal. Type your commands here.\n>> ");
		// set up terminalTextZone so that it can act as a terminal
		terminalTextZone.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent e) {
				if (e.getKeyCode() == KeyEvent.VK_ENTER) {
					// prevent the enter key from being added to the text area as it will be added manually
					e.consume();
					// get the command from the terminal
					//System.out.println(Arrays.toString(terminalTextZone.getText().split("\n")));
					String command = terminalTextZone.getText().split("\n")[3 + nbRequests];
					command = command.substring(3, command.length());
					//System.out.println("command "+command);
					sendRequest(command, RequestOrigin.TERMINAL);

				// backspace key
				} else if (e.getKeyCode() == KeyEvent.VK_BACK_SPACE) {
					e.consume();
				}
			}
		});


		// server message area
		serverAnswerTextZone = new JTextArea(30,80); // 50 lignes, 50 colonnes
		serverAnswerTextZone.setEditable(false);
		serverAnswerTextZone.setLineWrap(true);
		serverMsgPanel.add(serverAnswerTextZone, BorderLayout.CENTER);
		serverAnswerTextZone.append("Responses of the server will appear here.\n");

		JScrollPane serverMsgScrollPane = new JScrollPane(serverAnswerTextZone);
		serverMsgPanel.add(serverMsgScrollPane, BorderLayout.CENTER);

		JScrollPane terminalScrollPane = new JScrollPane(terminalTextZone);
		terminalPanel.add(terminalScrollPane, BorderLayout.CENTER);
		
		setDefaultCloseOperation(3); // EXIT ON CLOSE
		pack();
		setVisible(true);
	}

	public void sendRequest(String action, RequestOrigin type) {
		String response = client.send(action);
		System.out.println("answer from the server :\n"+response);
		// replacing sequences of 95 spaces with \n

		switch (type) {
			case BUTTON:
				terminalTextZone.append(action);
			case TERMINAL:
				terminalTextZone.append("\n>> ");
				nbRequests++;
				response = response.replace("          ", "\n");
				//System.out.println("response "+response);
				serverAnswerTextZone.append("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"+response + "\n");
				break;
			case IMPLICIT:
				response = response.replace("          ", "\n");
				//System.out.println("response "+response);
		}
		if (action.equals("print_all")) {
			refresh(response);
		} else {
			sendRequest("print_all", RequestOrigin.IMPLICIT);
		}
	}

	public void refresh(String response) {
		String[] elements = response.split("\n");
		mediaButtonsPanel.removeAll();
		mediaButtonsPanel.repaint();
		onScreenElements.clear();
		if (elements.length == 1) {
			mediaButtonsPanel.add(new JLabel("No media found."));
			pack();
			return;
		}
		ArrayList<String> files = new ArrayList<>();
		//System.out.println(Arrays.toString(elements));
		for (int i = 0; i < elements.length; i++) {
			//System.out.println(elements[i]);
			if (elements[i].split(" ")[0].equals("GROUP"))
				continue;
			files.add(elements[i].split(" ")[2]);
		}
		for (String file : files) {
			if (!onScreenElements.contains(file)) {
				onScreenElements.add(file);
				sendRequestAction a = new sendRequestAction("play "+file);
				JButton button = new JButton(a);
				button.setBackground(Color.WHITE);
				button.setPreferredSize(new Dimension(250,100));
				mediaButtonsPanel.add(button);

				System.out.println("added " + file + " to the mediaButtonsPanel");
			}
		}
		pack();
	}

	public void actionPerformed(ActionEvent e){
	}

	class sendRequestAction extends AbstractAction {

		private String action;

		public sendRequestAction(String name) {
			super(name);
			this.action = name;
		}

		public void actionPerformed(ActionEvent e) {
			sendRequest(action, RequestOrigin.BUTTON);
		}
	}

	class exitAction extends AbstractAction {
		public exitAction() {
			super("exit");
		}
		public void actionPerformed(ActionEvent e) {
			System.exit(0);
		}
	}
}