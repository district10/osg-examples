/* -*-c++-*- Copyright (C) 2010 Wang Rui <wangray84 at gmail dot com>
 * OpenSceneGraph Beginners Guide
 * Apply fog effect to the terrain model
*/

#include <osg/Fog>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

int apply_fog_main( int argc, char** argv )
{
    osg::ref_ptr<osg::Fog> fog = new osg::Fog;
    fog->setMode( osg::Fog::LINEAR );
    fog->setStart( 500.0f );
    fog->setEnd( 2500.0f );
    fog->setColor( osg::Vec4(1.0f, 1.0f, 0.0f, 1.0f) );
    
    osg::ref_ptr<osg::Node> model = osgDB::readNodeFile( "lz.osg" );
    model->getOrCreateStateSet()->setAttributeAndModes( fog.get() );
    
    osgViewer::Viewer viewer;
    viewer.setSceneData( model.get() );
    return viewer.run();
}
