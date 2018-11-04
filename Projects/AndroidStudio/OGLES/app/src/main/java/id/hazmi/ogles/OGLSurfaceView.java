package id.hazmi.ogles;

import android.content.Context;
import android.opengl.GLSurfaceView;
/**
 * Created by hazmi.arifin on 4/28/2018.
 */

public class OGLSurfaceView extends GLSurfaceView {
    private OGLRenderer mRenderer;
    public OGLSurfaceView(Context context){
        super(context);
        setEGLContextClientVersion(2);
        mRenderer=new OGLRenderer();
        setRenderer(mRenderer);
    }
}
