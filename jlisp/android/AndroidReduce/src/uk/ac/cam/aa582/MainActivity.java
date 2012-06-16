package uk.ac.cam.aa582;

import java.util.Random;

import uk.ac.cam.aa582.interactivity.AndroidGraphics;
import uk.ac.cam.aa582.interactivity.InputOutputLayout;
import uk.ac.cam.aa582.interactivity.KeyboardManager;
import uk.ac.cam.aa582.interactivity.OutputView;
import uk.ac.cam.aa582.interactivity.ScreenInfo;
import uk.ac.cam.aa582.reduce.Reduce;
import uk.ac.cam.aa582.structures.boxes.Box;
import uk.ac.cam.aa582.structures.boxes.BoxUtil;
import uk.ac.cam.aa582.structures.boxes.DelimiterBox;
import uk.ac.cam.aa582.structures.boxes.DelimiterBox.DelimiterType;
import uk.ac.cam.aa582.structures.boxes.DelimiterBox.Delimiters;
import uk.ac.cam.aa582.structures.boxes.FractionBox;
import uk.ac.cam.aa582.structures.boxes.IntegralBox;
import uk.ac.cam.aa582.structures.boxes.LargeOperatorBox;
import uk.ac.cam.aa582.structures.boxes.LargeOperatorSymbolBox;
import uk.ac.cam.aa582.structures.boxes.LargeOperatorSymbolBox.LargeOp;
import uk.ac.cam.aa582.structures.boxes.MultilineBox.Alignment;
import uk.ac.cam.aa582.structures.boxes.MultilineBox;
import uk.ac.cam.aa582.structures.boxes.OperationBox;
import uk.ac.cam.aa582.structures.boxes.RelationBox;
import uk.ac.cam.aa582.structures.boxes.S;
import uk.ac.cam.aa582.structures.boxes.ScriptBox;
import uk.ac.cam.aa582.structures.boxes.TexStyle;
import uk.ac.cam.aa582.structures.boxes.ScriptBox.ScriptMode;
import uk.ac.cam.aa582.structures.boxes.SequenceBox;
import uk.ac.cam.aa582.structures.boxes.SpaceBox;
import uk.ac.cam.aa582.structures.boxes.SpaceBox.Space;
import uk.ac.cam.aa582.structures.boxes.SqrtBox;
import uk.ac.cam.aa582.structures.boxes.SymbolBox;
import uk.ac.cam.aa582.structures.boxes.TableBox;
import uk.ac.cam.aa582.structures.boxes.Timer;
import uk.ac.cam.aa582.structures.tex.TexParser;
import android.app.Activity;
import android.app.Dialog;
import android.content.Intent;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;

@SuppressWarnings("unused")
public class MainActivity extends Activity implements ScreenInfo {
	
	InputOutputLayout io;
	
	
	//@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		// shows the actual application
		   onCreateKeyboard();
		
		
		// shows a basic range of formulae
		// onCreateMath();
		
		// shows textual input and output
		// onCreateMain();
		
		// shows latex input and output 
		 //  onCreateLatex(); (Does not work!)
		
		// show evaluation screen 
		// onCreateEvaluation(); (Does not work!)
		
	}


	private void onCreateEvaluation() {
		setContentView(R.layout.evaluation);
		
		
		layout = (LinearLayout) findViewById(R.id.math_main_layout);
		layout.setBackgroundColor(Color.WHITE);
		
		//------ Expressions (and their LATEX equivalent) ---------
		
		// Add more here...
//		add(new MultilineBox((
//						sqrt(sequence(fraction(sym(S.x), sym(S.y)) ,sym(S.b)))
//						).setGraphics(new AndroidGraphics(layout.getContext())).split(Level.medium)));


		

		Box box = new SymbolBox("22");
		Random rand = new Random();
		int levelCount = 100;
		
		for(int i=0; i<levelCount; i++) {
			int r = rand.nextInt(5);
			switch(r) {
			case 0 : box = sqrt(box); break;
			case 1 : box = brackets(box); break;
			case 2 : box = sequence(box); break;
			case 3 : box = fraction(box,sym("2")); break;
			case 4 : box = superscript(box,sym("2")); break;
			}
		}
		add(box);
		
//		Box.optimize = true;
//		Timer.start();
//		add(script(sym(S.x),sym("2"),null));
//		Timer.finish();
//		Log.d("timer setting up", Timer.time()+"ms");
//		System.out.println(Timer.time());
		
//		measure("22", sym("22"));
//		measure("y^2+sqrt(x)", sequence(script(sym(S.y),sym("2"),null),sqrt(sym(S.x))));
//		measure("log(tan(x)^2 + 1)/2", fraction(sequence(sym("log"),brackets(op(script(sequence(sym("tan"), brackets(sym(S.x))),sym("2"),null),S.plus, sym("1")))),sym("2")));
//		measure("z = log(tan(x)^2 + 1)/2 - y^2+sqrt(x)", relation(sym(S.z), S.equals, op(fraction(sequence(sym("log"),brackets(op(script(sequence(sym("tan"), brackets(sym(S.x))),sym("2"),null),S.plus, sym("1")))),sym("2")),S.minus,sequence(script(sym(S.y),sym("2"),null),sqrt(sym(S.x))))));
//		measure("{u = log(tan(x)^2 + 1)/2, v = y^2+sqrt(x)}", 
//				new DelimiterBox(sequence(
//						relation(sym(S.u),S.equals,fraction(sequence(sym("log"),brackets(op(script(sequence(sym("tan"), brackets(sym(S.x))),sym("2"),null),S.plus, sym("1")))),sym("2"))),				
//						sym(","),
//						new SpaceBox(Space.comma),
//						relation(sym(S.u),S.equals,sequence(script(sym(S.y),sym("2"),null),sqrt(sym(S.x))))									
//				),Delimiters.curly));	
	}


	private void measure(String l, Box box) {
		long time = 0;
		int reps = 5;
		
		Box.optimize = true;
		time=0;
		for(int i=0; i<reps; i++) {
			Timer.start();
			add(box);
			Timer.finish();		
			time = time + Timer.time();

			Log.d("time " + l + " unoptimized trial", Timer.time()+"ms");
		}
		
		time = time / reps;

		Log.d("time " + l + " unoptimized average", time+"ms");
		
		
		
		Box.optimize = true;
		time=0;
		for(int i=0; i<reps; i++) {
			Timer.start();
			add(relation(sym(S.x), S.equals, op(fraction(sequence(sym("log"),brackets(op(script(sequence(sym("tan"), brackets(sym(S.x))),sym("2"),null),S.plus, sym("1")))),sym("2")),S.minus,sequence(script(sym(S.y),sym("2"),null),sqrt(sym(S.x))))));			Timer.finish();		
			time = time + Timer.time();

			Log.d("time " + l + " optimized trial", Timer.time()+"ms");
		}
		
		time = time / reps;
		Log.d("time " + l + " optimized average", time+"ms");
	}


	private void onCreateKeyboard() {
		setContentView(R.layout.keyboard);
		
		this.showSplashScreen();
		
		
		io = (InputOutputLayout) findViewById(R.id.ioLayout);
		io.setScreenInfo(this);
		View keyboard = findViewById(R.id.keyboard);
		
		io.setInputKeyboard(new KeyboardManager(keyboard));
		
		
		new AsyncTask<Void,Void,Void>() {
			
			long start = 0l;
			
			@Override // this method runs asynchronously
			protected Void doInBackground(Void... arg0) {
				
				start = System.currentTimeMillis();
				Reduce reduce = new Reduce(MainActivity.this);
				reduce.start();
				
				return null;
			}
		
			@Override // this is executed on the UI thread after the async method returns
			protected void onPostExecute(Void v){
				
				removeSplashScreen();
				
				long millis = System.currentTimeMillis() - start;
				Log.d("Splash Screen Duration", millis+"");
			}

		}.execute();
	}
	

	@Override
	public float screenWidth() {
		return this.getWindowManager().getDefaultDisplay().getWidth();
	}

	@Override
	public float screenHeight() { 
		return this.getWindowManager().getDefaultDisplay().getHeight();
	}
	
	@Override
	public void onSaveInstanceState(Bundle outState) {
		//outState.put
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// get an xml inflater
		MenuInflater inflater = getMenuInflater();
		
		// inflate a menu and use it
		inflater.inflate(R.menu.menu, menu);
		return true;
				
	}
	
	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// There are two menu buttons, "Settings" and "About"
		
		switch(item.getItemId()) {
		// if the "settings" button is pressed
//		case R.id.settingsMenuItem:
//			// bring up the settings screen
//			Intent intent = new Intent(this, MainPreferenceActivity.class);
//			startActivity(intent);
//			break;
		// if the "about" button is pressed
		case R.id.aboutMenuItem:
			// bring up the about screen
			Intent intent2 = new Intent(this, AboutActivity.class);
			startActivity(intent2);
			break;
		}
		
		return true;
	}
	
	
	
	/**
	 * Simple Dialog used to show the splash screen
	 */
	protected Dialog mSplashDialog;
	 
	//@Override
	public void onCreate2(Bundle savedInstanceState) {
	    super.onCreate(savedInstanceState);
	 
	    MyStateSaver data = (MyStateSaver) getLastNonConfigurationInstance();
	    if (data != null) {
	        // Show splash screen if still loading
	        if (data.showSplashScreen) {
	            showSplashScreen();
	        }
	        setContentView(R.layout.keyboard);        
	 
	        // Rebuild your UI with your saved state here
	    } else {
	        showSplashScreen();
	        setContentView(R.layout.keyboard);
	        // Do your heavy loading here on a background thread
	    }
	}
	 
	@Override
	public Object onRetainNonConfigurationInstance() {
	    MyStateSaver data = new MyStateSaver();
	    // Save your important data here
	 
	    if (mSplashDialog != null) {
	        data.showSplashScreen = true;
	        removeSplashScreen();
	    }
	    return data;
	}
	 
	/**
	 * Removes the Dialog that displays the splash screen
	 */
	protected void removeSplashScreen() {
	    if (mSplashDialog != null) {
	        mSplashDialog.dismiss();
	        mSplashDialog = null;
	    }
	}
	 
	/**
	 * Shows the splash screen over the full Activity
	 */
	protected void showSplashScreen() {
	    mSplashDialog = new Dialog(this, android.R.style.Theme_Black_NoTitleBar_Fullscreen);
	    mSplashDialog.setContentView(R.layout.splash);
	    mSplashDialog.setCancelable(false);
	    mSplashDialog.show();
	 
	    // Set Runnable to remove splash screen just in case
	    final Handler handler = new Handler();
	    handler.postDelayed(new Runnable() {
	      @Override
	      public void run() {
	        removeSplashScreen();
	      }
	    }, 3000);
	}
	 
	/**
	 * Simple class for storing important data across config changes
	 */
	private class MyStateSaver {
	    public boolean showSplashScreen = false;
	    // Your other important fields here
	}
	
	
	///////////////////////////////////////// Textual input and output /////////////////////////////////////////
	
	private void onCreateMain() {
		
		// boilerplate code
		setContentView(R.layout.main);
		
		// text field where user provides input
		final EditText inputField = (EditText) this.findViewById(R.id.inputEditText);
		
		// text field where output is displayed
		final TextView outputField = (TextView) this.findViewById(R.id.outputTextView);
	
		try {
			
			final Reduce reduce = new Reduce(this);
			
			// attach this handler to the Enter button
			Button enterButton = (Button)this.findViewById(R.id.originalEnterButton);			
			enterButton.setOnClickListener(new OnClickListener(){
				@Override
				public void onClick(View v) {
					try
					{
						// input goes to Dr. Norman's library
						String inputString = inputField.getText().toString();						
						String originalContent = outputField.getText().toString(); // remember the contents of the outputField
						outputField.append("\nCalculating..."); // display something to pacify to the user
						
						new AsyncTask<String,Void,String[]>() {
							
							String originalContent;
							long startTime;
	
							@Override
							protected String[] doInBackground(String... params) {
								try{
									startTime = System.currentTimeMillis();
									originalContent = params[1];
									String inputString = params[0];
									
									String[] output = reduce.reduce(inputString);
									
									return output;
									
								} catch(Exception ex) {
									return null;
								}
							}
						
							@Override // this is executed on the UI thread after the async method returns
							protected void onPostExecute(String[] lines){
								// output displayed on the screen
								outputField.setText(originalContent); // remove the user pacifier
								
								long elapsedTime = System.currentTimeMillis() - startTime;
								for(String line : lines) {
									outputField.append(String.format("\n%s", line, elapsedTime)); // print the TeX line on the screen
								}
								outputField.append(String.format("(%sms)", elapsedTime)); // print the TeX line on the screen
							}
						}.execute(inputString, originalContent);
						
					}
					catch(Exception ex)
					{
						outputField.setText(ex.getMessage());
					}
				}
			});
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}
	
	
	//////////////////////////////////////// LaTeX input ///////////////////////////////////////////////////////
	
	private void onCreateLatex() {
		
		// boilerplate code
		setContentView(R.layout.main);
		
		// text field where user provides input
		final EditText inputField = (EditText) this.findViewById(R.id.inputEditText);
		
		// text field where output is displayed
		final TextView outputField = (TextView) this.findViewById(R.id.outputTextView);
	
		try {
			
			
			// attach this handler to the Enter button
			Button enterButton = (Button)this.findViewById(R.id.originalEnterButton);			
			enterButton.setOnClickListener(new OnClickListener(){
				@Override
				public void onClick(View v) {
					try
					{
						// input goes to Dr. Norman's library
						//String inputString = inputField.getText().toString();
						//String inputString = "\\begin{matrix} 1 & 2 & 3 \\\\ 4 & 5 & 6 \\\\ 7 & 8 & 9 \\end{matrix}";
						String inputString = "\\sqrt[3]{x}";
						TexParser parser = new TexParser(inputString);
						
						Box box = parser.parse();
						
						System.out.println(box.toString());
						Log.d("LaTeX", box.toString());
					}
					catch(Exception ex)
					{
						Log.d("LaTeX", "Error " + ex.getMessage());
					}
				}
			});
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}
	
	//////////////////////////////////////// Simple Math Display ///////////////////////////////////////////////

	LinearLayout layout;

	private void onCreateMath() {
		setContentView(R.layout.math);
		
		layout = (LinearLayout) findViewById(R.id.math_main_layout);
		layout.setBackgroundColor(Color.WHITE);
		
		//------ Expressions (and their LATEX equivalent) ---------
		
		// Add more here...
//		add(new MultilineBox((
//						sqrt(sequence(fraction(sym(S.x), sym(S.y)) ,sym(S.b)))
//						).setGraphics(new AndroidGraphics(layout.getContext())).split(Level.medium)));
//
//		// 1/2
//		add(fraction(sym("1"),sym("2")));
//		
//		// 1/2
//		add(fraction(sym("1"),sym("2")));
//		
//		
//		Box ul = sequence(sym(S.c),brackets(sequence(sym("1,"),new SpaceBox(Space.comma), sym(S.j))));
//		Box ur = sequence(sym("if"), new SpaceBox(Space.space), relation(sequence(sym(S.c),brackets(sequence(sym("1,"),new SpaceBox(Space.comma), sym(S.j)))),S.lessthen,sym(S.infty)));
//		Box dl = sequence(
//				new ScriptBox(sym("min"),null, sequence(sym("1"), sym(S.leq), sym(S.k), sym(S.lessthen), sym(S.j))),
//				brackets(op(sequence(sym(S.f),brackets(sym(S.k))),S.plus, sequence(sym(S.c),brackets(sequence(relation(sym(S.k), S.plus, sym("1")),sym(","),new SpaceBox(Space.comma), sym(S.j))))))
//				);
//		Box dr = sequence(sym("if"), new SpaceBox(Space.space), relation(sequence(sym(S.c),brackets(sequence(sym("1,"),new SpaceBox(Space.comma), sym(S.j)))),S.equals,sym(S.infty)));
//		
//		Box ll = sequence(sym(S.f), brackets(sym(S.j)));
//		
//		Box inside = sequence(
//				new MultilineBox(-1, -1, -1, Alignment.left, ul, dl),
//				new SpaceBox(Space.space), 
//				new MultilineBox(-1, -1, -1, Alignment.right, ur, dr));
//		
//		Box whole = relation(ll, S.equals, new DelimiterBox(inside, Delimiters.curly,DelimiterType.left));
//
//		add(whole);
//		
//		// matrix
//		add(brackets(new TableBox(6, 1, sym("1"),sym("2"),sym("3"),sym("4"),sym("5"),sym("6"))));
//		add(brackets(new TableBox(2, 3, sym("1"),sym("2"),sym("3"),sym("4"),sym("5"),op(sym(S.x),S.plus,sym(S.y)))));
//		add(brackets(new TableBox(3, 3, sym("1"),sym("2"),sym("3"),sym("4"),sym("5"),sym("6"),sym("7"),sym("8"),sym("9"))));
//		
//		add(new ScriptBox(sym(S.x), sym(S.y), sym(S.z), ScriptMode.overunder));
//		
//		
//		// Lorentz factor
//		add(relation(sym(S.gamma), S.equals, fraction(sym("1"), sqrt(op(sym("1"), S.minus, superscript(brackets(fraction(sym(S.v),sym(S.c))),sym("2")))))));
//		
//		// SHM potential energy
//		add(relation(sym(S.U), S.equals, sequence(fraction(sequence(sym(S.m), superscript(brackets(sequence(sym(S.omega),sym(S.A))),sym("2"))),sym("2")),superscript(sym("cos"), sym("2")), brackets(op(sequence(sym(S.omega), sym(S.t)), S.plus, sym(S.phi))))));
//		
//		//add(brackets(superscript(sqrt(sym(S.x)), superscript(sqrt(sym(S.x)),superscript(sqrt(sym(S.x)),sqrt(sym(S.x)))))));
//		
//		// Normal distribution formula
//		add(relation(sequence(sym(S.f),brackets(sym(S.x))), S.equals, sequence(fraction(sym("1"),sqrt(sequence(sym("2"),sym(S.pi), superscript(sym(S.sigma),sym("2"))))), superscript(sym(S.e),sequence(sym(S.minus),fraction(superscript(brackets(op(sym(S.x),S.minus,sym(S.mu))),sym("2")),sequence(sym("2"), superscript(sym(S.sigma), sym("2")))))))));
//
//		// x = \int_a^b v.\mathrm d t
//		add(relation(sym(S.x),S.equals, integral(sym(S.v), sym(S.t), sym(S.a), sym(S.b))));
//		
//
//		// x = \int v.\mathrm d t
//		add(relation(sym(S.x),S.equals, integral(sym(S.v), sym(S.t))));
//		
//		// {{a \over b} \over {c \over d}} + {x \over y} 
//		add(op(fraction(fraction(sym(S.a),sym(S.b)),fraction(sym(S.c),sym(S.d))), S.plus, fraction(sym(S.x),sym(S.y))));
//		
//		// x = \sqrt {x^2}
//		add(relation(sym(S.x),S.equals,sqrt(superscript(sym(S.x),sym("2")))));
//		
//		// E = mc^2
//		add(relation(sym(S.E), S.equals, sequence(sym(S.m),superscript(sym(S.c),sym("2")))));
//		
//		// \sin^2(x) + \cos^2(x) = 1
//		add(relation(sequence(op(sequence(superscript(sym("sin"),sym("2")),brackets(sym(S.x))), S.plus, sequence(superscript(sym("cos"),sym("2")), brackets(sym(S.x))))), S.equals, sym("1")));
//		
//		// \tan(x) = {\sin(x) \over \cos(x)}
//		add(relation(sequence(sym("tan"),brackets(sym(S.theta))),S.equals,fraction(sequence(sym("sin"),brackets(sym(S.theta))),sequence(sym("cos"),brackets(sym(S.theta))))));
//		
//		// x = {{-b \pm \sqrt {b^2 - 4ac}} \over {2a}}
//		add(relation(sym(S.x),S.equals,fraction(op(sequence(sym(S.minus),sym(S.b)),S.pm,sqrt(op(superscript(sym(S.b), sym("2")), S.minus,sequence(sym("4"),sym(S.a),sym(S.c))))),sequence(sym("2"),sym(S.a)))));
//		
//		// \left ( x \over \sqrt y \right )
//		add(brackets(fraction(sym(S.x), sqrt(sym(S.y)))));
//		
//		// schrodinger's equation
//		add(relation(sequence(superscript(brackets(op(sym(S.E), S.plus, fraction(superscript(sym(S.e),sym("2")), sym(S.r)))),sym("2")), sym(S.psi),brackets(sym(S.x)))
//						, S.equals
//						, op(sequence(sym(S.minus), superscript(sym(S.curl),sym("2")), sym(S.psi),brackets(sym(S.x))), S.plus, sequence(superscript(sym(S.m),sym("2")), sym(S.psi),brackets(sym(S.x))))
//						));
//
//		// angular frequency of a pendulum 2
//		add(relation(sym(S.omega), S.equals,sequence(sqrt(fraction(sym(S.L),sym(S.g))),brackets(Delimiters.square, op(sym("1"), S.plus, sequence(
//				
//				largeOp(LargeOp.sum, relation(sym(S.k), S.equals, sym("1")), sym(S.infty)), space(Space.asterisk)
//				
//				, fraction(
//				sequence(largeOp(LargeOp.prod,sym(S.k),relation(sym(S.n),S.equals, sym("1"))), brackets(op(sequence(sym("2"),sym(S.n)), S.minus, sym("1")))),
//				sequence(largeOp(LargeOp.prod,sym(S.m),relation(sym(S.n),S.equals, sym("1"))), brackets(sequence(sym("2"),sym(S.n))))
//				),superscript(sym("sin"),sequence(sym("2"),sym(S.n))), sym(S.Theta)))))));

		
		// Schrodinger's equation
		add(625, relation(sequence(superscript(brackets(op(sym(S.E), S.plus, fraction(superscript(sym(S.e),sym("2")), sym(S.r)))),sym("2")), sym(S.psi),brackets(sym(S.x))), S.equals, op(sequence(sym(S.minus), superscript(sym(S.curl),sym("2")), sym(S.psi),brackets(sym(S.x))), S.plus, sequence(superscript(sym(S.m),sym("2")), sym(S.psi),brackets(sym(S.x))))));
		add(575, relation(sequence(superscript(brackets(op(sym(S.E), S.plus, fraction(superscript(sym(S.e),sym("2")), sym(S.r)))),sym("2")), sym(S.psi),brackets(sym(S.x))), S.equals, op(sequence(sym(S.minus), superscript(sym(S.curl),sym("2")), sym(S.psi),brackets(sym(S.x))), S.plus, sequence(superscript(sym(S.m),sym("2")), sym(S.psi),brackets(sym(S.x))))));
		add(525, relation(sequence(superscript(brackets(op(sym(S.E), S.plus, fraction(superscript(sym(S.e),sym("2")), sym(S.r)))),sym("2")), sym(S.psi),brackets(sym(S.x))), S.equals, op(sequence(sym(S.minus), superscript(sym(S.curl),sym("2")), sym(S.psi),brackets(sym(S.x))), S.plus, sequence(superscript(sym(S.m),sym("2")), sym(S.psi),brackets(sym(S.x))))));
		add(475, relation(sequence(superscript(brackets(op(sym(S.E), S.plus, fraction(superscript(sym(S.e),sym("2")), sym(S.r)))),sym("2")), sym(S.psi),brackets(sym(S.x))), S.equals, op(sequence(sym(S.minus), superscript(sym(S.curl),sym("2")), sym(S.psi),brackets(sym(S.x))), S.plus, sequence(superscript(sym(S.m),sym("2")), sym(S.psi),brackets(sym(S.x))))));
		add(425, relation(sequence(superscript(brackets(op(sym(S.E), S.plus, fraction(superscript(sym(S.e),sym("2")), sym(S.r)))),sym("2")), sym(S.psi),brackets(sym(S.x))), S.equals, op(sequence(sym(S.minus), superscript(sym(S.curl),sym("2")), sym(S.psi),brackets(sym(S.x))), S.plus, sequence(superscript(sym(S.m),sym("2")), sym(S.psi),brackets(sym(S.x))))));
		add(375, relation(sequence(superscript(brackets(op(sym(S.E), S.plus, fraction(superscript(sym(S.e),sym("2")), sym(S.r)))),sym("2")), sym(S.psi),brackets(sym(S.x))), S.equals, op(sequence(sym(S.minus), superscript(sym(S.curl),sym("2")), sym(S.psi),brackets(sym(S.x))), S.plus, sequence(superscript(sym(S.m),sym("2")), sym(S.psi),brackets(sym(S.x))))));
		add(325, relation(sequence(superscript(brackets(op(sym(S.E), S.plus, fraction(superscript(sym(S.e),sym("2")), sym(S.r)))),sym("2")), sym(S.psi),brackets(sym(S.x))), S.equals, op(sequence(sym(S.minus), superscript(sym(S.curl),sym("2")), sym(S.psi),brackets(sym(S.x))), S.plus, sequence(superscript(sym(S.m),sym("2")), sym(S.psi),brackets(sym(S.x))))));
		add(275, relation(sequence(superscript(brackets(op(sym(S.E), S.plus, fraction(superscript(sym(S.e),sym("2")), sym(S.r)))),sym("2")), sym(S.psi),brackets(sym(S.x))), S.equals, op(sequence(sym(S.minus), superscript(sym(S.curl),sym("2")), sym(S.psi),brackets(sym(S.x))), S.plus, sequence(superscript(sym(S.m),sym("2")), sym(S.psi),brackets(sym(S.x))))));
		add(225, relation(sequence(superscript(brackets(op(sym(S.E), S.plus, fraction(superscript(sym(S.e),sym("2")), sym(S.r)))),sym("2")), sym(S.psi),brackets(sym(S.x))), S.equals, op(sequence(sym(S.minus), superscript(sym(S.curl),sym("2")), sym(S.psi),brackets(sym(S.x))), S.plus, sequence(superscript(sym(S.m),sym("2")), sym(S.psi),brackets(sym(S.x))))));
		add(175, relation(sequence(superscript(brackets(op(sym(S.E), S.plus, fraction(superscript(sym(S.e),sym("2")), sym(S.r)))),sym("2")), sym(S.psi),brackets(sym(S.x))), S.equals, op(sequence(sym(S.minus), superscript(sym(S.curl),sym("2")), sym(S.psi),brackets(sym(S.x))), S.plus, sequence(superscript(sym(S.m),sym("2")), sym(S.psi),brackets(sym(S.x))))));
		add(125, relation(sequence(superscript(brackets(op(sym(S.E), S.plus, fraction(superscript(sym(S.e),sym("2")), sym(S.r)))),sym("2")), sym(S.psi),brackets(sym(S.x))), S.equals, op(sequence(sym(S.minus), superscript(sym(S.curl),sym("2")), sym(S.psi),brackets(sym(S.x))), S.plus, sequence(superscript(sym(S.m),sym("2")), sym(S.psi),brackets(sym(S.x))))));
		add(75, relation(sequence(superscript(brackets(op(sym(S.E), S.plus, fraction(superscript(sym(S.e),sym("2")), sym(S.r)))),sym("2")), sym(S.psi),brackets(sym(S.x))), S.equals, op(sequence(sym(S.minus), superscript(sym(S.curl),sym("2")), sym(S.psi),brackets(sym(S.x))), S.plus, sequence(superscript(sym(S.m),sym("2")), sym(S.psi),brackets(sym(S.x))))));
		add(25, relation(sequence(superscript(brackets(op(sym(S.E), S.plus, fraction(superscript(sym(S.e),sym("2")), sym(S.r)))),sym("2")), sym(S.psi),brackets(sym(S.x))), S.equals, op(sequence(sym(S.minus), superscript(sym(S.curl),sym("2")), sym(S.psi),brackets(sym(S.x))), S.plus, sequence(superscript(sym(S.m),sym("2")), sym(S.psi),brackets(sym(S.x))))));

//		// some long formula
//		for(int i=450; i>24; i=i-25)
//			add(i, relation(op(sym(S.a),S.plus,op(sym(S.b),S.plus,op(sym(S.c),S.minus,sym(S.d)))),S.equals,op(sym(S.e),S.plus,op(sym(S.f),S.minus,op(sym(S.g),S.plus,sym(S.h))))));

//	
//		// angular frequency of a pendulum
//		add(600,relation(sym(S.omega), S.equals,sequence(sqrt(fraction(sym(S.L),sym(S.g))),brackets(Delimiters.square, op(sym("1"), S.plus, sequence(largeOp(LargeOp.sum), fraction(sequence(script(largeOp(LargeOp.prod),sym(S.k),relation(sym(S.n),S.equals, sym("1"))), brackets(op(sequence(sym("2"),sym(S.n)), S.minus, sym("1")))),sequence(script(largeOp(LargeOp.prod),sym(S.m),relation(sym(S.n),S.equals, sym("1"))), brackets(sequence(sym("2"),sym(S.n))))),superscript(sym("sin"),sequence(sym("2"),sym(S.n))), sym(S.Theta)))))));
//		add(550,relation(sym(S.omega), S.equals,sequence(sqrt(fraction(sym(S.L),sym(S.g))),brackets(Delimiters.square, op(sym("1"), S.plus, sequence(largeOp(LargeOp.sum), fraction(sequence(script(largeOp(LargeOp.prod),sym(S.k),relation(sym(S.n),S.equals, sym("1"))), brackets(op(sequence(sym("2"),sym(S.n)), S.minus, sym("1")))),sequence(script(largeOp(LargeOp.prod),sym(S.m),relation(sym(S.n),S.equals, sym("1"))), brackets(sequence(sym("2"),sym(S.n))))),superscript(sym("sin"),sequence(sym("2"),sym(S.n))), sym(S.Theta)))))));
//		add(500,relation(sym(S.omega), S.equals,sequence(sqrt(fraction(sym(S.L),sym(S.g))),brackets(Delimiters.square, op(sym("1"), S.plus, sequence(largeOp(LargeOp.sum), fraction(sequence(script(largeOp(LargeOp.prod),sym(S.k),relation(sym(S.n),S.equals, sym("1"))), brackets(op(sequence(sym("2"),sym(S.n)), S.minus, sym("1")))),sequence(script(largeOp(LargeOp.prod),sym(S.m),relation(sym(S.n),S.equals, sym("1"))), brackets(sequence(sym("2"),sym(S.n))))),superscript(sym("sin"),sequence(sym("2"),sym(S.n))), sym(S.Theta)))))));
//		add(450,relation(sym(S.omega), S.equals,sequence(sqrt(fraction(sym(S.L),sym(S.g))),brackets(Delimiters.square, op(sym("1"), S.plus, sequence(largeOp(LargeOp.sum), fraction(sequence(script(largeOp(LargeOp.prod),sym(S.k),relation(sym(S.n),S.equals, sym("1"))), brackets(op(sequence(sym("2"),sym(S.n)), S.minus, sym("1")))),sequence(script(largeOp(LargeOp.prod),sym(S.m),relation(sym(S.n),S.equals, sym("1"))), brackets(sequence(sym("2"),sym(S.n))))),superscript(sym("sin"),sequence(sym("2"),sym(S.n))), sym(S.Theta)))))));

//		add(new MultilineBox(-1f,50f,-1f,Alignment.centre,
//				relation(sequence(superscript(brackets(op(sym(S.E), S.plus, fraction(superscript(sym(S.e),sym("2")), sym(S.r)))),sym("2")), sym(S.psi),brackets(sym(S.x)))
//						, S.equals
//						, op(sequence(sym(S.minus), superscript(sym(S.curl),sym("2")), sym(S.psi),brackets(sym(S.x))), S.plus, sequence(superscript(sym(S.m),sym("2")), sym(S.psi),brackets(sym(S.x))))
//						).setGraphics(new AndroidGraphics(layout.getContext())).split(Level.easy)));
//		
//		add(new MultilineBox(-1f,50f,-1f,Alignment.centre,
//				relation(sequence(superscript(brackets(op(sym(S.E), S.plus, fraction(superscript(sym(S.e),sym("2")), sym(S.r)))),sym("2")), sym(S.psi),brackets(sym(S.x)))
//						, S.equals
//						, op(sequence(sym(S.minus), superscript(sym(S.curl),sym("2")), sym(S.psi),brackets(sym(S.x))), S.plus, sequence(superscript(sym(S.m),sym("2")), sym(S.psi),brackets(sym(S.x))))
//						).setGraphics(new AndroidGraphics(layout.getContext())).split(Level.medium)));
//		
//		add(new MultilineBox(-1f,50f,-1f,Alignment.centre,
//				relation(sequence(superscript(brackets(op(sym(S.E), S.plus, fraction(superscript(sym(S.e),sym("2")), sym(S.r)))),sym("2")), sym(S.psi),brackets(sym(S.x)))
//						, S.equals
//						, op(sequence(sym(S.minus), superscript(sym(S.curl),sym("2")), sym(S.psi),brackets(sym(S.x))), S.plus, sequence(superscript(sym(S.m),sym("2")), sym(S.psi),brackets(sym(S.x))))
//						).setGraphics(new AndroidGraphics(layout.getContext())).split(Level.hard)));
//		
//		for(int i=575; i>24; i=i-25)
//			add(i,relation(sequence(superscript(brackets(op(sym(S.E), S.plus, fraction(superscript(sym(S.e),sym("2")), sym(S.r)))),sym("2")), sym(S.psi),brackets(sym(S.x)))
//						, S.equals
//						, op(sequence(sym(S.minus), superscript(sym(S.curl),sym("2")), sym(S.psi),brackets(sym(S.x))), S.plus, sequence(superscript(sym(S.m),sym("2")), sym(S.psi),brackets(sym(S.x))))
//						).setGraphics(new AndroidGraphics(layout.getContext())));
	}

	private Box space(Space s) {
		return new SpaceBox(s);
	}

	private void add(Box box) {
//		box.setFontSize(72);
		
//		AndroidGraphics g = new AndroidGraphics(layout.getContext());
//		box.setGraphics(g);
//		
//		float screenWidth = this.getWindowManager().getDefaultDisplay().getWidth();
//		box = BoxUtil.fitWithin(box, screenWidth); // fit within screen width
//		
//		g = new AndroidGraphics(layout.getContext());
//		box.setGraphics(g);
//				
//		LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(
//				(int)(box.width() + 1), 
//				(int)(box.height()));
//		params.leftMargin = (int)(screenWidth - box.width())/2;
//		params.topMargin = (int)(100);
	//	g.setBackgroundColor(0x33AAAAAA);

	//	View oldG = layout.getChildAt(index+1);
	//	g.setLayoutParams(params);
	//	layout.addView(g, index+1);
	//	layout.removeView(oldG);

		OutputView outputView = new OutputView(layout.getContext(), box, this);
		layout.addView(outputView);
		layout.addView(new View(layout.getContext()) { // this is only a margin
			@Override
			public void onMeasure(int w, int h) {
				setMeasuredDimension(0,50);
			}
		});
	}
	
	private void add(float maxWidth, Box box) {
		//box.setFontSize(fs);
		
		AndroidGraphics g = new AndroidGraphics(layout.getContext());
		box.setGraphics(g);
		
		final float originalWidth = box.width();

		Box.universalStyle = TexStyle.D;
		box = BoxUtil.fitWithin(box, maxWidth);
		Box.universalStyle = TexStyle.T;
		box.setGraphics(new AndroidGraphics(layout.getContext()));
		
		LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(
				(int)(box.width() + 1), 
				(int)(box.height()));
		params.leftMargin = (int)(this.getWindowManager().getDefaultDisplay().getWidth() - box.width())/2;
		params.topMargin = (int)(30);
		g.setBackgroundColor(0x33FFFF66);
		layout.addView((View) box.getGraphics(), params);

		
		final float max = maxWidth;
		
		LinearLayout.LayoutParams params2 = new LinearLayout.LayoutParams(
				(int)(maxWidth + 1), 
				12);
		params2.leftMargin = (int)(this.getWindowManager().getDefaultDisplay().getWidth() - maxWidth)/2;
		params2.topMargin = (int)(3);
		
		layout.addView(new View(layout.getContext()) {
			@Override
			public void onDraw(Canvas c) {
				Paint paint = new Paint();
				paint.setStrokeWidth(5);
				paint.setColor(0x66FF6666);
				c.drawLine(0, 0, max, 0, paint) ;
			}
		}, params2);
		

	}
	
	private LargeOperatorSymbolBox largeOp(LargeOp sumLarge) {
		return new LargeOperatorSymbolBox(sumLarge);
	}
	
	private LargeOperatorBox largeOp(LargeOp sumLarge, Box sub, Box sup) {
		return new LargeOperatorBox(sumLarge, sub, sup);
	}


	
	// ---- helper methods -----
	
	private SymbolBox sym(short c) {
		return new SymbolBox(c);
	}
	
	private SymbolBox sym(String s) {
		return new SymbolBox(s);
	}
	
	private FractionBox fraction(Box n, Box d) {
		return new FractionBox(n, d);
	}
	
	private ScriptBox superscript(Box b, Box s) {
		return new ScriptBox(b, s);
	}
	private ScriptBox script(Box b, Box sup, Box sub) {
		return new ScriptBox(b, sup, sub);
	}
	
	private SequenceBox sequence(Box... boxes){
		return new SequenceBox(boxes);
	}
	
	private DelimiterBox brackets(Delimiters d, Box b) {
		return new DelimiterBox(b, d);
	}
	
	private DelimiterBox brackets(Box b) {
		return brackets(Delimiters.paren,b);
	}

	private SpaceBox space(float w, float h) {
		return new SpaceBox(w, h);
	}
	
	private SqrtBox sqrt(Box b) {
		return new SqrtBox(b);
	}
	
	private RelationBox relation(Box l, short rel, Box r) {
		return new RelationBox(rel, l, r);
	}
	
	private OperationBox op(Box l, short op, Box r) {
		return new OperationBox(op, l, r);
	}
	
	/**
	 * 
	 * @param i integrand
	 * @param wrt with respect to
	 * @param d limit at the bottom
	 * @param u limit at the top
	 * @return
	 */
	private IntegralBox integral(Box i, SymbolBox wrt, SymbolBox d, SymbolBox u) {
		return new IntegralBox(i, wrt, u, d);
	}
	
	/**
	 * 
	 * @param i integrand
	 * @param wrt with respect to
	 * @return
	 */
	private IntegralBox integral(Box i, SymbolBox wrt) {
		return new IntegralBox(i, wrt);
	}
}