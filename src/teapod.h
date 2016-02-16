/*
#include <gl/glut.h>
#include <osg/Drawable>
#include <osg/Geode>
#include <osgViewer/Viewer>


class TeapotDrawable : public osg::Drawable
{
public:
    TeapotDrawable( float size=1.0f ) : _size(size) {}
    TeapotDrawable( const TeapotDrawable& copy, const osg::CopyOp& copyop=osg::CopyOp::SHALLOW_COPY )
        : osg::Drawable(copy, copyop), _size(copy._size) {}
    META_Object( osg, TeapotDrawable );
    virtual osg::BoundingBox computeBound() const;
    virtual void drawImplementation( osg::RenderInfo& ) const;
protected:
    float _size;
};


osg::BoundingBox TeapotDrawable::computeBound() const
{
    osg::Vec3 min(-_size,-_size,-_size), max(_size, _size, _size);
    return osg::BoundingBox(min, max);
}

void TeapotDrawable::drawImplementation( osg::RenderInfo& renderInfo ) const
{
    glFrontFace( GL_CW );
    glutSolidTeapot( _size );
    glFrontFace( GL_CCW );
}

int teapod_main( int argc, char **argv )
{
    osg::ref_ptr<osg::Geode> root = new osg::Geode;
    root->addDrawable( new TeapotDrawable(1.0f) );
    osgViewer::Viewer viewer;
    viewer.setSceneData( root.get() );
    return viewer.run();
}
*/

int teapod_main( int argc, char **argv )
{
    return -1;
}