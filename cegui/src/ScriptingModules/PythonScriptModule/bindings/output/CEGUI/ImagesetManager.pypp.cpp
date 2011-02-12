// This file has been generated by Py++.

#include "boost/python.hpp"
#include "python_CEGUI.h"
#include "ImagesetManager.pypp.hpp"

namespace bp = boost::python;

struct ImagesetManager_wrapper : CEGUI::ImagesetManager, bp::wrapper< CEGUI::ImagesetManager > {

    ImagesetManager_wrapper( )
    : CEGUI::ImagesetManager( )
      , bp::wrapper< CEGUI::ImagesetManager >(){
        // null constructor
    
    }

    virtual void fireEvent( ::CEGUI::String const & name, ::CEGUI::EventArgs & args, ::CEGUI::String const & eventNamespace="" ) {
        if( bp::override func_fireEvent = this->get_override( "fireEvent" ) )
            func_fireEvent( boost::ref(name), boost::ref(args), boost::ref(eventNamespace) );
        else{
            this->CEGUI::EventSet::fireEvent( boost::ref(name), boost::ref(args), boost::ref(eventNamespace) );
        }
    }
    
    void default_fireEvent( ::CEGUI::String const & name, ::CEGUI::EventArgs & args, ::CEGUI::String const & eventNamespace="" ) {
        CEGUI::EventSet::fireEvent( boost::ref(name), boost::ref(args), boost::ref(eventNamespace) );
    }

    virtual ::CEGUI::RefCounted< CEGUI::BoundSlot > subscribeScriptedEvent( ::CEGUI::String const & name, ::CEGUI::String const & subscriber_name ) {
        if( bp::override func_subscribeScriptedEvent = this->get_override( "subscribeScriptedEvent" ) )
            return func_subscribeScriptedEvent( boost::ref(name), boost::ref(subscriber_name) );
        else{
            return this->CEGUI::EventSet::subscribeScriptedEvent( boost::ref(name), boost::ref(subscriber_name) );
        }
    }
    
    ::CEGUI::RefCounted< CEGUI::BoundSlot > default_subscribeScriptedEvent( ::CEGUI::String const & name, ::CEGUI::String const & subscriber_name ) {
        return CEGUI::EventSet::subscribeScriptedEvent( boost::ref(name), boost::ref(subscriber_name) );
    }

    virtual ::CEGUI::RefCounted< CEGUI::BoundSlot > subscribeScriptedEvent( ::CEGUI::String const & name, unsigned int group, ::CEGUI::String const & subscriber_name ) {
        if( bp::override func_subscribeScriptedEvent = this->get_override( "subscribeScriptedEvent" ) )
            return func_subscribeScriptedEvent( boost::ref(name), group, boost::ref(subscriber_name) );
        else{
            return this->CEGUI::EventSet::subscribeScriptedEvent( boost::ref(name), group, boost::ref(subscriber_name) );
        }
    }
    
    ::CEGUI::RefCounted< CEGUI::BoundSlot > default_subscribeScriptedEvent( ::CEGUI::String const & name, unsigned int group, ::CEGUI::String const & subscriber_name ) {
        return CEGUI::EventSet::subscribeScriptedEvent( boost::ref(name), group, boost::ref(subscriber_name) );
    }

};

void register_ImagesetManager_class(){

    { //::CEGUI::ImagesetManager
        typedef bp::class_< ImagesetManager_wrapper, bp::bases< CEGUI::Singleton< CEGUI::ImagesetManager >, CEGUI::NamedXMLResourceManager< CEGUI::Imageset, CEGUI::Imageset_xmlHandler > >, boost::noncopyable > ImagesetManager_exposer_t;
        ImagesetManager_exposer_t ImagesetManager_exposer = ImagesetManager_exposer_t( "ImagesetManager", bp::init< >("! Constructor for ImagesetManager objects\n") );
        bp::scope ImagesetManager_scope( ImagesetManager_exposer );
        { //::CEGUI::ImagesetManager::create
        
            typedef ::CEGUI::Imageset & ( ::CEGUI::ImagesetManager::*create_function_type )( ::CEGUI::String const &,::CEGUI::Texture &,::CEGUI::XMLResourceExistsAction ) ;
            
            ImagesetManager_exposer.def( 
                "create"
                , create_function_type( &::CEGUI::ImagesetManager::create )
                , ( bp::arg("name"), bp::arg("texture"), bp::arg("action")=::CEGUI::XREA_RETURN )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "*!\n\
                \n\
                    Create a Imageset object with the given name and Texture\n\
            \n\
                    The created Imageset will be of limited use, and will require one or\n\
                    more images to be defined for the set.\n\
            \n\
                @param name\n\
                    String object containing the unique name for the Imageset being created.\n\
            \n\
                @param texture\n\
                    Texture object to be associated with the Imageset\n\
            \n\
                @param action\n\
                    One of the XMLResourceExistsAction enumerated values indicating what\n\
                    action should be taken when an Imageset with the specified name\n\
                    already exists.\n\
            \n\
                @return\n\
                    Reference to the newly created Imageset object\n\
            \n\
                @exception AlreadyExistsException\n\
                    thrown if an Imageset named  name is already present in the system.\n\
                *\n" );
        
        }
        { //::CEGUI::ImagesetManager::createFromImageFile
        
            typedef ::CEGUI::Imageset & ( ::CEGUI::ImagesetManager::*createFromImageFile_function_type )( ::CEGUI::String const &,::CEGUI::String const &,::CEGUI::String const &,::CEGUI::XMLResourceExistsAction ) ;
            
            ImagesetManager_exposer.def( 
                "createFromImageFile"
                , createFromImageFile_function_type( &::CEGUI::ImagesetManager::createFromImageFile )
                , ( bp::arg("name"), bp::arg("filename"), bp::arg("resourceGroup")="", bp::arg("action")=::CEGUI::XREA_RETURN )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::CEGUI::ImagesetManager::getIterator
        
            typedef ::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Imageset*, CEGUI::String::FastLessCompare, CEGUI::STLAllocatorWrapper<std::pair<CEGUI::String, CEGUI::Imageset*>, CEGUI::StdAllocator> > > ( ::CEGUI::ImagesetManager::*getIterator_function_type )(  ) const;
            
            ImagesetManager_exposer.def( 
                "getIterator"
                , getIterator_function_type( &::CEGUI::ImagesetManager::getIterator )
                , "*!\n\
            \n\
                Return a ImagesetManager.ImagesetIterator object to iterate over the\n\
                available Imageset objects.\n\
            *\n" );
        
        }
        { //::CEGUI::ImagesetManager::notifyDisplaySizeChanged
        
            typedef void ( ::CEGUI::ImagesetManager::*notifyDisplaySizeChanged_function_type )( ::CEGUI::Size const & ) ;
            
            ImagesetManager_exposer.def( 
                "notifyDisplaySizeChanged"
                , notifyDisplaySizeChanged_function_type( &::CEGUI::ImagesetManager::notifyDisplaySizeChanged )
                , ( bp::arg("size") )
                , "*!\n\
                \n\
                    Notify the ImagesetManager that the display size may have changed.\n\
            \n\
                @param size\n\
                    Size object describing the display resolution\n\
                *\n" );
        
        }
        { //::CEGUI::ImagesetManager::writeImagesetToStream
        
            typedef void ( ::CEGUI::ImagesetManager::*writeImagesetToStream_function_type )( ::CEGUI::String const &,::CEGUI::OutStream & ) const;
            
            ImagesetManager_exposer.def( 
                "writeImagesetToStream"
                , writeImagesetToStream_function_type( &::CEGUI::ImagesetManager::writeImagesetToStream )
                , ( bp::arg("imageset"), bp::arg("out_stream") )
                , "*!\n\
                \n\
                    Writes a full XML imageset for the specified Imageset to the given\n\
                    OutStream.\n\
            \n\
                @param imageset\n\
                    String holding the name of the Imageset to be written to the stream.\n\
            \n\
                @param out_stream\n\
                    OutStream (std.ostream based) object where data is to be sent.\n\
            \n\
                @return\n\
                    Nothing.\n\
                *\n" );
        
        }
        { //::CEGUI::EventSet::fireEvent
        
            typedef void ( ::CEGUI::EventSet::*fireEvent_function_type )( ::CEGUI::String const &,::CEGUI::EventArgs &,::CEGUI::String const & ) ;
            typedef void ( ImagesetManager_wrapper::*default_fireEvent_function_type )( ::CEGUI::String const &,::CEGUI::EventArgs &,::CEGUI::String const & ) ;
            
            ImagesetManager_exposer.def( 
                "fireEvent"
                , fireEvent_function_type(&::CEGUI::EventSet::fireEvent)
                , default_fireEvent_function_type(&ImagesetManager_wrapper::default_fireEvent)
                , ( bp::arg("name"), bp::arg("args"), bp::arg("eventNamespace")="" ) );
        
        }
        { //::CEGUI::EventSet::subscribeScriptedEvent
        
            typedef ::CEGUI::RefCounted< CEGUI::BoundSlot > ( ::CEGUI::EventSet::*subscribeScriptedEvent_function_type )( ::CEGUI::String const &,::CEGUI::String const & ) ;
            typedef ::CEGUI::RefCounted< CEGUI::BoundSlot > ( ImagesetManager_wrapper::*default_subscribeScriptedEvent_function_type )( ::CEGUI::String const &,::CEGUI::String const & ) ;
            
            ImagesetManager_exposer.def( 
                "subscribeScriptedEvent"
                , subscribeScriptedEvent_function_type(&::CEGUI::EventSet::subscribeScriptedEvent)
                , default_subscribeScriptedEvent_function_type(&ImagesetManager_wrapper::default_subscribeScriptedEvent)
                , ( bp::arg("name"), bp::arg("subscriber_name") ) );
        
        }
        { //::CEGUI::EventSet::subscribeScriptedEvent
        
            typedef ::CEGUI::RefCounted< CEGUI::BoundSlot > ( ::CEGUI::EventSet::*subscribeScriptedEvent_function_type )( ::CEGUI::String const &,unsigned int,::CEGUI::String const & ) ;
            typedef ::CEGUI::RefCounted< CEGUI::BoundSlot > ( ImagesetManager_wrapper::*default_subscribeScriptedEvent_function_type )( ::CEGUI::String const &,unsigned int,::CEGUI::String const & ) ;
            
            ImagesetManager_exposer.def( 
                "subscribeScriptedEvent"
                , subscribeScriptedEvent_function_type(&::CEGUI::EventSet::subscribeScriptedEvent)
                , default_subscribeScriptedEvent_function_type(&ImagesetManager_wrapper::default_subscribeScriptedEvent)
                , ( bp::arg("name"), bp::arg("group"), bp::arg("subscriber_name") ) );
        
        }
    }

}