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

@class MetaData;

/*!
 @class MetaDataList

 @abstract MetaDataList class contains the list of metadata.

 @discussion MetaDataList class provide the methods to add/retrieve metadata from the metadata list.
 */

@interface MetaDataList : ResourceList
{

}

/**
 * This method will be used to add a metadata into the metadata list.
 * @param metadata MetaData which is to be added into the list
 **/
- (void) addMetaData: (MetaData*) metadata;

/**
 * This method returns the MetaData at the given index.
 * @param index Position of the metadata in metadata list.
 * @result Returns MetaData object from the metadata list.
 **/
- (MetaData*) metaDataAtIndex: (uint) index;

@end
