/**
 * @author  Steven Lovegrove
 * Copyright (C) 2010  Steven Lovegrove
 *                     Imperial College London
 **/

#include <pangolin/pangolin.h>
#include <pangolin/video.h>
#include <pangolin/video_record_repeat.h>
#include <pangolin/input_record_repeat.h>

using namespace pangolin;
using namespace std;

void RecordSample(const std::string uri, const std::string filename)
{
    // Setup Video Source
    VideoRecordRepeat video(uri, filename, 1024*1024*200);
    const unsigned w = video.Width();
    const unsigned h = video.Height();

    InputRecordRepeat input("ui.");

    // Create Glut window
    const int panel_width = 200;
    pangolin::CreateGlutWindowAndBind("Main",w + panel_width,h);

    // Create viewport for video with fixed aspect
    View& d_panel = pangolin::CreatePanel("ui.")
        .SetBounds(1.0, 0.0, 0, panel_width);

    View& vVideo = Display("Video")
        .SetBounds(1.0, 0.0, panel_width, 1.0)
        .SetAspect((float)w/h);

    // OpenGl Texture for video frame
    GlTexture texVideo(w,h,GL_RGBA8);

    unsigned char* rgb = new unsigned char[video.Width()*video.Height()*3];

    static Var<bool> record("ui.Record",false,false);
    static Var<bool> play("ui.Play",false,false);
    static Var<bool> source("ui.Source",false,false);
    static Var<bool> realtime("ui.realtime",true,true);

    static Var<float> hue("ui.Hue",0,0,360);
    static Var<bool> colour("ui.Colour Video",false,true);

    for(; !pangolin::ShouldQuit();)
    {
        // Load next video frame
        video.GrabNext(rgb,true);
        texVideo.Upload(rgb,GL_RGB,GL_UNSIGNED_BYTE);

        // Associate input with this video frame
        input.SetIndex(video.FrameId());

        // Activate video viewport and render texture
        vVideo.ActivateScissorAndClear();

        if( colour ) {
            glColorHSV(hue,0.5,1.0);
        }else{
            glColor3f(1,1,1);
        }
        texVideo.RenderToViewportFlipY();

        if(pangolin::Pushed(record)) {
            video.Record();
            input.Record();
        }

        if(pangolin::Pushed(play)) {
            video.Play(realtime);
            input.PlayBuffer(0,input.Size()-1);
        }

        if(pangolin::Pushed(source)) {
            video.Source();
            input.Stop();
        }

        d_panel.Render();

        glutSwapBuffers();
        glutMainLoopEvent();
    }

    delete[] rgb;
}

int main( int argc, char* argv[] )
{
    std::string uri = "dc1394:[fps=30,dma=10,size=640x480,iso=400]//0";
    std::string filename = "video.pvn";

    if( argc >= 2 ) {
        uri = std::string(argv[1]);
        if( argc == 3 ) {
            filename = std::string(argv[2]);
        }
    }else{
        cout << "Usage:" << endl << "\tSimpleRecord video-uri filename" << endl;
        cout << "\tvideo-uri:\tURI of file / device to extract video sequence from" << endl;
        cout << "\tfilename:\tfilename to record pvn video in to" << endl << endl;
        cout << "e.g." << endl;
        cout << "\tSimpleRecord dc1394:[fps=30,dma=10,size=640x480,iso=400]//0 video.pvn" << endl;
        cout << "\tSimpleRecord v4l:///dev/video0 video.pvn" << endl;
        cout << endl << "Defaulting to video-uri=" << uri << endl;
    }

    RecordSample(uri, filename);
}
