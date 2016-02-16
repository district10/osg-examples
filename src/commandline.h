/* -*-c++-*- OpenSceneGraph Beginners Guide
 * Read from command line arguments
 * Author: Wang Rui <wangray84 at gmail dot com>
*/
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

int commandline_main( int argc, char** argv )
{
    osg::ArgumentParser arguments( &argc, argv );
    //osg::ref_ptr<osg::Node> root = osgDB::readNodeFiles( arguments );
    
    std::string filename;
    arguments.read( "--model", filename );
    osg::ref_ptr<osg::Node> root = osgDB::readNodeFile( filename );
    
    osgViewer::Viewer viewer;
    viewer.setSceneData( root.get() );
    return viewer.run();
}
