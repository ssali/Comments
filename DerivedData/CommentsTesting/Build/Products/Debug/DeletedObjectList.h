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

@class DeletedObject;

/*!
 @class DeletedObjectList

 @abstract DeletedObjectList class contains the list of all deleted items.

 @discussion DeletedObjectList class provide the methods to fetch/insert items from recyclebin.
 */

@interface DeletedObjectList : ResourceList
{
	NSInteger			_totalItems;
}

@property (nonatomic) NSInteger totalItems;

/**
 * This method will be used to add an item into the resource list.
 * @param deletedObject Item which is to be added into the list
 **/
- (void) addDeletedObject: (DeletedObject*) deletedObject;

/**
 * This method returns the Deleted item as per the given index from the resource list.
 * @param index Position of the Item in DeletedObject list.
 * @result Returns Deleted object from the DeletedObject list.
 **/
- (DeletedObject*) deletedObjectAtIndex: (uint) index;

@end
