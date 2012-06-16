package uk.ac.cam.aa582.interactivity;

import uk.ac.cam.aa582.R;
import uk.ac.cam.aa582.reduce.Reduce;
import uk.ac.cam.aa582.structures.boxes.Box;
import uk.ac.cam.aa582.structures.reducible.Action;
import uk.ac.cam.aa582.structures.reducible.ExpressionBuilder;
import uk.ac.cam.aa582.structures.reducible.Reducible;
import android.content.Context;
import android.os.AsyncTask;
import android.util.AttributeSet;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.LinearLayout;

public class InputOutputLayout extends LinearLayout implements Action, ScreenInfo, OnClickListener {

	public InputOutputLayout(Context context, AttributeSet attrs) {
		super(context, attrs);
		this.addView(current);
		this.setOrientation(VERTICAL);
	}

	SimplifyInputView current = new SimplifyInputView(getContext()).setScreenInfo(this);
	KeyboardManager keyboard;
	
	public void setInputKeyboard(KeyboardManager keyboard) {
		this.keyboard = keyboard;
		keyboard.setListener(R.id.enter_button,this);
		current.setInputKeyboard(keyboard);
	}

	@Override
	public void exec() {
		// pacify the user with some animation 
		inflate(getContext(), R.layout.progress, this);
					
		// input goes to JLisp
		current.onLoseFocus();		
		keyboard.disableAllButtons();
		keyboard.flushUndoStack();		
		
		// Create an asynchronous task, because reduce may
		// take a while and you don't want the app to hang
		new AsyncTask<InputView,Void,OutputView>() {
			
			@Override // this method runs asynchronously
			protected OutputView doInBackground(InputView... params) {
				InputView current = params[0];
				Reducible reduceInput = current.toReducible();
				Reduce reduce = new Reduce(getContext());
				Box result = reduce.reduce(reduceInput);
				
				// just for optimization
				OutputView outputView = new OutputView(getContext(), result, InputOutputLayout.this);

				return outputView;
			}
		
			@Override // this is executed on the UI thread after the async method returns
			protected void onPostExecute(OutputView outputView){
				
				current.setOnClickListener(InputOutputLayout.this);
				InputOutputLayout.this.removeViewAt(InputOutputLayout.this.getChildCount()-1);
				//InputOutputLayout.this.removeView(animation);
				addView(outputView);
				addView(new View(getContext()) { // this is only a margin
					@Override
					public void onMeasure(int w, int h) {
						setMeasuredDimension(0,22);
					}
				});
				current = new SimplifyInputView(getContext()).setScreenInfo(InputOutputLayout.this);
				addView(current);
				current.setInputKeyboard(keyboard);
			}
		}.execute(current); // pass the current input view as parameter
	}
	
	@Override
	public void undo() {
		// remove the last inputView
		this.removeViewAt(this.getChildCount()-1);
		
		// remove the margin
		this.removeViewAt(this.getChildCount()-1);
		
		// remove the last output result
		this.removeViewAt(this.getChildCount()-1);
		
		SimplifyInputView previousInput = (SimplifyInputView) this.getChildAt(this.getChildCount()-1);
		this.current = previousInput;
		
		current.setInputKeyboard(keyboard);
		current.onGainFocus();
		
		this.current = previousInput;
		this.current.setOnClickListener(null);
	}
	
	ScreenInfo screenInfo;
	
	public InputOutputLayout setScreenInfo(ScreenInfo info){
		screenInfo = info;
		return this;
	}

	@Override
	public float screenWidth() {
		return screenInfo == null ? Float.POSITIVE_INFINITY : screenInfo.screenWidth();
	}

	@Override
	public float screenHeight() {
		return screenInfo == null ? Float.POSITIVE_INFINITY : screenInfo.screenHeight();
	}

	@Override
	public void onClick(View v) {
		final SimplifyInputView inputView = (SimplifyInputView) v;
		// The reason why the keyboard executes this is because
		// the keyboard holds the undo stack, so everything that
		// should be possible to undo must be done through the 
		// keyboard
		keyboard.execute(new Action() {

			SimplifyInputView previous = current;
			
			@Override
			public void exec() {
				// This is what happens when the user touches
				// a previous expression, it gets copied down
				// so s/he can edit the copied version
				ExpressionBuilder copy = inputView.toSimplify.copy();
				copy.gainFocus();
				previous.onLoseFocus();
				InputOutputLayout.this.removeView(previous);
				
				current = new SimplifyInputView(getContext()).setScreenInfo(InputOutputLayout.this);
				current.setToSimplify(copy);
				InputOutputLayout.this.addView(current);
				current.setInputKeyboard(keyboard);
			}

			@Override
			public void undo() {
				InputOutputLayout.this.removeView(current);
				current.onLoseFocus();
				current = previous;
				current.onGainFocus();
				
				InputOutputLayout.this.addView(current);
				current.setInputKeyboard(keyboard);
			}
		});
	}
}
