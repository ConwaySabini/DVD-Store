# DVD-Store
Utilizes file input and output to manage a DVD Store with customers borrowing, and returning movies, and getting the history. Implemented a hash table with open chaining and a self balancing AVL tree. Implemented a hash table with open chaining and a self balancing AVL tree. The hash table was used to store the customer transaction history, while the AVL tree was used to store the movie data and stock of movies.

CSS 343 Assignment 4 Design

Program Overview 
The main program will then read from a valid text file and execute a series of operators.
Acceptable operators are: borrow, return, inventory, and history with all other operators be marked as X and written to output. Y is written to output when a “No” is ever encountered for certain cases. 
* further class descriptions are found under the UML diagrams

Architecture:
![image](https://user-images.githubusercontent.com/53063791/153732192-31b81985-e29c-4655-88e3-ab0b593a922f.png)


Class Diagrams

![image](https://user-images.githubusercontent.com/53063791/153732241-40afd41f-2342-43bb-a122-edc32c5a6b64.png)


Movie Database
To store the movies, it will be handled by 2 unique classes since classic movies are different than funny and dramatic movies.

![image](https://user-images.githubusercontent.com/53063791/153732224-0bb784c3-def3-4773-8a37-4c85dd702fab.png)

Classic Movies inherit the Movie object and classic nodes inherit movie nodes as they use similar functionality and parameters.

The movie database will have 3 heads of nodes. 
Funny Tree
Drama Tree
Classic Tree
Where the nodes will be used to construct a binary search tree ordered by their movie nodes and classic nodes for the classic tree by overloading their equality and comparison operators.


Customer Database
We’ll store customers with a hashtable for quick retrieval using pointers. Their ID will be used as keys and their values will be a customer object containing information regarding their name and history. The history is a single linked list to be inserted in chronological order. It can also be derived from MovieNode/ClassicNode.

![image](https://user-images.githubusercontent.com/53063791/153732270-3f2803eb-2b74-44c0-a193-2f3190f24501.png)


