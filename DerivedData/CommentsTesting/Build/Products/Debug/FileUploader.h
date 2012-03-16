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

@class Service;
@class File;
@class FileUploader;

@protocol FileUploaderDelegate <NSObject>
@optional
- (void)uploadDidStart:(FileUploader*)uploader;
- (void)uploader:(FileUploader*)uploader didUploadLength:(NSUInteger)uploadLength;
- (void)uploadDidFail:(FileUploader*)uploader;
- (void)uploadDidCancel:(FileUploader*)uploader;
- (void)uploadDidFinish:(FileUploader*)uploader;
- (void)uploader:(FileUploader*)uploader setNetworkActivityIndicator:(BOOL) isVisible;
@end
@interface FileUploader : NSObject {
    NSObject<FileUploaderDelegate>*     _delegate;
    
    Service*           _service;
	File*			   fileObj;
    NSHTTPURLResponse*             _httpResponse;	
    NSURLConnection *  _connection;
    NSInputStream *    _fileStream;
    NSInteger          apiError;
    
    // For queueing
    NSOperation*                                            uploadOperation;
    NSOperationQueue*                                       uploadQueue;
}

@property(assign) id<FileUploaderDelegate> delegate;
@property(nonatomic) NSInteger apiError;
@property(nonatomic, retain)File* fileObj;
@property(nonatomic, assign) NSHTTPURLResponse* httpResponse;
/**
 * This method is used to initialize the FileUploader class.
 * @param service Service object which will used to execute the request.
 * @result Return FileUploader instance.
 **/
- (id)initWithService: (Service*) service;

/** 
 * This method is used to start the file upload operation. 
 **/
- (void)start; 

/** 
 * This method will be used to cancel the file upload operation. 
 **/
- (void)cancel;

/**
 * This method is used to overwrite a file on the server.
  * @param file File to replace the contents of
  * @param path Path of file.
 **/
- (void) overWriteFile: (File*) file path: (NSString*) path;

/**
 * This method is used to upload a file to the server.
 * @param file File to replace the contents of
 * @param path Path of file.
 * @result Success/failure is sent by 'message'
 **/
- (void) uploadFile: (File*) file path: (NSString*) path;

@end


