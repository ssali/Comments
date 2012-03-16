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

@class Tag;

/*!
 @class TagList

 @abstract TagList class contains the list of all tags applied to File or Container.

 @discussion TagList class provide the methods to add/retrieve the tags from the tag list.
 */

@interface TagList : ResourceList
{

}

/**
 * This method will be used to add a tag into the tag list.
 * @param tag Tag object which is to be added into the list
 **/
- (void) addTag: (Tag*) tag;

/**
 * This method returns the tag at the given index.
 * @param index Position of the tag in tag list.
 * @result Returns Tag object from the Tag list.
 **/
- (Tag*) tagAtIndex: (uint) index;

@end
