//
//  Bugtags/Bugtags.h
//
//  Contains:   API for using Bugtags's SDK.
//
//  Version:    1.3.1
//
//  Created by Bugtags on 2015-08-01.
//
//  Copyright (c) 2016 Bugtags, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "BTGConstants.h"

/**
 * The options used to customize the Bugtags initialization
 */
@interface BugtagsOptions : NSObject <NSCopying>

/**
 * Set whether to track the crashes in the app
 * Default = YES except debug whth USB connected
 */
@property(nonatomic, assign) BOOL trackingCrashes;

/**
 * Set whether to track the user's steps while using the app
 * Default = YES
 */
@property(nonatomic, assign) BOOL trackingUserSteps;

/**
 * Set whether to track the console logs while using the app
 * Default = YES
 */
@property(nonatomic, assign) BOOL trackingConsoleLog;

/**
 * Set whether to track the user's location while using the app
 * Default = YES
 */
@property(nonatomic, assign) BOOL trackingUserLocation;

/**
 * Set whether to track the network requests while using the app, support HTTP/HTTPS
 * Default = NO
 */
@property(nonatomic, assign) BOOL trackingNetwork;

/**
 * Set URLs or IPs for network tracking, combine multiple with '|', support Regular Expression
 * e.g., you can set 'bugtags.io|sample.io' to track the network request's url which contains 'bugtags.io' or 'sample.io'
 * Track all network requests if set to nil
 * Default = nil
 */
@property(nonatomic, copy) NSString *trackingNetworkURLFilter;

/**
 * Set whether to take a screenshot when the crash occurred
 * Default = NO
 */
@property(nonatomic, assign) BOOL crashWithScreenshot;

/**
 * Set whether to ignore the SIGPIPE crashes
 * Default = NO
 */
@property(nonatomic, assign) BOOL ignorePIPESignalCrash;

/**
 * Set whether to allow user to sign in Bugtags SDK
 * Default = YES
 */
@property(nonatomic, assign) BOOL enableUserSignIn;

/**
 * Set the app version
 * Get the version automatically if set to nil
 * Default = nil
 */
@property(nonatomic, copy) NSString *version;

/**
 * Set the app build
 * Get the build automatically if set to nil
 * Default = nil
 */
@property(nonatomic, copy) NSString *build;

@end

/**
 * The APIs for using Bugtags's SDK, for more details about the SDK integration, please visit https://docs.bugtags.io/start/integrate/ios/
 */
@interface Bugtags : NSObject

/**
 * Start the Bugtags's SDK
 * @param appKey - The app key that identifies the app, you can find it on your dashboard
 * @param invocationEvent - The event that invocates the Bugtags form
 * @return none
 */
+ (void)startWithAppKey:(NSString *)appKey invocationEvent:(BTGInvocationEvent)invocationEvent;

/**
 * Start the Bugtags's SDK with options
 * @param appKey - The appKey that identifies the app, you can find it on your dashboard
 * @param invocationEvent - The event that invocates the Bugtags form
 * @param options - The options that use to customize the Bugtags initialization
 * @return none
 */
+ (void)startWithAppKey:(NSString *)appKey invocationEvent:(BTGInvocationEvent)invocationEvent options:(BugtagsOptions *)options;

/**
 * Set the event that invocates the Bugtags form
 * @param invocationEvent - invocationEvent
 * @return none
 */
+ (void)setInvocationEvent:(BTGInvocationEvent)invocationEvent;

/**
 * Get the current event
 * @return BTGInvocationEvent
 */
+ (BTGInvocationEvent)currentInvocationEvent;

/**
 * Add custom logs that will be sent with each report
 * @param format
 * @param ...
 * @return none
 */
FOUNDATION_EXPORT void BTGLog(NSString *format, ...) NS_FORMAT_FUNCTION(1, 2);

/**
 * Add custom logs that will be sent with each report，the same as BTGLog
 * @param content - log message
 * @return none
 */
+ (void)log:(NSString *)content;

/**
 * Set whether to track the crashes in the app
 * @param trackingCrashes - Default = YES
 * @return none
 */
+ (void)setTrackingCrashes:(BOOL)trackingCrashes;

/**
 * Set whether to track the user's steps while using the app
 * @param trackingUserSteps - Default = YES
 * @return none
 */
+ (void)setTrackingUserSteps:(BOOL)trackingUserSteps;

/**
 * Set whether to track the console logs while using the app
 * @param trackingConsoleLog - Default = YES
 * @return none
 */
+ (void)setTrackingConsoleLog:(BOOL)trackingConsoleLog;

/**
 * Set whether to track the user's location while using the app
 * @param trackingUserLocation - Default = YES
 * @return none
 */
+ (void)setTrackingUserLocation:(BOOL)trackingUserLocation;

/**
 * Set whether to track the network requests while using the app, support HTTP/HTTPS
 * @param trackingNetwork - Default = NO
 * @return none
 */
+ (void)setTrackingNetwork:(BOOL)trackingNetwork;

/**
 * Add custom user data that will be sent with each report
 * @param data
 * @param key
 * @return none
 */
+ (void)setUserData:(NSString *)data forKey:(NSString *)key;

/**
 * Remove user data with key
 * @param key
 * @return none
 */
+ (void)removeUserDataForKey:(NSString *)key;

/**
 * Remove all user data
 * @return none
 */
+ (void)removeAllUserData;

/**
 * Manually report an exception
 * @param exception
 * @return none
 */
+ (void)sendException:(NSException *)exception;

/**
 * Manually report a feedback
 * @param content - feedback content
 * @return none
 */
+ (void)sendFeedback:(NSString *)content;

/**
 * Set the block that be executed before the report sending
 * @param callback
 * @return none
 */
+ (void)setBeforeSendingCallback:(void (^)(void))callback;

/**
 * Set the block that be executed after the report sent successfully
 * @param callback
 * @return none
 */
+ (void)setAfterSendingCallback:(void (^)(void))callback;

/**
 * Set whether to upload data only via WiFi
 * @param onlyViaWiFi - Default = NO
 */
+ (void)setUploadDataOnlyViaWiFi:(BOOL)onlyViaWiFi;

/**
 * Manually invocate the Bugtags form
 * @return none
 */
+ (void)invoke;

/**
 * Register a plugin
 * @param plugin
 * @return successful - YES，failed - NO
 */
+ (BOOL)registerPlugin:(id)plugin;

/**
 * Unregister a plugin
 * @param plugin
 */
+ (void)unregisterPlugin:(id)plugin;

@end