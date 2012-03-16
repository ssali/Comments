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
#import "ResourceList.h"

@class Permission;

/*!
 @class PermissionList

 @abstract PermissionList class contains the list of permissions of File or Container.

 @discussion PermissionList class provide the methods to add/retrieve permissions from the permission list.
 */

@interface PermissionList : ResourceList
{

}

/**
 * This method will be used to add a permission into the permission list.
 * @param permission Permission object which is to be added into the list
 **/
- (void) addPermission: (Permission*) permission;

/**
 * This method returns the permission at the given index.
 * @param index Position of the permission in permission list.
 * @result Returns permission object from the permission list.
 **/
- (Permission*) permissionAtIndex: (uint) index;

@end
