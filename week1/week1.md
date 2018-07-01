Slack channel :lock:cs261-cst
### Chapter 1 - The study of data structures.

>While the worksheets can be used in an individual situation, it is the author’s opinion (supported by experience), that they work best in a group setting. When students work in a group, they can help each other learn the basic material. Additionally, group work helps students develop their communication skills, as well as their programming skills. In the authors use, a typical class consists of a short fifteen to twenty minute lecture, followed by one or two worksheets completed in class.

### Chapter 2 - Algorithms
**program** - Series of commands that a computer follows to preform a useful task.  

**algorithm** - is a description of how a specific problem can be solved, written at a level of detail that can be followed by the reader.  

**function** - used to package a task to be preformed. Really an algorithm in a particular language



**PROPERTIES OF AN ALGORITHM**  
**input preconditions** - The most common form of algorithm is a transformation that takes a set of input values and performs some manipulations to yield a set of output values. An algorithm must make clear the number and type of input values, and the essential initial conditions those input values must possess to achieve successful operation.  

**precise specification of each instruction** - Each step of an algorithm must be well defined. There should be no ambiguity about the actions to be carried out at any point.  An algorithm is expected to solve a problem.   

**termination, time to execute** - It must be clear that for any input values the algorithm is guaranteed to terminate after a finite number of steps. It is usually not necessary to know the exact number of steps an algorithm will require, but it will be convenient to provide an upper bound and argue that the algorithm will always terminate in fewer steps than the upper bound. Usually this upper bound will be given as a function of some values in the input. For example, if the input consists of two integer values n and m, we might be able to say that a particular algorithm will always terminate in fewer than n + m steps.     

**description of the result or effect** -  it must be clear exactly what the algorithm is intended to accomplish. This can be expressed as the production of a result value having certain properties.   

### Chapter 3 - Debugging, Testing and Proving Correctness  
**Debugging Tips**   
1. Preform tests in small pieces before introducing into the larger code base.   
2. Determine most simple input that creates the error.   
3. Play the role of the computer to find logical errors.  
4. Think about what is occurring before the error is thrown  
5. Use print lines to provide information throughout the code  
6. Don't assume, if one input works... they all work  
7. Use assertions and invariants in your code  
8. Question everything. Be open to any possibility. Look everywhere.  

**assertion** - a comment that explains what you know to be true when execution reaches a specific point in the program.  

**invariant** - an assertion inside a loop. It must describe a condition that does not vary during the course of executing the loop.  

**assertion statement** - takes as argument an expression, and typically will halt execution and print an error message if the statement is not true.

### Worksheet 9  

Describe the running time of each function using big-Oh notation.    

| function | Big-O Notation | time |
| --- | --- | --- |
| 3n^3 +2n+7 | O(n^3) | 31.7 yrs |
| (5 * n) * (3 + log n) | O(log(n)) | 1.2*10^-5 s |
| 1+2+3+...+n | O(n) | 0.1 s |
| n + log n^2 | O(nlog n) | |
| ((n+1) log n ) / 2 | O(nlog n) | |
| n3 + n! + 3 | O(n!) | |
| 2n + n^2 | O(n^2) | |
| n (sqrt(n) + log n) | O(sqrt(n)) | |

#3 can either be linear or quadratic imo, 1 + 2 + 3 + ... + n) or (n^2/2) + 1 respectively.
#4 because log x^y = (y)(log x)  

Using the idea of dominating functions, give the big-Oh execution time for each of the following sequences of code.

| loop | description |   
| --- | --- |  
| for (int i = n; i > 0; i = i / 2) { ... } for (int j = 0; j * j < n; j++) ... |
| for (int i = 0; i < n; i++) { for (int j = n; j > 0; j = j/ 2) {... } for (int k = 0; k < n; k++) { ... } } |
| for (int i = 0; i < n; i++) ... for (int j = 0; j * j < n; j++) ... |
| for (int i = 0; i < n; i++) ... for (int j = n; j > 0; j--) ... |
| for (int i = 1; i * i < n; i += 2) ... for (int i = 1; i < n; i += 5) ... |
