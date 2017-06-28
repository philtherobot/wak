
# Argument passing

Taking arguments, as `const &`, `&` or by value?

If we prefer to take an argument by value, then I feel this is
pushing it too far.  We will run into real performance problems
with trivial data sets.  

By lvalue-reference (formely known as "by reference") does not
work because then the following expression fails to compile:

```
void func(UserType & v);

func(UserType());  // a temporay cannot be a lvalue-reference

```

An option is to use a "rvalue reference":

```
void func(UserType && v);
```

But we need to implement both, the lvalue and the rvalue
reference ones in order to support both the following
situations:

```
func(v); // v is a UserType
func(UserType());
```

Another option is to use `const &`.  Then all those
`const` qualifiers come creeping in, needing two
versions of everything.  And what happens if the
callee wants non-const access?  What signature do we
use then?

A solution is to use a plain `&` and the caller cannot
pass in a rvalue: the object must be created and named 
before passing it in.  But gets us away from our primary
goal: simpler, denser code.  Temporaries are great.

This brings us to the possiblity to passing by value while
all objects are really copy-on-write, making it cheap
to pass them like so.

Being copy-on-write also gives us a neat way to have
the "nil" concept: if there underlying implementation
data pointer is null, then this is a nil instance.

 
# Returning failure or absence

There often is the need to return "nothing".  A "find"
function returns nothing when not found.  This is
done with one of the following tricks:

- Return a bool, true if not "failure", false otherwise,
  actual value is returned via a reference argument.
  
- Return a pointer, null if "failure", newly allocated
  instance otherwise, which the caller must destroy 
  somehow.
  
- Reserve a value to signal "failure".  Return any other
  value for "success", otherwise return the "failure"
  value.
 
- Wrap the value in something similar to `boost::optional`
  and check the value before accesssing it.
  
Pointers may lead to leaks and impose on the caller.

Wrap in `boost::optional` is bulky.

"Bool plus reference argument" is bulkier.

Reserving a value is most useful and leads to simple
direct code.  Theses values can even be placed in 
data structures as guards or markers.

We will call the reserved value "nil".

# Testing of nil

It would be nice to check for nil like this:

```
if( isNil<UserType>(v) ) //...
```  

And to get "nil":

```
auto mark = nil<UserType>();
```

Very generic, great for template code.

This easily done for objects, but for PODs, it is
difficult.  The `isNil` template specialization
fails to work when you have `unsigned int` both
for `Size` and `Char`.

So PODs will rely on named constants.  If template
code needs to run on a POD and wants to call `isNil`,
then we will offer "boxing" of PODs, which will allow
template specialization to attach properly.

# Style

Camel case.

Type are capitalized, everything else is not.

Use `auto` as much as possible.
  
