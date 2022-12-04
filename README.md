                                                 External-Sorting-for-Massive-Data  
                                   https://www.kaggle.com/datasets/mohamedbakhet/amazon-books-reviews
Requirement: Use the "Books_rating.csv" file in this link and sort the id of the books ascendingly. If the id are the same, randomly sort. 
Store the result output in "sorted_books_ratings.csv".

Suggested Idea: Do not sort directly the whole data because it will lead to crash. Instead, you shuold apply the idea of Merge K-Sorted Array to solve this problem and to ensure that data do not fit in main memory

To test, it is suggested spliting the initial file into smaller one for easy handling.

Using the idea of External Sorting, I split the initial file into k sorted file and then respectively read the first element of each file and store it in one Min-heap then put the root into to the Result File.

All credits of the ideas are from:

- https://opendsa-server.cs.vt.edu/ODSA/Books/Everything/html/ExternalSort.html
- https://www.geeksforgeeks.org/external-sorting/
