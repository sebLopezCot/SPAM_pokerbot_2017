package pokerbots.spam_framework.util;

public class Timer {
	
	private long lastTime = 0L;
	
	public void resetAndStart() {
		lastTime = System.nanoTime();
	}
	
	public long getElapsedTime() {
		return System.nanoTime() - lastTime;
	}
}
