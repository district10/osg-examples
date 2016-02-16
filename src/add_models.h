/* -*-c++-*- Copyright (C) 2010 Wang Rui <wangray84 at gmail dot com>
 * OpenSceneGraph Beginners Guide
 * Adding more models from files
*/

#include <osg/Group>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

int add_models_main( int argc, char** argv )
{
    osg::ref_ptr<osg::Node> model1 = osgDB::readNodeFile( "cessna.osg" );
    osg::ref_ptr<osg::Node> model2 = osgDB::readNodeFile( "cow.osg" );
    
    osg::ref_ptr<osg::Group> root = new osg::Group;
    root->addChild( model1.get() );
    root->addChild( model2.get() );
    
    osgViewer::Viewer viewer;
    viewer.setSceneData( root.get() );
    return viewer.run();
}
