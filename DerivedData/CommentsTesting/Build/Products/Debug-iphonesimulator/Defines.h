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

#define kXmlTag             @"<?xml version=\"1.0\"?>"
#define kXmlnsTag           @"xmlns:xlink=\"http://www.w3.org/1999/xlink\""
#define kXlinkTag           @"xlink:href"

#define kContentType            @"Content-Type"
#define kAccept					@"Accept"
#define kXCloudDepth            @"X-Cloud-Depth"
#define kXCloudRoot             @"X-Cloud-Root"
#define kETag                   @"If-None-Match"
#define kXCloudKey              @"X-Cloud-Key"
#define kXCloudLock             @"X-Cloud-Lock"
#define kXCloudLockType         @"X-Cloud-Lock-Type"
#define kUserAgent              @"User-Agent"
#define kContentLocation        @"Content-Location"
#define kContentRange           @"Content-Range"
#define kXClientSpecification   @"X-Client-Specification"

#define kXmlRepresentation          @"xml"
#define kJsonRepresentation         @"json"

#define kCloudInfo          @"application/vnd.csp.cloud"
#define kCloudInfo2         @"application/vnd.csp.cloud2"
#define kAccountInfo        @"application/vnd.csp.account-info2"

#define kFileInfo           @"application/vnd.csp.file-info"
#define kFileList           @"application/vnd.csp.file-list"
#define kContainerInfo      @"application/vnd.csp.container-info"

#define kFile2Info           @"application/vnd.csp.file-info2"
#define kFile2List           @"application/vnd.csp.file2-list"
#define kContainer2Info      @"application/vnd.csp.container-info2"


#define kContactInfo        @"application/vnd.csp.contact"
#define kContactList        @"application/vnd.csp.contact-list"

#define kProjectInfo        @"application/vnd.csp.project"
#define kProjectList        @"application/vnd.csp.project-list"

#define kPermissionInfo     @"application/vnd.csp.permission"
#define kPermissionList     @"application/vnd.csp.permission-list"

#define kTagInfo            @"application/vnd.csp.tag-info"
#define kTagList            @"application/vnd.csp.tag-list"

#define kMetaData           @"application/vnd.csp.metadata"
#define kMetaDataList       @"application/vnd.csp.metadata-list"

#define kCommentInfo        @"application/vnd.csp.comment"
#define kCommentList        @"application/vnd.csp.comment-list"

#define kDeletedObject      @"application/vnd.csp.deleted-object"
#define kDeletedObjectList  @"application/vnd.csp.deleted-object-list"

#define kCloudTag           @"cloud"
#define kRootTag            @"rootTag"
#define kRootContainerTag   @"rootContainer"
#define kContactsTag        @"contacts"
#define kSharesTag          @"shares"
#define kAccountTag         @"account"
#define kTagsTag            @"tags"
#define kRecycleBinTag      @"recyclebin"
#define kNamespaceTag       @"namespace"
#define kLocationTag        @"location"
#define kLocationsTag       @"locations"
#define kManagementTag      @"management"

#define kContainerTag       @"container"
#define kFileTag            @"file"
#define kContentsTag        @"contents"
#define kMetadataTag        @"metadata"
#define kParentTag          @"parent"
#define kPermissionsTag     @"permissions"
#define kContentTag         @"content"
#define kThumbnailTag       @"thumbnail"

#define kNameTag            @"name"
#define kCreationTag        @"created"
#define kInprojectTag       @"inproject"
#define kModifiedTag        @"modified"
#define kOwnerTag           @"owner"
#define kVersionTag         @"version"
#define kSharedTag          @"shared"
#define kAccessedTag        @"accessed"
#define kBytesTag           @"bytes"
#define kMimeTypeTag        @"mime_type"

#define kFirstNameTag       @"firstname"
#define kLastNameTag        @"lastname"
#define kEmailTag           @"email"
#define kContactTag         @"contact"

#define kOriginalName       @"originalname"
#define kTrashedDate        @"recycleddate"

#define kStartDate          @"startdate"
#define kEndDate            @"enddate"

#define kGranteeTag         @"grantee"
#define kExpirationTag      @"expiration"
#define kPermissionTag      @"permission"
#define kCommentTag         @"comment"
#define kCommentsTag        @"comments"
#define kCreatedTag         @"created"
#define kNameTag            @"name"


#define kUserNameTag        @"username"
#define kAccountType		@"account_type"
#define kPasswordTag        @"password"
#define kStorageTag         @"storage"
#define kBandwidthTag       @"bandwidth"
#define kAllocatedTag       @"allocated"
#define kUsedTag            @"used"
#define kTotalTag           @"total"
#define kPrivateTag         @"private"
#define kPublicTag          @"public"

#define kTag                @"tag"
#define kObjectsTag         @"objects"

#define kMetadataItemTag    @"metadata-item"


typedef enum
{
    CLOUD_RES       = 0,
    CLOUD2_RES,
    ACCOUNT_RES,
    FILE_RES,
    FILE2_RES,
    FILE_LIST_RES,
    CONTAINER_RES,
    CONTAINER2_RES,
    CONTACT_RES,
    CONTACT_LIST_RES,
    PERMISSION_RES,
    PERMISSION_LIST_RES,
    LOCATION_RES,
    LOCATION_LIST_RES,
    METADATA_RES,
    METADATA_LIST_RES,
    SHARES_LIST_RES,
    TAG_RES,
    TAG_LIST_RES,
    TRASH_ITEM_RES,
    TRASH_ITEM_LIST_RES,
    COMMENT_RES,
    COMMENT_LIST_RES

} ResourceType;

typedef enum
{
    XML     = 0,
    JSON,
    XML_BYTE,
    XML_NODE,
    JSON_BYTE,

}E_ResRepresentation;

typedef enum
{
    FILE_TYPE       = 0,
    DIRECTORY_TYPE,
    PROJECT_TYPE,
    UNKNOWN_TYPE

} ItemType;

typedef enum
{
    HTTP_SUCCESS            = 0,
    HTTP_OK                 = 200,
    HTTP_CREATED            = 201,
    HTTP_NO_CONTENT         = 204,
    HTTP_NOT_AUTHORITATIVE  = 403,
    HTTP_BAD_REQUEST        = 400,
    HTTP_NOT_FOUND          = 404,
    HTTP_CONFLICT           = 409,
    HTTP_UNSUPPORTED_TYPE   = 415,
    HTTP_INTERNAL_ERROR     = 500,
    HTTP_UNKNOWN_ERROR      = 1000,
    PARSE_ERROR             = 1001

} E_ResponseCode;
