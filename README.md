# Event-Handlers
What: Native attributes in Java can be ported to c++ using the code provided.
Why: Java code is easily readable and will provide an easier insight for those digging into your code vs reversing android libraries providing little to no detail (if compiled to so).
Pros: 
   Code is harder to examine by 3rd parties.
   Combined with sideloading dex, no additional Java code needs to be added to the application.
Cons:
   Any form of JNI usage will hinder performance, but may not be easily noticeable.
   Must support x86 for some emulators given JNI errors can occur.
