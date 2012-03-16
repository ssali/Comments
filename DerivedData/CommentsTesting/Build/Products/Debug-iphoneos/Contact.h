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
#import "Resource.h"

/*!
 @class Contact

 @abstract Contact class is designed to hold the contact detail.

 @discussion Contact class is used to get and set the contact data.
 */
@interface Contact : Resource
{
    NSString*           _firstName;
    NSString*           _lastName;
    NSString*           _email;
}

/**
 * Get/Set the Contact's First Name.
 */
@property (copy) NSString* firstName;

/**
 * Get/Set the Contact's Last Name.
 */
@property (copy) NSString* lastName;

/**
 * Get/Set the Contact's Email Address.
 */
@property (copy) NSString* email;

@end
