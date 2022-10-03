# Boxes-CPP-SSDB-WebApplication

![alt text](https://github.com/PaulNovack/Boxes-CPP-SSDB-WebApplication/blob/main/BoxesCPPSSDB-Network.jpeg?raw=true)

Another experiment creating a highly scaleable JSON API Web Application (Boxes) with C++, SSDB and React.

* Utilizing C++ Web servers, sticky sessions and in memory session state persistance. Sticky sessions allows Web Application servers to maintain state in memory rather than in memcache, database or redis etc. 
* User data sharded on SSDB instances as a data store for persistence.  
* React framework for UI.

# To do:
* use https://github.com/PaulNovack/boxesCPlus as a starting point for web server and API routes already done.
* Create a thread safe redis connection pool with redis which includes health checks to all the shards using redis-plus-plus.
* Create an actual JSON parser implementation instead of the janky one in BoxesCPlus that was thrown in
* Change the way data is stored in BoxesCPlus from mySQL database to a Redis/SSDB backend
* Create Box, User and Item Classes that can function like an ORM to serialize their data to Key Value pairs for storage and serialize to JSON for frontend react.
* Change Session state stored in application to use STL map of Box and Item classes from the simple string representation used in BoxesCPlus implementation.
* Do all writes to SSDB async after updating Web Application Session and returning response.

Numeric ids are base65 encoded (A custom encoding) to strings 4 or 8 chars long.	SSDB only works with strings so numbers are represented in a sortable string rather than left padding a number to allow it to be sortable.  This way 8 characters can represent a number up to 3.186448129×10¹⁴

Users are strings 8 long up to 3.186448129×10¹⁴ users.
Boxes and Items are strings 4 long  (65 X 65 X 65 X 65) up to 17850625 boxes and items per box.

* Sequence of characters for encoding "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz{|}~"

The ":" character does not have to be stored in key actually beause we have set lengths for each key ( 8 or 4)

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
u:johndoe@gmail.com:password | 0000aabb

Example user_shard key value (Users data would be stored on shard 1

key | Value
--------|---------
us:0000aabb | 00000001

Example Box key value 

key | Value
--------|---------
b:0000aabb:bxdg | Box Attribures

Example Item key value 
* Items could use simply the box key but then here would have to be a distributed sequence generator like twitter snowflake or part of key would have to be the shard identifier.

key | Value
--------|---------
i:0000aabb:bxdg:adfg | Item Attribures

Redis / SSDB Commands

To get a users boxes

scan (b:user_id, b:user_id~)

This would return all key values for boxes then to get items use the box_id's returned for each box
