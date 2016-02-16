/* -*-c++-*- Copyright (C) 2010 Wang Rui <wangray84 at gmail dot com>
 * OpenSceneGraph Beginners Guide
 * Using a reading callback to share textures with the same filename
*/

#include <osg/Texture2D>
#include <osg/Geometry>
#include <osg/Geode>
#include <osg/Group>
#include <osgDB/ReadFile>
#include <osgViewer/ViewerEventHandlers>
#include <osgViewer/Viewer>

#define RAND(min, max) ((min) + (float)rand()/((float)RAND_MAX+1) * ((max)-(min)))

osg::Geode* createMassiveQuads( unsigned int number, const std::string& imageFile )
{
    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
    for ( unsigned int i=0; i<number; ++i )
    {
        osg::Vec3 randomCenter;
        randomCenter.x() = RAND(-100.0f, 100.0f);
        randomCenter.y() = RAND(1.0f, 100.0f);
        randomCenter.z() = RAND(-100.0f, 100.0f);
        
        osg::ref_ptr<osg::Drawable> quad = osg::createTexturedQuadGeometry(
            randomCenter, osg::Vec3(1.0f, 0.0f, 0.0f), osg::Vec3(0.0f, 0.0f, 1.0f) );
        
        osg::ref_ptr<osg::Texture2D> texture = new osg::Texture2D;
        osg::ref_ptr<osg::Image> image = osgDB::readImageFile( imageFile );
        texture->setImage( image.get() );
        quad->getOrCreateStateSet()->setTextureAttributeAndModes( 0, texture.get() );
        
        geode->addDrawable( quad.get() );
    }
    return geode.release();
}

class ReadAndShareImageCallback : public osgDB::ReadFileCallback
{
public:
    virtual osgDB::ReaderWriter::ReadResult readImage( const std::string& filename, const osgDB::Options* options )
    {
        osg::Image* image = getImageByName( filename );
        if ( !image )
        {
            osgDB::ReaderWriter::ReadResult rr = 
                osgDB::Registry::instance()->readImageImplementation( filename, options );
            if ( rr.success() ) _imageMap[filename] = rr.getImage();
            return rr;
        }
        return image;
    }
    
protected:
    osg::Image* getImageByName( const std::string& filename )
    {
        ImageMap::iterator itr = _imageMap.find(filename);
        if ( itr!=_imageMap.end() ) return itr->second.get();
        return NULL;
    }
    
    typedef std::map<std::string, osg::ref_ptr<osg::Image> > ImageMap;
    ImageMap _imageMap;
};

int sharing_textures_main( int argc, char** argv )
{
    osgDB::Registry::instance()->setReadFileCallback( new ReadAndShareImageCallback );
    osgDB::Registry::instance()->getOrCreateSharedStateManager();
    
    osg::ref_ptr<osg::Group> root = new osg::Group;
    root->addChild( createMassiveQuads(500, "Images/lz.rgb") );
    root->addChild( createMassiveQuads(500, "Images/osg64.png") );
    
    osgDB::SharedStateManager* ssm =
        osgDB::Registry::instance()->getSharedStateManager();
    if ( ssm ) ssm->share( root.get() );
    
    osgViewer::Viewer viewer;
    viewer.addEventHandler( new osgViewer::StatsHandler );
    viewer.setSceneData( root.get() );
    return viewer.run();
}
