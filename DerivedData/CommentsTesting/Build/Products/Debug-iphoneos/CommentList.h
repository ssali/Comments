//
//  CommentList.h
//  csplib
//
//  Created by Shreyas Sali on 3/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ResourceList.h"

@class Comment;

/*!
 @class CommentList
 
 @abstract CommentList class contains the list of comments.
 
 @discussion CommentList class provide the methods to add/retrieve metadata from the metadata list.
 */

@interface CommentList : ResourceList
{
    
}

/**
 * This method will be used to add a comments into the comments list.
 * @param commentsvalue Comment which is to be added into the list
 **/
- (void) addComments: (Comment*) commentvalue;

/**
 * This method returns the Comments at the given index.
 * @param index Position of the comments in comment list.
 * @result Returns Comment object from the comment list.
 **/
- (Comment*) commentAtIndex: (uint) index;

@end
