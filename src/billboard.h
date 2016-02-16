/* -*-c++-*- Copyright (C) 2010 Wang Rui <wangray84 at gmail dot com>
 * OpenSceneGraph Beginners Guide
 * Create a billboard displaying the OSG banner
*/

#include <osg/Billboard>
#include <osg/Texture2D>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

osg::Geometry* createQuad()
{
    osg::ref_ptr<osg::Texture2D> texture = new osg::Texture2D;
    osg::ref_ptr<osg::Image> image = osgDB::readImageFile( "Images/osg256.png" );
    texture->setImage( image.get() );
    
    osg::ref_ptr<osg::Geometry> quad = osg::createTexturedQuadGeometry(
        osg::Vec3(-0.5f, 0.0f, -0.5f), osg::Vec3(1.0f, 0.0f, 0.0f), osg::Vec3(0.0f, 0.0f, 1.0f) );
    quad->getOrCreateStateSet()->setTextureAttributeAndModes( 0, texture.get() );
    return quad.release();
}

int billboard_main( int argc, char** argv )
{
    osg::ref_ptr<osg::Billboard> geode = new osg::Billboard;
    geode->setMode( osg::Billboard::POINT_ROT_EYE );
    
    osg::Geometry* quad = createQuad();
    for ( unsigned int i=0; i<10; ++i )
    {
        geode->addDrawable( quad, osg::Vec3(-2.5f + 0.2f*(float)i, (float)i, 0.0f) );
        geode->addDrawable( quad, osg::Vec3( 2.5f - 0.2f*(float)i, (float)i, 0.0f) );
    }
    
    osg::StateSet* ss = geode->getOrCreateStateSet();
    ss->setRenderingHint( osg::StateSet::TRANSPARENT_BIN );
    
    osgViewer::Viewer viewer;
    viewer.setSceneData( geode.get() );
    return viewer.run();
}
