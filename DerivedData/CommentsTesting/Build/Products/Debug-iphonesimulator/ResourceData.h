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

@class PermissionList;

/*!
 @class ResourceData

 @abstract ResourceData class contains the common data among File, Container and Project resources.

 @discussion ResourceData class is used to get and set the File, Container and Project data.
 */

@interface ResourceData : Resource
{
    NSString*           _owner;
    PermissionList*     _permissions;
    ItemType            _itemType;
    BOOL                _shared;
    BOOL                _inProject;
}

/**
 * Get/Set the value of resource owner.
 */
@property (copy) NSString* owner;

/**
 * Get/Set the Permissions URL. Use this URL to get the permission list from server.
 */
@property (nonatomic, retain) PermissionList* permissions;

/**
 * Get/Set the resource type whether it is a File or Container.
 */
@property (nonatomic) ItemType itemType;

/**
 * Get/Set the resource shared status to determine whether the resource is shared or not.
 */
@property (nonatomic, getter=isShared) BOOL shared;

/**
 * Get/Set the status to determine whether the resource is assigned to project or not.
 */
@property (nonatomic, getter=isProject) BOOL inProject;

@end
