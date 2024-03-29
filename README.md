# C-LinkedList

# Accessor Methods
|Method|Usage|
|:-:|:-|
|int linkedListSize(int_LL *start)|linkedListSize(ll) where ll is the linkedList start. Returns the amount of links in the list.
|int getLink(int_LL *start, int index)|getLink(ll, index) where ll is the linkedList start, and index is the index. Returns the value held by the link. If the pointer directly to the link is desired, the `int_LL* linkPointer(int_LL *start, int index)` method should be used.|
|int frontLink(int_LL *start)|frontLink(ll) where ll is the linkedList start. Returns the first link in the list.|
|int backLink(int_LL *start)|backLink(ll) where ll is the linkedList start. Returns the last link in the list.|
|int_LL* linkPointer(int_LL *start, int index)|linkPointer(ll, index) where ll is the linkedList start, and index is the index. Returns the pointer to requested link.|

# Modifier Methods
|Method|Usage|
|:-:|:-|
|void insertLinkedList(int_LL *start, int index, int val)|insertLinkedList(ll, index, yourNum) where ll is the linkedList start, index is the index, and yourNum is the value to place. Places a new link into the list at a given index, and relinks list in order to preserve continuity.|
|void pushBackLinkedList(int_LL *start, int val)|pushBackLinkedList(ll, yourNum) where ll is the linkedList start, and yourNum is the value to place. Adds given value to a new link at the back of the list.|
|void popBackLinkedList(int_LL *start)|popBackLinkedList(ll) where ll is the linkedList start. Removes the last link from the list.|
|void deleteLink(int_LL *start, int index)|deleteLink(ll, index) where ll is the linkedList start, and index is the index. Removes the link at the given index. Relinks list for continuity.|
|void setLink(int_LL *start, int index, int val)|setLink(ll, index, yourNum) where ll is the linkedList start, index is the index, and yourNum is the value to place. Updates the given link to hold the given value.|
|void swapLink(int_LL *start, int index1, int index2)|swapLink(ll, index1, index2) where ll is the linkedList start, and the indeces are indeces. Swaps the value held by the links in each of the indeces. |

# Creating a Linked List
Linked Lists should be created by using the provided `int_LL* initLinkedList(int val)` method and manipulated using the given methods to ensure that no undocumented behavior occurs. The `void freeLinkedList(int_LL* start)` method is provided to free memory used by the list.

# More information
The header file is thoroughly commented, and contains more insights on the uses and quirks of each method in its headings and comments.
