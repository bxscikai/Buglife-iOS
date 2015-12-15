//
//  Buglife.h
//  Buglife
//
//  Copyright (c) 2016 Buglife, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, LIFEInvocationOptions) {
    LIFEInvocationOptionsNone             = 0,
    LIFEInvocationOptionsShake            = 1 << 0,
    LIFEInvocationOptionsScreenshot       = 1 << 1,
    LIFEInvocationOptionsFloatingButton   = 1 << 2
};

/**
 *  Buglife. Handles initialization and configuration of Buglife.
 */
@interface Buglife : NSObject

/**
 *  A mask of options specifying the way(s) that the Buglife bug reporter window
 *  can be invoked.
 *
 *  You may choose to support multiple invocation options, e.g.:
 *
 *    [Buglife sharedBuglife].invocationOptions = LIFEInvocationOptionsShake | LIFEInvocationOptionsFloatingButton;
 *
 *  This returns LIFEInvocationOptionsFloatingButton by default. We recommend the default
 *  option as-is for internal / dogfood builds, as it unobtrusively encourages users to
 *  report bugs, and does not interrupt common flows such as screenshot capturing.
 *
 *  However for App Store builds, we recommend LIFEInvocationOptionsNone. Instead,
 *  we recommend putting a button / selectable table row somewhere in your in-app settings/menu,
 *  and calling -presentReporter explicitly.
 */
@property (nonatomic) LIFEInvocationOptions invocationOptions;

/**
 *  Default shared initializer that returns the Buglife singleton.
 *
 *  @return The shared Buglife singleton
 */
+ (nonnull instancetype)sharedBuglife;

/**
 *  Enables Buglife bug reporting within your app.
 *
 *  The recommended way to enable Buglife is to call this method
 *  in your app delegate's -application:didFinishLaunchingWithOptions: method.
 *  Don't worry, it won't impact your app's launch performance. 😉
 *
 *  @param apiKey The Buglife API Key for this app
 */
- (void)startWithAPIKey:(nonnull NSString *)apiKey;

/**
 *  Immediately takes a screenshot & presents the Buglife bug reporter view controller.
 *  This is useful for apps that wish to supplement or replace the default invocation
 *  options, i.e. by placing a custom bug report button in their app settings.
 */
- (void)presentReporter;

/**
 *  Sorry, Buglife is a singleton 😁
 *  Please use the shared initializer +[Buglife sharedBuglife]
 */
- (nullable instancetype)init NS_UNAVAILABLE;

@end
