#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("My Game");
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    auto fileUtils = FileUtils::getInstance();
    auto screenSize = glview->getFrameSize();
    std::vector<std::string> resDirOrders;
    
    // check which assets the devices requires
    if ( 2208 == screenSize.width || 2208 == screenSize.height )
    {
        resDirOrders.push_back("iphone6+");
        resDirOrders.push_back("iphone6");
        glview->setDesignResolutionSize(2208, 1242, ResolutionPolicy::NO_BORDER);
    }
    else if ( 1334 == screenSize.width || 1334 == screenSize.height )
    {
        resDirOrders.push_back("iphone6");
        glview->setDesignResolutionSize(1334, 750, ResolutionPolicy::NO_BORDER);
    }
    /*
    else if ( 1136 == screenSize.width || 1136 == screenSize.height )
    {
        resDirOrders.push_back("iphone5");
        glview->setDesignResolutionSize(1136, 640, ResolutionPolicy::NO_BORDER);

    }*/
    /*
    else
    {
        resDirOrders.push_back("iphone");
        glview->setDesignResolutionSize(480, 320, ResolutionPolicy::NO_BORDER);
    }*/
    
    fileUtils->setSearchPaths(resDirOrders);

    // create a scene. it's an autorelease object
    auto scene = HelloWorld::createScene();
    
    // run
    director->runWithScene(scene);
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
