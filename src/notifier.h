/* -*-c++-*- OpenSceneGraph Beginners Guide
 * Use the notify handler
 * Author: Wang Rui <wangray84 at gmail dot com>
*/
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <fstream>
class LogFileHandler : public osg::NotifyHandler
{
public:
    LogFileHandler( const std::string& file ) { _log.open( file.c_str() ); }
    virtual ~LogFileHandler() { _log.close(); }
    
    virtual void notify( osg::NotifySeverity severity, const char* message )
    {
        switch ( severity )
        {
        case osg::ALWAYS: _log << "[ALWAYS]: "; break;
        case osg::FATAL: _log << "[FATAL]: "; break;
        case osg::WARN: _log << "[WARN]: "; break;
        case osg::NOTICE: _log << "[NOTICE]: "; break;
        case osg::INFO: _log << "[INFO]: "; break;
        default: break;
        }
        _log << message;
    }
    
protected:
    std::ofstream _log;
};
int notifier_main( int argc, char** argv )
{
    osg::setNotifyLevel( osg::INFO );
    osg::setNotifyHandler( new LogFileHandler("output.txt") );
    
    osg::ArgumentParser arguments( &argc, argv );
    osg::ref_ptr<osg::Node> root = osgDB::readNodeFiles( arguments );
    if ( !root )
    {
        OSG_FATAL << arguments.getApplicationName() <<": No data loaded." << std::endl;
        return -1;
    }
    
    osgViewer::Viewer viewer;
    viewer.setSceneData( root.get() );
    return viewer.run();
}