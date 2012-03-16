//
//  ViewController.h
//  Comments
//
//  Created by Shreyas Sali on 3/1/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@class Service;
@class File;
@class File2;

@interface ViewController : UIViewController
{
    UITextField             *nameTextField;
    UITextView              *responseTextView;
    NSMutableData           *receivedData;
    NSString*               finalString;
    File*                   mezeoTargetObj;
    File2*                  mezeoTargetObj2;
    NSMutableArray*         chatArray;
}

@property (nonatomic, retain) IBOutlet UITextField *nameTextField;
@property (nonatomic, retain) IBOutlet UITextView *responseTextView;
@property (nonatomic, retain) NSMutableData *receivedData;

- (IBAction) makeRequest;
- (IBAction)makeRequestforcomment;
- (Service*) getService;
- (void)addComment;
- (void)addCommentWithCommentAPI; 

@end
