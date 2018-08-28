# DataSorter

*Note: master branch represents the original project submission. Refactoring branch represents subsequent fixes to known issues

A list of decisions made in no particular order.

Use of console UI seemed simple and within the scope set for the project.

The chosen sort methods were:

  Bubble Sort
  
  Merge Sort
  
  Selection Sort
  
*Note: I would usually use std::sort for any sorting needs.

I considered an OOP approach to the problem as I am more familiar with that. What I did is more of a mix of procedural and dynamic styles. The major drawback to the current approach is that it is not very scalable.

Very few programs would require sorting the same unsorted data so many times and would thus not require maintaining copies of unmodified data. If I wanted to sort data from a file or other source I would do it as I streamed it, probably to a set or map depending on my needs, thus having 1 sorted data structure and no copying. Streaming the same data repeatedly didn't seem practical for this project however it may have worked well. I did not test sort while repeatedly streaming but I felt mainting an open fstream throughout the lifetime of the program was not the best idea.

the use of \_kbhit() and \_getch() for non-blocking IO is non-portable but the project was explicitly intended to be on the Windows platform. Multithreading would have been a better, more portable solution but is non-trivial. On further review I don't belive multithreading is necessary. There seems to be no clean way to interrupt a function from outside the scope of the function. Rather the functions themselves need to check upon iteration whether they should continue. Qt also provides signal support. Will look into that next.

The script I used to generate the data is also provided as well.

I will also note that I was canceling out of the bubble sort every time when using it with the large data set. I chose bubble sort because I wanted the opportunity to see just how slow it really is and this was an eye opening experience.
