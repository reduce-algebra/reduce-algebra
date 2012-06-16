package uk.ac.cam.aa582.interactivity;

import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Stack;

import uk.ac.cam.aa582.R;
import uk.ac.cam.aa582.structures.boxes.S;
import uk.ac.cam.aa582.structures.reducible.AbsoluteValue;
import uk.ac.cam.aa582.structures.reducible.Action;
import uk.ac.cam.aa582.structures.reducible.ExpressionBuilder;
import uk.ac.cam.aa582.structures.reducible.Fraction;
import uk.ac.cam.aa582.structures.reducible.Keyboard;
import uk.ac.cam.aa582.structures.reducible.Limit;
import uk.ac.cam.aa582.structures.reducible.Logarithm;
import uk.ac.cam.aa582.structures.reducible.Matrix;
import uk.ac.cam.aa582.structures.reducible.Product;
import uk.ac.cam.aa582.structures.reducible.SolveCommand;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

/**
 * Wrapper and manager around the real View keyboard
 * 
 * @author Ahmad Akra
 *
 */
public class KeyboardManager implements Keyboard {
	
	/**
	 * A lot of the buttons simply append things to
	 * the builder, and the undo in all of these cases
	 * is {@link ExpressionBuilder#deletePrevious()}.<br/>
	 * This class refactors <tt> builder.deletePrevious()</tt>
	 * in {@link AppendAction#undo()}, and I only have 
	 * to implement {@link AppendAction#exec()}
	 * 
	 * @author Ahmad Akra
	 *
	 */
	 public abstract class AppendAction implements Action {

		@Override
		public abstract void exec();

		@Override
		public void undo() {
			builder.deletePrevious();
		}

	}
	/* nothing enabled
	 * numbers_only
	 * vars_and_numbers
	 * everything_enabled except solve and matrix
	 * everything_enabled
	 */
	enum KeyboardState {
		disabled, digits_only, vars_digits_only, all_enabled
	}

	
	//--------------------------------------

	// state of the keyboard here
//	private LinkedList<Integer> disabledButtons = new LinkedList<Integer>();
	@SuppressWarnings("unused")
	private KeyboardState state = KeyboardState.all_enabled;
	private int switchableKeyboard = R.id.normal_keyboard;
//	private boolean isShiftPressed = false;
	
	
	private View keyboard;
	
	/**
	 * Contains all the actions that the user performed
	 * and all their reverse, when the user hits undo,
	 * the last action is popped from this stack and the
	 * reverse is performed. <br/>
	 * <u>Contract</u>: any adding or removing items
	 * from this stack should be accompanied by calling
	 * {@link KeyboardManager#refreshUndoStack()} to
	 * set the state of the undo button accordingly
	 */
	protected Stack<Action> undoStack = new Stack<Action>();
	
	/**
	 * Contains all the actions that the user undone, 
	 * when the user hits redo the last redone action is 
	 * popped from this stack and executed. <br/>
	 * <u>Contract</u>: any adding or removing items
	 * from this stack should be accompanied by calling
	 * {@link KeyboardManager#refreshRedoStack()} to
	 * set the state of the undo button accordingly
	 */
	protected Stack<Action> redoStack = new Stack<Action>();
	
	public KeyboardManager(View keyboard) {
		this.keyboard = keyboard;
		
		hookStandardListeners();
		refreshUndoButton();
		refreshRedoButton();
	}
	
	private void hookStandardListeners() {
		
		final Button shiftButton = (Button) keyboard.findViewById(R.id.shift_button);
		shiftButton.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) { 
				if(switchableKeyboard == R.id.shifted_keyboard)
					switchToSwitchableKeyboard(R.id.normal_keyboard);
				else 
					switchToSwitchableKeyboard(R.id.shifted_keyboard);
			}			
		});
		
		final Button shift2Button = (Button) keyboard.findViewById(R.id.shift2_button);
		shift2Button.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) { 
				if(switchableKeyboard == R.id.shifted2_keyboard)
					switchToSwitchableKeyboard(R.id.normal_keyboard);
				else 
					switchToSwitchableKeyboard(R.id.shifted2_keyboard);
			}			
		});
		
		final Button varButton = (Button) keyboard.findViewById(R.id.var_button);
		varButton.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) { 
				if(switchableKeyboard == R.id.identifiers_keyboard)
					switchToSwitchableKeyboard(R.id.normal_keyboard);
				else 
					switchToSwitchableKeyboard(R.id.identifiers_keyboard);
			}			
		});
		
		Button undo = (Button) keyboard.findViewById(R.id.undo_button);
		undo.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) {
				undo();
			}
		});
		
		Button redo = (Button) keyboard.findViewById(R.id.redo_button);
		redo.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) {
				redo();
			}
		});
	}
	
	public void refreshRedoButton() {
		if(redoButton == null) 
			redoButton = (Button) keyboard.findViewById(R.id.redo_button);
		
		if(redoStack.size() > 0)
			redoButton.setEnabled(true);
		else
			redoButton.setEnabled(false);
		
	}
	
	public void refreshUndoButton() {
		if(undoButton == null) 
			undoButton = (Button) keyboard.findViewById(R.id.undo_button);
		
		if(undoStack.size() > 0)
			undoButton.setEnabled(true);
		else
			undoButton.setEnabled(false);
		
	}

	private Button redoButton;
	private Button undoButton;

	protected void switchToSwitchableKeyboard(int keyboardId) {
		// if switching to the same keyboard
		if(keyboardId == this.switchableKeyboard) return;
		
		View oldKeyboard = keyboard.findViewById(this.switchableKeyboard); 
		oldKeyboard.setVisibility(View.INVISIBLE);
		this.switchableKeyboard = keyboardId;

		View newKeyboard = keyboard.findViewById(this.switchableKeyboard); 
		newKeyboard.setVisibility(View.VISIBLE);
	}

	public void setListener(int buttonId, final Action action) {
		Button btn = (Button) keyboard.findViewById(buttonId);
		if(btn != null) {
			btn.setOnClickListener(new OnClickListener() {

				@Override
				public void onClick(View v) {
					execute(action);
				}
			});
		}
	}
	

	public void disableAllButtons() {
		this.state = KeyboardState.disabled;
		for(Button btn : allButtons()) {
			if(btn != null)
				btn.setEnabled(false);
		}
	}
	
	public void enableVarsAndDigitsOnly() {
		this.state = KeyboardState.vars_digits_only;
		
		// disable all buttons
		for(Button btn : allButtons()) {
			if(btn != null)
				btn.setEnabled(false);
		}
		
		// enable variable buttons
		for(Button btn : identifierButtons()) {
			if(btn != null)
				btn.setEnabled(true);
		}
		
		// enable digit buttons
		for(Button btn : digitButtons()) {
			if(btn != null)
				btn.setEnabled(true);
		}
	}


	public void enableDigitsOnly() {
		this.state = KeyboardState.digits_only;
		
		// disable all buttons
		for(Button btn : allButtons()) {
			if(btn != null)
				btn.setEnabled(false);
		}
		
		// enable digit buttons
		for(Button btn : digitButtons()) {
			if(btn != null)
				btn.setEnabled(true);
		}
	}
	
	public void disableMatrixButton() {
		// TODO
	}
	
	public void enableMatrixButton() {
		// TODO
	}
	
	public void disableSolveButton() {
		// TODO
	}
	
	public void enableSolveButton() {
		// TODO
	}
	
	public void marryToBuilder(ExpressionBuilder builder) {
		// If this is the first builder to marry
		// hook all the event handlers
		if(this.builder == null) 
			hookListenersToBuilder();
		
		// else
		// update the builder reference, so buttons use the new one
		if(this.builder != null) this.builder.setKeyboardInterface(null);
		this.builder = builder;
		this.builder.setKeyboardInterface(this);
	}
	
	private ExpressionBuilder builder;
	
	protected ExpressionBuilder builder() {
		return builder;
	}
	
	private void hookListenersToBuilder() {
		
		//// The ten digits
		setListener(R.id.zero_digit_button, new AppendAction() {
			@Override
			public void exec() {
				builder().appendSymbol("0");
				
			}
		});
		
		setListener(R.id.one_digit_button, new AppendAction() {
			@Override
			public void exec() {
				builder().appendSymbol("1");
				
			}
		});
		
		setListener(R.id.two_digit_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("2");
				
			}
		});
		
		setListener(R.id.three_digit_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("3");
				
			}
		});
		setListener(R.id.four_digit_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("4");
				
			}
		});
		
		setListener(R.id.five_digit_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("5");
				
			}
		});
		
		
		setListener(R.id.six_digit_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("6");
				
			}
		});
		
		setListener(R.id.seven_digit_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("7");
				
			}
		});
		
		setListener(R.id.eight_digit_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("8");
				
			}
		});	
		
		setListener(R.id.nine_digit_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("9");
				
			}
		});
		
		//// Arithmetic Operators
		
		setListener(R.id.plus_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol(S.plus);
				
			}
		});
		
		setListener(R.id.minus_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol(S.minus);
				
			}
		});	
		
		setListener(R.id.times_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol(S.times);
				
			}
		});
		
		setListener(R.id.div_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol(S.slash);
				
			}
		});
		
		//// Decimal Point
		setListener(R.id.decimal_point_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol(".");
				
			}
		});
		
		
		//// Ans
		setListener(R.id.ans_button, new AppendAction() {

			@Override
			public void exec() {
				// Symbol is configured to translate "ans" to "ws"
				builder().appendSymbol("ans");
				
			}
		});
		
		//// Trigonometry
		setListener(R.id.sin_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("sin(");
				
			}
		});
		
		setListener(R.id.cos_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("cos(");
				
			}
		});
		
		setListener(R.id.tan_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("tan(");
				
			}
		});
		
		setListener(R.id.arcsin_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("asin(");
				
			}
		});
		
		setListener(R.id.arccos_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("acos(");
				
			}
		});
		
		setListener(R.id.arctan_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("atan(");
				
			}
		});
		
		setListener(R.id.sinh_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("sinh(");
				
			}
		});
		
		setListener(R.id.cosh_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("cosh(");
				
			}
		});
		
		setListener(R.id.tanh_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("tanh(");
				
			}
		});
		
		setListener(R.id.arcsinh_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("asinh(");
				
			}
		});
		
		setListener(R.id.arccosh_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("acosh(");
				
			}
		});
		
		setListener(R.id.arctanh_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("atanh(");
				
			}
		});
		
		//// Control
		setListener(R.id.power_button, new AppendAction() {

			@Override
			public void exec() {
				builder().raiseToPower();
				
			}
		});
		
		setListener(R.id.square_button, new Action() {

			@Override
			public void exec() {
				builder().square();
			}

			@Override
			public void undo() {
				builder.undoSquare();
			}
		});
		
		setListener(R.id.x10_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("E"); // TODO
			}
		});
		
		setListener(R.id.ln_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("ln(");			
			}			
		});
		
		setListener(R.id.log_button, new AppendAction() {

			@Override
			public void exec() {
				builder().append(new Logarithm());				
			}			
		});
		
		setListener(R.id.pi_button, new AppendAction() {
			
			@Override
			public void exec() {
				builder().appendSymbol(S.pi);
			}
		});
		
		setListener(R.id.e_button, new AppendAction() {
			
			@Override
			public void exec() {
				builder().appendSymbol("e");
			}
		});
		
		setListener(R.id.assign_button, new AppendAction() {
			
			@Override
			public void exec() {
				builder().appendSymbol(":=");
			}
		});
		
		setListener(R.id.equals_button, new AppendAction() {
			@Override
			public void exec() {
				builder().appendSymbol(S.equals);
			}
		});
		
		setListener(R.id.solve_button, new AppendAction() {
			@Override
			public void exec() {
				builder().append(new SolveCommand());
			}
		});
		
		setListener(R.id.clear_button, new AppendAction() {
			@Override
			public void exec() {
				builder().appendSymbol("clear(");
			}
		});
		
		setListener(R.id.comma_button, new AppendAction() {
			@Override
			public void exec() {
				builder().appendSymbol(",");
			}
		});
		
		setListener(R.id.fraction_button, new AppendAction() {
			@Override
			public void exec() {
				builder().append(new Fraction());
			}
		});
		
		setListener(R.id.factorial_button, new AppendAction() {
			@Override
			public void exec() {
				builder().appendSymbol("fact(");	
			}
		});
		
		setListener(R.id.i_button, new AppendAction() {
			@Override
			public void exec() {
				builder().appendSymbol("i");
			}
		});
		
		setListener(R.id.matrix3_button, new AppendAction() {
			@Override
			public void exec() {
				builder().append(new Matrix(3, 3)); // TODO: allow arbitrary
			}
		});
		
		setListener(R.id.matrix2_button, new AppendAction() {
			@Override
			public void exec() {
				builder().append(new Matrix(2, 2)); // TODO: allow arbitrary
			}
		});
		
		setListener(R.id.det_button, new AppendAction() {
			@Override
			public void exec() {
				builder().appendSymbol("det(");
			}
		});
		
		setListener(R.id.limit_button, new AppendAction() {
			@Override
			public void exec() {
				builder().append(new Limit());
			}
		});
		
		setListener(R.id.infinity_button, new AppendAction() {
			@Override
			public void exec() {
				builder().appendSymbol(S.infty);
			}
		});
		
		
		
		setListener(R.id.absolute_value_button, new AppendAction() {
			
			@Override
			public void exec() {
				builder().append(new AbsoluteValue());
			}
		});
		
		setListener(R.id.integral_with_limits_button, new AppendAction() {
			
			@Override
			public void exec() {
				builder().appendIntegralWithLimits();
			}
		});
		
		setListener(R.id.sqrt_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSqrt();
				
			}
		});
		
		setListener(R.id.sum_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSummation();
				
			}
		});
		
		setListener(R.id.prod_button, new AppendAction() {

			@Override
			public void exec() {
				builder().append(new Product());
				
			}
		});
		
		setListener(R.id.df_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendDifferential();
				
			}
		});

		setListener(R.id.int_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendIntegral();
				
			}
		});
		
		setListener(R.id.open_bracket_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol("(");
				
			}
		});
		
		setListener(R.id.close_bracket_button, new AppendAction() {

			@Override
			public void exec() {
				builder().appendSymbol(")");
				
			}
		});

		setListener(R.id.backspace_button, new Action() {
			
			Boolean wasAtLeftEnd;
			
			@Override
			public void exec() {
				wasAtLeftEnd = builder().pointerAtLeftEnd();
				builder().deletePrevious();
			}

			@Override
			public void undo() {
				builder().undoDeletePrevious(wasAtLeftEnd);
			}
		});
		
		setListener(R.id.left_button, new Action() {

			private boolean pointerMoved = false;

			@Override
			public void exec() {
				if(!builder().pointerAtLeftEnd()) {
					builder().moveCursorToTheLeft();
					pointerMoved = true;
					KeyboardManager.this.redo();
				}				
			}

			@Override
			public void undo() {
				if(pointerMoved) {
					builder().moveCursorToTheRight();
					KeyboardManager.this.undo(); // This is to ignore cursor movements when you undo
				}
			}
		});
		
		setListener(R.id.right_button, new Action() {
			
			private boolean pointerMoved = false;
			
			@Override
			public void exec() {
				if(!builder().pointerAtRightEnd()) {
					builder().moveCursorToTheRight();
					pointerMoved = true;
					KeyboardManager.this.redo();
				}				
			}

			@Override
			public void undo() {
				if(pointerMoved) {
					builder().moveCursorToTheLeft();
					KeyboardManager.this.undo();
				}
			}
		});
		
		// Identifiers (a, b, c, x, y, z, etc...)
		setListener(R.id.a_identifier_button, new AppendAction() { 

			@Override
			public void exec() {
				builder().appendSymbol(S.a);

			}
		});

		setListener(R.id.b_identifier_button, new AppendAction() { 

			@Override
			public void exec() {
				builder().appendSymbol(S.b);

			}
		});

		setListener(R.id.c_identifier_button, new AppendAction() { 

			@Override
			public void exec() {
				builder().appendSymbol(S.c);

			}
		});
		
		setListener(R.id.l_identifier_button, new AppendAction() { 

			@Override
			public void exec() {
				builder().appendSymbol(S.l);

			}
		});

		setListener(R.id.m_identifier_button, new AppendAction() { 

			@Override
			public void exec() {
				builder().appendSymbol(S.m);

			}
		});

		setListener(R.id.n_identifier_button, new AppendAction() { 

			@Override
			public void exec() {
				builder().appendSymbol(S.n);

			}
		});

		setListener(R.id.p_identifier_button, new AppendAction() { 

			@Override
			public void exec() {
				builder().appendSymbol(S.p);

			}
		});

		setListener(R.id.q_identifier_button, new AppendAction() { 

			@Override
			public void exec() {
				builder().appendSymbol(S.q);

			}
		});

		setListener(R.id.r_identifier_button, new AppendAction() { 

			@Override
			public void exec() {
				builder().appendSymbol(S.r);

			}
		});

		setListener(R.id.s_identifier_button, new AppendAction() { 

			@Override
			public void exec() {
				builder().appendSymbol(S.s);

			}
		});

		setListener(R.id.t_identifier_button, new AppendAction() { 

			@Override
			public void exec() {
				builder().appendSymbol(S.t);

			}
		});

		setListener(R.id.u_identifier_button, new AppendAction() { 

			@Override
			public void exec() {
				builder().appendSymbol(S.u);

			}
		});

		setListener(R.id.x_identifier_button, new AppendAction() { 

			@Override
			public void exec() {
				builder().appendSymbol(S.x);

			}
		});

		setListener(R.id.y_identifier_button, new AppendAction() { 

			@Override
			public void exec() {
				builder().appendSymbol(S.y);

			}
		});

		setListener(R.id.z_identifier_button, new AppendAction() { 

			@Override
			public void exec() {
				builder().appendSymbol(S.z);

			}
		});
	}


	public void enableAllButtons() {
		for(Button btn : allButtons()) {
			if(btn != null)
				btn.setEnabled(true);
		}
		refreshUndoButton();
		refreshRedoButton();
	}
	
	public Button getButton(int id) {
		return (Button) keyboard.findViewById(id);
	}

	public void setOnClickListener(int btnId, OnClickListener listener) {
		Button button = (Button) keyboard.findViewById(btnId);
		if(button != null) button.setOnClickListener(listener);
	}
	

	private Button[] identifierButtons() {
		return filterButtons("_identifier_button");
	}
	
	private Button[] digitButtons() {
		return filterButtons("_digit_button");
	}
	
	private Button[] allButtons() {
		return filterButtons("_button");
	}

	private Button[] filterButtons(String endsWith) {
		if(cache.get(endsWith) != null) return cache.get(endsWith);
		else {
			LinkedList<Field> result = new LinkedList<Field>();
			Field[] fields = R.id.class.getFields();
			for(Field f : fields) {
				if(Modifier.isStatic(f.getModifiers()) && f.getName().endsWith(endsWith))
					result.addFirst(f);
			}
			Button[] buttonIds = new Button[result.size()];
			int i = 0;
			for(Field f : result) {
				try {
					int id = f.getInt(null);
					buttonIds[i] = (Button) keyboard.findViewById(id); 
					i++;
				} catch (IllegalArgumentException e) {
				} catch (IllegalAccessException e) {
				}
			}
			cache.put(endsWith, buttonIds);
			return buttonIds;
		}
	}
	private HashMap<String, Button[]> cache = new HashMap<String, Button[]>();
	
	
// The following three methods handle everything related to undo
	
	public void execute(Action action) {
		// This is done upon every action from the user
		// that can be reversed with undo
		redoStack.removeAllElements();
		undoStack.push(action);
		action.exec();
		refreshRedoButton();
		refreshUndoButton();
		switchToSwitchableKeyboard(R.id.normal_keyboard);
	}

	public void undo() {
		// This is how undo works
		if(undoStack.empty()) return;
		Action action = undoStack.pop();
		redoStack.push(action);
		action.undo();
		refreshUndoButton();
		refreshRedoButton();
	}

	public void redo() {
		if(redoStack.empty()) return;
		Action action = redoStack.pop();
		undoStack.push(action);
		action.exec();
		refreshRedoButton();
		refreshUndoButton();
	}

	public void flushUndoStack() {
		this.undoStack.removeAllElements();
		
	}
}
