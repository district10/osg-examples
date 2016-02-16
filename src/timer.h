/* -*-c++-*- Copyright (C) 2010 Wang Rui <wangray84 at gmail dot com>
 * OpenSceneGraph Beginners Guide
 * Add a customized timer event and trigger it
*/

#include <osg/Switch>
#include <osgDB/ReadFile>
#include <osgGA/GUIEventHandler>
#include <osgViewer/Viewer>
#include <iostream>

struct TimerInfo : public osg::Referenced
{
    TimerInfo( unsigned int c ) : _count(c) {}
    unsigned int _count;
};

class TimerHandler : public osgGA::GUIEventHandler
{
public:
    TimerHandler( osg::Switch* sw )
    : _switch(sw), _count(0) {}
    
    virtual bool handle( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa )
    {
        switch ( ea.getEventType() )
        {
        case osgGA::GUIEventAdapter::FRAME:
            if ( _count % 100 == 0 )
            {
                osgViewer::Viewer* viewer = dynamic_cast<osgViewer::Viewer*>(&aa);
                if ( viewer ) viewer->getEventQueue()->userEvent( new TimerInfo(_count) );
            }
            _count++;
            break;
        case osgGA::GUIEventAdapter::USER:
            if ( _switch.valid() )
            {
                const TimerInfo* ti = dynamic_cast<const TimerInfo*>( ea.getUserData() );
                std::cout << "Timer event at: " << ti->_count << std::endl;
                
                _switch->setValue( 0, !_switch->getValue(0) );
                _switch->setValue( 1, !_switch->getValue(1) );
            }
            break;
        default:
            break;
        }
        return false;
    }
    
protected:
    osg::ref_ptr<osg::Switch> _switch;
    unsigned int _count;
};

int timer_main( int argc, char** argv )
{
    osg::ref_ptr<osg::Node> model1 = osgDB::readNodeFile( "cessna.osg" );
    osg::ref_ptr<osg::Node> model2 = osgDB::readNodeFile( "cessnafire.osg" );
    
    osg::ref_ptr<osg::Switch> root = new osg::Switch;
    root->addChild( model1.get(), false );
    root->addChild( model2.get(), true );
    
    osgViewer::Viewer viewer;
    viewer.setSceneData( root.get() );
    viewer.addEventHandler( new TimerHandler(root.get()) );
    return viewer.run();
}
