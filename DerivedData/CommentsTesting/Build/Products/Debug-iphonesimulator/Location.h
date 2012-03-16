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
 @class Location

 @abstract Location class is designed to handle the Location resource.

 @discussion Location is responsible to maintain the information for Location resource.

 */
@interface Location : Resource
{
    NSString*       _rootContainerLink;
    NSString*       _managementLink;
}

/**
 * Get/Set the management uri for this location.
 */
@property (copy) NSString*  managementLink;

/**
 * Get/Set the container uri for this location.
 */
@property (copy) NSString*  rootContainerLink;

@end
