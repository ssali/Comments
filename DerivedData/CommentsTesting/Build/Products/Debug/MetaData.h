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
 @class MetaData

 @abstract MetaData class is designed to hold the metadata detail.

 @discussion MetaData class is used to get and set the metadata value.
 */

@interface MetaData : Resource
{
    NSData*     _value;
}

/**
 * Get/Set the metadata value applied to a File or Container resource.
 *
 * To set the metadata value you need to convert first into NSData whatever type of data you want to set.
 *
 * Similarly to get metadata you need to convert back into appropriate type.
 */
@property (nonatomic, retain) NSData*   value;

@end
