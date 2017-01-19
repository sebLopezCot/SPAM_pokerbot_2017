package pokerbots.player;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;

import pokerbots.spam_framework.GameState;
import pokerbots.spam_framework.packet.GetActionPacket;
import pokerbots.spam_framework.packet.HandOverPacket;
import pokerbots.spam_framework.packet.Packet;
import pokerbots.spam_framework.packet.PacketParser;
import pokerbots.spam_framework.packet.RequestKeyValuesPacket;
import pokerbots.spam_framework.strategy.BasicStrategy;

/**
 * Simple example pokerbot, written in Java.
 * 
 * This is an example of a bare bones, pokerbot. It only sets up the socket
 * necessary to connect with the engine and then always returns the same action.
 * It is meant as an example of how a pokerbot should communicate with the
 * engine.
 * 
 */
public class GameEntry {
	
	private boolean DEBUG = true;
	
	private final PrintWriter outStream;
	private final BufferedReader inStream;
	
	public GameEntry(PrintWriter output, BufferedReader input) {
		this.outStream = output;
		this.inStream = input;
	}
	
	public void run() {
		String input;
		try {
			// Start a new game engine
			GameState gameState = new GameState();
			PacketParser parser = new PacketParser();
			BasicStrategy basicStrat = new BasicStrategy();
			
			// Block until engine sends us a packet; read it into input.
			while ((input = inStream.readLine()) != null) {

				// Here is where you should implement code to parse the packets
				// from the engine and act on it.
				System.out.println(input);

				// Parse the packet, update the gamestate, and perform an action
				Packet packet = parser.parse(input);
				packet.updateGameState(gameState);
				if(packet instanceof GetActionPacket || packet instanceof RequestKeyValuesPacket){
					
					String action = basicStrat.getAction(gameState);
					
					if (DEBUG) {
						System.out.println("MY ACTION: " + action);
					}
					
					outStream.println(action);
					
				} else if (packet instanceof HandOverPacket){
					System.out.println("----------------------------------------------------------------------------");
				}
				
				System.out.println(" ");
			}
		} catch (IOException e) {
			System.out.println("IOException: " + e.getMessage());
		}

		System.out.println("Gameover, engine disconnected");
		
		// Once the server disconnects from us, close our streams and sockets.
		try {
			outStream.close();
			inStream.close();
		} catch (IOException e) {
			System.out.println("Encounterd problem shutting down connections");
			e.printStackTrace();
		}
	}
	
}
