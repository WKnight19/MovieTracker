
---


We are going to model some objects and break up our program into separate files

Develop the foundation for a program for movie fans:
- keep track of movies watched and how many times they have been watched


**Class Movie**:
- Movie Name
- Movie Rating
- Watched Count

**Class Movies**:
Models a collection of movie objects with a vector
- with vectors
- this class needs to know about movie since it is a collection of movie objects, but driver should only interact with the movies class

**Main**:
- Create a movies object
- ask the movies object to add a movie
- ask the movies object to increment the watched count
- ask to display all of its movies

- If we try to add a movie whose name is already in the collection we should display this error to the user
- if we try to increment the watch count for a movie that does not exist we should display this error

**File Structure:**
- Movie.h
- Movie.cpp
- Movies.h
- Movies.cpp
- main.cpp

Don't create a menu driven system like we've done in the past just focus on getting the program working, once it is working, you can certainly provide a menu system for the user
