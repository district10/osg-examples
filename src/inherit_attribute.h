/* -*-c++-*- Copyright (C) 2010 Wang Rui <wangray84 at gmail dot com>
 * OpenSceneGraph Beginners Guide
 * Enable/disable OpenGL lighting of parent and child nodes
*/

#include <osg/PolygonMode>
#include <osg/MatrixTransform>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

int inherit_attribute_main( int argc, char** argv )
{
    osg::ref_ptr<osg::Node> model = osgDB::readNodeFile( "glider.osg" );
    
    osg::ref_ptr<osg::MatrixTransform> transformation1 = new osg::MatrixTransform;
    transformation1->setMatrix( osg::Matrix::translate(-0.5f, 0.0f, 0.0f) );
    transformation1->addChild( model.get() );
    transformation1->getOrCreateStateSet()->setMode(
        GL_LIGHTING, osg::StateAttribute::OFF );
    
    osg::ref_ptr<osg::MatrixTransform> transformation2 = new osg::MatrixTransform;
    transformation2->setMatrix( osg::Matrix::translate(0.5f, 0.0f, 0.0f) );
    transformation2->addChild( model.get() );
    transformation2->getOrCreateStateSet()->setMode(
        GL_LIGHTING, osg::StateAttribute::OFF|osg::StateAttribute::PROTECTED );
    
    osg::ref_ptr<osg::Group> root = new osg::Group;
    root->getOrCreateStateSet()->setMode(
        GL_LIGHTING, osg::StateAttribute::ON|osg::StateAttribute::OVERRIDE );
    root->addChild( transformation1.get() );
    root->addChild( transformation2.get() );
    
    osgViewer::Viewer viewer;
    viewer.setSceneData( root.get() );
    return viewer.run();
}
