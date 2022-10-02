# Boxes-CPP-SSDB-WebApplication

![alt text](https://github.com/PaulNovack/Boxes-CPP-SSDB-WebApplication/blob/main/BoxesCPPSSDB-Network.jpeg?raw=true)

Another experiment creating a highly scaleable JSON API Web Application (Boxes) with C++, SSDB and React.

* Utilizing C++ Web servers, sticky sessions and in memory session state persistance.  
* User data sharded on SSDB instances as a data store for persistence.  
* React framework for UI.

First Header  | Second Header
------------- | -------------
Content Cell  | Content Cell
Content Cell  | Content Cell

Boxes keys and values				
Numeric ids are base65 encoded strings 8 chars long	SSDB only works with strings so numbers are represented in a sortable string.

* Sequence of characters for encoding "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz{|}~"


pseudo table |		key	|	value
-------------|--------|--------------------------------------------------------
user		| u:username:password		| userid
user_shard		| us:user_id		| shard_id
box		| b:user_id:box_id		| attributes of box
item		| i:box_id:item_id		| attributes of item
shards		| s:shard_id		| attributes of shard
