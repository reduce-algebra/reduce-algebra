package uk.ac.cam.aa582.structures.boxes;

public class Timer {
	
	private static long start_time = 0l;
	private static long finish_time = 0l;
	
	public static void start() {
		start_time = System.currentTimeMillis();
	}
	
	public static void finish() {
		finish_time = System.currentTimeMillis();
	}
	
	public static long time() {
		return (finish_time - start_time);
	}
}
