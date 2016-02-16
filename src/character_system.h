/* -*-c++-*- Copyright (C) 2010 Wang Rui <wangray84 at gmail dot com>
 * OpenSceneGraph Beginners Guide
 * Reading and playing with a character skeleton from external file
*/

#include <osgAnimation/BasicAnimationManager>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <iostream>

int character_system_main( int argc, char** argv )
{
    osg::ArgumentParser arguments( &argc, argv );
    
    bool listAll = false;
    std::string animationName;
    arguments.read( "--animation", animationName );
    if ( arguments.read("--listall") ) listAll = true;
    
    osg::ref_ptr<osg::Node> model = osgDB::readNodeFile( "bignathan.osg" );
    if ( !model )
    {
        OSG_FATAL << "The file bignathan.osg not found." << std::endl;
        return 1;
    }
    
    osgAnimation::BasicAnimationManager* manager =
        dynamic_cast<osgAnimation::BasicAnimationManager*>( model->getUpdateCallback() );
    if ( !manager )
    {
        OSG_FATAL << "Unable to find animation manager callback from bignathan.osg." << std::endl;
        return 1;
    }
    
    const osgAnimation::AnimationList& animations = manager->getAnimationList();
    if ( listAll ) std::cout << "**** Animations ****" << std::endl;
    for ( unsigned int i=0; i<animations.size(); ++i )
    {
        const std::string& name = animations[i]->getName();
        if ( name==animationName ) manager->playAnimation( animations[i].get() );
        if ( listAll ) std::cout << name << std::endl;
    }
    if ( listAll )
    {
        std::cout << "********************" << std::endl;
        return 0;
    }
    
    osgViewer::Viewer viewer;
    viewer.setSceneData( model.get() );
    return viewer.run();
}
