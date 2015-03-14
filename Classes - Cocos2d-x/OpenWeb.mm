//
//  OpenWeb.m
//  MyGame
//
//  Created by 向仁 陈 on 3/11/15.
//
//

#include "OpenWeb.h"
#include "OpenWeb_objc.h"

void OpenWeb::OpenCata()
{
    OpenWebObjc *message = [[OpenWebObjc alloc] init];
    [message OpenCata];
    [message release];
}

void OpenWeb::OpenOrder()
{
    OpenWebObjc *message = [[OpenWebObjc alloc] init];
    [message OpenOrder];
    [message release];
}
