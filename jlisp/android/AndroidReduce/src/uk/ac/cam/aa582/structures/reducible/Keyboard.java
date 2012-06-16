package uk.ac.cam.aa582.structures.reducible;


public interface Keyboard {

	void execute(Action action);
	void undo();
	void redo();
}
