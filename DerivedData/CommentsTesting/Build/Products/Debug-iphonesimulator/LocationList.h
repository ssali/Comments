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

@class Location;

/*!
 @class LocationList

 @abstract LocationList class contains the list of all Location(s).

 @discussion LocationList class provide the methods to add/retrieve locations from the LocationList.
 */

@interface LocationList : ResourceList
{

}

/**
 * This method will be used to add a Location into the LocationList.
 * @param location Location object which is to be added into the list
 **/
- (void) addLocation: (Location*) location;

/**
 * This method returns the location at the given index.
 * @param index Position of the location in location list.
 * @result Returns Location object from the LocationList.
 **/
- (Location*) locationAtIndex: (uint) index;

@end
