# Boxes-CPP-SSDB-WebApplication

![alt text](https://github.com/PaulNovack/Boxes-CPP-SSDB-WebApplication/blob/main/BoxesCPPSSDB-Network.jpeg?raw=true)

Another experiment creating a highly scaleable JSON API Web Application (Boxes) with C++, SSDB and React.

* Utilizing C++ Web servers, sticky sessions and in memory session state persistance.  
* User data sharded on SSDB instances as a data store for persistence.  
* React framework for UI.

Numeric ids are base65 encoded (A custom encoding) to strings 4 or 8 chars long.	SSDB only works with strings so numbers are represented in a sortable string rather than left padding a number to allow it to be sortable.  This way 8 characters can represent a number up to 3.186448129×10¹⁴

* Sequence of characters for encoding "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz{|}~"


pseudo table |		key	|	value
-------------|--------|--------------------------------------------------------
user		| u:username:password		| userid
user_shard		| us:user_id		| shard_id
box		| b:user_id:box_id		| attributes of box
item		| i:box_id:item_id		| attributes of item
shards		| s:shard_id		| attributes of shard

Example user key value

key | Value
--------|---------
us:johndoe@gmail.com:password | 0000aabb

Example user_shard key value (Users data would be stored on shard 1

key | Value
--------|---------
us:0000aabb | 00000001

Example Box key value 

key | Value
--------|---------
b:0000aabb:0000bxdg | Box Attribures

Example Item key value 

key | Value
--------|---------
i:0000aabb:0000bxdg | Item Attribures

Redis / SSDB Commands

To get a users boxes

scan (b:user_id, b:user_id~)

This would return all key values for boxes then to get items use the box_id's returned for each box
