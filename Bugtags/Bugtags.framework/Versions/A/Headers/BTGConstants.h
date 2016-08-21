//
//  Bugtags/BTGConstants.h
//
//  Created by Bugtags on 2015-08-01.
//
//  Copyright (c) 2016 Bugtags, Inc. All rights reserved.
//

#ifndef Bugtags_BTGConstants_h
#define Bugtags_BTGConstants_h

/**
 * The event used to invocate the Bugtags form
 */
typedef NS_ENUM(NSInteger, BTGInvocationEvent) {
    
    // No event will be set, only report crash automatically,
    // you can invocate the Bugtags form by calling the method [Bugtags invoke]
    BTGInvocationEventNone,
    
    // Shake the device to invocate the Bugtags form
    BTGInvocationEventShake,
    
    // Show a floating button on top of all views, press it to invocate the Bugtags form
    BTGInvocationEventBubble
};

#endif