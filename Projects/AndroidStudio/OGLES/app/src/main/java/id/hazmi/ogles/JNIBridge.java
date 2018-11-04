package id.hazmi.ogles;

import android.content.res.AssetManager;

/**
 * Created by hazmi.arifin on 4/28/2018.
 */

public class JNIBridge {
    public static native void native_init();
    public static native void ogl_init(int width, int height);
    public static native void ogl_draw();

    public static native void getDataDirectory(String dataDir);
    public static native void setAsset(AssetManager assetMgr);
}
