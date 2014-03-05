AlgorithmProject-Stable-Matching
================================

The College Admission Stable Matching System with Gale-Shapley Algorithm

Input
The first line of each set contains two integers D and N (1 <= D <= 1000, 1 <= N <= 10000) which denotes the total number of department and perspective students.
Next, each of next D lines contains a string which denotes to the ID of the department, and two integers Di and Li (1 <= Di <= Li <= 100) which denotes the amount of total admission and the amount of students who are on the waiting-list. Then, Li is followed by the preference order of student IDs on the department's waiting-list. (Student IDs are from 1 to N)
Last, each of next N lines contains a number Ti which denotes to the amount of the i-th student. Then, Ti is followed by this student's preference order of departments IDs.


Output
Find and print the admission list of each department. The list must printed in lexicographical order of the department IDs as shown in sample output.


Sample Input
36 a001 2 b001 2 c001 3 2 b001 1 a001 3 b001 1 a001 3 c001 2 b001
4 4 1 3 2
5 6 3 4 5 1
4 4 6 5 3 a001
a001 c001
b001 a001 c001


Sample Output
a001 41
b001 63 c001 5