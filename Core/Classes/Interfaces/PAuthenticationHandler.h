//
//  PAuthenticationHandler.h
//  Pods
//
//  Created by Benjamin Smiley-andrews on 12/11/2016.
//
//

#ifndef PAuthenticationHandler_h
#define PAuthenticationHandler_h

#import <RXPromise/RXPromise.h>
#import <ChatSDK/BAccountTypes.h>

#import "BAccountTypes.h"

@protocol PAuthenticationHandler <NSObject>

/**
 * @brief Check to see if the user is already authenticated
 */
-(RXPromise *) authenticateWithCachedToken;

/**
 * @brief Authenticate with Firebase
 */
-(RXPromise *) authenticateWithDictionary: (NSDictionary *) details;

/**
 * @brief Checks whether the user has been authenticated this session
 */
-(BOOL) userAuthenticated;

/**
 * @brief Logout the user from the current account
 */
-(RXPromise *) logout;

/**
 * @brief Says which networks are available this can be setup in bFirebaseDefines
 * if you set the API key to @"" for Twitter Facebook or Google then it's automatically
 * disabled
 */
-(BOOL) accountTypeEnabled: (bAccountType) type;

/**
 * @brief Get the user's stored login credentials
 */
-(NSDictionary *) loginInfo;

/**
 * @brief Set the user's stored login credentials
 */
-(void) setLoginInfo: (NSDictionary *) info;

/**
 * @brief Get the current user's authentication id
 */
-(NSString *) currentUserEntityID;

/**
 * @brief The view controller that should be displayed when the user isn't logged in 
 */
-(UIViewController *) challengeViewController;
-(void) setChallengeViewController: (UIViewController *) viewController;

@end

#endif /* PAuthenticationHandler_h */
