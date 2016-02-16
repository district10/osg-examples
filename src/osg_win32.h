/* -*-c++-*- Copyright (C) 2010 Wang Rui <wangray84 at gmail dot com>
 * OpenSceneGraph Beginners Guide
 * Integrate the OSG rendering context with a window handle in Win32 applications
*/

#include <windows.h>
#include <process.h>
#include <osgDB/ReadFile>
#include <osgGA/TrackballManipulator>
#include <osgViewer/api/win32/GraphicsWindowWin32>
#include <osgViewer/Viewer>

osg::ref_ptr<osgViewer::Viewer> g_viewer;
bool g_finished;

void render( void* )
{
    while ( !g_viewer->done() )
        g_viewer->frame();
    g_finished = true;
}

LRESULT CALLBACK WndProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    switch ( message )
    {
    case WM_CREATE:
        {
            osg::ref_ptr<osg::Referenced> windata =
                new osgViewer::GraphicsWindowWin32::WindowData( hwnd );
            
            osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
            traits->x = 0;
            traits->y = 0;
            traits->width = 800;
            traits->height = 600;
            traits->windowDecoration = false;
            traits->doubleBuffer = true;
            traits->inheritedWindowData = windata;
            
            osg::ref_ptr<osg::GraphicsContext> gc =
                osg::GraphicsContext::createGraphicsContext( traits.get() );
            
            osg::ref_ptr<osg::Camera> camera = new osg::Camera;
            camera->setGraphicsContext( gc );
            camera->setViewport( new osg::Viewport(0, 0, traits->width, traits->height) );
            camera->setClearMask( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT );
            camera->setClearColor( osg::Vec4f(0.2f, 0.2f, 0.4f, 1.0f) );
            camera->setProjectionMatrixAsPerspective(
                30.0f, (double)traits->width/(double)traits->height, 1.0, 1000.0 );
            
            g_viewer = new osgViewer::Viewer;
            g_viewer->setCamera( camera.get() );
            g_viewer->setSceneData( osgDB::readNodeFile("cessna.osg") );
            g_viewer->setKeyEventSetsDone( 0 );
            g_viewer->setCameraManipulator( new osgGA::TrackballManipulator );
        }
        g_finished = false;
        _beginthread( render, 0, NULL );
        return 0;
    case WM_DESTROY:
        g_viewer->setDone( true );
        while ( !g_finished ) Sleep(10);
        PostQuitMessage( 0 );
        return 0;
    default:
        break;
    }
    return DefWindowProc( hwnd, message, wParam, lParam );
}

int osg_win32_main( int argc, char** argv )
{
    static TCHAR szAppName[] = TEXT("gui");
    
    WNDCLASS wndclass;
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = 0;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;
    if ( !RegisterClass(&wndclass) )
        return 0;
    
    HWND hwnd = CreateWindow( szAppName, // window class name
                              TEXT("OSG and Win32 API Window"), // window caption
                              WS_OVERLAPPEDWINDOW, // window style
                              100, // initial x position
                              100, // initial y position
                              800, // initial x size
                              600, // initial y size
                              NULL, // parent window handle
                              NULL, // window menu handle
                              0, // program instance handle
                              NULL ); // creation parameters
    ShowWindow( hwnd, SW_SHOW );
    UpdateWindow( hwnd );
    
    MSG msg;
    while ( GetMessage(&msg, NULL, 0, 0) )
    {
        TranslateMessage( &msg );
        DispatchMessage( &msg );
    }
    return 0;
}
