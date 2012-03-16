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
 @class DeletedObject

 @abstract DeletedObject class is designed to hold the deleted items data.

 @discussion DeletedObject is used to get and set the deleted items data.
 */
@interface DeletedObject : Resource
{
    uint64_t        _size;
    NSDate*         _trashedDate;
	ItemType        _itemType;
}

/**
 * Get/Set the size of the resource.
 */
@property (nonatomic) uint64_t size;

/**
 * Get/Set the trashed date when the resource was deleted.
 */
@property (retain) NSDate* trashedDate;

/**
* Get/Set the resource type whether it is a File or Container.
*/
@property (nonatomic) ItemType itemType;

@end
