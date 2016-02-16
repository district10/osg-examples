/* -*-c++-*- OpenSceneGraph Beginners Guide
 * Monitor a class derived from Referenced
 * Author: Wang Rui <wangray84 at gmail dot com>
*/
#include <osg/ref_ptr>
#include <osg/Referenced>
#include <iostream>
class MonitoringTarget : public osg::Referenced
{
public:
    MonitoringTarget( int id ) : _id(id)
    { std::cout << "Constructing target " << _id << std::endl; }
    
protected:
    virtual ~MonitoringTarget()
    { std::cout << "Destroying target " << _id << std::endl; }
    
    int _id;
};

int referenced_main( int argc, char** argv )
{
    osg::ref_ptr<MonitoringTarget> target = new MonitoringTarget(0);
    std::cout << "Referenced count before referring: " << target->referenceCount() << std::endl;
    osg::ref_ptr<MonitoringTarget> anotherTarget = target;
    std::cout << "Referenced count after referring: " << target->referenceCount() << std::endl;
    
    for ( unsigned int i=1; i<5; ++i )
    {
        osg::ref_ptr<MonitoringTarget> subTarget = new MonitoringTarget(i);
    }
    return 0;
}
