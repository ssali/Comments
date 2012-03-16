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

@class File;
@class Container;

/*!
 @class FileList

 @abstract FileList class contains the list of all files and containers.

 @discussion FileList class provide the methods to add/retrieve File and Container object from the list.
 */

@interface FileList : ResourceList
{
	NSInteger			_totalItems;
}

@property (nonatomic) NSInteger totalItems;
/**
 * This method will be used to add a File into the file list.
 * @param file File which is to be added into the list
 **/
- (void) addFile: (File*) file;

/**
 * This method returns the File at the given index.
 * @param index Position of the file in file list.
 * @result Returns File object from the file list.
 **/
- (File*) fileAtIndex: (uint) index;

/**
 * This method will be used to add a container into the file list.
 * @param cotainer Container which is to be added into the file list
 **/
- (void) addContainer: (Container*) cotainer;

/**
 * This method returns the container at the given index.
 * @param index Position of the container in file list.
 * @result Returns Container object from the file list.
 **/
- (Container*) containerAtIndex: (uint) index;

@end
