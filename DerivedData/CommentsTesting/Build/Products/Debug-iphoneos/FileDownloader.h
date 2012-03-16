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

/*!
 @class FileDownloader

 @abstract FileDownloader class is responsible to download a file from server.

 @discussion FileDownloader class adopt FileDownloaderDelegate protocol which is intended to provide the
             informational callbacks to client. To use these protocol's methods Client simply need to
             set the delegate of FileDownloader and implement these methods. By Doing this, client can
             track the current status of File Download operation such as how much data has been downloaded,
             when downloading will finish and change the UI accordingly.

Example:

YourClass.m

FileDownloader* fileDownload = [[FileDownloader alloc] initWithService: service];

[fileUpload setDelegate: self];
*/

@class Service;
@class File;
@class FileDownloader;
@protocol FileDownloaderDelegate <NSObject>
@optional
- (void)downloader:(FileDownloader*)downloader willSendRequest: (NSURLRequest*) request;
- (void)downloader:(FileDownloader*)downloader didReceiveData:(NSData*)data;
- (void)downloader:(FileDownloader*)downloader willStartDownloadWithContentLength:(uint64_t)downloadLength;
- (void)downloader:(FileDownloader*)downloader didFailWithError: (NSError*) error;
- (void)downloadDidCancel:(FileDownloader*)downloader;
- (void)downloadFinished:(FileDownloader*)downloader;
- (void)downloader:(FileDownloader*)downloader setNetworkActivityIndicator:(BOOL) isVisible;
@end

@interface FileDownloader : NSObject <FileDownloaderDelegate>
{
    Service*                            _service;
    NSHTTPURLResponse*                  _httpResponse;
    NSObject<FileDownloaderDelegate>*   _delegate;
    NSOutputStream*                     _outputStream;
    NSURLConnection*                    _urlConnection;
    BOOL                                _downloadCancel;
}

/**
 * Get/Set the delegate. This delegate provide the informational callback methods.
 */
@property(nonatomic, assign) id<FileDownloaderDelegate> delegate;

/**
 * Get/Set the download status, whether the downloading is to be cancelled or not.
 */
@property(nonatomic, assign) BOOL downloadCancel;

@property(nonatomic, assign) NSHTTPURLResponse* httpResponse;

/**
 * This method is used to initialize the FileDownloader class.
 * @param service Service object which will used to send the request on server.
 * @result Return FileDownloader instance.
 **/
- (id) initWithService: (Service*) service;

/**
 * This method is used to Download a file from server.
 * @param path Path where the file is to be downloaded.
 * @result Return YES if file has been downloaded successfully otherwise No.
 **/
- (void) downLoadFile: (File*) file downloadPath: (NSString*) localFileDwonloadPath;

/**
 * This method is used to get the thumbnail icon of a file.
 * @param file The file whose thumbnail data is to be fetched from server.
 * @result Returns the thumbnail data.
 **/
- (NSData*) getIcon: (File*) file;

- (void) cancel;

@end
