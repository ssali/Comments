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
#import "ResourceList.h"

@class Contact;

/*!
 @class ContactList

 @abstract ContactList class contains the list of all users.

 @discussion ContactList class is used to get and add the contact.
 */

@interface ContactList : ResourceList
{

}

/**
 * This method will be used to add a contact into the resource list.
 * @param contact Contact which is to be added into the list
 **/
- (void) addContact: (Contact*) contact;

/**
 * This method returns the contact as per the given index.
 * @param index Position of the contact in contact list.
 * @result Returns Contact object from the contact list.
 **/
- (Contact*) contactAtIndex: (uint) index;

@end
