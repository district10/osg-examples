/* -*-c++-*- Copyright (C) 2010 Wang Rui <wangray84 at gmail dot com>
 * OpenSceneGraph Beginners Guide
 * Enabling global multisampling of viewers
*/

#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

int multisampling_main( int argc, char** argv )
{
    osg::DisplaySettings::instance()->setNumMultiSamples( 4 );
    
    osg::ref_ptr<osg::Node> model = osgDB::readNodeFile( "cessna.osg" );
    
    osgViewer::Viewer viewer;
    viewer.setSceneData( model.get() );
    return viewer.run();
}
