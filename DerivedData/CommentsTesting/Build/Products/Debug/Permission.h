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
 @class Permission

 @abstract Permission class is designed to hold the permission detail of a resource.

 @discussion Permission class is used to get and set the permission data.
 */

@interface Permission : Resource
{
    NSString*       _grantee;
    NSString*       _expiration;
    NSString*       _permissionType;
    NSString*       _permissionUrl;
	NSString*       _comment;
}

/**
 * Get/Set the UserID to whom permissions are given.
 */
@property (copy) NSString*      grantee;

/**
 * Get/Set the expiration time of given permissions.
 */
@property (copy) NSString*      expiration;

/**
 * Get/Set the type i.e. what type of permissions has given. For e.g. r,rw..etc.
 */
@property (copy) NSString*      permissionType;

/**
 * Get/Set the permission URL.
 */
@property (copy) NSString*      permissionUrl;

/**
 * Get/Set the permission comment.
 */
@property (copy) NSString*      comment;


@end
