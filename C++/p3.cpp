#include <iostream>
#include <string>

#include "p3.h"

using namespace std;

Info::Info() {
    this->name = "No Name Set";
    this->value = "No Value Set";
    this->next = nullptr;
}

Info::Info(std::string name, std::string value, Info *next) {
    this->name = name;
    this->value = value;
    this->next = next;
}
 
Contact::Contact() {
    this->first = "No First Set";
    this->last = "No Last Set";
    this->next = nullptr;
    this->headInfoList = nullptr;
}

Contact::Contact(std::string first, std::string last, Contact *next) {
    this->first = first;
    this->last = last;
    this->next = next;
    this->headInfoList = nullptr;
}

ContactList::ContactList() {
    this->headContactList = nullptr;
    this->count = 0;
}

int ContactList::getCount() {
    return this->count;
}

// print the specified contact and its information
// 1. return false and print nothing if the contact is not in the list
// 2. otherwise return true and print the contact
bool ContactList::printContact(std::ostream &os, std::string first, std::string last) {
    Contact *cur = headContactList;
        while (first != cur->first && last != cur->last) {
            cur = cur->next;
            if(cur == nullptr){
                return false;}
        }
        os << "Contact Name: " << cur->first << " " << cur->last << endl;
        Info *curinfo = cur->headInfoList;
        while(curinfo != nullptr){
            os << curinfo->name << " | " << curinfo->value << endl;
            curinfo = curinfo->next;}
    return true;
}

// print all contacts and their information
// print nothing if the list is empty
void ContactList::print(std::ostream &os) {
Contact *cur = headContactList;
        while (cur != nullptr) {           
                os << "Contact Name: " << cur->first << " " << cur->last << endl;
                Info *curinf = cur->headInfoList;
                while(curinf != nullptr){
                    os << curinf ->name << "  | " << curinf ->value << endl;
                    curinf = curinf->next;
                }
            cur = cur->next;
        }
}

// add a contact to the back of the list
// 1. return false and do nothing if the contact is already in the list
// 2. otherwise return true and add the contact to the back of the list
// - do not forget to update count
bool ContactList::addContact(std::string first, std::string last) {
    Contact *n = new Contact(first, last);
        if (headContactList == nullptr){
            headContactList = n;
            count++;
            return true;
        }
        else {
            Contact *cur = headContactList;
            while (cur->next != nullptr) {
                
                if (cur->first == n->first && cur->last == n->last)
                {
                    return false;
                }
                cur = cur->next;
            }
            cur->next = n;
            count++;
            return true;
        }
}

// add info to the back of a contact's info list
// 1. return false and do nothing if the contact is not in the list
// 2. if the infoName is already in the info list, update the infoValue and return true
// 3. otherwise add the info to the back of the contact's list and return true
bool ContactList::addInfo(std::string first, std::string last, std::string infoName, std::string infoVal) {
    Info *n = new Info(infoName, infoVal);
            Contact *cur = headContactList;
            while (cur->first != first && cur->last != last) {
                if(cur->next == nullptr){
                    return false;
                }
                cur = cur->next;
                }
                Info *curinf = cur->headInfoList;
            if (cur->headInfoList == nullptr){
            cur->headInfoList = n;
            return true;
            
        }
        else if(curinf->name == infoName){
            curinf->value = infoVal;
            return true;
        }
        else {
            
            while (curinf->next != nullptr) {                
                if(curinf->name == infoName){
                    curinf->value = infoVal;
                    return true;
                }
                curinf = curinf->next;
                }
            curinf->next = n;
            return true;
        }
}

// add a contact to the list in ascending order by last name
//     if last names are equal, then order by first name ascending
// 1. return false and do nothing if the contact is already in the list
// 2. otherwise return true and add the contact to the list
// - do not forget to update count
// - a compare method/function is recommended
bool ContactList::addContactOrdered(std::string first, std::string last) {
    Contact *n = new Contact(first, last);
        if (headContactList == nullptr) { // empty
            headContactList = n;
            count++;
        }
        else if (last < headContactList->last) { // insert front
            n->next = headContactList;
            headContactList = n;
            count++;
        }
        else { // middle & back
            Contact *prev = headContactList;
            Contact *cur = headContactList->next;
            while (cur != nullptr) {
                if(last == cur->last && first == cur->first){
                    return false;
                }
                if (last <= cur->last) {
                    break;
                }
                prev = prev->next;
                cur = cur->next;
            }
            if(first > prev->first){
            prev->next = n;
            n->next = cur;
            count++;
            }
            else{
            prev->next = n;
            n->next = cur;
            count++;
            }
        }
    return true;
}

// add info to a contact's info list in ascending order by infoName
// 1. return false and do nothing if the contact is not in the list
// 2. if the infoName is already in the info list, update the infoValue and return true
// 3. otherwise add the info to the contact's list and return true
bool ContactList::addInfoOrdered(std::string first, std::string last, std::string infoName, std::string infoVal) {
    Info *n = new Info(infoName, infoVal);
            Contact *cur = headContactList;
            while (cur->first != first && cur->last != last) {
                if(cur->next == nullptr){
                    return false;
                }
                cur = cur->next;
                }
            if (cur->headInfoList == nullptr){
            cur->headInfoList = n;
            return true;
        }
        else {
            Info *curinf = cur->headInfoList;
        if (curinf == nullptr) { // empty
            curinf = n;
            return true;
        }
        else if (infoName < curinf->name) { // insert front
            n->next= curinf;
            cur->headInfoList = n;
            return true;
        }
        else { // middle & back
            Info *prev = curinf;
            Info *cur2 = curinf->next;
            while (cur2 != nullptr) {
                if(infoName == cur2->name){
                    cur2->value = infoVal;
                    return true;
                }
                else if (infoName < cur2->name) {
                    break;
                }
                prev = prev->next;
                cur2 = cur2->next;
            }
            if(infoName > prev->name){
            prev->next = n;
            n->next = cur2;
            return true;
            }
            else{
            cur2->next = n;
            return true;
            }
}
        }
}

// remove the contact and its info from the list
// 1. return false and do nothing if the contact is not in the list
// 2. otherwise return true and remove the contact and its info
// - do not forget to update count
bool ContactList::removeContact(std::string first, std::string last) {
        if (headContactList->last == last && headContactList->first == first)  { // front
            Contact *del = headContactList;
            headContactList = headContactList->next;
            delete del;
            count--;
            return true;
        }
        else { // middle & back
            Contact *prev = headContactList;
            Contact *cur = headContactList->next;
            while (cur->last != last && cur->first != first) {
                prev = prev->next;
                cur = cur->next;
            if(cur == nullptr){
                return false;
            }
            }
            prev->next = cur->next;
            delete cur;
            count--;
            return true;
            }
    
}

// remove the info from a contact's info list
// 1. return false and do nothing if the contact is not in the list
// 2. return false and do nothing if the info is not in the contact's info list
// 3. otherwise return true and remove the info from the contact's list
bool ContactList::removeInfo(std::string first, std::string last, std::string infoName) {
                Contact *cur = headContactList;
                    
                while(cur->first != first && cur->last != last){
                    cur = cur->next;
                    if(cur == nullptr){
                        return false;
                    }
                }
                if (cur->headInfoList->name == infoName) { // front
            Info *del = cur->headInfoList;
            cur->headInfoList = cur->headInfoList->next;
            delete del;

            return true;
        }
        else { // middle & back
            Info *prev = cur->headInfoList;
            Info *cur2 = cur->headInfoList->next;
            while (cur2->name != infoName) {
                prev = prev->next;
                cur2 = cur2->next;
            }
            prev->next = cur2->next;
            delete cur2;

            return true;
        }
}

// destroy the list by removing all contacts and their infos
ContactList::~ContactList() {
        while (headContactList != nullptr) {
            Contact *del = headContactList;
            headContactList = headContactList->next;
            while(del->headInfoList != nullptr){
                del->headInfoList = del->headInfoList->next;
                delete del->headInfoList;
            }
            delete del;}
}

// deep copy the source list
// - do not forget to update count
ContactList::ContactList(const ContactList &src) {
 for (Contact *cur = src.headContactList; cur != nullptr; cur = cur->next) {    
            this->addContact(cur->first,cur->last);
            for(Info *inf = cur->headInfoList; inf != nullptr; inf = inf->next){
            this->addInfo(cur->first,cur->last,inf->name,inf->value);
            }
        }
        this->count = src.count;
}

// remove all contacts and their info then deep copy the source list
// - do not forget to update count
const ContactList &ContactList::operator=(const ContactList &src) {
    if (this != &src) {
        *this = src;
    }
    return *this;
}
