/* -*-c++-*- Copyright (C) 2010 Wang Rui <wangray84 at gmail dot com>
 * OpenSceneGraph Beginners Guide
 * Create a simple file I/O plugin which reads points and output triangle strips
*/

#include <osg/Node>
#include <osgDB/ObjectWrapper>
#include <osgDB/Registry>
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <iostream>

namespace testNS
{

class ExampleNode : public osg::Node
{
public:
    ExampleNode() : osg::Node(), _exampleID(0) {}
    
    ExampleNode(const ExampleNode& copy, const osg::CopyOp& copyop=osg::CopyOp::SHALLOW_COPY)
    : osg::Node(copy, copyop), _exampleID(copy._exampleID) {}
    
    META_Node(testNS, ExampleNode)
    
    void setExampleID( unsigned int id ) { _exampleID = id; }
    unsigned int getExampleID() const { return _exampleID; }
    
protected:
    unsigned int _exampleID;
};

}

namespace
{

REGISTER_OBJECT_WRAPPER( ExampleNode_Wrapper,
                         new testNS::ExampleNode,
                         testNS::ExampleNode,
                         "osg::Object osg::Node testNS::ExampleNode" )
{
    ADD_UINT_SERIALIZER( ExampleID, 0 );
}

}

int serializer_main( int argc, char** argv )
{
    osg::ArgumentParser arguments( &argc, argv );
    
    unsigned int writingValue = 0;
    arguments.read( "-w", writingValue );
    
    if ( writingValue!=0 )
    {
        osg::ref_ptr<testNS::ExampleNode> node = new testNS::ExampleNode;
        node->setExampleID( writingValue );
        osgDB::writeNodeFile( *node, "examplenode.osgt" );
    }
    else
    {
        testNS::ExampleNode* node = dynamic_cast<testNS::ExampleNode*>(
            osgDB::readNodeFile("examplenode.osgt") );
        if ( node!=NULL )
            std::cout << "Example ID: " << node->getExampleID() << std::endl;
    }
    return 0;
}
