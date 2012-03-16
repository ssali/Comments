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
#import "AuthCredentials.h"

/*!
 @class BasicAuthCredentials

 @abstract BasicAuthCredentials class is used to authenticate the user.

 @discussion BasicAuthCredentials class accept the user credentials and pass this info to AuthCredentials class.
 */

@interface BasicAuthCredentials : AuthCredentials
{

}

/**
 * This method is used to initialize BasicAuthCredentials class by using given user and password.
 * @param user UserID
 * @param password Password
 * @param apiKey API key
 * @result Return the BasicAuthCredentials instance.
 **/
- (id) initWithCredentials: (NSString*) user password: (NSString*) password apiKey: (NSString*) apiKey;

@end
