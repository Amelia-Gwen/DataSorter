# DataSorter
A list of decisions made in no particular order.

Use of console UI seemed simple and within the scope set for the project.

The chosen sort methods were:
  Bubble Sort - chosen for its known poor performance.
  Bucket Sort - chosen because I wanted to see it used with strings.
  Merge Sort - for its general usefulness.
*Note: I would usually use std::sort for any sorting needs.

I tried to follow OOP approach to the problem. Although it is more of a mix of procedural and OOP styles. Procedural may have been a better approach considering the scope of the problem but I don't think so.The major drawback to the OOP structure is the constant passing of the data structure by const& levelafter level in the function calls.

The sorting functions need reworked. As they are they do to much work. If I were to actually want to use them I would rewrite them to have an interface similar to std::sort. I would take iterators as a parameter as well as an overloaded function call taking a function pointer that the user can pass as a comparator for user defined types. This is non-trivial and therefor outside the scope of this project.

Very few programs would require sorting data so many times and would thus not require maintaining copies of unmodified data. If I wanted to sort data from a file or other source I would do it as I streamed it, probably to a set or map depending on my needs, thus having 1 sorted data structure and no copying. This didn't seem practical for this project however it may have worked well. I did not test sort during stream repeatedly but I felt mainting an open fstream throughout the lifetime of the program was not the best idea.

the use of \_kbhit() and \_getch() for non-blocking IO is non-portable but the project was explicitly intended to be on the Windows platform. Multithreading would have been a better, more portable solution but is non-trivial.
