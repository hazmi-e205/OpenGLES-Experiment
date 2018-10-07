package id.hazmi.ogles;

import android.opengl.GLES20;
import android.opengl.GLSurfaceView;

import javax.microedition.khronos.opengles.GL10;
import javax.microedition.khronos.egl.EGLConfig;

/**
 * Created by hazmi.arifin on 4/28/2018.
 */

public class OGLRenderer implements GLSurfaceView.Renderer{
    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        JNIBridge.native_init();
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        JNIBridge.ogl_init(width, height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        JNIBridge.ogl_draw();
    }
}
