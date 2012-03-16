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
 @class UserAccount

 @abstract UserAccount class keeps the account detail like how much space has been used and how much is free.

 @discussion This class will hold all the account information for each individual user.
 */
@interface UserAccount : Resource
{
    NSString*       _userName;
	NSString*		_accountType;
    uint64_t        _storageAllocated;
    uint64_t        _storageUsed;

    uint64_t        _bandwidthAllocated;
    uint64_t        _bandwidthTotal;
    uint64_t        _bandwidthPrivate;
    uint64_t        _bandwidthPublic;
}

/**
 * Get/Set the current logged in user name.
 */
@property (copy) NSString*  userName;

/**
 * Get/Set the current logged in Account Type.
 */
@property (copy) NSString*  accountType;

/**
 * Get/Set the total storage space allocated to current logged in user.
 */
@property (nonatomic) uint64_t  storageAllocated;

/**
 * Get/Set the total storage space which has been used by the user.
 */
@property (nonatomic) uint64_t  storageUsed;

/**
 * The bandwidth allocated.
 */
@property (nonatomic) uint64_t  bandwidthAllocated;

/**
 * The total bandwidth.
 */
@property (nonatomic) uint64_t  bandwidthTotal;

/**
 * The private bandwidth.
 */
@property (nonatomic) uint64_t  bandwidthPrivate;

/**
 * The public bandwidth.
 */
@property (nonatomic) uint64_t  bandwidthPublic;

@end
