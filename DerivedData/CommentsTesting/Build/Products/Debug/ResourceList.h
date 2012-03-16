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
 @class ResourceList

 @abstract ResourceList class contains all resources.

 @discussion ResourceList class provide the methods to add/retrieve the resources from the resource list.
 */

@interface ResourceList : Resource
{
    NSMutableArray* _resourceList;                // hold the list of all resources
}

/**
 * Get/Set the the resource list.
 */
@property (nonatomic, retain) NSMutableArray*   resourceList;

/**
 * This method is used to fetch the desired resource from list.
 * @param index Index of object which we want to fetch.
 * @result Return the resource from the list according to given index.
 **/
- (Resource*) resoureAtIndex: (uint) index;

/**
 * This method is used to add resource to the list.
 * @param resource Resource which is to be added into the list.
 **/
- (void) addResource: (Resource*) resource;

@end
