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
#import "ResourceData.h"

@class FileList;
@class TagList;
@class MetaDataList;

/*!
 @class Container

 @abstract Container class is designed to hold the container detail.

 @discussion This is an example that illustrates basic use of the Container class...

 */

@interface Container : ResourceData
{
    u_int64_t           _resourceSize;
    u_int64_t           _accessed;
    NSUInteger          _version;

    FileList*           _contents;
    TagList*            _tags;
    MetaDataList*       _metadataList;
    NSString*           _parentUrl;

    NSDate*             _creationDate;
    NSDate*             _lastModifiedDate;
}

/**
 * Get/Set the contents of a container i.e. list of files and contaienrs.
 */
@property (nonatomic, retain) FileList* contents;

/**
 * Get/Set the tag list applied to files or containers.
 */
@property (nonatomic, retain) TagList* tags;

/**
 * Get/Set the metadata list applied to a file or container.
 */
@property (nonatomic, retain) MetaDataList* metadataList;

/**
 * Get/Set the parent Url of a file or container.
 */
@property (copy) NSString* parentUrl;

/**
 * Get/Set the size of a file or container.
 */
@property (nonatomic) u_int64_t resourceSize;

/**
 * Get/Set the time when the resource was last accessed.
 */
@property (nonatomic) u_int64_t accessed;

/**
 * Get/Set the version number.
 */
@property (nonatomic) NSUInteger version;

/**
 * Get/Set the information when a file or container was created.
 */
@property (retain) NSDate* creationDate;

/**
 * Get/Set the date of last modification of a file or container.
 */
@property (retain) NSDate* lastModifiedDate;

@end
