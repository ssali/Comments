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
#import "Defines.h"

@class ResRepresentation;
@protocol ResourceMarshaller <NSObject>

- (BOOL) unmarshall: (ResRepresentation*) data;
- (ResRepresentation*) marshall;

@end

#pragma mark -
/*!
 @class Resource

 @abstract Resource class is designed to hold the common data among all resources.

 @discussion This class keeps a dictionary for headers and identify the resource type.

 */
@interface Resource : NSObject <ResourceMarshaller>
{
    ResourceType        _type;
    NSString*           _name;
    NSString*           _uri;
    NSString*           _eTag;
    
    NSDictionary*       _headers;
}

/**
 * Get/Set the resource type.
 */
@property (nonatomic, assign)   ResourceType    type;

/**
 * Get/Set the resource URI.
 */
@property (nonatomic, copy)     NSString*       uri;

/**
 * Get/Set the Resource Name.
 */
@property (nonatomic, copy)     NSString*       name;

/**
 * Get/Set the Resource eTag.
 */
@property (nonatomic, copy)     NSString*       eTag;


/**
 * Get/Set the headers.
 */
@property (nonatomic, retain)   NSDictionary* headers;

/**
 * It is used to return the resource's content-type according to enum ResourceType.
 * @result Returns the resource's Content-Type header value.
 */
- (NSString*) contentType;

/**
 * This method is used to determine the resource representation.
 * @param representation Resource Representation i.e. XML, JSON etc.
 * @result Returns the appropriate representation as per the given representation value.
 */
- (NSString*) resRepresentation: (E_ResRepresentation) representation;

@end
