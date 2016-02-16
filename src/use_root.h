/* -*-c++-*- OpenSceneGraph Beginners Guide
 * Improve the simplest scene using a root node
 * Author: Wang Rui <wangray84 at gmail dot com>
*/
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

int use_root_main( int argc, char** argv )
{
    osg::ref_ptr<osg::Node> root = osgDB::readNodeFile( "cessna.osg" );
    
    osgViewer::Viewer viewer;
    viewer.setSceneData( root.get() );
    return viewer.run();
}