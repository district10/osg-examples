/* -*-c++-*- Copyright (C) 2010 Wang Rui <wangray84 at gmail dot com>
 * OpenSceneGraph Beginners Guide
 * Using a simulation loop to replace the run() method
*/

#include <osgDB/ReadFile>
#include <osgGA/TrackballManipulator>
#include <osgViewer/Viewer>
#include <iostream>

int simulation_loop_main( int argc, char** argv )
{
    osg::ref_ptr<osg::Node> model = osgDB::readNodeFile( "lz.osg" );
    
    osgViewer::Viewer viewer;
    viewer.setSceneData( model.get() );
    viewer.setCameraManipulator( new osgGA::TrackballManipulator );
    while ( !viewer.done() )
    {
        viewer.frame();
        std::cout << "Frame number: " << viewer.getFrameStamp()->getFrameNumber() << std::endl;
    }
    return 0;
}
