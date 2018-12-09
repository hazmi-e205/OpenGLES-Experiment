package id.hazmi.ogles;

import android.app.Activity;
import android.os.Bundle;

public class MainActivity extends Activity {
    static {
        System.loadLibrary("JNIBridge");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        JNIBridge.native_init();
        JNIBridge.setAsset(getAssets());

        //get directory https://gist.github.com/granoeste/5574148
        JNIBridge.getDataDirectory(getExternalFilesDir(null).toString());
        setContentView(new OGLSurfaceView(this));
    }
}
