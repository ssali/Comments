//
//  File2.h
//  csplib
//
//  Created by Shreyas Sali on 3/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Container2.h"

@interface File2 : Container2
{
    NSString*           _commentUrl;
    NSString*           _mimeType;
    NSString*           _thumbnailUrl;
    NSString*           _contentUrl;
	NSString*			_filePath;
	
    BOOL                _publicFile;
    BOOL                _cached;
	
	NSString*			_localFileName;
}

/**
 * Get/Set the comment URL of File resource.
 */
@property (copy) NSString* commentUrl;

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
