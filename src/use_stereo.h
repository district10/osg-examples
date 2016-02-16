/* -*-c++-*- Copyright (C) 2010 Wang Rui <wangray84 at gmail dot com>
 * OpenSceneGraph Beginners Guide
 * Rendering scenes in anaglyph (red/cyan) stereo mode
*/

#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

int use_stereo_main( int argc, char** argv )
{
    osg::DisplaySettings::instance()->setStereoMode( osg::DisplaySettings::ANAGLYPHIC );
    osg::DisplaySettings::instance()->setEyeSeparation( 0.05f );
    osg::DisplaySettings::instance()->setStereo( true );
    
    osg::ref_ptr<osg::Node> model = osgDB::readNodeFile( "cessna.osg" );
    
    osgViewer::Viewer viewer;
    viewer.setSceneData( model.get() );
    return viewer.run();
}
