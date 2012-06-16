package uk.ac.cam.aa582;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

/**
 * This activity is a simple about screen, which can be accessible
 * through an options menu from {@link MainActivity}. It contains
 * and OK button that allows the user to return to the previous
 * Activity.<br/>
 * The text shown in this Activity can be found at R.string.about
 * 
 * @author Ahmad Akra
 *
 */
public class AboutActivity extends Activity implements OnClickListener {
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.about);

		Button okButton = (Button) findViewById(R.id.ok);
		okButton.setOnClickListener(this);
	}

	@Override
	public void onClick(View v) {
		this.finish();
	}
}
