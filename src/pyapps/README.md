PYTHON 
--------------------------

As Python is an interpreter, it starts reading the code from the source file and starts executing them.

However, if you want to start from the main function, you should have the following special variable set in your source file as:

if__name__== “__main__
main()


    List: Collection of items of different data types which can be changed at run time.
          sample = list()
          sample = []
          
          Lists whereas is a sequence of elements which are separated by commas and are enclosed in brackets. Also, Tuples cannot be updated whereas, in lists, elements can be updated along with their sizes.    
    
    Tuple: Collection of items of different data types which cannot be changed. It only has read-only access to the collection. This can be used when you want to secure your data collection set and does not need any modification. Tuples is basically a sequence of elements which are separated by commas and are enclosed in parenthesis.    
    
    Set: Collection of items of a similar data type.
         sample = set()
         
    
    Dictionary: Collection of items with key-value pairs.
         sample = dict()

To get all keys from the dictionary.
print dict.keys()

To convert a string into an int in python.
int(x [,base])


There are 2 types of membership operators in Python:

In: If the value is found in a sequence, then the result becomes true else false

not in: If the value is not found in a sequence, then the result becomes true else false


__init__ -- 
It is the first function that gets executed when an object of a class is instantiated. Constructor for clasFunctions 

Parameter ‘self' is used to refer to the object properties of a class.

‘self' parameter is supposed to be prefixed to the class object properties. ‘self' parparse the strings and find the pattern. 


Lambda Functions -- 

It contains only one expression and can accept any number of arguments. It returns a function object. 

In case of a normal function, you can define a function name, pass the parameter and mandatorily have a return statement. The Lambda function can be typically used for simple operations without the use of function names. It can also be used in the place of a variable.


Exception Handling 

There are 3 main keywords i.e. try, except and finally which are used to catch exceptions and handle the 
recovering mechanism accordingly. Try is the block of a code which is monitored for errors. Except block gets
executed when an error occurs.


Sub-process

Python has a built-in module called sub-process. You can import this module and either use run() or Popen() function calls to launch a sub-process and get the control of its return code.


Threading support 

We should use the threading module to implement, control and destroy threads for parallel execution of the server code. Locks and Semaphores are available as synchronization objects to manage data between different threads.


OOPS CONCEPT IN PYTHON 
-------------------------------
--> ENCAPSULATION 
--> INHERITANCE 
--> POLYMORPHISM 

CLASS --> 

class node:    << class 
  def __init__(self, key):    << constructor 
       self.key = key
       self.next = None

  def searchNode(self, var):     << Methods 
       ...
       return

Node = node(12)    << creating object 

Node.searchNode(23)       << How to call methods 


ENCAPSULATION --> 




INHERITANCE --> 



Decorator 
------------------

Add functionality to existing functions. In python everything declared are the objects. Various different names can be bound to the same function object.

Functions and methods are called callable as they can be called.

In fact, any object which implements the special method __call__() is termed callable. So, in the most basic sense, a decorator is a callable that returns a callable.

Basically, a decorator takes in a function, adds some functionality and returns it.

We can decorate functions with parameters. 

def smart_divide(func):
   def inner(a,b):
      print("I am going to divide",a,"and",b)
      if b == 0:
         print("Whoops! cannot divide")
         return

      return func(a,b)
   return inner

@smart_divide
def divide(a,b):
    return a/b

Output 
>>> divide(2,5)
I am going to divide 2 and 5
0.4

>>> divide(2,0)
I am going to divide 2 and 0
Whoops! cannot divide


Multiple decorators can be chained in Python.

def star(func):
    def inner(*args, **kwargs):
        print("*" * 30)
        func(*args, **kwargs)
        print("*" * 30)
    return inner

def percent(func):
    def inner(*args, **kwargs):
        print("%" * 30)
        func(*args, **kwargs)
        print("%" * 30)
    return inner

@star
@percent
def printer(msg):
    print(msg)
printer("Hello")


Iterators 
----------
Building an iterator from scratch is easy in Python. We just have to implement the methods __iter__() and __next__().

The __iter__() method returns the iterator object itself. If required, some initialization can be performed.

The __next__() method must return the next item in the sequence. On reaching the end, and in subsequent calls, it must raise StopIteration.

class PowTwo:
    """Class to implement an iterator
    of powers of two"""

    def __init__(self, max = 0):
        self.max = max

    def __iter__(self):
        self.n = 0
        return self

    def __next__(self):
        if self.n <= self.max:
            result = 2 ** self.n
            self.n += 1
            return result
        else:
            raise StopIteration
   
There is a lot of overhead in building an iterator in Python; we have to implement a class with __iter__() and __next__() method, keep track of internal states, raise StopIteration when there was no values to be returned etc.


Create Generator (Simplifying Iterator)
-----------

defining a normal function with yield statement instead of a return statement.

If a function contains at least one yield statement (it may contain other yield or return statements), it becomes a generator function. Both yield and return will return some value from a function.

The difference is that, while a return statement terminates a function entirely, yield statement pauses the function saving all its states and later continues from there on successive calls.

Same as lambda function creates an anonymous function, generator expression creates an anonymous generator function.

class PowTwo:
    def __init__(self, max = 0):
        self.max = max

    def __iter__(self):
        self.n = 0
        return self

    def __next__(self):
        if self.n > self.max:
            raise StopIteration

        result = 2 ** self.n
        self.n += 1
        return result

This was lengthy. Now lets do the same using a generator function.

def PowTwoGen(max = 0):
    n = 0
    while n < max:
        yield 2 ** n
        n += 1

Generators can be used to pipeline a series of operations.


CLOSURE 
-----------

Closure enclosing scope when the variable goes out of scope or the function itself is removed from the current namespace.


The criteria that must be met to create closure in Python are summarized in the following points.

    -- We must have a nested function (function inside a function).
    -- The nested function must refer to a value defined in the enclosing function.
    -- The enclosing function must return the nested function.

Closures can avoid the use of global values and provides some form of data hiding. It can also provide an object oriented solution to the problem.

When there are few methods (one method in most cases) to be implemented in a class, closures can provide an alternate and more elegant solutions. But when the number of attributes and methods get larger, better implement a class.

Here is a simple example where a closure might be more preferable than defining a class and making objects. 

def make_multiplier_of(n):
    def multiplier(x):
        return x * n
    return multiplier

# Multiplier of 3
times3 = make_multiplier_of(3)

# Multiplier of 5
times5 = make_multiplier_of(5)

# Output: 27
print(times3(9))

# Output: 15
print(times5(3))

# Output: 30
print(times5(times3(2)))

All function objects have a __closure__ attribute that returns a tuple of cell objects if it is a closure function. Referring to the example above, we know times3 and times5 are closure functions.

Decorators in Python make an extensive use of closures as well.


Exception Handling 
------------

There are 3 main keywords i.e. try, except and finally which are used to catch exceptions and handle the recovering mechanism accordingly. Try is the block of a code which is monitored for errors. Except block gets executed when an error occurs.

# import module sys to get the type of exception
import sys

randomList = ['a', 0, 2]

for entry in randomList:
    try:
        print("The entry is", entry)
        r = 1/int(entry)
        break
    except:
        print("Oops!",sys.exc_info()[0],"occured.")
        print("Next entry.")
        print()
print("The reciprocal of",entry,"is",r)

finally:
   f.close()


Regular Expression 

^a...s$ --> any five letter string starting with a and ending with s.

re.match()   <-- search the pattern 

[abc] --> match contains any of the a, b or c.

[a-e] is the same as [abcde]. 

[^abc] means any character except a or b or c

[..] --> Matching two characters. period matches any single character. 

ma*n --> zero or more occurrences of the pattern left to it.

ma+n --> The plus symbol + matches one or more occurrences of the pattern left to it.

Backlash \ is used to escape various characters including all metacharacters.

Parentheses () is used to group sub-patterns. 

 This RegEx [0-9]{2, 4} matches at least 2 digits but not more than 4 digits
 
 Vertical bar | is used for alternation (or operator).
 

Similarly there are some special sequences which can be used for pattern matching. 

\Athe --> Matches if the specified characters are at the start of a string. 

foo\b or \bfoo -->  Matches if the specified characters are at the beginning or end of a word. 

\b - Matches if the specified characters are at the beginning or end of a word.

\B - Opposite of \b. Matches if the specified characters are not at the beginning or end of a word.

\d - Matches any decimal digit. Equivalent to [0-9]

\D - Matches any non-decimal digit. Equivalent to [^0-9]

Similarly \s & \S, \w & \W and \Z

result = re.findall(pattern, string)     << find all occurances 

result = re.split(pattern, string)       << splits the string where there is a match and returns a list of strings where the splits have occurred.

re.sub(pattern, replace, string)

The method returns a string where matched occurrences are replaced with the content of replace variable.

re.subn() 



Similarly you have many options that can be tried. 


The re attribute of a matched object returns a regular expression object. Similarly, string attribute returns the passed string.

>>> match.re
re.compile('(\\d{3}) (\\d{2})')

>>> match.string
'39801 356, 2102 1111'





stringVar.strip() 
This is one of the string methods which removes leading/traili ng white space.





COPY 
-------


 Shallow copy is used when a new instance type gets created and it keeps values that are copied whereas deep copy stores values that are already copied.

A shallow copy has faster program execution whereas deep coy makes it slow.



