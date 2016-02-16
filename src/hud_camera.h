/* -*-c++-*- Copyright (C) 2010 Wang Rui <wangray84 at gmail dot com>
 * OpenSceneGraph Beginners Guide
 * Creating a HUD camera which displays on the top of other scenes
*/

#include <osg/Camera>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

int hud_carema_main( int argc, char** argv )
{
    osg::ref_ptr<osg::Node> model = osgDB::readNodeFile( "lz.osg" );
    osg::ref_ptr<osg::Node> hud_model = osgDB::readNodeFile( "glider.osg" );
    
    osg::ref_ptr<osg::Camera> camera = new osg::Camera;
    camera->setClearMask( GL_DEPTH_BUFFER_BIT );
    camera->setRenderOrder( osg::Camera::POST_RENDER );
    camera->setReferenceFrame( osg::Camera::ABSOLUTE_RF );
    camera->setViewMatrixAsLookAt( osg::Vec3(0.0f,-5.0f, 5.0f), osg::Vec3(), osg::Vec3(0.0f, 1.0f, 1.0f) );
    camera->addChild( hud_model.get() );
    
    osg::ref_ptr<osg::Group> root = new osg::Group;
    root->addChild( model.get() );
    root->addChild( camera.get() );
    
    osgViewer::Viewer viewer;
    viewer.setSceneData( root.get() );
    return viewer.run();
}
