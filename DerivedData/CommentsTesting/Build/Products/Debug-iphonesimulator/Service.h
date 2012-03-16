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

/*!
 @class Service

 @abstract Service class establish the communication between client and server.

 @discussion Service class perform various operations like create, update and fetch resources from server.
 Client first need to initialize Service class because service will be used to execute the
 request for any resource. This class will be used to create a resource and provide the methods
 to perform the various operations on that resource like update, rename, delete, copy, move etc.

 Example:

Suppose you want to get the Cloud instance. Follow these steps to do it.

1. First create BasicAuthCredentials object using userID and password.
BasicAuthCredentials* credential = [[BasicAuthCredentials alloc] initWithCredentials: UserName
password: Password apiKey: ApiKey];

2. Now initialize Service class
Service* service = [[Service alloc] initWithCredentials: credential
userAgent: @"iPhone"
clientSpecification: 2];

3. Get Cloud instance
Cloud* cloud = (Cloud*)[service createNewResourceOfType: CLOUD_RES];
[cloud setUri: kServerURL];
[service get_resource: cloud];

After execution of get_resource method cloud will contain the link of all resources.

*/

@class AuthCredentials;
@class Resource;
@class HttpResponseData;
@protocol ServiceDelegate;
@interface Service : NSObject
{
	id<ServiceDelegate>		_delegate;
    AuthCredentials*        _credentials;
    E_ResRepresentation     _representation;

    NSInteger               _clientSpecification;
    NSString*               _userAgent;
    NSMutableURLRequest*    httpRequest;
	
	Resource*				_resource;
	NSMutableData*			_data;
	NSURLConnection*		urlConnection;
	NSHTTPURLResponse*		httpResponse;
	
	BOOL					isError;
	NSUInteger				transactionID;
    
    NSString*               _serverURL;
}

@property(nonatomic, retain) Resource* resource;
@property(readonly) BOOL isError;
@property(readonly) NSHTTPURLResponse* httpResponse;
@property(assign) NSUInteger transactionID;

/**
 * This method will be used to initialize the Service class.
 * @param credential Authentication detail needed to communicate with server.
 * @param userAgent Name of user agent which will be used for communication with server.
 * @param clientSpecification X-Client-Specification header value.
 * @result Service Instance.
 **/
- (id) initWithCredentials2: (AuthCredentials*) credential
userAgent: (NSString*) userAgent
clientSpecification: (NSInteger) clientSpecification;

/**
 * This method will be used to initialize the Service class.
 * @param credential Authentication detail needed to communicate with server.
 * @param userAgent Name of user agent which will be used for communication with server.
 * @param clientSpecification X-Client-Specification header value.
 * @result Service Instance.
 **/
- (id) init: (AuthCredentials*) credential
        userAgent: (NSString*) userAgent
        clientSpecification: (NSInteger) clientSpecification
        serverURL: (NSString*) serverURL;
    
/**
 * This method is used to set the resource representation i.e. XML, JSON etc.
 * @param representation Resource Representation value.
 **/
- (void) setResRepresentation: (E_ResRepresentation) representation;

/**
 * This method will be used to create a new resource of specified type i.e. Cloud, Account, File, Contact, Project etc.
 * @param type The type identify which resource is to be created.
 * @result Return Resource object as per the type.
 **/
- (Resource*) createNewResourceOfType: (ResourceType) type;

/**
 * This method will be used to return an initialized NSMutableURLRequest object.
 * @param resource Resource object used to set the request headers.
 * @param url URL for new request.
 * @param method Specify the request methods i.e. GET, POST, PUT,DELETE etc.
 * @param body The data which is to be set in request's setHttpBody: method.
 * @result NSMutableURLRequest instance.
 **/
- (NSMutableURLRequest*) getHttpRequest: (Resource*) resource url: (NSString*) url httpMethod: (NSString*) method body: (NSData*) data;

/**
 * This method is used to execute the request.
 * @param request Request object
 * @result HttpResponseData object containing the response data and httpResponse.
 **/
- (HttpResponseData*) sendRequest: (NSMutableURLRequest*) request;

/**
 * This method will be used to download the contents of specified resource.
 * @param resource Resource for which the data is to be downloaded from server.
 * @result E_ResponseCode Returns the following response code.

 HTTP_SUCCESS if resource is parsed successfully.

 HTTP_BAD_REQUEST if resource url is not found.

 HTTP_UNKNOWN_ERROR if server side error.
 **/
- (E_ResponseCode) get_resource: (Resource*) resource;

/**
 * This method will be used to perform the operations like upload a file, move file from one location to another, rename file etc.
 * @param resource Resource which needs these opeations.
 * @result Return YES if these operations has been applied successfully otherwise NO.
 **/
- (BOOL) put_resource: (Resource*) resource;

/**
 * This method will be used to create/copy a resource on server. For example: create a new File, copy existing File, create new Container, add new Contact or create new Project etc.
 * @param destination_url Destination URL where the resource is to be created/copied.
 * @param resource Resource object on which these operation is to be applied.
 * @result Return the resourceID generated by server.
 **/
- (NSString*) post_resource: (NSString*) destination_url resource: (Resource*) resource;

/**
 * This method is used to delete a resource from the server.
 * @param resource Resource object which is to be deleted from server.
 * @result Return YES if resource is deleted from server otherwise return NO.
 **/
- (BOOL) delete_resource: (Resource*) resource;

/**
 * This method will be used to get the lock on resource before modifying it. For example: To upload a file on server, first take the lock resource then upload the file and after this process is over, unlock the resource using unlock_resource method.
 * @param resource Resource which is to be locked.
 * @result Return the lockID for the given resource.
 **/
- (NSString*) lock_resource: (Resource*) resource;

/**
 * This method will be used to unlock a resource.
 * @param resource Resource object which is to be unlocked.
 * @result Return YES if resource has been unlocked successfully otherwise return NO.
 **/
- (BOOL) unlock_resource: (Resource*) resource;

/**
 * This method will be used to restore a resource from recyclebin.
 * @param resource Resource which needs to be restore.
 * @result Return YES if resource has been restored successfully otherwise NO.
 **/
- (BOOL) restore_resource: (Resource*) resource;

/** 
 * This method will be used to download the contents of specified resource.
 * @param resource Resource object for which request has been sent to server and parse the received response accordingly.
 * @param serviceDelegate The object which will send the callbacks to receiver in order to update the UI accordingly. 
 * @param startImmediately Whether the connection should start processing request immediately or should delay processing until it receives the -start message.
 * @result The initialized Service instance.
 **/
- (id) get_resourceAsynchronously: (Resource*) resource 
						 delegate: (id<ServiceDelegate>)serviceDelegate
				 startImmediately: (BOOL)startImmediately;

/** 
 * This method will be used to create/copy a resource on server. For example: create a new File, copy existing File, create new Container, add new Contact or create new Project etc. 
 * @param resource Resource object for which request has been sent to server.
 * @param destination_url Destination URL where the resource is to be created/copied.
 * @param serviceDelegate The object which will send the callbacks to receiver in order to update the UI accordingly. 
 * @param startImmediately Whether the connection should start processing request immediately or should delay processing until it receives the -start message.
 * @result The initialized Service instance.
 **/
- (id) post_resourceAsynchronously: (Resource*) resource 
					destinationUrl: (NSString*) destination_url
						  delegate: (id<ServiceDelegate>)serviceDelegate
				  startImmediately: (BOOL)startImmediately;

/** 
 * This method will be used to perform the operations like upload a file, move file from one location to another, rename file etc. 
 * @param resource Resource object for which request has been sent to server.
 * @param serviceDelegate The object which will send the callbacks to receiver in order to update the UI accordingly. 
 * @param startImmediately Whether the connection should start processing request immediately or should delay processing until it receives the -start message.
 * @result The initialized Service instance.
 **/
- (id) put_resourceAsynchronously: (Resource*) resource 
						 delegate: (id<ServiceDelegate>)serviceDelegate
				 startImmediately: (BOOL)startImmediately;

- (id) delete_resourceAsynchronously: (Resource*) resource 
							delegate: (id<ServiceDelegate>)serviceDelegate
					startImmediately: (BOOL)startImmediately;

- (id) restore_resourceAsynchronously: (Resource*) resource 
							 delegate: (id<ServiceDelegate>)serviceDelegate
					 startImmediately: (BOOL)startImmediately;
/** 
 * This method is used to send the request to server. 
 **/
- (void) start;

/** 
 * This method is used to cancel the request. 
 **/
- (void) cancel;

@end


@protocol ServiceDelegate<NSObject>

@optional
-(void)service:(Service*)service willSendRequest:(NSURLRequest*)request;
-(void)service:(Service*)service didStartRequest:(NSURLRequest*)request;
-(void)service:(Service*)service willStartDownloadWithContentLength:(uint64_t)contentLength;
-(void)service:(Service*)service didReceiveData:(NSData*)data;
-(void)service:(Service*)service didFailWithError:(NSError*)error;
-(void)serviceDidCancel:(Service*)service;
-(void)serviceDidFinishDownloading:(Service*)service;
-(void)serviceDidFinish:(Service*)service;
-(void)service:(Service*)service  setNetworkActivityIndicator:(BOOL) isVisible;
@end

