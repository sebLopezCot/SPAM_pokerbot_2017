package pokerbots.spam_framework.util;

public class Timer {
	
	private long lastTime = 0L;
	
	public void resetAndStart() {
		lastTime = System.nanoTime();
	}
	
	public double getElapsedTime() {
		return (System.nanoTime() - lastTime) * 1e-9;
	}
}
