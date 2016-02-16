/* -*-c++-*- Copyright (C) 2010 Wang Rui <wangray84 at gmail dot com>
 * OpenSceneGraph Beginners Guide
 * Load a model at runtime
*/

#include <osg/ProxyNode>
#include <osgViewer/Viewer>

int proxy_loading_main( int argc, char** argv )
{
    osg::ref_ptr<osg::ProxyNode> root = new osg::ProxyNode;
    root->setFileName( 0, "cow.osg" );
    
    osgViewer::Viewer viewer;
    viewer.setSceneData( root.get() );
    return viewer.run();
}
