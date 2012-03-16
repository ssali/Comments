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
 @class Tag

 @abstract Tag class is designed to keep track of all tags url.

 @discussion Tag is used to get and set the tag data.
 */
@class FileList;
@interface Tag : Resource
{
    FileList*       _objects;
	NSString*		_objectUri;
}

/**
 * Get/Set the tag list i.e. the list of tags applied to resources (Files or Containers).
 */
@property (nonatomic, retain) FileList*     objects;
@property (nonatomic, copy) NSString*		objectUri;

@end
