//
//  Cloud2.h
//  csplib
//
//  Created by Travis McLane on 12/2/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "Cloud.h"

@class Cloud;

/*!
 @class Cloud2
 
 @abstract Cloud2 class is designed to keep the links for all mezeo resources.
 
 @discussion This class contains one static method sharedCloudInstance. Whenever you need to set the
 requests in order to get mezeo resources, you can access these by using the appropriate link
 through sharedCloudInstance method of Cloud class.
 
 Example: 
 
 [requestObject setRequestProjectList: [Cloud sharedCloudInstance].rootContainerLink];
 */
@interface Cloud2 : Cloud
{
    NSString*            _namespaceLink;
}

/**
 * Get/Set the Namespace URL.
 */
@property (copy) NSString*  namespaceLink;


/**
 * It is used to return the resource's content-type according to enum ResourceType.
 * @result Returns the resource's Content-Type header value.
 */
- (NSString*) contentType;

/**
 * This method will be used to return the same Cloud instance throughout the application.
 * @result Cloud instance.
 **/
+ (Cloud*) sharedCloudInstance;


@end
