# Proxy

Provide a surrogate or placeholder for another object to control access to it.

## Participants

* __Proxy__:
  * maintains a reference that lets the proxy access the real subject. Proxy may refer to a Subject if the RealSubject and Subject interfaces are the same.
  
  * provides an interface identical to Subject's so that a proxy can be substituted for the real subject.

  * controls access to the real subject and may be responsible for creating and deleting it.

  * other responsibilities depend on the kind of proxy:
  
    * *remote proxies*: are responsible for encoding a request and its arguments and for sending the encoded request to the real subject in a different address space.

    * *virtual proxy*: may cache additional information about the real subject so that they can postpone accessing it.

    * *protected proxy*: check that the caller has the access permission required to perform a request.
  
  * __Subject__: defines the common interface for RealSubject and Proxy so that a Proxy can be used anywhere RealSubject is expected.

  * __RealSubject__: defines the real object that the proxy represents.

## Structure

![Proxy](https://raw.githubusercontent.com/DocBrown85/design_patterns/master/images/proxy.svg)
