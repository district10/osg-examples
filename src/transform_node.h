/* -*-c++-*- Copyright (C) 2010 Wang Rui <wangray84 at gmail dot com>
 * OpenSceneGraph Beginners Guide
 * Transform the model to another position
*/

#include <osg/MatrixTransform>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

int transform_node_main( int argc, char** argv )
{
    osg::ref_ptr<osg::Node> model = osgDB::readNodeFile( "cessna.osg" );
    
    osg::ref_ptr<osg::MatrixTransform> transformation1 = new osg::MatrixTransform;
    transformation1->setMatrix( osg::Matrix::translate(-25.0f, 0.0f, 0.0f) );
    transformation1->addChild( model.get() );
    
    osg::ref_ptr<osg::MatrixTransform> transformation2 = new osg::MatrixTransform;
    transformation2->setMatrix( osg::Matrix::translate(25.0f, 0.0f, 0.0f) );
    transformation2->addChild( model.get() );
    
    osg::ref_ptr<osg::Group> root = new osg::Group;
    root->addChild( transformation1.get() );
    root->addChild( transformation2.get() );
    
    osgViewer::Viewer viewer;
    viewer.setSceneData( root.get() );
    return viewer.run();
}
