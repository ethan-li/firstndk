package com.ethan.sample.ndk;

import android.app.Activity;
import android.app.AlertDialog;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class firstndkActivity extends Activity {
	
	static {
		System.loadLibrary("ndkfoo");
	}
	
	private native void helloLog(String logThis);
	private native String addIntReturnString(int value1, int value2);
	
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        Button btnNDKAdd = (Button)findViewById(R.id.buttonNDKAdd);
        btnNDKAdd.setOnClickListener(new OnClickListener() {
        	@Override
        	public void onClick(View v) {
        		
        	}
        });
        
        // java --> native
        helloLog("This will log to LogCat via the native call.");
        
        // java --> native --> java
        String result = "addIntReturnString result = "+ addIntReturnString(1, 2);
        new AlertDialog.Builder(this).setMessage(result).show();
    }
}