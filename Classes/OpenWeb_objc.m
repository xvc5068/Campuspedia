//
//  OpenWeb_objc.m
//  MyGame
//
//  Created by 向仁 陈 on 3/11/15.
//
//

#import "OpenWeb_objc.h"

@implementation OpenWebObjc
-(void) OpenCata {
    NSURL * url = [NSURL URLWithString:@"https://itunes.apple.com/us/app/cata/id347359554?mt=8"];
    [[UIApplication sharedApplication] openURL: url];
}

-(void) OpenOrder {
    NSURL * url = [NSURL URLWithString:@"https://itunes.apple.com/us/app/orderup-mobile/id685051001?mt=8"];
    [[UIApplication sharedApplication] openURL: url];
}

@end