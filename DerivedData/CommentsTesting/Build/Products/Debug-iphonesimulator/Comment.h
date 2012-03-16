//
//  Comment.h
//  csplib
//
//  Created by Shreyas Sali on 3/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Resource.h"

/*!
 @class Comment
 
 @abstract Comment class is designed to hold the comment detail.
 
 @discussion Comment class is used to get and set the Comment value.
 */


@interface Comment : Resource
{
    NSString*     _commentValue;
    NSString*     _username;
    NSString*     _email;
    NSDate*       _creationDate;    
}


//Get/Set the comment details applied to a File or Container resource.
@property (copy) NSString* commentValue;


//Get/Set the current logged in user name.
@property (copy) NSString*  username;


//Get/Set the Contact's Email Address.
@property (copy) NSString* email;


//Get/Set the information when a file or container was created.
@property (retain) NSDate* creationDate;


@end


