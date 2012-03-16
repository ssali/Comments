//
//  Container2.h
//  csplib
//
//  Created by Shreyas Sali on 3/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ResourceData.h"

@class FileList;
@class TagList;
@class MetaDataList;
@class CommentList;

/*!
 @class Container
 
 @abstract Container class is designed to hold the container detail.
 
 @discussion This is an example that illustrates basic use of the Container class...
 
 */

@interface Container2 : ResourceData
{
    u_int64_t           _resourceSize;
    u_int64_t           _accessed;
    NSUInteger          _version;
    
    FileList*           _contents;
    TagList*            _tags;
    MetaDataList*       _metadataList;
    CommentList*        _commentList;
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
 * Get/Set the metadata list applied to a file or container.
 */
@property (nonatomic, retain) CommentList* commentList;

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
