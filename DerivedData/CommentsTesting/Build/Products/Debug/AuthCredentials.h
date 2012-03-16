/* Copyright 2011 Mezeo Software Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

/*!
 @class AuthCredentials

 @abstract AuthCredentials class takes user credentials from BasicAuthCredentials class.

 @discussion AuthCredentials class accept the user credentials and encode them using base64 encoding.
 */

@interface AuthCredentials : NSObject
{
    NSString*           _apiKey;
    NSString*           _username;
    NSString*           _password;
}

/**
 * Get/Set the User Name.
 */
@property (copy) NSString* username;

/**
 * Get/Set the password.
 */
@property (copy) NSString* password;

/**
 * Get/Set the apikey.
 */
@property (copy) NSString* apiKey;

/**
 * This method is used to initialize the AuthCredentials class and it will be called internally from BasicAuthCredentials class.
 * @param user UserID
 * @param password Password
 * @param apiKey API key
 * @result Return the AuthCredentials instance.
 **/
- (id) initWithCredentials: (NSString*) user password: (NSString*) password apiKey: (NSString*) apiKey;

/**
 * This method will encode the userID and password into base64 encoding.
 * @result Returns base64 encoded string.
 **/
- (NSString*) headerValue;

@end
