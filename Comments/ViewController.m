//
//  ViewController.m
//  Comments
//
//  Created by Shreyas Sali on 3/1/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ViewController.h"
#import "BasicAuthCredentials.h"
#import "Header.h"
#import "MetaData.h"
#import "Service.h"
#import "File.h"
#import "Comment.h"
#import "File2.h"
#import "CommentList.h"

@implementation ViewController

@synthesize nameTextField;
@synthesize responseTextView;
@synthesize receivedData;




- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Release any cached data, images, etc that aren't in use.
}


- (IBAction)makeRequest
{
    [self addComment];
}



- (IBAction)makeRequestforcomment
{
    [self addCommentWithCommentAPI];
}


- (void)addComment
{
    Service* service = [self getService];
    mezeoTargetObj = [[File alloc]init];
    //name, url are in Resource class
    //file is dervied from Container is derived from Resource data is derived from 
    //resource
    
    mezeoTargetObj.name = @"testFile1330460627.27";
    mezeoTargetObj.uri = @"https://41.mezeo.net/v2/files/Zjc1OWRlMGIzMTMyMWJjM2ExZTExZWQ3NjRlYTk4MjM5";
    
    MetaData* mdata = (MetaData*)[service createNewResourceOfType: METADATA_RES];
    mdata.name      = mezeoTargetObj.name;
    
    NSDate* currentDate     = [NSDate date];
    double time             = [currentDate timeIntervalSince1970];
    NSNumber* num = [NSNumber numberWithDouble: time];
    NSString* date = [num stringValue];
    finalString   = [NSString stringWithFormat: @"%@||%@||%@", @"test1", date, nameTextField.text];
    
    mdata.value = [finalString dataUsingEncoding: NSUTF8StringEncoding];
    mdata.uri   = [NSString stringWithFormat: @"%@/metadata/%@", mezeoTargetObj.uri, date];
    mdata.headers = [NSDictionary dictionaryWithObjectsAndKeys: @"1", @"X-Cloud-Depth", nil];
    [service put_resourceAsynchronously: mdata delegate: self startImmediately: YES];    
}


- (void)addCommentWithCommentAPI
{ 
    Service* service = [self getService];
    mezeoTargetObj2 = [[File2 alloc]init];
    mezeoTargetObj2.name = @"testFile1330460627.27";
    mezeoTargetObj2.uri = @"https://41.mezeo.net/v2/files/Zjc1OWRlMGIzMTMyMWJjM2ExZTExZWQ3NjRlYTk4MjM5";
    
    Comment* commentdata = (Comment*)[service createNewResourceOfType: COMMENT_RES];
    
    commentdata.commentValue = nameTextField.text;
    
    commentdata.uri   = [NSString stringWithFormat: @"%@/comments", mezeoTargetObj2.uri];
    commentdata.headers = [NSDictionary dictionaryWithObjectsAndKeys: @"1", @"X-Cloud-Depth", nil];
    [service post_resourceAsynchronously:commentdata destinationUrl:commentdata.uri delegate:self startImmediately:YES];
    
    //[service post__resourceAsynchronously: commentdata destinationUrl: commentdata.uri delegate: self startImmediately: YES];	
    //[service post_resource: commentdata.uri resource:commentdata];
}


- (void)fetchComments: (Resource*)resource
{
    Service* service1 = [self getService];
 
    mezeoTargetObj2 = (File2*)[service1 createNewResourceOfType:FILE2_RES];

    mezeoTargetObj2.uri = @"https://41.mezeo.net/v2/files/Zjc1OWRlMGIzMTMyMWJjM2ExZTExZWQ3NjRlYTk4MjM5";
    [service1 get_resource:mezeoTargetObj2];
    NSLog(@"%@", mezeoTargetObj2.commentUrl);
     NSLog(@"%@", mezeoTargetObj2.contentUrl);
    
    CommentList* comm = (CommentList*)[service1 createNewResourceOfType:COMMENT_LIST_RES];
    comm.uri = mezeoTargetObj2.commentUrl;
    comm.headers = [NSDictionary dictionaryWithObjectsAndKeys: @"2", @"X-Cloud-Depth", nil];
   
    [service1 get_resource:comm];
   
    for(int i = 0; i < [comm.resourceList count]; ++i)
    {
        Comment* cdata = [comm.resourceList objectAtIndex: i];
        NSLog(@"Comment DATA: %@", cdata);
       // responseTextView.text = cdata.commentValue;
        responseTextView.text = cdata.username;
    }

}





#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
	[super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
	[super viewDidDisappear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}


- (void)dealloc
{
    
}


- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    self.nameTextField = nil;
    self.responseTextView = nil;
    self.receivedData = nil;
    // e.g. self.myOutlet = nil;
}


#pragma mark -
#pragma mark NSURLConnection Callbacks
// Connection response.
- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response
{

}
// You got data.
- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data
{

}
// Sorry Dude, connection failed gloriously.
- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error
{

}
// Finally the data is completely loaded.
- (void)connectionDidFinishLoading:(NSURLConnection *)connection
{
  
}

- (Service*) getService 
{	
	AuthCredentials* credential = [[BasicAuthCredentials alloc] initWithCredentials: @"test1"  password: @"mezeo" apiKey: MEZEOAPIKEY];
	return [[Service alloc] init: credential userAgent: USERAGENT clientSpecification: 2 serverURL: @"https://41.mezeo.net/v2"];
}

#pragma mark 
#pragma mark ServiceDelegate Methods


-(void)service:(Service*)service willSendRequest:(NSURLRequest*)request {

    }

-(void)service:(Service*)service didStartRequest:(NSURLRequest*)request
{
    
}

-(void)service:(Service*)service willStartDownloadWithContentLength:(uint64_t)contentLength 
{
    
}

-(void)service:(Service*)service didReceiveData:(NSData*)data 
{
    
}

-(void)service:(Service*)service didFailWithError:(NSError*)error 
{
	
}

-(void)serviceDidCancel:(Service*)service 
{
    
}

-(void)serviceDidFinishDownloading:(Service*)service 
{
    
}

-(void)serviceDidFinish:(Service*)service_obj 
{
    NSHTTPURLResponse* res = (NSHTTPURLResponse*)service_obj.httpResponse;
    NSLog(@"%d", [res statusCode]);
    [nameTextField resignFirstResponder];
    [nameTextField setText:@""];
    [self fetchComments:service_obj.resource];
   
}


@end
