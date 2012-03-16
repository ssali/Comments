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
#import "Container.h"

/*!
 @class File

 @abstract File class hold the information of file.

 @discussion File class is used to get/set file data.
 */
@interface File : Container
{
    NSString*           _mimeType;
    NSString*           _thumbnailUrl;
    NSString*           _contentUrl;
	NSString*			_filePath;
	
    BOOL                _publicFile;
    BOOL                _cached;
	
	NSString*			_localFileName;
}

/**
 * Get/Set the mime type of file.
 */
@property (copy) NSString* mimeType;

/**
 * Get/Set the thumbnail URL of File resource.
 */
@property (copy) NSString* thumbnailUrl;

/**
 * Content URL of File resource.
 *
 * Use this URL to get the file detail.
 */
@property (copy) NSString* contentUrl;

/**
 * Get/Set the cached status whether the file has been cached or not.
 */
@property (nonatomic, getter=isCached) BOOL cached;

/**
 * Get/Set the file publish status whether the file has to be published or not.
 */
@property (nonatomic, getter=isPublicFile) BOOL  publicFile;

/**
 * Get/Set the file path.
 */
@property (nonatomic, copy) NSString*  filePath;

/**
 * Get/Set the file path.
 */
@property (nonatomic, copy) NSString*  localFileName;

@end
