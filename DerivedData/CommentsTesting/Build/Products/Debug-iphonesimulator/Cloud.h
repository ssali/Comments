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
#import "LocationList.h"

@class Cloud;

/*!
 @class Cloud

 @abstract Cloud class is designed to keep the links for all mezeo resources.

 @discussion This class contains one static method sharedCloudInstance. Whenever you need to set the
             requests in order to get mezeo resources, you can access these by using the appropriate link
             through sharedCloudInstance method of Cloud class.

             Example: 
 
            NSString* rootContainerLink = [Cloud sharedCloudInstance].rootContainerLink;
*/

@interface Cloud : Resource
{
    NSString*       _rootContainerLink;
    NSString*       _contactsLink;
    NSString*       _sharesLink;
    NSString*       _accountLink;
    NSString*       _tagsLink;
    NSString*       _recyclebinLink;
    LocationList*   _locations;
}

/**
 * Get/Set the Root Container URL.
 */
@property (copy) NSString*  rootContainerLink;

/**
 * Get/Set the Contacts URL.
 */
@property (copy) NSString*  contactsLink;

/**
 * Get/Set the Shares URL.
 */
@property (copy) NSString*  sharesLink;

/**
 * Get/Set the Accounts URL.
 */
@property (copy) NSString*  accountLink;

/**
 * Get/Set the Tags URL.
 */
@property (copy) NSString*  tagsLink;

/**
 * Get/Set the Recyclebin URL.
 */
@property (copy) NSString*  recyclebinLink;

/**
 * Get/Set the Locations URL.
 */
@property (retain) LocationList*  locations;

/**
 * This method will be used to return the same Cloud instance throughout the application.
 * @result Cloud instance.
 **/
+ (Cloud*) sharedCloudInstance;

@end
